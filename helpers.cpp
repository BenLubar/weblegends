#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/historical_figure_info.h"
#include "df/history_event.h"
#include "df/world.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(world);

static void link_name(std::ostream & s, const std::string & prefix, int32_t id, const df::language_name & name)
{
    s << "<a href=\"" << prefix << id << "\" title=\"" << Translation::TranslateName(&name, true, false) << "\">" << Translation::TranslateName(&name, false, false) << "</a>";
}

void link(std::ostream & s, df::abstract_building *structure)
{
    s << "<a href=\"bld-" << structure->site_id << "-" << structure->id << "\" title=\"" << Translation::TranslateName(structure->getName(), true, false) << "\">" << Translation::TranslateName(structure->getName(), false, false) << "</a>";
}
void link(std::ostream & s, df::historical_entity *ent)
{
    link_name(s, "ent-", ent->id, ent->name);
}
void link(std::ostream & s, df::historical_figure *hf)
{
    link_name(s, "fig-", hf->id, hf->name);
}
void link(std::ostream & s, df::world_region *region)
{
    link_name(s, "region-", region->index, region->name);
}
void link(std::ostream & s, df::world_site *site)
{
    link_name(s, "site-", site->id, site->name);
}
void link(std::ostream & s, df::world_underground_region *layer)
{
    link_name(s, "layer-", layer->index, layer->name);
}

template<typename T>
static void event_link_name(std::ostream & s, T *reference, T *actual)
{
    if (reference == actual)
    {
        if (!actual->name.first_name.empty())
        {
            s << Translation::capitalize(actual->name.first_name);
        }
        else
        {
            s << "<abbr title=\"" << Translation::TranslateName(&actual->name, true, true) << "\">" << Translation::TranslateName(&actual->name, false, true) << "</abbr>";
        }
    }
    else
    {
        link(s, actual);
    }
}

void event_link(std::ostream & s, const event_context & context, df::abstract_building *structure)
{
    if (context.structure == structure)
    {
        s << "<abbr title=\"" << Translation::TranslateName(structure->getName(), true, false) << "\">" << Translation::TranslateName(structure->getName(), false, false) << "</abbr>";
    }
    else
    {
        link(s, structure);
    }
}
void event_link(std::ostream & s, const event_context & context, df::historical_entity *ent)
{
    event_link_name(s, context.ent, ent);
}
void event_link(std::ostream & s, const event_context & context, df::historical_figure *hf)
{
    event_link_name(s, context.hf, hf);
}
void event_link(std::ostream & s, const event_context & context, df::world_region *region)
{
    event_link_name(s, context.region, region);
}
void event_link(std::ostream & s, const event_context & context, df::world_site *site)
{
    event_link_name(s, context.site, site);
}
void event_link(std::ostream & s, const event_context & context, df::world_underground_region *layer)
{
    event_link_name(s, context.layer, layer);
}

void spheres(std::ostream & s, df::historical_figure *hf)
{
    if (hf->info && hf->info->spheres && !hf->info->spheres->empty())
    {
        s << " representing ";
        list<df::sphere_type>(s, *hf->info->spheres, [](std::ostream & out, df::sphere_type t)
                {
                    std::string sphere(ENUM_KEY_STR(sphere_type, t));
                    std::transform(sphere.begin(), sphere.end(), sphere.begin(), ::tolower);
                    out << sphere;
                });
    }
}

void born_died(std::ostream & s, df::historical_figure *hf)
{
    // TODO: handle negative years
    if (hf->born_year <= -1 && hf->died_year <= -1)
    {
        return;
    }

    s << " (";
    if (hf->born_year > -1)
    {
        s << "b. ";
        year(s, hf->born_year, hf->born_seconds);
        if (hf->died_year > -1)
        {
            s << " ";
        }
    }
    if (hf->died_year > -1)
    {
        s << "d. ";
        year(s, hf->died_year, hf->died_seconds);
    }
    s << ")";
}

static const std::string months[12] =
{
    "Granite",
    "Slate",
    "Felsite",
    "Hematite",
    "Malachite",
    "Galena",
    "Limestone",
    "Sandstone",
    "Timber",
    "Moonstone",
    "Opal",
    "Obsidian"
};

void year(std::ostream & s, int32_t year, int32_t tick)
{
    if (tick != -1)
    {
        s << "<abbr title=\"";
        s << day(tick) << " " << month(tick) << " " << year;
        s << "\">" << year << "</abbr>";
    }
    else
    {
        s << year;
    }
}

int32_t day(int32_t tick)
{
    return ((tick / 1200) % 28) + 1;
}

std::string dayth(int32_t tick)
{
    int32_t d = day(tick);
    if (d >= 11 && d <= 13)
        return stl_sprintf("the %dth of", d);
    if (d % 10 == 1)
        return stl_sprintf("the %dst of", d);
    if (d % 10 == 2)
        return stl_sprintf("the %dnd of", d);
    if (d % 10 == 3)
        return stl_sprintf("the %drd of", d);
    return stl_sprintf("the %dth of", d);
}

const std::string & month(int32_t tick)
{
    return months[(tick / 1200 / 28) % 12];
}

void history(std::ostream & s, const event_context & context)
{
    int32_t last_year = 0;
    int32_t last_seconds = -1;
    for (auto it = world->history.events.begin(); it != world->history.events.end(); it++)
    {
        if (!context.related(*it))
        {
            continue;
        }

        if (last_year == 0)
        {
            s << "<h2 id=\"history\">History</h2><p id=\"history-" << (*it)->year << "\">";
        }
        else if ((*it)->year != last_year)
        {
            s << "</p><p id=\"history-" << (*it)->year << "\">";
        }
        event(s, context, *it, last_year, last_seconds);
    }
    if (last_year != 0)
    {
        s << "</p>";
    }
}

bool event_context::related(df::history_event *event) const
{
    if (site && event->isRelatedToSiteID(site->id))
        return true;
    if (ent && event->isRelatedToEntityID(ent->id))
        return true;
    if (hf && event->isRelatedToHistfigID(hf->id))
        return true;
    if (region && event->isRelatedToRegionID(region->index))
        return true;
    if (site && event->isRelatedToSiteID(site->id))
        return true;
    if (layer && event->isRelatedToLayerID(layer->index))
        return true;
    return false;
}