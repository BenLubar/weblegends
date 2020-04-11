#include "../helpers_event.h"

#include "df/history_event_item_stolenst.h"
#include "df/item_drinkst.h"
#include "df/item_fish_rawst.h"
#include "df/item_fishst.h"
#include "df/item_meatst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_item_stolenst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    event_link(s, context, hf);
    s << " stole ";
    if (auto item = df::item::find(event->item))
    {
        do_item_description(s, context, item);
    }
    else if (event->item_type == item_type::FISH)
    {
        do_item_description<df::item_fishst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else if (event->item_type == item_type::FISH_RAW)
    {
        do_item_description<df::item_fish_rawst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else if (event->item_type == item_type::MEAT)
    {
        do_item_description<df::item_meatst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else if (event->item_type == item_type::DRINK)
    {
        do_item_description<df::item_drinkst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else
    {
        s << "a ";
        if (ENUM_ATTR(item_type, is_caste_mat, event->item_type))
        {
            auto creature = df::creature_raw::find(event->mattype);
            auto caste = creature->caste.at(event->matindex);
            if (!unique_creature_name(s, context, creature))
            {
                s << caste->caste_name[0];
            }
        }
        else
        {
            MaterialInfo mat(event->mattype, event->matindex);
            material(s, context, mat);
        }
        ItemTypeInfo type(event->item_type, event->item_subtype);
        s << " " << type.toString();
    }
    if (auto ent = df::historical_entity::find(event->entity))
    {
        s << " belonging to ";
        event_link(s, context, ent);
    }
    do_location(s, context, event, " from ");
    if (auto site = df::world_site::find(event->anon_1))
    {
        s << " and brought it to ";
        event_link(s, context, site);
    }
}
