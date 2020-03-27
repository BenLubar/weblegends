#include "helpers_event.h"
#include "events.h"

REQUIRE_GLOBAL(gamemode);
REQUIRE_GLOBAL(ui);
REQUIRE_GLOBAL(world);

std::string profession_name(int32_t race, int16_t caste, df::profession prof, bool plural)
{
    std::string str;
    if (*gamemode == df::game_mode::ADVENTURE)
    {
        int32_t old_race_id = world->units.active[0]->race;
        world->units.active[0]->race = race;
        str = Units::getCasteProfessionName(race, caste, prof, plural);
        world->units.active[0]->race = old_race_id;
    }
    else
    {
        int16_t old_race_id = ui->race_id;
        ui->race_id = race;
        str = Units::getCasteProfessionName(race, caste, prof, plural);
        ui->race_id = old_race_id;
    }
    return toLower(str);
}

std::string profession_name(df::historical_figure *hf, df::profession prof, bool plural)
{
    return profession_name(hf->race, hf->caste, prof, plural);
}

void do_item_description(std::ostream & s, const event_context & context, df::item *item)
{
    if (auto is_artifact = Items::getGeneralRef(item, general_ref_type::IS_ARTIFACT))
    {
        if (auto artifact = is_artifact->getArtifact())
        {
            event_link(s, context, artifact);
            return;
        }
    }

    std::string str;
    item->getItemDescriptionPrefix(&str, 0);
    s << str;
    str.clear();
    item->getItemDescription(&str, 0);
    if (auto corpse = virtual_cast<df::item_body_component>(item))
    {
        if (auto hf = df::historical_figure::find(corpse->hist_figure_id))
        {
            std::string name = Translation::capitalize(Translation::TranslateName(&hf->name, false), true);
            size_t start = 0;
            size_t pos;
            while ((pos = str.find(name, start)) != std::string::npos)
            {
                s << str.substr(start, pos - start);
                link(s, hf);
                start = pos + name.length();
            }
            s << str.substr(start);
            return;
        }
    }
    s << str;
}

bool do_weapon(std::ostream & s, const event_context & context, const df::history_hit_item & weapon, const std::string & prefix)
{
    bool any = false;

    if (auto item = df::item::find(weapon.item))
    {
        s << prefix;
        do_item_description(s, context, item);
        any = true;
    }
    else if (weapon.item_type != item_type::NONE)
    {
        ItemTypeInfo type(weapon.item_type, weapon.item_subtype);
        MaterialInfo mat(weapon.mattype, weapon.matindex);
        s << prefix << "a ";
        material(s, context, mat);
        s << " " << type.toString();
        any = true;
    }

    if (auto item = df::item::find(weapon.shooter_item))
    {
        if (!any)
        {
            s << prefix << "a projectile";
            any = true;
        }
        s << " fired from ";
        do_item_description(s, context, item);
    }
    else if (weapon.shooter_item_type != item_type::NONE)
    {
        if (!any)
        {
            s << prefix << "a projectile";
            any = true;
        }
        ItemTypeInfo type(weapon.shooter_item_type, weapon.shooter_item_subtype);
        MaterialInfo mat(weapon.shooter_mattype, weapon.shooter_matindex);
        s << " fired from a ";
        material(s, context, mat);
        s << " " << type.toString();
    }

    return any;
}

void do_identity(std::ostream & s, const event_context &, df::historical_figure *, df::identity *)
{
    // TODO: reimplement this; too much has changed for converting the previous implementation to be worth it
    s << "[TODO: identity]";
}

