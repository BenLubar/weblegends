#include "weblegends.h" 

#include <functional>
#include <iostream>
#include <sstream>

#include "df/viewscreen_loadgamest.h"

#include "modules/Gui.h"

bool WebLegends::http(CActiveSocket *sock, std::string & request)
{
    size_t ending = request.find('\n');
    if (ending == std::string::npos)
    {
        return false;
    }

    size_t ending_size = 1;
    if (ending != 0 && request.at(ending - 1) == '\r')
    {
        ending--;
        ending_size++;
    }

    if (ending == 0)
    {
        request.erase(0, ending_size);
        return true;
    }

    const static size_t min_length = std::string("GET / HTTP/1.0").length();
    if (ending < min_length)
    {
        sock->Close();
        return false;
    }

    std::string url;
    std::string method = request.substr(0, 5) == "GET /" ? "GET" : request.substr(0, 6) == "HEAD /" ? "HEAD" : "";
    char http1Point = request.at(ending - 1);
    bool keepAlive = http1Point == '1';

    if (!method.empty() && request.substr(method.length(), 2) == " /" && request.substr(ending - 9, 8) == " HTTP/1." && (http1Point == '0' || http1Point == '1'))
    {
        url = request.substr(method.length() + 1, ending - 10 - method.length());
    }

    while (true)
    {
        size_t start = ending + ending_size;
        ending = request.find('\n', start);
        if (ending == std::string::npos)
        {
            return false;
        }
        ending_size = 1;
        if (request.at(ending - 1) == '\r')
        {
            ending--;
            ending_size++;
        }

        if (request.substr(start, ending - start) == "Connection: keep-alive")
        {
            keepAlive = true;
        }
        else if (request.substr(start, ending - start) == "Connection: close")
        {
            keepAlive = false;
        }

        if (request.at(ending - 1) == '\n')
        {
            break;
        }
    }

    request.erase(0, ending + ending_size);

    if (url.empty())
    {
        sock->Close();
        return false;
    }

    try
    {
        handle(sock, method, url, http1Point, keepAlive);
    }
    catch (...)
    {
        WEBLEGENDS_DEBUG_LOG << "[weblegends] exception in request: " << method << " " << url << " (" << sock->GetClientAddr() << ")" << std::endl;
        throw;
    }

    if (!keepAlive)
    {
        sock->Close();
        return false;
    }

    return true;
}

static void http_error(CActiveSocket *sock, const std::string & method, const std::string & url, int status_code, const std::string & status_phrase, const std::string & body, char http1Point, bool keepAlive)
{
    std::string header = stl_sprintf("HTTP/1.%c %d %s\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Length: %d\r\nConnection: %s\r\n\r\n", http1Point, status_code, status_phrase.c_str(), body.length(), keepAlive ? "keep-alive" : "close");
    std::string payload = method == "HEAD" ? header : (header + body);
    if (sock->Send((const uint8_t *)payload.c_str(), payload.length()) != int32_t(payload.length()))
    {
        std::cerr << "weblegends send " << status_code << " " << url << ": " << sock->GetSocketError() << std::endl;
        std::cerr << sock->DescribeError() << std::endl;
    }
}

static void not_found(CActiveSocket *sock, const std::string & method, const std::string & url, char http1Point, bool keepAlive)
{
    http_error(sock, method, url, 404, "Not Found", "not found: " + url, http1Point, keepAlive);
}

static bool check_page(std::ostream & s, const std::string & url, const std::string & prefix, std::function<bool(std::ostream &, int32_t)> handler)
{
    if (url.length() <= prefix.length() || url.substr(0, prefix.length()) != prefix)
    {
        return false;
    }

    size_t end = 0;
    int32_t page = -1;
    try
    {
        page = std::stoi(url.substr(prefix.length()), &end);
    }
    catch (...)
    {
        return false;
    }

    if (end != url.length() - prefix.length())
    {
        return false;
    }

    if (page < 0)
    {
        return false;
    }

    return handler(s, page);
}

