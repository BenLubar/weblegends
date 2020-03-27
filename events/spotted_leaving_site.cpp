#include "../helpers_event.h"

#include "df/history_event_spotted_leaving_sitest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_spotted_leaving_sitest *event)
{
    auto spotter_hf = df::historical_figure::find(event->spotter_hf);
    auto leaver_civ = df::historical_entity::find(event->leaver_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, spotter_hf);
    if (site_civ)
    {
        s << " of ";
        event_link(s, context, site_civ);
    }
    s << " spotted the forces of ";
    event_link(s, context, leaver_civ);
    s << " slipping out of ";
    event_link(s, context, site);
}
