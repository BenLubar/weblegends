#include "../helpers_event.h"

#include "df/history_event_created_world_constructionst.h"
#include "df/world_construction.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_created_world_constructionst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto construction = df::world_construction::find(event->construction);
    auto master_construction = df::world_construction::find(event->master_construction);
    auto site1 = df::world_site::find(event->site1);
    auto site2 = df::world_site::find(event->site2);

    if (civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, civ);
    s << " finished the construction of ";
    if (!construction)
    {
        s << "[unknown construction]";
        return;
    }

    if (auto name = construction->getName())
    {
        name_translated(s, *name);
    }
    else
    {
        s << "[unnamed]";
    }

    s << ", a " << toLower(enum_item_key(construction->getType()));

    if (site1 && site2)
    {
        s << " connecting ";
        event_link(s, context, site1);
        s << " and ";
        event_link(s, context, site2);
    }
    else if (site1)
    {
        s << " at ";
        event_link(s, context, site1);
    }
    else if (site2)
    {
        s << " at ";
        event_link(s, context, site2);
    }

    if (master_construction)
    {
        s << " as part of the " << toLower(enum_item_key(master_construction->getType())) << " ";
        if (auto name = master_construction->getName())
        {
            name_translated(s, *name);
        }
        else
        {
            s << "[unnamed]";
        }
    }
}
