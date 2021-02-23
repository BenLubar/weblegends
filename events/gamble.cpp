#include "../helpers_event.h"

#include "df/history_event_gamblest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_gamblest *event)
{
    event_link(s, context, df::historical_figure::find(event->hf));

    int32_t earnings = event->account_after - event->account_before;

    if (earnings >= 5000)
    {
        s << " made a fortune";
    }
    else if (earnings <= -5000)
    {
        s << " lost a fortune";
    }
    else if (earnings >= 1000)
    {
        s << " did well";
    }
    else if (earnings <= -1000)
    {
        s << " did poorly";
    }
    else
    {
        s << " broke even";
    }

    s << " gambling";

    if (!context.structure || context.structure->id != event->structure || context.structure->site_id != event->site)
    {
        do_location(s, context, event->site, -1, -1, event->structure, " at ");
    }

    if (event->account_after < 0)
    {
        s << " and went";
        if (event->account_before < 0)
        {
            s << " further";
        }
        s << " into debt";
    }
}
