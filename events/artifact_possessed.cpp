#include "../helpers_event.h"

#include "df/history_event_artifact_possessedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_possessedst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto site = df::world_site::find(event->site);

    event_link(s, context, histfig);
    s << " took ";
    event_link(s, context, artifact);
    s << " from ";
    event_link(s, context, site);

    do_circumstance_reason(s, context, event);
}
