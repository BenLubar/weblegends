#include "weblegends.h"
#include "helpers.h"

#include "df/history_event_collection.h"
#include "df/world.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_eventcol(std::ostream & s, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto eventcol = df::history_event_collection::find(id);
    if (eventcol == nullptr)
    {
        return false;
    }

    simple_header(s, eventcol);
    // TODO

    int32_t last_page;
    if (!history(s, eventcol, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("eventcol-%d", id), "", "?page=", page, last_page);
    s << "</body></html>";
    return true;
}
