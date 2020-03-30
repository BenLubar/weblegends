#include "../helpers_event.h"

#include "df/history_event_remove_hf_hf_linkst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_remove_hf_hf_linkst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    auto hf_target = df::historical_figure::find(event->hf_target);

    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_hf_link_type::SPOUSE:
        event_link(s, context, hf);
        s << " divorced ";
        event_link(s, context, hf_target);
        BREAK(type);
    default:
        // TODO
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (REMOVE_HF_HF_LINK)", event->id));
}
