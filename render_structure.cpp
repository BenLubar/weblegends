#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/abstract_building_entombed.h"
#include "df/creature_raw.h"
#include "df/entity_population.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/world_site.h"

bool WebLegends::render_structure(Layout & l, int32_t site_id, int32_t id, int32_t page)
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
    if (structure->parent_building_id != -1)
    {
        auto parent = binsearch_in_vector(site->buildings, structure->parent_building_id);
        l.add_header_link(stl_sprintf("site-%d/bld-%d", site_id, structure->parent_building_id), DF2UTF(Translation::TranslateName(&get_name(parent), false)));
    }
    else
    {
        l.add_header_link(stl_sprintf("site-%d", site_id), DF2UTF(Translation::TranslateName(&site->name, false)));
    }

    simple_header(l, structure);

    auto & s = l.content;
    s << "<p>";
    categorize(s, structure);
    s << "</p>";

    if (!structure->child_building_ids.empty())
    {
        s << "<h2>Contains</h2><ul class=\"multicol\">";
        for (int32_t child_id : structure->child_building_ids)
        {
            auto child = binsearch_in_vector(site->buildings, child_id);
            s << "<li>";
            link(s, child);
            s << ",";
            categorize(s, child);
            s << "</li>";
        }
        s << "</ul>";
    }

    auto entombed = structure->getEntombed();
    if (entombed && (!entombed->populations.empty() || !entombed->histfigs.empty()))
    {
        s << "<h2>Entombed Here</h2><ul class=\"multicol\">";
        for (int32_t histfig_id : entombed->histfigs)
        {
            auto hf = df::historical_figure::find(histfig_id);
            s << "<li>";
            link(s, hf);
            s << ",";
            categorize(s, hf);
            s << "</li>";
        }
        for (auto population : entombed->populations)
        {
            auto creature = df::creature_raw::find(population->race);
            auto pop = df::entity_population::find(population->population);
            s << "<li>";
            s << format_number(population->count);
            s << " ";
            s << html_escape(DF2UTF(creature->name[population->count == 1 ? 0 : 1]));
            s << " (";
            link(s, df::historical_entity::find(pop->civ_id));
            s << ")</li>";
        }
        s << "</ul>";
    }

    int32_t last_page;
    if (!history(s, structure, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("site-%d/bld-%d", site_id, id), "", "?page=", page, last_page);
    return true;
}
