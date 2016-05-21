#include "weblegends.h" 

#include <functional>
#include <sstream>

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

    if (request.substr(0, 5) == "GET /" && request.substr(ending - 9, 8) == " HTTP/1." && (request.at(ending - 1) == '0' || request.at(ending - 1) == '1'))
    {
        url = request.substr(4, ending - 13);
    }

    while (true)
    {
        ending = request.find('\n', ending + ending_size);
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

        if (request.at(ending - 1) == '\n')
        {
            break;
        }
    }

    request.erase(0, ending + ending_size);

    if (url.empty())
    {
        const static std::string bad_request("HTTP/1.0 400 Bad Request\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Length: 11\r\n\r\nbad request");
        sock->Send((const uint8_t *) bad_request.c_str(), bad_request.length());
        return true;
    }

    handle(sock, url);

    return true;
}

static void not_found(CActiveSocket *sock, const std::string & url)
{
    std::string body = "not found: " + url;
    std::string not_found = stl_sprintf("HTTP/1.0 404 Not Found\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Length: %d\r\n\r\n%s", body.length(), body.c_str());
    sock->Send((const uint8_t *) not_found.c_str(), not_found.length());
}

static bool check_id(std::ostream & s, const std::string & url, const std::string & prefix, std::function<void(std::ostream &, int32_t)> handler)
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

    if (end != url.length() - prefix.length())
    {
        return false;
    }

    handler(s, id);

    return true;
}

static bool check_id_2(std::ostream & s, const std::string & url, const std::string & prefix1, const std::string & prefix2, std::function<void(std::ostream &, int32_t, int32_t)> handler)
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

    return check_id(s, url.substr(end), prefix2, [handler, id1](std::ostream & out, int32_t id2)
            {
                handler(out, id1, id2);
            });
}

void WebLegends::handle(CActiveSocket *sock, const std::string & url)
{
    std::ostringstream s;

    if (url == "/")
    {
        render_home(s);
    }
    else if (check_id(s, url, "/ents-", render_entity_list)) {}
    else if (check_id(s, url, "/ent-", render_entity)) {}
    else if (check_id(s, url, "/figs-", render_figure_list)) {}
    else if (check_id(s, url, "/fig-", render_figure)) {}
    else if (check_id(s, url, "/regions-", render_region_list)) {}
    else if (check_id(s, url, "/region-", render_region)) {}
    else if (check_id(s, url, "/sites-", render_site_list)) {}
    else if (check_id(s, url, "/site-", render_site)) {}
    else if (check_id_2(s, url, "/site-", "/bld-", render_structure)) {}
    //else if (check_id(s, url, "/layers-", render_layer_list)) {}
    //else if (check_id(s, url, "/layer-", render_layer)) {}

    std::string body = DF2UTF(s.str());

    if (body.empty())
    {
        not_found(sock, url);
        return;
    }

    std::string transport = stl_sprintf("HTTP/1.0 200 OK\r\nContent-Type: text/html; charset=utf-8\r\nContent-Length: %d\r\n\r\n%s", body.length(), body.c_str());
    sock->Send((const uint8_t *) transport.c_str(), transport.length());
}
