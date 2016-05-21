#include "weblegends.h"
#include "helpers.h"

#include "df/world_site.h"

void WebLegends::render_site(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto site = df::world_site::find(id);
    if (site == nullptr)
    {
        return;
    }

    simple_header(s, &site->name);
    history(s, site);
    // TODO
    s << "</body></html>";
}
