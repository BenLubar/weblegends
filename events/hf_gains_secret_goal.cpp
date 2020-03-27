#include "../helpers_event.h"

#include "df/history_event_hf_gains_secret_goalst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_gains_secret_goalst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);
    event_link(s, context, histfig);

    BEFORE_SWITCH(goal, event->goal);
    switch (goal)
    {
    case goal_type::STAY_ALIVE:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(goal);
    case goal_type::MAINTAIN_ENTITY_STATUS:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(goal);
    case goal_type::START_A_FAMILY:
        s << " began dreaming of starting a family";
        BREAK(goal);
    case goal_type::RULE_THE_WORLD:
        s << " came to desire to rule the world";
        BREAK(goal);
    case goal_type::CREATE_A_GREAT_WORK_OF_ART:
        s << " began dreaming of creating a great work of art";
        BREAK(goal);
    case goal_type::CRAFT_A_MASTERWORK:
        s << " began dreaming of crafting a masterwork";
        BREAK(goal);
    case goal_type::BRING_PEACE_TO_THE_WORLD:
        s << " began dreaming of bringing peace to the world";
        BREAK(goal);
    case goal_type::BECOME_A_LEGENDARY_WARRIOR:
        s << " began dreaming of becoming a legendary warrior";
        BREAK(goal);
    case goal_type::MASTER_A_SKILL:
        s << " began dreaming of mastering a skill";
        BREAK(goal);
    case goal_type::FALL_IN_LOVE:
        s << " began dreaming of falling in love";
        BREAK(goal);
    case goal_type::SEE_THE_GREAT_NATURAL_SITES:
        s << " began dreaming of seeing the great natural wonders of the world";
        BREAK(goal);
    case goal_type::IMMORTALITY:
        BEFORE_SWITCH(sex, histfig ? histfig->sex : -1);
        switch (sex)
        {
        case -1:
            s << " became obsessed with its own mortality and sought to extend its life by any means";
            BREAK(sex);
        case 0:
            s << " became obsessed with her own mortality and sought to extend her life by any means";
            BREAK(sex);
        case 1:
            s << " became obsessed with his own mortality and sought to extend his life by any means";
            BREAK(sex);
        }
        AFTER_SWITCH(sex, stl_sprintf("event-%d (HF_GAINS_SECRET_GOAL:IMMORTALITY)", event->id));
        BREAK(goal);
    case goal_type::MAKE_A_GREAT_DISCOVERY:
        s << " began dreaming of making a great discovery";
        BREAK(goal);
    case goal_type::ATTAINING_RANK_IN_SOCIETY:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(goal);
    case goal_type::BATHING_THE_WORLD_IN_CHAOS:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(goal);
    }
    AFTER_SWITCH(goal, stl_sprintf("event-%d (HF_GAINS_SECRET_GOAL)", event->id));
}
