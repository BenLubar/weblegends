#include "weblegends.h"
#include "helpers.h"

#include "df/history_era.h"
#include "df/world.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_era(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto era = vector_get(world->history.eras, id);
    if (era == nullptr)
    {
        return false;
    }

    simple_header(l, era);
    // TODO

    int32_t last_page;
    if (!history(l.content, era, page, last_page))
    {
        return false;
    }
    pagination(l.content, stl_sprintf("era-%d", id), "", "?page=", page, last_page);
    return true;
}
