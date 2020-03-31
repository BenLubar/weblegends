#include "weblegends.h"
#include "helpers.h"

#include "modules/Maps.h"

#include "df/coord2d_path.h"
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
    handler.raw_out() << "<svg viewBox=\"0 0 20 29\"><path d=\"m3 1v2h-2v16h2v2h4v2h2v2h6v-4h2v-2h2v-16h-2v-2z\" fill=\"#000\"></path>";
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

static void render_region_map(std::ostream & s)
{
    FOR_ENUM_ITEMS(biome_type, biome)
    {
        df::coord2d_path biome_coords;
        bool first = true;
        for (uint16_t x = 0; x < world->world_data->world_width; x++)
        {
            for (uint16_t y = 0; y < world->world_data->world_height; y++)
            {
                if (Maps::GetBiomeType(x, y) == biome)
                {
                    biome_coords.push_back(df::coord2d(x, y));
                }
            }
        }
        render_coord_path(s, "biome-" + toLower(enum_item_key_str(biome)), biome_coords);
    }
}

void render_map_coords(std::ostream & s, const df::coord2d_path & coords, int32_t mul)
{
    int32_t x0 = 0;
    int32_t y0 = 0;
    int32_t x1 = world->world_data->world_width * mul;
    int32_t y1 = world->world_data->world_height * mul;

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

    s << "<svg width=\"100%\" class=\"map\" viewBox=\"" << x0 << " " << y0 << " " << (x1 - x0) << " " << (y1 - y0) << "\">";
    s << "<g transform=\"scale(" << mul << ")\">";
    render_region_map(s);
    s << "</g>";
    render_coord_path(s, "outline", coords);
    s << "</svg>";
}
