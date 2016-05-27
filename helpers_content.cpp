#include "weblegends.h"
#include "helpers.h"

#include "df/general_ref_historical_eventst.h"
#include "df/general_ref_knowledge_scholar_flagst.h"
#include "df/general_ref_sitest.h"
#include "df/historical_entity.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/knowledge_scholar_category_flag.h"
#include "df/world_site.h"
#include "df/written_content.h"

void knowledge(std::ostream & s, const df::knowledge_scholar_category_flag & knowledge)
{
    using namespace df::enums::dfhack_knowledge_scholar_flag;

    SWITCH(know, knowledge.value())
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
    END_SWITCH(know, stl_sprintf("category-%d/flag-%032b", knowledge.category, knowledge.flags));
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
                SWITCH(wcs, style.first)
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
                END_SWITCH(wcs, stl_sprintf("content-%d", content->id));
            });
    if (!styles.empty())
    {
        s << " ";
    }
    SWITCH(type, content->type)
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
    END_SWITCH(type, stl_sprintf("content-%d", content->id));
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
            switch ((*ref)->getType())
            {
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
                    break;
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
                    break;
                case general_ref_type::KNOWLEDGE_SCHOLAR_FLAG:
                    if (auto r = virtual_cast<df::general_ref_knowledge_scholar_flagst>(*ref))
                    {
                        s << ". The writing concerns ";
                        knowledge(s, r->knowledge);
                    }
                    break;
                default:
                    s << " " << ENUM_KEY_STR(general_ref_type, (*ref)->getType()); // TODO
                    std::cerr << "[weblegends] missing general_ref_type::" << ENUM_KEY_STR(general_ref_type, (*ref)->getType()) << ": content-" << content->id << std::endl;
            }
        }
    }
}
