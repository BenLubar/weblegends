#include "../helpers_event.h"

#include "df/history_event_site_diedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_site_diedst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    if (event->flags2.bits.abandoned)
    {
        s << "The ";
    }

    event_link(s, context, site_civ);

    if (event->flags2.bits.abandoned)
    {
        s << " abandoned the";
    }
    else
    {
        s << " and ";
        event_link(s, context, civ);
    }

    s << " settlement of ";
    event_link(s, context, site);

    if (!event->flags2.bits.abandoned)
    {
        s << " withered";
    }
}
