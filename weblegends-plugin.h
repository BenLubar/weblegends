#pragma once

#include <functional>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "Core.h"

#include "df/history_event.h"
#include "df/history_event_context.h"

#define WEBLEGENDS_PLUGIN_HANDLERS_V0 "weblegends-plugin-handlers.0"
#define WEBLEGENDS_PLUGIN_HANDLERS_V1 "weblegends-plugin-handlers.1"
#define WEBLEGENDS_DESCRIBE_EVENT_V0 "weblegends-describe-event.0"

using weblegends_handler_v0_t = std::function<bool(std::ostringstream &, const std::string &)>;
using weblegends_handlers_v0_t = std::map<std::string, std::pair<std::string, weblegends_handler_v0_t>>;

class weblegends_handler_v1
{
    weblegends_handler_v1() {}
    virtual ~weblegends_handler_v1() {}
    friend class weblegends_handler_v1_impl;
    friend class weblegends_handler_v1_downgrade_impl;
public:
    virtual int32_t & status_code() = 0;
    virtual std::string & status_description() = 0;
    virtual std::map<std::string, std::string> & headers() = 0;
    virtual std::ostream & cp437_out() = 0;
    virtual std::ostream & raw_out() = 0;
};
using weblegends_handler_v1_t = std::function<bool(weblegends_handler_v1 &, const std::string &)>;
using weblegends_handlers_v1_t = std::map<std::string, std::pair<std::string, weblegends_handler_v1_t>>;
static inline bool add_weblegends_handler(const std::string & prefix, weblegends_handler_v1_t handler, const std::string & label = "");
class weblegends_handler_v1_downgrade_impl : public weblegends_handler_v1
{
    weblegends_handler_v1_downgrade_impl(std::ostringstream & out) : out(out) {}
    friend bool add_weblegends_handler(const std::string &, weblegends_handler_v1_t, const std::string &);
    std::ostream & out;
    int32_t dummy_status_code;
    std::string dummy_status_description;
    std::map<std::string, std::string> dummy_headers;
public:
    virtual int32_t & status_code() { dummy_status_code = 200; return dummy_status_code; }
    virtual std::string & status_description() { dummy_status_description = "OK"; return dummy_status_description; }
    virtual std::map<std::string, std::string> & headers() { dummy_headers.clear(); dummy_headers["Content-Type"] = "text/html; charset=utf-8"; return dummy_headers; }
    virtual std::ostream & cp437_out() { return out; }
    virtual std::ostream & raw_out() { return out; }
};

static inline bool add_weblegends_handler(const std::string & prefix, weblegends_handler_v0_t handler, const std::string & label = "")
{
    if (prefix.empty() || prefix.find('/') != std::string::npos)
    {
        return false;
    }

    DFHack::CoreSuspender suspend;
    weblegends_handlers_v0_t *ptr = static_cast<weblegends_handlers_v0_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V0));
    if (ptr == nullptr)
    {
        ptr = new weblegends_handlers_v0_t();
        Core::getInstance().RegisterData(static_cast<void *>(ptr), WEBLEGENDS_PLUGIN_HANDLERS_V0);
    }
    if (ptr->count(prefix))
    {
        return false;
    }
    (*ptr)[prefix] = std::make_pair(label, handler);
    return true;
}

static inline bool add_weblegends_handler(const std::string & prefix, weblegends_handler_v1_t handler, const std::string & label)
{
    if (prefix.empty() || prefix.find('/') != std::string::npos)
    {
        return false;
    }

    DFHack::CoreSuspender suspend;
    if (!add_weblegends_handler(prefix, [handler](std::ostringstream & out, const std::string & prefix) -> bool
    {
        weblegends_handler_v1_downgrade_impl downgrade(out);
        return handler(downgrade, prefix);
    }, label))
    {
        return false;
    }

    weblegends_handlers_v1_t *ptr = static_cast<weblegends_handlers_v1_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V1));
    if (ptr == nullptr)
    {
        ptr = new weblegends_handlers_v1_t();
        Core::getInstance().RegisterData(static_cast<void *>(ptr), WEBLEGENDS_PLUGIN_HANDLERS_V1);
    }
    (*ptr)[prefix] = std::make_pair(label, handler);
    return true;
}

static inline bool remove_weblegends_handler(const std::string & prefix)
{
    DFHack::CoreSuspender suspend;
    weblegends_handlers_v0_t *ptr0 = static_cast<weblegends_handlers_v0_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V0));
    if (ptr0 == nullptr)
    {
        return false;
    }
    weblegends_handlers_v1_t *ptr1 = static_cast<weblegends_handlers_v1_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V1));
    if (ptr1 != nullptr)
    {
        ptr1->erase(prefix);
    }
    return ptr0->erase(prefix) != 0;
}

static inline void weblegends_describe_event(std::ostream & out, df::history_event *event)
{
    using describe_event_fn = std::function<void(std::ostream &, df::history_event *)>;
    describe_event_fn *ptr = static_cast<describe_event_fn *>(Core::getInstance().GetData(WEBLEGENDS_DESCRIBE_EVENT_V0));
    if (ptr == nullptr)
    {
        if (!event)
        {
            out << "(unknown event)";
            return;
        }

        static df::history_event_context context;
        context.anon_1 = 0;
        context.anon_2 = 0;
        context.histfig_id_talker = -1;
        context.histfig_id_listener = -1;

        std::string str;
        event->getSentence(&str, &context, 1, 0);
        out << str;
        return;
    }
    (*ptr)(out, event);
}
