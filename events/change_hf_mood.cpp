#include "../helpers_event.h"

#include "df/history_event_change_hf_moodst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_moodst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);

    BEFORE_SWITCH(mood, event->mood);
    switch (mood)
    {
    case mood_type::None:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(mood);
    case mood_type::Fey:
        s << " was taken by a fey mood";
        BREAK(mood);
    case mood_type::Secretive:
        s << " withdrew from society";
        BREAK(mood);
    case mood_type::Possessed:
        s << " was possessed";
        BREAK(mood);
    case mood_type::Macabre:
        s << " began to skulk and brood";
        BREAK(mood);
    case mood_type::Fell:
        s << " was taken by a fell mood";
        BREAK(mood);
    case mood_type::Melancholy:
        s << " was striken by melancholy";
        BREAK(mood);
    case mood_type::Raving:
        s << " became crazed";
        BREAK(mood);
    case mood_type::Berserk:
        s << " went berserk";
        BREAK(mood);
    case mood_type::Baby:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(mood);
    case mood_type::Traumatized:
        s << " stopped responding to the outside world";
        BREAK(mood);
    }
    AFTER_SWITCH(mood, stl_sprintf("event-%d (CHANGE_HF_MOOD)", event->id));

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case history_event_reason::none:
        BREAK(reason);
    case history_event_reason::failed_mood:
        s << " after failing to create an artifact";
        BREAK(reason);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (CHANGE_HF_MOOD)", event->id));

    do_location(s, context, event);
}
