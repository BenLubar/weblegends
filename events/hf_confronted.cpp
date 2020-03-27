#include "../helpers_event.h"

#include "df/history_event_hf_confrontedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_confrontedst *event)
{
    auto target = df::historical_figure::find(event->target);

    event_link(s, context, target);

    BEFORE_SWITCH(accuser, event->accuser);
    switch (accuser)
    {
    case 0:
        s << " aroused general suspicion ";
        BREAK(accuser);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(accuser, stl_sprintf("event-%d (HF_CONFRONTED)", event->id));

    if (!event->reasons.empty())
    {
        s << " after ";
        list<int32_t>(s, event->reasons, [context, event](std::ostream & out, int32_t reason_id)
        {
            BEFORE_SWITCH(reason, reason_id);
            switch (reason)
            {
            case 0:
                out << "appearing not to age";
                BREAK(reason);
            case 1:
                out << "a murder";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __FILE__, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (HF_CONFRONTED)", event->id));
        });
    }

    do_location_2(s, context, event);
}
