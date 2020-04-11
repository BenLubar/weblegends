#include "../helpers_event.h"

#include "df/history_event_hist_figure_woundedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_woundedst *event)
{
    auto wounder = df::historical_figure::find(event->wounder);
    auto woundee = df::historical_figure::find(event->woundee);

    df::creature_raw *race = df::creature_raw::find(event->woundee_race);
    df::caste_raw *caste = race ? vector_get(race->caste, event->woundee_caste) : nullptr;
    df::body_part_raw *bp = caste ? vector_get(caste->body_info.body_parts, event->body_part) : nullptr;
    bool embedded = bp && bp->flags.is_set(body_part_raw_flags::EMBEDDED);

    event_link(s, context, woundee);
    s << RSQUO "s ";
    if (bp)
    {
        s << html_escape(*bp->name_singular.at(0));
    }
    else
    {
        s << "[unknown body part]";
    }
    s << " was ";

    using injury_type = df::history_event_hist_figure_woundedst::T_injury_type;
    BEFORE_SWITCH(type, event->injury_type);
    switch (type)
    {
    case injury_type::Smash:
        if (!event->part_lost)
            s << "smashed";
        else
            s << "broken away";
        BREAK(type);
    case injury_type::Slash:
        if (!event->part_lost)
            s << "slashed";
        else if (embedded)
            s << "slashed out";
        else
            s << "slashed off";
        BREAK(type);
    case injury_type::Stab:
        if (!event->part_lost)
            s << "stabbed";
        else if (embedded)
            s << "stabbed out";
        else
            s << "ripped off";
        BREAK(type);
    case injury_type::Rip:
        if (!event->part_lost)
            s << "ripped";
        else if (embedded)
            s << "torn out";
        else
            s << "torn off";
        BREAK(type);
    case injury_type::Burn:
        if (!event->part_lost)
            s << "burned";
        else if (embedded)
            s << "burned out";
        else
            s << "burned away";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED)", event->id));

    if (wounder)
    {
        s << " by ";
        event_link(s, context, wounder);

        if (event->flags2.bits.torture)
        {
            s << " as a means of torture";
        }
    }

    do_location(s, context, event);
}
