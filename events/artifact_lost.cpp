#include "../helpers_event.h"

#include "df/history_event_artifact_lostst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_lostst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    event_link(s, context, item);
    s << " was lost";
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}
