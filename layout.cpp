#include "weblegends.h"
#include "helpers.h"
#include "lodepng.h"

#include "modules/Gui.h"
#include "modules/Maps.h"

#include "df/coord2d_path.h"
#include "df/viewscreen_export_graphical_mapst.h"
#include "df/viewscreen_legendsst.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_region.h"

REQUIRE_GLOBAL(world);

void Layout::set_title(const std::string & title)
{
    head_content << "<title>" << html_escape(title) << "</title>";
}

void Layout::set_base_path(const std::string & url)
{
    head_content << "<base href=\"" << html_escape(url) << "\">";
}

void Layout::add_header_link(const std::string & url, const std::string & label, bool current)
{
    header_nav << (current ? "<li aria-current>" : "<li>");
    if (url.empty())
        header_nav << "<a>";
    else
        header_nav << "<a href=\"" << html_escape(url) << "\">";
    header_nav << html_escape(label) << "</a></li>";
}

void Layout::add_sidebar_section(const std::string & title)
{
    if (in_sidebar_section)
    {
        sidebar_nav << "</ul></nav>";
    }
    in_sidebar_section = true;
    sidebar_nav << "<nav><h3>" << html_escape(title) << "</h3><ul>";
}

void Layout::add_sidebar_link(const std::string & url, const std::string & label)
{
    if (!in_sidebar_section)
    {
        sidebar_nav << "<nav><ul>";
        in_sidebar_section = true;
    }
    sidebar_nav << "<li><a href=\"" << html_escape(url) << "\">" << html_escape(label) << "</a></li>";
}

void Layout::write_to(weblegends_handler_v1& handler) const
{
    handler.headers()["Content-Type"] = "text/html; charset=utf-8";
    handler.raw_out() << "<!DOCTYPE html><html dir=\"ltr\" lang=\"en\"><head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"faux-wikipedia.css\">";
    handler.raw_out() << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << head_content.str() << "</head>";
    handler.raw_out() << "<body><header><div id=\"logo\" role=\"banner\"><a href=\"\" title=\"Visit the main page\">";
    handler.raw_out() << "<svg viewBox=\"0 0 20 29\" width=\"160\" height=\"160\"><path d=\"m3 1v2h-2v16h2v2h4v2h2v2h6v-4h2v-2h2v-16h-2v-2z\" fill=\"#000\"></path>";
    handler.raw_out() << "<path d=\"m4 2v2h12v-2zm12 2v6h2v-6zm-12 0h-2v6h2zm2 4v2h2v-2zm6 0v2h2v-2zm-4 6v2h4v-2z\" fill=\"#fff\"></path>";
    handler.raw_out() << "<path d=\"m2 10v8h2v2h4v2h2v2h4v-4h2v-2h2v-8h-2v2h-12v-2zm4 4h8v2h-8z\" fill=\"#c0c0c0\"></path>";
    handler.raw_out() << "<text y=\"28\" x=\"11\">WeblegendS</text></svg></a></div><nav><ul>" << header_nav.str() << "</ul></nav></header>";
    handler.raw_out() << "<main>" << content.str() << "</main><aside>" << sidebar_nav.str();
    if (in_sidebar_section)
        handler.raw_out() << "</ul></nav>";
    handler.raw_out() << "</aside></body></html>";
}

static void rotate_ccw(int & x, int & y)
{
    int tmp = x;
    x = y;
    y = -tmp;
}

static void rotate_cw(int & x, int & y)
{
    int tmp = x;
    x = -y;
    y = tmp;
}

static void trace_path_segment(std::ostream & s, const std::set<df::coord2d> & coords, df::coord2d & coord, int & tx, int & ty)
{
    // compute normal
    int nx = tx, ny = ty;
    rotate_cw(nx, ny);

    bool concave = false;

    // determine length of segment
    int dx = tx, dy = ty;
    while (coords.count(coord + df::coord2d(uint16_t(dx), uint16_t(dy))))
    {
        if (coords.count(coord + df::coord2d(uint16_t(dx + nx), uint16_t(dy + ny))))
        {
            concave = true;
            break;
        }

        dx += tx;
        dy += ty;
    }

    if (dx)
    {
        s << "h" << dx;
    }
    if (dy)
    {
        s << "v" << dy;
    }

    if (concave)
    {
        coord.x += uint16_t(nx);
        coord.y += uint16_t(ny);

        rotate_cw(tx, ty);
    }
    else
    {
        dx -= tx;
        dy -= ty;

        rotate_ccw(tx, ty);
    }

    coord.x += uint16_t(dx);
    coord.y += uint16_t(dy);
}

