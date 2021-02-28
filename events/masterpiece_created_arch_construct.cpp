#include "../helpers_event.h"

#include "df/history_event_masterpiece_created_arch_constructst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_arch_constructst *event)
{
    event_link(s, context, df::historical_figure::find(event->maker));
    s << " of ";
    event_link(s, context, df::historical_entity::find(event->maker_entity));
    s << " constructed a masterful ";
    s << ENUM_ATTR_STR(building_type, name, df::building_type(event->building_type));
    s << " at ";
    event_link(s, context, df::world_site::find(event->site));
}
