#include "weblegends.h"
#include "helpers.h"

#include "df/world.h"
#include "df/world_data.h"
#include "df/world_region.h"

REQUIRE_GLOBAL(world)

void WebLegends::render_region(std::ostream & s, int32_t id)
{
	CoreSuspender suspend;

	auto region = df::world_region::find(id);
	if (region == nullptr)
	{
		return;
	}

	simple_header(s, region);

	s << "<svg width=\"100%\" style=\"max-width:500px;border:1px solid;float:right\" viewBox=\"0 0 " << world->world_data->world_width << " " << world->world_data->world_height << "\">";
	for (size_t i = 0; i < region->region_coords.size(); i++)
	{
		s << "<rect width=\"1\" height=\"1\" x=\"" << region->region_coords.x.at(i) << "\" y=\"" << region->region_coords.y.at(i) << "\"></rect>";
	}
	s << "</svg>";

	s << "<p>";
	categorize(s, region);
	s << "</p>";

	history(s, region);
	// TODO
	s << "</body></html>";
}
