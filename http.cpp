#include "weblegends.h" 

bool WebLegends::handle(CActiveSocket *sock, std::string & request)
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
        const static std::string bad_request("HTTP/1.0 400 Bad Request\r\nContent-Length: 0\r\n\r\n");
        sock->Send((const uint8_t *) bad_request.c_str(), bad_request.length());
        return true;
    }

    const static std::string not_found("HTTP/1.0 404 Not Found\r\nContent-Length: 0\r\n\r\n");
    sock->Send((const uint8_t *) not_found.c_str(), not_found.length());
    return true;
}
