#include "../helpers_event.h"

#include "df/history_event_hist_figure_travelst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_travelst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group);
    std::string prefix = " to ";
    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case df::history_event_hist_figure_travelst::T_reason::Journey:
        s << " made a journey";
        BREAK(reason);
    case df::history_event_hist_figure_travelst::T_reason::Return:
        s << " returned";
        BREAK(reason);
    case df::history_event_hist_figure_travelst::T_reason::Escape:
        s << " escaped";
        prefix = " from ";
        BREAK(reason);
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (HIST_FIGURE_TRAVEL)", event->id));
    do_location_2(s, context, event, prefix);
}
