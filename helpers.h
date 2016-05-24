#pragma once

#include <functional>

namespace DFHack
{
    struct MaterialInfo;
}

#define WEBLEGENDS_TYPES \
    WEBLEGENDS_TYPE(abstract_building, structure) \
    WEBLEGENDS_TYPE(artifact_record, item) \
    WEBLEGENDS_TYPE(historical_entity, ent) \
    WEBLEGENDS_TYPE(historical_figure, hf) \
    WEBLEGENDS_TYPE(world_region, region) \
    WEBLEGENDS_TYPE(world_site, site) \
    WEBLEGENDS_TYPE(world_underground_region, layer)

namespace df
{
#define WEBLEGENDS_TYPE(type, name) \
    struct type;
    WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE
    struct history_event;
    struct language_name;
    struct written_content;
}

struct event_context
{
#define WEBLEGENDS_TYPE(type, name) \
    df::type *name;
WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE

    event_context() { clear(); }
#define WEBLEGENDS_TYPE(type, name) \
    event_context(df::type *name) { clear(); this->name = name; }
WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE

    bool related(df::history_event *event) const;

private:
    inline void clear()
    {
#define WEBLEGENDS_TYPE(type, name) \
        this->name = nullptr;
WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE
    }
};

#define WEBLEGENDS_TYPE(type, name) \
int32_t get_id(df::type *name); \
const df::language_name & get_name(df::type *name); \
void link(std::ostream & s, df::type *name); \
void event_link(std::ostream & s, const event_context & context, df::type *name); \
void categorize(std::ostream & s, df::type *name, bool in_link = false); \
void simple_header(std::ostream & s, df::type *name);
WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE

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

void material(std::ostream & s, const event_context & context, MaterialInfo mat, bool in_link = false);
void written_content(std::ostream & s, const event_context & context, df::written_content *content);

int32_t day(int32_t tick);
std::string dayth(int32_t tick);
const std::string & month(int32_t tick);

void history(std::ostream & s, const event_context & context);
void event(std::ostream & s, const event_context & context, df::history_event *event, int32_t & last_year, int32_t & last_seconds);

#undef WEBLEGENDS_TYPES
