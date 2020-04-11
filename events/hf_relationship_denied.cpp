#include "../helpers_event.h"

#include "df/history_event_hf_relationship_deniedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_relationship_deniedst *event)
{
    auto seeker_hf = df::historical_figure::find(event->seeker_hf);
    auto target_hf = df::historical_figure::find(event->target_hf);

    event_link(s, context, seeker_hf);

    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case unit_relationship_type::Apprentice:
        s << " was denied an apprenticeship under ";
        BREAK(type);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HF_RELATIONSHIP_DENIED)", event->id));

    event_link(s, context, target_hf);

    s << " as ";

    if (event->reason_id == event->seeker_hf)
    {
        s << "the former";
    }
    else if (event->reason_id == event->target_hf)
    {
        s << "the latter";
    }
    else
    {
        event_link(s, context, df::historical_figure::find(event->reason_id));
    }

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case history_event_reason::prefers_working_alone:
        s << " prefers to work alone";
        BREAK(reason);
    case history_event_reason::jealousy:
        s << " was jealous";
        BREAK(reason);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (HF_RELATIONSHIP_DENIED)", event->id));

    do_location(s, context, event);
}
