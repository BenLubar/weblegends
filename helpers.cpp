#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"
#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/abstract_building_dungeonst.h"
#include "df/abstract_building_templest.h"
#include "df/artifact_record.h"
#include "df/caste_raw.h"
#include "df/creature_interaction_effect_body_transformationst.h"
#include "df/creature_raw.h"
#include "df/entity_site_link.h"
#include "df/general_ref_is_artifactst.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/historical_figure_info.h"
#include "df/history_era.h"
#include "df/history_event_collection.h"
#include "df/interaction_effect_add_syndromest.h"
#include "df/interaction_effect_animatest.h"
#include "df/item_constructed.h"
#include "df/itemimprovement_pagesst.h"
#include "df/itemimprovement_writingst.h"
#include "df/syndrome.h"
#include "df/world.h"
#include "df/world_data.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

REQUIRE_GLOBAL(cur_year);
REQUIRE_GLOBAL(cur_year_tick);
REQUIRE_GLOBAL(world);

int32_t get_id(df::abstract_building *structure)
{
    return structure ? structure->id : -1;
}
int32_t get_id(df::artifact_record *item)
{
    return item ? item->id : -1;
}
int32_t get_id(df::historical_entity *ent)
{
    return ent ? ent->id : -1;
}
int32_t get_id(df::historical_figure *hf)
{
    return hf ? hf->id : -1;
}
int32_t get_id(df::world_region *region)
{
    return region ? region->index : -1;
}
int32_t get_id(df::world_site *site)
{
    return site ? site->id : -1;
}
int32_t get_id(df::world_underground_region *layer)
{
    return layer ? layer->index : -1;
}
int32_t get_id(df::history_era *era)
{
    return era ? std::find(world->history.eras.begin(), world->history.eras.end(), era) - world->history.eras.begin() : -1;
}
int32_t get_id(df::history_event_collection *eventcol)
{
    return eventcol ? eventcol->id : -1;
}

static const df::language_name & get_no_name()
{
    static df::language_name no_name;
    no_name.has_name = false;
    return no_name;
}

const df::language_name & get_name(df::abstract_building *structure)
{
    return structure && structure->getName() ? *structure->getName() : get_no_name();
}
const df::language_name & get_name(df::artifact_record *item)
{
    return item ? item->name : get_no_name();
}
const df::language_name & get_name(df::historical_entity *ent)
{
    return ent ? ent->name : get_no_name();
}
const df::language_name & get_name(df::historical_figure *hf)
{
    return hf ? hf->name : get_no_name();
}
const df::language_name & get_name(df::world_region *region)
{
    return region ? region->name : get_no_name();
}
const df::language_name & get_name(df::world_site *site)
{
    return site ? site->name : get_no_name();
}
const df::language_name & get_name(df::world_underground_region *layer)
{
    return layer ? layer->name : get_no_name();
}
const df::language_name & get_name(df::history_era *era)
{
    static df::language_name name;
    name.first_name = era ? era->title.name : "";
    name.has_name = !name.first_name.empty();
    name.nickname = "";
    name.words[0] = -1;
    name.words[1] = -1;
    name.words[2] = -1;
    name.words[3] = -1;
    name.words[4] = -1;
    name.words[5] = -1;
    name.words[6] = -1;
    return name;
}
const df::language_name & get_name(df::history_event_collection *eventcol)
{
    static df::language_name name;
    name.first_name = "";
    if (eventcol)
        eventcol->getName(&name.first_name);
    name.has_name = !name.first_name.empty();
    name.nickname = "";
    name.words[0] = -1;
    name.words[1] = -1;
    name.words[2] = -1;
    name.words[3] = -1;
    name.words[4] = -1;
    name.words[5] = -1;
    name.words[6] = -1;
    return name;
}
// for render_home
const df::language_name & get_name(df::world_data *world_data)
{
    return world_data->name;
}

