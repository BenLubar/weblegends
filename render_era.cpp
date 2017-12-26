#include "weblegends.h"
#include "helpers.h"

#include "df/history_era.h"
#include "df/world.h"

REQUIRE_GLOBAL(world);

bool WebLegends::render_era(std::ostream & s, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto era = vector_get(world->history.eras, id);
    if (era == nullptr)
    {
        return false;
    }

    simple_header(s, era);
    // TODO

    int32_t last_page;
    if (!history(s, era, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("era-%d", id), "", "?page=", page, last_page);
    s << "</body></html>";
    return true;
}
