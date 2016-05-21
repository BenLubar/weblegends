#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/world_region.h"

void WebLegends::render_region(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto region = df::world_region::find(id);
    if (region == nullptr)
    {
        return;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(&region->name, false, false) << "</title></head><body>";
    s << "<h1>" << Translation::TranslateName(&region->name, false, false) << " &ldquo;" << Translation::TranslateName(&region->name, true, false)  << "&rdquo;</h1>";
    history(s, region);
    // TODO
    s << "</body></html>";
}
