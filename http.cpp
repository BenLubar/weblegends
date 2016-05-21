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

void WebLegends::handle(CActiveSocket *sock, const std::string & url)
{
    std::ostringstream s;
    auto check_id = [&s, url](const std::string & prefix, std::function<void(std::ostream &, int32_t)> handler) -> bool
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
            return true;
        }

        if (end != url.length() - prefix.length())
        {
            return true;
        }

        handler(s, id);

        return true;
    };

    if (url == "/")
    {
        render_home(s);
    }
    else if (check_id("/ent-", render_entity)) {}
    else if (check_id("/fig-", render_figure)) {}
    else if (check_id("/region-", render_region)) {}
    else if (check_id("/site-", render_site)) {}
    else if (check_id("/layer-", render_layer)) {}

    std::string body = DF2UTF(s.str());

    if (body.empty())
    {
        not_found(sock, url);
        return;
    }

    std::string transport = stl_sprintf("HTTP/1.0 200 OK\r\nContent-Type: text/html; charset=utf-8\r\nContent-Length: %d\r\n\r\n%s", body.length(), body.c_str());
    sock->Send((const uint8_t *) transport.c_str(), transport.length());
}
