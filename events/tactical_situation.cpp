#include "../helpers_event.h"

#include "df/history_event_tactical_situationst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_tactical_situationst *event)
{
    auto a_tactician = df::historical_figure::find(event->a_tactician_hfid);
    auto d_tactician = df::historical_figure::find(event->d_tactician_hfid);

    int tactical_outcome = event->a_tactics_roll < event->d_tactics_roll ?
        (event->a_tactics_roll > event->d_tactics_roll / 2 ? 2 : 3) :
        (event->a_tactics_roll / 2 < event->d_tactics_roll ? 1 : 0);

    if (a_tactician && d_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " outmatched ";
            }
            else
            {
                s << " entirely outwitted ";
            }
            event_link(s, context, d_tactician);
            break;
        case 1:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s tactical planning was superior to ";
            }
            else
            {
                s << " outmaneuvered ";
            }
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s";
            }
            break;
        case 2:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s tactical planning was superior to ";
            }
            else
            {
                s << " outmaneuvered ";
            }
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s";
            }
            break;
        case 3:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " outmatched ";
            }
            else
            {
                s << " entirely outwitted ";
            }
            event_link(s, context, a_tactician);
            break;
        }
    }
    else if (a_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " unrolled a brilliant tactical plan";
            }
            else
            {
                s << " hatched a stunning strategy";
            }
            break;
        case 1:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " put forth a sound plan";
            }
            else
            {
                s << " used good tactics";
            }
            break;
        case 2:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made a poor plan";
            }
            else
            {
                s << " used poor tactics";
            }
            break;
        case 3:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made an outright foolish plan";
            }
            else
            {
                s << " blundered terribly";
            }
            break;
        }
    }
    else if (d_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made an outright foolish plan";
            }
            else
            {
                s << " blundered terribly";
            }
            break;
        case 1:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made a poor plan";
            }
            else
            {
                s << " used poor tactics";
            }
            break;
        case 2:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " put forth a sound plan";
            }
            else
            {
                s << " used good tactics";
            }
            break;
        case 3:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " unrolled a brilliant tactical plan";
            }
            else
            {
                s << " hatched a stunning strategy";
            }
            break;
        }
    }
    else
    {
        // XXX: as of 0.44.07, the game gives a nonsensical "the forced shifted" or "the forced were arrayed" for this case

        BEFORE_SWITCH(situation, event->situation);
        switch (situation)
        {
        case tactical_situation::attacker_strongly_favored:
            s << "The attackers had a strong positional advantage";
            BREAK(situation);
        case tactical_situation::attacker_favored:
            s << "The attackers had a position advantage";
            BREAK(situation);
        case tactical_situation::attacker_slightly_favored:
            s << "The attackers had a slight position advantage";
            BREAK(situation);
        case tactical_situation::defender_strongly_favored:
            s << "The defenders had a strong position advantage";
            BREAK(situation);
        case tactical_situation::defender_favored:
            s << "The defenders had a position advantage";
            BREAK(situation);
        case tactical_situation::defender_slightly_favored:
            s << "The defenders had a slight position advantage";
            BREAK(situation);
        case tactical_situation::neither_favored:
            s << "Neither side had a position advantage";
            BREAK(situation);
        }
        AFTER_SWITCH(situation, stl_sprintf("event-%d (TACTICAL_SITUATION)", event->id));

        do_location(s, context, event);

        return;
    }

    switch (event->situation)
    {
    case tactical_situation::attacker_strongly_favored:
    case tactical_situation::attacker_favored:
    case tactical_situation::attacker_slightly_favored:
        s << (tactical_outcome < 2 ? ", and " : ", but ");
        break;
    case tactical_situation::defender_strongly_favored:
    case tactical_situation::defender_favored:
    case tactical_situation::defender_slightly_favored:
        s << (tactical_outcome < 2 ? ", but " : ", and ");
        break;
    case tactical_situation::neither_favored:
        s << ", but ";
        break;
    }

    BEFORE_SWITCH(situation, event->situation);
    switch (situation)
    {
    case tactical_situation::attacker_strongly_favored:
        s << "the attackers had a strong positional advantage";
        BREAK(situation);
    case tactical_situation::attacker_favored:
        s << "the attackers had a position advantage";
        BREAK(situation);
    case tactical_situation::attacker_slightly_favored:
        s << "the attackers had a slight position advantage";
        BREAK(situation);
    case tactical_situation::defender_strongly_favored:
        s << "the defenders had a strong position advantage";
        BREAK(situation);
    case tactical_situation::defender_favored:
        s << "the defenders had a position advantage";
        BREAK(situation);
    case tactical_situation::defender_slightly_favored:
        s << "the defenders had a slight position advantage";
        BREAK(situation);
    case tactical_situation::neither_favored:
        s << "neither side had a position advantage";
        BREAK(situation);
    }
    AFTER_SWITCH(situation, stl_sprintf("event-%d (TACTICAL_SITUATION)", event->id));

    do_location(s, context, event);
}