static void flip_contiguous_coords(std::set<df::coord2d> & coords, std::set<df::coord2d> & all_coords, const df::coord2d & base_coord)
{
    df::coord2d min = base_coord;
    df::coord2d max = base_coord;

    std::deque<df::coord2d> todo;
    coords.insert(base_coord);
    todo.push_back(base_coord);

    // flood fill the current shape
    while (!todo.empty())
    {
        auto c0 = todo.back();
        todo.pop_back();

        df::coord2d c1(c0.x - 1, c0.y);
        if (all_coords.count(c1) && coords.insert(c1).second)
        {
            min.x = std::min(min.x, c1.x);
            todo.push_back(c1);
        }
        c1.x = c0.x + 1;
        if (all_coords.count(c1) && coords.insert(c1).second)
        {
            max.x = std::max(max.x, c1.x);
            todo.push_back(c1);
        }
        c1.x = c0.x;
        c1.y = c0.y - 1;
        if (all_coords.count(c1) && coords.insert(c1).second)
        {
            min.y = std::min(min.y, c1.y);
            todo.push_back(c1);
        }
        c1.y = c0.y + 1;
        if (all_coords.count(c1) && coords.insert(c1).second)
        {
            max.y = std::max(max.y, c1.y);
            todo.push_back(c1);
        }
    }

    // compute the border of the shape (that is, any tiles outside of the shape but inside of its bounding box)
    std::set<df::coord2d> border;
    for (int16_t x = min.x; x <= max.x; x++)
    {
        df::coord2d c0(uint16_t(x), min.y);
        df::coord2d c1(uint16_t(x), max.y);
        if (!coords.count(c0) && border.insert(c0).second)
        {
            todo.push_back(c0);
        }
        if (!coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
    }
    for (int16_t y = min.y; y <= max.y; y++)
    {
        df::coord2d c0(min.x, uint16_t(y));
        df::coord2d c1(max.x, uint16_t(y));
        if (!coords.count(c0) && border.insert(c0).second)
        {
            todo.push_back(c0);
        }
        if (!coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
    }

    // flood fill the border
    while (!todo.empty())
    {
        auto c0 = todo.back();
        todo.pop_back();

        df::coord2d c1(c0.x - 1, c0.y);
        if (min.x < c0.x && !coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
        c1.x = c0.x + 1;
        if (max.x > c0.x && !coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
        c1.x = c0.x;
        c1.y = c0.y - 1;
        if (min.y < c0.y && !coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
        c1.y = c0.y + 1;
        if (max.y > c0.y && !coords.count(c1) && border.insert(c1).second)
        {
            todo.push_back(c1);
        }
    }

    // now that we have the border, fill in the inside of our blob
    for (int16_t x = min.x; x <= max.x; x++)
    {
        for (int16_t y = min.y; y <= max.y; y++)
        {
            df::coord2d c{ uint16_t(x), uint16_t(y) };
            if (!border.count(c))
            {
                coords.insert(c);

                // at the same time, flip every tile within this blob in the original set
                if (!all_coords.insert(c).second)
                {
                    all_coords.erase(c);
                }
            }
        }
    }
}

static void render_coord_path(std::ostream & s, const std::string & className, const df::coord2d_path & coord_path)
{
    std::set<df::coord2d> all_coords;
    for (size_t i = 0; i < coord_path.size(); i++)
    {
        all_coords.insert(coord_path[i]);
    }

    if (all_coords.empty())
    {
        return;
    }

    s << "<path class=\"" << className << "\" d=\"";

    while (!all_coords.empty())
    {
        // coordinates are sorted first by x coordinate, then by y coordinate
        // this means the first coordinate in the set is guaranteed to be the top corner of a left edge
        auto base_coord = *all_coords.cbegin();
        std::set<df::coord2d> coords;
        flip_contiguous_coords(coords, all_coords, base_coord);

        // trace outer border
        auto coord = base_coord;
        s << "M" << coord.x << " " << coord.y;
        int tx = 0, ty = 1;
        do
        {
            trace_path_segment(s, coords, coord, tx, ty);
        } while (coord != base_coord || tx != 0 || ty != 1);
        s << "z";
    }

    s << "\"></path>";
}

#pragma pack(push, 1)
struct rgb_color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    bool operator<(const rgb_color & other) const
    {
        if (r != other.r)
            return r < other.r;
        if (g != other.g)
            return g < other.g;
        return b < other.b;
    }
};
#pragma pack(pop)

static const std::map<rgb_color, df::biome_type> biome_type_colors =
{
    std::make_pair(rgb_color{128, 128, 128}, biome_type::MOUNTAIN),
    std::make_pair(rgb_color{0, 224, 255}, biome_type::LAKE_TEMPERATE_FRESHWATER),
    std::make_pair(rgb_color{0, 192, 255}, biome_type::LAKE_TEMPERATE_BRACKISHWATER),
    std::make_pair(rgb_color{0, 160, 255}, biome_type::LAKE_TEMPERATE_SALTWATER),
    std::make_pair(rgb_color{0, 96, 255}, biome_type::LAKE_TROPICAL_FRESHWATER),
    std::make_pair(rgb_color{0, 64, 255}, biome_type::LAKE_TROPICAL_BRACKISHWATER),
    std::make_pair(rgb_color{0, 32, 255}, biome_type::LAKE_TROPICAL_SALTWATER),
    std::make_pair(rgb_color{0, 255, 255}, biome_type::OCEAN_ARCTIC),
    std::make_pair(rgb_color{0, 0, 255}, biome_type::OCEAN_TROPICAL),
    std::make_pair(rgb_color{0, 128, 255}, biome_type::OCEAN_TEMPERATE),
    std::make_pair(rgb_color{64, 255, 255}, biome_type::GLACIER),
    std::make_pair(rgb_color{128, 255, 255}, biome_type::TUNDRA),
    std::make_pair(rgb_color{96, 192, 128}, biome_type::SWAMP_TEMPERATE_FRESHWATER),
    std::make_pair(rgb_color{64, 192, 128}, biome_type::SWAMP_TEMPERATE_SALTWATER),
    std::make_pair(rgb_color{96, 255, 128}, biome_type::MARSH_TEMPERATE_FRESHWATER),
    std::make_pair(rgb_color{64, 255, 128}, biome_type::MARSH_TEMPERATE_SALTWATER),
    std::make_pair(rgb_color{96, 192, 64}, biome_type::SWAMP_TROPICAL_FRESHWATER),
    std::make_pair(rgb_color{64, 192, 64}, biome_type::SWAMP_TROPICAL_SALTWATER),
    std::make_pair(rgb_color{64, 255, 96}, biome_type::SWAMP_MANGROVE),
    std::make_pair(rgb_color{96, 255, 64}, biome_type::MARSH_TROPICAL_FRESHWATER),
    std::make_pair(rgb_color{64, 255, 64}, biome_type::MARSH_TROPICAL_SALTWATER),
    std::make_pair(rgb_color{0, 96, 64}, biome_type::FOREST_TAIGA),
    std::make_pair(rgb_color{0, 96, 32}, biome_type::FOREST_TEMPERATE_CONIFER),
    std::make_pair(rgb_color{0, 160, 32}, biome_type::FOREST_TEMPERATE_BROADLEAF),
    std::make_pair(rgb_color{0, 96, 0}, biome_type::FOREST_TROPICAL_CONIFER),
    std::make_pair(rgb_color{0, 128, 0}, biome_type::FOREST_TROPICAL_DRY_BROADLEAF),
    std::make_pair(rgb_color{0, 160, 0}, biome_type::FOREST_TROPICAL_MOIST_BROADLEAF),
    std::make_pair(rgb_color{0, 255, 32}, biome_type::GRASSLAND_TEMPERATE),
    std::make_pair(rgb_color{0, 224, 32}, biome_type::SAVANNA_TEMPERATE),
    std::make_pair(rgb_color{0, 192, 32}, biome_type::SHRUBLAND_TEMPERATE),
    std::make_pair(rgb_color{255, 160, 0}, biome_type::GRASSLAND_TROPICAL),
    std::make_pair(rgb_color{255, 176, 0}, biome_type::SAVANNA_TROPICAL),
    std::make_pair(rgb_color{255, 192, 0}, biome_type::SHRUBLAND_TROPICAL),
    std::make_pair(rgb_color{255, 96, 32}, biome_type::DESERT_BADLAND),
    std::make_pair(rgb_color{255, 255, 0}, biome_type::DESERT_SAND),
    std::make_pair(rgb_color{255, 128, 64}, biome_type::DESERT_ROCK),
};

static std::string cached_region_map;

void clear_region_map_cache()
{
    CoreSuspender suspend;
    cached_region_map.clear();
}

void render_region_map(std::ostream & s)
{
    CoreSuspender suspend;
    if (!cached_region_map.empty())
    {
        s << cached_region_map;
        return;
    }

    auto real_curview = Gui::getCurViewscreen(false);

    // call up legends screen and immediately swap to export map screen
    // this allows us to use the game's logic for generating the region details structures
    auto legends = df::allocate<df::viewscreen_legendsst>();
    real_curview->child = legends;
    legends->parent = real_curview;
    legends->feed_key(interface_key::LEGENDS_EXPORT_DETAILED_MAP);
    real_curview->child = nullptr;
    legends->parent = nullptr;
    std::unique_ptr<df::viewscreen_export_graphical_mapst> exporter(static_cast<df::viewscreen_export_graphical_mapst *>(legends->child));
    legends->child = nullptr;
    exporter->parent = nullptr;
    delete legends;

    // we now have a map exporter screen that's not part of the UI hierarchy
    // we're going to be very silly and manipulate it directly
    int32_t width = world->world_data->world_width;
    int32_t height = world->world_data->world_height;
    exporter->in_select = false;
    exporter->sel_type = export_map_type::biome;
    exporter->x0 = 0;
    exporter->y0 = 0;
    exporter->x1 = int16_t(width - 1);
    exporter->y1 = int16_t(height - 1);
    exporter->cur_x = 0;
    exporter->cur_y = 0;
    exporter->map_width = width;
    exporter->map_height = height;
    width *= 16;
    height *= 16;
    exporter->numtiles_map_width = width;
    exporter->numtiles_map_width = height;
    auto rgb_buffer = new rgb_color[width * height];
    exporter->rgb_buffer = rgb_buffer;

    // each call to logic() renders one column of the image
    while (exporter->breakdown_level != interface_breakdown_types::STOPSCREEN)
    {
        exporter->logic();
    }

    // the map exporter writes files in its destructor
    // pretend we didn't get that far so we only clean up memory
    exporter->rgb_buffer = nullptr;
    exporter->in_select = true;

    uint8_t *png_data;
    size_t png_size;

    lodepng_encode24(&png_data, &png_size, reinterpret_cast<uint8_t *>(rgb_buffer), unsigned(width), unsigned(height));

    delete[] rgb_buffer;
    cached_region_map = std::string(reinterpret_cast<char *>(png_data), png_size);
    free(png_data);

    s << cached_region_map;
}

void render_map_coords(std::ostream & s, const df::coord2d_path & coords, int32_t mul)
{
    int32_t w = world->world_data->world_width;
    int32_t h = world->world_data->world_height;
    int32_t x0 = 0;
    int32_t y0 = 0;
    int32_t x1 = w * mul;
    int32_t y1 = h * mul;

    int32_t minx = x1, maxx = x0;
    int32_t miny = y1, maxy = y0;
    for (size_t i = 0; i < coords.size(); i++)
    {
        minx = std::min(minx, int32_t(coords.x.at(i)));
        miny = std::min(miny, int32_t(coords.y.at(i)));
        maxx = std::max(maxx, int32_t(coords.x.at(i)));
        maxy = std::max(maxy, int32_t(coords.y.at(i)));
    }

    int32_t dx = maxx - minx + 1;
    int32_t dy = maxy - miny + 1;

    while (dx < 5)
    {
        minx--;
        maxx++;
        dx += 2;
    }

    while (dy < 5)
    {
        miny--;
        maxy++;
        dy += 2;
    }

    x0 = std::max(x0, minx - dx);
    x1 = std::min(x1, maxx + dx);
    y0 = std::max(y0, miny - dy);
    y1 = std::min(y1, maxy + dy);

    s << "<svg width=\"100\" height=\"100\" class=\"map\" viewBox=\"" << x0 << " " << y0 << " " << (x1 - x0) << " " << (y1 - y0) << "\">";
    s << "<foreignObject x=\"0\" y=\"0\" width=\"" << w << "\" height=\"" << h << "\" transform=\"scale(" << mul << ")\">";
    s << "<img src=\"region.svg\" width=\"" << w << "\" height=\"" << h << "\"/>";
    s << "</foreignObject>";
    render_coord_path(s, "outline", coords);
    s << "</svg>";
}
