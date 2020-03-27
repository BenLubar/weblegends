#include "../helpers_event.h"

#include "df/history_event_written_content_composedst.h"
#include "df/written_content.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_written_content_composedst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    if (hf)
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown author";
    }
    s << " wrote ";
    if (auto content = df::written_content::find(event->content))
    {
        written_content(s, context, content, hf);
    }
    else
    {
        s << "[unknown document]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}
