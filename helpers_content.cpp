#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/abstract_building.h"
#include "df/artifact_record.h"
#include "df/dance_form.h"
#include "df/entity_occasion_schedule_feature.h"
#include "df/general_ref_abstract_buildingst.h"
#include "df/general_ref_artifact.h"
#include "df/general_ref_dance_formst.h"
#include "df/general_ref_entity.h"
#include "df/general_ref_feature_layerst.h"
#include "df/general_ref_historical_eventst.h"
#include "df/general_ref_historical_figurest.h"
#include "df/general_ref_interactionst.h"
#include "df/general_ref_knowledge_scholar_flagst.h"
#include "df/general_ref_languagest.h"
#include "df/general_ref_musical_formst.h"
#include "df/general_ref_poetic_formst.h"
#include "df/general_ref_sitest.h"
#include "df/general_ref_subregionst.h"
#include "df/general_ref_value_levelst.h"
#include "df/general_ref_written_contentst.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/interaction.h"
#include "df/interaction_source.h"
#include "df/knowledge_scholar_category_flag.h"
#include "df/musical_form.h"
#include "df/poetic_form.h"
#include "df/world_region.h"
#include "df/world_site.h"
#include "df/world_underground_region.h"
#include "df/written_content.h"

void knowledge(std::ostream & s, df::knowledge_scholar_category_flag knowledge)
{
	using namespace df::enums::dfhack_knowledge_scholar_flag;

	BEFORE_SWITCH(know, knowledge.value());
	switch (know)
	{
	case philosophy_logic_formal_reasoning:
		s << "philosophy_logic_formal_reasoning"; // TODO
		BREAK(know);
	case philosophy_logic_deductive_reasoning:
		s << "philosophy_logic_deductive_reasoning"; // TODO
		BREAK(know);
	case philosophy_logic_syllogistic_logic:
		s << "philosophy_logic_syllogistic_logic"; // TODO
		BREAK(know);
	case philosophy_logic_hypothetical_syllogisms:
		s << "philosophy_logic_hypothetical_syllogisms"; // TODO
		BREAK(know);
	case philosophy_logic_propositional_logic:
		s << "philosophy_logic_propositional_logic"; // TODO
		BREAK(know);
	case philosophy_logic_dialectic_reasoning:
		s << "philosophy_logic_dialectic_reasoning"; // TODO
		BREAK(know);
	case philosophy_logic_analogical_inference:
		s << "philosophy_logic_analogical_inference"; // TODO
		BREAK(know);
	case philosophy_ethics_applied_medical:
		s << "philosophy_ethics_applied_medical"; // TODO
		BREAK(know);
	case philosophy_ethics_individual_value:
		s << "philosophy_ethics_individual_value"; // TODO
		BREAK(know);
	case philosophy_ethics_state_consequentialism:
		s << "philosophy_ethics_state_consequentialism"; // TODO
		BREAK(know);
	case philosophy_epistemology_truth:
		s << "philosophy_epistemology_truth"; // TODO
		BREAK(know);
	case philosophy_epistemology_perception:
		s << "philosophy_epistemology_perception"; // TODO
		BREAK(know);
	case philosophy_epistemology_justification:
		s << "philosophy_epistemology_justification"; // TODO
		BREAK(know);
	case philosophy_epistemology_belief:
		s << "philosophy_epistemology_belief"; // TODO
		BREAK(know);
	case philosophy_metaphysics_existence:
		s << "philosophy_metaphysics_existence"; // TODO
		BREAK(know);
	case philosophy_metaphysics_time:
		s << "philosophy_metaphysics_time"; // TODO
		BREAK(know);
	case philosophy_metaphysics_mind_body:
		s << "philosophy_metaphysics_mind_body"; // TODO
		BREAK(know);
	case philosophy_metaphysics_objects_and_properties:
		s << "philosophy_metaphysics_objects_and_properties"; // TODO
		BREAK(know);
	case philosophy_metaphysics_wholes_and_parts:
		s << "philosophy_metaphysics_wholes_and_parts"; // TODO
		BREAK(know);
	case philosophy_metaphysics_events:
		s << "philosophy_metaphysics_events"; // TODO
		BREAK(know);
	case philosophy_metaphysics_processes:
		s << "philosophy_metaphysics_processes"; // TODO
		BREAK(know);
	case philosophy_metaphysics_causation:
		s << "philosophy_metaphysics_causation"; // TODO
		BREAK(know);
	case philosophy_ethics_applied_military:
		s << "philosophy_ethics_applied_military"; // TODO
		BREAK(know);
	case philosophy_ethics_applied_interpersonal_conduct:
		s << "philosophy_ethics_applied_interpersonal_conduct"; // TODO
		BREAK(know);
	case philosophy_specialized_law:
		s << "philosophy_specialized_law"; // TODO
		BREAK(know);
	case philosophy_specialized_education:
		s << "philosophy_specialized_education"; // TODO
		BREAK(know);
	case philosophy_specialized_language_grammar:
		s << "philosophy_specialized_language_grammar"; // TODO
		BREAK(know);
	case philosophy_specialized_language_etymology:
		s << "philosophy_specialized_language_etymology"; // TODO
		BREAK(know);
	case philosophy_specialized_politics_diplomacy:
		s << "philosophy_specialized_politics_diplomacy"; // TODO
		BREAK(know);
	case philosophy_specialized_politics_government_forms:
		s << "philosophy_specialized_politics_government_forms"; // TODO
		BREAK(know);
	case philosophy_specialized_politics_economic_policy:
		s << "philosophy_specialized_politics_economic_policy"; // TODO
		BREAK(know);
	case philosophy_specialized_politics_social_welfare:
		s << "philosophy_specialized_politics_social_welfare"; // TODO
		BREAK(know);
	case philosophy_logic_inductive_reasoning:
		s << "philosophy_logic_inductive_reasoning"; // TODO
		BREAK(know);
	case philosophy_logic_direct_inference:
		s << "philosophy_logic_direct_inference"; // TODO
		BREAK(know);
	case philosophy_aesthetics_nature_of_beauty:
		s << "philosophy_aesthetics_nature_of_beauty"; // TODO
		BREAK(know);
	case philosophy_aesthetics_value_of_art:
		s << "philosophy_aesthetics_value_of_art"; // TODO
		BREAK(know);
	case philosophy_specialized_language_dictionary:
		s << "philosophy_specialized_language_dictionary"; // TODO
		BREAK(know);
	case mathematics_method_proof_by_contradiction:
		s << "mathematics_method_proof_by_contradiction"; // TODO
		BREAK(know);
	case mathematics_notation_zero:
		s << "mathematics_notation_zero"; // TODO
		BREAK(know);
	case mathematics_notation_negative_numbers:
		s << "mathematics_notation_negative_numbers"; // TODO
		BREAK(know);
	case mathematics_notation_large_numbers:
		s << "mathematics_notation_large_numbers"; // TODO
		BREAK(know);
	case mathematics_notation_positional:
		s << "mathematics_notation_positional"; // TODO
		BREAK(know);
	case mathematics_geometry_basic_objects:
		s << "mathematics_geometry_basic_objects"; // TODO
		BREAK(know);
	case mathematics_method_exhaustion:
		s << "mathematics_method_exhaustion"; // TODO
		BREAK(know);
	case mathematics_geometry_similar_and_congruent_triangles:
		s << "mathematics_geometry_similar_and_congruent_triangles"; // TODO
		BREAK(know);
	case mathematics_geometry_geometric_mean_theorem:
		s << "mathematics_geometry_geometric_mean_theorem"; // TODO
		BREAK(know);
	case mathematics_geometry_isosceles_base_angles_equal:
		s << "mathematics_geometry_isosceles_base_angles_equal"; // TODO
		BREAK(know);
	case mathematics_geometry_inscribed_triangle_on_diameter_is_right:
		s << "mathematics_geometry_inscribed_triangle_on_diameter_is_right"; // TODO
		BREAK(know);
	case mathematics_geometry_pythagorean_theorem:
		s << "mathematics_geometry_pythagorean_theorem"; // TODO
		BREAK(know);
	case mathematics_geometry_pythagorean_triples_small:
		s << "mathematics_geometry_pythagorean_triples_small"; // TODO
		BREAK(know);
	case mathematics_geometry_pythagorean_triples_3_digit:
		s << "mathematics_geometry_pythagorean_triples_3_digit"; // TODO
		BREAK(know);
	case mathematics_geometry_pythagorean_triples_4_digit:
		s << "mathematics_geometry_pythagorean_triples_4_digit"; // TODO
		BREAK(know);
	case mathematics_geometry_existence_of_incommensurable_ratios:
		s << "mathematics_geometry_existence_of_incommensurable_ratios"; // TODO
		BREAK(know);
	case mathematics_method_axiomatic_reasoning:
		s << "mathematics_method_axiomatic_reasoning"; // TODO
		BREAK(know);
	case mathematics_numbers_unique_prime_factorization:
		s << "mathematics_numbers_unique_prime_factorization"; // TODO
		BREAK(know);
	case mathematics_numbers_algorithm_for_computing_gcd:
		s << "mathematics_numbers_algorithm_for_computing_gcd"; // TODO
		BREAK(know);
	case mathematics_geometry_volume_of_pyramid:
		s << "mathematics_geometry_volume_of_pyramid"; // TODO
		BREAK(know);
	case mathematics_geometry_volume_of_cone:
		s << "mathematics_geometry_volume_of_cone"; // TODO
		BREAK(know);
	case mathematics_geometry_volume_of_sphere:
		s << "mathematics_geometry_volume_of_sphere"; // TODO
		BREAK(know);
	case mathematics_geometry_pi_to_4_digits:
		s << "mathematics_geometry_pi_to_4_digits"; // TODO
		BREAK(know);
	case mathematics_numbers_division_algorithm:
		s << "mathematics_numbers_division_algorithm"; // TODO
		BREAK(know);
	case mathematics_geometry_table_of_chord_values:
		s << "mathematics_geometry_table_of_chord_values"; // TODO
		BREAK(know);
	case mathematics_geometry_area_of_triangle_from_side_lengths:
		s << "mathematics_geometry_area_of_triangle_from_side_lengths"; // TODO
		BREAK(know);
	case mathematics_geometry_area_of_circle:
		s << "mathematics_geometry_area_of_circle"; // TODO
		BREAK(know);
	case mathematics_geometry_pi_to_6_digits:
		s << "mathematics_geometry_pi_to_6_digits"; // TODO
		BREAK(know);
	case mathematics_geometry_definitions_and_basic_properties_of_conic_sections:
		s << "mathematics_geometry_definitions_and_basic_properties_of_conic_sections"; // TODO
		BREAK(know);
	case mathematics_numbers_chinese_remainder_algorithm:
		s << "mathematics_numbers_chinese_remainder_algorithm"; // TODO
		BREAK(know);
	case mathematics_geometry_area_enclosed_by_line_and_parabola:
		s << "mathematics_geometry_area_enclosed_by_line_and_parabola"; // TODO
		BREAK(know);
	case mathematics_numbers_sieve_algorithm_for_primes:
		s << "mathematics_numbers_sieve_algorithm_for_primes"; // TODO
		BREAK(know);
	case mathematics_numbers_root_2_to_5_digits:
		s << "mathematics_numbers_root_2_to_5_digits"; // TODO
		BREAK(know);
	case mathematics_numbers_infinite_primes:
		s << "mathematics_numbers_infinite_primes"; // TODO
		BREAK(know);
	case mathematics_numbers_root_2_irrational:
		s << "mathematics_numbers_root_2_irrational"; // TODO
		BREAK(know);
	case mathematics_geometry_surface_area_of_sphere:
		s << "mathematics_geometry_surface_area_of_sphere"; // TODO
		BREAK(know);
	case mathematics_algebra_finite_summation_formulas:
		s << "mathematics_algebra_finite_summation_formulas"; // TODO
		BREAK(know);
	case mathematics_algebra_solving_linear_systems:
		s << "mathematics_algebra_solving_linear_systems"; // TODO
		BREAK(know);
	case mathematics_algebra_balancing_and_completion:
		s << "mathematics_algebra_balancing_and_completion"; // TODO
		BREAK(know);
	case mathematics_algebra_quadratic_by_completing_square:
		s << "mathematics_algebra_quadratic_by_completing_square"; // TODO
		BREAK(know);
	case mathematics_algebra_quadratic_formula:
		s << "mathematics_algebra_quadratic_formula"; // TODO
		BREAK(know);
	case mathematics_notation_syncopated_algebra:
		s << "mathematics_notation_syncopated_algebra"; // TODO
		BREAK(know);
	case mathematics_geometry_law_of_sines:
		s << "mathematics_geometry_law_of_sines"; // TODO
		BREAK(know);
	case mathematics_geometry_angle_sum_difference_trig_identities:
		s << "mathematics_geometry_angle_sum_difference_trig_identities"; // TODO
		BREAK(know);
	case mathematics_algebra_pascals_triangle:
		s << "mathematics_algebra_pascals_triangle"; // TODO
		BREAK(know);
	case mathematics_algebra_solving_higher_order_polynomials:
		s << "mathematics_algebra_solving_higher_order_polynomials"; // TODO
		BREAK(know);
	case mathematics_notation_early_symbols_for_operations:
		s << "mathematics_notation_early_symbols_for_operations"; // TODO
		BREAK(know);
	case mathematics_algebra_divergence_of_harmonic_series:
		s << "mathematics_algebra_divergence_of_harmonic_series"; // TODO
		BREAK(know);
	case mathematics_geometry_properties_of_chords:
		s << "mathematics_geometry_properties_of_chords"; // TODO
		BREAK(know);
	case history_sourcing_basic_reliability:
		s << "history_sourcing_basic_reliability"; // TODO
		BREAK(know);
	case history_sourcing_role_of_systemic_bias:
		s << "history_sourcing_role_of_systemic_bias"; // TODO
		BREAK(know);
	case history_sourcing_role_of_state_bias_and_propaganda:
		s << "history_sourcing_role_of_state_bias_and_propaganda"; // TODO
		BREAK(know);
	case history_sourcing_personal_interviews:
		s << "history_sourcing_personal_interviews"; // TODO
		BREAK(know);
	case history_theory_historical_causation:
		s << "history_theory_historical_causation"; // TODO
		BREAK(know);
	case history_theory_historical_cycles:
		s << "history_theory_historical_cycles"; // TODO
		BREAK(know);
	case history_theory_social_cohesion:
		s << "history_theory_social_cohesion"; // TODO
		BREAK(know);
	case history_theory_social_conflict:
		s << "history_theory_social_conflict"; // TODO
		BREAK(know);
	case history_form_biography:
		s << "history_form_biography"; // TODO
		BREAK(know);
	case history_form_comparative_biography:
		s << "history_form_comparative_biography"; // TODO
		BREAK(know);
	case history_form_biographical_dictionaries:
		s << "history_form_biographical_dictionaries"; // TODO
		BREAK(know);
	case history_form_autobiographical_adventure:
		s << "history_form_autobiographical_adventure"; // TODO
		BREAK(know);
	case history_form_genealogy:
		s << "history_form_genealogy"; // TODO
		BREAK(know);
	case history_form_encyclopedia:
		s << "history_form_encyclopedia"; // TODO
		BREAK(know);
	case history_form_cultural_history:
		s << "history_form_cultural_history"; // TODO
		BREAK(know);
	case history_form_cultural_comparison:
		s << "history_form_cultural_comparison"; // TODO
		BREAK(know);
	case history_sourcing_role_of_cultural_differences:
		s << "history_sourcing_role_of_cultural_differences"; // TODO
		BREAK(know);
	case history_form_alternate_history:
		s << "history_form_alternate_history"; // TODO
		BREAK(know);
	case history_sourcing_basic_archaeology:
		s << "history_sourcing_basic_archaeology"; // TODO
		BREAK(know);
	case history_form_treatise_on_tech_evolution:
		s << "history_form_treatise_on_tech_evolution"; // TODO
		BREAK(know);
	case astronomy_phases_of_the_moon:
		s << "astronomy_phases_of_the_moon"; // TODO
		BREAK(know);
	case astronomy_summer_winter_moon:
		s << "astronomy_summer_winter_moon"; // TODO
		BREAK(know);
	case astronomy_path_of_the_moon:
		s << "astronomy_path_of_the_moon"; // TODO
		BREAK(know);
	case astronomy_tides_and_the_moon:
		s << "astronomy_tides_and_the_moon"; // TODO
		BREAK(know);
	case astronomy_height_of_tides_vs_moon_and_sun:
		s << "astronomy_height_of_tides_vs_moon_and_sun"; // TODO
		BREAK(know);
	case astronomy_summer_winter_sun:
		s << "astronomy_summer_winter_sun"; // TODO
		BREAK(know);
	case astronomy_relationship_between_lunar_solar_year:
		s << "astronomy_relationship_between_lunar_solar_year"; // TODO
		BREAK(know);
	case astronomy_daylight_variation_with_solar_year:
		s << "astronomy_daylight_variation_with_solar_year"; // TODO
		BREAK(know);
	case astronomy_geocentric_model:
		s << "astronomy_geocentric_model"; // TODO
		BREAK(know);
	case astronomy_heliocentric_model:
		s << "astronomy_heliocentric_model"; // TODO
		BREAK(know);
	case astronomy_dates_of_lunar_and_solar_eclipses:
		s << "astronomy_dates_of_lunar_and_solar_eclipses"; // TODO
		BREAK(know);
	case astronomy_star_charts:
		s << "astronomy_star_charts"; // TODO
		BREAK(know);
	case astronomy_star_catalogues_100:
		s << "astronomy_star_catalogues_100"; // TODO
		BREAK(know);
	case astronomy_star_catalogues_1000:
		s << "astronomy_star_catalogues_1000"; // TODO
		BREAK(know);
	case astronomy_star_color_classification:
		s << "astronomy_star_color_classification"; // TODO
		BREAK(know);
	case astronomy_star_magnitude_classification:
		s << "astronomy_star_magnitude_classification"; // TODO
		BREAK(know);
	case astronomy_shape_of_the_world:
		s << "astronomy_shape_of_the_world"; // TODO
		BREAK(know);
	case astronomy_precession_of_equinoxes:
		s << "astronomy_precession_of_equinoxes"; // TODO
		BREAK(know);
	case astronomy_method_empirical_observation:
		s << "astronomy_method_empirical_observation"; // TODO
		BREAK(know);
	case astronomy_method_path_models:
		s << "astronomy_method_path_models"; // TODO
		BREAK(know);
	case naturalist_method_dissection:
		s << "naturalist_method_dissection"; // TODO
		BREAK(know);
	case naturalist_observation_anatomy:
		s << "naturalist_observation_anatomy"; // TODO
		BREAK(know);
	case naturalist_theory_comparative_anatomy:
		s << "naturalist_theory_comparative_anatomy"; // TODO
		BREAK(know);
	case naturalist_theory_classification_by_physical_features:
		s << "naturalist_theory_classification_by_physical_features"; // TODO
		BREAK(know);
	case naturalist_observation_migration_patterns:
		s << "naturalist_observation_migration_patterns"; // TODO
		BREAK(know);
	case naturalist_observation_reproductive_behavior:
		s << "naturalist_observation_reproductive_behavior"; // TODO
		BREAK(know);
	case naturalist_observation_foraging_behavior_and_diet:
		s << "naturalist_observation_foraging_behavior_and_diet"; // TODO
		BREAK(know);
	case naturalist_theory_food_chain:
		s << "naturalist_theory_food_chain"; // TODO
		BREAK(know);
	case naturalist_observation_social_behavior:
		s << "naturalist_observation_social_behavior"; // TODO
		BREAK(know);
	case naturalist_observation_diseases:
		s << "naturalist_observation_diseases"; // TODO
		BREAK(know);
	case naturalist_theory_climactic_adaptation:
		s << "naturalist_theory_climactic_adaptation"; // TODO
		BREAK(know);
	case naturalist_observation_embriological_development:
		s << "naturalist_observation_embriological_development"; // TODO
		BREAK(know);
	case naturalist_theory_struggle_for_existence:
		s << "naturalist_theory_struggle_for_existence"; // TODO
		BREAK(know);
	case chemistry_classification_combustibles:
		s << "chemistry_classification_combustibles"; // TODO
		BREAK(know);
	case chemistry_classification_ores:
		s << "chemistry_classification_ores"; // TODO
		BREAK(know);
	case chemistry_metallurgy_alloys:
		s << "chemistry_metallurgy_alloys"; // TODO
		BREAK(know);
	case chemistry_classification_scratch_test:
		s << "chemistry_classification_scratch_test"; // TODO
		BREAK(know);
	case chemistry_classification_elemental_theory:
		s << "chemistry_classification_elemental_theory"; // TODO
		BREAK(know);
	case chemistry_chemicals_adhesives:
		s << "chemistry_chemicals_adhesives"; // TODO
		BREAK(know);
	case chemistry_laboratory_blast_furnace:
		s << "chemistry_laboratory_blast_furnace"; // TODO
		BREAK(know);
	case chemistry_laboratory_alembic:
		s << "chemistry_laboratory_alembic"; // TODO
		BREAK(know);
	case chemistry_laboratory_theory_of_liquid_liquid_extraction:
		s << "chemistry_laboratory_theory_of_liquid_liquid_extraction"; // TODO
		BREAK(know);
	case chemistry_laboratory_theory_of_distillation:
		s << "chemistry_laboratory_theory_of_distillation"; // TODO
		BREAK(know);
	case chemistry_laboratory_theory_of_evaporation:
		s << "chemistry_laboratory_theory_of_evaporation"; // TODO
		BREAK(know);
	case chemistry_classification_alkali_and_acids:
		s << "chemistry_classification_alkali_and_acids"; // TODO
		BREAK(know);
	case chemistry_laboratory_systematic_experiments:
		s << "chemistry_laboratory_systematic_experiments"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_flask:
		s << "chemistry_laboratory_glass_flask"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_beaker:
		s << "chemistry_laboratory_glass_beaker"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_vial:
		s << "chemistry_laboratory_glass_vial"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_funnel:
		s << "chemistry_laboratory_glass_funnel"; // TODO
		BREAK(know);
	case chemistry_laboratory_crucible:
		s << "chemistry_laboratory_crucible"; // TODO
		BREAK(know);
	case chemistry_chemicals_nitric_acid:
		s << "chemistry_chemicals_nitric_acid"; // TODO
		BREAK(know);
	case chemistry_chemicals_sulfuric_acid:
		s << "chemistry_chemicals_sulfuric_acid"; // TODO
		BREAK(know);
	case chemistry_chemicals_aqua_regia:
		s << "chemistry_chemicals_aqua_regia"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_ampoule:
		s << "chemistry_laboratory_glass_ampoule"; // TODO
		BREAK(know);
	case chemistry_laboratory_glass_retort:
		s << "chemistry_laboratory_glass_retort"; // TODO
		BREAK(know);
	case chemistry_laboratory_lab_ovens:
		s << "chemistry_laboratory_lab_ovens"; // TODO
		BREAK(know);
	case geography_surveying_basic:
		s << "geography_surveying_basic"; // TODO
		BREAK(know);
	case geography_surveying_staff:
		s << "geography_surveying_staff"; // TODO
		BREAK(know);
	case geography_cartography_basic:
		s << "geography_cartography_basic"; // TODO
		BREAK(know);
	case geography_surveying_triangulation:
		s << "geography_surveying_triangulation"; // TODO
		BREAK(know);
	case geography_surveying_cartographical:
		s << "geography_surveying_cartographical"; // TODO
		BREAK(know);
	case geography_surveying_land:
		s << "geography_surveying_land"; // TODO
		BREAK(know);
	case geography_surveying_military:
		s << "geography_surveying_military"; // TODO
		BREAK(know);
	case geography_surveying_engineering:
		s << "geography_surveying_engineering"; // TODO
		BREAK(know);
	case geography_cartography_geological:
		s << "geography_cartography_geological"; // TODO
		BREAK(know);
	case geography_cartography_grid_system:
		s << "geography_cartography_grid_system"; // TODO
		BREAK(know);
	case geography_cartography_distance_scale:
		s << "geography_cartography_distance_scale"; // TODO
		BREAK(know);
	case geography_cartography_height_measurements:
		s << "geography_cartography_height_measurements"; // TODO
		BREAK(know);
	case geography_method_economic_data_collection:
		s << "geography_method_economic_data_collection"; // TODO
		BREAK(know);
	case geography_cartography_economic:
		s << "geography_cartography_economic"; // TODO
		BREAK(know);
	case geography_form_atlas:
		s << "geography_form_atlas"; // TODO
		BREAK(know);
	case geography_theory_delta_formation:
		s << "geography_theory_delta_formation"; // TODO
		BREAK(know);
	case geography_theory_wind_patterns:
		s << "geography_theory_wind_patterns"; // TODO
		BREAK(know);
	case geography_theory_origin_of_rainfall_from_evap_condense:
		s << "geography_theory_origin_of_rainfall_from_evap_condense"; // TODO
		BREAK(know);
	case geography_theory_water_cycle:
		s << "geography_theory_water_cycle"; // TODO
		BREAK(know);
	case geography_theory_latitude_climate_zones:
		s << "geography_theory_latitude_climate_zones"; // TODO
		BREAK(know);
	case geography_cartography_accurate_maps:
		s << "geography_cartography_accurate_maps"; // TODO
		BREAK(know);
	case geography_cartography_map_projections:
		s << "geography_cartography_map_projections"; // TODO
		BREAK(know);
	case medicine_theory_disease_and_fouled_water:
		s << "medicine_theory_disease_and_fouled_water"; // TODO
		BREAK(know);
	case medicine_method_physical_examination:
		s << "medicine_method_physical_examination"; // TODO
		BREAK(know);
	case medicine_method_autopsy:
		s << "medicine_method_autopsy"; // TODO
		BREAK(know);
	case medicine_theory_prognosis:
		s << "medicine_theory_prognosis"; // TODO
		BREAK(know);
	case medicine_tool_herbal_remedies:
		s << "medicine_tool_herbal_remedies"; // TODO
		BREAK(know);
	case medicine_tool_animal_remedies:
		s << "medicine_tool_animal_remedies"; // TODO
		BREAK(know);
	case medicine_tool_mineral_remedies:
		s << "medicine_tool_mineral_remedies"; // TODO
		BREAK(know);
	case medicine_tool_bandages:
		s << "medicine_tool_bandages"; // TODO
		BREAK(know);
	case medicine_theory_disease_classification:
		s << "medicine_theory_disease_classification"; // TODO
		BREAK(know);
	case medicine_theory_toxicology:
		s << "medicine_theory_toxicology"; // TODO
		BREAK(know);
	case medicine_theory_acute_and_chronic_conditions:
		s << "medicine_theory_acute_and_chronic_conditions"; // TODO
		BREAK(know);
	case medicine_theory_endemic_disease:
		s << "medicine_theory_endemic_disease"; // TODO
		BREAK(know);
	case medicine_theory_epidemic_disease:
		s << "medicine_theory_epidemic_disease"; // TODO
		BREAK(know);
	case medicine_theory_exacerbation:
		s << "medicine_theory_exacerbation"; // TODO
		BREAK(know);
	case medicine_theory_paroxysm:
		s << "medicine_theory_paroxysm"; // TODO
		BREAK(know);
	case medicine_theory_relapse:
		s << "medicine_theory_relapse"; // TODO
		BREAK(know);
	case medicine_theory_convalescence:
		s << "medicine_theory_convalescence"; // TODO
		BREAK(know);
	case medicine_method_treatment_of_traumatic_injuries:
		s << "medicine_method_treatment_of_traumatic_injuries"; // TODO
		BREAK(know);
	case medicine_method_fracture_treatment:
		s << "medicine_method_fracture_treatment"; // TODO
		BREAK(know);
	case medicine_theory_fracture_classification:
		s << "medicine_theory_fracture_classification"; // TODO
		BREAK(know);
	case medicine_tool_traction_bench:
		s << "medicine_tool_traction_bench"; // TODO
		BREAK(know);
	case medicine_method_fracture_immobilization:
		s << "medicine_method_fracture_immobilization"; // TODO
		BREAK(know);
	case medicine_tool_orthopedic_cast:
		s << "medicine_tool_orthopedic_cast"; // TODO
		BREAK(know);
	case medicine_method_surgery_excision:
		s << "medicine_method_surgery_excision"; // TODO
		BREAK(know);
	case medicine_method_surgery_incision:
		s << "medicine_method_surgery_incision"; // TODO
		BREAK(know);
	case medicine_method_hernia_surgery:
		s << "medicine_method_hernia_surgery"; // TODO
		BREAK(know);
	case medicine_method_tracheotomy_surgery:
		s << "medicine_method_tracheotomy_surgery"; // TODO
		BREAK(know);
	case medicine_method_lithotomy_surgery:
		s << "medicine_method_lithotomy_surgery"; // TODO
		BREAK(know);
	case medicine_method_surgery_scraping:
		s << "medicine_method_surgery_scraping"; // TODO
		BREAK(know);
	case medicine_method_surgery_draining:
		s << "medicine_method_surgery_draining"; // TODO
		BREAK(know);
	case medicine_method_surgery_probing:
		s << "medicine_method_surgery_probing"; // TODO
		BREAK(know);
	case medicine_method_surgery_suturing:
		s << "medicine_method_surgery_suturing"; // TODO
		BREAK(know);
	case medicine_method_surgery_ligature:
		s << "medicine_method_surgery_ligature"; // TODO
		BREAK(know);
	case medicine_theory_surgical_models:
		s << "medicine_theory_surgical_models"; // TODO
		BREAK(know);
	case medicine_tool_mud_bags_as_surgical_models:
		s << "medicine_tool_mud_bags_as_surgical_models"; // TODO
		BREAK(know);
	case medicine_tool_plants_as_surgical_models:
		s << "medicine_tool_plants_as_surgical_models"; // TODO
		BREAK(know);
	case medicine_tool_animals_as_surgical_models:
		s << "medicine_tool_animals_as_surgical_models"; // TODO
		BREAK(know);
	case medicine_theory_specialized_surgical_instruments:
		s << "medicine_theory_specialized_surgical_instruments"; // TODO
		BREAK(know);
	case medicine_tool_forceps:
		s << "medicine_tool_forceps"; // TODO
		BREAK(know);
	case medicine_tool_scalpel:
		s << "medicine_tool_scalpel"; // TODO
		BREAK(know);
	case medicine_tool_surgical_scissors:
		s << "medicine_tool_surgical_scissors"; // TODO
		BREAK(know);
	case medicine_tool_surgical_needles:
		s << "medicine_tool_surgical_needles"; // TODO
		BREAK(know);
	case medicine_method_cataract_surgery:
		s << "medicine_method_cataract_surgery"; // TODO
		BREAK(know);
	case medicine_method_cauterization:
		s << "medicine_method_cauterization"; // TODO
		BREAK(know);
	case medicine_method_anesthesia:
		s << "medicine_method_anesthesia"; // TODO
		BREAK(know);
	case medicine_theory_pulmonary_medicine:
		s << "medicine_theory_pulmonary_medicine"; // TODO
		BREAK(know);
	case medicine_theory_anatomical_studies:
		s << "medicine_theory_anatomical_studies"; // TODO
		BREAK(know);
	case medicine_theory_classification_of_bodily_fluids:
		s << "medicine_theory_classification_of_bodily_fluids"; // TODO
		BREAK(know);
	case medicine_theory_eye_anatomy:
		s << "medicine_theory_eye_anatomy"; // TODO
		BREAK(know);
	case medicine_theory_motor_vs_sensory_nerves:
		s << "medicine_theory_motor_vs_sensory_nerves"; // TODO
		BREAK(know);
	case medicine_theory_nervous_system_function:
		s << "medicine_theory_nervous_system_function"; // TODO
		BREAK(know);
	case medicine_theory_reaction_time:
		s << "medicine_theory_reaction_time"; // TODO
		BREAK(know);
	case medicine_theory_blood_vessels:
		s << "medicine_theory_blood_vessels"; // TODO
		BREAK(know);
	case medicine_theory_pulmonary_circulation:
		s << "medicine_theory_pulmonary_circulation"; // TODO
		BREAK(know);
	case medicine_theory_comparative_anatomy:
		s << "medicine_theory_comparative_anatomy"; // TODO
		BREAK(know);
	case medicine_theory_the_voice:
		s << "medicine_theory_the_voice"; // TODO
		BREAK(know);
	case medicine_theory_classification_of_muscles:
		s << "medicine_theory_classification_of_muscles"; // TODO
		BREAK(know);
	case medicine_theory_classification_of_mental_illnesses:
		s << "medicine_theory_classification_of_mental_illnesses"; // TODO
		BREAK(know);
	case medicine_theory_treatment_of_mental_illnesses:
		s << "medicine_theory_treatment_of_mental_illnesses"; // TODO
		BREAK(know);
	case medicine_tool_dedicated_hospitals:
		s << "medicine_tool_dedicated_hospitals"; // TODO
		BREAK(know);
	case medicine_method_professional_hospital_staff:
		s << "medicine_method_professional_hospital_staff"; // TODO
		BREAK(know);
	case medicine_method_specialized_wards:
		s << "medicine_method_specialized_wards"; // TODO
		BREAK(know);
	case medicine_method_hospital_lab:
		s << "medicine_method_hospital_lab"; // TODO
		BREAK(know);
	case medicine_method_medical_school:
		s << "medicine_method_medical_school"; // TODO
		BREAK(know);
	case medicine_method_asylum_for_mentally_ill:
		s << "medicine_method_asylum_for_mentally_ill"; // TODO
		BREAK(know);
	case engineering_horology_shadow_clock:
		s << "engineering_horology_shadow_clock"; // TODO
		BREAK(know);
	case engineering_horology_water_clock:
		s << "engineering_horology_water_clock"; // TODO
		BREAK(know);
	case engineering_horology_conical_water_clock:
		s << "engineering_horology_conical_water_clock"; // TODO
		BREAK(know);
	case engineering_horology_water_clock_reservoir:
		s << "engineering_horology_water_clock_reservoir"; // TODO
		BREAK(know);
	case engineering_horology_astrarium:
		s << "engineering_horology_astrarium"; // TODO
		BREAK(know);
	case engineering_horology_hourglass:
		s << "engineering_horology_hourglass"; // TODO
		BREAK(know);
	case engineering_horology_mechanical_clock:
		s << "engineering_horology_mechanical_clock"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_pulley:
		s << "engineering_machine_theory_of_pulley"; // TODO
		BREAK(know);
	case engineering_machine_pulley:
		s << "engineering_machine_pulley"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_screw:
		s << "engineering_machine_theory_of_screw"; // TODO
		BREAK(know);
	case engineering_machine_screw:
		s << "engineering_machine_screw"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_wheel_and_axle:
		s << "engineering_machine_theory_of_wheel_and_axle"; // TODO
		BREAK(know);
	case engineering_machine_windlass:
		s << "engineering_machine_windlass"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_wedge:
		s << "engineering_machine_theory_of_wedge"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_lever:
		s << "engineering_machine_theory_of_lever"; // TODO
		BREAK(know);
	case engineering_machine_lever:
		s << "engineering_machine_lever"; // TODO
		BREAK(know);
	case engineering_machine_straight_beam_balance:
		s << "engineering_machine_straight_beam_balance"; // TODO
		BREAK(know);
	case engineering_machine_theory_of_gears:
		s << "engineering_machine_theory_of_gears"; // TODO
		BREAK(know);
	case engineering_machine_warded_lock:
		s << "engineering_machine_warded_lock"; // TODO
		BREAK(know);
	case engineering_machine_tumbler_lock:
		s << "engineering_machine_tumbler_lock"; // TODO
		BREAK(know);
	case engineering_machine_padlock:
		s << "engineering_machine_padlock"; // TODO
		BREAK(know);
	case engineering_machine_camshaft:
		s << "engineering_machine_camshaft"; // TODO
		BREAK(know);
	case engineering_machine_crankshaft:
		s << "engineering_machine_crankshaft"; // TODO
		BREAK(know);
	case engineering_machine_water_powered_sawmill:
		s << "engineering_machine_water_powered_sawmill"; // TODO
		BREAK(know);
	case engineering_machine_chariot_odometer:
		s << "engineering_machine_chariot_odometer"; // TODO
		BREAK(know);
	case engineering_machine_chain_drive:
		s << "engineering_machine_chain_drive"; // TODO
		BREAK(know);
	case engineering_machine_mechanical_compass:
		s << "engineering_machine_mechanical_compass"; // TODO
		BREAK(know);
	case engineering_machine_differential_gear:
		s << "engineering_machine_differential_gear"; // TODO
		BREAK(know);
	case engineering_machine_combination_lock:
		s << "engineering_machine_combination_lock"; // TODO
		BREAK(know);
	case engineering_machine_verge_escapement:
		s << "engineering_machine_verge_escapement"; // TODO
		BREAK(know);
	case engineering_machine_balance_wheel:
		s << "engineering_machine_balance_wheel"; // TODO
		BREAK(know);
	case engineering_fluid_theory_of_siphon:
		s << "engineering_fluid_theory_of_siphon"; // TODO
		BREAK(know);
	case engineering_fluid_valves:
		s << "engineering_fluid_valves"; // TODO
		BREAK(know);
	case engineering_fluid_force_pump:
		s << "engineering_fluid_force_pump"; // TODO
		BREAK(know);
	case engineering_optics_crystal_lens:
		s << "engineering_optics_crystal_lens"; // TODO
		BREAK(know);
	case engineering_optics_water_filled_spheres:
		s << "engineering_optics_water_filled_spheres"; // TODO
		BREAK(know);
	case engineering_optics_glass_lens:
		s << "engineering_optics_glass_lens"; // TODO
		BREAK(know);
	case engineering_optics_camera_obscura:
		s << "engineering_optics_camera_obscura"; // TODO
		BREAK(know);
	case engineering_optics_parabolic_mirror:
		s << "engineering_optics_parabolic_mirror"; // TODO
		BREAK(know);
	case engineering_optics_theory_of_color:
		s << "engineering_optics_theory_of_color"; // TODO
		BREAK(know);
	case engineering_optics_theory_of_rainbows:
		s << "engineering_optics_theory_of_rainbows"; // TODO
		BREAK(know);
	case engineering_optics_law_of_refraction:
		s << "engineering_optics_law_of_refraction"; // TODO
		BREAK(know);
	case engineering_design_models_and_templates:
		s << "engineering_design_models_and_templates"; // TODO
		BREAK(know);
	case engineering_construction_wood_lamination:
		s << "engineering_construction_wood_lamination"; // TODO
		BREAK(know);
	case engineering_astronomy_dioptra:
		s << "engineering_astronomy_dioptra"; // TODO
		BREAK(know);
	case engineering_astronomy_astrolabe:
		s << "engineering_astronomy_astrolabe"; // TODO
		BREAK(know);
	case engineering_astronomy_armillary_sphere:
		s << "engineering_astronomy_armillary_sphere"; // TODO
		BREAK(know);
	case engineering_astronomy_spherical_astrolabe:
		s << "engineering_astronomy_spherical_astrolabe"; // TODO
		BREAK(know);
	case engineering_astronomy_mural_instrument:
		s << "engineering_astronomy_mural_instrument"; // TODO
		BREAK(know);
	case engineering_astronomy_orrery:
		s << "engineering_astronomy_orrery"; // TODO
		BREAK(know);
	case engineering_machine_water_powered_trip_hammer:
		s << "engineering_machine_water_powered_trip_hammer"; // TODO
		BREAK(know);
	case engineering_machine_double_acting_piston_bellows:
		s << "engineering_machine_double_acting_piston_bellows"; // TODO
		BREAK(know);
	case engineering_fluid_archimedes_principle:
		s << "engineering_fluid_archimedes_principle"; // TODO
		BREAK(know);
	case engineering_optics_atmospheric_refraction:
		s << "engineering_optics_atmospheric_refraction"; // TODO
		BREAK(know);
	case engineering_optics_cause_of_twilight:
		s << "engineering_optics_cause_of_twilight"; // TODO
		BREAK(know);
	case engineering_optics_height_of_atmosphere:
		s << "engineering_optics_height_of_atmosphere"; // TODO
		BREAK(know);
	case engineering_machine_piston:
		s << "engineering_machine_piston"; // TODO
		BREAK(know);
	case engineering_machine_crank:
		s << "engineering_machine_crank"; // TODO
		BREAK(know);
	case engineering_machine_bellows:
		s << "engineering_machine_bellows"; // TODO
		BREAK(know);
	case engineering_machine_water_powered_piston_bellows:
		s << "engineering_machine_water_powered_piston_bellows"; // TODO
		BREAK(know);
	case engineering_machine_water_wheel:
		s << "engineering_machine_water_wheel"; // TODO
		BREAK(know);
	case engineering_machine_trip_hammer:
		s << "engineering_machine_trip_hammer"; // TODO
		BREAK(know);
	}
	AFTER_SWITCH(know, stl_sprintf("category-%d/flag-%032b", knowledge.category, knowledge.flags));
}

