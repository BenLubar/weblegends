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
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_ABSTRACT_BUILDING:
        s << " took up residence in ";
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_BUILDING:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::LAIR:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_SUL:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_SAVED_CIVZONE:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::PRISON_ABSTRACT_BUILDING:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    case histfig_site_link_type::PRISON_SITE_BUILDING_PROFILE:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_SITE_LINK)", event->id));
    event_link(s, context, structure);
    if (civ)
    {
        s << " of ";
        event_link(s, context, civ);
    }
    if (civ)
    {
        s << " in ";
        event_link(s, context, site);
    }
}
