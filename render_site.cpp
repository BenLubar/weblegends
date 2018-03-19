#include "weblegends.h"
#include "helpers.h"

#include "df/world.h"
#include "df/world_data.h"
#include "df/world_site.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_site(std::ostream & s, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(id);
    if (site == nullptr)
    {
        return false;
    }

    simple_header(s, site);

    df::coord2d_path coords;
    for (int32_t x = site->global_min_x; x <= site->global_max_x; x++)
    {
        for (int32_t y = site->global_min_y; y <= site->global_max_y; y++)
        {
            coords.push_back(df::coord2d(uint16_t(x), uint16_t(y)));
        }
    }
    render_map_coords(s, coords);

    s << "<p>";
    categorize(s, site);
    s << "</p>";

    if (!site->buildings.empty())
    {
        s << "<h2 id=\"structures\">Structures</h2><ul>";
        for (auto it = site->buildings.begin(); it != site->buildings.end(); it++)
        {
            s << "<li>";
            link(s, *it);
            categorize(s, *it);
            s << "</li>";
        }
        s << "</ul>";
    }
    int32_t last_page;
    if (!history(s, site, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("site-%d", id), "", "?page=", page, last_page);
    s << "</body></html>";
    return true;
}
