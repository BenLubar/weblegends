#pragma once

#include <functional>

namespace df
{
    struct abstract_building;
    struct historical_entity;
    struct historical_figure;
    struct history_event;
    struct language_name;
    struct world_region;
    struct world_site;
    struct world_underground_region;
}

struct event_context
{
    df::abstract_building *structure;
    df::historical_entity *ent;
    df::historical_figure *hf;
    df::world_region *region;
    df::world_site *site;
    df::world_underground_region *layer;

    event_context(df::abstract_building *structure) : structure(structure), ent(nullptr), hf(nullptr), region(nullptr), site(nullptr), layer(nullptr) {};
    event_context(df::historical_entity *ent) : structure(nullptr), ent(ent), hf(nullptr), region(nullptr), site(nullptr), layer(nullptr) {};
    event_context(df::historical_figure *hf) : structure(nullptr), ent(nullptr), hf(hf), region(nullptr), site(nullptr), layer(nullptr) {};
    event_context(df::world_region *region) : structure(nullptr), ent(nullptr), hf(nullptr), region(region), site(nullptr), layer(nullptr) {};
    event_context(df::world_site *site) : structure(nullptr), ent(nullptr), hf(nullptr), region(nullptr), site(site), layer(nullptr) {};
    event_context(df::world_underground_region *layer) : structure(nullptr), ent(nullptr), hf(nullptr), region(nullptr), site(nullptr), layer(layer) {};

    bool related(df::history_event *event) const;
};

void link(std::ostream & s, df::abstract_building *structure);
void link(std::ostream & s, df::historical_entity *ent);
void link(std::ostream & s, df::historical_figure *hf);
void link(std::ostream & s, df::world_region *region);
void link(std::ostream & s, df::world_site *site);
void link(std::ostream & s, df::world_underground_region *layer);

void event_link(std::ostream & s, const event_context & context, df::abstract_building *structure);
void event_link(std::ostream & s, const event_context & context, df::historical_entity *ent);
void event_link(std::ostream & s, const event_context & context, df::historical_figure *hf);
void event_link(std::ostream & s, const event_context & context, df::world_region *region);
void event_link(std::ostream & s, const event_context & context, df::world_site *site);
void event_link(std::ostream & s, const event_context & context, df::world_underground_region *layer);

template<typename T>
inline void list(std::ostream & s, const std::vector<T> & vec, std::function<void(std::ostream &, T)> f)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (it + 1 == vec.end())
        {
            if (vec.size() == 2)
            {
                s << " and ";
            }
            else if (vec.size() > 2)
            {
                s << ", and ";
            }
        }
        else if (it != vec.begin())
        {
            s << ", ";
        }
        f(s, *it);
    }
}

void simple_header(std::ostream & s, const df::language_name *name, bool sub = false);

int32_t day(int32_t tick);
std::string dayth(int32_t tick);
const std::string & month(int32_t tick);

void history(std::ostream & s, const event_context & context);
void event(std::ostream & s, const event_context & context, df::history_event *event, int32_t & last_year, int32_t & last_seconds);
