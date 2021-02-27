#include "weblegends.h"
#include "helpers.h"

#include "df/history_era.h"
#include "df/world.h"
#include "df/world_data.h"

REQUIRE_GLOBAL(world);

void WebLegends::render_home(Layout & l)
{
    CoreSuspender suspend;

    if (!world->world_data)
    {
        return;
    }

    void simple_header(Layout &, df::world_data *);
    simple_header(l, world->world_data);
    auto & s = l.content;
    s << "<img src=\"region.png\" width=\"100\" height=\"100\" class=\"map\">";
    s << "<table class=\"home-links\">";
    s << "<tr><th><a href=\"eventcols-0\">Event Collections</a></th><td>" << format_number(world->history.event_collections.all.size()) << "</td></tr>";
    s << "<tr><th><a href=\"figs-0\">Historical Figures</a></th><td>" << format_number(world->history.figures.size()) << "</td></tr>";
    s << "<tr><th><a href=\"sites-0\">Sites</a></th><td>" << format_number(world->world_data->sites.size()) << "</td></tr>";
    s << "<tr><th><a href=\"items-0\">Artifacts</a></th><td>" << format_number(world->artifacts.all.size()) << "</td></tr>";
    s << "<tr><th><a href=\"regions-0\">Regions</a></th><td>" << format_number(world->world_data->regions.size()) << "</td></tr>";
    s << "<tr><th><a href=\"layers-0\">Underground Regions</a></th><td>" << format_number(world->world_data->underground_regions.size()) << "</td></tr>";
    s << "<tr><th><a href=\"ents-0\">Civilizations and other entities</a></th><td>" << format_number(world->entities.all.size()) << "</td></tr>";
    s << "<tr><td colspan=\"2\"><hr/></td></tr>";

    for (size_t i = 0; i < world->history.eras.size(); i++)
    {
        auto era = world->history.eras.at(i);
        auto next_era = i + 1 < world->history.eras.size() ? world->history.eras.at(i + 1) : nullptr;
        size_t count = 0;
        for (auto e : world->history.events)
        {
            if (e->year >= era->year && (!next_era || e->year < next_era->year))
            {
                count++;
            }
        }

        s << "<tr><th><a href=\"era-" << i << "\">" << escape_name(get_name(era)) << "</a></th><td>" << format_number(count) << "</td></tr>";
    }

    auto handlers = get_handlers_v0();
    bool any_handlers = false;
    if (handlers != nullptr)
    {
        for (auto & h : *handlers)
        {
            if (!h.second.first.empty())
            {
                if (!any_handlers)
                {
                    s << "<tr><td colspan=\"2\"><hr/></td></tr>";
                    any_handlers = true;
                }

                s << "<tr><th colspan=\"2\"><a href=\"" << html_escape(h.first) << "\">" << html_escape(h.second.first) << "</a></th></tr>";
            }
        }
    }

    s << "</table>";
}

void WebLegends::render_sidebar(Layout & l)
{
    CoreSuspender suspend;

    if (!world->world_data)
    {
        return;
    }

    l.add_sidebar_link("eras-0", "Eras");
    l.add_sidebar_link("eventcols-0", "Event Collections");
    l.add_sidebar_link("figs-0", "Historical Figures");
    l.add_sidebar_link("sites-0", "Sites");
    l.add_sidebar_link("items-0", "Artifacts");
    l.add_sidebar_link("regions-0", "Regions");
    l.add_sidebar_link("layers-0", "Underground Regions");
    l.add_sidebar_link("ents-0", "Civilizations");

    auto handlers = get_handlers_v0();
    if (handlers != nullptr)
    {
        bool first = true;
        for (auto & h : *handlers)
        {
            if (!h.second.first.empty())
            {
                if (first)
                {
                    l.add_sidebar_section("Plugins");
                    first = false;
                }
                l.add_sidebar_link(h.first, h.second.first);
            }
        }
    }
}
