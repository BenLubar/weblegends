#include "weblegends.h"

DFHACK_PLUGIN("weblegends");

static WebLegends *weblegends = nullptr;

static command_result export_command(color_ostream & out, std::vector<std::string> & args)
{
    if (args.size() != 1)
    {
        return CR_WRONG_USAGE;
    }

    return weblegends->export_all(out, args.at(0));
}

DFhackCExport command_result plugin_init(color_ostream & out, std::vector<PluginCommand> & commands)
{
    commands.push_back(PluginCommand(
        "weblegends-export",
        "exports a full weblegends site to a folder",
        export_command,
        false,
        "weblegends-export [folder-name]\n"
        "  exports a full weblegends site to a folder"
    ));

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

void clear_region_map_cache();
DFhackCExport command_result plugin_onstatechange(color_ostream & out, state_change_event sc)
{
    if (sc == SC_WORLD_LOADED || sc == SC_WORLD_UNLOADED)
    {
        clear_region_map_cache();
    }
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
