#include "../helpers_event.h"

#include "df/history_event_entity_persecutedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_persecutedst *event)
{
    if (event->persecuting_hf != -1)
    {
        event_link(s, context, df::historical_figure::find(event->persecuting_hf));
        s << " of ";
    }
    event_link(s, context, df::historical_entity::find(event->persecuting_entity));
    s << " persecuted ";
    event_link(s, context, df::historical_entity::find(event->target_entity));

    if (event->shrines_destroyed > 0)
    {
        s << ", desecrating " << format_number(event->shrines_destroyed) << (event->shrines_destroyed == 1 ? " shrine" : " shrines");
    }

    do_location(s, context, event->site, -1, -1);

    if (!event->property_confiscated_from_hfs.empty() || !event->destroyed_structures.empty()
        || !event->expelled_hfs.empty() || !event->expelled_populations.empty()
        || !event->expelled_races.empty() || !event->expelled_counts.empty())
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
}
