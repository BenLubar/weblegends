#include "weblegends.h"
#include "helpers.h"

#include "df/entity_entity_link.h"
#include "df/entity_site_link.h"
#include "df/historical_entity.h"
#include "df/world_site.h"

void WebLegends::render_entity(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto ent = df::historical_entity::find(id);
    if (ent == nullptr)
    {
        return;
    }

    simple_header(s, &ent->name);

    s << "<p>";
    categorize(s, ent);
    s << "</p>";

    if (!ent->entity_links.empty())
    {
        s << "<h2 id=\"related-entities\">Related Entities</h2><ul>";
        for (auto it = ent->entity_links.begin(); it != ent->entity_links.end(); it++)
        {
            if (auto target = df::historical_entity::find((*it)->target))
            {
                s << "<li>";
                link(s, target);
                s << ",";
                categorize(s, target);
                s << "</li>";
            }
        }
        s << "</ul>";
    }
    if (!ent->site_links.empty())
    {
        s << "<h2 id=\"related-sites\">Related Sites</h2><ul>";
        for (auto it = ent->site_links.begin(); it != ent->site_links.end(); it++)
        {
            if (auto target = df::world_site::find((*it)->target))
            {
                s << "<li>";
                link(s, target);
                s << ",";
                categorize(s, target);
                // TODO: type
                s << "</li>";
            }
        }
        s << "</ul>";
    }

    history(s, ent);
    // TODO
    s << "</body></html>";
}
