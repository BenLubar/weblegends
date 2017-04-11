#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/caste_raw.h"
#include "df/creature_raw.h"
#include "df/entity_position.h"
#include "df/entity_position_assignment.h"
#include "df/histfig_entity_link.h"
#include "df/histfig_entity_link_former_occupationst.h"
#include "df/histfig_entity_link_former_positionst.h"
#include "df/histfig_entity_link_former_squadst.h"
#include "df/histfig_entity_link_occupationst.h"
#include "df/histfig_entity_link_position_claimst.h"
#include "df/histfig_entity_link_positionst.h"
#include "df/histfig_entity_link_squadst.h"
#include "df/histfig_hf_link.h"
#include "df/histfig_site_link.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/historical_figure_info.h"
#include "df/occupation.h"
#include "df/squad.h"
#include "df/world_site.h"

static void spheres(std::ostream & s, df::historical_figure *hf)
{
	if (hf->info && hf->info->spheres && !hf->info->spheres->empty())
	{
		s << " associated with ";
		list<df::sphere_type>(s, *hf->info->spheres, [](std::ostream & out, df::sphere_type t)
		{
			out << toLower(ENUM_KEY_STR(sphere_type, t));
		});
	}
}

static void year(std::ostream & s, int32_t year, int32_t tick)
{
	if (tick != -1)
	{
		s << "<abbr title=\"";
		s << day(tick) << " " << month(tick) << " " << year;
		s << "\">" << year << "</abbr>";
	}
	else
	{
		s << year;
	}
}

static void born_died(std::ostream & s, df::historical_figure *hf)
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

