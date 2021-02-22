#include "weblegends.h"
#include "helpers.h"

#include "df/creature_raw.h"
#include "df/entity_site_link.h"
#include "df/historical_entity.h"
#include "df/nemesis_record.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_site.h"
#include "df/world_site_inhabitant.h"

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

    render_world_populations(s, site->name, site->unk_1.animals, "site", site->id);

    if (!site->unk_1.nemesis.empty() || !site->unk_1.inhabitants.empty())
    {
        s << "<h3>Inhabitants</h3><ul class=\"multicol\">";
        for (auto id : site->unk_1.nemesis)
        {
            auto nemesis = df::nemesis_record::find(id);
            if (!nemesis)
            {
                s << "<li>(unknown)</li>";
                continue;
            }

            s << "<li>";
            link(s, nemesis->figure);
            s << ",";
            categorize(s, nemesis->figure);
            s << "</li>";
        }
        for (auto inhabitant : site->unk_1.inhabitants)
        {
            auto creature = df::creature_raw::find(inhabitant->race);
            s << "<li>" << inhabitant->count << " ";
            s << creature->name[inhabitant->count == 1 ? 0 : 1];
            if (auto outcast = df::historical_entity::find(inhabitant->outcast_id))
            {
                s << " (";
                link(s, outcast);
                s << ")";
            }
            s << "</li>";
        }
        s << "</ul>";
    }

    if (!site->unk_1.artifacts.empty())
    {
        s << "<h3>Artifacts</h3><ul class=\"multicol\">";
        for (auto art : site->unk_1.artifacts)
        {
            s << "<li>";
            link(s, art);
            s << ",";
            categorize(s, art);
            s << "</li>";
        }
        s << "</ul>";
    }

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
