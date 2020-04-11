#include "../helpers_event.h"

#include "df/history_event_change_hf_body_statest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_body_statest *event)
{
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);

    std::string separator(" at ");

    BEFORE_SWITCH(body_state, event->body_state);
    switch (body_state)
    {
    case histfig_body_state::Active:
        s << " arose";
        separator = " from ";
        BREAK(body_state);
    case histfig_body_state::BuriedAtSite:
        s << " was buried";
        BREAK(body_state);
    case histfig_body_state::UnburiedAtBattlefield:
        s << " was left unburied on a battlefield";
        BREAK(body_state);
    case histfig_body_state::UnburiedAtSubregion:
    case histfig_body_state::UnburiedAtFeatureLayer:
    case histfig_body_state::UnburiedAtSite:
        s << " was left unburied";
        separator = " in ";
        BREAK(body_state);
    case histfig_body_state::EntombedAtSite:
        s << " was entombed";
        separator = " in ";
        BREAK(body_state);
    }
    AFTER_SWITCH(body_state, stl_sprintf("event-%d (CHANGE_HF_BODY_STATE)", event->id));

    do_location(s, context, event, separator);
}