template<typename T>
static void link_name(std::ostream & s, const std::string & prefix, T *target)
{
    int32_t id = get_id(target);
    const df::language_name & name = get_name(target);

    if (name.has_name)
    {
        s << "<a href=\"" << prefix << id << "\" title=\"" << html_escape(DF2UTF(Translation::TranslateName(&name, true, false))) << ",";
        categorize(s, target, true, true);
        s << "\">" << html_escape(DF2UTF(Translation::TranslateName(&name, false, false))) << "</a>";
    }
    else if (id == -1)
    {
        s << "[unknown ";
        categorize(s, target, true);
        s << "]";
    }
    else
    {
        s << "<a href=\"" << prefix << id << "\">[unnamed";
        categorize(s, target, true);
        s << "]</a>";
    }
}

void link(std::ostream & s, df::abstract_building *structure)
{
    std::string prefix = structure ? stl_sprintf("site-%d/bld-", structure->site_id) : "";
    link_name(s, prefix, structure);
}
void link(std::ostream & s, df::artifact_record *item)
{
    link_name(s, "item-", item);
}
void link(std::ostream & s, df::historical_entity *ent)
{
    link_name(s, "ent-", ent);
}
void link(std::ostream & s, df::history_era *era)
{
    link_name(s, "era-", era);
}
void link(std::ostream & s, df::history_event_collection *eventcol)
{
    link_name(s, "eventcol-", eventcol);
}
void link(std::ostream & s, df::historical_figure *hf)
{
    link_name(s, "fig-", hf);
}
void link(std::ostream & s, df::world_region *region)
{
    link_name(s, "region-", region);
}
void link(std::ostream & s, df::world_site *site)
{
    link_name(s, "site-", site);
}
void link(std::ostream & s, df::world_underground_region *layer)
{
    link_name(s, "layer-", layer);
}

void name_translated(std::ostream & s, const df::language_name & name, bool only_last)
{
    std::string native = html_escape(DF2UTF(Translation::TranslateName(&name, false, only_last)));
    std::string english = html_escape(DF2UTF(Translation::TranslateName(&name, true, only_last)));
    if (native != english)
    {
        s << "<abbr title=\"" << english << "\">" << native << "</abbr>";
    }
    else
    {
        s << native;
    }
}

template<typename T>
static void event_link_name(std::ostream & s, T *reference, T *actual)
{
    if (reference == actual)
    {
        const df::language_name & name = get_name(actual);
        if (!name.has_name)
        {
            s << "[unnamed";
            categorize(s, actual);
            s << "]";
        }
        else if (!name.first_name.empty())
        {
            s << DF2UTF(Translation::capitalize(name.first_name));
        }
        else
        {
            name_translated(s, name, true);
        }
    }
    else
    {
        link(s, actual);
    }
}

