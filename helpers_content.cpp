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

    switch (knowledge.value())
    {
        case philosophy_logic_formal_reasoning:
            s << "philosophy_logic_formal_reasoning";
            break;
        case philosophy_logic_deductive_reasoning:
            s << "philosophy_logic_deductive_reasoning";
            break;
        case philosophy_logic_syllogistic_logic:
            s << "philosophy_logic_syllogistic_logic";
            break;
        case philosophy_logic_hypothetical_syllogisms:
            s << "philosophy_logic_hypothetical_syllogisms";
            break;
        case philosophy_logic_propositional_logic:
            s << "philosophy_logic_propositional_logic";
            break;
        case philosophy_logic_dialectic_reasoning:
            s << "philosophy_logic_dialectic_reasoning";
            break;
        case philosophy_logic_analogical_inference:
            s << "philosophy_logic_analogical_inference";
            break;
        case philosophy_ethics_applied_medical:
            s << "philosophy_ethics_applied_medical";
            break;
        case philosophy_ethics_individual_value:
            s << "philosophy_ethics_individual_value";
            break;
        case philosophy_ethics_state_consequentialism:
            s << "philosophy_ethics_state_consequentialism";
            break;
        case philosophy_epistemology_truth:
            s << "philosophy_epistemology_truth";
            break;
        case philosophy_epistemology_perception:
            s << "philosophy_epistemology_perception";
            break;
        case philosophy_epistemology_justification:
            s << "philosophy_epistemology_justification";
            break;
        case philosophy_epistemology_belief:
            s << "philosophy_epistemology_belief";
            break;
        case philosophy_metaphysics_existence:
            s << "philosophy_metaphysics_existence";
            break;
        case philosophy_metaphysics_time:
            s << "philosophy_metaphysics_time";
            break;
        case philosophy_metaphysics_mind_body:
            s << "philosophy_metaphysics_mind_body";
            break;
        case philosophy_metaphysics_objects_and_properties:
            s << "philosophy_metaphysics_objects_and_properties";
            break;
        case philosophy_metaphysics_wholes_and_parts:
            s << "philosophy_metaphysics_wholes_and_parts";
            break;
        case philosophy_metaphysics_events:
            s << "philosophy_metaphysics_events";
            break;
        case philosophy_metaphysics_processes:
            s << "philosophy_metaphysics_processes";
            break;
        case philosophy_metaphysics_causation:
            s << "philosophy_metaphysics_causation";
            break;
        case philosophy_ethics_applied_military:
            s << "philosophy_ethics_applied_military";
            break;
        case philosophy_ethics_applied_interpersonal_conduct:
            s << "philosophy_ethics_applied_interpersonal_conduct";
            break;
        case philosophy_specialized_law:
            s << "philosophy_specialized_law";
            break;
        case philosophy_specialized_education:
            s << "philosophy_specialized_education";
            break;
        case philosophy_specialized_language_grammar:
            s << "philosophy_specialized_language_grammar";
            break;
        case philosophy_specialized_language_etymology:
            s << "philosophy_specialized_language_etymology";
            break;
        case philosophy_specialized_politics_diplomacy:
            s << "philosophy_specialized_politics_diplomacy";
            break;
        case philosophy_specialized_politics_government_forms:
            s << "philosophy_specialized_politics_government_forms";
            break;
        case philosophy_specialized_politics_economic_policy:
            s << "philosophy_specialized_politics_economic_policy";
            break;
        case philosophy_specialized_politics_social_welfare:
            s << "philosophy_specialized_politics_social_welfare";
            break;
        case philosophy_logic_inductive_reasoning:
            s << "philosophy_logic_inductive_reasoning";
            break;
        case philosophy_logic_direct_inference:
            s << "philosophy_logic_direct_inference";
            break;
        case philosophy_aesthetics_nature_of_beauty:
            s << "philosophy_aesthetics_nature_of_beauty";
            break;
        case philosophy_aesthetics_value_of_art:
            s << "philosophy_aesthetics_value_of_art";
            break;
        case philosophy_specialized_language_dictionary:
            s << "philosophy_specialized_language_dictionary";
            break;
        case mathematics_method_proof_by_contradiction:
            s << "mathematics_method_proof_by_contradiction";
            break;
        case mathematics_notation_zero:
            s << "mathematics_notation_zero";
            break;
        case mathematics_notation_negative_numbers:
            s << "mathematics_notation_negative_numbers";
            break;
        case mathematics_notation_large_numbers:
            s << "mathematics_notation_large_numbers";
            break;
        case mathematics_notation_positional:
            s << "mathematics_notation_positional";
            break;
        case mathematics_geometry_basic_objects:
            s << "mathematics_geometry_basic_objects";
            break;
        case mathematics_method_exhaustion:
            s << "mathematics_method_exhaustion";
            break;
        case mathematics_geometry_similar_and_congruent_triangles:
            s << "mathematics_geometry_similar_and_congruent_triangles";
            break;
        case mathematics_geometry_geometric_mean_theorem:
            s << "mathematics_geometry_geometric_mean_theorem";
            break;
        case mathematics_geometry_isosceles_base_angles_equal:
            s << "mathematics_geometry_isosceles_base_angles_equal";
            break;
        case mathematics_geometry_inscribed_triangle_on_diameter_is_right:
            s << "mathematics_geometry_inscribed_triangle_on_diameter_is_right";
            break;
        case mathematics_geometry_pythagorean_theorem:
            s << "mathematics_geometry_pythagorean_theorem";
            break;
        case mathematics_geometry_pythagorean_triples_small:
            s << "mathematics_geometry_pythagorean_triples_small";
            break;
        case mathematics_geometry_pythagorean_triples_3_digit:
            s << "mathematics_geometry_pythagorean_triples_3_digit";
            break;
        case mathematics_geometry_pythagorean_triples_4_digit:
            s << "mathematics_geometry_pythagorean_triples_4_digit";
            break;
        case mathematics_geometry_existence_of_incommensurable_ratios:
            s << "mathematics_geometry_existence_of_incommensurable_ratios";
            break;
        case mathematics_method_axiomatic_reasoning:
            s << "mathematics_method_axiomatic_reasoning";
            break;
        case mathematics_numbers_unique_prime_factorization:
            s << "mathematics_numbers_unique_prime_factorization";
            break;
        case mathematics_numbers_algorithm_for_computing_gcd:
            s << "mathematics_numbers_algorithm_for_computing_gcd";
            break;
        case mathematics_geometry_volume_of_pyramid:
            s << "mathematics_geometry_volume_of_pyramid";
            break;
        case mathematics_geometry_volume_of_cone:
            s << "mathematics_geometry_volume_of_cone";
            break;
        case mathematics_geometry_volume_of_sphere:
            s << "mathematics_geometry_volume_of_sphere";
            break;
        case mathematics_geometry_pi_to_4_digits:
            s << "mathematics_geometry_pi_to_4_digits";
            break;
        case mathematics_numbers_division_algorithm:
            s << "mathematics_numbers_division_algorithm";
            break;
        case mathematics_geometry_table_of_chord_values:
            s << "mathematics_geometry_table_of_chord_values";
            break;
        case mathematics_geometry_area_of_triangle_from_side_lengths:
            s << "mathematics_geometry_area_of_triangle_from_side_lengths";
            break;
        case mathematics_geometry_area_of_circle:
            s << "mathematics_geometry_area_of_circle";
            break;
        case mathematics_geometry_pi_to_6_digits:
            s << "mathematics_geometry_pi_to_6_digits";
            break;
        case mathematics_geometry_definitions_and_basic_properties_of_conic_sections:
            s << "mathematics_geometry_definitions_and_basic_properties_of_conic_sections";
            break;
        case mathematics_numbers_chinese_remainder_algorithm:
            s << "mathematics_numbers_chinese_remainder_algorithm";
            break;
        case mathematics_geometry_area_enclosed_by_line_and_parabola:
            s << "mathematics_geometry_area_enclosed_by_line_and_parabola";
            break;
        case mathematics_numbers_sieve_algorithm_for_primes:
            s << "mathematics_numbers_sieve_algorithm_for_primes";
            break;
        case mathematics_numbers_root_2_to_5_digits:
            s << "mathematics_numbers_root_2_to_5_digits";
            break;
        case mathematics_numbers_infinite_primes:
            s << "mathematics_numbers_infinite_primes";
            break;
        case mathematics_numbers_root_2_irrational:
            s << "mathematics_numbers_root_2_irrational";
            break;
        case mathematics_geometry_surface_area_of_sphere:
            s << "mathematics_geometry_surface_area_of_sphere";
            break;
        case mathematics_algebra_finite_summation_formulas:
            s << "mathematics_algebra_finite_summation_formulas";
            break;
        case mathematics_algebra_solving_linear_systems:
            s << "mathematics_algebra_solving_linear_systems";
            break;
        case mathematics_algebra_balancing_and_completion:
            s << "mathematics_algebra_balancing_and_completion";
            break;
        case mathematics_algebra_quadratic_by_completing_square:
            s << "mathematics_algebra_quadratic_by_completing_square";
            break;
        case mathematics_algebra_quadratic_formula:
            s << "mathematics_algebra_quadratic_formula";
            break;
        case mathematics_notation_syncopated_algebra:
            s << "mathematics_notation_syncopated_algebra";
            break;
        case mathematics_geometry_law_of_sines:
            s << "mathematics_geometry_law_of_sines";
            break;
        case mathematics_geometry_angle_sum_difference_trig_identities:
            s << "mathematics_geometry_angle_sum_difference_trig_identities";
            break;
        case mathematics_algebra_pascals_triangle:
            s << "mathematics_algebra_pascals_triangle";
            break;
        case mathematics_algebra_solving_higher_order_polynomials:
            s << "mathematics_algebra_solving_higher_order_polynomials";
            break;
        case mathematics_notation_early_symbols_for_operations:
            s << "mathematics_notation_early_symbols_for_operations";
            break;
        case mathematics_algebra_divergence_of_harmonic_series:
            s << "mathematics_algebra_divergence_of_harmonic_series";
            break;
        case mathematics_geometry_properties_of_chords:
            s << "mathematics_geometry_properties_of_chords";
            break;
        case history_sourcing_basic_reliability:
            s << "history_sourcing_basic_reliability";
            break;
        case history_sourcing_role_of_systemic_bias:
            s << "history_sourcing_role_of_systemic_bias";
            break;
        case history_sourcing_role_of_state_bias_and_propaganda:
            s << "history_sourcing_role_of_state_bias_and_propaganda";
            break;
        case history_sourcing_personal_interviews:
            s << "history_sourcing_personal_interviews";
            break;
        case history_theory_historical_causation:
            s << "history_theory_historical_causation";
            break;
        case history_theory_historical_cycles:
            s << "history_theory_historical_cycles";
            break;
        case history_theory_social_cohesion:
            s << "history_theory_social_cohesion";
            break;
        case history_theory_social_conflict:
            s << "history_theory_social_conflict";
            break;
        case history_form_biography:
            s << "history_form_biography";
            break;
        case history_form_comparative_biography:
            s << "history_form_comparative_biography";
            break;
        case history_form_biographical_dictionaries:
            s << "history_form_biographical_dictionaries";
            break;
        case history_form_autobiographical_adventure:
            s << "history_form_autobiographical_adventure";
            break;
        case history_form_genealogy:
            s << "history_form_genealogy";
            break;
        case history_form_encyclopedia:
            s << "history_form_encyclopedia";
            break;
        case history_form_cultural_history:
            s << "history_form_cultural_history";
            break;
        case history_form_cultural_comparison:
            s << "history_form_cultural_comparison";
            break;
        case history_sourcing_role_of_cultural_differences:
            s << "history_sourcing_role_of_cultural_differences";
            break;
        case history_form_alternate_history:
            s << "history_form_alternate_history";
            break;
        case history_sourcing_basic_archaeology:
            s << "history_sourcing_basic_archaeology";
            break;
        case history_form_treatise_on_tech_evolution:
            s << "history_form_treatise_on_tech_evolution";
            break;
        case astronomy_phases_of_the_moon:
            s << "astronomy_phases_of_the_moon";
            break;
        case astronomy_summer_winter_moon:
            s << "astronomy_summer_winter_moon";
            break;
        case astronomy_path_of_the_moon:
            s << "astronomy_path_of_the_moon";
            break;
        case astronomy_tides_and_the_moon:
            s << "astronomy_tides_and_the_moon";
            break;
        case astronomy_height_of_tides_vs_moon_and_sun:
            s << "astronomy_height_of_tides_vs_moon_and_sun";
            break;
        case astronomy_summer_winter_sun:
            s << "astronomy_summer_winter_sun";
            break;
        case astronomy_relationship_between_lunar_solar_year:
            s << "astronomy_relationship_between_lunar_solar_year";
            break;
        case astronomy_daylight_variation_with_solar_year:
            s << "astronomy_daylight_variation_with_solar_year";
            break;
        case astronomy_geocentric_model:
            s << "astronomy_geocentric_model";
            break;
        case astronomy_heliocentric_model:
            s << "astronomy_heliocentric_model";
            break;
        case astronomy_dates_of_lunar_and_solar_eclipses:
            s << "astronomy_dates_of_lunar_and_solar_eclipses";
            break;
        case astronomy_star_charts:
            s << "astronomy_star_charts";
            break;
        case astronomy_star_catalogues_100:
            s << "astronomy_star_catalogues_100";
            break;
        case astronomy_star_catalogues_1000:
            s << "astronomy_star_catalogues_1000";
            break;
        case astronomy_star_color_classification:
            s << "astronomy_star_color_classification";
            break;
        case astronomy_star_magnitude_classification:
            s << "astronomy_star_magnitude_classification";
            break;
        case astronomy_shape_of_the_world:
            s << "astronomy_shape_of_the_world";
            break;
        case astronomy_precession_of_equinoxes:
            s << "astronomy_precession_of_equinoxes";
            break;
        case astronomy_method_empirical_observation:
            s << "astronomy_method_empirical_observation";
            break;
        case astronomy_method_path_models:
            s << "astronomy_method_path_models";
            break;
        case naturalist_method_dissection:
            s << "naturalist_method_dissection";
            break;
        case naturalist_observation_anatomy:
            s << "naturalist_observation_anatomy";
            break;
        case naturalist_theory_comparative_anatomy:
            s << "naturalist_theory_comparative_anatomy";
            break;
        case naturalist_theory_classification_by_physical_features:
            s << "naturalist_theory_classification_by_physical_features";
            break;
        case naturalist_observation_migration_patterns:
            s << "naturalist_observation_migration_patterns";
            break;
        case naturalist_observation_reproductive_behavior:
            s << "naturalist_observation_reproductive_behavior";
            break;
        case naturalist_observation_foraging_behavior_and_diet:
            s << "naturalist_observation_foraging_behavior_and_diet";
            break;
        case naturalist_theory_food_chain:
            s << "naturalist_theory_food_chain";
            break;
        case naturalist_observation_social_behavior:
            s << "naturalist_observation_social_behavior";
            break;
        case naturalist_observation_diseases:
            s << "naturalist_observation_diseases";
            break;
        case naturalist_theory_climactic_adaptation:
            s << "naturalist_theory_climactic_adaptation";
            break;
        case naturalist_observation_embriological_development:
            s << "naturalist_observation_embriological_development";
            break;
        case naturalist_theory_struggle_for_existence:
            s << "naturalist_theory_struggle_for_existence";
            break;
        case chemistry_classification_combustibles:
            s << "chemistry_classification_combustibles";
            break;
        case chemistry_classification_ores:
            s << "chemistry_classification_ores";
            break;
        case chemistry_metallurgy_alloys:
            s << "chemistry_metallurgy_alloys";
            break;
        case chemistry_classification_scratch_test:
            s << "chemistry_classification_scratch_test";
            break;
        case chemistry_classification_elemental_theory:
            s << "chemistry_classification_elemental_theory";
            break;
        case chemistry_chemicals_adhesives:
            s << "chemistry_chemicals_adhesives";
            break;
        case chemistry_laboratory_blast_furnace:
            s << "chemistry_laboratory_blast_furnace";
            break;
        case chemistry_laboratory_alembic:
            s << "chemistry_laboratory_alembic";
            break;
        case chemistry_laboratory_theory_of_liquid_liquid_extraction:
            s << "chemistry_laboratory_theory_of_liquid_liquid_extraction";
            break;
        case chemistry_laboratory_theory_of_distillation:
            s << "chemistry_laboratory_theory_of_distillation";
            break;
        case chemistry_laboratory_theory_of_evaporation:
            s << "chemistry_laboratory_theory_of_evaporation";
            break;
        case chemistry_classification_alkali_and_acids:
            s << "chemistry_classification_alkali_and_acids";
            break;
        case chemistry_laboratory_systematic_experiments:
            s << "chemistry_laboratory_systematic_experiments";
            break;
        case chemistry_laboratory_glass_flask:
            s << "chemistry_laboratory_glass_flask";
            break;
        case chemistry_laboratory_glass_beaker:
            s << "chemistry_laboratory_glass_beaker";
            break;
        case chemistry_laboratory_glass_vial:
            s << "chemistry_laboratory_glass_vial";
            break;
        case chemistry_laboratory_glass_funnel:
            s << "chemistry_laboratory_glass_funnel";
            break;
        case chemistry_laboratory_crucible:
            s << "chemistry_laboratory_crucible";
            break;
        case chemistry_chemicals_nitric_acid:
            s << "chemistry_chemicals_nitric_acid";
            break;
        case chemistry_chemicals_sulfuric_acid:
            s << "chemistry_chemicals_sulfuric_acid";
            break;
        case chemistry_chemicals_aqua_regia:
            s << "chemistry_chemicals_aqua_regia";
            break;
        case chemistry_laboratory_glass_ampoule:
            s << "chemistry_laboratory_glass_ampoule";
            break;
        case chemistry_laboratory_glass_retort:
            s << "chemistry_laboratory_glass_retort";
            break;
        case chemistry_laboratory_lab_ovens:
            s << "chemistry_laboratory_lab_ovens";
            break;
        case geography_surveying_basic:
            s << "geography_surveying_basic";
            break;
        case geography_surveying_staff:
            s << "geography_surveying_staff";
            break;
        case geography_cartography_basic:
            s << "geography_cartography_basic";
            break;
        case geography_surveying_triangulation:
            s << "geography_surveying_triangulation";
            break;
        case geography_surveying_cartographical:
            s << "geography_surveying_cartographical";
            break;
        case geography_surveying_land:
            s << "geography_surveying_land";
            break;
        case geography_surveying_military:
            s << "geography_surveying_military";
            break;
        case geography_surveying_engineering:
            s << "geography_surveying_engineering";
            break;
        case geography_cartography_geological:
            s << "geography_cartography_geological";
            break;
        case geography_cartography_grid_system:
            s << "geography_cartography_grid_system";
            break;
        case geography_cartography_distance_scale:
            s << "geography_cartography_distance_scale";
            break;
        case geography_cartography_height_measurements:
            s << "geography_cartography_height_measurements";
            break;
        case geography_method_economic_data_collection:
            s << "geography_method_economic_data_collection";
            break;
        case geography_cartography_economic:
            s << "geography_cartography_economic";
            break;
        case geography_form_atlas:
            s << "geography_form_atlas";
            break;
        case geography_theory_delta_formation:
            s << "geography_theory_delta_formation";
            break;
        case geography_theory_wind_patterns:
            s << "geography_theory_wind_patterns";
            break;
        case geography_theory_origin_of_rainfall_from_evap_condense:
            s << "geography_theory_origin_of_rainfall_from_evap_condense";
            break;
        case geography_theory_water_cycle:
            s << "geography_theory_water_cycle";
            break;
        case geography_theory_latitude_climate_zones:
            s << "geography_theory_latitude_climate_zones";
            break;
        case geography_cartography_accurate_maps:
            s << "geography_cartography_accurate_maps";
            break;
        case geography_cartography_map_projections:
            s << "geography_cartography_map_projections";
            break;
        case medicine_theory_disease_and_fouled_water:
            s << "medicine_theory_disease_and_fouled_water";
            break;
        case medicine_method_physical_examination:
            s << "medicine_method_physical_examination";
            break;
        case medicine_method_autopsy:
            s << "medicine_method_autopsy";
            break;
        case medicine_theory_prognosis:
            s << "medicine_theory_prognosis";
            break;
        case medicine_tool_herbal_remedies:
            s << "medicine_tool_herbal_remedies";
            break;
        case medicine_tool_animal_remedies:
            s << "medicine_tool_animal_remedies";
            break;
        case medicine_tool_mineral_remedies:
            s << "medicine_tool_mineral_remedies";
            break;
        case medicine_tool_bandages:
            s << "medicine_tool_bandages";
            break;
        case medicine_theory_disease_classification:
            s << "medicine_theory_disease_classification";
            break;
        case medicine_theory_toxicology:
            s << "medicine_theory_toxicology";
            break;
        case medicine_theory_acute_and_chronic_conditions:
            s << "medicine_theory_acute_and_chronic_conditions";
            break;
        case medicine_theory_endemic_disease:
            s << "medicine_theory_endemic_disease";
            break;
        case medicine_theory_epidemic_disease:
            s << "medicine_theory_epidemic_disease";
            break;
        case medicine_theory_exacerbation:
            s << "medicine_theory_exacerbation";
            break;
        case medicine_theory_paroxysm:
            s << "medicine_theory_paroxysm";
            break;
        case medicine_theory_relapse:
            s << "medicine_theory_relapse";
            break;
        case medicine_theory_convalescence:
            s << "medicine_theory_convalescence";
            break;
        case medicine_method_treatment_of_traumatic_injuries:
            s << "medicine_method_treatment_of_traumatic_injuries";
            break;
        case medicine_method_fracture_treatment:
            s << "medicine_method_fracture_treatment";
            break;
        case medicine_theory_fracture_classification:
            s << "medicine_theory_fracture_classification";
            break;
        case medicine_tool_traction_bench:
            s << "medicine_tool_traction_bench";
            break;
        case medicine_method_fracture_immobilization:
            s << "medicine_method_fracture_immobilization";
            break;
        case medicine_tool_orthopedic_cast:
            s << "medicine_tool_orthopedic_cast";
            break;
        case medicine_method_surgery_excision:
            s << "medicine_method_surgery_excision";
            break;
        case medicine_method_surgery_incision:
            s << "medicine_method_surgery_incision";
            break;
        case medicine_method_hernia_surgery:
            s << "medicine_method_hernia_surgery";
            break;
        case medicine_method_tracheotomy_surgery:
            s << "medicine_method_tracheotomy_surgery";
            break;
        case medicine_method_lithotomy_surgery:
            s << "medicine_method_lithotomy_surgery";
            break;
        case medicine_method_surgery_scraping:
            s << "medicine_method_surgery_scraping";
            break;
        case medicine_method_surgery_draining:
            s << "medicine_method_surgery_draining";
            break;
        case medicine_method_surgery_probing:
            s << "medicine_method_surgery_probing";
            break;
        case medicine_method_surgery_suturing:
            s << "medicine_method_surgery_suturing";
            break;
        case medicine_method_surgery_ligature:
            s << "medicine_method_surgery_ligature";
            break;
        case medicine_theory_surgical_models:
            s << "medicine_theory_surgical_models";
            break;
        case medicine_tool_mud_bags_as_surgical_models:
            s << "medicine_tool_mud_bags_as_surgical_models";
            break;
        case medicine_tool_plants_as_surgical_models:
            s << "medicine_tool_plants_as_surgical_models";
            break;
        case medicine_tool_animals_as_surgical_models:
            s << "medicine_tool_animals_as_surgical_models";
            break;
        case medicine_theory_specialized_surgical_instruments:
            s << "medicine_theory_specialized_surgical_instruments";
            break;
        case medicine_tool_forceps:
            s << "medicine_tool_forceps";
            break;
        case medicine_tool_scalpel:
            s << "medicine_tool_scalpel";
            break;
        case medicine_tool_surgical_scissors:
            s << "medicine_tool_surgical_scissors";
            break;
        case medicine_tool_surgical_needles:
            s << "medicine_tool_surgical_needles";
            break;
        case medicine_method_cataract_surgery:
            s << "medicine_method_cataract_surgery";
            break;
        case medicine_method_cauterization:
            s << "medicine_method_cauterization";
            break;
        case medicine_method_anesthesia:
            s << "medicine_method_anesthesia";
            break;
        case medicine_theory_pulmonary_medicine:
            s << "medicine_theory_pulmonary_medicine";
            break;
        case medicine_theory_anatomical_studies:
            s << "medicine_theory_anatomical_studies";
            break;
        case medicine_theory_classification_of_bodily_fluids:
            s << "medicine_theory_classification_of_bodily_fluids";
            break;
        case medicine_theory_eye_anatomy:
            s << "medicine_theory_eye_anatomy";
            break;
        case medicine_theory_motor_vs_sensory_nerves:
            s << "medicine_theory_motor_vs_sensory_nerves";
            break;
        case medicine_theory_nervous_system_function:
            s << "medicine_theory_nervous_system_function";
            break;
        case medicine_theory_reaction_time:
            s << "medicine_theory_reaction_time";
            break;
        case medicine_theory_blood_vessels:
            s << "medicine_theory_blood_vessels";
            break;
        case medicine_theory_pulmonary_circulation:
            s << "medicine_theory_pulmonary_circulation";
            break;
        case medicine_theory_comparative_anatomy:
            s << "medicine_theory_comparative_anatomy";
            break;
        case medicine_theory_the_voice:
            s << "medicine_theory_the_voice";
            break;
        case medicine_theory_classification_of_muscles:
            s << "medicine_theory_classification_of_muscles";
            break;
        case medicine_theory_classification_of_mental_illnesses:
            s << "medicine_theory_classification_of_mental_illnesses";
            break;
        case medicine_theory_treatment_of_mental_illnesses:
            s << "medicine_theory_treatment_of_mental_illnesses";
            break;
        case medicine_tool_dedicated_hospitals:
            s << "medicine_tool_dedicated_hospitals";
            break;
        case medicine_method_professional_hospital_staff:
            s << "medicine_method_professional_hospital_staff";
            break;
        case medicine_method_specialized_wards:
            s << "medicine_method_specialized_wards";
            break;
        case medicine_method_hospital_lab:
            s << "medicine_method_hospital_lab";
            break;
        case medicine_method_medical_school:
            s << "medicine_method_medical_school";
            break;
        case medicine_method_asylum_for_mentally_ill:
            s << "medicine_method_asylum_for_mentally_ill";
            break;
        case engineering_horology_shadow_clock:
            s << "engineering_horology_shadow_clock";
            break;
        case engineering_horology_water_clock:
            s << "engineering_horology_water_clock";
            break;
        case engineering_horology_conical_water_clock:
            s << "engineering_horology_conical_water_clock";
            break;
        case engineering_horology_water_clock_reservoir:
            s << "engineering_horology_water_clock_reservoir";
            break;
        case engineering_horology_astrarium:
            s << "engineering_horology_astrarium";
            break;
        case engineering_horology_hourglass:
            s << "engineering_horology_hourglass";
            break;
        case engineering_horology_mechanical_clock:
            s << "engineering_horology_mechanical_clock";
            break;
        case engineering_machine_theory_of_pulley:
            s << "engineering_machine_theory_of_pulley";
            break;
        case engineering_machine_pulley:
            s << "engineering_machine_pulley";
            break;
        case engineering_machine_theory_of_screw:
            s << "engineering_machine_theory_of_screw";
            break;
        case engineering_machine_screw:
            s << "engineering_machine_screw";
            break;
        case engineering_machine_theory_of_wheel_and_axle:
            s << "engineering_machine_theory_of_wheel_and_axle";
            break;
        case engineering_machine_windlass:
            s << "engineering_machine_windlass";
            break;
        case engineering_machine_theory_of_wedge:
            s << "engineering_machine_theory_of_wedge";
            break;
        case engineering_machine_theory_of_lever:
            s << "engineering_machine_theory_of_lever";
            break;
        case engineering_machine_lever:
            s << "engineering_machine_lever";
            break;
        case engineering_machine_straight_beam_balance:
            s << "engineering_machine_straight_beam_balance";
            break;
        case engineering_machine_theory_of_gears:
            s << "engineering_machine_theory_of_gears";
            break;
        case engineering_machine_warded_lock:
            s << "engineering_machine_warded_lock";
            break;
        case engineering_machine_tumbler_lock:
            s << "engineering_machine_tumbler_lock";
            break;
        case engineering_machine_padlock:
            s << "engineering_machine_padlock";
            break;
        case engineering_machine_camshaft:
            s << "engineering_machine_camshaft";
            break;
        case engineering_machine_crankshaft:
            s << "engineering_machine_crankshaft";
            break;
        case engineering_machine_water_powered_sawmill:
            s << "engineering_machine_water_powered_sawmill";
            break;
        case engineering_machine_chariot_odometer:
            s << "engineering_machine_chariot_odometer";
            break;
        case engineering_machine_chain_drive:
            s << "engineering_machine_chain_drive";
            break;
        case engineering_machine_mechanical_compass:
            s << "engineering_machine_mechanical_compass";
            break;
        case engineering_machine_differential_gear:
            s << "engineering_machine_differential_gear";
            break;
        case engineering_machine_combination_lock:
            s << "engineering_machine_combination_lock";
            break;
        case engineering_machine_verge_escapement:
            s << "engineering_machine_verge_escapement";
            break;
        case engineering_machine_balance_wheel:
            s << "engineering_machine_balance_wheel";
            break;
        case engineering_fluid_theory_of_siphon:
            s << "engineering_fluid_theory_of_siphon";
            break;
        case engineering_fluid_valves:
            s << "engineering_fluid_valves";
            break;
        case engineering_fluid_force_pump:
            s << "engineering_fluid_force_pump";
            break;
        case engineering_optics_crystal_lens:
            s << "engineering_optics_crystal_lens";
            break;
        case engineering_optics_water_filled_spheres:
            s << "engineering_optics_water_filled_spheres";
            break;
        case engineering_optics_glass_lens:
            s << "engineering_optics_glass_lens";
            break;
        case engineering_optics_camera_obscura:
            s << "engineering_optics_camera_obscura";
            break;
        case engineering_optics_parabolic_mirror:
            s << "engineering_optics_parabolic_mirror";
            break;
        case engineering_optics_theory_of_color:
            s << "engineering_optics_theory_of_color";
            break;
        case engineering_optics_theory_of_rainbows:
            s << "engineering_optics_theory_of_rainbows";
            break;
        case engineering_optics_law_of_refraction:
            s << "engineering_optics_law_of_refraction";
            break;
        case engineering_design_models_and_templates:
            s << "engineering_design_models_and_templates";
            break;
        case engineering_construction_wood_lamination:
            s << "engineering_construction_wood_lamination";
            break;
        case engineering_astronomy_dioptra:
            s << "engineering_astronomy_dioptra";
            break;
        case engineering_astronomy_astrolabe:
            s << "engineering_astronomy_astrolabe";
            break;
        case engineering_astronomy_armillary_sphere:
            s << "engineering_astronomy_armillary_sphere";
            break;
        case engineering_astronomy_spherical_astrolabe:
            s << "engineering_astronomy_spherical_astrolabe";
            break;
        case engineering_astronomy_mural_instrument:
            s << "engineering_astronomy_mural_instrument";
            break;
        case engineering_astronomy_orrery:
            s << "engineering_astronomy_orrery";
            break;
        case engineering_machine_water_powered_trip_hammer:
            s << "engineering_machine_water_powered_trip_hammer";
            break;
        case engineering_machine_double_acting_piston_bellows:
            s << "engineering_machine_double_acting_piston_bellows";
            break;
        case engineering_fluid_archimedes_principle:
            s << "engineering_fluid_archimedes_principle";
            break;
        case engineering_optics_atmospheric_refraction:
            s << "engineering_optics_atmospheric_refraction";
            break;
        case engineering_optics_cause_of_twilight:
            s << "engineering_optics_cause_of_twilight";
            break;
        case engineering_optics_height_of_atmosphere:
            s << "engineering_optics_height_of_atmosphere";
            break;
        case engineering_machine_piston:
            s << "engineering_machine_piston";
            break;
        case engineering_machine_crank:
            s << "engineering_machine_crank";
            break;
        case engineering_machine_bellows:
            s << "engineering_machine_bellows";
            break;
        case engineering_machine_water_powered_piston_bellows:
            s << "engineering_machine_water_powered_piston_bellows";
            break;
        case engineering_machine_water_wheel:
            s << "engineering_machine_water_wheel";
            break;
        case engineering_machine_trip_hammer:
            s << "engineering_machine_trip_hammer";
            break;
    }
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
    list<style_t>(s, styles, [](std::ostream & out, style_t style)
            {
                if (style.second > 1)
                {
                    out << "somewhat ";
                }
                else if (style.second < 1)
                {
                    out << "very ";
                }
                switch (style.first)
                {
                    case written_content_style::Meandering:
                        out << "meandering";
                        break;
                    case written_content_style::Cheerful:
                        out << "cheerful";
                        break;
                    case written_content_style::Depressing:
                        out << "depressing";
                        break;
                    case written_content_style::Rigid:
                        out << "rigid";
                        break;
                    case written_content_style::Serious:
                        out << "serious";
                        break;
                    case written_content_style::Disjointed:
                        out << "disjointed";
                        break;
                    case written_content_style::Ornate:
                        out << "ornate";
                        break;
                    case written_content_style::Forceful:
                        out << "forceful";
                        break;
                    case written_content_style::Humorous:
                        out << "humorous";
                        break;
                    case written_content_style::Immature:
                        out << "immature";
                        break;
                    case written_content_style::SelfIndulgent:
                        out << "self-indulgent";
                        break;
                    case written_content_style::Touching:
                        out << "touching";
                        break;
                    case written_content_style::Compassionate:
                        out << "compassionate";
                        break;
                    case written_content_style::Vicious:
                        out << "vicious";
                        break;
                    case written_content_style::Concise:
                        out << "concise";
                        break;
                    case written_content_style::Scornful:
                        out << "scornful";
                        break;
                    case written_content_style::Witty:
                        out << "witty";
                        break;
                    case written_content_style::Ranting:
                        out << "ranting";
                        break;
                }
            });
    if (!styles.empty())
    {
        s << " ";
    }
    switch (content->type)
    {
        case written_content_type::Manual:
            s << "manual";
            break;
        case written_content_type::Guide:
            s << "guide";
            break;
        case written_content_type::Chronicle:
            s << "chronicle";
            break;
        case written_content_type::ShortStory:
            s << "short story";
            break;
        case written_content_type::Novel:
            s << "novel";
            break;
        case written_content_type::Biography:
            s << "biography";
            break;
        case written_content_type::Autobiography:
            s << "autobiography";
            break;
        case written_content_type::Poem:
            s << "poem";
            break;
        case written_content_type::Play:
            s << "play";
            break;
        case written_content_type::Letter:
            s << "letter";
            break;
        case written_content_type::Essay:
            s << "essay";
            break;
        case written_content_type::Dialog:
            s << "dialog";
            break;
        case written_content_type::MusicalComposition:
            s << "musical composition";
            break;
        case written_content_type::Choreography:
            s << "choreography";
            break;
        case written_content_type::ComparativeBiography:
            s << "comparative biography";
            break;
        case written_content_type::BiographicalDictionary:
            s << "biographical dictionary";
            break;
        case written_content_type::Genealogy:
            s << "genealogy";
            break;
        case written_content_type::Encyclopedia:
            s << "encyclopedia";
            break;
        case written_content_type::CulturalHistory:
            s << "cultural history";
            break;
        case written_content_type::CulturalComparison:
            s << "cultural comparison";
            break;
        case written_content_type::AlternateHistory:
            s << "alternate history";
            break;
        case written_content_type::TreatiseOnTechnologicalEvolution:
            s << "treatise on technological evolution";
            break;
        case written_content_type::Dictionary:
            s << "dictionary";
            break;
        case written_content_type::StarChart:
            s << "star chart";
            break;
        case written_content_type::StarCatalogue:
            s << "star catalogue";
            break;
        case written_content_type::Atlas:
            s << "atlas";
            break;
    }
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
                    s << " " << ENUM_KEY_STR(general_ref_type, (*ref)->getType());
            }
        }
    }
}
