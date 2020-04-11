#include "../helpers_event.h"

#include "df/dance_form.h"
#include "df/entity_occasion.h"
#include "df/entity_occasion_info.h"
#include "df/entity_occasion_schedule.h"
#include "df/history_event_performancest.h"
#include "df/musical_form.h"
#include "df/poetic_form.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_performancest *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case occasion_schedule_type::DANCE_PERFORMANCE:
        if (auto form = df::dance_form::find(schedule->reference))
        {
            s << "a performance of the dance ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a dance performance";
        }
        BREAK(type);
    case occasion_schedule_type::MUSICAL_PERFORMANCE:
        if (auto form = df::musical_form::find(schedule->reference))
        {
            s << "a performance of the song ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a musical performance";
        }
        BREAK(type);
    case occasion_schedule_type::POETRY_RECITAL:
        if (auto form = df::poetic_form::find(schedule->reference))
        {
            s << "a recital of the poetry ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a poetry recital";
        }
        BREAK(type);
    case occasion_schedule_type::STORYTELLING:
        if (auto ref = df::history_event::find(schedule->reference))
        {
            s << "a telling of how ";
            event_reverse(s, context, ref);
        }
        else
        {
            s << "a storytelling";
        }
        BREAK(type);
    default:
        s << enum_item_key_str(event->getType());
        s << ":";
        s << enum_item_key_str(schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (PERFORMANCE) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
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
}
