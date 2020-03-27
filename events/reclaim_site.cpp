#include "../helpers_event.h"

#include "df/history_event_reclaim_sitest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_reclaim_sitest *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, site_civ);
    s << " of ";
    event_link(s, context, civ);
    if (event->flags2.bits.unretire)
    {
        s << " were taken by a mood to act against their better judgment at ";
    }
    else
    {
        s << " launched an expedition to reclaim ";
    }
    event_link(s, context, site);
}
