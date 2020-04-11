#include "../helpers_event.h"

#include "df/entity_occasion.h"
#include "df/entity_occasion_info.h"
#include "df/entity_occasion_schedule.h"
#include "df/history_event_ceremonyst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_ceremonyst *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case df::occasion_schedule_type::CEREMONY:
        s << "a ceremony";
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
    AFTER_SWITCH(type, stl_sprintf("event-%d (CEREMONY) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
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
