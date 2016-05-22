#include "weblegends.h"
#include "helpers.h"

#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

const static int32_t items_per_page = 250;

template<typename T>
static void render_list(std::ostream & s, int32_t page, const std::string & prefix, const std::string & title)
{
    auto begin = std::find_if(T::get_vector().begin(), T::get_vector().end(), [](T *t) -> bool
            {
                return t->name.has_name;
            });

    int32_t page_count = (int32_t(T::get_vector().end() - begin) + items_per_page - 1) / items_per_page;
    if (page < 0 || page >= page_count)
    {
        return;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << title << ", page " << page << "</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head><body><h1>" << title << "</h1><ul>";
    for (auto it = begin + (page * items_per_page); it != T::get_vector().end() && it != begin + ((page + 1) * items_per_page); it++)
    {
        s << "<li>";
        link(s, *it);
        categorize(s, *it);
        s << "</li>";
    }
    s << "</ul>";
    if (page_count != 1)
    {
        s << "<p>";
        if (page > 0)
        {
            s << "<a href=\"" << prefix << (page - 1) << "\">Previous</a>";
            if (page < page_count - 1)
            {
                s << " - ";
            }
        }
        if (page < page_count - 1)
        {
            s << "<a href=\"" << prefix << (page + 1) << "\">Next</a>";
        }
    }
    s << "</body></html>";
}

void WebLegends::render_entity_list(std::ostream & s, int32_t page)
{
    render_list<df::historical_entity>(s, page, "ents-", "Civilizations and other entities");
}
void WebLegends::render_figure_list(std::ostream & s, int32_t page)
{
    render_list<df::historical_figure>(s, page, "figs-", "Historical Figures");
}
void WebLegends::render_region_list(std::ostream & s, int32_t page)
{
    render_list<df::world_region>(s, page, "regions-", "Regions");
}
void WebLegends::render_site_list(std::ostream & s, int32_t page)
{
    render_list<df::world_site>(s, page, "sites-", "Sites");
}
void WebLegends::render_layer_list(std::ostream & s, int32_t page)
{
    render_list<df::world_underground_region>(s, page, "layers-", "Underground Regions");
}
