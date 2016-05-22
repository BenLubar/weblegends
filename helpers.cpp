#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/abstract_building_dungeonst.h"
#include "df/abstract_building_templest.h"
#include "df/caste_raw.h"
#include "df/creature_raw.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/world.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(world);

static void link_name(std::ostream & s, const std::string & prefix, int32_t id, const df::language_name & name)
{
    if (name.has_name)
    {
        s << "<a href=\"" << prefix << id << "\" title=\"" << Translation::TranslateName(&name, true, false) << "\">" << Translation::TranslateName(&name, false, false) << "</a>";
    }
    else
    {
        s << "<a href=\"" << prefix << id << "\">[unnamed]</a>";
    }
}

void link(std::ostream & s, df::abstract_building *structure)
{
    s << "<a href=\"site-" << structure->site_id << "/bld-" << structure->id << "\" title=\"" << Translation::TranslateName(structure->getName(), true, false) << "\">" << Translation::TranslateName(structure->getName(), false, false) << "</a>";
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

void categorize(std::ostream & s, df::abstract_building *structure)
{
    switch (structure->getType())
    {
        case abstract_building_type::MEAD_HALL:
            s << " mead hall";
            break;
        case abstract_building_type::KEEP:
            s << " keep";
            break;
        case abstract_building_type::TEMPLE:
            s << " temple";
            if (auto temple = virtual_cast<df::abstract_building_templest>(structure))
            {
                if (auto deity = df::historical_figure::find(temple->deity))
                {
                    s << " of ";
                    link(s, deity);
                }
            }
            break;
        case abstract_building_type::DARK_TOWER:
            s << " dark tower";
            break;
        case abstract_building_type::MARKET:
            s << " market";
            break;
        case abstract_building_type::TOMB:
            s << " tomb";
            break;
        case abstract_building_type::DUNGEON:
            if (auto dungeon = virtual_cast<df::abstract_building_dungeonst>(structure))
            {
                switch (dungeon->dungeon_type)
                {
                    case df::abstract_building_dungeonst::T_dungeon_type::DUNGEON:
                        s << " dungeon";
                        break;
                    case df::abstract_building_dungeonst::T_dungeon_type::SEWERS:
                        s << " sewers";
                        break;
                    case df::abstract_building_dungeonst::T_dungeon_type::CATACOMBS:
                        s << " catacombs";
                        break;
                }
            }
            else
            {
                s << " dungeon";
            }
            break;
        case abstract_building_type::UNDERWORLD_SPIRE:
            s << " underworld spire";
            break;
        case abstract_building_type::INN_TAVERN:
            s << " tavern";
            break;
        case abstract_building_type::LIBRARY:
            s << " library";
            break;
    }
}
void categorize(std::ostream & s, df::historical_entity *ent)
{
    if (auto race = df::creature_raw::find(ent->race))
    {
        s << " " << race->name[2];
    }

    switch (ent->type)
    {
        case historical_entity_type::Civilization:
            s << " civilization";
            break;
        case historical_entity_type::SiteGovernment:
            s << " site government";
            break;
        case historical_entity_type::VesselCrew:
            s << " vessel crew";
            break;
        case historical_entity_type::MigratingGroup:
            s << " migrating group";
            break;
        case historical_entity_type::NomadicGroup:
            s << " nomadic group";
            break;
        case historical_entity_type::Religion:
            s << " religion";
            break;
        case historical_entity_type::MilitaryUnit:
            s << " military unit";
            break;
        case historical_entity_type::Outcast:
            s << " outcast group";
            break;
        case historical_entity_type::PerformanceTroupe:
            s << " performance troupe";
            break;
    }
}
void categorize(std::ostream & s, df::historical_figure *hf)
{
    auto race = df::creature_raw::find(hf->race);
    auto caste = (race && hf->caste != -1) ? race->caste.at(hf->caste) : nullptr;

    if (caste != nullptr)
    {
        if (hf->flags.is_set(histfig_flags::rotting_deity))
        {
            s << " rotting";
        }
        if (hf->flags.is_set(histfig_flags::skeletal_deity))
        {
            s << " skeletal";
        }
        if (caste->caste_name[0] == race->name[0] && hf->sex != -1)
        {
            if (hf->sex == 0)
            {
                s << " female";
            }
            else if (hf->sex == 1)
            {
                s << " male";
            }
        }
        s << " " << caste->caste_name[0];
        if (hf->flags.is_set(histfig_flags::deity) || hf->flags.is_set(histfig_flags::skeletal_deity) || hf->flags.is_set(histfig_flags::rotting_deity))
        {
            s << " deity";
        }
    }
    else if (hf->flags.is_set(histfig_flags::force))
    {
        s << " force";
    }
}
void categorize(std::ostream & s, df::world_region *region)
{
    switch (region->type)
    {
        case world_region_type::Swamp:
            s << " swamp";
            break;
        case world_region_type::Desert:
            s << " desert";
            break;
        case world_region_type::Jungle:
            s << " jungle";
            break;
        case world_region_type::Mountains:
            s << " mountains";
            break;
        case world_region_type::Ocean:
            s << " ocean";
            break;
        case world_region_type::Lake:
            s << " lake";
            break;
        case world_region_type::Glacier:
            s << " glacier";
            break;
        case world_region_type::Tundra:
            s << " tundra";
            break;
        case world_region_type::Steppe:
            s << " steppe";
            break;
        case world_region_type::Hills:
            s << " hills";
            break;
    }
}
void categorize(std::ostream & s, df::world_site *site)
{
    if (auto ent = df::historical_entity::find(site->cur_owner_id))
    {
        if (auto race = df::creature_raw::find(ent->race))
        {
            s << " " << race->name[2];
        }
    }

    switch (site->type)
    {
        case world_site_type::PlayerFortress:
            s << " fortress";
            break;
        case world_site_type::DarkFortress:
            s << " dark fortress";
            break;
        case world_site_type::Cave:
            s << " cave";
            break;
        case world_site_type::MountainHalls:
            s << " mountain hall";
            break;
        case world_site_type::ForestRetreat:
            s << " forest retreat";
            break;
        case world_site_type::Town:
            s << " town";
            break;
        case world_site_type::ImportantLocation:
            s << " important location";
            break;
        case world_site_type::LairShrine:
            if (site->subtype_info != nullptr && site->subtype_info->lair_type == 2)
            {
                s << " monument";
            }
            else if (site->subtype_info != nullptr && site->subtype_info->lair_type == 3)
            {
                s << " shrine";
            }
            else
            {
                s << " lair";
            }
            break;
        case world_site_type::Fortress:
            if (site->subtype_info != nullptr && site->subtype_info->is_tower == 1)
            {
                s << " tower";
            }
            else
            {
                s << " fortress";
            }
            break;
        case world_site_type::Camp:
            s << " camp";
            break;
        case world_site_type::Monument:
            if (site->subtype_info != nullptr && site->subtype_info->is_monument == 0)
            {
                s << " tomb";
            }
            else
            {
                s << " monument";
            }
            break;
    }
}
void categorize(std::ostream & s, df::world_underground_region *layer)
{
    switch (layer->type)
    {
        case df::world_underground_region::T_type::Cavern:
            s << " cavern";
            break;
        case df::world_underground_region::T_type::MagmaSea:
            s << " magma sea";
            break;
        case df::world_underground_region::T_type::Underworld:
            s << " underworld";
            break;
    }
}

void simple_header(std::ostream & s, const df::language_name *name, bool sub)
{
    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(name, false, false) << "</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << (sub ? "<base href=\"..\">" : "") << "</head><body>";
    s << "<h1>" << Translation::TranslateName(name, false, false) << " &ldquo;" << Translation::TranslateName(name, true, false)  << "&rdquo;</h1>";
}

int32_t day(int32_t tick)
{
    if (tick < 0)
    {
        return 0;
    }
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

const std::string & month(int32_t tick)
{
    if (tick < 0)
    {
        static std::string empty;
        return empty;
    }
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
