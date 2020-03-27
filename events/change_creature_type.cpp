#include "../helpers_event.h"

#include "df/history_event_change_creature_typest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_creature_typest *event)
{
    auto changee = df::historical_figure::find(event->changee);
    auto changer = df::historical_figure::find(event->changer);
    auto old_race = df::creature_raw::find(event->old_race);
    auto old_caste = old_race ? vector_get(old_race->caste, event->old_caste) : nullptr;
    auto new_race = df::creature_raw::find(event->new_race);
    auto new_caste = new_race ? vector_get(new_race->caste, event->new_caste) : nullptr;

    event_link(s, context, changer);
    s << " changed ";
    event_link(s, context, changee);

    if (old_caste)
    {
        s << " from a " << old_caste->caste_name[0];
    }
    else if (old_race)
    {
        s << " from a " << old_race->name[0];
    }

    if (new_caste)
    {
        s << " into a " << new_caste->caste_name[0];
    }
    else if (new_race)
    {
        s << " into a " << new_race->name[0];
    }
}
