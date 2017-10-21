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
#define WEBLEGENDS_DESCRIBE_EVENT_V0 "weblegends-describe-event.0"

using weblegends_handler_t = std::function<bool(std::ostringstream &, const std::string &)>;
using weblegends_handlers_v0_t = std::map<std::string, std::pair<std::string, weblegends_handler_t>>;

static inline bool add_weblegends_handler(const std::string & prefix, weblegends_handler_t handler, const std::string & label = "")
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

static inline bool remove_weblegends_handler(const std::string & prefix)
{
	DFHack::CoreSuspender suspend;
	weblegends_handlers_v0_t *ptr = static_cast<weblegends_handlers_v0_t *>(Core::getInstance().GetData(WEBLEGENDS_PLUGIN_HANDLERS_V0));
	if (ptr == nullptr)
	{
		return false;
	}
	return ptr->erase(prefix) != 0;
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
