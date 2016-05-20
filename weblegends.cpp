#include "weblegends.h"

DFHACK_PLUGIN("weblegends");

static WebLegends *weblegends = nullptr;

DFhackCExport command_result plugin_init(color_ostream & out, std::vector<PluginCommand> &)
{
    weblegends = new WebLegends();
    return weblegends->init(out);
}

DFhackCExport command_result plugin_shutdown(color_ostream & out)
{
    command_result res = weblegends->shutdown(out);
    if (res == CR_OK)
        delete weblegends;
    return res;
}
