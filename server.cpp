#include "weblegends.h"

#include <cerrno>
#include <cstring>
#include <iostream>

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
    if (Core::getInstance().isSuspended())
    {
        return CR_FAILURE;
    }

    out << "weblegends cleaning up..." << std::endl;
    std::cerr << "weblegends sending shutdown request" << std::endl;

    {
        tthread::lock_guard<tthread::mutex> l(to_delete_lock);
        do_shutdown = true;
    }

    thread->join();
    delete thread;

    std::cerr << "weblegends forcibly closing " << clients.size() << " clients" << std::endl;

    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->kill();
    }

    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->join();
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
    while (true)
    {
        if (cleanup())
        {
            std::cerr << "weblegends got shutdown request" << std::endl;
            sock.Close();
            return;
        }

        if (!sock.Select(1, 0))
        {
            continue;
        }

        CActiveSocket *client = sock.Accept();
        if (!client)
        {
            std::cerr << "weblegends accept: " << sock.GetSocketError() << std::endl;
            std::cerr << sock.DescribeError() << std::endl;

            continue;
        }

        Client *c = new Client(this, client);
        if (c->start())
        {
            clients.push_back(c);
        }
        else
        {
            int err = errno;
            std::cerr << "weblegends failed to start connection handler for " << (const char *) client->GetClientAddr() << ":" << uint16_t(client->GetClientPort()) << ": error " << err << ": " << strerror(err) << std::endl;
            client->Close();
            delete c;
        }
    }
}

bool WebLegends::cleanup()
{
    tthread::lock_guard<tthread::mutex> l(to_delete_lock);
    for (auto it = to_delete.begin(); it != to_delete.end(); it++)
    {
        clients.erase(std::find(clients.begin(), clients.end(), *it));
        (*it)->join();
        delete *it;
    }
    to_delete.clear();

    return do_shutdown;
}

void WebLegends::mark(Client *c)
{
    tthread::lock_guard<tthread::mutex> l(to_delete_lock);
    to_delete.push_back(c);
}

Client::Client(WebLegends *weblegends, CActiveSocket *sock) :
    weblegends(weblegends),
    sock(sock),
    thread(nullptr)
{
}

Client::~Client()
{
    delete thread;
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
        if (len == 0)
        {
            // closed on other end
            sock->Close();
            continue;
        }
        if (len == -1)
        {
            std::cerr << "weblegends recv: " << sock->GetSocketError() << std::endl;
            std::cerr << sock->DescribeError() << std::endl;
            sock->Close();
            continue;
        }
        request.append((const char *) sock->GetData(), size_t(len));

        try
        {
            while (weblegends->http(sock, request));
        }
        catch (std::exception & ex)
        {
            std::cerr << "weblegends ex: " << ex.what() << std::endl;
            sock->Close();
            continue;
        }
        catch (...)
        {
            std::cerr << "weblegends unknown error" << std::endl;
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

bool Client::start()
{
    tthread::lock_guard<tthread::mutex> l(weblegends->to_delete_lock);
    thread = new tthread::thread(Client::run, this);
    return thread->joinable();
}

void Client::kill()
{
    sock->Shutdown(CSimpleSocket::Both);
}

void Client::join()
{
    thread->join();
}
