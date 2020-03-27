#include "../helpers_event.h"

#include "df/history_event_artifact_storedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_storedst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
        s << " stored ";
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        s << " was stored";
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}
