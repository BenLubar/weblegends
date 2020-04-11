#include "../helpers_event.h"

#include "df/history_event_hist_figure_revivedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_revivedst *event)
{
    event_link(s, context, df::historical_figure::find(event->histfig));
    s << " came back to life";
    if (event->flags2.bits.again)
    {
        s << " again";
    }

    BEFORE_SWITCH(type, event->ghost_type);
    switch (type)
    {
    case ghost_type::None:
        BREAK(type);
    case ghost_type::MurderousGhost:
        s << " as a murderous ghost";
        BREAK(type);
    case ghost_type::SadisticGhost:
        s << " as a sadistic ghost";
        BREAK(type);
    case ghost_type::SecretivePoltergeist:
        s << " as a secretive poltergeist";
        BREAK(type);
    case ghost_type::EnergeticPoltergeist:
        s << " as an energetic poltergeist";
        BREAK(type);
    case ghost_type::AngryGhost:
        s << " as an angry ghost";
        BREAK(type);
    case ghost_type::ViolentGhost:
        s << " as a violent ghost";
        BREAK(type);
    case ghost_type::MoaningSpirit:
        s << " as a moaning spirit";
        BREAK(type);
    case ghost_type::HowlingSpirit:
        s << " as a howling spirit";
        BREAK(type);
    case ghost_type::TroublesomePoltergeist:
        s << " as a troublesome poltergeist";
        BREAK(type);
    case ghost_type::RestlessHaunt:
        s << " as a restless haunt";
        BREAK(type);
    case ghost_type::ForlornHaunt:
        s << " as a forlorn haunt";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_REVIVED)", event->id));
    do_location(s, context, event);
}
