#include "../helpers_event.h"

#include "df/history_event_hist_figure_woundedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_woundedst *event)
{
    auto wounder = df::historical_figure::find(event->wounder);
    event_link(s, context, wounder);

    std::string suffix;
    BEFORE_SWITCH(type, event->injury_type);
    switch (type)
    {
    case df::history_event_hist_figure_woundedst::T_injury_type::Smash:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " smashed";
            BREAK(part_lost);
        case 1:
            s << "crushed";
            suffix = " to a pulp";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Smash", event->id));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Slash:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " cut";
            BREAK(part_lost);
        case 1:
            s << " cut";
            suffix = " off";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Slash", event->id));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Stab:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " stabbed";
            BREAK(part_lost);
        case 1:
            s << " punctured";
            suffix = " into an indistinguishable mess";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Stab", event->id));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Rip:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " ripped";
            BREAK(part_lost);
        case 1:
            s << " tore";
            suffix = " off";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Rip", event->id));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Burn:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " burned";
            BREAK(part_lost);
        case 1:
            s << " burned";
            suffix = " beyond recognition";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Burn", event->id));
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED)", event->id));

    df::creature_raw *race = df::creature_raw::find(event->woundee_race);
    df::caste_raw *caste = race ? race->caste.at(event->woundee_caste) : nullptr;

    auto woundee = df::historical_figure::find(event->woundee);
    if (woundee)
    {
        s << " ";
        event_link(s, context, woundee);
        s << "&rsquo;s ";
    }
    else
    {
        s << " the ";
    }

    df::body_part_raw *bp = caste ? caste->body_info.body_parts.at(event->body_part) : nullptr;
    if (bp)
    {
        s << *bp->name_singular.at(0);
    }
    else
    {
        s << "[unknown body part]";
    }

    if (woundee == nullptr && caste != nullptr)
    {
        s << " of a " << caste->caste_name[0];
    }

    s << suffix;

    do_location_2(s, context, event);
}
