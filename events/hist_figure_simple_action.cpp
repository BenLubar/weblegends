#include "../helpers_event.h"

#include "df/history_event_hist_figure_simple_actionst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_actionst *event)
{
    list<int32_t>(s, event->group_hfs, [&](std::ostream & out, int32_t id)
        {
            event_link(out, context, df::historical_figure::find(id));
        });

    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
        case simple_action_type::carouse:
            s << " caroused";
            BREAK(type);
        case simple_action_type::purchase_well_crafted_equipment:
            s << " purchased well-crafted equipment";
            BREAK(type);
        case simple_action_type::purchase_finely_crafted_equipment:
            s << " purchased finely-crafted equipment";
            BREAK(type);
        case simple_action_type::purchase_superior_equipment:
            s << " purchased superior equipment";
            BREAK(type);
        case simple_action_type::purchase_exceptional_equipment:
            s << " purchased exceptional equipment";
            BREAK(type);
        case simple_action_type::purchase_masterwork_equipment:
            s << " purchased masterwork equipment";
            BREAK(type);
        case simple_action_type::performe_horrible_experiments:
            s << " performed horrible experiments";
            BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_SIMPLE_ACTION)", event->id));

    do_location(s, context, event);
}
