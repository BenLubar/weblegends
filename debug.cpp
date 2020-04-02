#include "weblegends.h"

#ifdef WEBLEGENDS_DEBUG

#include "weblegends-git-describe.h"

#include <iostream>

static std::ofstream weblegends_debug_stream;

static void weblegends_debug_log_message()
{
    auto & console = Core::getInstance().getConsole();
    console << COLOR_YELLOW;
    console << "[weblegends] Debug messages have been written "
        "to weblegends_debug.log. Please send this file to "
        "https://github.com/BenLubar/weblegends" << std::endl;
    console << COLOR_RESET;
}

std::ostream & weblegends_debug_log()
{
    if (!weblegends_debug_stream.is_open())
    {
        weblegends_debug_stream.open("weblegends_debug.log", std::ios_base::out | std::ios_base::app);
        weblegends_debug_stream << "weblegends " << WEBLEGENDS_GIT_DESCRIPTION << " debug log opened" << std::endl;
        weblegends_debug_stream << "weblegends commit: " << WEBLEGENDS_GIT_COMMIT << std::endl;
        weblegends_debug_log_message();
    }

    return weblegends_debug_stream;
}

void weblegends_debug_close_log()
{
    if (!weblegends_debug_stream.is_open())
    {
        weblegends_debug_stream.close();
        weblegends_debug_log_message();
    }
}

#endif
