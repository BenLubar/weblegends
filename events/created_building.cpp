#include "../helpers_event.h"

#include "df/history_event_created_buildingst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_created_buildingst *event)
{
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    if (structure->getType() == abstract_building_type::UNDERWORLD_SPIRE)
    {
        auto builder = df::historical_figure::find(event->builder_hf);
        event_link(s, context, builder);
        s << " thrust a spire of slade up from the underworld, naming it ";
        event_link(s, context, structure);
        s << ", and established a gateway between worlds in ";
        event_link(s, context, site);
        return;
    }

    if (auto builder = df::historical_figure::find(event->builder_hf))
    {
        event_link(s, context, builder);
        s << " built ";
        event_link(s, context, structure);
        if (auto site_civ = df::historical_entity::find(event->site_civ))
        {
            s << " for ";
            event_link(s, context, site_civ);
            if (auto civ = df::historical_entity::find(event->civ))
            {
                s << " of ";
                event_link(s, context, civ);
            }
        }
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " for ";
            event_link(s, context, civ);
        }
    }
    else if (auto site_civ = df::historical_entity::find(event->site_civ))
    {
        event_link(s, context, site_civ);
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " of ";
            event_link(s, context, civ);
        }
        s << " built ";
        event_link(s, context, structure);
    }
    else if (auto civ = df::historical_entity::find(event->civ))
    {
        event_link(s, context, civ);
        s << " built ";
        event_link(s, context, structure);
    }
    else
    {
        event_link(s, context, structure);
        s << " was built";
    }
    if (site)
    {
        s << " at ";
        event_link(s, context, site);
    }
}