void value_level(std::ostream & s, df::value_type type, int32_t level)
{
	BEFORE_SWITCH(value, type);
	switch (value)
	{
	case value_type::LAW:
		if (level > 40)
		{
			s << "is an absolute believer in the rule of law";
		}
		else if (level > 25)
		{
			s << "has a great deal of respect for the law";
		}
		else if (level > 10)
		{
			s << "respects the law";
		}
		else if (level >= -10)
		{
			s << "doesn't feel strongly about the law";
		}
		else if (level >= -25)
		{
			s << "does not respect the law";
		}
		else if (level >= -40)
		{
			s << "disdains the law";
		}
		else
		{
			s << "finds the idea of laws abhorent";
		}
		BREAK(value);
	case value_type::LOYALTY:
		if (level > 40)
		{
			s << "has the highest regard for loyalty";
		}
		else if (level > 25)
		{
			s << "greatly prizes loyalty";
		}
		else if (level > 10)
		{
			s << "values loyalty";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly value loyalty";
		}
		else if (level >= -25)
		{
			s << "views loyalty unfavorably";
		}
		else if (level >= -40)
		{
			s << "disdains loyalty";
		}
		else
		{
			s << "is disgusted by the idea of loyalty";
		}
		BREAK(value);
	case value_type::FAMILY:
		if (level > 40)
		{
			s << "sees family as one of the most important things in life";
		}
		else if (level > 25)
		{
			s << "values family greatly";
		}
		else if (level > 10)
		{
			s << "values family";
		}
		else if (level >= -10)
		{
			s << "does not care about family one way or the other";
		}
		else if (level >= -25)
		{
			s << "is put off by family";
		}
		else if (level >= -40)
		{
			s << "lacks any respect for family";
		}
		else
		{
			s << "finds the idea of family loathsome";
		}
		BREAK(value);
	case value_type::FRIENDSHIP:
		if (level > 40)
		{
			s << "believes friendship is a key to the ideal life";
		}
		else if (level > 25)
		{
			s << "sees friendship as one of the finer things in life";
		}
		else if (level > 10)
		{
			s << "thinks friendship is important";
		}
		else if (level >= -10)
		{
			s << "does not care about friendship";
		}
		else if (level >= -25)
		{
			s << "finds friendship burdensome";
		}
		else if (level >= -40)
		{
			s << "is completely put off by the idea of friends";
		}
		else
		{
			s << "finds the whole idea of friendship disgusting";
		}
		BREAK(value);
	case value_type::POWER:
		if (level > 40)
		{
			s << "believes that the acquisition of power over others is the ideal goal in life and worthy of the highest respect";
		}
		else if (level > 25)
		{
			s << "sees power over others as something to strive for";
		}
		else if (level > 10)
		{
			s << "respects power";
		}
		else if (level >= -10)
		{
			s << "doesn't find power particularly praiseworthy";
		}
		else if (level >= -25)
		{
			s << "has a negative view of those who exercise power over others";
		}
		else if (level >= -40)
		{
			s << "hates those who wield power over others";
		}
		else
		{
			s << "finds the acquisition and use of power abhorent and would have all masters toppled";
		}
		BREAK(value);
	case value_type::TRUTH:
		if (level > 40)
		{
			s << "believes the truth is inviolable regardless of the cost";
		}
		else if (level > 25)
		{
			s << "believes that honesty is a high ideal";
		}
		else if (level > 10)
		{
			s << "values honesty";
		}
		else if (level >= -10)
		{
			s << "does not particularly value the truth";
		}
		else if (level >= -25)
		{
			s << "finds blind honesty foolish";
		}
		else if (level >= -40)
		{
			s << "sees lying as an important means to an end";
		}
		else
		{
			s << "is repelled by the idea of honesty and lies without compunction";
		}
		BREAK(value);
	case value_type::CUNNING:
		if (level > 40)
		{
			s << "holds well-laid plans and shrewd deceptions in the highest regard";
		}
		else if (level > 25)
		{
			s << "greatly respects the shrewd and guileful";
		}
		else if (level > 10)
		{
			s << "values cunning";
		}
		else if (level >= -10)
		{
			s << "does not really value cunning and guile";
		}
		else if (level >= -25)
		{
			s << "sees guile and cunning as indirect and somewhat worthless";
		}
		else if (level >= -40)
		{
			s << "holds shrewd and crafty individuals in the lowest esteem";
		}
		else
		{
			s << "is utterly disgusted by guile and cunning";
		}
		BREAK(value);
	case value_type::ELOQUENCE:
		if (level > 40)
		{
			s << "believes that artful speech and eloquent expression are of the highest ideals";
		}
		else if (level > 25)
		{
			s << "deeply respects eloquent speakers";
		}
		else if (level > 10)
		{
			s << "values eloquence";
		}
		else if (level >= -10)
		{
			s << "doesn't value eloquence so much";
		}
		else if (level >= -25)
		{
			s << "finds eloquence and artful speech off-putting";
		}
		else if (level >= -40)
		{
			s << "finds [him/her]self somewhat disgusted with eloquent speakers";
		}
		else
		{
			s << "sees artful speech and eloquence as a wasteful form of deliberate deception and treats it as such";
		}
		BREAK(value);
	case value_type::FAIRNESS:
		if (level > 40)
		{
			s << "holds fairness as one of the highest ideals and despises cheating of any kind";
		}
		else if (level > 25)
		{
			s << "has great respect for fairness";
		}
		else if (level > 10)
		{
			s << "respects fair-dealing and fair-play";
		}
		else if (level >= -10)
		{
			s << "does not care about fairness";
		}
		else if (level >= -25)
		{
			s << "sees life as unfair and doesn't mind it that way";
		}
		else if (level >= -40)
		{
			s << "finds the idea of fair-dealing foolish and cheats when [he/she] finds it profitable";
		}
		else
		{
			s << "is disgusted by the idea of fairness and will freely cheat anybody at any time";
		}
		BREAK(value);
	case value_type::DECORUM:
		if (level > 40)
		{
			s << "views decorum as a high ideal and is deeply offended by those that fail to maintain it";
		}
		else if (level > 25)
		{
			s << "greatly respects those that observe decorum and maintain their dignity";
		}
		else if (level > 10)
		{
			s << "values decorum, dignity and proper behavior";
		}
		else if (level >= -10)
		{
			s << "doesn't care very much about decorum";
		}
		else if (level >= -25)
		{
			s << "finds maintaining decorum a silly, fumbling waste of time";
		}
		else if (level >= -40)
		{
			s << "sees those that attempt to maintain dignified and proper behavior as vain and offensive";
		}
		else
		{
			s << "is affronted by the whole notion of maintaining decorum and finds so-called dignified people disgusting";
		}
		BREAK(value);
	case value_type::TRADITION:
		if (level > 40)
		{
			s << "holds the maintenance of tradition as one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "is a firm believer in the value of tradition";
		}
		else if (level > 10)
		{
			s << "values tradition";
		}
		else if (level >= -10)
		{
			s << "doesn't have any strong feelings about tradition";
		}
		else if (level >= -25)
		{
			s << "disregards tradition";
		}
		else if (level >= -40)
		{
			s << "finds the following of tradition foolish and limiting";
		}
		else
		{
			s << "is disgusted by tradition and would flout any [he/she] encounters if given a chance";
		}
		BREAK(value);
	case value_type::ARTWORK:
		if (level > 40)
		{
			s << "believes that the creation and appreciation of artwork is one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "greatly respects artists and their works";
		}
		else if (level > 10)
		{
			s << "values artwork";
		}
		else if (level >= -10)
		{
			s << "doesn't care about art one way or another";
		}
		else if (level >= -25)
		{
			s << "finds artwork boring";
		}
		else if (level >= -40)
		{
			s << "sees the whole pursuit of art as silly";
		}
		else
		{
			s << "finds art offensive and would have it destroyed whenever possible";
		}
		BREAK(value);
	case value_type::COOPERATION:
		if (level > 40)
		{
			s << "places cooperation as one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "sees cooperation as very important in life";
		}
		else if (level > 10)
		{
			s << "values cooperation";
		}
		else if (level >= -10)
		{
			s << "doesn't see cooperation as valuable";
		}
		else if (level >= -25)
		{
			s << "dislikes cooperation";
		}
		else if (level >= -40)
		{
			s << "views cooperation as a low ideal not worthy of any respect";
		}
		else
		{
			s << "is thoroughly disgusted by cooperation";
		}
		BREAK(value);
	case value_type::INDEPENDENCE:
		if (level > 40)
		{
			s << "believes that freedom and independence are completely non-negotiable and would fight to defend them";
		}
		else if (level > 25)
		{
			s << "treasures independence";
		}
		else if (level > 10)
		{
			s << "values independence";
		}
		else if (level >= -10)
		{
			s << "doesn't really value independence one way or another";
		}
		else if (level >= -25)
		{
			s << "finds the ideas of independence and freedom somewhat foolish";
		}
		else if (level >= -40)
		{
			s << "sees freedom and independence as completely worthless";
		}
		else
		{
			s << "hates freedom and would crush the independent spirit wherever it is found";
		}
		BREAK(value);
	case value_type::STOICISM:
		if (level > 40)
		{
			s << "views any show of emotion as offensive";
		}
		else if (level > 25)
		{
			s << "thinks it is of the utmost importance to present a bold face and never grouse, complain or even show emotion";
		}
		else if (level > 10)
		{
			s << "believes it is important to conceal emotions and refrain from complaining";
		}
		else if (level >= -10)
		{
			s << "doesn't see much value in being stoic";
		}
		else if (level >= -25)
		{
			s << "sees no value in holding back complaints and concealing emotions";
		}
		else if (level >= -40)
		{
			s << "feels that those who attempt to conceal their emotions are vain and foolish";
		}
		else
		{
			s << "sees concealment of emotions as a betrayal and tries [his/her] best never to associate with such secretive fools";
		}
		BREAK(value);
	case value_type::INTROSPECTION:
		if (level > 40)
		{
			s << "feels that introspection and all forms of self-examination are the keys to a good life and worthy of respect";
		}
		else if (level > 25)
		{
			s << "deeply values introspection";
		}
		else if (level > 10)
		{
			s << "sees introspection as important";
		}
		else if (level >= -10)
		{
			s << "doesn't really see the value in self-examination";
		}
		else if (level >= -25)
		{
			s << "finds introspection to be a waste of time";
		}
		else if (level >= -40)
		{
			s << "thinks that introspection is valueless and those that waste time in self-examination are deluded fools";
		}
		else
		{
			s << "finds the whole idea of introspection completely offensive and contrary to the ideals of a life well-lived";
		}
		BREAK(value);
	case value_type::SELF_CONTROL:
		if (level > 40)
		{
			s << "believes that self-mastery and the denial of impulses are of the highest ideals";
		}
		else if (level > 25)
		{
			s << "finds moderation and self-control to be very important";
		}
		else if (level > 10)
		{
			s << "values self-control";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly value self-control";
		}
		else if (level >= -25)
		{
			s << "finds those that deny their impulses somewhat stiff";
		}
		else if (level >= -40)
		{
			s << "sees the denial of impulses as a vain and foolish pursuit";
		}
		else
		{
			s << "has abandoned any attempt at self-control and finds the whole concept deeply offensive";
		}
		BREAK(value);
	case value_type::TRANQUILITY:
		if (level > 40)
		{
			s << "views tranquility as one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "strongly values tranquility and quiet";
		}
		else if (level > 10)
		{
			s << "values tranquility and a peaceful day";
		}
		else if (level >= -10)
		{
			s << "doesn't have a preference between tranquility and tumult";
		}
		else if (level >= -25)
		{
			s << "prefers a noisy, bustling life to boring days without activity";
		}
		else if (level >= -40)
		{
			s << "is greatly disturbed by quiet and a peaceful existence";
		}
		else
		{
			s << "is disgusted by tranquility and would that the world would constantly churn with noise and activity";
		}
		BREAK(value);
	case value_type::HARMONY:
		if (level > 40)
		{
			s << "would have the world operate in complete harmony without the least bit of strife or disorder";
		}
		else if (level > 25)
		{
			s << "strongly believes that a peaceful and ordered society without dissent is best";
		}
		else if (level > 10)
		{
			s << "values a harmonious existence";
		}
		else if (level >= -10)
		{
			s << "sees equal parts of harmony and discord as part of life";
		}
		else if (level >= -25)
		{
			s << "doesn't respect a society that has settled into harmony without debate and strife";
		}
		else if (level >= -40)
		{
			s << "can't fathom why anyone would want to live in an orderly and harmonious society";
		}
		else
		{
			s << "believes deeply that chaos and disorder are the truest expressions of life and would disrupt harmony wherever it is found";
		}
		BREAK(value);
	case value_type::MERRIMENT:
		if (level > 40)
		{
			s << "believes that little is better in life than a good party";
		}
		else if (level > 25)
		{
			s << "truly values merrymaking and parties";
		}
		else if (level > 10)
		{
			s << "finds merrymaking and partying worthwhile activities";
		}
		else if (level >= -10)
		{
			s << "doesn't really value merrymaking";
		}
		else if (level >= -25)
		{
			s << "sees merrymaking as a waste";
		}
		else if (level >= -40)
		{
			s << "is disgusted by merrymakers";
		}
		else
		{
			s << "is appalled by merrymaking, parties and other such worthless activities";
		}
		BREAK(value);
	case value_type::CRAFTSMANSHIP:
		if (level > 40)
		{
			s << "holds crafts[man]ship to be of the highest ideals and celebrates talented artisans and their masterworks";
		}
		else if (level > 25)
		{
			s << "has a great deal of respect for worthy crafts[man]ship";
		}
		else if (level > 10)
		{
			s << "values good crafts[man]ship";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly care about crafts[man]ship";
		}
		else if (level >= -25)
		{
			s << "considers crafts[man]ship to be relatively worthless";
		}
		else if (level >= -40)
		{
			s << "sees the pursuit of good crafts[man]ship as a total waste";
		}
		else
		{
			s << "views crafts[man]ship with disgust and would desecrate a so-called masterwork or two if [he/she] could get away with it";
		}
		BREAK(value);
	case value_type::MARTIAL_PROWESS:
		if (level > 40)
		{
			s << "believes that martial prowess defines the good character of an individual";
		}
		else if (level > 25)
		{
			s << "deeply respects skill at arms";
		}
		else if (level > 10)
		{
			s << "values martial prowess";
		}
		else if (level >= -10)
		{
			s << "does not really value skills related to fighting";
		}
		else if (level >= -25)
		{
			s << "finds those that develop skill with weapons and fighting distasteful";
		}
		else if (level >= -40)
		{
			s << "thinks that the pursuit of the skills of warfare and fighting is a low pursuit indeed";
		}
		else
		{
			s << "abhors those that pursue the mastery of weapons and skill with fighting";
		}
		BREAK(value);
	case value_type::SKILL:
		if (level > 40)
		{
			s << "believes that the mastery of a skill is one of the highest pursuits";
		}
		else if (level > 25)
		{
			s << "really respects those that take the time to master a skill";
		}
		else if (level > 10)
		{
			s << "respects the development of skill";
		}
		else if (level >= -10)
		{
			s << "doesn't care if others take the time to master skills";
		}
		else if (level >= -25)
		{
			s << "finds the pursuit of skill mastery off-putting";
		}
		else if (level >= -40)
		{
			s << "believes that the time taken to master a skill is a horrible waste";
		}
		else
		{
			s << "sees the whole idea of taking time to master a skill as appalling";
		}
		BREAK(value);
	case value_type::HARD_WORK:
		if (level > 40)
		{
			s << "believes that hard work is one of the highest ideals and a key to the good life";
		}
		else if (level > 25)
		{
			s << "deeply respects those that work hard at their labors";
		}
		else if (level > 10)
		{
			s << "values hard work";
		}
		else if (level >= -10)
		{
			s << "doesn't really see the point of working hard";
		}
		else if (level >= -25)
		{
			s << "sees working hard as a foolish waste of time";
		}
		else if (level >= -40)
		{
			s << "thinks working hard is an abject idiocy";
		}
		else
		{
			s << "finds the proposition that one should work hard in life utterly abhorent";
		}
		BREAK(value);
	case value_type::SACRIFICE:
		if (level > 40)
		{
			s << "finds sacrifice to be one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "believes that those who sacrifice for others should be deeply respected";
		}
		else if (level > 10)
		{
			s << "values sacrifice";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly respect sacrifice as a virtue";
		}
		else if (level >= -25)
		{
			s << "sees sacrifice as wasteful and foolish";
		}
		else if (level >= -40)
		{
			s << "finds sacrifice to be the height of folly";
		}
		else
		{
			s << "thinks that the entire concept of sacrifice for others is truly disgusting";
		}
		BREAK(value);
	case value_type::COMPETITION:
		if (level > 40)
		{
			s << "holds the idea of competition among the most important and would encourage it wherever possible";
		}
		else if (level > 25)
		{
			s << "views competition as a crucial driving force in the world";
		}
		else if (level > 10)
		{
			s << "sees competition as reasonably important";
		}
		else if (level >= -10)
		{
			s << "doesn't have strong views on competition";
		}
		else if (level >= -25)
		{
			s << "sees competition as wasteful and silly";
		}
		else if (level >= -40)
		{
			s << "deeply dislikes competition";
		}
		else
		{
			s << "finds the very idea of competition obscene";
		}
		BREAK(value);
	case value_type::PERSEVERENCE:
		if (level > 40)
		{
			s << "believes that perseverence is one of the greatest qualities somebody can have";
		}
		else if (level > 25)
		{
			s << "greatly respects individuals that persevere through their trials and labors";
		}
		else if (level > 10)
		{
			s << "respects perseverence";
		}
		else if (level >= -10)
		{
			s << "doesn't think much about the idea of perseverence";
		}
		else if (level >= -25)
		{
			s << "sees perseverence in the face of adversity as bull-headed and foolish";
		}
		else if (level >= -40)
		{
			s << "thinks there is something deeply wrong with people that persevere through adversity";
		}
		else
		{
			s << "finds the notion that one would persevere through adversity completely abhorent";
		}
		BREAK(value);
	case value_type::LEISURE_TIME:
		if (level > 40)
		{
			s << "believes that it would be a fine thing if all time were leisure time";
		}
		else if (level > 25)
		{
			s << "treasures leisure time and thinks it is very important in life";
		}
		else if (level > 10)
		{
			s << "values leisure time";
		}
		else if (level >= -10)
		{
			s << "doesn't think one way or the other about leisure time";
		}
		else if (level >= -25)
		{
			s << "finds leisure time wasteful";
		}
		else if (level >= -40)
		{
			s << "is offended by leisure time and leisurely living";
		}
		else
		{
			s << "believes that those that take leisure time are evil and finds the whole idea disgusting";
		}
		BREAK(value);
	case value_type::COMMERCE:
		if (level > 40)
		{
			s << "sees engaging in commerce as a high ideal in life";
		}
		else if (level > 25)
		{
			s << "really respects commerce and those that engage in trade";
		}
		else if (level > 10)
		{
			s << "respects commerce";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly respect commerce";
		}
		else if (level >= -25)
		{
			s << "is somewhat put off by trade and commerce";
		}
		else if (level >= -40)
		{
			s << "finds those that engage in trade and commerce to be fairly disgusting";
		}
		else
		{
			s << "holds the view that commerce is a vile obscenity";
		}
		BREAK(value);
	case value_type::ROMANCE:
		if (level > 40)
		{
			s << "sees romance as one of the highest ideals";
		}
		else if (level > 25)
		{
			s << "thinks romance is very important in life";
		}
		else if (level > 10)
		{
			s << "values romance";
		}
		else if (level >= -10)
		{
			s << "doesn't care one way or the other about romance";
		}
		else if (level >= -25)
		{
			s << "finds romance distasteful";
		}
		else if (level >= -40)
		{
			s << "is somewhat disgusted by romance";
		}
		else
		{
			s << "finds even the abstract idea of romance repellent";
		}
		BREAK(value);
	case value_type::NATURE:
		if (level > 40)
		{
			s << "holds nature to be of greater value than most aspects of civilization";
		}
		else if (level > 25)
		{
			s << "has a deep respect for animals, plants and the natural world";
		}
		else if (level > 10)
		{
			s << "values nature";
		}
		else if (level >= -10)
		{
			s << "doesn't care about nature one way or another";
		}
		else if (level >= -25)
		{
			s << "finds nature somewhat disturbing";
		}
		else if (level >= -40)
		{
			s << "has a deep dislike of the natural world";
		}
		else
		{
			s << "would just as soon have nature and the great outdoors burned to ashes and converted into a great mining pit";
		}
		BREAK(value);
	case value_type::PEACE:
		if (level > 40)
		{
			s << "believes the idea of war is utterly repellent and would have peace at all costs";
		}
		else if (level > 25)
		{
			s << "believes that peace is always preferable to war";
		}
		else if (level > 10)
		{
			s << "values peace over war";
		}
		else if (level >= -10)
		{
			s << "doesn't particularly care between war and peace";
		}
		else if (level >= -25)
		{
			s << "sees war as a useful means to an end";
		}
		else if (level >= -40)
		{
			s << "believes war is preferable to peace in general";
		}
		else
		{
			s << "thinks that the world should be engaged in perpetual warfare";
		}
		BREAK(value);
	case value_type::KNOWLEDGE:
		if (level > 40)
		{
			s << "finds the quest for knowledge to be of the very highest value";
		}
		else if (level > 25)
		{
			s << "views the pursuit of knowledge as deeply important";
		}
		else if (level > 10)
		{
			s << "values knowledge";
		}
		else if (level >= -10)
		{
			s << "doesn't see the attainment of knowledge as important";
		}
		else if (level >= -25)
		{
			s << "finds the pursuit of knowledge to be a waste of effort";
		}
		else if (level >= -40)
		{
			s << "thinks the quest for knowledge is a delusional fantasy";
		}
		else
		{
			s << "sees the attainment and preservation of knowledge as an offensive enterprise engaged in by arrogant fools";
		}
		BREAK(value);
	}
	AFTER_SWITCH(value, "");
}

