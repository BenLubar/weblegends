#include "../helpers_event.h"

#include "df/history_event_war_site_new_leaderst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_war_site_new_leaderst *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto new_site_civ = df::historical_entity::find(event->new_site_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    s << " defeated ";
    if (defender_civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, defender_civ);
    s << " and placed ";
    list_event_link<df::historical_figure>(s, context, event->new_leaders);
    s << " in charge of ";
    event_link(s, context, site);
    s << ". The new government was called ";
    event_link(s, context, new_site_civ);
}
