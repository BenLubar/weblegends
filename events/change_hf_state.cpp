#include "../helpers_event.h"

#include "df/history_event_change_hf_statest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_statest *event)
{
    std::string separator = " in ";
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    BEFORE_SWITCH(state, event->state);
    switch (state)
    {
    case whereabouts_type::NONE:
        break;
    case whereabouts_type::wanderer:
        BEFORE_SWITCH(reason, event->reason);
        switch (reason)
        {
        case history_event_reason::none:
            s << " was wandering";
            BREAK(reason);
        case history_event_reason::flight:
            s << " fled";
            separator = " to ";
            BREAK(reason);
        default:
            break;
        }
        AFTER_SWITCH(reason, stl_sprintf("event-%d (CHANGE_HF_STATE) Wandering", event->id));
        BREAK(state);
    case whereabouts_type::settler:
        if (hf->born_year == event->year && event->seconds <= hf->born_seconds)
        {
            s << " was born";
        }
        else
        {
            s << " settled";
        }
        BREAK(state);
    case whereabouts_type::refugee:
        s << " became a refugee";
        BREAK(state);
    case whereabouts_type::army_died:
        break;
    case whereabouts_type::army_survived:
        break;
    case whereabouts_type::visitor:
        s << " visited";
        separator = " ";
        BREAK(state);
    }
    AFTER_SWITCH(state, stl_sprintf("event-%d (CHANGE_HF_STATE)", event->id));
    do_location(s, context, event, separator, true);
}
