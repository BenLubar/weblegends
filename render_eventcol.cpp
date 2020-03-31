#include "weblegends.h"
#include "helpers.h"

#include "df/history_event_collection.h"
#include "df/world.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_eventcol(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto eventcol = df::history_event_collection::find(id);
    if (eventcol == nullptr)
    {
        return false;
    }

    if (auto parent = df::history_event_collection::find(eventcol->getParent()))
    {
        std::string name;
        parent->getName(&name);
        l.add_header_link(stl_sprintf("eventcol-%d", parent->id), DF2UTF(name));
    }

    simple_header(l, eventcol);
    // TODO

    df::coord2d_path coords;
    coords.push_back(df::coord2d());
    eventcol->getRegionCoords(&coords.x.at(0), &coords.y.at(0));
    render_map_coords(l.content, coords);

    bool first = true;
    for (auto child_id : eventcol->collections)
    {
        if (auto child = df::history_event_collection::find(child_id))
        {
            if (first)
            {
                first = false;
                l.content << "<ul>";
            }

            l.content << "<li>";
            link(l.content, child);
            l.content << "</li>";
        }
    }
    if (!first)
    {
        l.content << "</ul>";
    }

    int32_t last_page;
    if (!history(l.content, eventcol, page, last_page))
    {
        return !page;
    }
    pagination(l.content, stl_sprintf("eventcol-%d", id), "", "?page=", page, last_page);
    return true;
}
