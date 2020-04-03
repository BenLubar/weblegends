#include "../helpers_event.h"

#include "df/history_event_add_entity_site_profile_flagst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_entity_site_profile_flagst *event)
{
    BEFORE_SWITCH(added_flags, event->added_flags.whole);
    switch (added_flags)
    {
    case df::entity_site_link_flags::mask_holy_city:
        event_link(s, context, df::historical_entity::find(event->entity));
        s << " declared ";
        event_link(s, context, df::world_site::find(event->site));
        s << " to be a holy city";
        BREAK(added_flags);
    }
    if (!added_flags_found)
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
    AFTER_SWITCH(added_flags, stl_sprintf("event-%d (ADD_ENTITY_SITE_PROFILE_FLAG)", event->id));
}
