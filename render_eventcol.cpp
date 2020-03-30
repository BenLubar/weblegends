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

    simple_header(l, eventcol);
    // TODO

    int32_t last_page;
    if (!history(l.content, eventcol, page, last_page))
    {
        return false;
    }
    pagination(l.content, stl_sprintf("eventcol-%d", id), "", "?page=", page, last_page);
    return true;
}
