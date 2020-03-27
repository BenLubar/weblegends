#include "../helpers_event.h"

#include "df/history_event_war_peace_rejectedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_war_peace_rejectedst *event)
{
    auto destination = df::historical_entity::find(event->destination);
    event_link(s, context, destination);
    s << " rejected a peace treaty from ";
    auto source = df::historical_entity::find(event->source);
    event_link(s, context, source);
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
    // TODO: df::meeting_topic topic;
}
