#include "../helpers_event.h"

#include "df/history_event_entity_createdst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_createdst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, entity);
    s << " was formed in ";
    if (structure)
    {
        event_link(s, context, structure);
        s << " in ";
    }
    event_link(s, context, site);
}
