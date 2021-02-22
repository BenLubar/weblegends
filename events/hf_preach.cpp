#include "../helpers_event.h"

#include "df/history_event_hf_preachst.h"
#include "df/reputation_type.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_preachst *event)
{
    event_link(s, context, df::historical_figure::find(event->speaker_hf));
    s << " preached to ";
    event_link(s, context, df::historical_entity::find(event->entity1));
    BEFORE_SWITCH(topic, event->topic);
    switch (topic)
    {
        case reputation_type::RespectedGroup:
            s << ", inveighing against ";
            BREAK(topic);
        case reputation_type::HatedGroup:
            s << ", urging love to be shown to ";
            BREAK(topic);
        default:
            do_event_missing(s, context, event, __FILE__, __LINE__);
            break;
    }
    AFTER_SWITCH(topic, stl_sprintf("event-%d (HF_PREACH)", event->id));
    event_link(s, context, df::historical_entity::find(event->entity2));
    do_location(s, context, event->site, -1, -1);
}
