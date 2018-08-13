#include "weblegends.h"
#include "helpers.h"

#include "df/artifact_record.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_era.h"
#include "df/world.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(world);

const static int32_t items_per_page = 250;

template<typename T>
static typename std::vector<T *> & get_vector()
{
    return T::get_vector();
}

template<>
std::vector<df::history_era *> & get_vector<df::history_era>()
{
    return world->history.eras;
}

template<typename T>
static typename std::vector<T *>::iterator get_first()
{
    return std::find_if(get_vector<T>().begin(), get_vector<T>().end(), [](T *t) -> bool
    {
        return get_id(t) >= 0 && get_name(t).has_name;
    });
}

template<>
std::vector<df::world_underground_region *>::iterator get_first<df::world_underground_region>()
{
    return df::world_underground_region::get_vector().begin();
}

template<typename T>
static void do_extra(std::ostream &, T *)
{
    // do nothing
}

template<>
void do_extra<df::historical_figure>(std::ostream & s, df::historical_figure *target)
{
    spheres(s, target);
    born_died(s, target);
}

template<typename T>
static bool render_list(std::ostream & s, int32_t page, const std::string & prefix, const std::string & title)
{
    auto begin = get_first<T>();

    // get page count
    int32_t page_count = (int32_t(get_vector<T>().end() - begin) + items_per_page - 1) / items_per_page;
    
    // return if invalid page number
    if (page < 0 || page >= page_count)
    {
        return false;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << title << ", page " << page << "</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    
    add_styles_and_scripts(s);
    
    s << "</head><body><h1>" << title << "</h1><ul>";
    for (auto it = begin + (page * items_per_page); it != get_vector<T>().end() && it != begin + ((page + 1) * items_per_page); it++)
    {
        s << "<li>";
        link(s, *it);
        categorize(s, *it);
        do_extra(s, *it);
        s << "</li>";
    }
    s << "</ul>";
    pagination(s, prefix, "0", "", page, page_count - 1);
    s << "</body></html>";
    return true;
}

bool WebLegends::render_entity_list(std::ostream & s, int32_t page)
{
    return render_list<df::historical_entity>(s, page, "ents-", "Civilizations and other entities");
}
bool WebLegends::render_era_list(std::ostream & s, int32_t page)
{
    return render_list<df::history_era>(s, page, "eras-", "History Eras");
}
bool WebLegends::render_figure_list(std::ostream & s, int32_t page)
{
    return render_list<df::historical_figure>(s, page, "figs-", "Historical Figures");
}
bool WebLegends::render_item_list(std::ostream & s, int32_t page)
{
    return render_list<df::artifact_record>(s, page, "items-", "Artifacts");
}
bool WebLegends::render_region_list(std::ostream & s, int32_t page)
{
    return render_list<df::world_region>(s, page, "regions-", "Regions");
}
bool WebLegends::render_site_list(std::ostream & s, int32_t page)
{
    return render_list<df::world_site>(s, page, "sites-", "Sites");
}
bool WebLegends::render_layer_list(std::ostream & s, int32_t page)
{
    return render_list<df::world_underground_region>(s, page, "layers-", "Underground Regions");
}
