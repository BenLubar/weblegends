#include "../weblegends.h"
#include "../helpers.h"
#include "../debug.h"

#include "modules/Translation.h"

#include "df/creature_raw.h"
#include "df/historical_entity.h"
#include "df/plant_raw.h"
#include "df/world_population.h"

void render_world_populations(std::ostream & s, const df::language_name & region_name, const std::vector<df::world_population *> & population, const char *region_type, int32_t id)
{
    if (population.empty())
    {
        return;
    }

    bool any_countable = false;
    s << "<h2>Population</h2><ul class=\"multicol\">";
    std::ostringstream uncountable;
    for (auto pop : population)
    {
        if (pop->count_min == 0 && (pop->count_max == 0 || pop->count_max == 10000001))
        {
            continue;
        }

        std::ostream & ss = pop->count_min == 10000001 ? uncountable : s;
        ss << "<li>";
        if (pop->count_min != 10000001)
        {
            any_countable = true;
            ss << format_number(pop->count_min);

            if (pop->count_max == 10000001)
            {
                ss << "+ ";
            }
            else if (pop->count_min < pop->count_max)
            {
                ss << "-" << format_number(pop->count_max) << " ";
            }
            else
            {
                ss << " ";
            }
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
                ss << html_escape(DF2UTF(pop->count_min == 1 ? creature->name[0] : creature->name[1]));
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
                ss << html_escape(DF2UTF(pop->count_min == 1 ? plant->name : plant->name_plural));
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
        AFTER_SWITCH(type, stl_sprintf("%s-%d population", region_type, id));

        if (auto owner = df::historical_entity::find(pop->owner))
        {
            ss << " (";
            link(s, owner);
            ss << ")";
        }

        ss << "</li>";
    }
    auto uncountable_str = uncountable.str();
    if (!uncountable_str.empty())
    {
        if (any_countable)
        {
            s << "</ul><h2>Also commonly found in ";
            if (region_name.has_name)
            {
                s << escape_name(region_name);
            }
            else
            {
                s << "this area";
            }
            s << "</h2><ul class=\"multicol\">";
        }
        s << uncountable_str;
    }
    s << "</ul>";
}
