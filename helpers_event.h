#pragma once

#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"
#include "modules/Translation.h"
#include "modules/Units.h"
#include "modules/World.h"

#include "df/abstract_building.h"
#include "df/artifact_record.h"
#include "df/caste_raw.h"
#include "df/creature_raw.h"
#include "df/entity_position.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_era.h"
#include "df/history_event_circumstance_info.h"
#include "df/history_event_collection.h"
#include "df/history_event_reason_info.h"
#include "df/history_hit_item.h"
#include "df/identity.h"
#include "df/item_body_component.h"
#include "df/item_constructed.h"
#include "df/ui.h"
#include "df/world.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

using df::global::ui;
using df::global::world;

void do_event_missing(std::ostream & s, const event_context & context, df::history_event *event, const char *file, int line);
std::string profession_name(int32_t race, int16_t caste, df::profession prof, bool plural = false);
std::string profession_name(df::historical_figure *hf, df::profession prof, bool plural = false);

void do_location(std::ostream & s, const event_context & context, int32_t site, int32_t region, int32_t layer, int32_t structure = -1, std::string separator = " in ", bool force = false);

// a helper for SFINAE (Substitution Failire Is Not An Error)
// typename sfinae_helper<T, ...>::type is equivalent to T if the remaining types can be determined
// otherwise, the template fails to substitute
template<typename T, typename ...>
struct sfinae_helper
{
    typedef T type;
};

template<typename T, typename = int32_t>
struct do_location_structure_helper
{
    do_location_structure_helper(T *) {}
    operator int32_t() const { return -1; }
};

template<typename T>
struct do_location_structure_helper<T, decltype(T::structure)>
{
    do_location_structure_helper(T *event) : event(event) {}
    operator int32_t() const { return event->structure; }
private:
    T *event;
};

template<typename T, typename sfinae_helper<int, decltype(T::site), decltype(T::subregion), decltype(T::feature_layer)>::type = 0>
inline void do_location(std::ostream & s, const event_context & context, T *event, std::string separator = " in ", bool force = false)
{
    do_location(s, context, event->site, event->subregion, event->feature_layer, do_location_structure_helper<T>(event), separator, force);
}

template<typename T, typename sfinae_helper<short, decltype(T::site), decltype(T::region), decltype(T::layer)>::type = 0>
inline void do_location(std::ostream & s, const event_context & context, T *event, std::string separator = " in ", bool force = false)
{
    do_location(s, context, event->site, event->region, event->layer, do_location_structure_helper<T>(event), separator, force);
}

void do_item_description(std::ostream & s, const event_context & context, df::item *item);

template<typename T, typename sfinae_helper<short, decltype(T::caste)>::type = 0>
inline void do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
{
    auto item = df::allocate<T>();
    item->race = mat_type;
    item->caste = int16_t(mat_index);

    if (auto race = df::creature_raw::find(mat_type))
    {
        if (auto caste = vector_get(race->caste, mat_index))
        {
            std::ostringstream creature;
            if (unique_creature_name(creature, context, race))
            {
                std::string name = caste->caste_name[0];
                caste->caste_name[0] = creature.str();

                do_item_description(s, context, item);

                caste->caste_name[0] = name;

                delete item;

                return;
            }
        }
    }

    do_item_description(s, context, item);

    delete item;
}

template<typename T, typename D = typename std::remove_pointer<decltype(T::subtype)>::type>
inline void do_item_description(std::ostream & s, const event_context & context, int16_t item_subtype, int16_t mat_type, int32_t mat_index)
{
    auto item = df::allocate<T>();
    item->mat_type = mat_type;
    item->mat_index = mat_index;
    item->subtype = D::find(item_subtype);

    if (auto race = MaterialInfo(mat_type, mat_index).creature)
    {
        std::ostringstream creature;
        if (unique_creature_name(creature, context, race))
        {
            std::string name = race->name[0];
            race->name[0] = creature.str();

            do_item_description(s, context, item);

            race->name[0] = name;

            delete item;

            return;
        }
    }

    do_item_description(s, context, item);

    delete item;
}

template<typename T, typename sfinae_helper<typename std::enable_if<!std::is_base_of<df::item_constructed, T>::value, int>::type, decltype(T::mat_type)>::type = 0>
inline void do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
{
    auto item = df::allocate<T>();
    item->mat_type = mat_type;
    item->mat_index = mat_index;

    if (auto race = MaterialInfo(mat_type, mat_index).creature)
    {
        std::ostringstream creature;
        if (unique_creature_name(creature, context, race))
        {
            std::string name = race->name[0];
            race->name[0] = creature.str();

            do_item_description(s, context, item);

            race->name[0] = name;

            delete item;

            return;
        }
    }

    do_item_description(s, context, item);

    delete item;
}

bool do_weapon(std::ostream & s, const event_context & context, const df::history_hit_item & weapon, const std::string & prefix = " with ");

void do_identity(std::ostream & s, const event_context &, df::historical_figure *, df::identity *);

void do_circumstance_reason(std::ostream & s, const event_context & context, df::history_event *event, df::history_event_circumstance_info & circumstance, df::history_event_reason_info & reason);

template<typename T>
inline void do_circumstance_reason(std::ostream & s, const event_context & context, T *event)
{
    do_circumstance_reason(s, context, event, event->circumstance, event->reason);
}
