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

    simple_header(s, site);

    s << "<p>";
    categorize(s, site);
    s << "</p>";

    if (!site->buildings.empty())
    {
        s << "<h2 id=\"structures\">Structures</h2><ul>";
        for (auto it = site->buildings.begin(); it != site->buildings.end(); it++)
        {
            s << "<li>";
            link(s, *it);
            categorize(s, *it);
            s << "</li>";
        }
        s << "</ul>";
    }
    history(s, site);
    // TODO
    s << "</body></html>";
}
