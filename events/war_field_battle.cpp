#include "../helpers_event.h"

#include "df/history_event_war_field_battlest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_war_field_battlest *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto region = df::world_region::find(event->region);
    auto layer = df::world_underground_region::find(event->layer);
    // TODO: df::coord2d region_pos;
    auto attacker_general_hf = df::historical_figure::find(event->attacker_general_hf);
    auto defender_general_hf = df::historical_figure::find(event->defender_general_hf);

    event_link(s, context, attacker_civ);
    s << " attacked ";
    event_link(s, context, defender_civ);
    if (region)
    {
        s << " in ";
        event_link(s, context, region);
    }
    if (layer)
    {
        s << " in ";
        event_link(s, context, layer);
    }
    s << ". ";
    event_link(s, context, attacker_general_hf);
    s << " led the attack, and the defenders were led by ";
    event_link(s, context, defender_general_hf);
}
