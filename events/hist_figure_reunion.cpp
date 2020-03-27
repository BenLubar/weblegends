#include "../helpers_event.h"

#include "df/history_event_hist_figure_reunionst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_reunionst *event)
{
    list_event_link<df::historical_figure>(s, context, event->missing);
    s << " " << (event->missing.size() == 1 ? "was" : "were") << " reunited with ";
    list_event_link<df::historical_figure>(s, context, event->reunited_with);

    if (auto assistant = df::historical_figure::find(event->assistant))
    {
        s << " with the help of ";
        event_link(s, context, assistant);
    }

    do_location_2(s, context, event);
}
