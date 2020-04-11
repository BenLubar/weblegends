#include "../helpers_event.h"

#include "df/history_event_hist_figure_simple_battle_eventst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_battle_eventst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group1);
    BEFORE_SWITCH(type, event->subtype);
    switch (type)
    {
    case history_event_simple_battle_subtype::SCUFFLE:
        s << " had a scuffle with ";
        BREAK(type);
    case history_event_simple_battle_subtype::ATTACK:
        s << " attacked ";
        BREAK(type);
    case history_event_simple_battle_subtype::SURPRISE:
        s << " surprised ";
        BREAK(type);
    case history_event_simple_battle_subtype::AMBUSH:
        s << " ambushed ";
        BREAK(type);
    case history_event_simple_battle_subtype::HAPPEN_UPON:
        s << " happened upon ";
        BREAK(type);
    case history_event_simple_battle_subtype::CORNER:
        s << " cornered ";
        BREAK(type);
    case history_event_simple_battle_subtype::CONFRONT:
        s << " confronted ";
        BREAK(type);
    case history_event_simple_battle_subtype::LOSE_AFTER_RECEIVE_WOUND:
    case history_event_simple_battle_subtype::LOSE_AFTER_INFLICT_WOUND:
    case history_event_simple_battle_subtype::LOSE_AFTER_EXCHANGE_WOUND:
        s << " attacked ";
        BREAK(type);
    case history_event_simple_battle_subtype::SUBDUED:
        s << " subdued ";
        BREAK(type);
    case history_event_simple_battle_subtype::GOT_INTO_A_BRAWL:
        s << " got into a brawl with ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_SIMPLE_BATTLE_EVENT)", event->id));
    list_event_link<df::historical_figure>(s, context, event->group2);
    switch (event->subtype)
    {
    case history_event_simple_battle_subtype::LOSE_AFTER_RECEIVE_WOUND:
        s << " and was wounded but escaped";
        break;
    case history_event_simple_battle_subtype::LOSE_AFTER_INFLICT_WOUND:
        s << " and inflicted a wound before escaping";
        break;
    case history_event_simple_battle_subtype::LOSE_AFTER_EXCHANGE_WOUND:
        s << " and exchanged wounds before escaping";
        break;
    default:
        break;
    }
    do_location(s, context, event);
}
