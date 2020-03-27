#include "../helpers_event.h"

#include "df/history_event_create_entity_positionst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_create_entity_positionst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto position = site_civ ? binsearch_in_vector(site_civ->positions.own, event->position) : nullptr;

    event_link(s, context, histfig);
    if (civ)
    {
        s << " of ";
        event_link(s, context, civ);
    }

    std::string before(" created the position of ");
    std::string after;

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
        case 0:
            after = " through force of argument";
            BREAK(reason);
        case 1:
            before = " compelled the creation of the position of ";
            after = " with threats of violence";
            BREAK(reason);
        case 2:
            before = " collaborated to create the position of ";
            BREAK(reason);
        case 3:
            after = ", pushed by a wave of popular support";
            BREAK(reason);
        case 4:
            after = " as a matter of course";
            BREAK(reason);
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (CREATE_ENTITY_POSITION)", event->id));

    s << before;
    s << (position ? html_escape(position->name[0]) : "[unknown position]");
    if (civ != site_civ)
    {
        s << " of ";
        event_link(s, context, site_civ);
    }
    s << after;
}
