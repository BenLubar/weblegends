#include "../helpers_event.h"

#include "df/history_event_artifact_copiedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_copiedst *event)
{
    event_link(s, context, df::historical_entity::find(event->entity_src));
    s << " made a copy of ";
    if (event->flags2.bits.from_original)
    {
        s << "the original ";
    }
    event_link(s, context, df::artifact_record::find(event->artifact));
    do_location(s, context, event->site_src, -1, -1, event->structure_src);
    if (event->entity_src != event->entity_dest)
    {
        s << " for ";
        event_link(s, context, df::historical_entity::find(event->entity_dest));
    }
    do_location(s, context, event->site_dest, -1, -1, event->structure_dest, ", storing it in ");
}
