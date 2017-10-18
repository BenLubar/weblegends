#pragma once

#include <functional>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "Core.h"

#define WEBLEGENDS_PLUGIN_HANDLERS_V0 "weblegends-plugin-handlers.0"

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
