#include "weblegends.h"
#include "helpers.h"

#include "df/abstract_building.h"
#include "df/world_site.h"

void WebLegends::render_structure(std::ostream & s, int32_t site_id, int32_t id)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(site_id);
    if (site == nullptr)
    {
        return;
    }
    auto structure = vector_get(site->buildings, uint32_t(id));
    if (structure == nullptr)
    {
        return;
    }

    simple_header(s, structure->getName(), true);
    history(s, site);
    // TODO
    s << "</body></html>";
}
