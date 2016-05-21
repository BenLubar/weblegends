#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/world_site.h"

void WebLegends::render_site(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(id);
    if (site == nullptr)
    {
        return;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(&site->name, false, false) << "</title></head><body>";
    s << "<h1>" << Translation::TranslateName(&site->name, false, false) << " &ldquo;" << Translation::TranslateName(&site->name, true, false)  << "&rdquo;</h1>";
    history(s, site);
    // TODO
    s << "</body></html>";
}
