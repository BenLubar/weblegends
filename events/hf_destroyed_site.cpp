#include "../helpers_event.h"

#include "df/history_event_hf_destroyed_sitest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_destroyed_sitest *event)
{
    auto hf = df::historical_figure::find(event->attacker_hf);
    event_link(s, context, hf);
    s << " routed ";
    auto ent = df::historical_entity::find(event->site_civ);
    event_link(s, context, ent);
    if (auto civ = df::historical_entity::find(event->defender_civ))
    {
        s << " of ";
        event_link(s, context, civ);
    }
    auto site = df::world_site::find(event->site);
    s << " and destroyed ";
    event_link(s, context, site);
}
