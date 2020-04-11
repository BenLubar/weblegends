#include "../helpers_event.h"

#include "df/history_event_hist_figure_abductedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_abductedst *event)
{
    auto target = df::historical_figure::find(event->target);
    auto snatcher = df::historical_figure::find(event->snatcher);

    event_link(s, context, target);
    s << " was abudcted by ";
    event_link(s, context, snatcher);
    do_location(s, context, event);
}
