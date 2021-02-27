#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/creature_raw.h"
#include "df/entity_entity_link.h"
#include "df/entity_population.h"
#include "df/entity_position.h"
#include "df/entity_position_assignment.h"
#include "df/entity_site_link.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/squad.h"
#include "df/world_site.h"
#include "df/world_site_inhabitant.h"

bool WebLegends::render_entity(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto ent = df::historical_entity::find(id);
    if (ent == nullptr)
    {
        return false;
    }

    simple_header(l, ent);

    auto & s = l.content;
    s << "<p>";
    categorize(s, ent);
    s << "</p>";

    if (!ent->positions.assignments.empty())
    {
        s << "<h2>Administrative Positions</h2><ul class=\"multicol\">";
        for (auto asn : ent->positions.assignments)
        {
            s << "<li>";

            auto assigned = df::historical_figure::find(asn->histfig);
            if (asn->histfig == -1)
            {
                s << "(vacant)";
            }
            else
            {
                link(s, assigned);
            }

            auto pos = binsearch_in_vector(ent->positions.own, asn->position_id);
            s << ", " << sex_name(assigned, pos);

            if (auto squad = df::squad::find(asn->squad_id))
            {
                s << " of " << escape_name(squad->name, true);
            }

            s << "</li>";
        }
        s << "</ul>";
    }

    if (!ent->entity_links.empty())
    {
        s << "<h2 id=\"related-entities\">Related Entities</h2><ul class=\"multicol\">";
        for (auto ent_link : ent->entity_links)
        {
            if (auto target = df::historical_entity::find(ent_link->target))
            {
                s << "<li>";
                link(s, target);
                s << ",";
                categorize(s, target, false, false, ent->race);
                s << "</li>";
            }
        }
        s << "</ul>";
    }
    bool any_residence = false;
    if (!ent->site_links.empty())
    {
        s << "<h2 id=\"related-sites\">Related Sites</h2><ul class=\"multicol\">";
        for (auto site_link : ent->site_links)
        {
            if (auto target = df::world_site::find(site_link->target))
            {
                if (site_link->flags.bits.residence)
                {
                    any_residence = true;
                }
                s << "<li>";
                link(s, target);
                s << ",";
                categorize(s, target);
                if (site_link->flags.bits.primary_criminal_gang)
                {
                    s << " (primary criminal gang)";
                }
                else if (site_link->flags.bits.criminal_gang)
                {
                    s << " (criminal gang)";
                }
                else if (site_link->flags.bits.residence)
                {
                    s << " (residence)";
                }
                else if (site_link->flags.bits.capital)
                {
                    s << " (capital)";
                }
                else if (site_link->flags.bits.base_of_operation)
                {
                    s << " (base of operation)";
                }
                else if (site_link->flags.bits.holy_city)
                {
                    s << " (holy city)";
                }
                else if (site_link->flags.bits.monument)
                {
                    s << " (monument)";
                }
                s << "</li>";
            }
        }
        s << "</ul>";
    }
    if (!ent->hist_figures.empty() || !ent->populations.empty() || any_residence)
    {
        s << "<h2>Members</h2><ul class=\"multicol\">";
        for (auto hf : ent->hist_figures)
        {
            s << "<li>";
            link(s, hf);
            s << ",";
            categorize(s, hf);
            s << "</li>";
        }
        for (auto id : ent->populations)
        {
            if (auto pop = df::entity_population::find(id))
            {
                for (size_t i = 0; i < pop->races.size(); i++)
                {
                    if (pop->counts.at(i) == 0)
                    {
                        continue;
                    }

                    auto creature = df::creature_raw::find(pop->races.at(i));
                    s << "<li>" << format_number(pop->counts.at(i)) << " ";
                    s << creature->name[pop->counts.at(i) == 1 ? 0 : 1];
                    s << "</li>";
                }
            }
        }
        for (auto site_link : ent->site_links)
        {
            if (!site_link->flags.bits.residence)
            {
                continue;
            }
            if (auto site = df::world_site::find(site_link->target))
            {
                for (auto inh : site->unk_1.inhabitants)
                {
                    if (inh->outcast_id == ent->id)
                    {
                        if (inh->count == 0)
                        {
                            continue;
                        }

                        auto creature = df::creature_raw::find(inh->race);
                        s << "<li>" << format_number(inh->count) << " ";
                        s << creature->name[inh->count == 1 ? 0 : 1];
                        s << " (";
                        link(s, site);
                        if (auto pop = df::entity_population::find(inh->population_id))
                        {
                            s << ", ";
                            link(s, df::historical_entity::find(pop->civ_id));
                        }
                        s << ")</li>";
                    }
                }
            }
        }
        s << "</ul>";
    }

    int32_t last_page;
    if (!history(s, ent, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("ent-%d", id), "", "?page=", page, last_page);
    return true;
}
