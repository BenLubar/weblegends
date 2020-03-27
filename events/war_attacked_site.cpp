#include "../helpers_event.h"

#include "df/history_event_war_attacked_sitest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_war_attacked_sitest *event)
{
    auto attacker = df::historical_entity::find(event->attacker_civ);
    event_link(s, context, attacker);
    s << " attacked ";
    auto site_civ = df::historical_entity::find(event->site_civ);
    event_link(s, context, site_civ);
    s << " of ";
    auto defender = df::historical_entity::find(event->defender_civ);
    event_link(s, context, defender);
    s << " in ";
    auto site = df::world_site::find(event->site);
    event_link(s, context, site);
    if (auto attacker_general = df::historical_figure::find(event->attacker_general_hf))
    {
        s << ". The attackers were led by ";
        event_link(s, context, attacker_general);
        if (auto defender_general = df::historical_figure::find(event->defender_general_hf))
        {
            s << ", and the defenders were led by ";
            event_link(s, context, defender_general);
        }
    }
    else if (auto defender_general = df::historical_figure::find(event->defender_general_hf))
    {
        s << ". The defenders were led by ";
        event_link(s, context, defender_general);
    }
}
