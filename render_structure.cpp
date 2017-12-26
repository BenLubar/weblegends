#include "weblegends.h"
#include "helpers.h"

#include "df/abstract_building.h"
#include "df/world_site.h"

bool WebLegends::render_structure(std::ostream & s, int32_t site_id, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(site_id);
    if (site == nullptr)
    {
        return false;
    }
    auto structure = binsearch_in_vector(site->buildings, uint32_t(id));
    if (structure == nullptr)
    {
        return false;
    }

    simple_header(s, structure);

    s << "<p>";
    categorize(s, structure);
    s << "</p>";

    int32_t last_page;
    if (!history(s, structure, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("site-%d/bld-%d", site_id, id), "", "?page=", page, last_page);
    s << "</body></html>";
    return true;
}
