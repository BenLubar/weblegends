#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"
#include "modules/Units.h"

#include "df/abstract_building.h"
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
#include "df/interaction.h"
#include "df/interaction_source.h"
#include "df/itemdef_weaponst.h"
#include "df/musical_form.h"
#include "df/plant_raw.h"
#include "df/poetic_form.h"
#include "df/ui.h"
#include "df/world.h"
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

static void do_weapon(std::ostream & s, const event_context & context, const df::history_hit_item & weapon)
{
	if (auto item = df::item::find(weapon.item))
	{
		s << " with ";
		std::string str;
		item->getItemDescriptionPrefix(&str, 0);
		s << str;
		str.clear();
		item->getItemDescription(&str, 0);
		s << str;
	}
	else if (weapon.item_type != item_type::NONE)
	{
		ItemTypeInfo type(weapon.item_type, weapon.item_subtype);
		MaterialInfo mat(weapon.mattype, weapon.matindex);
		s << " with a ";
		material(s, context, mat);
		s << " " << type.toString();
	}

	if (auto item = df::item::find(weapon.shooter_item))
	{
		s << " fired from ";
		std::string str;
		item->getItemDescriptionPrefix(&str, 0);
		s << str;
		str.clear();
		item->getItemDescription(&str, 0);
		s << str;
	}
	else if (weapon.shooter_item_type != item_type::NONE)
	{
		ItemTypeInfo type(weapon.shooter_item_type, weapon.shooter_item_subtype);
		MaterialInfo mat(weapon.shooter_mattype, weapon.shooter_matindex);
		s << " fired from a ";
		material(s, context, mat);
		s << " " << type.toString();
	}
}

