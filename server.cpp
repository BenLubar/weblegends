#include "weblegends.h"

command_result WebLegends::init(color_ostream & out)
{
    if (!sock.Initialize() || !sock.Listen((const uint8_t *) "0.0.0.0", 5080))
    {
        out << "weblegends startup failed: " << sock.GetSocketError() << std::endl;
        out << sock.DescribeError() << std::endl;
        return CR_FAILURE;
    }
    out << "weblegends listening on http://localhost:5080/" << std::endl;

    thread = new tthread::thread(WebLegends::run, this);

    return CR_OK;
}

command_result WebLegends::shutdown(color_ostream & out)
{
    out << "weblegends cleaning up..." << std::endl;

    sock.Close();
    thread->join();
    delete thread;

    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->kill();
    }
    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->thread.join();
    }
    tthread::lock_guard<tthread::mutex> l(to_delete_lock);
    for (auto it = to_delete.begin(); it != to_delete.end(); it++)
    {
        delete *it;
    }
    to_delete.clear();
    clients.clear();

    out << "done." << std::endl;

    return CR_OK;
}

void WebLegends::run(void *wl)
{
    reinterpret_cast<WebLegends *>(wl)->run();
}

void WebLegends::run()
{
    sock.SetNonblocking();

    while (true)
    {
        cleanup();

        CActiveSocket *client = sock.Select(1, 0) ? sock.Accept() : nullptr;
        if (!client)
        {
            if (!sock.IsSocketValid())
            {
                return;
            }

            continue;
        }

        clients.push_back(new Client(this, client));
    }
}

void WebLegends::cleanup()
{
    tthread::lock_guard<tthread::mutex> l(to_delete_lock);
    for (auto it = to_delete.begin(); it != to_delete.end(); it++)
    {
        clients.erase(std::find(clients.begin(), clients.end(), *it));
        delete *it;
    }
    to_delete.clear();
}

void WebLegends::mark(Client *c)
{
    tthread::lock_guard<tthread::mutex> l(to_delete_lock);
    to_delete.push_back(c);
}

Client::Client(WebLegends *weblegends, CActiveSocket *sock) :
    weblegends(weblegends),
    sock(sock),
    thread(Client::run, this)
{
}

Client::~Client()
{
    delete sock;
}

void Client::run(void *c)
{
    reinterpret_cast<Client *>(c)->run();
}

void Client::run()
{
    std::string request;

    while (true)
    {
        if (!sock->IsSocketValid())
        {
            weblegends->mark(this);
            return;
        }

        if (!sock->Select(1, 0))
        {
            continue;
        }

        int32_t len = sock->Receive(8192);
        if (len <= 0)
        {
            sock->Close();
            continue;
        }
        request.append((const char *) sock->GetData(), size_t(len));

        try
        {
            while (weblegends->http(sock, request));
        }
        catch (...)
        {
            sock->Close();
            continue;
        }

        if (request.size() >= 8192)
        {
            sock->Close();
            continue;
        }
    }
}

void Client::kill()
{
    sock->Shutdown(CSimpleSocket::Both);
}

void Client::join()
{
    thread.join();
}