void WebLegends::render_figure(std::ostream & s, int32_t id)
{
	CoreSuspender suspend;

	auto hf = df::historical_figure::find(id);
	if (hf == nullptr)
	{
		return;
	}

	auto race = df::creature_raw::find(hf->race);
	auto caste = (race && hf->caste != -1) ? race->caste.at(hf->caste) : nullptr;

	simple_header(s, hf);

	s << "<p>";
	categorize(s, hf);
	spheres(s, hf);
	born_died(s, hf);
	if (caste)
	{
		s << "<br>" << caste->description;
	}
	s << "</p>";

	if (!hf->histfig_links.empty())
	{
		s << "<h2 id=\"related-figures\">Related Figures</h2><ul>";
		for (auto it = hf->histfig_links.begin(); it != hf->histfig_links.end(); it++)
		{
			if (auto target = df::historical_figure::find((*it)->target_hf))
			{
				s << "<li>";
				link(s, target);
				SWITCH(link_type, (*it)->getType())
				{
                    case histfig_hf_link_type::MOTHER:
						s << ", mother";
						BREAK(link_type);
					case histfig_hf_link_type::FATHER:
						s << ", father";
						BREAK(link_type);
					case histfig_hf_link_type::SPOUSE:
						if (target->sex == 0)
						{
							s << ", wife";
						}
						else if (target->sex == 1)
						{
							s << ", husband";
						}
						else
						{
							s << ", spouse";
						}
						BREAK(link_type);
					case histfig_hf_link_type::CHILD:
						if (target->sex == 0)
						{
							s << ", daughter";
						}
						else if (target->sex == 1)
						{
							s << ", son";
						}
						else
						{
							s << ", child";
						}
						BREAK(link_type);
					case histfig_hf_link_type::LOVER:
						s << ", lover";
						BREAK(link_type);
					case histfig_hf_link_type::DEITY:
						s << ", object of ";
						// TODO: ardent, faithful, ..., casual, dubious
						s << " worship";
						BREAK(link_type);
					case histfig_hf_link_type::COMPANION:
						s << ", companion";
						BREAK(link_type);
					case histfig_hf_link_type::PRISONER:
						s << ", prisoner";
						BREAK(link_type);
					case histfig_hf_link_type::IMPRISONER:
						s << ", imprisoner";
						BREAK(link_type);
					case histfig_hf_link_type::MASTER:
						s << ", master";
						BREAK(link_type);
					case histfig_hf_link_type::APPRENTICE:
						s << ", apprentice";
						BREAK(link_type);
					case histfig_hf_link_type::FORMER_MASTER:
						s << ", former master";
						BREAK(link_type);
					case histfig_hf_link_type::FORMER_APPRENTICE:
						s << ", former apprentice";
						BREAK(link_type);
				}
				END_SWITCH(link_type, stl_sprintf("fig-%d target=fig-%d", id, (*it)->target_hf));
				born_died(s, target);
				s << "</li>";
			}
		}
		s << "</ul>";
	}
	if (!hf->entity_links.empty())
	{
		s << "<h2 id=\"related-entities\">Related Entities</h2><ul>";
		for (auto it = hf->entity_links.begin(); it != hf->entity_links.end(); it++)
		{
			if (auto ent = df::historical_entity::find((*it)->entity_id))
			{
				s << "<li>";
				link(s, ent);
				SWITCH(link_type, (*it)->getType())
				{
					case histfig_entity_link_type::MEMBER:
						s << ", member";
						BREAK(link_type);
					case histfig_entity_link_type::FORMER_MEMBER:
						s << ", former member";
						BREAK(link_type);
					case histfig_entity_link_type::MERCENARY:
						s << ", mercenary";
						BREAK(link_type);
					case histfig_entity_link_type::FORMER_MERCENARY:
						s << ", former mercenary";
						BREAK(link_type);
					case histfig_entity_link_type::SLAVE:
						s << ", slave";
						BREAK(link_type);
					case histfig_entity_link_type::FORMER_SLAVE:
						s << ", former slave";
						BREAK(link_type);
					case histfig_entity_link_type::PRISONER:
						s << ", prisoner";
						BREAK(link_type);
					case histfig_entity_link_type::FORMER_PRISONER:
						s << ", former prisoner";
						BREAK(link_type);
					case histfig_entity_link_type::ENEMY:
						s << ", enemy";
						BREAK(link_type);
					case histfig_entity_link_type::CRIMINAL:
						s << ", criminal";
						BREAK(link_type);
					case histfig_entity_link_type::POSITION:
					{
						auto l = virtual_cast<df::histfig_entity_link_positionst>(*it);
						auto assignment = binsearch_in_vector(ent->positions.assignments, l->assignment_id);
						auto position = binsearch_in_vector(ent->positions.own, assignment->position_id);
						s << ", ";
						if (hf->sex == 0 && !position->name_female[0].empty())
						{
							s << position->name_female[0];
						}
						else if (hf->sex == 1 && !position->name_male[0].empty())
						{
							s << position->name_male[0];
						}
						else
						{
							s << position->name[0];
						}
						if (l->start_year > 0)
						{
							s << " (since " << l->start_year << ")";
						}
						BREAK(link_type);
					}
					case histfig_entity_link_type::FORMER_POSITION:
					{
						auto l = virtual_cast<df::histfig_entity_link_former_positionst>(*it);
						auto assignment = binsearch_in_vector(ent->positions.assignments, l->assignment_id);
						auto position = binsearch_in_vector(ent->positions.own, assignment->position_id);
						s << ", ";
						if (hf->sex == 0 && !position->name_female[0].empty())
						{
							s << position->name_female[0];
						}
						else if (hf->sex == 1 && !position->name_male[0].empty())
						{
							s << position->name_male[0];
						}
						else
						{
							s << position->name[0];
						}
						if (l->start_year > 0)
						{
							s << " (" << l->start_year << "-" << l->end_year << ")";
						}
						else
						{
							s << " (until " << l->end_year << ")";
						}
						BREAK(link_type);
					}
					case histfig_entity_link_type::POSITION_CLAIM:
					{
						auto l = virtual_cast<df::histfig_entity_link_position_claimst>(*it);
						auto assignment = binsearch_in_vector(ent->positions.assignments, l->assignment_id);
						auto position = binsearch_in_vector(ent->positions.own, assignment->position_id);
						s << ", ";
						if (hf->sex == 0 && !position->name_female[0].empty())
						{
							s << position->name_female[0];
						}
						else if (hf->sex == 1 && !position->name_male[0].empty())
						{
							s << position->name_male[0];
						}
						else
						{
							s << position->name[0];
						}
						if (l->start_year > 0)
						{
							s << " (since " << l->start_year << ")";
						}
						BREAK(link_type);
					}
					case histfig_entity_link_type::SQUAD:
					{
						auto l = virtual_cast<df::histfig_entity_link_squadst>(*it);
						auto squad = df::squad::find(l->squad_id);
						s << ", member of ";
						if (squad->alias.empty())
						{
							name_translated(s, squad->name);
						}
						else
						{
							s << squad->alias;
						}
						if (l->start_year > 0)
						{
							s << " (since " << l->start_year << ")";
						}
						BREAK(link_type);
					}
					case histfig_entity_link_type::FORMER_SQUAD:
					{
						auto l = virtual_cast<df::histfig_entity_link_former_squadst>(*it);
						auto squad = df::squad::find(l->squad_id);
						s << ", former member of ";
						if (squad->alias.empty())
						{
							name_translated(s, squad->name);
						}
						else
						{
							s << squad->alias;
						}
						if (l->start_year > 0)
						{
							s << " (" << l->start_year << "-" << l->end_year << ")";
						}
						else
						{
							s << " (until " << l->end_year << ")";
						}
						BREAK(link_type);
					}
					case histfig_entity_link_type::OCCUPATION:
					{
						auto l = virtual_cast<df::histfig_entity_link_occupationst>(*it);
						auto occupation = df::occupation::find(l->occupation_id);
						auto site = df::world_site::find(occupation->site_id);
						auto location = binsearch_in_vector(site->buildings, occupation->location_id);
						s << ", ";
						SWITCH(occ, occupation->type)
						{
					case occupation_type::TAVERN_KEEPER:
						s << "tavern keeper";
						BREAK(occ);
					case occupation_type::PERFORMER:
						s << "performer";
						BREAK(occ);
					case occupation_type::SCHOLAR:
						s << "scholar";
						BREAK(occ);
					case occupation_type::MERCENARY:
						s << "mercenary";
						BREAK(occ);
					case occupation_type::MONSTER_SLAYER:
						s << "monster slayer";
						BREAK(occ);
					case occupation_type::SCRIBE:
						s << "scribe";
						BREAK(occ);
						}
						END_SWITCH(occ, stl_sprintf("fig-%d (current) occ=%d loc=site-%d/bld-%d", id, l->occupation_id, occupation->site_id, occupation->location_id));
						s << " at ";
						link(s, location);
						s << " (" << l->start_year << "-)";
						BREAK(link_type);
					}
					case histfig_entity_link_type::FORMER_OCCUPATION:
					{
						auto l = virtual_cast<df::histfig_entity_link_former_occupationst>(*it);
						auto occupation = df::occupation::find(l->occupation_id);
						auto site = df::world_site::find(occupation->site_id);
						auto location = binsearch_in_vector(site->buildings, occupation->location_id);
						s << ", former ";
						SWITCH(occ, occupation->type)
						{
					case occupation_type::TAVERN_KEEPER:
						s << "tavern keeper";
						BREAK(occ);
					case occupation_type::PERFORMER:
						s << "performer";
						BREAK(occ);
					case occupation_type::SCHOLAR:
						s << "scholar";
						BREAK(occ);
					case occupation_type::MERCENARY:
						s << "mercenary";
						BREAK(occ);
					case occupation_type::MONSTER_SLAYER:
						s << "monster slayer";
						BREAK(occ);
					case occupation_type::SCRIBE:
						s << "scribe";
						BREAK(occ);
						}
						END_SWITCH(occ, stl_sprintf("fig-%d (former) occ=%d loc=site-%d/bld-%d", id, l->occupation_id, occupation->site_id, occupation->location_id));
						s << " at ";
						link(s, location);
						s << " (" << l->start_year << "-" << l->end_year << ")";
						BREAK(link_type);
					}
				}
				END_SWITCH(link_type, stl_sprintf("fig-%d target=ent-%d", id, (*it)->entity_id));
				s << "</li>";
			}
		}
		s << "</ul>";
	}
	if (!hf->site_links.empty())
	{
		s << "<h2 id=\"related-sites\">Related Sites</h2><ul>";
		for (auto it = hf->site_links.begin(); it != hf->site_links.end(); it++)
		{
			auto site = df::world_site::find((*it)->site);
			s << "<li>";
			SWITCH(link_type, (*it)->getType())
			{
                case histfig_site_link_type::SEAT_OF_POWER:
					link(s, site);
					s << ", seat of power";
					BREAK(link_type);
				case histfig_site_link_type::HANGOUT:
					link(s, site);
					s << ", hangout";
					BREAK(link_type);
				case histfig_site_link_type::HOME_SITE_ABSTRACT_BUILDING:
				{
					auto structure = binsearch_in_vector(site->buildings, (*it)->sub_id);
					link(s, structure);
					s << " in ";
					link(s, site);
					s << ", home";
					BREAK(link_type);
				}
				case histfig_site_link_type::HOME_SITE_REALIZATION_BUILDING:
					link(s, site);
					s << ", home";
					BREAK(link_type);
				case histfig_site_link_type::LAIR:
					link(s, site);
					s << ", lair";
					BREAK(link_type);
				case histfig_site_link_type::HOME_SITE_REALIZATION_SUL:
					link(s, site);
					s << ", home";
					BREAK(link_type);
			}
			END_SWITCH(link_type, stl_sprintf("fig-%d target=site-%d", id, (*it)->site));
			s << "</li>";
		}
		s << "</ul>";
	}
	history(s, hf);
	s << "</body></html>";
}