void do_circumstance_reason(std::ostream & s, const event_context & context, df::history_event *event, df::history_event_circumstance_info & circumstance, df::history_event_reason_info & reason)
{
    BEFORE_SWITCH(reason_type, reason.type);
    switch (reason_type)
    {
    case history_event_reason::none:
        BREAK(reason_type);
    case history_event_reason::glorify_hf:
        s << " in order to glorify ";
        event_link(s, context, df::historical_figure::find(reason.data.glorify_hf));
        BREAK(reason_type);
    case history_event_reason::artifact_is_heirloom_of_family_hfid:
        s << " of the ";
        event_link(s, context, df::historical_figure::find(reason.data.artifact_is_heirloom_of_family_hfid));
        s << " family";
        BREAK(reason_type);
    case history_event_reason::as_a_symbol_of_everlasting_peace:
        s << " as a symbol of everlasting peace";
        BREAK(reason_type);
    case history_event_reason::artifact_is_symbol_of_entity_position:
        s << " as a symbol of authority witin ";
        event_link(s, context, df::historical_entity::find(reason.data.artifact_is_symbol_of_entity_position));
        BREAK(reason_type);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(reason_type, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));

    BEFORE_SWITCH(circumstance_type, circumstance.type);
    switch (circumstance_type)
    {
    case unit_thought_type::None:
        BREAK(circumstance_type);
    case unit_thought_type::Death:
        s << " after the death of ";
        event_link(s, context, df::historical_figure::find(circumstance.data.Death));
        BREAK(circumstance_type);
    case unit_thought_type::Prayer:
        s << " after praying to ";
        event_link(s, context, df::historical_figure::find(circumstance.data.Prayer));
        BREAK(circumstance_type);
    case unit_thought_type::DreamAbout:
        s << " after dreaming about ";
        event_link(s, context, df::historical_figure::find(circumstance.data.DreamAbout));
        BREAK(circumstance_type);
    case unit_thought_type::Dream:
        s << " after a dream";
        BREAK(circumstance_type);
    case unit_thought_type::Nightmare:
        s << " after a nightmare";
        BREAK(circumstance_type);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(circumstance_type, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));
}

#define EVENT_TYPE(upper, lower) \
    void do_event(std::ostream &, const event_context &, df::history_event_ ## lower ## st *);
EVENT_TYPES
#undef EVENT_TYPE

static void event_dispatch(std::ostream & s, const event_context & context, df::history_event *event)
{
    if (event->seconds != -1)
    {
        int32_t month = (event->seconds / 28 / 1200) + 1;
        int32_t day = ((event->seconds / 1200) % 28) + 1;
        int32_t hour = (event->seconds % 1200) / 50;
        int32_t minute = (event->seconds % 50) * 60 / 50;
        s << "<!--" << event->id << ", " << stl_sprintf("%04d-%02d-%02dT%02d:%02d", event->year, month, day, hour, minute) << "-->";
    }
    else
    {
        s << "<!--" << event->id << ", year " << event->year << ", time unknown-->";
    }
    BEFORE_SWITCH(type, event->getType());
    switch (type)
    {
#define EVENT_TYPE(upper, lower) \
    case history_event_type::upper: \
        do_event(s, context, static_cast<df::history_event_ ## lower ## st *>(event)); \
        BREAK(type);
EVENT_TYPES
#undef EVENT_TYPE
    }
    if (!type_found)
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d", event->id));
}

void event(std::ostream & s, const event_context & context, df::history_event *event, int32_t & last_year, int32_t & last_seconds)
{
    if (event->year != last_year)
    {
        if (event->year < 0)
        {
            s << "In a time before time, ";
        }
        else
        {
            s << "In " << event->year;
            if (event->seconds < 0)
            {
                s << ", ";
            }
            else
            {
                s << " on " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
            }
        }
    }
    else if ((event->seconds < 0) != (last_seconds < 0) || event->seconds / 1200 != last_seconds / 1200)
    {
        s << "On " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
    }
    last_year = event->year;
    last_seconds = event->seconds;

    event_dispatch(s, context, event);
    s << ". ";
}

void event_reverse(std::ostream & s, const event_context & context, df::history_event *event)
{
    event_dispatch(s, context, event);

    if (event->year < 0)
    {
        s << " in a time before time";
    }
    else
    {
        s << " in " << event->year;
        if (event->seconds >= 0)
        {
            s << " on " << dayth(event->seconds) << " " << month(event->seconds);
        }
    }
}
