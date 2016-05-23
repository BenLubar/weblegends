#include "weblegends.h"
#include "helpers.h"

#include "df/world_underground_region.h"

void WebLegends::render_layer(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto layer = df::world_underground_region::find(id);
    if (layer == nullptr)
    {
        return;
    }

    simple_header(s, layer);

    s << "<p>";
    categorize(s, layer);
    s << "</p>";

    history(s, layer);
    // TODO
    s << "</body></html>";
}
