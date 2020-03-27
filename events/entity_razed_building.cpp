#include "../helpers_event.h"

#include "df/history_event_entity_razed_buildingst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_razed_buildingst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, civ);
    s << " razed ";
    event_link(s, context, structure);
    s << " in ";
    event_link(s, context, site);
}
