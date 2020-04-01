#include "weblegends.h" 
#include "resource.h"

#include <functional>
#include <iostream>
#include <sstream>

#include "df/viewscreen_adopt_regionst.h"
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

    const static size_t min_length = strlen("GET / HTTP/1.0");
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

static void http_error(CActiveSocket *sock, const std::string & method, const std::string & url, int status_code, const std::string & status_phrase, const std::string & body, char http1Point, bool keepAlive, const std::string & extra_headers = std::string())
{
    std::string header = stl_sprintf("HTTP/1.%c %d %s\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Length: %zu\r\nConnection: %s\r\n%s\r\n", http1Point, status_code, status_phrase.c_str(), body.length(), keepAlive ? "keep-alive" : "close", extra_headers.c_str());
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

static bool check_page(Layout & l, const std::string & url, const std::string & prefix, std::function<bool(Layout &, int32_t)> handler)
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

    return handler(l, page);
}

static bool check_id(Layout & l, const std::string & url, const std::string & prefix, std::function<bool(Layout &, int32_t, int32_t)> handler)
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
        return handler(l, id, 0);
    }

    return check_page(l, url.substr(prefix.length() + end), "?page=", [handler, id](Layout & l2, int32_t page) -> bool
    {
        if (page <= 0)
        {
            return false;
        }
        return handler(l2, id, page);
    });
}

static bool check_id_2(Layout & l, const std::string & url, const std::string & prefix1, const std::string & prefix2, std::function<bool(Layout &, int32_t, int32_t, int32_t)> handler)
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

    return check_id(l, url.substr(prefix1.length() + end), prefix2, [handler, id1](Layout & l2, int32_t id2, int32_t page) -> bool
    {
        return handler(l2, id1, id2, page);
    });
}

bool WebLegends::is_world_loaded()
{
    if (!Core::getInstance().isWorldLoaded())
    {
        return false;
    }

    auto view = Gui::getCurViewscreen(true);
    if (virtual_cast<df::viewscreen_adopt_regionst>(view))
    {
        return false;
    }

    if (virtual_cast<df::viewscreen_loadgamest>(view))
    {
        return false;
    }

    return true;
}

DECLARE_RESOURCE(faux_wikipedia_css);

bool WebLegends::request(weblegends_handler_v1 & response, const std::string & url)
{
    Layout l;

    bool builtin = true;
    render_sidebar(l);
    if (url == "/") { render_home(l); }
    else if (check_page(l, url, "/ents-", render_entity_list)) {}
    else if (check_id(l, url, "/ent-", render_entity)) {}
    else if (check_page(l, url, "/figs-", render_figure_list)) {}
    else if (check_id(l, url, "/fig-", render_figure)) {}
    else if (check_page(l, url, "/items-", render_item_list)) {}
    else if (check_id(l, url, "/item-", render_item)) {}
    else if (check_page(l, url, "/regions-", render_region_list)) {}
    else if (check_id(l, url, "/region-", render_region)) {}
    else if (check_page(l, url, "/sites-", render_site_list)) {}
    else if (check_id(l, url, "/site-", render_site)) {}
    else if (check_id_2(l, url, "/site-", "/bld-", render_structure)) {}
    else if (check_page(l, url, "/layers-", render_layer_list)) {}
    else if (check_id(l, url, "/layer-", render_layer)) {}
    else if (check_page(l, url, "/eras-", render_era_list)) {}
    else if (check_id(l, url, "/era-", render_era)) {}
    else if (check_page(l, url, "/eventcols-", render_eventcol_list)) {}
    else if (check_id(l, url, "/eventcol-", render_eventcol)) {}
    else { builtin = false; }

    if (builtin)
    {
        if (l.content.str().empty())
            return false;

        l.write_to(response);
        return true;
    }

    if (url == "/style.css")
    {
        response.status_code() = 410;
        response.status_description() = "Gone";
        response.headers()["Content-Type"] = "text/css; charset=utf-8";
        return true;
    }

    if (url == "/faux-wikipedia.css")
    {
        response.headers()["Content-Type"] = "text/css; charset=utf-8";
        response.raw_out().write(faux_wikipedia_css.data(), faux_wikipedia_css.size());
        return true;
    }

    if (url == "/region.png")
    {
        void render_region_map(std::ostream & s);
        response.headers()["Content-Type"] = "image/png";
        render_region_map(response.raw_out());
        return true;
    }

    size_t pos = url.find_first_of("/?", 1);

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
    auto handlers_1 = get_handlers_v1();
    if (handlers_1 != nullptr)
    {
        auto handler = handlers_1->find(prefix);
        if (handler != handlers_1->end())
        {
            return handler->second.second(response, rest);
        }
    }

    auto handlers_0 = get_handlers_v0();
    if (handlers_0 != nullptr)
    {
        auto handler = handlers_0->find(prefix);
        if (handler != handlers_0->end())
        {
            std::ostringstream s;
            handler->second.second(s, rest);

            auto str = s.str();
            if (str.empty())
                return false;

            response.cp437_out() << str;
            return true;
        }
    }

    return false;
}

void WebLegends::handle(CActiveSocket *sock, const std::string & method, const std::string & url, char http1Point, bool keepAlive)
{
    if (method != "GET" && method != "HEAD")
    {
        http_error(sock, method, url, 405, "Method Not Allowed", "Method \"" + method + "\" not allowed.", http1Point, keepAlive, "Allow: GET, HEAD\r\n");
        return;
    }

    if (!is_world_loaded())
    {
        http_error(sock, method, url, 503, "Service Unavailable", "No world loaded.", http1Point, keepAlive, "Retry-After: 5\r\nRefresh: 5\r\n");
        return;
    }

    weblegends_handler_v1_impl response;

    try
    {
        if (!request(response, url))
        {
            not_found(sock, method, url, http1Point, keepAlive);
            return;
        }
    }
    catch (...)
    {
        http_error(sock, method, url, 500, "Internal Server Error", "Error processing page.", http1Point, keepAlive);
        throw;
    }

    std::ostringstream transport;
    transport << "HTTP/1." << http1Point << " " << response.current_status_code << " " << response.current_status_description << "\r\n";
    response.current_headers.erase("Content-Length");
    response.current_headers.erase("Connection");
    for (auto h : response.current_headers)
    {
        transport << h.first << ": " << h.second << "\r\n";
    }
    auto body = response.body_raw.str();
    transport << "Content-Length: " << body.length() << "\r\n";
    transport << "Connection: " << (keepAlive ? "keep-alive" : "close") << "\r\n";
    transport << "\r\n";
    if (method != "HEAD")
    {
        transport << body;
    }

    std::string transport_str = transport.str();
    if (size_t(sock->Send((const uint8_t *)transport_str.c_str(), transport_str.length())) != transport_str.length())
    {
        std::cerr << "weblegends send " << response.current_status_code << " " << url << ": " << sock->GetSocketError() << std::endl;
        std::cerr << sock->DescribeError() << std::endl;
    }
}
