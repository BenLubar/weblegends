#include "../helpers_event.h"

#include "df/entity_population.h"
#include "df/history_event_entity_persecutedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_persecutedst *event)
{
    if (event->persecuting_hf != -1)
    {
        event_link(s, context, df::historical_figure::find(event->persecuting_hf));
        s << " of ";
    }
    event_link(s, context, df::historical_entity::find(event->persecuting_entity));
    s << " persecuted ";
    event_link(s, context, df::historical_entity::find(event->target_entity));

    std::string separator = " in ";

    if (event->shrines_destroyed > 0)
    {
        s << ", desecrating " << format_number(event->shrines_destroyed) << (event->shrines_destroyed == 1 ? " shrine" : " shrines");
    }

    if (!event->property_confiscated_from_hfs.empty())
    {
        s << ", confiscating the property of ";
        list<int32_t>(s, event->property_confiscated_from_hfs, [&](std::ostream & out, int32_t id)
            {
                event_link(out, context, df::historical_figure::find(id));
            });
    }

    if (!event->expelled_hfs.empty() || !event->expelled_populations.empty())
    {
        if (event->shrines_destroyed > 0)
        {
            s << " and ";
        }
        else
        {
            s << ", ";
        }

        separator = " from ";
        s << " expelling ";

        std::vector<std::string> expelled;
        for (auto id : event->expelled_hfs)
        {
            std::ostringstream str;
            event_link(str, context, df::historical_figure::find(id));
            expelled.push_back(str.str());
        }
        for (size_t i = 0; i < event->expelled_populations.size(); i++)
        {
            std::ostringstream str;
            auto pop = df::entity_population::find(event->expelled_populations.at(i));
            auto creature = df::creature_raw::find(event->expelled_races.at(i));
            str << format_number(event->expelled_counts.at(i));
            str << " ";
            event_link(str, context, df::historical_entity::find(pop->civ_id));
            str << " " << html_escape(DF2UTF(creature->name[event->expelled_counts.at(i) == 1 ? 0 : 1]));
            expelled.push_back(str.str());
        }

        list<std::string>(s, expelled, [](std::ostream & out, const std::string & str)
            {
                out << str;
            });
    }

    do_location(s, context, event->site, -1, -1, -1, separator);

    if (!event->destroyed_structures.empty())
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
}
