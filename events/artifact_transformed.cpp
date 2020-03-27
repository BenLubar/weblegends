#include "../helpers_event.h"

#include "df/history_event_artifact_transformedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_transformedst *event)
{
    auto new_artifact = df::artifact_record::find(event->new_artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto site = df::world_site::find(event->site);

    event_link(s, context, new_artifact);
    s << " was made from ";
    list_event_link<df::artifact_record>(s, context, event->old_artifact);
    s << " in ";
    event_link(s, context, site);
    s << " by ";
    event_link(s, context, histfig);
}
