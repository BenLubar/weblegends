#include "../helpers_event.h"

#include "df/history_event_artifact_givenst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_givenst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto giver_hf = df::historical_figure::find(event->giver_hf);
    auto giver_entity = df::historical_entity::find(event->giver_entity);
    auto receiver_hf = df::historical_figure::find(event->receiver_hf);
    auto receiver_entity = df::historical_entity::find(event->receiver_entity);

    event_link(s, context, artifact);
    s << " was offered to ";
    if (receiver_hf)
    {
        event_link(s, context, receiver_hf);
        if (receiver_entity)
        {
            s << " of ";
            event_link(s, context, receiver_entity);
        }
    }
    else
    {
        event_link(s, context, receiver_entity);
    }
    s << " by ";
    if (giver_hf)
    {
        event_link(s, context, giver_hf);
        if (giver_entity)
        {
            s << " of ";
            event_link(s, context, giver_entity);
        }
    }
    else
    {
        event_link(s, context, giver_entity);
    }
    do_circumstance_reason(s, context, event);
}
