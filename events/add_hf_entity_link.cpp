#include "../helpers_event.h"

#include "df/history_event_add_hf_entity_linkst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_entity_linkst *event)
{
    auto ent = df::historical_entity::find(event->civ);
    auto hf = df::historical_figure::find(event->histfig);
    df::entity_position *pos;
    BEFORE_SWITCH(type, event->link_type);
    switch (type)
    {
    case histfig_entity_link_type::MEMBER:
        event_link(s, context, hf);
        s << " became a member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MEMBER:
        event_link(s, context, hf);
        s << " became a former member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::MERCENARY:
        event_link(s, context, hf);
        s << " became a mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MERCENARY:
        event_link(s, context, hf);
        s << " became a former mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SLAVE:
        event_link(s, context, hf);
        s << " became a slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SLAVE:
        event_link(s, context, hf);
        s << " became a former slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::PRISONER:
        event_link(s, context, hf);
        s << " became a prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_PRISONER:
        event_link(s, context, hf);
        s << " became a former prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::ENEMY:
        event_link(s, context, hf);
        s << " became an enemy of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::CRIMINAL:
        event_link(s, context, hf);
        s << " became a criminal of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " became ";
        if (pos->number == 1)
        {
            s << "the ";
        }
        else
        {
            s << "a ";
        }
        s << sex_name(hf, pos);
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " became a former ";
        s << sex_name(hf, pos);
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION_CLAIM:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " claimed the position of ";
        s << sex_name(hf, pos);
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SQUAD:
        event_link(s, context, hf);
        s << " became a squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SQUAD:
        event_link(s, context, hf);
        s << " became a former squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::OCCUPATION:
        event_link(s, context, hf);
        s << " became a worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_OCCUPATION:
        event_link(s, context, hf);
        s << " became a former worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));
}
