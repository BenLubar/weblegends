#include "../helpers_event.h"

#include "df/history_event_masterpiece_created_foodst.h"
#include "df/itemdef_foodst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_foodst *event)
{
    auto maker = df::historical_figure::find(event->maker);
    auto maker_entity = df::historical_entity::find(event->maker_entity);
    auto site = df::world_site::find(event->site);
    auto subtype = df::itemdef_foodst::find(event->item_subtype);
    auto item = df::item::find(event->item_id);

    event_link(s, context, maker);
    s << " cooked a masterful ";
    if (item)
    {
        do_item_description(s, context, item);
    }
    else
    {
        s << subtype->name;
    }

    if (maker_entity)
    {
        s << " for ";
        event_link(s, context, maker_entity);
    }

    if (site)
    {
        s << " in ";
        event_link(s, context, site);
    }
}
