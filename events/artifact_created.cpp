#include "../helpers_event.h"

#include "df/history_event_artifact_createdst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_createdst *event)
{
    auto item = df::artifact_record::find(event->artifact_id);
    if (auto hf = df::historical_figure::find(event->creator_hfid))
    {
        event_link(s, context, hf);
        if (event->flags2.bits.name_only)
        {
            s << " bestowed a name upon ";
        }
        else
        {
            s << " created ";
        }
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        if (event->flags2.bits.name_only)
        {
            s << " was given a name";
        }
        else
        {
            s << " was created";
        }
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}
