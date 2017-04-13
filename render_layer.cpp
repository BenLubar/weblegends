#include "weblegends.h"
#include "helpers.h"

#include "df/world.h"
#include "df/world_data.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(world)

bool WebLegends::render_layer(std::ostream & s, int32_t id, int32_t page)
{
	CoreSuspender suspend;

	auto layer = df::world_underground_region::find(id);
	if (layer == nullptr)
	{
		return false;
	}

	simple_header(s, layer);

	s << "<svg width=\"100%\" style=\"max-width:500px;border:1px solid;float:right\" viewBox=\"0 0 " << world->world_data->world_width << " " << world->world_data->world_height << "\">";
	for (size_t i = 0; i < layer->region_coords.size(); i++)
	{
		s << "<rect width=\"1\" height=\"1\" x=\"" << layer->region_coords.x.at(i) << "\" y=\"" << layer->region_coords.y.at(i) << "\"></rect>";
	}
	s << "</svg>";

	s << "<p>";
	categorize(s, layer);
	s << "</p>";

	int32_t last_page;
	if (!history(s, layer, page, last_page))
	{
		return false;
	}
	pagination(s, stl_sprintf("layer-%d", id), "", "?page=", page, last_page);
	s << "</body></html>";
	return true;
}
