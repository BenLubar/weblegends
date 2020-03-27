#include "../helpers_event.h"

#include "df/history_event_knowledge_discoveredst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_knowledge_discoveredst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    event_link(s, context, hf);
    if (event->first == 0)
    {
        s << " independently discovered ";
    }
    else
    {
        ASSUME_EQUAL(event->first, 1, stl_sprintf("event-%d (KNOWLEDGE_DISCOVERED)", event->id));
        s << " was the first to discover ";
    }
    knowledge(s, event->knowledge);
}
