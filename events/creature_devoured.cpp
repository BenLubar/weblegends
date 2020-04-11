#include "../helpers_event.h"

#include "df/history_event_creature_devouredst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_creature_devouredst *event)
{
    auto eater = df::historical_figure::find(event->eater);
    event_link(s, context, eater);
    s << " devoured ";
    if (auto victim = df::historical_figure::find(event->victim))
    {
        event_link(s, context, victim);
    }
    else if (auto race = df::creature_raw::find(event->race))
    {
        auto caste = race->caste.at(event->caste);
        s << "a " << caste->caste_name[0];
        if (auto ent = df::historical_entity::find(event->entity))
        {
            s << " owned by ";
            event_link(s, context, ent);
        }
    }
    do_location(s, context, event);
}
