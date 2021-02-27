#include "weblegends.h"
#include "helpers.h"

#include "df/feature.h"
#include "df/feature_init.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(world)

bool WebLegends::render_layer(Layout & l, int32_t id, int32_t page)
{
    CoreSuspender suspend;

    auto layer = df::world_underground_region::find(id);
    if (layer == nullptr)
    {
        return false;
    }

    simple_header(l, layer);

    auto & s = l.content;
    render_map_coords(s, layer->region_coords);

    s << "<p>";
    categorize(s, layer);
    s << "</p>";

    auto feature = layer->feature_init ? layer->feature_init->getFeature() : nullptr;
    if (feature)
    {
        render_world_populations(s, get_name(layer), feature->population, "layer", id);
    }

    int32_t last_page;
    if (!history(s, layer, page, last_page))
    {
        return false;
    }
    pagination(s, stl_sprintf("layer-%d", id), "", "?page=", page, last_page);
    return true;
}
