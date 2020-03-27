#include "../helpers_event.h"

#include "df/history_event_created_sitest.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_created_sitest *event)
{
    auto site = df::world_site::find(event->site);

    if (auto builder = df::historical_figure::find(event->builder_hf))
    {
        event_link(s, context, builder);
        s << " founded ";
        event_link(s, context, site);
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " in the name of ";
            event_link(s, context, civ);
        }
    }
    else if (auto civ = df::historical_entity::find(event->civ))
    {
        event_link(s, context, civ);
        s << " founded ";
        event_link(s, context, site);
    }
    else
    {
        event_link(s, context, site);
        s << " was founded";
    }

    if (auto site_civ = df::historical_entity::find(event->site_civ))
    {
        s << ". The new government was named ";
        event_link(s, context, site_civ);
    }
}
