#include "../helpers_event.h"

#include "df/history_event_artifact_destroyedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_destroyedst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    if (auto hf = df::historical_figure::find(event->destroyer_hf))
    {
        event_link(s, context, hf);
        if (auto civ = df::historical_entity::find(event->destroyer_civ))
        {
            s << " of ";
            event_link(s, context, civ);
        }
        s << " destroyed ";
        event_link(s, context, item);
    }
    else if (auto civ = df::historical_entity::find(event->destroyer_civ))
    {
        event_link(s, context, civ);
        s << " destroyed ";
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        s << " was destroyed";
    }

    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}
