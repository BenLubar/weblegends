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

template<typename T>
inline void do_location_1(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
{
    if (auto loc = df::world_site::find(event->site))
    {
        if (loc != context.site)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }
    if (auto loc = df::world_region::find(event->subregion))
    {
        if (loc != context.region)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }
    if (auto loc = df::world_underground_region::find(event->feature_layer))
    {
        if (loc != context.layer)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }
}

template<typename T>
inline void do_location_1_structure(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
{
    if (auto site = df::world_site::find(event->site))
    {
        if (auto loc = binsearch_in_vector(site->buildings, event->structure))
        {
            if (loc != context.structure)
            {
                s << separator;
                link(s, loc);
                separator = " in ";
            }
        }
    }
    do_location_1(s, context, event, separator);
}

template<typename T>
inline void do_location_2(std::ostream & s, const event_context & context, T *event, std::string separator = " in ", bool force = false)
{
    if (auto loc = df::world_site::find(event->site))
    {
        if (loc != context.site || force)
        {
            s << separator;
            event_link(s, context, loc);
            separator = " in ";
        }
    }
    if (auto loc = df::world_region::find(event->region))
    {
        if (loc != context.region || force)
        {
            s << separator;
            event_link(s, context, loc);
            separator = " in ";
        }
    }
    // TODO: df::coord2d region_pos;
    if (auto loc = df::world_underground_region::find(event->layer))
    {
        if (loc != context.layer || force)
        {
            s << separator;
            event_link(s, context, loc);
            separator = " in ";
        }
    }
}

template<typename T>
inline void do_location_2_structure(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
{
    if (auto site = df::world_site::find(event->site))
    {
        if (auto loc = binsearch_in_vector(site->buildings, event->structure))
        {
            if (loc != context.structure)
            {
                s << separator;
                link(s, loc);
                separator = " in ";
            }
        }
    }
    do_location_2(s, context, event, separator);
}

void do_item_description(std::ostream & s, const event_context & context, df::item *item);

template<typename T>
inline typename void_t<decltype(T::caste)>::type do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
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

template<typename T>
inline typename std::enable_if<!std::is_base_of<df::item_constructed, T>::value, typename void_t<decltype(T::mat_type)>::type>::type do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
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
