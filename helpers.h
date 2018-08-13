#pragma once

#include <functional>

#include "df/value_type.h"

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
    WEBLEGENDS_TYPE(world_underground_region, layer) \
    WEBLEGENDS_TYPE(history_era, era)

namespace df
{
#define WEBLEGENDS_TYPE(type, name) \
    struct type;
    WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE
    struct coord2d_path;
    struct creature_raw;
    struct entity_occasion_schedule_feature;
    struct history_event;
    struct item;
    struct knowledge_scholar_category_flag;
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

void name_translated(std::ostream & s, const df::language_name & name, bool only_last = false);

template<typename ...>
struct void_t
{
    typedef void type;
};

#define WEBLEGENDS_TYPE(type, name) \
int32_t get_id(df::type *name); \
const df::language_name & get_name(df::type *name); \
void link(std::ostream & s, df::type *name); \
void event_link(std::ostream & s, const event_context & context, df::type *name); \
void categorize(std::ostream & s, df::type *name, bool in_link = false, bool in_attr = false); \
void add_styles_and_scripts(std::ostream & s); \
void simple_header(std::ostream & s, df::type *name);
WEBLEGENDS_TYPES
#undef WEBLEGENDS_TYPE

df::artifact_record *get_artifact(df::item *item);

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

template<typename T, typename I = typename T::key_field_type>
inline void list_event_link(std::ostream & s, const event_context & context, const std::vector<I> & vec)
{
    list<I>(s, vec, [context](std::ostream & out, I id)
    {
        event_link(out, context, T::find(id));
    });
}

void material(std::ostream & s, const event_context & context, MaterialInfo mat, bool in_link = false, bool in_attr = false);
bool unique_creature_name(std::ostream & s, const event_context & context, df::creature_raw *creature, bool in_link = false, bool in_attr = false);
void knowledge(std::ostream & s, df::knowledge_scholar_category_flag knowledge);
void value_level(std::ostream & s, df::value_type type, int32_t level);
void written_content(std::ostream & s, const event_context & context, df::written_content *content, df::historical_figure *omit_author = nullptr, bool show_refs = false);
void schedule_feature(std::ostream & s, const event_context & context, df::entity_occasion_schedule_feature *feature, df::history_event *event);

void age_years_days(int32_t year, int32_t tick, int32_t year_compare, int32_t tick_compare, int32_t & years, int32_t & days);
int32_t day(int32_t tick);
std::string dayth(int32_t tick);
const std::string & month(int32_t tick);

bool history(std::ostream & s, const event_context & context, int32_t page, int32_t & last_page);
void event(std::ostream & s, const event_context & context, df::history_event *event, int32_t & last_year, int32_t & last_seconds);
void event_reverse(std::ostream & s, const event_context & context, df::history_event *event);
void pagination(std::ostream & s, const std::string & base, const std::string & page_0, const std::string & page_prefix, int32_t current_page, int32_t last_page);

void spheres(std::ostream & s, df::historical_figure *hf);
void year(std::ostream & s, int32_t year, int32_t tick);
void born_died(std::ostream & s, df::historical_figure *hf);

void render_map_coords(std::ostream &s, const df::coord2d_path &coords, int32_t mul = 1);

// https://stackoverflow.com/a/24315631/2664560
static inline void replace_all(std::string & str, const std::string & from, const std::string & to)
{
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos)
    {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}

static inline std::string html_escape(const std::string & str)
{
    std::string escaped(str);
    replace_all(escaped, "&", "&amp;");
    replace_all(escaped, "\"", "&quot;");
    replace_all(escaped, "<", "&lt;");
    replace_all(escaped, ">", "&gt;");
    replace_all(escaped, "\n", "<br/>");
    return escaped;
}

#undef WEBLEGENDS_TYPES
