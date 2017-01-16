
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    void * memory);

void adm_open_test_result_file  (void);
void adm_close_test_result_file (void);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    adm_base_string_typ * string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ     error,
    adm_err_file_typ       file,
    adm_err_line_typ       line,
    adm_err_rank_typ       rank,
    adm_err_problem_typ  * source,
    adm_base_integer_typ   identity,
    adm_err_problem_typ  * relation,
    adm_err_problem_typ  * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_matrix_installer(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_matrix_installer(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_matrix_installer(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_matrix_installer(void);


/* Data Access Prototypes */

adm_ent_product_typ * adm_make_object_product(
    adm_sta_product_typ status);

adm_ent_icon_typ * adm_make_object_icon(void);

adm_ent_package_typ * adm_make_object_package(void);

adm_ent_property_typ * adm_make_object_property(void);

adm_ent_directory_typ * adm_make_object_directory(void);

adm_ent_component_typ * adm_make_object_component(void);

adm_ent_file_typ * adm_make_object_file(void);

adm_ent_shortcut_typ * adm_make_object_shortcut(void);

adm_ent_file_shortcut_typ * adm_make_object_file_shortcut(void);

adm_ent_uninstall_shortcut_typ * adm_make_object_uninstall_shortcut(void);

adm_ent_create_folder_typ * adm_make_object_create_folder(void);

adm_ent_remove_folder_typ * adm_make_object_remove_folder(void);

adm_ent_environment_typ * adm_make_object_environment(void);

adm_ent_registry_key_typ * adm_make_object_registry_key(void);

adm_ent_registry_value_typ * adm_make_object_registry_value(void);

adm_ent_feature_typ * adm_make_object_feature(void);

void adm_bind_object_product(
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_icon(
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_package(
    adm_ent_package_typ * ent_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_property(
    adm_ent_property_typ * ent_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_directory(
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_component(
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_file(
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_shortcut(
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_file_shortcut(
    adm_ent_file_shortcut_typ * ent_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_uninstall_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_create_folder(
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_remove_folder(
    adm_ent_remove_folder_typ * ent_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_environment(
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_registry_key(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_registry_value(
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_feature(
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_product(
    void * source_object,
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_icon(
    void * source_object,
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_package(
    void * source_object,
    adm_ent_package_typ * ent_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_property(
    void * source_object,
    adm_ent_property_typ * ent_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_directory(
    void * source_object,
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_component(
    void * source_object,
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_file(
    void * source_object,
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_shortcut(
    void * source_object,
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_file_shortcut(
    void * source_object,
    adm_ent_file_shortcut_typ * ent_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_uninstall_shortcut(
    void * source_object,
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_create_folder(
    void * source_object,
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_remove_folder(
    void * source_object,
    adm_ent_remove_folder_typ * ent_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_environment(
    void * source_object,
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_registry_key(
    void * source_object,
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_registry_value(
    void * source_object,
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_feature(
    void * source_object,
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_product_includes_icon(
    adm_ent_product_typ * ent_source_product,
    adm_ent_icon_typ * ent_target_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_product_includes_package(
    adm_ent_product_typ * ent_source_product,
    adm_ent_package_typ * ent_target_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_product_includes_property(
    adm_ent_product_typ * ent_source_product,
    adm_ent_property_typ * ent_target_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_product_includes_directory(
    adm_ent_product_typ * ent_source_product,
    adm_ent_directory_typ * ent_target_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_product_includes_feature(
    adm_ent_product_typ * ent_source_product,
    adm_ent_feature_typ * ent_target_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_directory_includes_component(
    adm_ent_directory_typ * ent_source_directory,
    adm_ent_component_typ * ent_target_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_directory_includes_directory(
    adm_ent_directory_typ * ent_source_directory,
    adm_ent_directory_typ * ent_target_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_file(
    adm_ent_component_typ * ent_source_component,
    adm_ent_file_typ * ent_target_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_uninstall_shortcut(
    adm_ent_component_typ * ent_source_component,
    adm_ent_uninstall_shortcut_typ * ent_target_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_create_folder(
    adm_ent_component_typ * ent_source_component,
    adm_ent_create_folder_typ * ent_target_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_remove_folder(
    adm_ent_component_typ * ent_source_component,
    adm_ent_remove_folder_typ * ent_target_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_environment(
    adm_ent_component_typ * ent_source_component,
    adm_ent_environment_typ * ent_target_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_registry_key(
    adm_ent_component_typ * ent_source_component,
    adm_ent_registry_key_typ * ent_target_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_component_includes_registry_value(
    adm_ent_component_typ * ent_source_component,
    adm_ent_registry_value_typ * ent_target_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_file_includes_file_shortcut(
    adm_ent_file_typ * ent_source_file,
    adm_ent_file_shortcut_typ * ent_target_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_file_shortcut_specialisation_shortcut(
    adm_ent_file_shortcut_typ * ent_source_file_shortcut,
    adm_ent_shortcut_typ * ent_target_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_uninstall_shortcut_specialisation_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_source_uninstall_shortcut,
    adm_ent_shortcut_typ * ent_target_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_registry_key_includes_registry_value(
    adm_ent_registry_key_typ * ent_source_registry_key,
    adm_ent_registry_value_typ * ent_target_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_feature_includes_component(
    adm_ent_feature_typ * ent_source_feature,
    adm_ent_component_typ * ent_target_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_feature_includes_feature(
    adm_ent_feature_typ * ent_source_feature,
    adm_ent_feature_typ * ent_target_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_product_includes_icon(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_icon_typ * rel_product_includes_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_product_includes_package(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_package_typ * rel_product_includes_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_product_includes_property(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_property_typ * rel_product_includes_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_product_includes_directory(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_directory_typ * rel_product_includes_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_product_includes_feature(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_feature_typ * rel_product_includes_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_directory_includes_component(
    adm_ent_directory_typ * ent_directory,
    adm_rel_directory_includes_component_typ * rel_directory_includes_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_directory_includes_directory(
    adm_ent_directory_typ * ent_directory,
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_file(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_file_typ * rel_component_includes_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_uninstall_shortcut(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_uninstall_shortcut_typ * rel_component_includes_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_create_folder(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_create_folder_typ * rel_component_includes_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_remove_folder(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_remove_folder_typ * rel_component_includes_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_environment(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_environment_typ * rel_component_includes_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_registry_key(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_registry_key_typ * rel_component_includes_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_component_includes_registry_value(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_registry_value_typ * rel_component_includes_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_file_includes_file_shortcut(
    adm_ent_file_typ * ent_file,
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_file_shortcut_specialisation_shortcut(
    adm_ent_file_shortcut_typ * ent_file_shortcut,
    adm_rel_file_shortcut_specialisation_shortcut_typ * rel_file_shortcut_specialisation_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_uninstall_shortcut_specialisation_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_rel_uninstall_shortcut_specialisation_shortcut_typ * rel_uninstall_shortcut_specialisation_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_registry_key_includes_registry_value(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_rel_registry_key_includes_registry_value_typ * rel_registry_key_includes_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_feature_includes_component(
    adm_ent_feature_typ * ent_feature,
    adm_rel_feature_includes_component_typ * rel_feature_includes_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_feature_includes_feature(
    adm_ent_feature_typ * ent_feature,
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_product(
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_icon(
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_package(
    adm_ent_package_typ * ent_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_property(
    adm_ent_property_typ * ent_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_directory(
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_component(
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_file(
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_shortcut(
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_file_shortcut(
    adm_ent_file_shortcut_typ * ent_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_uninstall_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_create_folder(
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_remove_folder(
    adm_ent_remove_folder_typ * ent_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_environment(
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_registry_key(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_registry_value(
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_feature(
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_product_generate(
    void * source_object,
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_product         (void);
void adm_dispatch_home_pool_product (void);

adm_pool_target_product_typ * adm_find_home_target_event_product (void);
adm_pool_target_product_typ * adm_find_away_target_event_product (void);

void adm_dispatch_state_action_product(
    adm_pool_target_product_typ * pool_target_product);


/* State Action Prototypes */

void adm_state_action_product_generating(
    adm_ent_product_typ * ent_product);


/* Process Include Entity Prototypes */

void adm_ent_pro_product_001_005_001_process_generate_directory(
    adm_ent_directory_typ * ent_directory_0000000007);

void adm_ent_pro_product_001_015_001_process_generate_registry_value(
    adm_ent_registry_value_typ * ent_registry_value_0000000032);

void adm_ent_pro_product_001_016_001_process_generate_feature(
    adm_ent_feature_typ * ent_feature_0000000041);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */