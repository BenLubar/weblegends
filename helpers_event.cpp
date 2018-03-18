#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"
#include "modules/Translation.h"
#include "modules/Units.h"

#include "df/abstract_building.h"
#include "df/agreement.h"
#include "df/art_image.h"
#include "df/art_image_chunk.h"
#include "df/artifact_record.h"
#include "df/caste_raw.h"
#include "df/creature_raw.h"
#include "df/dance_form.h"
#include "df/entity_occasion.h"
#include "df/entity_occasion_info.h"
#include "df/entity_occasion_schedule.h"
#include "df/entity_occasion_schedule_feature.h"
#include "df/entity_position.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/history_event_add_hf_entity_linkst.h"
#include "df/history_event_add_hf_hf_linkst.h"
#include "df/history_event_add_hf_site_linkst.h"
#include "df/history_event_agreement_concludedst.h"
#include "df/history_event_agreement_formedst.h"
#include "df/history_event_agreements_voidedst.h"
#include "df/history_event_artifact_claim_formedst.h"
#include "df/history_event_artifact_copiedst.h"
#include "df/history_event_artifact_createdst.h"
#include "df/history_event_artifact_destroyedst.h"
#include "df/history_event_artifact_droppedst.h"
#include "df/history_event_artifact_foundst.h"
#include "df/history_event_artifact_givenst.h"
#include "df/history_event_artifact_hiddenst.h"
#include "df/history_event_artifact_lostst.h"
#include "df/history_event_artifact_possessedst.h"
#include "df/history_event_artifact_recoveredst.h"
#include "df/history_event_artifact_storedst.h"
#include "df/history_event_artifact_transformedst.h"
#include "df/history_event_assume_identityst.h"
#include "df/history_event_body_abusedst.h"
#include "df/history_event_ceremonyst.h"
#include "df/history_event_change_creature_typest.h"
#include "df/history_event_change_hf_body_statest.h"
#include "df/history_event_change_hf_jobst.h"
#include "df/history_event_change_hf_moodst.h"
#include "df/history_event_change_hf_statest.h"
#include "df/history_event_competitionst.h"
#include "df/history_event_context.h"
#include "df/history_event_create_entity_positionst.h"
#include "df/history_event_created_buildingst.h"
#include "df/history_event_created_sitest.h"
#include "df/history_event_created_world_constructionst.h"
#include "df/history_event_creature_devouredst.h"
#include "df/history_event_dance_form_createdst.h"
#include "df/history_event_diplomat_lostst.h"
#include "df/history_event_entity_actionst.h"
#include "df/history_event_entity_createdst.h"
#include "df/history_event_entity_fled_sitest.h"
#include "df/history_event_entity_incorporatedst.h"
#include "df/history_event_entity_lawst.h"
#include "df/history_event_entity_rampaged_in_sitest.h"
#include "df/history_event_entity_razed_buildingst.h"
#include "df/history_event_entity_searched_sitest.h"
#include "df/history_event_first_contact_failedst.h"
#include "df/history_event_first_contactst.h"
#include "df/history_event_hf_act_on_artifactst.h"
#include "df/history_event_hf_act_on_buildingst.h"
#include "df/history_event_hf_attacked_sitest.h"
#include "df/history_event_hf_confrontedst.h"
#include "df/history_event_hf_destroyed_sitest.h"
#include "df/history_event_hf_does_interactionst.h"
#include "df/history_event_hf_freedst.h"
#include "df/history_event_hf_gains_secret_goalst.h"
#include "df/history_event_hf_learns_secretst.h"
#include "df/history_event_hf_razed_buildingst.h"
#include "df/history_event_hf_recruited_unit_type_for_entityst.h"
#include "df/history_event_hf_relationship_deniedst.h"
#include "df/history_event_hfs_formed_reputation_relationshipst.h"
#include "df/history_event_hist_figure_abductedst.h"
#include "df/history_event_hist_figure_diedst.h"
#include "df/history_event_hist_figure_new_petst.h"
#include "df/history_event_hist_figure_reach_summitst.h"
#include "df/history_event_hist_figure_reunionst.h"
#include "df/history_event_hist_figure_revivedst.h"
#include "df/history_event_hist_figure_simple_actionst.h"
#include "df/history_event_hist_figure_simple_battle_eventst.h"
#include "df/history_event_hist_figure_travelst.h"
#include "df/history_event_hist_figure_woundedst.h"
#include "df/history_event_insurrection_endedst.h"
#include "df/history_event_insurrection_startedst.h"
#include "df/history_event_item_stolenst.h"
#include "df/history_event_knowledge_discoveredst.h"
#include "df/history_event_masterpiece_created_arch_constructst.h"
#include "df/history_event_masterpiece_created_arch_designst.h"
#include "df/history_event_masterpiece_created_dye_itemst.h"
#include "df/history_event_masterpiece_created_engravingst.h"
#include "df/history_event_masterpiece_created_foodst.h"
#include "df/history_event_masterpiece_created_item_improvementst.h"
#include "df/history_event_masterpiece_created_itemst.h"
#include "df/history_event_masterpiece_lostst.h"
#include "df/history_event_merchantst.h"
#include "df/history_event_musical_form_createdst.h"
#include "df/history_event_performancest.h"
#include "df/history_event_poetic_form_createdst.h"
#include "df/history_event_processionst.h"
#include "df/history_event_reclaim_sitest.h"
#include "df/history_event_regionpop_incorporated_into_entityst.h"
#include "df/history_event_remove_hf_entity_linkst.h"
#include "df/history_event_remove_hf_hf_linkst.h"
#include "df/history_event_remove_hf_site_linkst.h"
#include "df/history_event_replaced_buildingst.h"
#include "df/history_event_site_diedst.h"
#include "df/history_event_site_disputest.h"
#include "df/history_event_site_retiredst.h"
#include "df/history_event_sneak_into_sitest.h"
#include "df/history_event_spotted_leaving_sitest.h"
#include "df/history_event_squad_vs_squadst.h"
#include "df/history_event_tactical_situationst.h"
#include "df/history_event_topicagreement_concludedst.h"
#include "df/history_event_topicagreement_madest.h"
#include "df/history_event_topicagreement_rejectedst.h"
#include "df/history_event_type.h"
#include "df/history_event_war_attacked_sitest.h"
#include "df/history_event_war_destroyed_sitest.h"
#include "df/history_event_war_field_battlest.h"
#include "df/history_event_war_peace_acceptedst.h"
#include "df/history_event_war_peace_rejectedst.h"
#include "df/history_event_war_plundered_sitest.h"
#include "df/history_event_war_site_new_leaderst.h"
#include "df/history_event_war_site_taken_overst.h"
#include "df/history_event_war_site_tribute_forcedst.h"
#include "df/history_event_written_content_composedst.h"
#include "df/identity.h"
#include "df/interaction.h"
#include "df/interaction_effect.h"
#include "df/interaction_effect_animatest.h"
#include "df/interaction_source.h"
#include "df/item_body_component.h"
#include "df/item_constructed.h"
#include "df/item_fishst.h"
#include "df/item_fish_rawst.h"
#include "df/item_meatst.h"
#include "df/itemdef_weaponst.h"
#include "df/musical_form.h"
#include "df/plant_raw.h"
#include "df/poetic_form.h"
#include "df/sphere_type.h"
#include "df/squad.h"
#include "df/syndrome.h"
#include "df/ui.h"
#include "df/world.h"
#include "df/world_construction.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"
#include "df/written_content.h"

REQUIRE_GLOBAL(gamemode);
REQUIRE_GLOBAL(ui);
REQUIRE_GLOBAL(world);

static std::string profession_name(df::historical_figure *hf, df::profession prof, bool plural = false)
{
    std::string str;
    if (*gamemode == df::game_mode::ADVENTURE)
    {
        int32_t old_race_id = world->units.active[0]->race;
        world->units.active[0]->race = hf->race;
        str = Units::getCasteProfessionName(hf->race, hf->caste, prof, plural);
        world->units.active[0]->race = old_race_id;
    }
    else
    {
        int16_t old_race_id = ui->race_id;
        ui->race_id = hf->race;
        str = Units::getCasteProfessionName(hf->race, hf->caste, prof, plural);
        ui->race_id = old_race_id;
    }
    return toLower(str);
}

template<typename T>
static void do_location_1(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
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
static void do_location_1_structure(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
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
static void do_location_2(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
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
    if (auto loc = df::world_region::find(event->region))
    {
        if (loc != context.region)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }
    // TODO: df::coord2d region_pos;
    if (auto loc = df::world_underground_region::find(event->layer))
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
static void do_location_2_structure(std::ostream & s, const event_context & context, T *event, std::string separator = " in ")
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

static void do_item_description(std::ostream & s, df::item *item)
{
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

template<typename T>
static typename void_t<decltype(T::caste)>::type do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
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

                do_item_description(s, item);

                caste->caste_name[0] = name;

                delete item;

                return;
            }
        }
    }

    do_item_description(s, item);

    delete item;
}

template<typename T, typename D = typename std::remove_pointer<decltype(T::subtype)>::type>
static void do_item_description(std::ostream & s, const event_context & context, int16_t item_subtype, int16_t mat_type, int32_t mat_index)
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

            do_item_description(s, item);

            race->name[0] = name;

            delete item;

            return;
        }
    }

    do_item_description(s, item);

    delete item;
}

template<typename T>
static typename std::enable_if<!std::is_base_of<df::item_constructed, T>::value, typename void_t<decltype(T::mat_type)>::type>::type do_item_description(std::ostream & s, const event_context & context, int16_t, int16_t mat_type, int32_t mat_index)
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

            do_item_description(s, item);

            race->name[0] = name;

            delete item;

            return;
        }
    }

    do_item_description(s, item);

    delete item;
}

static bool do_weapon(std::ostream & s, const event_context & context, const df::history_hit_item & weapon, const std::string & prefix = " with ")
{
    bool any = false;

    if (auto item = df::item::find(weapon.item))
    {
        s << prefix;
        do_item_description(s, item);
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
        do_item_description(s, item);
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

static void do_identity(std::ostream & s, const event_context & context, df::identity *identity)
{
    if (!identity)
    {
        s << "[unknown identity]";
    }
    else if (auto hf = df::historical_figure::find(identity->histfig_id))
    {
        event_link(s, context, hf);
    }
    else
    {
        name_translated(s, identity->name);
        auto race = df::creature_raw::find(identity->race);
        auto caste = race ? vector_get(race->caste, identity->caste) : nullptr;
        if (caste)
        {
            s << ", a ";
            if (caste->caste_name[0] == race->name[0])
            {
                BEFORE_SWITCH(gender, caste->gender);
                switch (gender)
                {
                case -1:
                    BREAK(gender);
                case 0:
                    s << "female ";
                    BREAK(gender);
                case 1:
                    s << "male ";
                    BREAK(gender);
                }
                AFTER_SWITCH(gender, stl_sprintf("identity-%d", identity->id));
            }

            s << caste->caste_name[0];
        }
        else if (race)
        {
            s << ", a " << race->name[0];
        }

        if (identity->profession != profession::NONE)
        {
            if (caste && !caste->caste_profession_name.singular[identity->profession].empty())
            {
                s << " " << caste->caste_profession_name.singular[identity->profession];
            }
            else if (race && !race->profession_name.singular[identity->profession].empty())
            {
                s << " " << race->profession_name.singular[identity->profession];
            }
            else
            {
                s << " " << ENUM_ATTR(profession, caption, identity->profession);
            }
        }
    }
}

template<typename T>
static void do_circumstance_reason(std::ostream & s, const event_context & context, T *event)
{
    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case history_event_reason::none:
        BREAK(reason);
    case history_event_reason::glorify_hf:
        s << " in order to glorify ";
        event_link(s, context, df::historical_figure::find(event->reason_id));
        BREAK(reason);
    case history_event_reason::artifact_is_heirloom_of_family_hfid:
        s << " of the ";
        event_link(s, context, df::historical_figure::find(event->reason_id));
        s << " family";
        BREAK(reason);
    case history_event_reason::artifact_is_symbol_of_entity_position:
        s << " as a symbol of authority witin ";
        event_link(s, context, df::historical_entity::find(event->reason_id));
        BREAK(reason);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));

    BEFORE_SWITCH(circumstance, event->circumstance);
    switch (circumstance)
    {
    case unit_thought_type::None:
        BREAK(circumstance);
    case unit_thought_type::Death:
        s << " after the death of ";
        event_link(s, context, df::historical_figure::find(event->circumstance_id));
        BREAK(circumstance);
    case unit_thought_type::Prayer:
        s << " after praying to ";
        event_link(s, context, df::historical_figure::find(event->circumstance_id));
        BREAK(circumstance);
    case unit_thought_type::DreamAbout:
        s << " after dreaming about ";
        event_link(s, context, df::historical_figure::find(event->circumstance_id));
        BREAK(circumstance);
    case unit_thought_type::Dream:
        s << " after a dream";
        BREAK(circumstance);
    case unit_thought_type::Nightmare:
        s << " after a nightmare";
        BREAK(circumstance);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(circumstance, stl_sprintf("event-%d (%s)", event->id, enum_item_key_str(event->getType())));
}

static void do_event_missing(std::ostream & s, const event_context &, df::history_event *event, int line)
{
    std::string df_description;
    df::history_event_context df_context;
    df_context.anon_1 = -1;
    df_context.anon_2 = -1;
    df_context.histfig_id_talker = -1;
    df_context.histfig_id_listener = -1;
    event->getSentence(&df_description, &df_context, 1, 0);
    s << "<abbr title=\"" << html_escape(df_description) << "\">" << ENUM_KEY_STR(history_event_type, event->getType()) << ":" << event->id << "</abbr>";
#ifdef WEBLEGENDS_DEBUG
    weblegends_debug_log() << "[weblegends] [helpers_event.cpp:" << line << "] missing event type handler for " << ENUM_KEY_STR(history_event_type, event->getType()) << ": event-" << event->id << std::endl;
#endif
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_attacked_sitest *event)
{
    auto attacker = df::historical_entity::find(event->attacker_civ);
    event_link(s, context, attacker);
    s << " attacked ";
    auto site_civ = df::historical_entity::find(event->site_civ);
    event_link(s, context, site_civ);
    s << " of ";
    auto defender = df::historical_entity::find(event->defender_civ);
    event_link(s, context, defender);
    s << " in ";
    auto site = df::world_site::find(event->site);
    event_link(s, context, site);
    if (auto attacker_general = df::historical_figure::find(event->attacker_general_hf))
    {
        s << ". The attackers were led by ";
        event_link(s, context, attacker_general);
        if (auto defender_general = df::historical_figure::find(event->defender_general_hf))
        {
            s << ", and the defenders were led by ";
            event_link(s, context, defender_general);
        }
    }
    else if (auto defender_general = df::historical_figure::find(event->defender_general_hf))
    {
        s << ". The defenders were led by ";
        event_link(s, context, defender_general);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_destroyed_sitest *event)
{
    // TODO: int32_t attacker_civ;
    // TODO: int32_t defender_civ;
    // TODO: int32_t site_civ;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_created_sitest *event)
{
    auto site = df::world_site::find(event->site);

    if (auto builder = df::historical_figure::find(event->builder_hf))
    {
        event_link(s, context, builder);
        s << " founded ";
        event_link(s, context, site);
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " in the name of ";
            event_link(s, context, civ);
        }
    }
    else if (auto civ = df::historical_entity::find(event->civ))
    {
        event_link(s, context, civ);
        s << " founded ";
        event_link(s, context, site);
    }
    else
    {
        event_link(s, context, site);
        s << " was founded";
    }

    if (auto site_civ = df::historical_entity::find(event->site_civ))
    {
        s << ". The new government was named ";
        event_link(s, context, site_civ);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_diedst *event)
{
    std::string weapon_prefix = " with ";
    std::string prefix;
    std::string no_weapon_text;
    std::string no_weapon_prefix;

    auto victim = df::historical_figure::find(event->victim_hf);
    event_link(s, context, victim);

    BEFORE_SWITCH(cause, event->death_cause);
    switch (cause)
    {
    case death_type::NONE:
#ifdef WEBLEGENDS_DEBUG
        weblegends_debug_log() << "[weblegends] [helpers_event.cpp:" << __LINE__ << "] history_event_hist_figure_diedst.death_cause is NONE: event-" << event->id << std::endl;
#endif
        s << " died";
        weapon_prefix = ", killed with ";
        no_weapon_prefix = " ";
        prefix = ", killed";
        BREAK(cause);
    case death_type::OLD_AGE:
        s << " died of old age";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::HUNGER:
        s << " starved to death";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::THIRST:
        s << " died of thirst";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::SHOT:
        s << " was shot and killed";
        BREAK(cause);
    case death_type::BLEED:
        s << " bled to death";
        prefix = ", killed";
        BREAK(cause);
    case death_type::DROWN:
        s << " drowned";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SUFFOCATE:
        s << " suffocated";
        weapon_prefix = " after being hit with ";
        prefix = ", strangled";
        BREAK(cause);
    case death_type::STRUCK_DOWN:
        s << " was slain";
        BREAK(cause);
    case death_type::SCUTTLE:
        s << " was scuttled";
        BREAK(cause);
    case death_type::COLLISION:
        s << " died in a collision";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MAGMA:
        s << " was boiled alive in magma";
        prefix = ", pushed";
        BREAK(cause);
    case death_type::MAGMA_MIST:
        s << " got too close to magma";
        prefix = ", killed";
        BREAK(cause);
    case death_type::DRAGONFIRE:
        s << " was burned to a crisp";
        BREAK(cause);
    case death_type::FIRE:
        s << " burned to death";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SCALD:
        s << " was scalded";
        BREAK(cause);
    case death_type::CAVEIN:
        s << " was crushed in a cave-in";
        prefix = " caused";
        BREAK(cause);
    case death_type::DRAWBRIDGE:
        s << " was crushed by a drawbridge";
        prefix = " operated";
        BREAK(cause);
    case death_type::FALLING_ROCKS:
        s << " was crushed by falling rocks";
        prefix = " dropped";
        BREAK(cause);
    case death_type::CHASM:
        s << " fell into a deep chasm";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = ", pushed";
        prefix = " ";
        BREAK(cause);
    case death_type::CAGE:
        s << " died in a cage";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MURDER:
        s << " was murdered";
        BREAK(cause);
    case death_type::TRAP:
        s << " died in a trap";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::VANISH:
        s << " vanished into thin air";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::QUIT:
        s << " gave into starvation";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ABANDON:
        s << " was abandoned";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::HEAT:
        s << " died of heat";
        prefix = ", killed";
        BREAK(cause);
    case death_type::COLD:
        s << " died of cold";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SPIKE:
        s << " died on a spike";
        prefix = ", killed";
        BREAK(cause);
    case death_type::ENCASE_LAVA:
        s << " was encased in cooling lava";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ENCASE_MAGMA:
        s << " was encased in cooling magma";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::ENCASE_ICE:
        s << " was encased in ice";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::BEHEAD:
        s << " was beheaded";
        BREAK(cause);
    case death_type::CRUCIFY:
        s << " was crucified";
        BREAK(cause);
    case death_type::BURY_ALIVE:
        s << " was buried alive";
        BREAK(cause);
    case death_type::DROWN_ALT:
        s << " was drowned";
        BREAK(cause);
    case death_type::BURN_ALIVE:
        s << " was burned alive";
        BREAK(cause);
    case death_type::FEED_TO_BEASTS:
        s << " was fed to beasts";
        BREAK(cause);
    case death_type::HACK_TO_PIECES:
        s << " was hacked to pieces";
        BREAK(cause);
    case death_type::LEAVE_OUT_IN_AIR:
        s << " was left out in the air";
        BREAK(cause);
    case death_type::BOIL:
        s << " boiled";
        prefix = ", killed";
        BREAK(cause);
    case death_type::MELT:
        s << " melted";
        prefix = ", killed";
        BREAK(cause);
    case death_type::CONDENSE:
        s << " condensed";
        prefix = ", killed";
        BREAK(cause);
    case death_type::SOLIDIFY:
        s << " solidified";
        prefix = ", killed";
        BREAK(cause);
    case death_type::INFECTION:
        s << " succumbed to infection";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::MEMORIALIZE:
        s << " was laid to rest";
        BREAK(cause);
    case death_type::SCARE:
        s << " was scared to death";
        BREAK(cause);
    case death_type::DARKNESS:
        s << " died in the dark";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::COLLAPSE:
        s << " collapsed";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::DRAIN_BLOOD:
        s << " was drained of blood";
        BREAK(cause);
    case death_type::SLAUGHTER:
        s << " was slaughtered";
        BREAK(cause);
    case death_type::VEHICLE:
        s << " was killed by ";
        weapon_prefix = "the vehicle ";
        no_weapon_text = "a vehicle";
        prefix = " after being attacked";
        BREAK(cause);
    case death_type::FALLING_OBJECT:
        s << " was killed by a falling ";
        weapon_prefix = "";
        no_weapon_text = "object";
        prefix = " after being attacked";
        BREAK(cause);
    case death_type::LEAPT_FROM_HEIGHT:
        s << " fell off a cliff";
        weapon_prefix = " after being attacked with ";
        no_weapon_prefix = " after being attacked";
        prefix = " ";
        BREAK(cause);
    case death_type::DROWN_ALT2:
        s << " drowned";
        prefix = ", killed";
        BREAK(cause);
    }
    AFTER_SWITCH(cause, stl_sprintf("event-%d (HIST_FIGURE_DIED)", event->id));
    if (!do_weapon(s, context, event->weapon, weapon_prefix))
    {
        s << no_weapon_text;
        if (!no_weapon_prefix.empty())
        {
            prefix = no_weapon_prefix;
        }
    }
    if (auto slayer = df::historical_figure::find(event->slayer_hf))
    {
        s << prefix << " by ";
        event_link(s, context, slayer);
    }
    else if (auto race = df::creature_raw::find(event->slayer_race))
    {
        auto caste = race->caste.at(event->slayer_caste);
        s << prefix << " by a " << caste->caste_name[0];
    }
    if (victim->born_year > -1)
    {
        int32_t years, days;
        age_years_days(victim->born_year, victim->born_seconds, event->year, event->seconds, years, days);
        if (years != 0)
        {
            s << " at the age of " << years;
            if (days >= 28 * 9)
            {
                s << "&frac34;";
            }
            else if (days >= 28 * 6)
            {
                s << "&frac12;";
            }
            else if (days >= 28 * 3)
            {
                s << "&frac14;";
            }
        }
        else
        {
            s << " at only " << days << " days old";
        }
    }
    do_location_1(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_entity_linkst *event)
{
    auto ent = df::historical_entity::find(event->civ);
    auto hf = df::historical_figure::find(event->histfig);
    df::entity_position *pos;
    BEFORE_SWITCH(type, event->link_type);
    switch (type)
    {
    case histfig_entity_link_type::MEMBER:
        event_link(s, context, hf);
        s << " became a member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MEMBER:
        event_link(s, context, hf);
        s << " became a former member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::MERCENARY:
        event_link(s, context, hf);
        s << " became a mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MERCENARY:
        event_link(s, context, hf);
        s << " became a former mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SLAVE:
        event_link(s, context, hf);
        s << " became a slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SLAVE:
        event_link(s, context, hf);
        s << " became a former slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::PRISONER:
        event_link(s, context, hf);
        s << " became a prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_PRISONER:
        event_link(s, context, hf);
        s << " became a former prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::ENEMY:
        event_link(s, context, hf);
        s << " became an enemy of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::CRIMINAL:
        event_link(s, context, hf);
        s << " became a criminal of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " became ";
        if (pos->number == 1)
        {
            s << "the ";
        }
        else
        {
            s << "a ";
        }
        if (hf->sex == 0 && !pos->name_female[0].empty())
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1 && !pos->name_male[0].empty())
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " became a former ";
        if (hf->sex == 0)
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1)
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION_CLAIM:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " claimed the position of ";
        if (hf->sex == 0)
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1)
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SQUAD:
        event_link(s, context, hf);
        s << " became a squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SQUAD:
        event_link(s, context, hf);
        s << " became a former squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::OCCUPATION:
        event_link(s, context, hf);
        s << " became a worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_OCCUPATION:
        event_link(s, context, hf);
        s << " became a former worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_remove_hf_entity_linkst *event)
{
    auto ent = df::historical_entity::find(event->civ);
    auto hf = df::historical_figure::find(event->histfig);
    df::entity_position *pos;
    BEFORE_SWITCH(type, event->link_type);
    switch (type)
    {
    case histfig_entity_link_type::MEMBER:
        event_link(s, context, hf);
        s << " ceased to be a member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MEMBER:
        event_link(s, context, hf);
        s << " ceased to be a former member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::MERCENARY:
        event_link(s, context, hf);
        s << " ceased to be a mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_MERCENARY:
        event_link(s, context, hf);
        s << " ceased to be a former mercenary of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SLAVE:
        event_link(s, context, hf);
        s << " ceased to be a slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SLAVE:
        event_link(s, context, hf);
        s << " ceased to be a former slave of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::PRISONER:
        event_link(s, context, hf);
        s << " ceased to be a prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_PRISONER:
        event_link(s, context, hf);
        s << " ceased to be a former prisoner of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::ENEMY:
        event_link(s, context, hf);
        s << " ceased to be an enemy of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::CRIMINAL:
        event_link(s, context, hf);
        s << " ceased to be a criminal of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " ceased to be ";
        if (pos->number == 1)
        {
            s << "the ";
        }
        else
        {
            s << "a ";
        }
        if (hf->sex == 0 && !pos->name_female[0].empty())
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1 && !pos->name_male[0].empty())
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_POSITION:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " ceased to be a former ";
        if (hf->sex == 0)
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1)
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::POSITION_CLAIM:
        pos = binsearch_in_vector(ent->positions.own, event->position_id);
        event_link(s, context, hf);
        s << " relinquished ";
        if (hf->sex == 0)
        {
            s << "her";
        }
        else if (hf->sex == 1)
        {
            s << "his";
        }
        else
        {
            s << "its";
        }
        s << " claim of the position of ";
        if (hf->sex == 0)
        {
            s << pos->name_female[0];
        }
        else if (hf->sex == 1)
        {
            s << pos->name_male[0];
        }
        else
        {
            s << pos->name[0];
        }
        s << " of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::SQUAD:
        event_link(s, context, hf);
        s << " ceased to be a squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_SQUAD:
        event_link(s, context, hf);
        s << " ceased to be a former squad member of ";
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::OCCUPATION:
        event_link(s, context, hf);
        s << " ceased to be a worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    case histfig_entity_link_type::FORMER_OCCUPATION:
        event_link(s, context, hf);
        s << " ceased to be a former worker of ";
        // TODO: get occupation type
        event_link(s, context, ent);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_first_contactst *event)
{
    // TODO: int32_t contactor;
    // TODO: int32_t contacted;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_first_contact_failedst *event)
{
    // TODO: int32_t contactor;
    // TODO: int32_t rejector;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_topicagreement_concludedst *event)
{
    // TODO: int32_t source;
    // TODO: int32_t destination;
    // TODO: int32_t site;
    // TODO: df::meeting_topic topic;
    // TODO: int32_t result; /*!< range from -3 to +2 */
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_topicagreement_rejectedst *event)
{
    auto source = df::historical_entity::find(event->source);
    auto destination = df::historical_entity::find(event->destination);
    auto site = df::world_site::find(event->site);

    BEFORE_SWITCH(topic, event->topic);
    switch (topic)
    {
    case meeting_topic::RequestPeace:
        s << "A peace agreement";
        BREAK(topic);
    case meeting_topic::TreeQuota:
        s << "A lumber agreement";
        BREAK(topic);
    case meeting_topic::BecomeLandHolder:
        s << "The establishment of landed nobility";
        BREAK(topic);
    case meeting_topic::PromoteLandHolder:
        s << "The elevation of the landed nobility";
        BREAK(topic);
    case meeting_topic::ExportAgreement:
    case meeting_topic::ImportAgreement:
        s << "A trade agreement";
        BREAK(topic);
    case meeting_topic::TributeAgreement:
        s << "A tribute agreement";
        BREAK(topic);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(topic, stl_sprintf("event-%d (TOPICAGREEMENT_REJECTED)", event->id));

    s << " proposed by ";
    event_link(s, context, source);
    s << " was rejected by ";
    event_link(s, context, destination);
    s << " at ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_topicagreement_madest *event)
{
    // TODO: df::meeting_topic topic;
    // TODO: int32_t source;
    // TODO: int32_t destination;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_peace_acceptedst *event)
{
    auto destination = df::historical_entity::find(event->destination);
    event_link(s, context, destination);
    s << " accepted a peace treaty from ";
    auto source = df::historical_entity::find(event->source);
    event_link(s, context, source);
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
    // TODO: df::meeting_topic topic;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_peace_rejectedst *event)
{
    auto destination = df::historical_entity::find(event->destination);
    event_link(s, context, destination);
    s << " rejected a peace treaty from ";
    auto source = df::historical_entity::find(event->source);
    event_link(s, context, source);
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
    // TODO: df::meeting_topic topic;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_diplomat_lostst *event)
{
    // TODO: int32_t entity;
    // TODO: int32_t involved;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_agreements_voidedst *event)
{
    // TODO: int32_t source;
    // TODO: int32_t destination;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_merchantst *event)
{
    auto source = df::historical_entity::find(event->source);
    auto destination = df::historical_entity::find(event->destination);
    auto site = df::world_site::find(event->site);

    s << "Merchants from ";
    event_link(s, context, source);
    s << " visited ";
    event_link(s, context, destination);
    s << " in ";
    event_link(s, context, site);

    // TODO: BitArray<int> flags2;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_hiddenst *event)
{
    // TODO: int32_t artifact;
    // TODO: int32_t unit;
    // TODO: int32_t histfig;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_possessedst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto site = df::world_site::find(event->site);

    event_link(s, context, histfig);
    s << " took ";
    event_link(s, context, artifact);
    s << " from ";
    event_link(s, context, site);

    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_createdst *event)
{
    auto item = df::artifact_record::find(event->artifact_id);
    if (auto hf = df::historical_figure::find(event->hfid))
    {
        event_link(s, context, hf);
        if ((event->flags2 & 1) == 1)
        {
            s << " bestowed a name upon ";
        }
        else
        {
            s << " created ";
        }
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        if ((event->flags2 & 1) == 1)
        {
            s << " was given a name";
        }
        else
        {
            s << " was created";
        }
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_lostst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    event_link(s, context, item);
    s << " was lost";
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_foundst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
        s << " found ";
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        s << " was found";
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_recoveredst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, artifact);
    s << " was recovered by ";
    event_link(s, context, histfig);

    do_location_2_structure(s, context, event, " from ");
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_droppedst *event)
{
    // TODO: int32_t artifact;
    // TODO: int32_t unit;
    // TODO: int32_t histfig;
    // TODO: int32_t site;
    // TODO: BitArray<int> flags2;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_reclaim_sitest *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, site_civ);
    s << " of ";
    event_link(s, context, civ);
    if ((event->flags & 1) == 1)
    {
        s << " were taken by a mood to act against their better judgment at ";
    }
    else
    {
        s << " launched an expedition to reclaim ";
    }
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_destroyed_sitest *event)
{
    auto hf = df::historical_figure::find(event->attacker_hf);
    event_link(s, context, hf);
    s << " routed ";
    auto ent = df::historical_entity::find(event->site_civ);
    event_link(s, context, ent);
    if (auto civ = df::historical_entity::find(event->defender_civ))
    {
        s << " of ";
        event_link(s, context, civ);
    }
    auto site = df::world_site::find(event->site);
    s << " and destroyed ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_site_diedst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    if ((event->flags & 1) == 0)
    {
        s << "The ";
    }

    event_link(s, context, site_civ);

    if ((event->flags & 1) == 1)
    {
        s << " abandoned the";
    }
    else
    {
        s << " and ";
        event_link(s, context, civ);
    }

    s << " settlement of ";
    event_link(s, context, site);

    if ((event->flags & 1) == 0)
    {
        s << " withered";
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_site_retiredst *event)
{
    // TODO: int32_t civ;
    // TODO: int32_t site_civ;
    // TODO: int32_t site;
    // TODO: int32_t flags; /*!< 1: first time */
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_createdst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, entity);
    s << " was formed in ";
    if (structure)
    {
        event_link(s, context, structure);
        s << " in ";
    }
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_actionst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, entity);
    BEFORE_SWITCH(action, event->action);
    switch (action)
    {
    case entity_action_type::entity_primary_criminals:
        s << " became the primary criminal organization in ";
        BREAK(action);
    case entity_action_type::entity_relocate:
        s << " moved to ";
        BREAK(action);
    }
    AFTER_SWITCH(action, stl_sprintf("event-%d (ENTITY_ACTION)", event->id));

    if (structure)
    {
        event_link(s, context, structure);
        s << " in ";
    }
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_incorporatedst *event)
{
    // TODO: int32_t migrant_entity;
    // TODO: int32_t join_entity;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_created_buildingst *event)
{
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    if (structure->getType() == abstract_building_type::UNDERWORLD_SPIRE)
    {
        auto builder = df::historical_figure::find(event->builder_hf);
        event_link(s, context, builder);
        s << " thrust a spire of slade up from the underworld, naming it ";
        event_link(s, context, structure);
        s << ", and established a gateway between worlds in ";
        event_link(s, context, site);
        return;
    }

    if (auto builder = df::historical_figure::find(event->builder_hf))
    {
        event_link(s, context, builder);
        s << " built ";
        event_link(s, context, structure);
        if (auto site_civ = df::historical_entity::find(event->site_civ))
        {
            s << " for ";
            event_link(s, context, site_civ);
            if (auto civ = df::historical_entity::find(event->civ))
            {
                s << " of ";
                event_link(s, context, civ);
            }
        }
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " for ";
            event_link(s, context, civ);
        }
    }
    else if (auto site_civ = df::historical_entity::find(event->site_civ))
    {
        event_link(s, context, site_civ);
        if (auto civ = df::historical_entity::find(event->civ))
        {
            s << " of ";
            event_link(s, context, civ);
        }
        s << " built ";
        event_link(s, context, structure);
    }
    else if (auto civ = df::historical_entity::find(event->civ))
    {
        event_link(s, context, civ);
        s << " built ";
        event_link(s, context, structure);
    }
    else
    {
        event_link(s, context, structure);
        s << " was built";
    }
    if (site)
    {
        s << " at ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_replaced_buildingst *event)
{
    // TODO: int32_t civ;
    // TODO: int32_t site_civ;
    // TODO: int32_t site;
    // TODO: int32_t old_structure;
    // TODO: int32_t new_structure;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_site_linkst *event)
{
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;
    auto histfig = df::historical_figure::find(event->histfig);
    auto civ = df::historical_entity::find(event->civ);

    event_link(s, context, histfig);
    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_site_link_type::OCCUPATION:
        s << " started working at ";
        BREAK(type);
    case histfig_site_link_type::SEAT_OF_POWER:
        s << " ruled from ";
        BREAK(type);
    case histfig_site_link_type::HANGOUT:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_ABSTRACT_BUILDING:
        s << " took up residence in ";
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_BUILDING:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::LAIR:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_SUL:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_SAVED_CIVZONE:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_SITE_LINK)", event->id));
    event_link(s, context, structure);
    if (civ)
    {
        s << " of ";
        event_link(s, context, civ);
    }
    if (civ)
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_remove_hf_site_linkst *event)
{
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;
    auto histfig = df::historical_figure::find(event->histfig);
    auto civ = df::historical_entity::find(event->civ);

    event_link(s, context, histfig);
    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_site_link_type::OCCUPATION:
        s << " stopped working at ";
        BREAK(type);
    case histfig_site_link_type::SEAT_OF_POWER:
        s << " stopped ruling from ";
        BREAK(type);
    case histfig_site_link_type::HANGOUT:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_ABSTRACT_BUILDING:
        s << " moved out of ";
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_BUILDING:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::LAIR:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_REALIZATION_SUL:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    case histfig_site_link_type::HOME_SITE_SAVED_CIVZONE:
        do_event_missing(s, context, event, __LINE__);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (REMOVE_HF_SITE_LINK)", event->id));
    event_link(s, context, structure);
    if (civ)
    {
        s << " of ";
        event_link(s, context, civ);
    }
    if (civ)
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_hf_linkst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    auto hf_target = df::historical_figure::find(event->hf_target);
    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_hf_link_type::MOTHER:
        event_link(s, context, hf);
        s << " was born to ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FATHER:
        event_link(s, context, hf);
        s << " was fathered by ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::SPOUSE:
        event_link(s, context, hf);
        s << " married ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::CHILD:
        event_link(s, context, hf);
        if (hf->sex == 1)
        {
            s << " fathered ";
        }
        else
        {
            s << " gave birth to ";
        }
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::DEITY:
        event_link(s, context, hf);
        s << " began worshipping ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::LOVER:
        event_link(s, context, hf);
        s << " fell in love with ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::PRISONER:
        event_link(s, context, hf);
        s << " imprisoned ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::IMPRISONER:
        event_link(s, context, hf);
        s << " was imprisoned by ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::MASTER:
        event_link(s, context, hf);
        s << " started an apprenticeship under ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::APPRENTICE:
        event_link(s, context, hf);
        s << " accepted ";
        event_link(s, context, hf_target);
        s << " as an apprentice";
        BREAK(type);
    case histfig_hf_link_type::COMPANION:
        event_link(s, context, hf);
        s << " became the companion of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FORMER_MASTER:
        event_link(s, context, hf);
        s << " was no longer the master of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FORMER_APPRENTICE:
        event_link(s, context, hf);
        s << " was no longer the apprentice of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::PET_OWNER:
        if (auto race = hf ? df::creature_raw::find(hf->race) : nullptr)
        {
            auto caste = race->caste.at(hf->caste);
            if (caste->flags.is_set(caste_raw_flags::ADOPTS_OWNER))
            {
                std::swap(hf, hf_target);
            }
        }
        event_link(s, context, hf);
        s << " was adopted as the pet of ";
        event_link(s, context, hf_target);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_HF_LINK)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_remove_hf_hf_linkst *event)
{
    // TODO: int32_t hf;
    // TODO: int32_t hf_target;
    // TODO: df::histfig_hf_link_type type;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_razed_buildingst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;

    event_link(s, context, civ);
    s << " razed ";
    event_link(s, context, structure);
    s << " in ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_arch_designst *event)
{
    // TODO: int32_t maker;
    // TODO: int32_t maker_entity;
    // TODO: int32_t site;
    // TODO: int32_t anon_1;
    // TODO: int16_t building_type;
    // TODO: int16_t building_subtype;
    // TODO: int32_t building_custom;
    // TODO: int32_t anon_2;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_arch_constructst *event)
{
    // TODO: int32_t maker;
    // TODO: int32_t maker_entity;
    // TODO: int32_t site;
    // TODO: int32_t anon_1;
    // TODO: int16_t building_type;
    // TODO: int16_t building_subtype;
    // TODO: int32_t building_custom;
    // TODO: int32_t anon_2;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_itemst *event)
{
    if (auto maker = df::historical_figure::find(event->maker))
    {
        event_link(s, context, maker);
    }
    else if (event->skill_used != job_skill::NONE)
    {
        s << "a " << toLower(ENUM_ATTR(job_skill, caption_noun, event->skill_used));
    }
    else
    {
        s << "an unknown person";
    }
    if (auto maker_entity = df::historical_entity::find(event->maker_entity))
    {
        s << " of ";
        event_link(s, context, maker_entity);
    }
    s << " created ";
    if (auto art = get_artifact(df::item::find(event->item_id)))
    {
        event_link(s, context, art);
    }
    else
    {
        s << "a masterwork ";
        if (ENUM_ATTR(item_type, is_caste_mat, event->item_type))
        {
            auto creature = df::creature_raw::find(event->mat_type);
            auto caste = creature->caste.at(event->mat_index);
            if (!unique_creature_name(s, context, creature))
            {
                s << caste->caste_name[0];
            }
        }
        else
        {
            MaterialInfo mat(event->mat_type, event->mat_index);
            material(s, context, mat);
        }
        ItemTypeInfo type(event->item_type, event->item_subtype);
        s << " " << type.toString();
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_dye_itemst *event)
{
    // TODO: int32_t maker;
    // TODO: int32_t maker_entity;
    // TODO: int32_t site;
    // TODO: int32_t anon_1;
    // TODO: df::item_type item_type;
    // TODO: int16_t item_subtype;
    // TODO: int16_t mat_type;
    // TODO: int32_t mat_index;
    // TODO: int32_t anon_2;
    // TODO: int16_t dye_mat_type;
    // TODO: int32_t dye_mat_index;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_item_improvementst *event)
{
    // TODO: int32_t maker;
    // TODO: int32_t maker_entity;
    // TODO: int32_t site;
    // TODO: int32_t anon_1;
    // TODO: df::item_type item_type;
    // TODO: int16_t item_subtype;
    // TODO: int16_t mat_type;
    // TODO: int32_t mat_index;
    // TODO: int32_t anon_2;
    // TODO: enum_field<df::improvement_type, int16_t> improvement_type;
    // TODO: int32_t improvement_subtype;
    // TODO: int16_t imp_mat_type;
    // TODO: int32_t imp_mat_index;
    // TODO: int32_t art_id;
    // TODO: int16_t art_subid;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_foodst *event)
{
    // TODO: int32_t maker;
    // TODO: int32_t maker_entity;
    // TODO: int32_t site;
    // TODO: int32_t unk1;
    // TODO: int16_t item_subtype;
    // TODO: int32_t item_id;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_engravingst *event)
{
    auto maker = df::historical_figure::find(event->maker);
    auto maker_entity = df::historical_entity::find(event->maker_entity);
    auto site = df::world_site::find(event->site);
    auto art_chunk = df::art_image_chunk::find(event->art_id);
    auto art = art_chunk ? art_chunk->images[event->art_subid] : nullptr;

    event_link(s, context, maker);
    s << " created a masterful engraving";
    if (art)
    {
        s << " <em>";
        name_translated(s, art->name);
        s << "</em>";
    }

    if (maker_entity)
    {
        s << " for ";
        event_link(s, context, maker_entity);
    }

    if (site)
    {
        s << " at ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_lostst *event)
{
    // TODO: int32_t creation_event;
    // TODO: int32_t histfig;
    // TODO: int32_t site;
    // TODO: df::masterpiece_loss_type method;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_statest *event)
{
    std::string separator = " in ";
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    BEFORE_SWITCH(state, event->state);
    switch (state)
    {
    case df::history_event_change_hf_statest::T_state::Wandering:
        BEFORE_SWITCH(reason, event->reason);
        switch (reason)
        {
        case history_event_reason::flight:
            s << " fled";
            separator = " to ";
            BREAK(reason);
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wswitch"
        case (df::history_event_reason)-1:
#pragma GCC diagnostic pop
            s << " was wandering";
            BREAK(reason);
        default:
            break;
        }
        AFTER_SWITCH(reason, stl_sprintf("event-%d (CHANGE_HF_STATE) Wandering", event->id));
        BREAK(state);
    case df::history_event_change_hf_statest::T_state::Settled:
        if (hf->born_year == event->year && event->seconds <= hf->born_seconds)
        {
            s << " was born";
        }
        else
        {
            s << " settled";
        }
        BREAK(state);
    case df::history_event_change_hf_statest::T_state::Refugee:
        s << " became a refugee";
        BREAK(state);
    case df::history_event_change_hf_statest::T_state::anon_1:
        break;
    case df::history_event_change_hf_statest::T_state::anon_2:
        break;
    case df::history_event_change_hf_statest::T_state::Visiting:
        s << " visited";
        separator = " ";
        BREAK(state);
    }
    AFTER_SWITCH(state, stl_sprintf("event-%d (CHANGE_HF_STATE)", event->id));
    do_location_2(s, context, event, separator);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_jobst *event)
{
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    if (event->new_job != profession::STANDARD)
    {
        s << " became a " << profession_name(hf, event->new_job);
        do_location_2(s, context, event);
        if (event->old_job != profession::STANDARD)
        {
            s << ", leaving ";
            if (hf->sex == 0)
            {
                s << "her";
            }
            else if (hf->sex == 1)
            {
                s << "his";
            }
            else
            {
                ASSUME_EQUAL(hf->sex, -1, stl_sprintf("hf-%d sex", hf->id));
                s << "its";
            }
            s << " previous job as a " << profession_name(hf, event->old_job);
        }
    }
    else
    {
        s << " left ";
        if (hf->sex == 0)
        {
            s << "her";
        }
        else if (hf->sex == 1)
        {
            s << "his";
        }
        else
        {
            ASSUME_EQUAL(hf->sex, -1, stl_sprintf("hf-%d sex", hf->id));
            s << "its";
        }
        s << " job as a " << profession_name(hf, event->old_job);
        do_location_2(s, context, event);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_field_battlest *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto region = df::world_region::find(event->region);
    auto layer = df::world_underground_region::find(event->layer);
    // TODO: df::coord2d region_pos;
    auto attacker_general_hf = df::historical_figure::find(event->attacker_general_hf);
    auto defender_general_hf = df::historical_figure::find(event->defender_general_hf);

    event_link(s, context, attacker_civ);
    s << " attacked ";
    event_link(s, context, defender_civ);
    if (region)
    {
        s << " in ";
        event_link(s, context, region);
    }
    if (layer)
    {
        s << " in ";
        event_link(s, context, layer);
    }
    s << ". ";
    event_link(s, context, attacker_general_hf);
    s << " led the attack, and the defenders were led by ";
    event_link(s, context, defender_general_hf);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_plundered_sitest *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    s << " defeated ";
    if (defender_civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, defender_civ);
    s << " and pillaged ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_site_new_leaderst *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto new_site_civ = df::historical_entity::find(event->new_site_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    s << " defeated ";
    if (defender_civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, defender_civ);
    s << " and placed ";
    list_event_link<df::historical_figure>(s, context, event->new_leaders);
    s << " in charge of ";
    event_link(s, context, site);
    s << ". The new government was called ";
    event_link(s, context, new_site_civ);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_site_tribute_forcedst *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    if (event->tribute_flags.bits.bled_dry)
    {
        s << " tried to secure tribute from ";
    }
    else
    {
        s << " secured tribute from ";
    }
    event_link(s, context, site_civ);
    s << " of ";
    event_link(s, context, defender_civ);
    if (event->tribute_flags.bits.bled_dry)
    {
        s << ", but they had nothing left to give";
    }
    else
    {
        s << ", to be delivered from ";
        event_link(s, context, site);
        s << " every ";
        BEFORE_SWITCH(season, event->season);
        switch (season)
        {
        case 0:
            s << "Spring";
            BREAK(season);
        case 1:
            s << "Summer";
            BREAK(season);
        case 2:
            s << "Autumn";
            BREAK(season);
        case 3:
            s << "Winter";
            BREAK(season);
        }
        AFTER_SWITCH(season, stl_sprintf("event-%d (WAR_SITE_TRIBUTE_FORCED)"));
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_war_site_taken_overst *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto new_site_civ = df::historical_entity::find(event->new_site_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->attacker_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    s << " defeated ";
    if (defender_civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, defender_civ);
    s << " and took over ";
    event_link(s, context, site);
    s << ". The new government was called ";
    event_link(s, context, new_site_civ);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_body_abusedst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
        if (auto ent = df::historical_entity::find(event->civ))
        {
            s << " of ";
            event_link(s, context, ent);
        }
    }
    else if (auto ent = df::historical_entity::find(event->civ))
    {
        event_link(s, context, ent);
    }
    BEFORE_SWITCH(type, event->abuse_type);
    switch (type)
    {
    case df::history_event_body_abusedst::T_abuse_type::Impaled:
        s << " impaled";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Piled:
        s << " added";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Flayed:
        s << " flayed";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Hung:
        s << " hung";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Mutilated:
        s << " horribly mutilated";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Animated:
        s << " animated";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
    if (event->bodies.size() == 1)
    {
        s << " the body of ";
    }
    else
    {
        s << " the bodies of ";
    }
    list_event_link<df::historical_figure>(s, context, event->bodies);
    BEFORE_SWITCH(type, event->abuse_type);
    switch (type)
    {
    case df::history_event_body_abusedst::T_abuse_type::Impaled:
    {
        ASSUME_EQUAL(event->props.item.item_type, item_type::WEAPON, stl_sprintf("event-%d (BODY_ABUSED) impaled", event->id));
        auto idef = df::itemdef_weaponst::find(event->props.item.item_subtype);
        s << " on ";
        if (event->bodies.size() == 1)
        {
            s << "a ";
            material(s, context, &event->props.item);
            s << " " << idef->name;
        }
        else
        {
            material(s, context, &event->props.item);
            s << " " << idef->name_plural;
        }
        BREAK(type);
    }
    case df::history_event_body_abusedst::T_abuse_type::Piled:
        s << " to a ";
        BEFORE_SWITCH(pile_type, event->props.pile_type);
        switch (pile_type)
        {
        case df::history_event_body_abusedst::T_props::T_pile_type::GrislyMound:
            s << "grisly mound";
            BREAK(pile_type);
        case df::history_event_body_abusedst::T_props::T_pile_type::GrotesquePillar:
            s << "grotesque pillar";
            BREAK(pile_type);
        case df::history_event_body_abusedst::T_props::T_pile_type::GruesomeSculpture:
            s << "gruesome sculpture";
            BREAK(pile_type);
        }
        AFTER_SWITCH(pile_type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Flayed:
    {
        s << " and stretched ";
        if (event->bodies.size() == 1)
        {
            auto hf = df::historical_figure::find(event->bodies.at(0));
            if (hf->sex == 0)
            {
                s << "her skin";
            }
            else if (hf->sex == 1)
            {
                s << "his skin";
            }
            else
            {
                s << "its skin";
            }
        }
        else
        {
            s << "their skins";
        }
        s << " over ";
        auto site = df::world_site::find(event->site);
        auto structure = binsearch_in_vector(site->buildings, event->props.structure);
        event_link(s, context, structure);
        BREAK(type);
    }
    case df::history_event_body_abusedst::T_abuse_type::Hung:
        s << " from ";
        if (auto tree = df::plant_raw::find(event->props.hung.tree))
        {
            s << "a " << tree->name << " tree with ";
        }
        if (event->bodies.size() == 1)
        {
            s << "a ";
            material(s, context, &event->props.hung);
            s << " rope";
        }
        else
        {
            material(s, context, &event->props.hung);
            s << " ropes";
        }
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Mutilated:
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Animated:
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
    // TODO: int32_t anon_1;
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_abductedst *event)
{
    auto target = df::historical_figure::find(event->target);
    auto snatcher = df::historical_figure::find(event->snatcher);

    event_link(s, context, target);
    s << " was abudcted by ";
    event_link(s, context, snatcher);
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_item_stolenst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    event_link(s, context, hf);
    s << " stole ";
    if (auto item = df::item::find(event->item))
    {
        do_item_description(s, item);
    }
    else if (event->item_type == item_type::FISH)
    {
        do_item_description<df::item_fishst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else if (event->item_type == item_type::FISH_RAW)
    {
        do_item_description<df::item_fish_rawst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else if (event->item_type == item_type::MEAT)
    {
        do_item_description<df::item_meatst>(s, context, event->item_subtype, event->mattype, event->matindex);
    }
    else
    {
        s << "a ";
        if (ENUM_ATTR(item_type, is_caste_mat, event->item_type))
        {
            auto creature = df::creature_raw::find(event->mattype);
            auto caste = creature->caste.at(event->matindex);
            if (!unique_creature_name(s, context, creature))
            {
                s << caste->caste_name[0];
            }
        }
        else
        {
            MaterialInfo mat(event->mattype, event->matindex);
            material(s, context, mat);
        }
        ItemTypeInfo type(event->item_type, event->item_subtype);
        s << " " << type.toString();
    }
    if (auto ent = df::historical_entity::find(event->entity))
    {
        s << " belonging to ";
        event_link(s, context, ent);
    }
    do_location_2_structure(s, context, event, " from ");
    if (auto site = df::world_site::find(event->anon_1))
    {
        s << " and brought it to ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_razed_buildingst *event)
{
    // TODO: int32_t histfig;
    // TODO: int32_t site;
    // TODO: int32_t structure;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_creature_devouredst *event)
{
    auto eater = df::historical_figure::find(event->eater);
    event_link(s, context, eater);
    s << " devoured ";
    if (auto victim = df::historical_figure::find(event->victim))
    {
        event_link(s, context, victim);
    }
    else if (auto race = df::creature_raw::find(event->race))
    {
        auto caste = race->caste.at(event->caste);
        s << "a " << caste->caste_name[0];
        if (auto ent = df::historical_entity::find(event->entity))
        {
            s << " owned by ";
            event_link(s, context, ent);
        }
    }
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_woundedst *event)
{
    auto wounder = df::historical_figure::find(event->wounder);
    event_link(s, context, wounder);

    std::string suffix;
    BEFORE_SWITCH(type, event->injury_type);
    switch (type)
    {
    case df::history_event_hist_figure_woundedst::T_injury_type::Smash:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " smashed";
            BREAK(part_lost);
        case 1:
            s << "crushed";
            suffix = " to a pulp";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Smash"));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Slash:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " cut";
            BREAK(part_lost);
        case 1:
            s << " cut";
            suffix = " off";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Slash"));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Stab:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " stabbed";
            BREAK(part_lost);
        case 1:
            s << " punctured";
            suffix = " into an indistinguishable mess";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Stab"));
        BREAK(type);
    case df::history_event_hist_figure_woundedst::T_injury_type::Rip:
        BEFORE_SWITCH(part_lost, event->part_lost);
        switch (part_lost)
        {
        case 0:
            s << " ripped";
            BREAK(part_lost);
        case 1:
            s << " tore";
            suffix = " off";
            BREAK(part_lost);
        }
        AFTER_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Rip"));
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED)", event->id));

    df::creature_raw *race = df::creature_raw::find(event->woundee_race);
    df::caste_raw *caste = race ? race->caste.at(event->woundee_caste) : nullptr;

    auto woundee = df::historical_figure::find(event->woundee);
    if (woundee)
    {
        s << " ";
        event_link(s, context, woundee);
        s << "&rsquo;s ";
    }
    else
    {
        s << " the ";
    }

    df::body_part_raw *bp = caste ? caste->body_info.body_parts.at(event->body_part) : nullptr;
    if (bp)
    {
        s << *bp->name_singular.at(0);
    }
    else
    {
        s << "[unknown body part]";
    }

    if (woundee == nullptr && caste != nullptr)
    {
        s << " of a " << caste->caste_name[0];
    }

    s << suffix;

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_battle_eventst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group1);
    BEFORE_SWITCH(type, event->subtype);
    switch (type)
    {
    case history_event_simple_battle_subtype::SCUFFLE:
        s << " had a scuffle with ";
        BREAK(type);
    case history_event_simple_battle_subtype::ATTACK:
        s << " attacked ";
        BREAK(type);
    case history_event_simple_battle_subtype::SURPRISE:
        s << " surprised ";
        BREAK(type);
    case history_event_simple_battle_subtype::AMBUSH:
        s << " ambushed ";
        BREAK(type);
    case history_event_simple_battle_subtype::HAPPEN_UPON:
        s << " happened upon ";
        BREAK(type);
    case history_event_simple_battle_subtype::CORNER:
        s << " cornered ";
        BREAK(type);
    case history_event_simple_battle_subtype::CONFRONT:
        s << " confronted ";
        BREAK(type);
    case history_event_simple_battle_subtype::LOSE_AFTER_RECEIVE_WOUND:
    case history_event_simple_battle_subtype::LOSE_AFTER_INFLICT_WOUND:
    case history_event_simple_battle_subtype::LOSE_AFTER_EXCHANGE_WOUND:
        s << " attacked ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_SIMPLE_BATTLE_EVENT)", event->id));
    list_event_link<df::historical_figure>(s, context, event->group2);
    switch (event->subtype)
    {
    case history_event_simple_battle_subtype::LOSE_AFTER_RECEIVE_WOUND:
        s << " and was wounded but escaped";
        break;
    case history_event_simple_battle_subtype::LOSE_AFTER_INFLICT_WOUND:
        s << " and inflicted a wound before escaping";
        break;
    case history_event_simple_battle_subtype::LOSE_AFTER_EXCHANGE_WOUND:
        s << " and exchanged wounds before escaping";
        break;
    default:
        break;
    }
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_created_world_constructionst *event)
{
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto construction = df::world_construction::find(event->construction);
    auto master_construction = df::world_construction::find(event->master_construction);
    auto site1 = df::world_site::find(event->site1);
    auto site2 = df::world_site::find(event->site2);

    if (civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, civ);
    s << " finished the construction of ";
    if (!construction)
    {
        s << "[unknown construction]";
        return;
    }

    if (auto name = construction->getName())
    {
        name_translated(s, *name);
    }
    else
    {
        s << "[unnamed]";
    }

    s << ", a " << toLower(enum_item_key(construction->getType()));

    if (site1 && site2)
    {
        s << " connecting ";
        event_link(s, context, site1);
        s << " and ";
        event_link(s, context, site2);
    }
    else if (site1)
    {
        s << " at ";
        event_link(s, context, site1);
    }
    else if (site2)
    {
        s << " at ";
        event_link(s, context, site2);
    }

    if (master_construction)
    {
        s << " as part of the " << toLower(enum_item_key(master_construction->getType())) << " ";
        if (auto name = master_construction->getName())
        {
            name_translated(s, *name);
        }
        else
        {
            s << "[unnamed]";
        }
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_reunionst *event)
{
    list_event_link<df::historical_figure>(s, context, event->missing);
    s << " " << (event->missing.size() == 1 ? "was" : "were") << " reunited with ";
    list_event_link<df::historical_figure>(s, context, event->reunited_with);

    if (auto assistant = df::historical_figure::find(event->assistant))
    {
        s << " with the help of ";
        event_link(s, context, assistant);
    }

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_reach_summitst *event)
{
    // TODO: std::vector<int32_t > group;
    // TODO: int32_t region;
    // TODO: int32_t layer;
    // TODO: df::coord2d region_pos;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_travelst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group);
    std::string prefix = " to ";
    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case df::history_event_hist_figure_travelst::T_reason::Journey:
        s << " made a journey";
        BREAK(reason);
    case df::history_event_hist_figure_travelst::T_reason::Return:
        s << " returned";
        BREAK(reason);
    case df::history_event_hist_figure_travelst::T_reason::Escape:
        s << " escaped";
        prefix = " from ";
        BREAK(reason);
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (HIST_FIGURE_TRAVEL)", event->id));
    do_location_2(s, context, event, prefix);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_new_petst *event)
{
    list_event_link<df::historical_figure>(s, context, event->group);
    s << " tamed ";
    list<int16_t>(s, event->pets, [](std::ostream & out, int16_t id)
    {
        if (auto race = df::creature_raw::find(id))
        {
            out << "the " << race->name[1];
        }
        else
        {
            out << "[unknown race]";
        }
    });
    do_location_2(s, context, event, " of ");
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_assume_identityst *event)
{
    auto trickster = df::historical_figure::find(event->trickster);
    auto identity = df::identity::find(event->identity);
    auto target = df::historical_entity::find(event->target);

    event_link(s, context, trickster);
    s << " tricked ";
    event_link(s, context, target);
    s << " into thinking ";

    BEFORE_SWITCH(sex, trickster ? trickster->sex : -1);
    switch (sex)
    {
    case -1:
        s << "it";
        BREAK(sex);
    case 0:
        s << "she";
        BREAK(sex);
    case 1:
        s << "he";
        BREAK(sex);
    }
    AFTER_SWITCH(sex, stl_sprintf("event-%d (ASSUME_IDENTITY)", event->id));

    s << " was ";
    do_identity(s, context, identity);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_create_entity_positionst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);
    auto civ = df::historical_entity::find(event->civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto position = site_civ ? binsearch_in_vector(site_civ->positions.own, event->position) : nullptr;

    event_link(s, context, histfig);
    if (civ)
    {
        s << " of ";
        event_link(s, context, civ);
    }

    std::string before(" created the position of ");
    std::string after;

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
        case 0:
            after = " through force of argument";
            BREAK(reason);
        case 1:
            before = " compelled the creation of the position of ";
            after = " with threats of violence";
            BREAK(reason);
        case 2:
            before = " collaborated to create the position of ";
            BREAK(reason);
        case 3:
            after = ", pushed by a wave of popular support";
            BREAK(reason);
        case 4:
            after = " as a matter of course";
            BREAK(reason);
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (CREATE_ENTITY_POSITION)", event->id));

    s << before;
    s << (position ? html_escape(position->name[0]) : "[unknown position]");
    if (civ != site_civ)
    {
        s << " of ";
        event_link(s, context, site_civ);
    }
    s << after;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_creature_typest *event)
{
    auto changee = df::historical_figure::find(event->changee);
    auto changer = df::historical_figure::find(event->changer);
    auto old_race = df::creature_raw::find(event->old_race);
    auto old_caste = old_race ? vector_get(old_race->caste, event->old_caste) : nullptr;
    auto new_race = df::creature_raw::find(event->new_race);
    auto new_caste = new_race ? vector_get(new_race->caste, event->new_caste) : nullptr;

    event_link(s, context, changer);
    s << " changed ";
    event_link(s, context, changee);

    if (old_caste)
    {
        s << " from a " << old_caste->caste_name[0];
    }
    else if (old_race)
    {
        s << " from a " << old_race->name[0];
    }

    if (new_caste)
    {
        s << " into a " << new_caste->caste_name[0];
    }
    else if (new_race)
    {
        s << " into a " << new_race->name[0];
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_revivedst *event)
{
    event_link(s, context, df::historical_figure::find(event->histfig));
    s << " came back to life ";
    BEFORE_SWITCH(flags, event->flags);
    switch (flags)
    {
        case 0:
            BREAK(flags);
        case 1:
            s << "again ";
            BREAK(flags);
    }
    AFTER_SWITCH(flags, stl_sprintf("event-%d (HIST_FIGURE_REVIVED)", event->id));

    s << "as ";
    BEFORE_SWITCH(type, event->ghost_type);
    switch (type)
    {
    case ghost_type::MurderousGhost:
        s << "a murderous ghost";
        BREAK(type);
    case ghost_type::SadisticGhost:
        s << "a sadistic ghost";
        BREAK(type);
    case ghost_type::SecretivePoltergeist:
        s << "a secretive poltergeist";
        BREAK(type);
    case ghost_type::EnergeticPoltergeist:
        s << "an energetic poltergeist";
        BREAK(type);
    case ghost_type::AngryGhost:
        s << "an angry ghost";
        BREAK(type);
    case ghost_type::ViolentGhost:
        s << "a violent ghost";
        BREAK(type);
    case ghost_type::MoaningSpirit:
        s << "a moaning spirit";
        BREAK(type);
    case ghost_type::HowlingSpirit:
        s << "a howling spirit";
        BREAK(type);
    case ghost_type::TroublesomePoltergeist:
        s << "a troublesome poltergeist";
        BREAK(type);
    case ghost_type::RestlessHaunt:
        s << "a restless haunt";
        BREAK(type);
    case ghost_type::ForlornHaunt:
        s << "a forlorn haunt";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_REVIVED)", event->id));
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_learns_secretst *event)
{
    auto student = df::historical_figure::find(event->student);
    auto teacher = df::historical_figure::find(event->teacher);
    auto artifact = df::artifact_record::find(event->artifact);
    auto interaction = df::interaction::find(event->interaction);

    if (teacher)
    {
        event_link(s, context, teacher);
        s << " taught ";
        event_link(s, context, student);
        s << " ";
    }
    else
    {
        event_link(s, context, student);
        s << " learned ";
    }
    s << (interaction && !interaction->sources.empty() ? interaction->sources.at(0)->name : "[unknown interaction]");
    if (artifact)
    {
        s << (teacher ? " using " : " from ");
        event_link(s, context, artifact);
    }

    // TODO: int32_t anon_1;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_body_statest *event)
{
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);

    std::string separator(" at ");

    BEFORE_SWITCH(body_state, event->body_state);
    switch (body_state)
    {
    case histfig_body_state::Active:
        s << " arose";
        separator = " from ";
        BREAK(body_state);
    case histfig_body_state::BuriedAtSite:
        s << " was buried";
        BREAK(body_state);
    case histfig_body_state::UnburiedAtBattlefield:
        s << " was left unburied on a battlefield";
        BREAK(body_state);
    case histfig_body_state::UnburiedAtSubregion:
    case histfig_body_state::UnburiedAtFeatureLayer:
    case histfig_body_state::UnburiedAtSite:
        s << " was left unburied";
        separator = " in ";
        BREAK(body_state);
    case histfig_body_state::EntombedAtSite:
        s << " was entombed";
        separator = " in ";
        BREAK(body_state);
    }
    AFTER_SWITCH(body_state, stl_sprintf("event-%d (CHANGE_HF_BODY_STATE)", event->id));

    do_location_2_structure(s, context, event, separator);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_act_on_buildingst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    event_link(s, context, hf);

    BEFORE_SWITCH(action, event->action);
    switch (action)
    {
    case df::history_event_hf_act_on_buildingst::T_action::Profane:
        s << " profaned ";
        BREAK(action);
    case df::history_event_hf_act_on_buildingst::T_action::Disturb:
        s << " disturbed ";
        BREAK(action);
    case df::history_event_hf_act_on_buildingst::T_action::PrayedInside:
        s << " prayed inside ";
        BREAK(action);
    }
    AFTER_SWITCH(action, stl_sprintf("event-%d (HF_ACT_ON_BUILDING)", event->id));

    auto site = df::world_site::find(event->site);
    auto structure = site ? binsearch_in_vector(site->buildings, event->structure) : nullptr;
    if (structure)
    {
        s << "the";
        categorize(s, structure);
        s << " ";
        event_link(s, context, structure);
    }
    else
    {
        s << "an unknown structure";
    }

    if (site)
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_does_interactionst *event)
{
    auto interaction = df::interaction::find(event->interaction);
    auto source = interaction ? binsearch_in_vector(interaction->sources, event->source) : nullptr;

    auto doer = df::historical_figure::find(event->doer);
    event_link(s, context, doer);
    if (source)
    {
        s << source->hist_string_1;
    }
    auto target = df::historical_figure::find(event->target);
    event_link(s, context, target);
    if (source)
    {
        s << source->hist_string_2;
    }
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_confrontedst *event)
{
    auto target = df::historical_figure::find(event->target);

    event_link(s, context, target);

    BEFORE_SWITCH(accuser, event->accuser);
    switch (accuser)
    {
    case 0:
        s << " aroused general suspicion ";
        BREAK(accuser);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(accuser, stl_sprintf("event-%d (HF_CONFRONTED)", event->id));

    if (!event->reasons.empty())
    {
        s << " after ";
        list<int32_t>(s, event->reasons, [context, event](std::ostream & out, int32_t reason_id)
        {
            BEFORE_SWITCH(reason, reason_id);
            switch (reason)
            {
            case 0:
                out << "appearing not to age";
                BREAK(reason);
            case 1:
                out << "a murder";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (HF_CONFRONTED)", event->id));
        });
    }

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_lawst *event)
{
    // TODO: int32_t entity;
    // TODO: int32_t histfig;
    // TODO: int32_t add_flags;
    // TODO: int32_t remove_flags;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_gains_secret_goalst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);
    event_link(s, context, histfig);

    BEFORE_SWITCH(goal, event->goal);
    switch (goal)
    {
    case goal_type::STAY_ALIVE:
        do_event_missing(s, context, event, __LINE__);
        BREAK(goal);
    case goal_type::MAINTAIN_ENTITY_STATUS:
        do_event_missing(s, context, event, __LINE__);
        BREAK(goal);
    case goal_type::START_A_FAMILY:
        s << " began dreaming of starting a family";
        BREAK(goal);
    case goal_type::RULE_THE_WORLD:
        s << " came to desire to rule the world";
        BREAK(goal);
    case goal_type::CREATE_A_GREAT_WORK_OF_ART:
        s << " began dreaming of creating a great work of art";
        BREAK(goal);
    case goal_type::CRAFT_A_MASTERWORK:
        s << " began dreaming of crafting a masterwork";
        BREAK(goal);
    case goal_type::BRING_PEACE_TO_THE_WORLD:
        s << " began dreaming of bringing peace to the world";
        BREAK(goal);
    case goal_type::BECOME_A_LEGENDARY_WARRIOR:
        s << " began dreaming of becoming a legendary warrior";
        BREAK(goal);
    case goal_type::MASTER_A_SKILL:
        s << " began dreaming of mastering a skill";
        BREAK(goal);
    case goal_type::FALL_IN_LOVE:
        s << " began dreaming of falling in love";
        BREAK(goal);
    case goal_type::SEE_THE_GREAT_NATURAL_SITES:
        s << " began dreaming of seeing the great natural wonders of the world";
        BREAK(goal);
    case goal_type::IMMORTALITY:
        BEFORE_SWITCH(sex, histfig ? histfig->sex : -1);
        switch (sex)
        {
        case -1:
            s << " became obsessed with its own mortality and sought to extend its life by any means";
            BREAK(sex);
        case 0:
            s << " became obsessed with her own mortality and sought to extend her life by any means";
            BREAK(sex);
        case 1:
            s << " became obsessed with his own mortality and sought to extend his life by any means";
            BREAK(sex);
        }
        AFTER_SWITCH(sex, stl_sprintf("event-%d (HF_GAINS_SECRET_GOAL:IMMORTALITY)", event->id));
        BREAK(goal);
    case goal_type::MAKE_A_GREAT_DISCOVERY:
        s << " began dreaming of making a great discovery";
        BREAK(goal);
    }
    AFTER_SWITCH(goal, stl_sprintf("event-%d (HF_GAINS_SECRET_GOAL)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_storedst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
        s << " stored ";
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        s << " was stored";
    }
    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_agreement_party(std::ostream & s, const event_context & context, df::history_event *event, df::agreement *agreement, df::agreement::T_parties *party)
{
    if (!party)
    {
        UNEXPECTED(stl_sprintf("missing agreement party: event-%d %s agreement-%d", event->id, enum_item_key(event->getType()).c_str(), agreement->id));
        s << "[unknown party]";
        return;
    }

    std::vector<std::pair<int32_t, bool>> members;
    for (auto it = party->histfig_ids.begin(); it != party->histfig_ids.end(); it++)
    {
        members.push_back(std::make_pair(*it, false));
    }
    for (auto it = party->entity_ids.begin(); it != party->entity_ids.end(); it++)
    {
        members.push_back(std::make_pair(*it, true));
    }
    ASSUME_EQUAL(party->anon_1.size(), 0, stl_sprintf("event-%d %s agreement-%d party-%d anon_1", event->id, enum_item_key(event->getType()).c_str(), agreement->id, party->id));

    list<std::pair<int32_t, bool>>(s, members, [context](std::ostream & out, std::pair<int32_t, bool> member)
    {
        if (member.second)
        {
            event_link(out, context, df::historical_entity::find(member.first));
        }
        else
        {
            event_link(out, context, df::historical_figure::find(member.first));
        }
    });
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_agreement_formedst *event)
{
    auto agreement = df::agreement::find(event->agreement_id);
    list<df::agreement::T_details *>(s, agreement->details, [context, event, agreement](std::ostream & out, df::agreement::T_details *details)
    {
        BEFORE_SWITCH(type, details->type);
        switch (type)
        {
        case 0:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data0->anon_2));
            out << " joined with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data0->anon_3));
            BEFORE_SWITCH(reason, static_cast<df::history_event_reason>(details->data.data0->anon_1));
            switch (reason)
            {
            case history_event_reason::insurrection:
                out << " to oust ";
                event_link(out, context, df::historical_entity::find(details->data.data0->anon_5));
                out << " from ";
                event_link(out, context, df::world_site::find(details->data.data0->anon_4));
                BREAK(reason);
            case history_event_reason::adventure:
                out << " to live a life of adventure";
                BREAK(reason);
            case history_event_reason::guide:
                out << " as a guide to ";
                event_link(out, context, df::world_site::find(details->data.data0->anon_4));
                BREAK(reason);
            case history_event_reason::be_brought_to_safety:
                out << " in order to be brought to safety";
                BREAK(reason);
            case history_event_reason::help_with_rescue:
                out << " to help rescue ";
                event_link(out, context, df::historical_figure::find(details->data.data0->anon_6));
                BREAK(reason);
            case history_event_reason::true_name_invocation: // TODO: ???
                out << " after being compelled to serve";
                BREAK(reason);
            case history_event_reason::entertain_people:
                out << " to entertain the world";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (joined party)", event->id, agreement->id, details->id));
            BREAK(type);
        }
        case 1:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data1->anon_2));
            out << " aided ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data1->anon_1));
            out << " in becoming a permanent part of the living world";
            BEFORE_SWITCH(reason, details->data.data1->reason);
            switch (reason)
            {
            case history_event_reason::sphere_alignment:
                out << " after pondering the ineffable subtleties of ";
                out << toLower(enum_item_key(static_cast<df::sphere_type>(details->data.data1->anon_3)));
                BREAK(reason);
            case history_event_reason::maintain_balance_in_universe:
                out << " in order to maintain balance in the universe";
                BREAK(reason);
            case history_event_reason::highlight_boundaries_between_worlds:
                out << " to create a monument to the boundaries between realities";
                BREAK(reason);
            case history_event_reason::sow_the_seeds_of_chaos_in_the_world:
                out << " to sow the seeds of chaos therein";
                BREAK(reason);
            case history_event_reason::provide_opportunities_for_courage:
                out << " to provide opportunities for courage to rise";
                BREAK(reason);
            case history_event_reason::bring_death_to_the_world:
                out << " that more might die";
                BREAK(reason);
            case history_event_reason::liked_appearance:
                out << " that all should gaze upon a truly gruesome visage";
                BREAK(reason);
            case history_event_reason::because_it_was_destined:
                out << " because it was destined";
                BREAK(reason);
            case history_event_reason::great_fortresses_built_and_tested:
                out << " that great fortresses might be raised and tested in siege";
                BREAK(reason);
            case history_event_reason::whim:
                out << " on a whim";
                BREAK(reason);
            case history_event_reason::bring_misery_to_the_world:
                out << " that it might bathe in misery forever";
                BREAK(reason);
            case history_event_reason::bring_murder_to_the_world:
                out << " that more might be murdered";
                BREAK(reason);
            case history_event_reason::bring_nightmares_into_reality:
                out << " in order to make nightmares reality";
                BREAK(reason);
            case history_event_reason::bring_thralldom_to_the_world:
                out << " in order to make thralls of everyone";
                BREAK(reason);
            case history_event_reason::bring_torture_to_the_world:
                out << " in order that acts of torture be perpetrated";
                BREAK(reason);
            case history_event_reason::provide_opportunities_for_acts_of_valor:
                out << " to provide opportunities for acts of valor to be performed";
                BREAK(reason);
            case history_event_reason::bring_war_to_the_world:
                out << " that war might rage forever";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (demonic binding)", event->id, agreement->id, details->id));

            if (auto artifact = df::artifact_record::find(details->data.data1->artifact))
            {
                out << " using ";
                event_link(out, context, artifact);
            }
            if (auto site = df::world_site::find(details->data.data1->site))
            {
                out << " in ";
                event_link(out, context, site);
            }
            BREAK(type);
        }
        case 2:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data1->anon_1));
            out << " made an agreement with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data1->anon_2));
            out << ", becoming a resident of ";
            event_link(out, context, df::world_site::find(details->data.data1->site));
            BEFORE_SWITCH(reason, details->data.data1->reason);
            switch (reason)
            {
            case history_event_reason::eradicate_beasts:
                out << " to eradicate monsters";
                BREAK(reason);
            case history_event_reason::entertain_people:
                out << " to entertain the citizenry";
                BREAK(reason);
            case history_event_reason::make_a_living_as_a_warrior:
                out << " to work as a mercenary";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (become resident)", event->id, agreement->id, details->id));
            BREAK(type);
        }
        case 3:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data0->anon_1));
            out << " made an agreement with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, &df::agreement::T_parties::id, details->data.data0->anon_2));
            out << ", becoming a citizen of ";
            event_link(out, context, df::world_site::find(details->data.data0->anon_3));
            BREAK(type);
        }
        default:
            do_event_missing(out, context, event, __LINE__);
            break;
        }
        AFTER_SWITCH(type, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d type", event->id, agreement->id, details->id));
    });
    // TODO: int32_t anon_1;
    // TODO: int32_t anon_2;
    // TODO: int32_t anon_3;
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_site_disputest *event)
{
    auto entity_1 = df::historical_entity::find(event->entity_1);
    auto entity_2 = df::historical_entity::find(event->entity_2);
    auto site_1 = df::world_site::find(event->site_1);
    auto site_2 = df::world_site::find(event->site_2);

    event_link(s, context, site_1);
    s << " of ";
    event_link(s, context, entity_1);

    s << " and ";

    event_link(s, context, site_2);
    s << " of ";
    event_link(s, context, entity_2);

    s << " became embroiled in a dispute over ";

    BEFORE_SWITCH(type, event->dispute_type);
    switch (type)
    {
    case site_dispute_type::Territory:
        s << "territory";
        BREAK(type);
    case site_dispute_type::WaterRights:
        s << "water rights";
        BREAK(type);
    case site_dispute_type::GrazingRights:
        s << "grazing rights";
        BREAK(type);
    case site_dispute_type::FishingRights:
        s << "fishing rights";
        BREAK(type);
    case site_dispute_type::RightsOfWay:
        s << "rights-of-way";
        BREAK(type);
    case site_dispute_type::LivestockOwnership:
        s << "livestock ownership";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (SITE_DISPUTE)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_agreement_concludedst *event)
{
    // TODO: int32_t agreement_id;
    // TODO: int32_t subject_id;
    // TODO: df::agreement_conclusion_reason reason;
    // TODO: int32_t concluder_hf;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_insurrection_startedst *event)
{
    // TODO: int32_t target_civ;
    // TODO: int32_t site;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_insurrection_endedst *event)
{
    // TODO: int32_t target_civ;
    // TODO: int32_t site;
    // TODO: df::insurrection_outcome outcome;
    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_attacked_sitest *event)
{
    auto hf = df::historical_figure::find(event->attacker_hf);
    event_link(s, context, hf);
    s << " attacked ";
    auto ent = df::historical_entity::find(event->site_civ);
    event_link(s, context, ent);
    if (auto civ = df::historical_entity::find(event->defender_civ))
    {
        s << " of ";
        event_link(s, context, civ);
    }
    auto site = df::world_site::find(event->site);
    s << " at ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_performancest *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case occasion_schedule_type::DANCE_PERFORMANCE:
        if (auto form = df::dance_form::find(schedule->reference))
        {
            s << "a performance of the dance ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a dance performance";
        }
        BREAK(type);
    case occasion_schedule_type::MUSICAL_PERFORMANCE:
        if (auto form = df::musical_form::find(schedule->reference))
        {
            s << "a performance of the song ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a musical performance";
        }
        BREAK(type);
    case occasion_schedule_type::POETRY_RECITAL:
        if (auto form = df::poetic_form::find(schedule->reference))
        {
            s << "a recital of the poetry ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a poetry recital";
        }
        BREAK(type);
    case occasion_schedule_type::STORYTELLING:
        if (auto ref = df::history_event::find(schedule->reference))
        {
            s << "a telling of how ";
            event_reverse(s, context, ref);
        }
        else
        {
            s << "a storytelling";
        }
        BREAK(type);
    default:
        s << ENUM_KEY_STR(history_event_type, event->getType());
        s << ":";
        s << ENUM_KEY_STR(occasion_schedule_type, schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (PERFORMANCE) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
    if (!schedule->features.empty())
    {
        s << " featuring ";
        list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context, event](std::ostream & out, df::entity_occasion_schedule_feature *feature)
        {
            schedule_feature(out, context, feature, event);
        });
    }
    s << " as part of ";
    name_translated(s, occasion->name);
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_competitionst *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case occasion_schedule_type::DANCE_COMPETITION:
        if (auto form = df::dance_form::find(schedule->reference))
        {
            s << "a competition of the dance ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a dance competition";
        }
        BREAK(type);
    case occasion_schedule_type::MUSICAL_COMPETITION:
        if (auto form = df::musical_form::find(schedule->reference))
        {
            s << "a competition of the song ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a musical competition";
        }
        BREAK(type);
    case occasion_schedule_type::POETRY_COMPETITION:
        if (auto form = df::poetic_form::find(schedule->reference))
        {
            s << "a competition of the poetry ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a poetry competition";
        }
        BREAK(type);
    case occasion_schedule_type::FOOT_RACE:
        s << "a foot race";
        BREAK(type);
    case occasion_schedule_type::WRESTLING_COMPETITION:
        s << "a wrestling competition";
        BREAK(type);
    case occasion_schedule_type::THROWING_COMPETITION:
        s << "a ";
        s << ItemTypeInfo(df::item_type(schedule->reference), int16_t(schedule->reference2)).toString();
        s << "-throwing competition";
        BREAK(type);
    case occasion_schedule_type::GLADIATORY_COMPETITION:
        s << "a gladiatory competition";
        s << ":" << schedule->reference << ":" << schedule->reference2;
        BREAK(type);
    default:
        s << ENUM_KEY_STR(history_event_type, event->getType());
        s << ":";
        s << ENUM_KEY_STR(occasion_schedule_type, schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (COMPETITION) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
    if (!schedule->features.empty())
    {
        s << " featuring ";
        list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context, event](std::ostream & out, df::entity_occasion_schedule_feature *feature)
        {
            schedule_feature(out, context, feature, event);
        });
    }
    s << " as part of ";
    name_translated(s, occasion->name);
    do_location_2(s, context, event);
    if (!event->competitor_hf.empty())
    {
        if (event->competitor_hf.size() == 1)
        {
            s << ", but the only competitor was ";
        }
        else
        {
            s << ". Competing were ";
        }
        list_event_link<df::historical_figure>(s, context, event->competitor_hf);
    }
    if (!event->winner_hf.empty())
    {
        if (event->winner_hf.size() == 1)
        {
            s << ". The winner was ";
        }
        else
        {
            s << ". The winners were ";
        }
        list_event_link<df::historical_figure>(s, context, event->winner_hf);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_processionst *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case occasion_schedule_type::PROCESSION:
        s << "a procession";
        BREAK(type);
    default:
        s << ENUM_KEY_STR(history_event_type, event->getType());
        s << ":";
        s << ENUM_KEY_STR(occasion_schedule_type, schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (PROCESSION) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
    if (!schedule->features.empty())
    {
        s << " featuring ";
        list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context, event](std::ostream & out, df::entity_occasion_schedule_feature *feature)
        {
            schedule_feature(out, context, feature, event);
        });
    }
    s << " as part of ";
    name_translated(s, occasion->name);
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_ceremonyst *event)
{
    auto ent = df::historical_entity::find(event->entity);
    event_link(s, context, ent);
    s << " held ";
    auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
    auto schedule = vector_get(occasion->schedule, event->schedule);
    BEFORE_SWITCH(type, schedule->type);
    switch (type)
    {
    case df::occasion_schedule_type::CEREMONY:
        s << "a ceremony";
        BREAK(type);
    default:
        s << ENUM_KEY_STR(history_event_type, event->getType());
        s << ":";
        s << ENUM_KEY_STR(occasion_schedule_type, schedule->type);
        s << ":";
        s << schedule->reference;
        s << ":";
        s << schedule->reference2;
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (CEREMONY) ref1=%d ref2=%d", event->id, schedule->reference, schedule->reference2));
    if (!schedule->features.empty())
    {
        s << " featuring ";
        list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context, event](std::ostream & out, df::entity_occasion_schedule_feature *feature)
        {
            schedule_feature(out, context, feature, event);
        });
    }
    s << " as part of ";
    name_translated(s, occasion->name);
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_knowledge_discoveredst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    event_link(s, context, hf);
    if (event->first == 0)
    {
        s << " independently discovered ";
    }
    else
    {
        ASSUME_EQUAL(event->first, 1, stl_sprintf("event-%d (KNOWLEDGE_DISCOVERED)", event->id));
        s << " was the first to discover ";
    }
    knowledge(s, event->knowledge);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_transformedst *event)
{
    auto new_artifact = df::artifact_record::find(event->new_artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto site = df::world_site::find(event->site);

    event_link(s, context, new_artifact);
    s << " was made from ";
    list_event_link<df::artifact_record>(s, context, event->old_artifact);
    s << " in ";
    event_link(s, context, site);
    s << " by ";
    event_link(s, context, histfig);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_destroyedst *event)
{
    auto item = df::artifact_record::find(event->artifact);
    if (auto hf = df::historical_figure::find(event->destroyer_hf))
    {
        event_link(s, context, hf);
        if (auto civ = df::historical_entity::find(event->destroyer_civ))
        {
            s << " of ";
            event_link(s, context, civ);
        }
        s << " destroyed ";
        event_link(s, context, item);
    }
    else if (auto civ = df::historical_entity::find(event->destroyer_civ))
    {
        event_link(s, context, civ);
        s << " destroyed ";
        event_link(s, context, item);
    }
    else
    {
        event_link(s, context, item);
        s << " was destroyed";
    }

    if (auto site = df::world_site::find(event->site))
    {
        s << " in ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_relationship_deniedst *event)
{
    auto seeker_hf = df::historical_figure::find(event->seeker_hf);
    auto target_hf = df::historical_figure::find(event->target_hf);

    event_link(s, context, seeker_hf);

    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case unit_relationship_type::Apprentice:
        s << " was denied an apprenticeship under ";
        BREAK(type);
    default:
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (HF_RELATIONSHIP_DENIED)", event->id));

    event_link(s, context, target_hf);

    s << " as ";

    if (event->reason_id == event->seeker_hf)
    {
        s << "the former";
    }
    else if (event->reason_id == event->target_hf)
    {
        s << "the latter";
    }
    else
    {
        event_link(s, context, df::historical_figure::find(event->reason_id));
    }

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case history_event_reason::prefers_working_alone:
        s << " prefers to work alone";
        BREAK(reason);
    default:
        s << enum_item_key(reason);
        break;
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (HF_RELATIONSHIP_DENIED)", event->id));

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_regionpop_incorporated_into_entityst *event)
{
    s << event->number_moved;
    if (auto race = df::creature_raw::find(event->pop_race))
    {
        s << " " << race->name[event->number_moved == 1 ? 0 : 1];
    }
    if (auto region = df::world_region::find(event->pop_region))
    {
        s << " from ";
        event_link(s, context, region);
    }
    if (auto layer = df::world_underground_region::find(event->pop_layer))
    {
        s << " from ";
        event_link(s, context, layer);
    }
    s << " joined ";
    auto ent = df::historical_entity::find(event->join_entity);
    event_link(s, context, ent);
    if (auto site = df::world_site::find(event->site))
    {
        s << " at ";
        event_link(s, context, site);
    }
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_poetic_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown poet";
    }
    s << " created ";
    if (auto form = df::poetic_form::find(event->form))
    {
        s << "the poetic form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown poetic form]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_musical_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown musician";
    }
    s << " created ";
    if (auto form = df::musical_form::find(event->form))
    {
        s << "the musical form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown musical form]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_dance_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown choreographer";
    }
    s << " created ";
    if (auto form = df::dance_form::find(event->form))
    {
        s << "the dance form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown dance form]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_written_content_composedst *event)
{
    auto hf = df::historical_figure::find(event->histfig);
    if (hf)
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown author";
    }
    s << " wrote ";
    if (auto content = df::written_content::find(event->content))
    {
        written_content(s, context, content, hf);
    }
    else
    {
        s << "[unknown document]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_moodst *event)
{
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);

    BEFORE_SWITCH(mood, event->mood);
    switch (mood)
    {
    case mood_type::None:
        do_event_missing(s, context, event, __LINE__);
        BREAK(mood);
    case mood_type::Fey:
        s << " was taken by a fey mood";
        BREAK(mood);
    case mood_type::Secretive:
        s << " withdrew from society";
        BREAK(mood);
    case mood_type::Possessed:
        s << " was possessed";
        BREAK(mood);
    case mood_type::Macabre:
        s << " began to skulk and brood";
        BREAK(mood);
    case mood_type::Fell:
        s << " was taken by a fell mood";
        BREAK(mood);
    case mood_type::Melancholy:
        s << " was striken by melancholy";
        BREAK(mood);
    case mood_type::Raving:
        s << " became crazed";
        BREAK(mood);
    case mood_type::Berserk:
        s << " went berserk";
        BREAK(mood);
    case mood_type::Baby:
        do_event_missing(s, context, event, __LINE__);
        BREAK(mood);
    case mood_type::Traumatized:
        s << " stopped responding to the outside world";
        BREAK(mood);
    }
    AFTER_SWITCH(mood, stl_sprintf("event-%d (CHANGE_HF_MOOD)", event->id));

    BEFORE_SWITCH(reason, event->reason);
    switch (reason)
    {
    case history_event_reason::none:
        BREAK(reason);
    case history_event_reason::failed_mood:
        s << " after failing to create an artifact";
        BREAK(reason);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(reason, stl_sprintf("event-%d (CHANGE_HF_MOOD)", event->id));

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_claim_formedst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto entity = df::historical_entity::find(event->entity);

    event_link(s, context, artifact);

    std::string before;
    std::string after;

    BEFORE_SWITCH(type, event->claim_type);
    using claim_type = df::history_event_artifact_claim_formedst::T_claim_type;
    switch (type)
    {
    case claim_type::Symbol:
        before = " was made a symbol of ";
        BREAK(type);
    case claim_type::Heirloom:
        before = " was claimed by ";
        after = " as a family heirloom";
        BREAK(type);
    case claim_type::Treasure:
        before = " was claimed by ";
        BREAK(type);
    case claim_type::HolyRelic:
        before = " was sanctified by ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ARTIFACT_CLAIM_FORMED)", event->id));

    s << before;

    if (histfig)
    {
        event_link(s, context, histfig);
    }
    if (!histfig || entity)
    {
        if (auto pos = entity ? vector_get(entity->positions.own, event->position_profile) : nullptr)
        {
            if (histfig)
            {
                s << ", ";
            }
            s << " the " << pos->name[0] << " of ";
        }
        else if (histfig)
        {
            s << " of ";
        }
        event_link(s, context, entity);
    }

    s << after;

    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_givenst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto giver_hf = df::historical_figure::find(event->giver_hf);
    auto giver_entity = df::historical_entity::find(event->giver_entity);
    auto receiver_hf = df::historical_figure::find(event->receiver_hf);
    auto receiver_entity = df::historical_entity::find(event->receiver_entity);

    event_link(s, context, artifact);
    s << " was offered to ";
    if (receiver_hf)
    {
        event_link(s, context, receiver_hf);
        if (receiver_entity)
        {
            s << " of ";
            event_link(s, context, receiver_entity);
        }
    }
    else
    {
        event_link(s, context, receiver_entity);
    }
    s << " by ";
    if (giver_hf)
    {
        event_link(s, context, giver_hf);
        if (giver_entity)
        {
            s << " of ";
            event_link(s, context, giver_entity);
        }
    }
    else
    {
        event_link(s, context, giver_entity);
    }
    do_circumstance_reason(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_act_on_artifactst *event)
{
    // TODO: T_action action;
    // TODO: int32_t artifact;
    // TODO: int32_t histfig;
    // TODO: int32_t site;
    // TODO: int32_t structure;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_recruited_unit_type_for_entityst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);
    s << " recruited " << toLower(ENUM_ATTR(profession, caption, event->profession)) << "s into "; // XXX: plural
    event_link(s, context, entity);

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hfs_formed_reputation_relationshipst *event)
{
    auto histfig1 = df::historical_figure::find(event->histfig1);
    auto identity1 = df::identity::find(event->identity1);
    auto histfig2 = df::historical_figure::find(event->histfig2);
    auto identity2 = df::identity::find(event->identity2);

    event_link(s, context, histfig1);
    if (identity1)
    {
        s << ", as ";
        do_identity(s, context, identity1);
        s << ",";
    }

    std::string before;
    std::string after;

    BEFORE_SWITCH(rep1, event->rep1);
    switch (rep1)
    {
    case reputation_type::InformationSource:
        BEFORE_SWITCH(rep2, event->rep2);
        switch (rep2)
        {
        case reputation_type::Buddy:
            before = " formed a false friendship with ";
            after = " in order to extract information";
            BREAK(rep2);
        case reputation_type::InformationSource:
            before = " and ";
            after = " formed a false friendship where each used the other for information";
            BREAK(rep2);
        default:
            do_event_missing(s, context, event, __LINE__);
            break;
        }
        AFTER_SWITCH(rep2, stl_sprintf("event-%d (HFS_FORMED_REPUTATION_RELATIONSHIP:InformationSource)", event->id));
        BREAK(rep1);
    default:
        do_event_missing(s, context, event, __LINE__);
        break;
    }
    AFTER_SWITCH(rep1, stl_sprintf("event-%d (HFS_FORMED_REPUTATION_RELATIONSHIP)", event->id));

    s << before;

    event_link(s, context, histfig2);
    if (identity2)
    {
        s << ", disguised as ";
        do_identity(s, context, identity2);
        if (!after.empty())
        {
            s << ",";
        }
    }

    s << after;

    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_copiedst *event)
{
    // TODO: int32_t artifact;
    // TODO: int32_t entity_dest;
    // TODO: int32_t entity_src;
    // TODO: int32_t site_dest;
    // TODO: int32_t site_src;
    // TODO: int32_t structure_dest;
    // TODO: int32_t structure_src;
    // TODO: T_flags flags;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_sneak_into_sitest *event)
{
    auto attacker_civ = df::historical_entity::find(event->attacker_civ);
    auto defender_civ = df::historical_entity::find(event->defender_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, attacker_civ);
    s << " slipped into ";
    event_link(s, context, site);
    s << ", undetected by ";
    if (defender_civ != site_civ)
    {
        event_link(s, context, site_civ);
        s << " of ";
    }
    event_link(s, context, defender_civ);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_spotted_leaving_sitest *event)
{
    auto spotter_hf = df::historical_figure::find(event->spotter_hf);
    auto leaver_civ = df::historical_entity::find(event->leaver_civ);
    auto site_civ = df::historical_entity::find(event->site_civ);
    auto site = df::world_site::find(event->site);

    event_link(s, context, spotter_hf);
    if (site_civ)
    {
        s << " of ";
        event_link(s, context, site_civ);
    }
    s << " spotted the forces of ";
    event_link(s, context, leaver_civ);
    s << " slipping out of ";
    event_link(s, context, site);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_searched_sitest *event)
{
    // TODO: int32_t searcher_civ;
    // TODO: int32_t site;
    // TODO: int32_t result; /*!< 0 = found nothing */

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_freedst *event)
{
    // TODO: int32_t freeing_civ;
    // TODO: int32_t freeing_hf;
    // TODO: int32_t holding_civ;
    // TODO: int32_t site_civ;
    // TODO: int32_t site;
    // TODO: std::vector<int32_t > rescued_hfs;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_actionst *event)
{
    // TODO: std::vector<int32_t > group_hfs;
    // TODO: int32_t type; /*!< 0 = hf carouse */
    // TODO: int32_t site;
    // TODO: int32_t structure;
    // TODO: int32_t region;
    // TODO: int32_t layer;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_rampaged_in_sitest *event)
{
    // TODO: int32_t rampage_civ_id;
    // TODO: int32_t site_id;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_entity_fled_sitest *event)
{
    // TODO: int32_t fled_civ_id;
    // TODO: int32_t site_id;

    do_event_missing(s, context, event, __LINE__);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_tactical_situationst *event)
{
    auto a_tactician = df::historical_figure::find(event->a_tactician_hfid);
    auto d_tactician = df::historical_figure::find(event->d_tactician_hfid);

    int tactical_outcome = event->a_tactics_roll < event->d_tactics_roll ?
        (event->a_tactics_roll > event->d_tactics_roll / 2 ? 2 : 3) :
        (event->a_tactics_roll / 2 < event->d_tactics_roll ? 1 : 0);

    if (a_tactician && d_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " outmatched ";
            }
            else
            {
                s << " entirely outwitted ";
            }
            event_link(s, context, d_tactician);
            break;
        case 1:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s tactical planning was superior to ";
            }
            else
            {
                s << " outmaneuvered ";
            }
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s";
            }
            break;
        case 2:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s tactical planning was superior to ";
            }
            else
            {
                s << " outmaneuvered ";
            }
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << "'s";
            }
            break;
        case 3:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " outmatched ";
            }
            else
            {
                s << " entirely outwitted ";
            }
            event_link(s, context, a_tactician);
            break;
        }

        switch (event->situation)
        {
        case tactical_situation::attacker_strongly_favored:
        case tactical_situation::attacker_favored:
        case tactical_situation::attacker_slightly_favored:
            s << (tactical_outcome < 2 ? ", and " : ", but ");
            break;
        case tactical_situation::defender_strongly_favored:
        case tactical_situation::defender_favored:
        case tactical_situation::defender_slightly_favored:
            s << (tactical_outcome < 2 ? ", but " : ", and ");
            break;
        case tactical_situation::neither_favored:
            s << ", but ";
            break;
        }
    }
    else if (a_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " unrolled a brilliant tactical plan ";
            }
            else
            {
                s << " hatched a stunning strategy ";
            }
            break;
        case 1:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " put forth a sound plan ";
            }
            else
            {
                s << " used good tactics ";
            }
            break;
        case 2:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made a poor plan ";
            }
            else
            {
                s << " used poor tactics ";
            }
            break;
        case 3:
            event_link(s, context, a_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made an outright foolish plan ";
            }
            else
            {
                s << " blundered terribly ";
            }
            break;
        }
    }
    else if (d_tactician)
    {
        switch (tactical_outcome)
        {
        case 0:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made an outright foolish plan ";
            }
            else
            {
                s << " blundered terribly ";
            }
            break;
        case 1:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " made a poor plan ";
            }
            else
            {
                s << " used poor tactics ";
            }
            break;
        case 2:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " put forth a sound plan ";
            }
            else
            {
                s << " used good tactics ";
            }
            break;
        case 3:
            event_link(s, context, d_tactician);
            if (event->tactics_flags.bits.start)
            {
                s << " unrolled a brilliant tactical plan ";
            }
            else
            {
                s << " hatched a stunning strategy ";
            }
            break;
        }
    }
    else
    {
        do_event_missing(s, context, event, __LINE__);
        return;
    }

    switch (event->situation)
    {
    case tactical_situation::attacker_strongly_favored:
    case tactical_situation::attacker_favored:
    case tactical_situation::attacker_slightly_favored:
        s << (tactical_outcome < 2 ? ", and " : ", but ");
        break;
    case tactical_situation::defender_strongly_favored:
    case tactical_situation::defender_favored:
    case tactical_situation::defender_slightly_favored:
        s << (tactical_outcome < 2 ? ", but " : ", and ");
        break;
    case tactical_situation::neither_favored:
        s << ", but ";
        break;
    }

    BEFORE_SWITCH(situation, event->situation);
    switch (situation)
    {
    case tactical_situation::attacker_strongly_favored:
        s << "the attackers had a strong positional advantage";
        BREAK(situation);
    case tactical_situation::attacker_favored:
        s << "the attackers had a position advantage";
        BREAK(situation);
    case tactical_situation::attacker_slightly_favored:
        s << "the attackers had a slight position advantage";
        BREAK(situation);
    case tactical_situation::defender_strongly_favored:
        s << "the defenders had a strong position advantage";
        BREAK(situation);
    case tactical_situation::defender_favored:
        s << "the defenders had a position advantage";
        BREAK(situation);
    case tactical_situation::defender_slightly_favored:
        s << "the defenders had a slight position advantage";
        BREAK(situation);
    case tactical_situation::neither_favored:
        s << "neither side had a position advantage";
        BREAK(situation);
    }
    AFTER_SWITCH(situation, stl_sprintf("event-%d (TACTICAL_SITUATION)", event->id));

    do_location_1_structure(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_squad_vs_squadst *event)
{
    if (event->d_leader_hfid != -1 || event->a_hfid.empty() || !event->d_hfid.empty() || event->a_number != 0 || event->d_number == 0 || event->d_squad_id != -1)
    {
        // TODO: int32_t a_leader_hfid;
        // TODO: int32_t a_leadership_roll;
        // TODO: std::vector<int32_t > a_hfid;
        // TODO: int32_t a_squad_id;
        // TODO: int32_t a_race;
        // TODO: int32_t a_interaction;
        // TODO: int32_t a_effect;
        // TODO: int32_t a_number;
        // TODO: int32_t a_slain;
        // TODO: int32_t d_leader_hfid;
        // TODO: int32_t d_leadership_roll;
        // TODO: std::vector<int32_t > d_hfid;
        // TODO: int32_t d_squad_id;
        // TODO: int32_t d_race;
        // TODO: int32_t d_interaction;
        // TODO: int32_t d_effect;
        // TODO: int32_t d_number;
        // TODO: int32_t d_slain;
        do_event_missing(s, context, event, __LINE__);
        return;
    }

    auto d_race = df::creature_raw::find(event->d_race);
    auto d_interaction = df::interaction::find(event->d_interaction);
    auto d_effect = d_interaction ? vector_get(d_interaction->effects, event->d_effect) : nullptr;

    if (auto a_squad = df::squad::find(event->a_squad_id))
    {
        name_translated(s, a_squad->name);
        if (auto a_squad_civ = df::historical_entity::find(a_squad->entity_id))
        {
            s << " of ";
            event_link(s, context, a_squad_civ);
        }
        s << ", ";
    }
    list_event_link<df::historical_figure>(s, context, event->a_hfid);
    if (auto a_leader = df::historical_figure::find(event->a_leader_hfid))
    {
        s << ", led by ";
        event_link(s, context, a_leader);
    }
    s << " clashed with " << event->d_number;
    if (d_effect)
    {
        auto animate = virtual_cast<df::interaction_effect_animatest>(d_effect);
        if (animate && animate->syndrome.size() == 1)
        {
            auto syn = animate->syndrome.at(0);
            do_event_missing(s, context, event, __LINE__);
        }
        else
        {
            do_event_missing(s, context, event, __LINE__);
        }
    }
    s << " " << d_race->name[event->d_number == 1 ? 0 : 1];

    do_location_1_structure(s, context, event);

    if (event->d_slain > 0)
    {
        s << ", slaying " << event->d_slain;
    }
}

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
    case history_event_type::WAR_ATTACKED_SITE:
        do_event(s, context, virtual_cast<df::history_event_war_attacked_sitest>(event));
        BREAK(type);
    case history_event_type::WAR_DESTROYED_SITE:
        do_event(s, context, virtual_cast<df::history_event_war_destroyed_sitest>(event));
        BREAK(type);
    case history_event_type::CREATED_SITE:
        do_event(s, context, virtual_cast<df::history_event_created_sitest>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_DIED:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_diedst>(event));
        BREAK(type);
    case history_event_type::ADD_HF_ENTITY_LINK:
        do_event(s, context, virtual_cast<df::history_event_add_hf_entity_linkst>(event));
        BREAK(type);
    case history_event_type::REMOVE_HF_ENTITY_LINK:
        do_event(s, context, virtual_cast<df::history_event_remove_hf_entity_linkst>(event));
        BREAK(type);
    case history_event_type::FIRST_CONTACT:
        do_event(s, context, virtual_cast<df::history_event_first_contactst>(event));
        BREAK(type);
    case history_event_type::FIRST_CONTACT_FAILED:
        do_event(s, context, virtual_cast<df::history_event_first_contact_failedst>(event));
        BREAK(type);
    case history_event_type::TOPICAGREEMENT_CONCLUDED:
        do_event(s, context, virtual_cast<df::history_event_topicagreement_concludedst>(event));
        BREAK(type);
    case history_event_type::TOPICAGREEMENT_REJECTED:
        do_event(s, context, virtual_cast<df::history_event_topicagreement_rejectedst>(event));
        BREAK(type);
    case history_event_type::TOPICAGREEMENT_MADE:
        do_event(s, context, virtual_cast<df::history_event_topicagreement_madest>(event));
        BREAK(type);
    case history_event_type::WAR_PEACE_ACCEPTED:
        do_event(s, context, virtual_cast<df::history_event_war_peace_acceptedst>(event));
        BREAK(type);
    case history_event_type::WAR_PEACE_REJECTED:
        do_event(s, context, virtual_cast<df::history_event_war_peace_rejectedst>(event));
        BREAK(type);
    case history_event_type::DIPLOMAT_LOST:
        do_event(s, context, virtual_cast<df::history_event_diplomat_lostst>(event));
        BREAK(type);
    case history_event_type::AGREEMENTS_VOIDED:
        do_event(s, context, virtual_cast<df::history_event_agreements_voidedst>(event));
        BREAK(type);
    case history_event_type::MERCHANT:
        do_event(s, context, virtual_cast<df::history_event_merchantst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_HIDDEN:
        do_event(s, context, virtual_cast<df::history_event_artifact_hiddenst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_POSSESSED:
        do_event(s, context, virtual_cast<df::history_event_artifact_possessedst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_CREATED:
        do_event(s, context, virtual_cast<df::history_event_artifact_createdst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_LOST:
        do_event(s, context, virtual_cast<df::history_event_artifact_lostst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_FOUND:
        do_event(s, context, virtual_cast<df::history_event_artifact_foundst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_RECOVERED:
        do_event(s, context, virtual_cast<df::history_event_artifact_recoveredst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_DROPPED:
        do_event(s, context, virtual_cast<df::history_event_artifact_droppedst>(event));
        BREAK(type);
    case history_event_type::RECLAIM_SITE:
        do_event(s, context, virtual_cast<df::history_event_reclaim_sitest>(event));
        BREAK(type);
    case history_event_type::HF_DESTROYED_SITE:
        do_event(s, context, virtual_cast<df::history_event_hf_destroyed_sitest>(event));
        BREAK(type);
    case history_event_type::SITE_DIED:
        do_event(s, context, virtual_cast<df::history_event_site_diedst>(event));
        BREAK(type);
    case history_event_type::SITE_RETIRED:
        do_event(s, context, virtual_cast<df::history_event_site_retiredst>(event));
        BREAK(type);
    case history_event_type::ENTITY_CREATED:
        do_event(s, context, virtual_cast<df::history_event_entity_createdst>(event));
        BREAK(type);
    case history_event_type::ENTITY_ACTION:
        do_event(s, context, virtual_cast<df::history_event_entity_actionst>(event));
        BREAK(type);
    case history_event_type::ENTITY_INCORPORATED:
        do_event(s, context, virtual_cast<df::history_event_entity_incorporatedst>(event));
        BREAK(type);
    case history_event_type::CREATED_BUILDING:
        do_event(s, context, virtual_cast<df::history_event_created_buildingst>(event));
        BREAK(type);
    case history_event_type::REPLACED_BUILDING:
        do_event(s, context, virtual_cast<df::history_event_replaced_buildingst>(event));
        BREAK(type);
    case history_event_type::ADD_HF_SITE_LINK:
        do_event(s, context, virtual_cast<df::history_event_add_hf_site_linkst>(event));
        BREAK(type);
    case history_event_type::REMOVE_HF_SITE_LINK:
        do_event(s, context, virtual_cast<df::history_event_remove_hf_site_linkst>(event));
        BREAK(type);
    case history_event_type::ADD_HF_HF_LINK:
        do_event(s, context, virtual_cast<df::history_event_add_hf_hf_linkst>(event));
        BREAK(type);
    case history_event_type::REMOVE_HF_HF_LINK:
        do_event(s, context, virtual_cast<df::history_event_remove_hf_hf_linkst>(event));
        BREAK(type);
    case history_event_type::ENTITY_RAZED_BUILDING:
        do_event(s, context, virtual_cast<df::history_event_entity_razed_buildingst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_ARCH_DESIGN:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_arch_designst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_ARCH_CONSTRUCT:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_arch_constructst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_ITEM:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_itemst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_DYE_ITEM:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_dye_itemst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_ITEM_IMPROVEMENT:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_item_improvementst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_FOOD:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_foodst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_CREATED_ENGRAVING:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_created_engravingst>(event));
        BREAK(type);
    case history_event_type::MASTERPIECE_LOST:
        do_event(s, context, virtual_cast<df::history_event_masterpiece_lostst>(event));
        BREAK(type);
    case history_event_type::CHANGE_HF_STATE:
        do_event(s, context, virtual_cast<df::history_event_change_hf_statest>(event));
        BREAK(type);
    case history_event_type::CHANGE_HF_JOB:
        do_event(s, context, virtual_cast<df::history_event_change_hf_jobst>(event));
        BREAK(type);
    case history_event_type::WAR_FIELD_BATTLE:
        do_event(s, context, virtual_cast<df::history_event_war_field_battlest>(event));
        BREAK(type);
    case history_event_type::WAR_PLUNDERED_SITE:
        do_event(s, context, virtual_cast<df::history_event_war_plundered_sitest>(event));
        BREAK(type);
    case history_event_type::WAR_SITE_NEW_LEADER:
        do_event(s, context, virtual_cast<df::history_event_war_site_new_leaderst>(event));
        BREAK(type);
    case history_event_type::WAR_SITE_TRIBUTE_FORCED:
        do_event(s, context, virtual_cast<df::history_event_war_site_tribute_forcedst>(event));
        BREAK(type);
    case history_event_type::WAR_SITE_TAKEN_OVER:
        do_event(s, context, virtual_cast<df::history_event_war_site_taken_overst>(event));
        BREAK(type);
    case history_event_type::BODY_ABUSED:
        do_event(s, context, virtual_cast<df::history_event_body_abusedst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_ABDUCTED:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_abductedst>(event));
        BREAK(type);
    case history_event_type::ITEM_STOLEN:
        do_event(s, context, virtual_cast<df::history_event_item_stolenst>(event));
        BREAK(type);
    case history_event_type::HF_RAZED_BUILDING:
        do_event(s, context, virtual_cast<df::history_event_hf_razed_buildingst>(event));
        BREAK(type);
    case history_event_type::CREATURE_DEVOURED:
        do_event(s, context, virtual_cast<df::history_event_creature_devouredst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_WOUNDED:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_woundedst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_SIMPLE_BATTLE_EVENT:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_simple_battle_eventst>(event));
        BREAK(type);
    case history_event_type::CREATED_WORLD_CONSTRUCTION:
        do_event(s, context, virtual_cast<df::history_event_created_world_constructionst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_REUNION:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_reunionst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_REACH_SUMMIT:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_reach_summitst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_TRAVEL:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_travelst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_NEW_PET:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_new_petst>(event));
        BREAK(type);
    case history_event_type::ASSUME_IDENTITY:
        do_event(s, context, virtual_cast<df::history_event_assume_identityst>(event));
        BREAK(type);
    case history_event_type::CREATE_ENTITY_POSITION:
        do_event(s, context, virtual_cast<df::history_event_create_entity_positionst>(event));
        BREAK(type);
    case history_event_type::CHANGE_CREATURE_TYPE:
        do_event(s, context, virtual_cast<df::history_event_change_creature_typest>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_REVIVED:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_revivedst>(event));
        BREAK(type);
    case history_event_type::HF_LEARNS_SECRET:
        do_event(s, context, virtual_cast<df::history_event_hf_learns_secretst>(event));
        BREAK(type);
    case history_event_type::CHANGE_HF_BODY_STATE:
        do_event(s, context, virtual_cast<df::history_event_change_hf_body_statest>(event));
        BREAK(type);
    case history_event_type::HF_ACT_ON_BUILDING:
        do_event(s, context, virtual_cast<df::history_event_hf_act_on_buildingst>(event));
        BREAK(type);
    case history_event_type::HF_DOES_INTERACTION:
        do_event(s, context, virtual_cast<df::history_event_hf_does_interactionst>(event));
        BREAK(type);
    case history_event_type::HF_CONFRONTED:
        do_event(s, context, virtual_cast<df::history_event_hf_confrontedst>(event));
        BREAK(type);
    case history_event_type::ENTITY_LAW:
        do_event(s, context, virtual_cast<df::history_event_entity_lawst>(event));
        BREAK(type);
    case history_event_type::HF_GAINS_SECRET_GOAL:
        do_event(s, context, virtual_cast<df::history_event_hf_gains_secret_goalst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_STORED:
        do_event(s, context, virtual_cast<df::history_event_artifact_storedst>(event));
        BREAK(type);
    case history_event_type::AGREEMENT_FORMED:
        do_event(s, context, virtual_cast<df::history_event_agreement_formedst>(event));
        BREAK(type);
    case history_event_type::SITE_DISPUTE:
        do_event(s, context, virtual_cast<df::history_event_site_disputest>(event));
        BREAK(type);
    case history_event_type::AGREEMENT_CONCLUDED:
        do_event(s, context, virtual_cast<df::history_event_agreement_concludedst>(event));
        BREAK(type);
    case history_event_type::INSURRECTION_STARTED:
        do_event(s, context, virtual_cast<df::history_event_insurrection_startedst>(event));
        BREAK(type);
    case history_event_type::INSURRECTION_ENDED:
        do_event(s, context, virtual_cast<df::history_event_insurrection_endedst>(event));
        BREAK(type);
    case history_event_type::HF_ATTACKED_SITE:
        do_event(s, context, virtual_cast<df::history_event_hf_attacked_sitest>(event));
        BREAK(type);
    case history_event_type::PERFORMANCE:
        do_event(s, context, virtual_cast<df::history_event_performancest>(event));
        BREAK(type);
    case history_event_type::COMPETITION:
        do_event(s, context, virtual_cast<df::history_event_competitionst>(event));
        BREAK(type);
    case history_event_type::PROCESSION:
        do_event(s, context, virtual_cast<df::history_event_processionst>(event));
        BREAK(type);
    case history_event_type::CEREMONY:
        do_event(s, context, virtual_cast<df::history_event_ceremonyst>(event));
        BREAK(type);
    case history_event_type::KNOWLEDGE_DISCOVERED:
        do_event(s, context, virtual_cast<df::history_event_knowledge_discoveredst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_TRANSFORMED:
        do_event(s, context, virtual_cast<df::history_event_artifact_transformedst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_DESTROYED:
        do_event(s, context, virtual_cast<df::history_event_artifact_destroyedst>(event));
        BREAK(type);
    case history_event_type::HF_RELATIONSHIP_DENIED:
        do_event(s, context, virtual_cast<df::history_event_hf_relationship_deniedst>(event));
        BREAK(type);
    case history_event_type::REGIONPOP_INCORPORATED_INTO_ENTITY:
        do_event(s, context, virtual_cast<df::history_event_regionpop_incorporated_into_entityst>(event));
        BREAK(type);
    case history_event_type::POETIC_FORM_CREATED:
        do_event(s, context, virtual_cast<df::history_event_poetic_form_createdst>(event));
        BREAK(type);
    case history_event_type::MUSICAL_FORM_CREATED:
        do_event(s, context, virtual_cast<df::history_event_musical_form_createdst>(event));
        BREAK(type);
    case history_event_type::DANCE_FORM_CREATED:
        do_event(s, context, virtual_cast<df::history_event_dance_form_createdst>(event));
        BREAK(type);
    case history_event_type::WRITTEN_CONTENT_COMPOSED:
        do_event(s, context, virtual_cast<df::history_event_written_content_composedst>(event));
        BREAK(type);
    case history_event_type::CHANGE_HF_MOOD:
        do_event(s, context, virtual_cast<df::history_event_change_hf_moodst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_CLAIM_FORMED:
        do_event(s, context, virtual_cast<df::history_event_artifact_claim_formedst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_GIVEN:
        do_event(s, context, virtual_cast<df::history_event_artifact_givenst>(event));
        BREAK(type);
    case history_event_type::HF_ACT_ON_ARTIFACT:
        do_event(s, context, virtual_cast<df::history_event_hf_act_on_artifactst>(event));
        BREAK(type);
    case history_event_type::HF_RECRUITED_UNIT_TYPE_FOR_ENTITY:
        do_event(s, context, virtual_cast<df::history_event_hf_recruited_unit_type_for_entityst>(event));
        BREAK(type);
    case history_event_type::HFS_FORMED_REPUTATION_RELATIONSHIP:
        do_event(s, context, virtual_cast<df::history_event_hfs_formed_reputation_relationshipst>(event));
        BREAK(type);
    case history_event_type::ARTIFACT_COPIED:
        do_event(s, context, virtual_cast<df::history_event_artifact_copiedst>(event));
        BREAK(type);
    case history_event_type::SNEAK_INTO_SITE:
        do_event(s, context, virtual_cast<df::history_event_sneak_into_sitest>(event));
        BREAK(type);
    case history_event_type::SPOTTED_LEAVING_SITE:
        do_event(s, context, virtual_cast<df::history_event_spotted_leaving_sitest>(event));
        BREAK(type);
    case history_event_type::ENTITY_SEARCHED_SITE:
        do_event(s, context, virtual_cast<df::history_event_entity_searched_sitest>(event));
        BREAK(type);
    case history_event_type::HF_FREED:
        do_event(s, context, virtual_cast<df::history_event_hf_freedst>(event));
        BREAK(type);
    case history_event_type::HIST_FIGURE_SIMPLE_ACTION:
        do_event(s, context, virtual_cast<df::history_event_hist_figure_simple_actionst>(event));
        BREAK(type);
    case history_event_type::ENTITY_RAMPAGED_IN_SITE:
        do_event(s, context, virtual_cast<df::history_event_entity_rampaged_in_sitest>(event));
        BREAK(type);
    case history_event_type::ENTITY_FLED_SITE:
        do_event(s, context, virtual_cast<df::history_event_entity_fled_sitest>(event));
        BREAK(type);
    case history_event_type::TACTICAL_SITUATION:
        do_event(s, context, virtual_cast<df::history_event_tactical_situationst>(event));
        BREAK(type);
    case history_event_type::SQUAD_VS_SQUAD:
        do_event(s, context, virtual_cast<df::history_event_squad_vs_squadst>(event));
        BREAK(type);
    }
    if (!type_found)
    {
        do_event_missing(s, context, event, __LINE__);
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