static void do_event(std::ostream & s, const event_context &, df::history_event *event)
{
	std::string df_description;
	df::history_event_context df_context;
	df_context.anon_1 = -1;
	df_context.anon_2 = -1;
	df_context.histfig_id_talker = -1;
	df_context.histfig_id_listener = -1;
	event->getSentence(&df_description, &df_context, 1, 0);
	s << "<abbr title=\"" << df_description << "\">" << ENUM_KEY_STR(history_event_type, event->getType()) << ":" << event->id << "</abbr>";
	std::cerr << "[weblegends] missing event type handler for " << ENUM_KEY_STR(history_event_type, event->getType()) << ": event-" << event->id << std::endl;
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
	std::string prefix;

	auto victim = df::historical_figure::find(event->victim_hf);
	event_link(s, context, victim);

	SWITCH(cause, event->death_cause)
	{
        case death_type::OLD_AGE:
			s << " died of old age";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::HUNGER:
			s << " starved to death";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::THIRST:
			s << " died of thirst";
			prefix = " after being attacked";
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
			prefix = " after being attacked";
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
			prefix = ", pushed";
			BREAK(cause);
		case death_type::CAGE:
			s << " died in a cage";
			prefix = ", killed";
			BREAK(cause);
		case death_type::MURDER:
			s << " was murdered";
			BREAK(cause);
		case death_type::TRAP:
			s << " died in a trap";
			prefix = ", killed";
			BREAK(cause);
		case death_type::VANISH:
			s << " vanished into thin air";
			prefix = ", killed";
			BREAK(cause);
		case death_type::QUIT:
			s << " gave into starvation";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::ABANDON:
			s << " was abandoned";
			prefix = " after being attacked";
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
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::ENCASE_MAGMA:
			s << " was encased in cooling magma";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::ENCASE_ICE:
			s << " was encased in ice";
			prefix = " after being attacked";
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
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::MEMORIALIZE:
			s << " was put to death";
			BREAK(cause);
		case death_type::SCARE:
			s << " was scared to death";
			BREAK(cause);
		case death_type::DARKNESS:
			s << " died in the dark";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::COLLAPSE:
			s << " collapsed";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::DRAIN_BLOOD:
			s << " was drained of blood";
			BREAK(cause);
		case death_type::SLAUGHTER:
			s << " was slaughtered";
			BREAK(cause);
		case death_type::VEHICLE:
			s << " was killed by a vehicle";
			prefix = " after being attacked";
			BREAK(cause);
		case death_type::FALLING_OBJECT:
			s << " was killed by a falling object";
			prefix = " after being attacked";
			BREAK(cause);
	}
	END_SWITCH(cause, stl_sprintf("event-%d (HIST_FIGURE_DIED)", event->id));
	do_weapon(s, context, event->weapon);
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
	SWITCH(type, event->link_type)
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
	END_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_remove_hf_entity_linkst *event)
{
	auto ent = df::historical_entity::find(event->civ);
	auto hf = df::historical_figure::find(event->histfig);
	df::entity_position *pos;
	SWITCH(type, event->link_type)
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
	END_SWITCH(type, stl_sprintf("event-%d (ADD_HF_ENTITY_LINK)", event->id));
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_createdst *event)
{
	auto item = df::artifact_record::find(event->artifact_id);
	if (auto hf = df::historical_figure::find(event->hfid))
	{
		event_link(s, context, hf);
		s << " created ";
		event_link(s, context, item);
	}
	else
	{
		event_link(s, context, item);
		s << " was created";
	}
	if (auto site = df::world_site::find(event->site))
	{
		s << " in ";
		event_link(s, context, site);
	}
	// TODO uint32_t flags2; /*!< 1 = name_only */
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
	SWITCH(type, event->abuse_type)
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
	END_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
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
	SWITCH(type, event->abuse_type)
	{
		case df::history_event_body_abusedst::T_abuse_type::Impaled:
		{
			// event->props.item.item_type == item_type::WEAPON
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
		{
			s << " to a ";
			SWITCH(pile_type, event->props.pile_type)
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
			END_SWITCH(pile_type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
			BREAK(type);
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
			BREAK(type);
		}
		case df::history_event_body_abusedst::T_abuse_type::Hung:
		{
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
		}
		case df::history_event_body_abusedst::T_abuse_type::Mutilated:
		{
			BREAK(type);
		}
		case df::history_event_body_abusedst::T_abuse_type::Animated:
		{
			BREAK(type);
		}
	}
	END_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
	// TODO: int32_t anon_1;
	do_location_2(s, context, event);
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_hf_linkst *event)
{
	auto hf = df::historical_figure::find(event->hf);
	auto hf_target = df::historical_figure::find(event->hf_target);
	SWITCH(type, event->type)
	{
		case df::histfig_hf_link_type::MOTHER:
			event_link(s, context, hf);
			s << " gave birth to ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::FATHER:
			event_link(s, context, hf);
			s << " fathered ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::SPOUSE:
			event_link(s, context, hf);
			s << " married ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::CHILD:
			event_link(s, context, hf);
			s << " was born to ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::DEITY:
			event_link(s, context, hf);
			s << " began worshipping ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::LOVER:
			event_link(s, context, hf);
			s << " fell in love with ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::PRISONER:
			event_link(s, context, hf);
			s << " was imprisoned by ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::IMPRISONER:
			event_link(s, context, hf);
			s << " imprisoned ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::MASTER:
			event_link(s, context, hf);
			s << " accepted ";
			event_link(s, context, hf_target);
			s << " as an apprentice";
			BREAK(type);
		case df::histfig_hf_link_type::APPRENTICE:
			event_link(s, context, hf);
			s << " started an apprenticeship under ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::COMPANION:
			event_link(s, context, hf);
			s << " became the companion of ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::FORMER_MASTER:
			event_link(s, context, hf);
			s << " was no longer the master of ";
			event_link(s, context, hf_target);
			BREAK(type);
		case df::histfig_hf_link_type::FORMER_APPRENTICE:
			event_link(s, context, hf);
			s << " was no longer the apprentice of ";
			event_link(s, context, hf_target);
			BREAK(type);
	}
	END_SWITCH(type, stl_sprintf("event-%d (ADD_HF_HF_LINK)", event->id));
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_statest *event)
{
	std::string separator = " in ";
	auto hf = df::historical_figure::find(event->hfid);
	event_link(s, context, hf);
	SWITCH(state, event->state)
	{
		case df::history_event_change_hf_statest::T_state::Wandering:
			SWITCH(substate, event->substate)
			{
		case df::history_event_change_hf_statest::T_substate::Fled:
			s << " fled";
			separator = " to ";
			BREAK(substate);
		case df::history_event_change_hf_statest::T_substate::Wandered:
			s << " was wandering";
			BREAK(substate);
			}
			END_SWITCH(substate, stl_sprintf("event-%d (CHANGE_HF_STATE) Wandering", event->id));
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
		case (df::history_event_change_hf_statest::T_state)5:
			s << " visited";
			separator = " ";
			BREAK(state);
	}
	END_SWITCH(state, stl_sprintf("event-%d (CHANGE_HF_STATE)", event->id));
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
			s << "its";
		}
		s << " job as a " << profession_name(hf, event->old_job);
		do_location_2(s, context, event);
	}
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_item_stolenst *event)
{
	auto hf = df::historical_figure::find(event->histfig);
	event_link(s, context, hf);
	s << " stole ";
	if (auto item = df::item::find(event->item))
	{
		std::string str;
		item->getItemDescriptionPrefix(&str, 0);
		s << str;
		str.clear();
		item->getItemDescription(&str, 0);
		s << str;
	}
	else
	{
		s << "a ";
		if (ENUM_ATTR(item_type, is_caste_mat, event->item_type))
		{
			auto creature = df::creature_raw::find(event->mattype);
			auto caste = creature->caste.at(event->matindex);
			if (!material(s, context, creature))
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
	// TODO: int32_t anon_1;
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
	SWITCH(type, event->injury_type)
	{
		case df::history_event_hist_figure_woundedst::Smash:
			SWITCH(part_lost, event->part_lost)
			{
		case 0:
			s << " smashed";
			BREAK(part_lost);
		case 1:
			s << "crushed";
			suffix = " to a pulp";
			BREAK(part_lost);
			}
			END_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Smash"));
			BREAK(type);
		case df::history_event_hist_figure_woundedst::Slash:
			SWITCH(part_lost, event->part_lost)
			{
		case 0:
			s << " cut";
			BREAK(part_lost);
		case 1:
			s << " cut";
			suffix = " off";
			BREAK(part_lost);
			}
			END_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Slash"));
			BREAK(type);
		case df::history_event_hist_figure_woundedst::Stab:
			SWITCH(part_lost, event->part_lost)
			{
		case 0:
			s << " stabbed";
			BREAK(part_lost);
		case 1:
			s << " punctured";
			suffix = " into an indistinguishable mess";
			BREAK(part_lost);
			}
			END_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Stab"));
			BREAK(type);
		case df::history_event_hist_figure_woundedst::Rip:
			SWITCH(part_lost, event->part_lost)
			{
		case 0:
			s << " ripped";
			BREAK(part_lost);
		case 1:
			s << " tore";
			suffix = " off";
			BREAK(part_lost);
			}
			END_SWITCH(part_lost, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED) Rip"));
			BREAK(type);
	}
	END_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_WOUNDED)", event->id));

	df::creature_raw *race;
	df::caste_raw *caste;

	auto woundee = df::historical_figure::find(event->woundee);
	if (woundee)
	{
		race = df::creature_raw::find(woundee->race);
		caste = race->caste.at(woundee->caste);
		s << " ";
		event_link(s, context, woundee);
		s << "&rsquo;s ";
	}
	else
	{
		race = df::creature_raw::find(event->woundee_race);
		caste = race->caste.at(event->woundee_caste);
		s << " the ";
	}

	df::body_part_raw *bp = caste->body_info.body_parts.at(event->body_part);
	s << *bp->name_singular.at(0);

	if (woundee == nullptr)
	{
		s << " of a " << caste->caste_name[0];
	}

	s << suffix;

	do_location_2(s, context, event);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_simple_battle_eventst *event)
{
	list<int32_t>(s, event->group1, [context](std::ostream & out, int32_t id)
	{
		auto hf = df::historical_figure::find(id);
		event_link(out, context, hf);
	});
	SWITCH(type, event->subtype)
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
	END_SWITCH(type, stl_sprintf("event-%d (HIST_FIGURE_SIMPLE_BATTLE_EVENT)", event->id));
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_travelst *event)
{
	list<int32_t>(s, event->group, [context](std::ostream & out, int32_t id)
	{
		auto hf = df::historical_figure::find(id);
		event_link(out, context, hf);
	});
	std::string prefix = " to ";
	SWITCH(reason, event->reason)
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
	END_SWITCH(reason, stl_sprintf("event-%d (HIST_FIGURE_TRAVEL)", event->id));
	do_location_2(s, context, event, prefix);
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_hist_figure_new_petst *event)
{
	list<int32_t>(s, event->group, [context](std::ostream & out, int32_t id)
	{
		auto hf = df::historical_figure::find(id);
		event_link(out, context, hf);
	});
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

static void do_event(std::ostream & s, const event_context & context, df::history_event_hf_act_on_buildingst *event)
{
	auto hf = df::historical_figure::find(event->histfig);
	event_link(s, context, hf);

	SWITCH(action, event->action)
	{
	case df::history_event_hf_act_on_buildingst::T_action::Profane:
		s << " profaned ";
		BREAK(action);
	case df::history_event_hf_act_on_buildingst::T_action::Disturb:
		s << " disturbed ";
		BREAK(action);
	}
	END_SWITCH(action, stl_sprintf("event-%d (HF_ACT_ON_BUILDING)", event->id));

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

static void do_event(std::ostream & s, const event_context & context, df::history_event_performancest *event)
{
	auto ent = df::historical_entity::find(event->entity);
	event_link(s, context, ent);
	s << " held ";
	auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
	auto schedule = vector_get(occasion->schedule, event->schedule);
	SWITCH(type, schedule->type)
	{
	case df::occasion_schedule_type::DANCE_PERFORMANCE:
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
	case df::occasion_schedule_type::MUSICAL_PERFORMANCE:
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
	case df::occasion_schedule_type::POETRY_RECITAL:
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
	case df::occasion_schedule_type::STORYTELLING:
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
	}
	END_SWITCH(type, stl_sprintf("event-%d (PERFORMANCE)", event->id));
	if (!schedule->features.empty())
	{
		s << " featuring ";
		list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context](std::ostream & out, df::entity_occasion_schedule_feature *feature)
		{
			schedule_feature(out, context, feature);
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
	SWITCH(type, schedule->type)
	{
	case df::occasion_schedule_type::DANCE_COMPETITION:
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
	case df::occasion_schedule_type::MUSICAL_COMPETITION:
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
	case df::occasion_schedule_type::POETRY_COMPETITION:
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
	case df::occasion_schedule_type::FOOT_RACE:
		s << "a foot race";
		BREAK(type);
	case df::occasion_schedule_type::WRESTLING_COMPETITION:
		s << "a wrestling competition";
		BREAK(type);
	case df::occasion_schedule_type::THROWING_COMPETITION:
		s << "a ";
		s << ItemTypeInfo(df::item_type(schedule->reference), int16_t(schedule->reference2)).toString();
		s << "-throwing competition";
		BREAK(type);
	case df::occasion_schedule_type::GLADIATORY_COMPETITION:
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
	}
	END_SWITCH(type, stl_sprintf("event-%d (COMPETITION)", event->id));
	if (!schedule->features.empty())
	{
		s << " featuring ";
		list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context](std::ostream & out, df::entity_occasion_schedule_feature *feature)
		{
			schedule_feature(out, context, feature);
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
		list<int32_t>(s, event->competitor_hf, [context](std::ostream & out, int32_t id)
		{
			auto hf = df::historical_figure::find(id);
			event_link(out, context, hf);
		});
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
		list<int32_t>(s, event->winner_hf, [context](std::ostream & out, int32_t id)
		{
			auto hf = df::historical_figure::find(id);
			event_link(out, context, hf);
		});
	}
}

static void do_event(std::ostream & s, const event_context & context, df::history_event_processionst *event)
{
	auto ent = df::historical_entity::find(event->entity);
	event_link(s, context, ent);
	s << " held ";
	auto occasion = binsearch_in_vector(ent->occasion_info->occasions, &df::entity_occasion::id, event->occasion);
	auto schedule = vector_get(occasion->schedule, event->schedule);
	SWITCH(type, schedule->type)
	{
	case df::occasion_schedule_type::PROCESSION:
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
	}
	END_SWITCH(type, stl_sprintf("event-%d (PROCESSION)", event->id));
	if (!schedule->features.empty())
	{
		s << " featuring ";
		list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context](std::ostream & out, df::entity_occasion_schedule_feature *feature)
		{
			schedule_feature(out, context, feature);
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
	SWITCH(type, schedule->type)
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
	}
	END_SWITCH(type, stl_sprintf("event-%d (CEREMONY)", event->id));
	if (!schedule->features.empty())
	{
		s << " featuring ";
		list<df::entity_occasion_schedule_feature *>(s, schedule->features, [context](std::ostream & out, df::entity_occasion_schedule_feature *feature)
		{
			schedule_feature(out, context, feature);
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
		s << " was the first to discover ";
	}
	knowledge(s, event->knowledge);
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
	// TODO: int32_t circumstance;
	// TODO: int32_t circumstance_id;
	// TODO: int32_t reason;
	// TODO: int32_t reason_id;
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
	// TODO: int32_t circumstance;
	// TODO: int32_t circumstance_id;
	// TODO: int32_t reason;
	// TODO: int32_t reason_id;
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
	// TODO: int32_t circumstance;
	// TODO: int32_t circumstance_id;
	// TODO: int32_t reason;
	// TODO: int32_t reason_id;
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
	// TODO: int32_t circumstance;
	// TODO: int32_t circumstance_id;
	// TODO: int32_t reason;
	// TODO: int32_t reason_id;
}

static void event_dispatch(std::ostream & s, const event_context & context, df::history_event *event)
{
	int32_t month = (event->seconds / 28 / 1200) + 1;
	int32_t day = ((event->seconds / 1200) % 28) + 1;
	int32_t hour = (event->seconds % 1200) / 50;
	int32_t minute = (event->seconds % 50) * 60 / 50;
	s << "<!--" << event->id << ", " << stl_sprintf("%04d-%02d-%02dT%02d:%02d", event->year, month, day, hour, minute) << "-->";
	SWITCH(type, event->getType())
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
	}
	END_SWITCH(type, stl_sprintf("event-%d", event->id));
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
