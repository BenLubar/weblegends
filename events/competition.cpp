#include "../helpers_event.h"

#include "df/dance_form.h"
#include "df/entity_occasion.h"
#include "df/entity_occasion_info.h"
#include "df/entity_occasion_schedule.h"
#include "df/history_event_competitionst.h"
#include "df/musical_form.h"
#include "df/poetic_form.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_competitionst *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case occasion_schedule_type::DANCE_COMPETITION:
        if (auto form = df::dance_form::find(schedule->reference))
        {
            s << "a competition of the dance ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a dance competition";
        }
        BREAK(type);
    case occasion_schedule_type::MUSICAL_COMPETITION:
        if (auto form = df::musical_form::find(schedule->reference))
        {
            s << "a competition of the song ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a musical competition";
        }
        BREAK(type);
    case occasion_schedule_type::POETRY_COMPETITION:
        if (auto form = df::poetic_form::find(schedule->reference))
        {
            s << "a competition of the poetry ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a poetry competition";
        }
        BREAK(type);
    case occasion_schedule_type::FOOT_RACE:
        s << "a foot race";
        BREAK(type);
    case occasion_schedule_type::WRESTLING_COMPETITION:
        s << "a wrestling competition";
        BREAK(type);
    case occasion_schedule_type::THROWING_COMPETITION:
        s << "a ";
        s << ItemTypeInfo(df::item_type(schedule->reference), int16_t(schedule->reference2)).toString();
        s << "-throwing competition";
        BREAK(type);
    case occasion_schedule_type::GLADIATORY_COMPETITION:
        s << "a gladiatory competition";
        s << ":" << schedule->reference << ":" << schedule->reference2;
        BREAK(type);
    default:
        s << ENUM_KEY_STR(history_event_type, event->getType());
        s << ":";
        s << ENUM_KEY_STR(occasion_schedule_type, schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (COMPETITION) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
    if (!schedule->features.empty())
    {
        s << " featuring ";
        list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context, event](std::ostream & out, df::entity_occasion_schedule_feature *feature)
        {
            schedule_feature(out, context, feature, event);
        });
    }
    s << " as part of ";
    name_translated(s, occasion->name);
    do_location(s, context, event);
    if (!event->competitor_hf.empty())
    {
        if (event->competitor_hf.size() == 1)
        {
            s << ", but the only competitor was ";
        }
        else
        {
            s << ". Competing were ";
        }
        list_event_link<df::historical_figure>(s, context, event->competitor_hf);
    }
    if (!event->winner_hf.empty())
    {
        if (event->winner_hf.size() == 1)
        {
            s << ". The winner was ";
        }
        else
        {
            s << ". The winners were ";
        }
        list_event_link<df::historical_figure>(s, context, event->winner_hf);
    }
}
