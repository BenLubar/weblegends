#pragma once

#include "Core.h"
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>

#include "DataDefs.h"

#define NOMINMAX

#include "PassiveSocket.h"
#include "ActiveSocket.h"
#include "tinythread.h"

#ifndef HAVE_NULLPTR
#define nullptr 0L
#endif

#include "debug.h"

using namespace DFHack;
using namespace df::enums;

DFhackDataExport extern std::vector<std::string> *plugin_globals;

class Client;

class WebLegends
{
    CPassiveSocket sock;
    tthread::thread *thread;
    bool do_shutdown;

    std::vector<Client *> to_delete;
    std::vector<Client *> clients;

protected:
    tthread::mutex to_delete_lock;

public:
    WebLegends() : sock(), thread(nullptr), do_shutdown(false) {}
    ~WebLegends() {}

    command_result init(color_ostream & out);
    command_result shutdown(color_ostream & out);

protected:
    void mark(Client *c);
    bool http(CActiveSocket *sock, std::string & request);
    friend class Client;

private:
    static void run(void *wl);
    void run();
    bool cleanup();

    void handle(CActiveSocket *sock, const std::string & method, const std::string & url);

    static void render_home(std::ostream & s);
    static bool render_entity(std::ostream & s, int32_t id, int32_t page);
	static bool render_era(std::ostream & s, int32_t id, int32_t page);
	static bool render_figure(std::ostream & s, int32_t id, int32_t page);
    static bool render_item(std::ostream & s, int32_t id, int32_t page);
    static bool render_region(std::ostream & s, int32_t id, int32_t page);
    static bool render_site(std::ostream & s, int32_t id, int32_t page);
    static bool render_structure(std::ostream & s, int32_t site_id, int32_t id, int32_t page);
	static bool render_layer(std::ostream & s, int32_t id, int32_t page);
    static bool render_entity_list(std::ostream & s, int32_t page);
	static bool render_era_list(std::ostream & s, int32_t page);
	static bool render_figure_list(std::ostream & s, int32_t page);
    static bool render_item_list(std::ostream & s, int32_t page);
    static bool render_region_list(std::ostream & s, int32_t page);
    static bool render_site_list(std::ostream & s, int32_t page);
	static bool render_layer_list(std::ostream & s, int32_t page);
};

class Client
{
    WebLegends *weblegends;

    CActiveSocket *sock;
    tthread::thread *thread;

public:
    Client(WebLegends *weblegends, CActiveSocket *sock);
    ~Client();

private:
    static void run(void *c);
    void run();

protected:
    bool start();
    void kill();
    void join();
    friend class WebLegends;
};
