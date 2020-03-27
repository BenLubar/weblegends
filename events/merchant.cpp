#include "../helpers_event.h"

#include "df/history_event_merchantst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_merchantst *event)
{
    auto source = df::historical_entity::find(event->source);
    auto destination = df::historical_entity::find(event->destination);
    auto site = df::world_site::find(event->site);

    s << "Merchants from ";
    event_link(s, context, source);
    s << " visited ";
    event_link(s, context, destination);
    s << " in ";
    event_link(s, context, site);

    // TODO: BitArray<int> flags2;
}