void written_content(std::ostream & s, const event_context & context, df::written_content *content, df::historical_figure *omit_author, bool show_refs)
{
	s << "a ";
	typedef std::pair<df::written_content_style, int32_t> style_t;
	std::vector<style_t> styles;
	styles.resize(content->styles.size());
	for (auto style = styles.begin(); style != styles.end(); style++)
	{
		style->first = content->styles.at(style - styles.begin());
		style->second = content->style_strength.at(style - styles.begin());
	}
	list<style_t>(s, styles, [content](std::ostream & out, style_t style)
	{
		if (style.second > 1)
		{
			out << "somewhat ";
		}
		else if (style.second < 1)
		{
			out << "very ";
		}
		BEFORE_SWITCH(wcs, style.first);
		switch (wcs)
		{
		case written_content_style::Meandering:
			out << "meandering";
			BREAK(wcs);
		case written_content_style::Cheerful:
			out << "cheerful";
			BREAK(wcs);
		case written_content_style::Depressing:
			out << "depressing";
			BREAK(wcs);
		case written_content_style::Rigid:
			out << "rigid";
			BREAK(wcs);
		case written_content_style::Serious:
			out << "serious";
			BREAK(wcs);
		case written_content_style::Disjointed:
			out << "disjointed";
			BREAK(wcs);
		case written_content_style::Ornate:
			out << "ornate";
			BREAK(wcs);
		case written_content_style::Forceful:
			out << "forceful";
			BREAK(wcs);
		case written_content_style::Humorous:
			out << "humorous";
			BREAK(wcs);
		case written_content_style::Immature:
			out << "immature";
			BREAK(wcs);
		case written_content_style::SelfIndulgent:
			out << "self-indulgent";
			BREAK(wcs);
		case written_content_style::Touching:
			out << "touching";
			BREAK(wcs);
		case written_content_style::Compassionate:
			out << "compassionate";
			BREAK(wcs);
		case written_content_style::Vicious:
			out << "vicious";
			BREAK(wcs);
		case written_content_style::Concise:
			out << "concise";
			BREAK(wcs);
		case written_content_style::Scornful:
			out << "scornful";
			BREAK(wcs);
		case written_content_style::Witty:
			out << "witty";
			BREAK(wcs);
		case written_content_style::Ranting:
			out << "ranting";
			BREAK(wcs);
		}
		AFTER_SWITCH(wcs, stl_sprintf("content-%d", content->id));
	});
	if (!styles.empty())
	{
		s << " ";
	}
	BEFORE_SWITCH(type, content->type);
	switch (type)
	{
	case written_content_type::Manual:
		s << "manual";
		BREAK(type);
	case written_content_type::Guide:
		s << "guide";
		BREAK(type);
	case written_content_type::Chronicle:
		s << "chronicle";
		BREAK(type);
	case written_content_type::ShortStory:
		s << "short story";
		BREAK(type);
	case written_content_type::Novel:
		s << "novel";
		BREAK(type);
	case written_content_type::Biography:
		s << "biography";
		BREAK(type);
	case written_content_type::Autobiography:
		s << "autobiography";
		BREAK(type);
	case written_content_type::Poem:
		s << "poem";
		BREAK(type);
	case written_content_type::Play:
		s << "play";
		BREAK(type);
	case written_content_type::Letter:
		s << "letter";
		BREAK(type);
	case written_content_type::Essay:
		s << "essay";
		BREAK(type);
	case written_content_type::Dialog:
		s << "dialog";
		BREAK(type);
	case written_content_type::MusicalComposition:
		s << "musical composition";
		BREAK(type);
	case written_content_type::Choreography:
		s << "choreography";
		BREAK(type);
	case written_content_type::ComparativeBiography:
		s << "comparative biography";
		BREAK(type);
	case written_content_type::BiographicalDictionary:
		s << "biographical dictionary";
		BREAK(type);
	case written_content_type::Genealogy:
		s << "genealogy";
		BREAK(type);
	case written_content_type::Encyclopedia:
		s << "encyclopedia";
		BREAK(type);
	case written_content_type::CulturalHistory:
		s << "cultural history";
		BREAK(type);
	case written_content_type::CulturalComparison:
		s << "cultural comparison";
		BREAK(type);
	case written_content_type::AlternateHistory:
		s << "alternate history";
		BREAK(type);
	case written_content_type::TreatiseOnTechnologicalEvolution:
		s << "treatise on technological evolution";
		BREAK(type);
	case written_content_type::Dictionary:
		s << "dictionary";
		BREAK(type);
	case written_content_type::StarChart:
		s << "star chart";
		BREAK(type);
	case written_content_type::StarCatalogue:
		s << "star catalogue";
		BREAK(type);
	case written_content_type::Atlas:
		s << "atlas";
		BREAK(type);
	}
	AFTER_SWITCH(type, stl_sprintf("content-%d", content->id));
	if (auto author = df::historical_figure::find(content->author))
	{
		if (author != omit_author)
		{
			s << " by ";
			link(s, author);
		}
	}
	if (!content->title.empty())
	{
		s << " titled <em>" << content->title << "</em>";
	}

	if (show_refs)
	{
		for (auto ref = content->refs.begin(); ref != content->refs.end(); ref++)
		{
			BEFORE_SWITCH(type, (*ref)->getType());
			switch (type)
			{
			case general_ref_type::ARTIFACT:
				if (auto r = virtual_cast<df::general_ref_artifact>(*ref))
				{
					if (auto item = df::artifact_record::find(r->artifact_id))
					{
						s << ". The writing concerns the";
						categorize(s, item);
						s << " ";
						event_link(s, context, item);
					}
				}
				BREAK(type);
			case general_ref_type::INTERACTION:
				if (auto r = virtual_cast<df::general_ref_interactionst>(*ref))
				{
					if (auto interaction = df::interaction::find(r->interaction_id))
					{
						if (auto source = binsearch_in_vector(interaction->sources, r->source_id))
						{
							s << ". The writing teaches the reader " << source->name;
						}
					}
				}
				BREAK(type);
			case general_ref_type::ABSTRACT_BUILDING:
				if (auto r = virtual_cast<df::general_ref_abstract_buildingst>(*ref))
				{
					if (auto site = df::world_site::find(r->site_id))
					{
						if (auto structure = binsearch_in_vector(site->buildings, r->building_id))
						{
							s << ". The writing concerns the";
							categorize(s, structure);
							s << " ";
							event_link(s, context, structure);
						}
					}
				}
				BREAK(type);
			case general_ref_type::ENTITY:
				if (auto r = virtual_cast<df::general_ref_entity>(*ref))
				{
					if (auto ent = df::historical_entity::find(r->entity_id))
					{
						s << ". The writing concerns the";
						categorize(s, ent);
						s << " ";
						event_link(s, context, ent);
					}
				}
				BREAK(type);
			case general_ref_type::HISTORICAL_EVENT:
				if (auto r = virtual_cast<df::general_ref_historical_eventst>(*ref))
				{
					if (auto e = df::history_event::find(r->event_id))
					{
						s << ". <em>";
						event_reverse(s, context, e);
						s << "</em>";
					}
				}
				BREAK(type);
			case general_ref_type::SITE:
				if (auto r = virtual_cast<df::general_ref_sitest>(*ref))
				{
					if (auto site = df::world_site::find(r->site_id))
					{
						s << ". The writing concerns the";
						categorize(s, site);
						s << " ";
						event_link(s, context, site);
					}
				}
				BREAK(type);
			case general_ref_type::SUBREGION:
				if (auto r = virtual_cast<df::general_ref_subregionst>(*ref))
				{
					if (auto region = df::world_region::find(r->region_id))
					{
						s << ". The writing concerns the";
						categorize(s, region);
						s << " ";
						event_link(s, context, region);
					}
				}
				BREAK(type);
			case general_ref_type::FEATURE_LAYER:
				if (auto r = virtual_cast<df::general_ref_feature_layerst>(*ref))
				{
					if (auto layer = df::world_underground_region::find(r->underground_region_id))
					{
						s << ". The writing concerns the";
						categorize(s, layer);
						s << " ";
						event_link(s, context, layer);
					}
				}
				BREAK(type);
			case general_ref_type::HISTORICAL_FIGURE:
				if (auto r = virtual_cast<df::general_ref_historical_figurest>(*ref))
				{
					if (auto hf = df::historical_figure::find(r->hist_figure_id))
					{
						s << ". The writing concerns the";
						categorize(s, hf);
						s << " ";
						event_link(s, context, hf);
					}
				}
				BREAK(type);
			case general_ref_type::KNOWLEDGE_SCHOLAR_FLAG:
				if (auto r = virtual_cast<df::general_ref_knowledge_scholar_flagst>(*ref))
				{
					s << ". The writing concerns ";
					knowledge(s, r->knowledge);
				}
				BREAK(type);
			case general_ref_type::VALUE_LEVEL:
				if (auto r = virtual_cast<df::general_ref_value_levelst>(*ref))
				{
					s << ". The author ";
					value_level(s, r->value, r->level);
				}
				BREAK(type);
			case general_ref_type::LANGUAGE:
				if (auto r = virtual_cast<df::general_ref_languagest>(*ref))
				{
					if (auto lang = df::language_translation::find(r->anon_1))
					{
						s << ". The writing concerns the " << Translation::capitalize(toLower(lang->name)) << " language";
					}
				}
				BREAK(type);
			case general_ref_type::WRITTEN_CONTENT:
				if (auto r = virtual_cast<df::general_ref_written_contentst>(*ref))
				{
					if (auto target = df::written_content::find(r->written_content_id))
					{
						s << ". The writing concerns ";
						written_content(s, context, target);
					}
					else
					{
						s << ". The writing concerns an unknown writing";
					}
				}
				BREAK(type);
			case general_ref_type::POETIC_FORM:
				if (auto r = virtual_cast<df::general_ref_poetic_formst>(*ref))
				{
					if (auto form = df::poetic_form::find(r->poetic_form_id))
					{
						s << ". The writing concerns the poetic form ";
						name_translated(s, form->name);
					}
					else
					{
						s << ". The writing concerns a poetic form";
					}
				}
				BREAK(type);
			case general_ref_type::MUSICAL_FORM:
				if (auto r = virtual_cast<df::general_ref_musical_formst>(*ref))
				{
					if (auto form = df::musical_form::find(r->musical_form_id))
					{
						s << ". The writing concerns the musical form ";
						name_translated(s, form->name);
					}
					else
					{
						s << ". The writing concerns a musical form";
					}
				}
				BREAK(type);
			case general_ref_type::DANCE_FORM:
				if (auto r = virtual_cast<df::general_ref_dance_formst>(*ref))
				{
					if (auto form = df::dance_form::find(r->dance_form_id))
					{
						s << ". The writing concerns the dance form ";
						name_translated(s, form->name);
					}
					else
					{
						s << ". The writing concerns a dance form";
					}
				}
				BREAK(type);
			default:
				break;
			}
			AFTER_SWITCH(type, stl_sprintf("content-%d", content->id));
		}
	}
}

