#include "../helpers_event.h"

#include "df/history_event_tradest.h"
#include "df/resource_allotment_data.h"
#include "df/resource_allotment_specifier_cropst.h"

static void do_resource_allotment(std::ostream & s, const event_context & context, int32_t production_zone, df::resource_allotment_specifier_type allotment_type, int32_t allotment_index)
{
    auto zone = df::resource_allotment_data::find(production_zone);
    if (!zone)
    {
        s << "goods";
        return;
    }

    auto allotment = zone->resource_allotments[allotment_type].at(allotment_index);
    BEFORE_SWITCH(type, allotment_type);
    switch (type)
    {
    case resource_allotment_specifier_type::CROP:
        if (auto plant = df::plant_raw::find(static_cast<df::resource_allotment_specifier_cropst *>(allotment)->mat_type))
        {
            s << plant->name_plural;
        }
        else
        {
            s << "crops";
        }
        BREAK(type);
    }
    if (!type_found)
    {
        s << "goods";
    }
    AFTER_SWITCH(type, "resource allotment");
}

void do_event(std::ostream & s, const event_context & context, df::history_event_tradest *event)
{
    event_link(s, context, df::historical_figure::find(event->hf));
    if (event->entity != -1)
    {
        s << " of ";
        event_link(s, context, df::historical_entity::find(event->entity));
    }

    do_account_shift(s, event->account_shift);
    s << " trading ";
    do_resource_allotment(s, context, event->production_zone, df::resource_allotment_specifier_type(event->allotment), event->allotment_index);

    s << " from ";
    event_link(s, context, df::world_site::find(event->source_site));
    s << " to ";
    event_link(s, context, df::world_site::find(event->dest_site));
}
