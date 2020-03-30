#include "weblegends.h"
#include "helpers.h"

#include "df/world.h"
#include "df/world_data.h"
#include "df/world_region.h"

REQUIRE_GLOBAL(world)

bool WebLegends::render_region(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto region = df::world_region::find(id);
    if (region == nullptr)
    {
        return false;
    }

    simple_header(l, region);

    auto & s = l.content;
    render_map_coords(s, region->region_coords);

    s << "<p>";
    categorize(s, region);
    s << "</p>";

    int32_t last_page;
    if (!history(s, region, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("region-%d", id), "", "?page=", page, last_page);
    return true;
}
