#include "../helpers_event.h"

void do_circumstance_reason(std::ostream & s, const event_context & context, df::history_event *event, df::history_event_circumstance_info & circumstance, df::history_event_reason_info & reason)
{
    BEFORE_SWITCH(reason_type, reason.type);
    switch (reason_type)
    {
    case history_event_reason::none:
        BREAK(reason_type);
    case history_event_reason::glorify_hf:
        s << " in order to glorify ";
        event_link(s, context, df::historical_figure::find(reason.data.glorify_hf));
        BREAK(reason_type);
    case history_event_reason::artifact_is_heirloom_of_family_hfid:
        s << " of the ";
        event_link(s, context, df::historical_figure::find(reason.data.artifact_is_heirloom_of_family_hfid));
        s << " family";
        BREAK(reason_type);
    case history_event_reason::as_a_symbol_of_everlasting_peace:
        s << " as a symbol of everlasting peace";
        BREAK(reason_type);
    case history_event_reason::artifact_is_symbol_of_entity_position:
        s << " as a symbol of authority witin ";
        event_link(s, context, df::historical_entity::find(reason.data.artifact_is_symbol_of_entity_position));
        BREAK(reason_type);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(reason_type, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));

    BEFORE_SWITCH(circumstance_type, circumstance.type);
    switch (circumstance_type)
    {
    case unit_thought_type::None:
        BREAK(circumstance_type);
    case unit_thought_type::Death:
        s << " after the death of ";
        event_link(s, context, df::historical_figure::find(circumstance.data.Death));
        BREAK(circumstance_type);
    case unit_thought_type::Prayer:
        s << " after praying to ";
        event_link(s, context, df::historical_figure::find(circumstance.data.Prayer));
        BREAK(circumstance_type);
    case unit_thought_type::DreamAbout:
        s << " after dreaming about ";
        event_link(s, context, df::historical_figure::find(circumstance.data.DreamAbout));
        BREAK(circumstance_type);
    case unit_thought_type::Dream:
        s << " after a dream";
        BREAK(circumstance_type);
    case unit_thought_type::Nightmare:
        s << " after a nightmare";
        BREAK(circumstance_type);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(circumstance_type, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));
}