void event_link(std::ostream & s, const event_context & context, df::abstract_building *structure)
{
    event_link_name(s, context.structure, structure);
}
void event_link(std::ostream & s, const event_context & context, df::artifact_record *item)
{
    bool italicize = false;
    if (item && item->name.has_name && !item->name.first_name.empty())
    {
        if (auto constructed = virtual_cast<df::item_constructed>(item->item))
        {
            for (auto it = constructed->improvements.begin(); it != constructed->improvements.end(); it++)
            {
                if (virtual_cast<df::itemimprovement_writingst>(*it) || virtual_cast<df::itemimprovement_pagesst>(*it))
                {
                    italicize = true;
                    break;
                }
            }
        }
    }
    if (italicize)
    {
        s << "<em>";
    }
    event_link_name(s, context.item, item);
    if (italicize)
    {
        s << "</em>";
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
void event_link(std::ostream & s, const event_context & context, df::history_era *era)
{
    event_link_name(s, context.era, era);
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

void age_years_days(int32_t year, int32_t tick, int32_t year_compare, int32_t tick_compare, int32_t & years, int32_t & days)
{
    years = year_compare - year;
    days = tick_compare - tick;
    if (days < 0 && years > 0)
    {
        years--;
        days += 1200 * 28 * 12;
    }
    days /= 1200;
}

void categorize(std::ostream & s, df::abstract_building *structure, bool in_link, bool in_attr)
{
    if (!structure)
    {
        s << " structure";
        return;
    }

    BEFORE_SWITCH(type, structure->getType());
    switch (type)
    {
    case abstract_building_type::MEAD_HALL:
        s << " mead hall";
        BREAK(type);
    case abstract_building_type::KEEP:
        s << " keep";
        BREAK(type);
    case abstract_building_type::TEMPLE:
        s << " temple";
        if (auto temple = virtual_cast<df::abstract_building_templest>(structure))
        {
            BEFORE_SWITCH(deity_type, temple->deity_type);
            switch (deity_type)
            {
            case temple_deity_type::None:
                BREAK(deity_type);
            case temple_deity_type::Deity:
                if (auto deity = df::historical_figure::find(temple->deity_data.Deity))
                {
                    if (in_link)
                    {
                        const df::language_name & name = get_name(deity);
                        if (name.has_name)
                        {
                            s << " of ";
                            if (in_attr)
                            {
                                s << html_escape(DF2UTF(Translation::TranslateName(&name, false)));
                            }
                            else
                            {
                                name_translated(s, name);
                            }
                        }
                    }
                    else
                    {
                        s << " of ";
                        link(s, deity);
                    }
                }
                BREAK(deity_type);
            case temple_deity_type::Religion:
                if (auto religion = df::historical_entity::find(temple->deity_data.Religion))
                {
                    if (in_link)
                    {
                        const df::language_name & name = get_name(religion);
                        if (name.has_name)
                        {
                            s << " of ";
                            if (in_attr)
                            {
                                s << html_escape(DF2UTF(Translation::TranslateName(&name, false)));
                            }
                            else
                            {
                                name_translated(s, name);
                            }
                        }
                    }
                    else
                    {
                        s << " of ";
                        link(s, religion);
                    }
                }
                BREAK(deity_type);
            }
            AFTER_SWITCH(deity_type, stl_sprintf("site-%d/bld-%d (temple)", structure->site_id, structure->id));
        }
        BREAK(type);
    case abstract_building_type::DARK_TOWER:
        s << " dark tower";
        BREAK(type);
    case abstract_building_type::MARKET:
        s << " market";
        BREAK(type);
    case abstract_building_type::TOMB:
        s << " tomb";
        BREAK(type);
    case abstract_building_type::DUNGEON:
        if (auto dungeon = virtual_cast<df::abstract_building_dungeonst>(structure))
        {
            BEFORE_SWITCH(dungeon_type, dungeon->dungeon_type);
            switch (dungeon_type)
            {
            case df::abstract_building_dungeonst::T_dungeon_type::DUNGEON:
                s << " dungeon";
                BREAK(dungeon_type);
            case df::abstract_building_dungeonst::T_dungeon_type::SEWERS:
                s << " sewers";
                BREAK(dungeon_type);
            case df::abstract_building_dungeonst::T_dungeon_type::CATACOMBS:
                s << " catacombs";
                BREAK(dungeon_type);
            }
            AFTER_SWITCH(dungeon_type, stl_sprintf("site-%d/bld-%d (dungeon)", structure->site_id, structure->id));
        }
        else
        {
            s << " dungeon";
        }
        BREAK(type);
    case abstract_building_type::UNDERWORLD_SPIRE:
        s << " underworld spire";
        BREAK(type);
    case abstract_building_type::INN_TAVERN:
        s << " tavern";
        BREAK(type);
    case abstract_building_type::LIBRARY:
        s << " library";
        BREAK(type);
    case abstract_building_type::COUNTING_HOUSE:
        s << " counting house";
        BREAK(type);
    case abstract_building_type::GUILDHALL:
        s << " guild hall";
        BREAK(type);
    case abstract_building_type::TOWER:
        s << " tower";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("site-%d/bld-%d", structure->site_id, structure->id));
}
void categorize(std::ostream & s, df::artifact_record *item, bool in_link, bool in_attr)
{
    if (!item)
    {
        s << " artifact";
        return;
    }

    s << " ";
    material(s, event_context(), item->item, in_link, in_attr);
    s << " " << html_escape(DF2UTF(ItemTypeInfo(item->item).toString()));
}
void categorize(std::ostream & s, df::historical_entity *ent, bool, bool)
{
    if (!ent)
    {
        s << " entity";
        return;
    }

    if (auto race = df::creature_raw::find(ent->race))
    {
        s << " " << html_escape(DF2UTF(race->name[2]));
    }

    BEFORE_SWITCH(type, ent->type);
    switch (type)
    {
    case historical_entity_type::Civilization:
        s << " civilization";
        BREAK(type);
    case historical_entity_type::SiteGovernment:
        s << " site government";
        BREAK(type);
    case historical_entity_type::VesselCrew:
        s << " vessel crew";
        BREAK(type);
    case historical_entity_type::MigratingGroup:
        s << " migrating group";
        BREAK(type);
    case historical_entity_type::NomadicGroup:
        s << " nomadic group";
        BREAK(type);
    case historical_entity_type::Religion:
        s << " religion";
        BREAK(type);
    case historical_entity_type::MilitaryUnit:
        s << " military unit";
        BREAK(type);
    case historical_entity_type::Outcast:
        s << " outcast group";
        BREAK(type);
    case historical_entity_type::PerformanceTroupe:
        s << " performance troupe";
        BREAK(type);
    case historical_entity_type::MerchantCompany:
        s << " merchant company";
        BREAK(type);
    case historical_entity_type::Guild:
        s << " guild";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("ent-%d", ent->id));
}
void categorize(std::ostream & s, df::historical_figure *hf, bool, bool)
{
    if (!hf)
    {
        s << " figure";
        return;
    }

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

        int32_t age_years, age_days;
        if (hf->died_year == -1)
        {
            age_years_days(hf->born_year, hf->born_seconds, *cur_year, *cur_year_tick, age_years, age_days);
        }
        else
        {
            age_years_days(hf->born_year, hf->born_seconds, hf->died_year, hf->died_seconds, age_years, age_days);
        }
        std::string name(caste->caste_name[0]);
        std::string suffix;
        if (caste->flags.is_set(caste_raw_flags::HAS_BABYSTATE) && age_years < caste->misc.baby_age)
        {
            if (caste->baby_name[0].empty())
            {
                suffix = " baby";
            }
            else
            {
                name = caste->baby_name[0];
            }
        }
        else if (caste->flags.is_set(caste_raw_flags::HAS_CHILDSTATE) && age_years < caste->misc.child_age)
        {
            if (caste->child_name[0].empty())
            {
                suffix = " child";
            }
            else
            {
                name = caste->child_name[0];
            }
        }

        if (name == race->name[0] && hf->sex != -1)
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
        s << " " << html_escape(DF2UTF(name)) << suffix;

        if (hf->flags.is_set(histfig_flags::deity) || hf->flags.is_set(histfig_flags::skeletal_deity) || hf->flags.is_set(histfig_flags::rotting_deity))
        {
            s << " deity";
        }
    }
    else if (hf->flags.is_set(histfig_flags::force))
    {
        s << " force";
    }

    if (hf->info && hf->info->curse)
    {
        if (!hf->info->curse->name.empty())
        {
            s << " " << html_escape(DF2UTF(hf->info->curse->name));
        }
        for (auto it = hf->info->curse->active_effects.begin(); it != hf->info->curse->active_effects.end(); it++)
        {
            std::vector<df::syndrome *> *syndromes = nullptr;
            if (auto syndrome = virtual_cast<df::interaction_effect_add_syndromest>(*it))
            {
                syndromes = &syndrome->syndrome;
            }
            else if (auto zombie = virtual_cast<df::interaction_effect_animatest>(*it))
            {
                syndromes = &zombie->syndrome;
            }
            else
            {
                continue;
            }
            for (auto it2 = syndromes->begin(); it2 != syndromes->end(); it2++)
            {
                for (auto it3 = (*it2)->ce.begin(); it3 != (*it2)->ce.end(); it3++)
                {
                    if (auto transformation = virtual_cast<df::creature_interaction_effect_body_transformationst>(*it3))
                    {
                        auto race_caste = find_creature_raws(transformation->race_str, transformation->caste_str);
                        if (race_caste.second)
                        {
                            s << " " << html_escape(DF2UTF(race_caste.second->caste_name[0]));
                        }
                    }
                }
            }
        }
    }
}
void categorize(std::ostream & s, df::history_era *, bool, bool)
{
    s << " era";
    // TODO
}
void categorize(std::ostream & s, df::history_event_collection *eventcol, bool, bool)
{
    if (eventcol)
        s << " " << toLower(enum_item_key_str(eventcol->getType()));
    s << " event collection";
    // TODO
}
void categorize(std::ostream & s, df::world_region *region, bool, bool)
{
    if (!region)
    {
        s << " region";
        return;
    }

    if (region->good)
    {
        s << " good";
    }
    if (region->evil)
    {
        s << " evil";
    }

    BEFORE_SWITCH(type, region->type);
    switch (type)
    {
    case world_region_type::Swamp:
        s << " swamp";
        BREAK(type);
    case world_region_type::Desert:
        s << " desert";
        BREAK(type);
    case world_region_type::Jungle:
        s << " jungle";
        BREAK(type);
    case world_region_type::Mountains:
        s << " mountains";
        BREAK(type);
    case world_region_type::Ocean:
        s << " ocean";
        BREAK(type);
    case world_region_type::Lake:
        s << " lake";
        BREAK(type);
    case world_region_type::Glacier:
        s << " glacier";
        BREAK(type);
    case world_region_type::Tundra:
        s << " tundra";
        BREAK(type);
    case world_region_type::Steppe:
        s << " steppe";
        BREAK(type);
    case world_region_type::Hills:
        s << " hills";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("region-%d", region->index));
}
void categorize(std::ostream & s, df::world_site *site, bool, bool)
{
    if (!site)
    {
        s << " site";
        return;
    }

    if (auto ent = df::historical_entity::find(site->cur_owner_id))
    {
        if (auto race = df::creature_raw::find(ent->race))
        {
            s << " " << html_escape(DF2UTF(race->name[2]));
        }
    }
    else
    {
        df::entity_site_link *found = nullptr;
        for (auto link : site->entity_links)
        {
            if (link->flags.bits.residence)
            {
                if (found)
                {
                    // Don't try to handle multiple claims.
                    found = nullptr;
                    break;
                }
                found = link;
            }
        }

        if (auto ent = found ? df::historical_entity::find(found->entity_id) : nullptr)
        {
            if (auto race = df::creature_raw::find(ent->race))
            {
                s << " " << html_escape(DF2UTF(race->name[2]));
            }
        }
    }

    BEFORE_SWITCH(type, site->type);
    switch (type)
    {
    case world_site_type::PlayerFortress:
        s << " fortress";
        BREAK(type);
    case world_site_type::DarkFortress:
        s << " dark fortress";
        BREAK(type);
    case world_site_type::Cave:
        s << " cave";
        BREAK(type);
    case world_site_type::MountainHalls:
        s << " mountain hall";
        BREAK(type);
    case world_site_type::ForestRetreat:
        s << " forest retreat";
        BREAK(type);
    case world_site_type::Town:
        s << " town";
        BREAK(type);
    case world_site_type::ImportantLocation:
        s << " important location";
        BREAK(type);
    case world_site_type::LairShrine:
        if (site->subtype_info)
        {
            BEFORE_SWITCH(subtype, site->subtype_info->lair_type);
            switch (subtype)
            {
            case lair_type::NONE:
                s << " lair";
                BREAK(subtype);
            case lair_type::SIMPLE_MOUND:
                s << " lair"; // night creatures
                BREAK(subtype);
            case lair_type::SIMPLE_BURROW:
                s << " lair";
                BREAK(subtype);
            case lair_type::LABYRINTH:
                s << " monument";
                BREAK(subtype);
            case lair_type::SHRINE:
                s << " shrine";
                BREAK(subtype);
            case lair_type::WILDERNESS_LOCATION:
                s << " nest";
                BREAK(subtype);
            }
            AFTER_SWITCH(subtype, stl_sprintf("site-%d (lair)", site->id));
        }
        else
        {
            s << " lair";
        }
        BREAK(type);
    case world_site_type::Fortress:
        if (site->subtype_info)
        {
            BEFORE_SWITCH(subtype, site->subtype_info->fortress_type);
            switch (subtype)
            {
            case fortress_type::NONE:
                s << " fortress";
                BREAK(subtype);
            case fortress_type::CASTLE:
                s << " castle";
                BREAK(subtype);
            case fortress_type::TOWER:
                s << " tower";
                BREAK(subtype);
            case fortress_type::MONASTERY:
                s << " monastery";
                BREAK(subtype);
            case fortress_type::FORT:
                s << " fort";
                BREAK(subtype);
            }
            AFTER_SWITCH(subtype, stl_sprintf("site-%d (fortress)", site->id));
        }
        else
        {
            s << " fortress";
        }
        BREAK(type);
    case world_site_type::Camp:
        s << " camp";
        BREAK(type);
    case world_site_type::Monument:
        if (site->subtype_info)
        {
            BEFORE_SWITCH(subtype, site->subtype_info->monument_type);
            switch (subtype)
            {
            case monument_type::NONE:
                s << " monument";
                BREAK(subtype);
            case monument_type::TOMB:
                s << " tomb";
                BREAK(subtype);
            case monument_type::VAULT:
                s << " vault";
                BREAK(subtype);
            }
            AFTER_SWITCH(subtype, stl_sprintf("site-%d (monument)", site->id));
        }
        else
        {
            s << " monument";
        }
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("site-%d", site->id));
}
void categorize(std::ostream & s, df::world_underground_region *layer, bool, bool)
{
    if (!layer)
    {
        s << " underground region";
        return;
    }

    BEFORE_SWITCH(type, layer->type);
    switch (type)
    {
    case df::world_underground_region::T_type::Cavern:
        s << " cavern";
        BREAK(type);
    case df::world_underground_region::T_type::MagmaSea:
        s << " magma sea";
        BREAK(type);
    case df::world_underground_region::T_type::Underworld:
        s << " underworld";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("layer-%d", layer->index));
}
// for render_home
void categorize(std::ostream & s, df::world_data *, bool, bool)
{
    s << " world";
}

template<typename T>
void simple_header_impl(Layout & l, T subject, bool sub = false)
{
    const df::language_name & name = get_name(subject);
    std::ostringstream title;
    if (name.has_name)
    {
        title << DF2UTF(Translation::TranslateName(&name, false, false));
    }
    else
    {
        title << "unnamed";
        categorize(title, subject, true, true);
    }
    l.set_title(title.str());
    l.set_base_path(sub ? "../" : "./");

    if (name.has_name)
    {
        std::string native = Translation::TranslateName(&name, false, false);
        std::string english = Translation::TranslateName(&name, true, false);
        if (native != english)
        {
            title << ", " LDQUO << DF2UTF(english) << RDQUO;
        }
    }

    l.add_header_link("", title.str(), true);
}

void simple_header(Layout & l, df::abstract_building *structure)
{
    simple_header_impl(l, structure, true);
}
void simple_header(Layout & l, df::artifact_record *item)
{
    simple_header_impl(l, item);
}
void simple_header(Layout & l, df::historical_entity *ent)
{
    simple_header_impl(l, ent);
}
void simple_header(Layout & l, df::historical_figure *hf)
{
    simple_header_impl(l, hf);
}
void simple_header(Layout & l, df::world_region *region)
{
    simple_header_impl(l, region);
}
void simple_header(Layout & l, df::world_site *site)
{
    simple_header_impl(l, site);
}
void simple_header(Layout & l, df::world_underground_region *layer)
{
    simple_header_impl(l, layer);
}
void simple_header(Layout & l, df::history_era *era)
{
    simple_header_impl(l, era);
}
void simple_header(Layout & l, df::history_event_collection *eventcol)
{
    simple_header_impl(l, eventcol);
}
// for render_home
void simple_header(Layout & l, df::world_data *world_data)
{
    simple_header_impl(l, world_data);
}

df::artifact_record *get_artifact(df::item *i)
{
    if (!i)
    {
        return nullptr;
    }

    for (auto ref : i->general_refs)
    {
        if (auto art = virtual_cast<df::general_ref_is_artifactst>(ref))
        {
            return df::artifact_record::find(art->artifact_id);
        }
    }
    return nullptr;
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

struct events_by_year
{
public:
    events_by_year(const event_context & context)
    {
        for (auto it = world->history.events.begin(); it != world->history.events.end(); it++)
        {
            if (context.related(*it))
            {
                size_t year = size_t(std::max((*it)->year, 0));
                if (events.size() <= year)
                {
                    events.resize(year + 1);
                }
                events.at(year).push_back(*it);
            }
        }

        for (auto it = events.begin(); it != events.end(); it++)
        {
            std::stable_sort(it->begin(), it->end(), [](df::history_event *a, df::history_event *b) -> bool
            {
                if (a->year != b->year)
                {
                    return a->year < b->year;
                }
                return a->seconds < b->seconds;
            });
        }
    }

    std::vector<std::vector<df::history_event *>> events;
};

bool history(std::ostream & s, const event_context & context, int32_t page, int32_t & last_page)
{
    const static size_t events_per_page = 1000;

    size_t events_on_this_page = 0;
    int32_t last_year = 0;
    int32_t last_seconds = -1;

    last_page = 0;

    events_by_year relevant(context);
    auto it = relevant.events.begin();
    for (int32_t pages_skipped = 0; pages_skipped < page; pages_skipped++)
    {
        for (; it != relevant.events.end(); it++)
        {
            events_on_this_page += it->size();

            if (events_on_this_page >= events_per_page)
            {
                it++;
                break;
            }
        }
        if (events_on_this_page != 0)
        {
            last_page = pages_skipped;
        }
        events_on_this_page = 0;
    }

    if (it != relevant.events.end())
    {
        s << "<h2 id=\"history\">History</h2>";
    }
    else if (page != 0)
    {
        return false;
    }

    for (; it != relevant.events.end(); it++)
    {
        if (!it->empty())
        {
            int32_t year = (it - relevant.events.begin());
            int32_t cur_month = 12;
            s << "<p id=\"history-" << year;
            if (year != 0 && it->size() > 20)
            {
                cur_month = it->at(0)->seconds < 0 ? -1 : std::max(0, it->at(0)->seconds / 1200 / 28);
                s << "-" << (cur_month + 1);
            }
            s << "\">";
            for (auto e : *it)
            {
                if (e->seconds >= 0 && cur_month < e->seconds / 1200 / 28)
                {
                    cur_month = e->seconds / 1200 / 28;
                    s << "</p><p id=\"history-" << year << "-" << (cur_month + 1) << "\">";
                }

                event(s, context, e, last_year, last_seconds);
            }
            s << "</p>";

            events_on_this_page += it->size();
            if (events_on_this_page >= events_per_page)
            {
                it++;
                break;
            }
        }
    }

    last_page = page;
    for (;;)
    {
        events_on_this_page = 0;
        for (; it != relevant.events.end(); it++)
        {
            events_on_this_page += it->size();

            if (events_on_this_page >= events_per_page)
            {
                it++;
                break;
            }
        }

        if (events_on_this_page != 0)
        {
            last_page++;
        }
        else
        {
            break;
        }
    }

    return true;
}

bool event_context::related(df::history_event *event) const
{
    if (structure && event->isRelatedToSiteStructure(structure->site_id, structure->id))
        return true;
    if (item && event->isRelatedToArtifactID(item->id))
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
    if (era && era->year <= event->year)
    {
        auto next_era = vector_get(world->history.eras, get_id(era) + 1);
        if (!next_era || event->year < next_era->year)
            return true;
    }
    if (eventcol && vector_contains(eventcol->events, event->id))
        return true;
    return false;
}

void material(std::ostream & s, const event_context & context, MaterialInfo mat, bool in_link, bool in_attr)
{
    if (!mat.isCreature())
    {
        s << mat.toString();
        return;
    }
    if (unique_creature_name(s, context, mat.creature, in_link, in_attr))
    {
        if (mat.material)
        {
            df::matter_state state = matter_state::Solid;
            if (10015 >= mat.material->heat.melting_point)
                state = matter_state::Liquid;
            if (10015 >= mat.material->heat.boiling_point)
                state = matter_state::Gas;
            s << " " << mat.material->state_name[state];
        }
        else
        {
            s << " unknown substance";
        }
        return;
    }
    s << mat.toString();
}

bool unique_creature_name(std::ostream & s, const event_context & context, df::creature_raw *creature, bool in_link, bool in_attr)
{
    if (creature->flags.is_set(creature_raw_flags::HAS_ANY_FEATURE_BEAST) || creature->flags.is_set(creature_raw_flags::HAS_ANY_TITAN) || creature->flags.is_set(creature_raw_flags::HAS_ANY_UNIQUE_DEMON))
    {
        for (auto it = world->history.figures.begin(); it != world->history.figures.end(); it++)
        {
            if (df::creature_raw::find((*it)->race) == creature)
            {
                if (in_link)
                {
                    const df::language_name & name = get_name(*it);
                    if (!name.has_name)
                    {
                        s << "[unnamed";
                        categorize(s, *it, true, in_attr);
                        s << "]";
                    }
                    else if (context.hf != *it)
                    {
                        if (in_attr)
                        {
                            s << Translation::TranslateName(&name, false);
                        }
                        else
                        {
                            name_translated(s, name);
                        }
                    }
                    else if (!name.first_name.empty())
                    {
                        s << Translation::capitalize(name.first_name);
                    }
                    else
                    {
                        if (in_attr)
                        {
                            s << Translation::TranslateName(&name, false, true);
                        }
                        else
                        {
                            name_translated(s, name, true);
                        }
                    }
                }
                else
                {
                    event_link(s, context, *it);
                }
                return true;
            }
        }
    }
    return false;
}

void pagination(std::ostream & s, const std::string & base, const std::string & page_0, const std::string & page_prefix, int32_t current_page, int32_t last_page)
{
    if (last_page != 0)
    {
        s << "<nav class=\"pagination\"><p>";
        if (current_page > 0)
        {
            s << "<a href=\"" << base << page_0 << "\" rel=\"first\">First</a>";
            if (current_page - 1 > 0)
            {
                s << " - <a href=\"" << base << page_prefix << (current_page - 1) << "\" rel=\"prev\">Previous</a>";
            }
            if (current_page < last_page)
            {
                s << " - ";
            }
        }
        if (current_page + 1 < last_page)
        {
            s << "<a href=\"" << base << page_prefix << (current_page + 1) << "\" rel=\"next\">Next</a> - ";
        }
        if (current_page < last_page)
        {
            s << "<a href=\"" << base << page_prefix << last_page << "\" rel=\"last\">Last</a>";
        }
        s << "</p></nav>";
    }
}

std::string format_number_u(uint64_t number)
{
    if (!number)
    {
        return "0";
    }

    // UINT64_MAX (for correct capacity)
    char buf[] = "18,446,744,073,709,551,615";
    // start pointing at null terminator
    char *ptr = &buf[sizeof(buf) - 1];
    while (number)
    {
        ptr--;
        if (*ptr == ',')
        {
            ptr--;
        }
        *ptr = '0' + (number % 10);
        number /= 10;
    }

    return ptr;
}

std::string format_number_s(int64_t number)
{
    if (number < 0)
    {
        return "-" + format_number_u(uint64_t(-number));
    }
    return format_number_u(uint64_t(number));
}

void spheres(std::ostream & s, df::historical_figure *hf)
{
    if (hf->info && hf->info->spheres && !hf->info->spheres->empty())
    {
        s << " associated with ";
        list<df::sphere_type>(s, *hf->info->spheres, [](std::ostream & out, df::sphere_type t)
        {
            out << toLower(enum_item_key_str(t));
        });
    }
}

void year(std::ostream & s, int32_t year, int32_t tick)
{
    if (tick != -1)
    {
        s << "<abbr title=\"";
        s << dayth(tick) << " " << month(tick) << " " << year;
        s << "\">" << year << "</abbr>";
    }
    else
    {
        s << year;
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

std::pair<df::creature_raw *, df::caste_raw *> find_creature_raws(const std::string & creature_id, const std::string & caste_id)
{
    auto race = binsearch_in_vector(world->raws.creatures.alphabetic, &df::creature_raw::creature_id, creature_id);
    int caste_idx = race ? linear_index(race->caste, &df::caste_raw::caste_id, caste_id) : -1;
    auto caste = race ? vector_get(race->caste, caste_idx) : nullptr;

    return std::make_pair(race, caste);
}
