#include "../helpers_event.h"

#include "df/history_event_masterpiece_created_itemst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_itemst *event)
{
    if (auto maker = df::historical_figure::find(event->maker))
    {
        event_link(s, context, maker);
    }
    else
    {
        s << "an unknown person";
    }
    if (auto maker_entity = df::historical_entity::find(event->maker_entity))
    {
        s << " of ";
        event_link(s, context, maker_entity);
    }
    s << " created ";
    if (auto art = get_artifact(df::item::find(event->item_id)))
    {
        event_link(s, context, art);
    }
    else
    {
        s << "a masterwork ";
        if (ENUM_ATTR(item_type, is_caste_mat, event->item_type))
        {
            auto creature = df::creature_raw::find(event->mat_type);
            auto caste = creature->caste.at(event->mat_index);
            if (!unique_creature_name(s, context, creature))
            {
                s << caste->caste_name[0];
            }
        }
        else
        {
            MaterialInfo mat(event->mat_type, event->mat_index);
            material(s, context, mat);
        }
        ItemTypeInfo type(event->item_type, event->item_subtype);
        s << " " << type.toString();
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
}