void schedule_feature(std::ostream & s, const event_context & context, df::entity_occasion_schedule_feature *feature, df::history_event *event)
{
	BEFORE_SWITCH(feat, feature->feature);
	switch (feat)
	{
	case occasion_schedule_feature::STORYTELLING:
		if (auto ref = df::history_event::find(feature->reference))
		{
			s << "telling of how ";
			event_reverse(s, context, ref);
		}
		else
		{
			s << "storytelling";
		}
		BREAK(feat);
	case occasion_schedule_feature::POETRY_RECITAL:
		if (auto form = df::poetic_form::find(feature->reference))
		{
			s << "a recital of the poetry ";
			name_translated(s, form->name);
		}
		else
		{
			s << "a poetry recital";
		}
		BREAK(feat);
	case occasion_schedule_feature::MUSICAL_PERFORMANCE:
		if (auto form = df::musical_form::find(feature->reference))
		{
			s << "a performance of the music ";
			name_translated(s, form->name);
		}
		else
		{
			s << "a musical performance";
		}
		BREAK(feat);
	case occasion_schedule_feature::DANCE_PERFORMANCE:
		if (auto form = df::dance_form::find(feature->reference))
		{
			s << "a performance of the dance ";
			name_translated(s, form->name);
		}
		else
		{
			s << "a dance performance";
		}
		BREAK(feat);
	case occasion_schedule_feature::CRIERS_IN_FRONT:
		s << "criers in front";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: criers in front (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::ORDER_OF_PRECEDENCE:
		s << "an order of precedence";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: order of precedence (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::BANNERS:
		s << "banners";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: banners (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::IMAGES:
		s << "images";
		if (auto hf = df::historical_figure::find(feature->reference))
		{
			s << " of ";
			link(s, hf);
		}
		BREAK(feat);
	case occasion_schedule_feature::ACROBATS:
		s << "acrobats";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: acrobats (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::INCENSE_BURNING:
		s << "the burning of incense";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: incense burning (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::COSTUMES:
		s << "costumes";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: costumes (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::CANDLES:
		s << "candles";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: candles (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::THE_GIVING_OF_ITEMS:
		s << "the giving of items";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: the giving of items (event-%d)", event->id));
		BREAK(feat);
	case occasion_schedule_feature::THE_SACRIFICE_OF_ITEMS:
		s << "the sacrifice of items";
		ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: the sacrifice of items (event-%d)", event->id));
		BREAK(feat);
	default:
		s << ENUM_KEY_STR(occasion_schedule_feature, feat);
		s << ":";
		s << feature->reference;
		break;
	}
	AFTER_SWITCH(feat, stl_sprintf("feature: reference=%d (event-%d)", feature->reference, event->id));
}
