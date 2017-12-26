#include "weblegends.h"

DFHACK_PLUGIN("weblegends");

static WebLegends *weblegends = nullptr;

DFhackCExport command_result plugin_init(color_ostream & out, std::vector<PluginCommand> &)
{
    weblegends = new WebLegends();
    return weblegends->init(out);
}

static command_result do_unload(color_ostream & out)
{
    if (weblegends == nullptr)
    {
        return CR_OK;
    }

    command_result res = weblegends->shutdown(out);
    if (res == CR_OK)
    {
        delete weblegends;
        weblegends = nullptr;
#ifdef WEBLEGENDS_DEBUG
        weblegends_debug_close_log();
#endif
    }
    return res;
}

DFhackCExport command_result plugin_onstatechange(color_ostream & out, state_change_event sc)
{
    if (sc == SC_BEGIN_UNLOAD)
    {
        return do_unload(out);
    }
    return CR_OK;
}

DFhackCExport command_result plugin_shutdown(color_ostream & out)
{
    return do_unload(out);
}
