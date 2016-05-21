#include "weblegends.h"
#include "helpers.h"

#include "modules/Materials.h"

#include "df/abstract_building.h"
#include "df/caste_raw.h"
#include "df/creature_raw.h"
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
#include "df/history_event_artifact_createdst.h"
#include "df/history_event_artifact_destroyedst.h"
#include "df/history_event_artifact_droppedst.h"
#include "df/history_event_artifact_foundst.h"
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
#include "df/history_event_change_hf_statest.h"
#include "df/history_event_competitionst.h"
#include "df/history_event_create_entity_positionst.h"
#include "df/history_event_created_buildingst.h"
#include "df/history_event_created_sitest.h"
#include "df/history_event_created_world_constructionst.h"
#include "df/history_event_creature_devouredst.h"
#include "df/history_event_dance_form_createdst.h"
#include "df/history_event_diplomat_lostst.h"
#include "df/history_event_entity_actionst.h"
#include "df/history_event_entity_createdst.h"
#include "df/history_event_entity_incorporatedst.h"
#include "df/history_event_entity_lawst.h"
#include "df/history_event_entity_razed_buildingst.h"
#include "df/history_event_first_contact_failedst.h"
#include "df/history_event_first_contactst.h"
#include "df/history_event_hf_act_on_buildingst.h"
#include "df/history_event_hf_attacked_sitest.h"
#include "df/history_event_hf_confrontedst.h"
#include "df/history_event_hf_destroyed_sitest.h"
#include "df/history_event_hf_does_interactionst.h"
#include "df/history_event_hf_gains_secret_goalst.h"
#include "df/history_event_hf_learns_secretst.h"
#include "df/history_event_hf_razed_buildingst.h"
#include "df/history_event_hf_relationship_deniedst.h"
#include "df/history_event_hist_figure_abductedst.h"
#include "df/history_event_hist_figure_diedst.h"
#include "df/history_event_hist_figure_new_petst.h"
#include "df/history_event_hist_figure_reach_summitst.h"
#include "df/history_event_hist_figure_reunionst.h"
#include "df/history_event_hist_figure_revivedst.h"
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
#include "df/itemdef_weaponst.h"
#include "df/plant_raw.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"

template<typename T>
static void do_location_1(std::ostream & s, const event_context & context, T *event)
{
    if (auto loc = df::world_site::find(event->site))
    {
        if (loc != context.site)
        {
            s << " in ";
            link(s, loc);
        }
    }
    if (auto loc = df::world_region::find(event->subregion))
    {
        if (loc != context.region)
        {
            s << " in ";
            link(s, loc);
        }
    }
    if (auto loc = df::world_underground_region::find(event->feature_layer))
    {
        if (loc != context.layer)
        {
            s << " in ";
            link(s, loc);
        }
    }
}

template<typename T>
static void do_location_2(std::ostream & s, const event_context & context, T *event)
{
    if (auto loc = df::world_site::find(event->site))
    {
        if (loc != context.site)
        {
            s << " in ";
            link(s, loc);
        }
    }
    if (auto loc = df::world_region::find(event->region))
    {
        if (loc != context.region)
        {
            s << " in ";
            link(s, loc);
        }
    }
    // TODO: df::coord2d region_pos;
    if (auto loc = df::world_underground_region::find(event->layer))
    {
        if (loc != context.layer)
        {
            s << " in ";
            link(s, loc);
        }
    }
}

static void do_event(std::ostream & s, const event_context &, df::history_event *event)
{
    s << ENUM_KEY_STR(history_event_type, event->getType());
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_diedst *event)
{
    auto victim = df::historical_figure::find(event->victim_hf);
    event_link(s, context, victim);
    if (auto slayer = df::historical_figure::find(event->slayer_hf))
    {
        s << " was slain by ";
        event_link(s, context, slayer);
    }
    else if (auto race = df::creature_raw::find(event->slayer_race))
    {
        auto caste = race->caste[event->slayer_caste];
        s << " was slain by a " << caste->caste_name[0];
    }
    else
    {
        s << " died of old age";
    }
    // TODO: df::history_hit_item weapon;
    do_location_1(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_entity_linkst *event)
{
    auto ent = df::historical_entity::find(event->civ);
    auto hf = df::historical_figure::find(event->histfig);
    df::entity_position *pos;
    switch (event->link_type)
    {
        case histfig_entity_link_type::MEMBER:
            event_link(s, context, hf);
            s << " became a member of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_MEMBER:
            event_link(s, context, hf);
            s << " became a former member of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::MERCENARY:
            event_link(s, context, hf);
            s << " became a mercenary of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_MERCENARY:
            event_link(s, context, hf);
            s << " became a former mercenary of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::SLAVE:
            event_link(s, context, hf);
            s << " became a slave of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_SLAVE:
            event_link(s, context, hf);
            s << " became a former slave of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::PRISONER:
            event_link(s, context, hf);
            s << " became a prisoner of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_PRISONER:
            event_link(s, context, hf);
            s << " became a former prisoner of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::ENEMY:
            event_link(s, context, hf);
            s << " became an enemy of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::CRIMINAL:
            event_link(s, context, hf);
            s << " became a criminal of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::POSITION:
            pos = ent->positions.own.at(event->position_id);
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
            break;
        case histfig_entity_link_type::FORMER_POSITION:
            pos = ent->positions.own.at(event->position_id);
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
            break;
        case histfig_entity_link_type::POSITION_CLAIM:
            pos = ent->positions.own.at(event->position_id);
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
            break;
        case histfig_entity_link_type::SQUAD:
            event_link(s, context, hf);
            s << " became a squad member of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_SQUAD:
            event_link(s, context, hf);
            s << " became a former squad member of ";
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::OCCUPATION:
            event_link(s, context, hf);
            s << " became a worker of ";
            // TODO: get occupation type
            event_link(s, context, ent);
            break;
        case histfig_entity_link_type::FORMER_OCCUPATION:
            event_link(s, context, hf);
            s << " became a former worker of ";
            // TODO: get occupation type
            event_link(s, context, ent);
            break;
    }
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
    switch (event->abuse_type)
    {
        case df::history_event_body_abusedst::T_abuse_type::Impaled:
            s << " impaled";
            break;
        case df::history_event_body_abusedst::T_abuse_type::Piled:
            s << " added";
            break;
        case df::history_event_body_abusedst::T_abuse_type::Flayed:
            s << " flayed";
            break;
        case df::history_event_body_abusedst::T_abuse_type::Hung:
            s << " hung";
            break;
        case df::history_event_body_abusedst::T_abuse_type::Mutilated:
            s << " horribly mutilated";
            break;
        case df::history_event_body_abusedst::T_abuse_type::Animated:
            s << " animated";
            break;
    }
    if (event->bodies.size() == 1)
    {
        s << " the body of ";
    }
    else
    {
        s << " the bodies of ";
    }
    list<int32_t>(s, event->bodies, [context](std::ostream & out, int32_t id)
            {
                auto hf = df::historical_figure::find(id);
                event_link(out, context, hf);
            });
    switch (event->abuse_type)
    {
        case df::history_event_body_abusedst::T_abuse_type::Impaled:
            {
                // event->props.item.item_type == item_type::WEAPON
                auto idef = df::itemdef_weaponst::find(event->props.item.item_subtype);
                MaterialInfo mat(&event->props.item);
                s << " on ";
                if (event->bodies.size() == 1)
                {
                    s << "a " << mat.toString() << " " << idef->name;
                }
                else
                {
                    s << mat.toString() << " " << idef->name_plural;
                }
                break;
            }
        case df::history_event_body_abusedst::T_abuse_type::Piled:
            {
                s << " to a ";
                switch (event->props.pile_type)
                {
                    case df::history_event_body_abusedst::T_props::T_pile_type::GrislyMound:
                        s << "grisly mound";
                        break;
                    case df::history_event_body_abusedst::T_props::T_pile_type::GrotesquePillar:
                        s << "grotesque pillar";
                        break;
                    case df::history_event_body_abusedst::T_props::T_pile_type::GruesomeSculpture:
                        s << "gruesome sculpture";
                        break;
                }
                break;
            }
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
                break;
            }
        case df::history_event_body_abusedst::T_abuse_type::Hung:
            {
                auto tree = df::plant_raw::find(event->props.hung.tree);
                MaterialInfo rope(&event->props.hung);
                s << " from a " << tree->name << " tree with ";
                if (event->bodies.size() == 1)
                {
                    s << "a " << rope.toString() << " rope";
                }
                else
                {
                    s << rope.toString() << " ropes";
                }
                break;
            }
        case df::history_event_body_abusedst::T_abuse_type::Mutilated:
            {
                break;
            }
        case df::history_event_body_abusedst::T_abuse_type::Animated:
            {
                break;
            }
    }
    // TODO: int32_t anon_1;
    do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_statest *event)
{
    std::string separator = " in ";
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    switch (event->state)
    {
        case df::history_event_change_hf_statest::T_state::Wandering:
            switch (event->substate)
            {
                case df::history_event_change_hf_statest::T_substate::Fled:
                    s << " fled";
                    separator = " to ";
                    break;
                case df::history_event_change_hf_statest::T_substate::Wandered:
                    s << " was wandering";
                    break;
            }
            break;
        case df::history_event_change_hf_statest::T_state::Settled:
            s << " settled";
            break;
        case df::history_event_change_hf_statest::T_state::Refugee:
            s << " became a refugee";
            break;
    }
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_battle_eventst *event)
{
    list<int32_t>(s, event->group1, [context](std::ostream & out, int32_t id)
            {
                auto hf = df::historical_figure::find(id);
                event_link(out, context, hf);
            });
    switch (event->subtype)
    {
        case history_event_simple_battle_subtype::SCUFFLE:
            s << " had a scuffle with ";
            break;
        case history_event_simple_battle_subtype::ATTACK:
            s << " attacked ";
            break;
        case history_event_simple_battle_subtype::SURPRISE:
            s << " surprised ";
            break;
        case history_event_simple_battle_subtype::AMBUSH:
            s << " ambushed ";
            break;
        case history_event_simple_battle_subtype::HAPPEN_UPON:
            s << " happened upon ";
            break;
        case history_event_simple_battle_subtype::CORNER:
            s << " cornered ";
            break;
        case history_event_simple_battle_subtype::CONFRONT:
            s << " confronted ";
            break;
        case history_event_simple_battle_subtype::LOSE_AFTER_RECEIVE_WOUND:
        case history_event_simple_battle_subtype::LOSE_AFTER_INFLICT_WOUND:
        case history_event_simple_battle_subtype::LOSE_AFTER_EXCHANGE_WOUND:
            s << " attacked ";
            break;
    }
    list<int32_t>(s, event->group2, [context](std::ostream & out, int32_t id)
            {
                auto hf = df::historical_figure::find(id);
                event_link(out, context, hf);
            });
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
            if (event->seconds == -1)
            {
                s << ", ";
            }
            else
            {
                s << " on " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
            }
        }
    }
    else if (event->seconds / 1200 != last_seconds / 1200)
    {
        s << "On " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
    }
    last_year = event->year;
    last_seconds = event->seconds;

    switch (event->getType())
    {
        case history_event_type::WAR_ATTACKED_SITE:
            do_event(s, context, virtual_cast<df::history_event_war_attacked_sitest>(event));
            break;
        case history_event_type::WAR_DESTROYED_SITE:
            do_event(s, context, virtual_cast<df::history_event_war_destroyed_sitest>(event));
            break;
        case history_event_type::CREATED_SITE:
            do_event(s, context, virtual_cast<df::history_event_created_sitest>(event));
            break;
        case history_event_type::HIST_FIGURE_DIED:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_diedst>(event));
            break;
        case history_event_type::ADD_HF_ENTITY_LINK:
            do_event(s, context, virtual_cast<df::history_event_add_hf_entity_linkst>(event));
            break;
        case history_event_type::REMOVE_HF_ENTITY_LINK:
            do_event(s, context, virtual_cast<df::history_event_remove_hf_entity_linkst>(event));
            break;
        case history_event_type::FIRST_CONTACT:
            do_event(s, context, virtual_cast<df::history_event_first_contactst>(event));
            break;
        case history_event_type::FIRST_CONTACT_FAILED:
            do_event(s, context, virtual_cast<df::history_event_first_contact_failedst>(event));
            break;
        case history_event_type::TOPICAGREEMENT_CONCLUDED:
            do_event(s, context, virtual_cast<df::history_event_topicagreement_concludedst>(event));
            break;
        case history_event_type::TOPICAGREEMENT_REJECTED:
            do_event(s, context, virtual_cast<df::history_event_topicagreement_rejectedst>(event));
            break;
        case history_event_type::TOPICAGREEMENT_MADE:
            do_event(s, context, virtual_cast<df::history_event_topicagreement_madest>(event));
            break;
        case history_event_type::WAR_PEACE_ACCEPTED:
            do_event(s, context, virtual_cast<df::history_event_war_peace_acceptedst>(event));
            break;
        case history_event_type::WAR_PEACE_REJECTED:
            do_event(s, context, virtual_cast<df::history_event_war_peace_rejectedst>(event));
            break;
        case history_event_type::DIPLOMAT_LOST:
            do_event(s, context, virtual_cast<df::history_event_diplomat_lostst>(event));
            break;
        case history_event_type::AGREEMENTS_VOIDED:
            do_event(s, context, virtual_cast<df::history_event_agreements_voidedst>(event));
            break;
        case history_event_type::MERCHANT:
            do_event(s, context, virtual_cast<df::history_event_merchantst>(event));
            break;
        case history_event_type::ARTIFACT_HIDDEN:
            do_event(s, context, virtual_cast<df::history_event_artifact_hiddenst>(event));
            break;
        case history_event_type::ARTIFACT_POSSESSED:
            do_event(s, context, virtual_cast<df::history_event_artifact_possessedst>(event));
            break;
        case history_event_type::ARTIFACT_CREATED:
            do_event(s, context, virtual_cast<df::history_event_artifact_createdst>(event));
            break;
        case history_event_type::ARTIFACT_LOST:
            do_event(s, context, virtual_cast<df::history_event_artifact_lostst>(event));
            break;
        case history_event_type::ARTIFACT_FOUND:
            do_event(s, context, virtual_cast<df::history_event_artifact_foundst>(event));
            break;
        case history_event_type::ARTIFACT_RECOVERED:
            do_event(s, context, virtual_cast<df::history_event_artifact_recoveredst>(event));
            break;
        case history_event_type::ARTIFACT_DROPPED:
            do_event(s, context, virtual_cast<df::history_event_artifact_droppedst>(event));
            break;
        case history_event_type::RECLAIM_SITE:
            do_event(s, context, virtual_cast<df::history_event_reclaim_sitest>(event));
            break;
        case history_event_type::HF_DESTROYED_SITE:
            do_event(s, context, virtual_cast<df::history_event_hf_destroyed_sitest>(event));
            break;
        case history_event_type::SITE_DIED:
            do_event(s, context, virtual_cast<df::history_event_site_diedst>(event));
            break;
        case history_event_type::SITE_RETIRED:
            do_event(s, context, virtual_cast<df::history_event_site_retiredst>(event));
            break;
        case history_event_type::ENTITY_CREATED:
            do_event(s, context, virtual_cast<df::history_event_entity_createdst>(event));
            break;
        case history_event_type::ENTITY_ACTION:
            do_event(s, context, virtual_cast<df::history_event_entity_actionst>(event));
            break;
        case history_event_type::ENTITY_INCORPORATED:
            do_event(s, context, virtual_cast<df::history_event_entity_incorporatedst>(event));
            break;
        case history_event_type::CREATED_BUILDING:
            do_event(s, context, virtual_cast<df::history_event_created_buildingst>(event));
            break;
        case history_event_type::REPLACED_BUILDING:
            do_event(s, context, virtual_cast<df::history_event_replaced_buildingst>(event));
            break;
        case history_event_type::ADD_HF_SITE_LINK:
            do_event(s, context, virtual_cast<df::history_event_add_hf_site_linkst>(event));
            break;
        case history_event_type::REMOVE_HF_SITE_LINK:
            do_event(s, context, virtual_cast<df::history_event_remove_hf_site_linkst>(event));
            break;
        case history_event_type::ADD_HF_HF_LINK:
            do_event(s, context, virtual_cast<df::history_event_add_hf_hf_linkst>(event));
            break;
        case history_event_type::REMOVE_HF_HF_LINK:
            do_event(s, context, virtual_cast<df::history_event_remove_hf_hf_linkst>(event));
            break;
        case history_event_type::ENTITY_RAZED_BUILDING:
            do_event(s, context, virtual_cast<df::history_event_entity_razed_buildingst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_ARCH_DESIGN:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_arch_designst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_ARCH_CONSTRUCT:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_arch_constructst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_ITEM:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_itemst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_DYE_ITEM:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_dye_itemst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_ITEM_IMPROVEMENT:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_item_improvementst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_FOOD:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_foodst>(event));
            break;
        case history_event_type::MASTERPIECE_CREATED_ENGRAVING:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_created_engravingst>(event));
            break;
        case history_event_type::MASTERPIECE_LOST:
            do_event(s, context, virtual_cast<df::history_event_masterpiece_lostst>(event));
            break;
        case history_event_type::CHANGE_HF_STATE:
            do_event(s, context, virtual_cast<df::history_event_change_hf_statest>(event));
            break;
        case history_event_type::CHANGE_HF_JOB:
            do_event(s, context, virtual_cast<df::history_event_change_hf_jobst>(event));
            break;
        case history_event_type::WAR_FIELD_BATTLE:
            do_event(s, context, virtual_cast<df::history_event_war_field_battlest>(event));
            break;
        case history_event_type::WAR_PLUNDERED_SITE:
            do_event(s, context, virtual_cast<df::history_event_war_plundered_sitest>(event));
            break;
        case history_event_type::WAR_SITE_NEW_LEADER:
            do_event(s, context, virtual_cast<df::history_event_war_site_new_leaderst>(event));
            break;
        case history_event_type::WAR_SITE_TRIBUTE_FORCED:
            do_event(s, context, virtual_cast<df::history_event_war_site_tribute_forcedst>(event));
            break;
        case history_event_type::WAR_SITE_TAKEN_OVER:
            do_event(s, context, virtual_cast<df::history_event_war_site_taken_overst>(event));
            break;
        case history_event_type::BODY_ABUSED:
            do_event(s, context, virtual_cast<df::history_event_body_abusedst>(event));
            break;
        case history_event_type::HIST_FIGURE_ABDUCTED:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_abductedst>(event));
            break;
        case history_event_type::ITEM_STOLEN:
            do_event(s, context, virtual_cast<df::history_event_item_stolenst>(event));
            break;
        case history_event_type::HF_RAZED_BUILDING:
            do_event(s, context, virtual_cast<df::history_event_hf_razed_buildingst>(event));
            break;
        case history_event_type::CREATURE_DEVOURED:
            do_event(s, context, virtual_cast<df::history_event_creature_devouredst>(event));
            break;
        case history_event_type::HIST_FIGURE_WOUNDED:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_woundedst>(event));
            break;
        case history_event_type::HIST_FIGURE_SIMPLE_BATTLE_EVENT:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_simple_battle_eventst>(event));
            break;
        case history_event_type::CREATED_WORLD_CONSTRUCTION:
            do_event(s, context, virtual_cast<df::history_event_created_world_constructionst>(event));
            break;
        case history_event_type::HIST_FIGURE_REUNION:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_reunionst>(event));
            break;
        case history_event_type::HIST_FIGURE_REACH_SUMMIT:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_reach_summitst>(event));
            break;
        case history_event_type::HIST_FIGURE_TRAVEL:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_travelst>(event));
            break;
        case history_event_type::HIST_FIGURE_NEW_PET:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_new_petst>(event));
            break;
        case history_event_type::ASSUME_IDENTITY:
            do_event(s, context, virtual_cast<df::history_event_assume_identityst>(event));
            break;
        case history_event_type::CREATE_ENTITY_POSITION:
            do_event(s, context, virtual_cast<df::history_event_create_entity_positionst>(event));
            break;
        case history_event_type::CHANGE_CREATURE_TYPE:
            do_event(s, context, virtual_cast<df::history_event_change_creature_typest>(event));
            break;
        case history_event_type::HIST_FIGURE_REVIVED:
            do_event(s, context, virtual_cast<df::history_event_hist_figure_revivedst>(event));
            break;
        case history_event_type::HF_LEARNS_SECRET:
            do_event(s, context, virtual_cast<df::history_event_hf_learns_secretst>(event));
            break;
        case history_event_type::CHANGE_HF_BODY_STATE:
            do_event(s, context, virtual_cast<df::history_event_change_hf_body_statest>(event));
            break;
        case history_event_type::HF_ACT_ON_BUILDING:
            do_event(s, context, virtual_cast<df::history_event_hf_act_on_buildingst>(event));
            break;
        case history_event_type::HF_DOES_INTERACTION:
            do_event(s, context, virtual_cast<df::history_event_hf_does_interactionst>(event));
            break;
        case history_event_type::HF_CONFRONTED:
            do_event(s, context, virtual_cast<df::history_event_hf_confrontedst>(event));
            break;
        case history_event_type::ENTITY_LAW:
            do_event(s, context, virtual_cast<df::history_event_entity_lawst>(event));
            break;
        case history_event_type::HF_GAINS_SECRET_GOAL:
            do_event(s, context, virtual_cast<df::history_event_hf_gains_secret_goalst>(event));
            break;
        case history_event_type::ARTIFACT_STORED:
            do_event(s, context, virtual_cast<df::history_event_artifact_storedst>(event));
            break;
        case history_event_type::AGREEMENT_FORMED:
            do_event(s, context, virtual_cast<df::history_event_agreement_formedst>(event));
            break;
        case history_event_type::SITE_DISPUTE:
            do_event(s, context, virtual_cast<df::history_event_site_disputest>(event));
            break;
        case history_event_type::AGREEMENT_CONCLUDED:
            do_event(s, context, virtual_cast<df::history_event_agreement_concludedst>(event));
            break;
        case history_event_type::INSURRECTION_STARTED:
            do_event(s, context, virtual_cast<df::history_event_insurrection_startedst>(event));
            break;
        case history_event_type::INSURRECTION_ENDED:
            do_event(s, context, virtual_cast<df::history_event_insurrection_endedst>(event));
            break;
        case history_event_type::HF_ATTACKED_SITE:
            do_event(s, context, virtual_cast<df::history_event_hf_attacked_sitest>(event));
            break;
        case history_event_type::PERFORMANCE:
            do_event(s, context, virtual_cast<df::history_event_performancest>(event));
            break;
        case history_event_type::COMPETITION:
            do_event(s, context, virtual_cast<df::history_event_competitionst>(event));
            break;
        case history_event_type::PROCESSION:
            do_event(s, context, virtual_cast<df::history_event_processionst>(event));
            break;
        case history_event_type::CEREMONY:
            do_event(s, context, virtual_cast<df::history_event_ceremonyst>(event));
            break;
        case history_event_type::KNOWLEDGE_DISCOVERED:
            do_event(s, context, virtual_cast<df::history_event_knowledge_discoveredst>(event));
            break;
        case history_event_type::ARTIFACT_TRANSFORMED:
            do_event(s, context, virtual_cast<df::history_event_artifact_transformedst>(event));
            break;
        case history_event_type::ARTIFACT_DESTROYED:
            do_event(s, context, virtual_cast<df::history_event_artifact_destroyedst>(event));
            break;
        case history_event_type::HF_RELATIONSHIP_DENIED:
            do_event(s, context, virtual_cast<df::history_event_hf_relationship_deniedst>(event));
            break;
        case history_event_type::REGIONPOP_INCORPORATED_INTO_ENTITY:
            do_event(s, context, virtual_cast<df::history_event_regionpop_incorporated_into_entityst>(event));
            break;
        case history_event_type::POETIC_FORM_CREATED:
            do_event(s, context, virtual_cast<df::history_event_poetic_form_createdst>(event));
            break;
        case history_event_type::MUSICAL_FORM_CREATED:
            do_event(s, context, virtual_cast<df::history_event_musical_form_createdst>(event));
            break;
        case history_event_type::DANCE_FORM_CREATED:
            do_event(s, context, virtual_cast<df::history_event_dance_form_createdst>(event));
            break;
        case history_event_type::WRITTEN_CONTENT_COMPOSED:
            do_event(s, context, virtual_cast<df::history_event_written_content_composedst>(event));
            break;
    }
    s << ". ";
}
