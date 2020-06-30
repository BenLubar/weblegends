#include "../helpers_event.h"

#include "df/history_event_add_hf_site_linkst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_site_linkst *event)
{
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;
    auto histfig = df::historical_figure::find(event->histfig);
    auto civ = df::historical_entity::find(event->civ);

    event_link(s, context, histfig);
    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_site_link_type::OCCUPATION:
        s << " started working at ";
        BREAK(type);
    case histfig_site_link_type::SEAT_OF_POWER:
        s << " ruled from ";
        BREAK(type);
    case histfig_site_link_type::HANGOUT:
        s << " started hanging out at ";
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_ABSTRACT_BUILDING:
        s << " took up residence in ";
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_BUILDING:
    case histfig_site_link_type::HOME_SITE_REALIZATION_SUL:
    case histfig_site_link_type::HOME_SITE_SAVED_CIVZONE:
        s << " took up residence ";
        BREAK(type);
    case histfig_site_link_type::LAIR:
        s << " laired within ";
        BREAK(type);
    case histfig_site_link_type::PRISON_ABSTRACT_BUILDING:
    case histfig_site_link_type::PRISON_SITE_BUILDING_PROFILE:
        s << " was imprisoned in ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_SITE_LINK)", event->id));

    if (event->structure != -1)
    {
        event_link(s, context, structure);
        if (event->civ != -1)
        {
            s << " of ";
            event_link(s, context, civ);
        }
    }

    s << " in ";
    event_link(s, context, site);
}
