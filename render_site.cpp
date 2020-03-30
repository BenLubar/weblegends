#include "weblegends.h"
#include "helpers.h"

#include "df/entity_site_link.h"
#include "df/historical_entity.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_site.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_site(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(id);
    if (site == nullptr)
    {
        return false;
    }

    simple_header(l, site);

    auto & s = l.content;
    df::coord2d_path coords;
    for (int32_t x = site->global_min_x; x <= site->global_max_x; x++)
    {
        for (int32_t y = site->global_min_y; y <= site->global_max_y; y++)
        {
            coords.push_back(df::coord2d(uint16_t(x), uint16_t(y)));
        }
    }
    render_map_coords(s, coords, 16);

    s << "<p>";
    categorize(s, site);
    s << "</p>";

    if (!site->entity_links.empty())
    {
        s << "<h2 id=\"related-entities\">Related Entities</h2><ul>";
        for (auto l : site->entity_links)
        {
            auto entity = df::historical_entity::find(l->entity_id);
            s << "<li>";
            link(s, entity);
            s << ",";
            categorize(s, entity);
            s << "</li>";
        }
        s << "</ul>";
    }

    if (!site->buildings.empty())
    {
        s << "<h2 id=\"structures\">Structures</h2><ul>";
        for (auto b : site->buildings)
        {
            s << "<li>";
            link(s, b);
            s << ",";
            categorize(s, b);
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
    return true;
}
