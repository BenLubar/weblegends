#include "../helpers_event.h"

#include "df/history_event_artifact_recoveredst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_recoveredst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, artifact);
    s << " was recovered by ";
    event_link(s, context, histfig);

    do_location(s, context, event, " from ");
}