static bool check_id(std::ostream & s, const std::string & url, const std::string & prefix, std::function<bool(std::ostream &, int32_t, int32_t)> handler)
{
    if (url.length() <= prefix.length() || url.substr(0, prefix.length()) != prefix)
    {
        return false;
    }

    size_t end = 0;
    int32_t id = -1;
    try
    {
        id = std::stoi(url.substr(prefix.length()), &end);
    }
    catch (...)
    {
        return false;
    }

    if (end == url.length() - prefix.length())
    {
        return handler(s, id, 0);
    }

    return check_page(s, url.substr(prefix.length() + end), "?page=", [handler, id](std::ostream & out, int32_t page) -> bool
    {
        if (page <= 0)
        {
            return false;
        }
        return handler(out, id, page);
    });
}

static bool check_id_2(std::ostream & s, const std::string & url, const std::string & prefix1, const std::string & prefix2, std::function<bool(std::ostream &, int32_t, int32_t, int32_t)> handler)
{
    if (url.length() <= prefix1.length() + prefix2.length() || url.substr(0, prefix1.length()) != prefix1)
    {
        return false;
    }

    size_t end = 0;
    int32_t id1 = -1;
    try
    {
        id1 = std::stoi(url.substr(prefix1.length()), &end);
    }
    catch (...)
    {
        return false;
    }

    return check_id(s, url.substr(prefix1.length() + end), prefix2, [handler, id1](std::ostream & out, int32_t id2, int32_t page) -> bool
    {
        return handler(out, id1, id2, page);
    });
}

void WebLegends::handle(CActiveSocket *sock, const std::string & method, const std::string & url, char http1Point, bool keepAlive)
{
    if (!DFHack::Core::getInstance().isWorldLoaded() || virtual_cast<df::viewscreen_loadgamest>(DFHack::Gui::getCurViewscreen(true)))
    {
        http_error(sock, method, url, 503, "Service Unavailable", "No world loaded.", http1Point, keepAlive);
        return;
    }

    std::ostringstream s;

    try
    {
        if (url == "/")
        {
            render_home(s);
        }
        else if (check_page(s, url, "/ents-", render_entity_list)) {}
        else if (check_id(s, url, "/ent-", render_entity)) {}
        else if (check_page(s, url, "/figs-", render_figure_list)) {}
        else if (check_id(s, url, "/fig-", render_figure)) {}
        else if (check_page(s, url, "/items-", render_item_list)) {}
        else if (check_id(s, url, "/item-", render_item)) {}
        else if (check_page(s, url, "/regions-", render_region_list)) {}
        else if (check_id(s, url, "/region-", render_region)) {}
        else if (check_page(s, url, "/sites-", render_site_list)) {}
        else if (check_id(s, url, "/site-", render_site)) {}
        else if (check_id_2(s, url, "/site-", "/bld-", render_structure)) {}
        else if (check_page(s, url, "/layers-", render_layer_list)) {}
        else if (check_id(s, url, "/layer-", render_layer)) {}
        else if (check_page(s, url, "/eras-", render_era_list)) {}
        else if (check_id(s, url, "/era-", render_era)) {}
        else
        {
            size_t pos = url.find('/', 1);
            if (pos != 0)
            {
                std::string prefix, rest;
                if (pos == std::string::npos)
                {
                    prefix = url.substr(1);
                    rest = "";
                }
                else
                {
                    prefix = url.substr(1, pos - 1);
                    rest = url.substr(pos);
                }

                CoreSuspender suspend;
                auto handlers = get_handlers_v0();
                if (handlers != nullptr)
                {
                    auto handler = handlers->find(prefix);
                    if (handler != handlers->end())
                    {
                        handler->second.second(s, rest);
                    }
                }
            }
        }
    }
    catch (...)
    {
        http_error(sock, method, url, 500, "Internal Server Error", "Error processing page.", http1Point, keepAlive);
        throw;
    }

    std::string body = DF2UTF(s.str());

    if (body.empty())
    {
        not_found(sock, method, url, http1Point, keepAlive);
        return;
    }

    std::string header = stl_sprintf("HTTP/1.%c 200 OK\r\nContent-Type: text/html; charset=utf-8\r\nContent-Length: %d\r\nConnection: %s\r\n\r\n", http1Point, body.length(), keepAlive ? "keep-alive" : "close");
    std::string transport = method == "HEAD" ? header : (header + body);
    if (sock->Send((const uint8_t *)transport.c_str(), transport.length()) != int32_t(transport.length()))
    {
        std::cerr << "weblegends send 200 " << url << ": " << sock->GetSocketError() << std::endl;
        std::cerr << sock->DescribeError() << std::endl;
    }
}
