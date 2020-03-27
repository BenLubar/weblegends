#include "../helpers_event.h"

#include "df/history_event_hf_act_on_buildingst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_act_on_buildingst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    event_link(s, context, hf);

    BEFORE_SWITCH(action, event->action);
    switch (action)
    {
    case df::history_event_hf_act_on_buildingst::T_action::Profane:
        s << " profaned ";
        BREAK(action);
    case df::history_event_hf_act_on_buildingst::T_action::Disturb:
        s << " disturbed ";
        BREAK(action);
    case df::history_event_hf_act_on_buildingst::T_action::PrayedInside:
        s << " prayed inside ";
        BREAK(action);
    }
    AFTER_SWITCH(action, stl_sprintf("event-%d (HF_ACT_ON_BUILDING)", event->id));

    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;
    if (structure)
    {
        s << "the";
        categorize(s, structure);
        s << " ";
        event_link(s, context, structure);
    }
    else
    {
        s << "an unknown structure";
    }

    if (site)
    {
        s << " in ";
        event_link(s, context, site);
    }
}
