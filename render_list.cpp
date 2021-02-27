#include "weblegends.h"
#include "helpers.h"

#include "df/artifact_record.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_era.h"
#include "df/history_event_collection.h"
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
std::vector<df::history_event_collection *> & get_vector<df::history_event_collection>()
{
    static std::vector<df::history_event_collection *> filtered;
    filtered.clear();

    for (auto col : df::history_event_collection::get_vector())
    {
        if (col->getParent() == -1)
        {
            filtered.push_back(col);
        }
    }

    return filtered;
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
static bool render_list(Layout & l, int32_t page, const std::string & prefix, const std::string & title, bool translate = true)
{
    auto begin = get_first<T>();

    int32_t page_count = (int32_t(get_vector<T>().end() - begin) + items_per_page - 1) / items_per_page;
    if (page < 0 || page >= page_count)
    {
        return false;
    }

    l.set_title(stl_sprintf("%s, page %d", title.c_str(), page));
    l.set_base_path("./");
    l.add_header_link("", title, true);
    auto & s = l.content;
    for (auto it = begin + (page * items_per_page); it != get_vector<T>().end() && it != begin + ((page + 1) * items_per_page); it++)
    {
        s << "<li>";
        link(s, *it, translate);
        categorize(s, *it);
        do_extra(s, *it);
        s << "</li>";
    }
    s << "</ul>";
    pagination(s, prefix, "0", "", page, page_count - 1);
    return true;
}

bool WebLegends::render_entity_list(Layout & l, int32_t page)
{
    return render_list<df::historical_entity>(l, page, "ents-", "Civilizations and other entities");
}
bool WebLegends::render_eventcol_list(Layout & l, int32_t page)
{
    return render_list<df::history_event_collection>(l, page, "eventcols-", "History Event Collections", false);
}
bool WebLegends::render_figure_list(Layout & l, int32_t page)
{
    return render_list<df::historical_figure>(l, page, "figs-", "Historical Figures");
}
bool WebLegends::render_item_list(Layout & l, int32_t page)
{
    return render_list<df::artifact_record>(l, page, "items-", "Artifacts", false);
}
bool WebLegends::render_region_list(Layout & l, int32_t page)
{
    return render_list<df::world_region>(l, page, "regions-", "Regions");
}
bool WebLegends::render_site_list(Layout & l, int32_t page)
{
    return render_list<df::world_site>(l, page, "sites-", "Sites");
}
bool WebLegends::render_layer_list(Layout & l, int32_t page)
{
    return render_list<df::world_underground_region>(l, page, "layers-", "Underground Regions", false);
}
