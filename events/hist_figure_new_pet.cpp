#include "../helpers_event.h"

#include "df/history_event_hist_figure_new_petst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_new_petst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group);
    s << " tamed ";
    list<int16_t>(s, event->pets, [](std::ostream & out, int16_t id)
    {
        if (auto race = df::creature_raw::find(id))
        {
            out << "the " << race->name[1];
        }
        else
        {
            out << "[unknown race]";
        }
    });
    do_location(s, context, event, " of ");
}
