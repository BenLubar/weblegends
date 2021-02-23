#include "../helpers_event.h"

#include "df/history_event_hist_figure_diedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_diedst *event)
{
    std::string weapon_prefix = " with ";
    std::string prefix;
    std::string no_weapon_text;
    std::string no_weapon_prefix;

    auto victim = df::historical_figure::find(event->victim_hf);
    event_link(s, context, victim);

    BEFORE_SWITCH(cause, event->death_cause);
    switch (cause)
    {
    case death_type::NONE:
#ifdef WEBLEGENDS_DEBUG
        weblegends_debug_log() << "[weblegends] [hist_figure_died.cpp:" << __LINE__ << "] history_event_hist_figure_diedst.death_cause is NONE: event-" << event->id << std::endl;
#endif
        s << " died";
        weapon_prefix = ", killed with ";
        no_weapon_prefix = " ";
        prefix = ", killed";
        BREAK(cause);
    case death_type::OLD_AGE:
        s << " died of old age";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::HUNGER:
        s << " starved to death";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::THIRST:
        s << " died of thirst";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::SHOT:
        s << " was shot and killed";
        BREAK(cause);
    case death_type::BLEED:
        s << " bled to death";
        prefix = ", killed";
        BREAK(cause);
    case death_type::DROWN:
        s << " drowned";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SUFFOCATE:
        s << " suffocated";
        weapon_prefix = " after being hit with ";
        prefix = ", strangled";
        BREAK(cause);
    case death_type::STRUCK_DOWN:
        s << " was slain";
        BREAK(cause);
    case death_type::SCUTTLE:
        s << " was scuttled";
        BREAK(cause);
    case death_type::COLLISION:
        s << " died in a collision";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MAGMA:
        s << " was boiled alive in magma";
        prefix = ", pushed";
        BREAK(cause);
    case death_type::MAGMA_MIST:
        s << " got too close to magma";
        prefix = ", killed";
        BREAK(cause);
    case death_type::DRAGONFIRE:
        s << " was burned to a crisp";
        BREAK(cause);
    case death_type::FIRE:
        s << " burned to death";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SCALD:
        s << " was scalded";
        BREAK(cause);
    case death_type::CAVEIN:
        s << " was crushed in a cave-in";
        prefix = " caused";
        BREAK(cause);
    case death_type::DRAWBRIDGE:
        s << " was crushed by a drawbridge";
        prefix = " operated";
        BREAK(cause);
    case death_type::FALLING_ROCKS:
        s << " was crushed by falling rocks";
        prefix = " dropped";
        BREAK(cause);
    case death_type::CHASM:
        s << " fell into a deep chasm";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = ", pushed";
        prefix = " ";
        BREAK(cause);
    case death_type::CAGE:
        s << " died in a cage";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MURDER:
        s << " was murdered";
        BREAK(cause);
    case death_type::TRAP:
        s << " died in a trap";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::VANISH:
        s << " vanished into thin air";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::QUIT:
        s << " gave into starvation";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ABANDON:
        s << " was abandoned";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::HEAT:
        s << " died of heat";
        prefix = ", killed";
        BREAK(cause);
    case death_type::COLD:
        s << " died of cold";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SPIKE:
        s << " died on a spike";
        prefix = ", killed";
        BREAK(cause);
    case death_type::ENCASE_LAVA:
        s << " was encased in cooling lava";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ENCASE_MAGMA:
        s << " was encased in cooling magma";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ENCASE_ICE:
        s << " was encased in ice";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::BEHEAD:
        s << " was beheaded";
        BREAK(cause);
    case death_type::CRUCIFY:
        s << " was crucified";
        BREAK(cause);
    case death_type::BURY_ALIVE:
        s << " was buried alive";
        BREAK(cause);
    case death_type::DROWN_ALT:
        s << " was drowned";
        BREAK(cause);
    case death_type::BURN_ALIVE:
        s << " was burned alive";
        BREAK(cause);
    case death_type::FEED_TO_BEASTS:
        s << " was fed to beasts";
        BREAK(cause);
    case death_type::HACK_TO_PIECES:
        s << " was hacked to pieces";
        BREAK(cause);
    case death_type::LEAVE_OUT_IN_AIR:
        s << " was left out in the air";
        BREAK(cause);
    case death_type::BOIL:
        s << " boiled";
        prefix = ", killed";
        BREAK(cause);
    case death_type::MELT:
        s << " melted";
        prefix = ", killed";
        BREAK(cause);
    case death_type::CONDENSE:
        s << " condensed";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SOLIDIFY:
        s << " solidified";
        prefix = ", killed";
        BREAK(cause);
    case death_type::INFECTION:
        s << " succumbed to infection";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MEMORIALIZE:
        s << " was laid to rest";
        BREAK(cause);
    case death_type::SCARE:
        s << " was scared to death";
        BREAK(cause);
    case death_type::DARKNESS:
        s << " died in the dark";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::COLLAPSE:
        s << " collapsed";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::DRAIN_BLOOD:
        s << " was drained of blood";
        BREAK(cause);
    case death_type::SLAUGHTER:
        s << " was slaughtered";
        BREAK(cause);
    case death_type::VEHICLE:
        s << " was killed by ";
        weapon_prefix = "the vehicle ";
        no_weapon_text = "a vehicle";
        prefix = " after being attacked";
        BREAK(cause);
    case death_type::FALLING_OBJECT:
        s << " was killed by a falling ";
        weapon_prefix = "";
        no_weapon_text = "object";
        prefix = " after being attacked";
        BREAK(cause);
    case death_type::LEAPT_FROM_HEIGHT:
        s << " fell off a cliff";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::DROWN_ALT2:
        s << " drowned";
        prefix = ", killed";
        BREAK(cause);
    case death_type::EXECUTION_GENERIC:
        s << " was executed";
        BREAK(cause);
    }
    AFTER_SWITCH(cause, stl_sprintf("event-%d (HIST_FIGURE_DIED)", event->id));
    if (!do_weapon(s, context, event->weapon, weapon_prefix))
    {
        s << no_weapon_text;
        if (!no_weapon_prefix.empty())
        {
            prefix = no_weapon_prefix;
        }
    }
    if (auto slayer = df::historical_figure::find(event->slayer_hf))
    {
        s << prefix << " by ";
        event_link(s, context, slayer);
    }
    else if (auto race = df::creature_raw::find(event->slayer_race))
    {
        auto caste = race->caste.at(event->slayer_caste);
        s << prefix << " by a " << caste->caste_name[0];
    }
    if (victim->born_year > -1)
    {
        int32_t years, days;
        age_years_days(victim->born_year, victim->born_seconds, event->year, event->seconds, years, days);
        if (years != 0)
        {
            s << " at the age of " << years;
            if (days >= 28 * 9)
            {
                s << "&frac34;";
            }
            else if (days >= 28 * 6)
            {
                s << "&frac12;";
            }
            else if (days >= 28 * 3)
            {
                s << "&frac14;";
            }
        }
        else if (days > 0)
        {
            s << " at only " << days << " days old";
        }
    }
    do_location(s, context, event);
}
