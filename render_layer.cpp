#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/world_underground_region.h"

void WebLegends::render_layer(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto layer = df::world_underground_region::find(id);
    if (layer == nullptr)
    {
        return;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(&layer->name, false, false) << "</title></head><body>";
    s << "<h1>" << Translation::TranslateName(&layer->name, false, false) << " &ldquo;" << Translation::TranslateName(&layer->name, true, false)  << "&rdquo;</h1>";
    history(s, layer);
    // TODO
    s << "</body></html>";
}
