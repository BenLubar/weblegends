#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/creature_raw.h"
#include "df/plant_raw.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_population.h"
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

    s << "<h3>Population</h3><ul class=\"multicol\">";
    std::ostringstream uncountable;
    for (auto pop : region->population)
    {
        ASSUME_EQUAL(pop->count_min, pop->count_max, stl_sprintf("population min/max differs (region-%d)", region->index));

        std::ostream & ss = pop->count_max == 10000001 ? uncountable : s;
        ss << "<li>";
        if (pop->count_max != 10000001)
        {
            ss << pop->count_max << " ";
        }
        BEFORE_SWITCH(type, pop->type);
        switch (type)
        {
        case world_population_type::Animal:
        case world_population_type::ColonyInsect:
        case world_population_type::Vermin:
        case world_population_type::VerminInnumerable:
            if (auto creature = df::creature_raw::find(pop->race))
            {
                ss << html_escape(DF2UTF(pop->count_max == 1 ? creature->name[0] : creature->name[1]));
            }
            else
            {
                ss << "[unknown creature]";
            }
            BREAK(type);
        case world_population_type::Bush:
        case world_population_type::Grass:
        case world_population_type::Tree:
            if (auto plant = df::plant_raw::find(pop->plant))
            {
                ss << html_escape(DF2UTF(pop->count_max == 1 ? plant->name : plant->name_plural));
            }
            else
            {
                ss << "[unknown " << toLower(enum_item_key_str(type)) << "]";
            }
            BREAK(type);
        case world_population_type::Unk2:
            break;
        }
        if (!type_found)
        {
            ss << "[" << enum_item_key_str(pop->type) << "]";
        }
        AFTER_SWITCH(type, stl_sprintf("region-%d population", region->index));
        ss << "</li>";
    }
    s << "</ul><h3>Also commonly found in ";
    s << html_escape(DF2UTF(Translation::TranslateName(&region->name, false)));
    s << "</h3><ul class=\"multicol\">";
    s << uncountable.str();
    s << "</ul>";

    int32_t last_page;
    if (!history(s, region, page, last_page))
    {
        return true;
    }
    pagination(s, stl_sprintf("region-%d", id), "", "?page=", page, last_page);
    return true;
}
