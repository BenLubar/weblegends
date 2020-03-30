#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/world_site.h"

bool WebLegends::render_structure(Layout & l, int32_t site_id, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(site_id);
    if (site == nullptr)
    {
        return false;
    }
    l.add_header_link(stl_sprintf("site-%d", site_id), Translation::TranslateName(&site->name, false));
    auto structure = binsearch_in_vector(site->buildings, uint32_t(id));
    if (structure == nullptr)
    {
        return false;
    }

    simple_header(l, structure);

    auto & s = l.content;
    s << "<p>";
    categorize(s, structure);
    s << "</p>";

    int32_t last_page;
    if (!history(s, structure, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("site-%d/bld-%d", site_id, id), "", "?page=", page, last_page);
    return true;
}
