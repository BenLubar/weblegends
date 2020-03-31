#pragma once

#include <queue>
#include <typeinfo>

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

using namespace DFHack;
using namespace df::enums;

#include "weblegends-plugin.h"

#include "debug.h"

DFhackDataExport extern std::vector<std::string> *plugin_globals;

class Client;
class Layout;

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
    command_result export_all(color_ostream & out, const std::string & folder);
    command_result export_recursive(color_ostream & out, std::set<std::string> & exported, std::queue<std::string> & queue, const std::string & folder);
    void queue_linked_pages(std::queue<std::string> & queue, const std::string & url, std::string & body);

protected:
    void mark(Client *c);
    bool http(CActiveSocket *sock, std::string & request);
    friend class Client;

private:
    static void run(void *wl);
    void run();
    bool cleanup();

    inline static weblegends_handlers_v0_t *get_handlers_v0()
    {
        return static_cast<weblegends_handlers_v0_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V0));
    }

    inline static weblegends_handlers_v1_t *get_handlers_v1()
    {
        return static_cast<weblegends_handlers_v1_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V1));
    }

    void handle(CActiveSocket *sock, const std::string & method, const std::string & url, char http1Point, bool keepAlive);
    bool request(weblegends_handler_v1 & response, const std::string & url);

    static bool is_world_loaded();
    static void render_home(Layout & l);
    static void render_sidebar(Layout & l);
    static bool render_entity(Layout & l, int32_t id, int32_t page);
    static bool render_era(Layout & l, int32_t id, int32_t page);
    static bool render_eventcol(Layout & l, int32_t id, int32_t page);
    static bool render_figure(Layout & l, int32_t id, int32_t page);
    static bool render_item(Layout & l, int32_t id, int32_t page);
    static bool render_region(Layout & l, int32_t id, int32_t page);
    static bool render_site(Layout & l, int32_t id, int32_t page);
    static bool render_structure(Layout & l, int32_t site_id, int32_t id, int32_t page);
    static bool render_layer(Layout & l, int32_t id, int32_t page);
    static bool render_entity_list(Layout & l, int32_t page);
    static bool render_era_list(Layout & l, int32_t page);
    static bool render_eventcol_list(Layout & l, int32_t page);
    static bool render_figure_list(Layout & l, int32_t page);
    static bool render_item_list(Layout & l, int32_t page);
    static bool render_region_list(Layout & l, int32_t page);
    static bool render_site_list(Layout & l, int32_t page);
    static bool render_layer_list(Layout & l, int32_t page);
};

class weblegends_handler_v1_impl : public weblegends_handler_v1
{
    class cp437_streambuf : public std::streambuf
    {
    public:
        cp437_streambuf(std::streambuf *raw) : raw(raw) {}
        std::streambuf *raw;
    protected:
        virtual int_type overflow(int_type c)
        {
            if (c != EOF)
            {
                auto utf8 = DF2UTF(std::string(1, char(c)));
                if (raw->sputn(utf8.c_str(), std::streamsize(utf8.size())) != std::streamsize(utf8.size()))
                {
                    c = EOF;
                }
            }
            return c;
        }
    };

    weblegends_handler_v1_impl() :
        current_status_code(200),
        current_status_description("OK"),
        current_headers(),
        body_raw(),
        cp437_buf(body_raw.rdbuf()),
        body_cp437(&cp437_buf)
    {
        current_headers["Content-Type"] = "text/html; charset=utf-8";
    }
    friend class WebLegends;
    int32_t current_status_code;
    std::string current_status_description;
    std::map<std::string, std::string> current_headers;
    std::ostringstream body_raw;
    cp437_streambuf cp437_buf;
    std::ostream body_cp437;
public:
    virtual int32_t & status_code() { return current_status_code; }
    virtual std::string & status_description() { return current_status_description; }
    virtual std::map<std::string, std::string> & headers() { return current_headers; }
    virtual std::ostream & cp437_out() { return body_cp437; }
    virtual std::ostream & raw_out() { return body_raw; }
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

class Layout
{
public:
    std::ostringstream head_content;
    std::ostringstream header_nav;
    std::ostringstream sidebar_nav;
    std::ostringstream content;

    bool in_sidebar_section{};

    void set_title(const std::string & title);
    void set_base_path(const std::string & url);
    void add_header_link(const std::string & url, const std::string & label, bool current = false);
    void add_sidebar_section(const std::string & title);
    void add_sidebar_link(const std::string & url, const std::string & label);

    void write_to(weblegends_handler_v1 & handler) const;
};
