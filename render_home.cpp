#include "weblegends.h"
#include "helpers.h"

#include "df/world.h"
#include "df/world_data.h"

REQUIRE_GLOBAL(world);

void WebLegends::render_home(std::ostream & s)
{
    CoreSuspender suspend;

    if (!world->world_data)
    {
        return;
    }

    simple_header(s, &world->world_data->name);
    s << "<table>";
    s << "<tr><th><a href=\"figs-0\">Historical Figures</a></th><td>" << world->history.figures.size() << "</td></tr>";
    s << "<tr><th><a href=\"sites-0\">Sites</a></th><td>" << world->world_data->sites.size() << "</td></tr>";
    s << "<tr><th><a href=\"regions-0\">Regions</a></th><td>" << world->world_data->regions.size() << "</td></tr>";
    s << "<tr><th><a href=\"layers-0\">Underground Regions</a></th><td>" << world->world_data->underground_regions.size() << "</td></tr>";
    s << "<tr><th><a href=\"ents-0\">Civilizations and other entities</a></th><td>" << world->entities.all.size() << "</td></tr>";
    s << "</body></html>";
}
