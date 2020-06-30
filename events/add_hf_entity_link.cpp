#include "../helpers_event.h"

#include "df/history_event_add_hf_entity_linkst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_entity_linkst *event)
{
    auto ent = df::historical_entity::find(event->civ);
    auto hf = df::historical_figure::find(event->histfig);
    auto pos = ent ? binsearch_in_vector(ent->positions.own, event->position_id) : nullptr;

    event_link(s, context, hf);

    BEFORE_SWITCH(type, event->link_type);
    switch (type)
    {
    case histfig_entity_link_type::MEMBER:
        s << " became a member of ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_MEMBER:
        s << " became a former member of ";
        BREAK(type);
    case histfig_entity_link_type::MERCENARY:
        s << " became a mercenary for ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_MERCENARY:
        s << " became a former mercenary of ";
        BREAK(type);
    case histfig_entity_link_type::SLAVE:
        s << " was enslaved by ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_SLAVE:
        s << " became a former slave of ";
        BREAK(type);
    case histfig_entity_link_type::PRISONER:
        s << " was imprisoned by ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_PRISONER:
        s << " became a former prisoner of ";
        BREAK(type);
    case histfig_entity_link_type::ENEMY:
        s << " became an enemy of ";
        BREAK(type);
    case histfig_entity_link_type::CRIMINAL:
        s << " became a criminal in the eyes of ";
        BREAK(type);
    case histfig_entity_link_type::POSITION:
        s << " became ";
        s << (pos->number == 1 ? "the" : "a");
        s << sex_name(hf, pos);
        s << " of ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_POSITION:
        s << " became a former ";
        s << sex_name(hf, pos);
        s << " of ";
        BREAK(type);
    case histfig_entity_link_type::POSITION_CLAIM:
        s << " a claimant for ";
        s << sex_name(hf, pos);
        s << " of ";
        BREAK(type);
    case histfig_entity_link_type::SQUAD:
        s << " became a ";
        s << pos->squad[0];
        s << " of ";
        BREAK(type);
    case histfig_entity_link_type::FORMER_SQUAD:
        s << " became a former ";
        s << pos->squad[0];
        s << " of ";
        BREAK(type);
    case histfig_entity_link_type::OCCUPATION:
        s << " became a worker of ";
        // TODO: does DF store occupation type in this event?
        BREAK(type);
    case histfig_entity_link_type::FORMER_OCCUPATION:
        s << " became a former worker of ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));

    event_link(s, context, ent);

    if (auto appointer = df::historical_figure::find(event->appointer_hfid))
    {
        s << ", appointed by ";
        event_link(s, context, appointer);
    }
}
