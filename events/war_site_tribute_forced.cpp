#include "../helpers_event.h"

#include "df/history_event_war_site_tribute_forcedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_war_site_tribute_forcedst *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    if (event->tribute_flags.bits.bled_dry)
    {
        s << " tried to secure tribute from ";
    }
    else
    {
        s << " secured tribute from ";
    }
    event_link(s, context, site_civ);
    s << " of ";
    event_link(s, context, defender_civ);
    if (event->tribute_flags.bits.bled_dry)
    {
        s << ", but they had nothing left to give";
    }
    else
    {
        s << ", to be delivered from ";
        event_link(s, context, site);
        s << " every ";
        BEFORE_SWITCH(seas, event->season);
        switch (seas)
        {
        case season::None:
            s << "season";
            BREAK(seas);
        case season::Spring:
            s << "Spring";
            BREAK(seas);
        case season::Summer:
            s << "Summer";
            BREAK(seas);
        case season::Autumn:
            s << "Autumn";
            BREAK(seas);
        case season::Winter:
            s << "Winter";
            BREAK(seas);
        }
        AFTER_SWITCH(seas, stl_sprintf("event-%d (WAR_SITE_TRIBUTE_FORCED)", event->id));
    }
}
