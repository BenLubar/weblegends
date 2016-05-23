#include "weblegends.h"
#include "helpers.h"

#include "df/world_region.h"

void WebLegends::render_region(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto region = df::world_region::find(id);
    if (region == nullptr)
    {
        return;
    }

    simple_header(s, region);

    s << "<p>";
    categorize(s, region);
    s << "</p>";

    history(s, region);
    // TODO
    s << "</body></html>";
}
