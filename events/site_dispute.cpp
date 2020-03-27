#include "../helpers_event.h"

#include "df/history_event_site_disputest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_site_disputest *event)
{
    auto entity_1 = df::historical_entity::find(event->entity_1);
    auto entity_2 = df::historical_entity::find(event->entity_2);
    auto site_1 = df::world_site::find(event->site_1);
    auto site_2 = df::world_site::find(event->site_2);

    event_link(s, context, site_1);
    s << " of ";
    event_link(s, context, entity_1);

    s << " and ";

    event_link(s, context, site_2);
    s << " of ";
    event_link(s, context, entity_2);

    s << " became embroiled in a dispute over ";

    BEFORE_SWITCH(type, event->dispute_type);
    switch (type)
    {
    case site_dispute_type::Territory:
        s << "territory";
        BREAK(type);
    case site_dispute_type::WaterRights:
        s << "water rights";
        BREAK(type);
    case site_dispute_type::GrazingRights:
        s << "grazing rights";
        BREAK(type);
    case site_dispute_type::FishingRights:
        s << "fishing rights";
        BREAK(type);
    case site_dispute_type::RightsOfWay:
        s << "rights-of-way";
        BREAK(type);
    case site_dispute_type::LivestockOwnership:
        s << "livestock ownership";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (SITE_DISPUTE)", event->id));
}
