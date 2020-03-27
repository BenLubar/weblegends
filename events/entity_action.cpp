#include "../helpers_event.h"

#include "df/history_event_entity_actionst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_actionst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, entity);
    BEFORE_SWITCH(action, event->action);
    switch (action)
    {
    case entity_action_type::entity_primary_criminals:
        s << " became the primary criminal organization in ";
        BREAK(action);
    case entity_action_type::entity_relocate:
        s << " moved to ";
        BREAK(action);
    }
    AFTER_SWITCH(action, stl_sprintf("event-%d (ENTITY_ACTION)", event->id));

    if (structure)
    {
        event_link(s, context, structure);
        s << " in ";
    }
    event_link(s, context, site);
}
