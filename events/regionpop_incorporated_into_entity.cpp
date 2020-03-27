#include "../helpers_event.h"

#include "df/history_event_regionpop_incorporated_into_entityst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_regionpop_incorporated_into_entityst *event)
{
    s << event->number_moved;
    if (auto race = df::creature_raw::find(event->pop_race))
    {
        s << " " << race->name[event->number_moved == 1 ? 0 : 1];
    }
    if (auto region = df::world_region::find(event->pop_region))
    {
        s << " from ";
        event_link(s, context, region);
    }
    if (auto layer = df::world_underground_region::find(event->pop_layer))
    {
        s << " from ";
        event_link(s, context, layer);
    }
    s << " joined ";
    auto ent = df::historical_entity::find(event->join_entity);
    event_link(s, context, ent);
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
}
