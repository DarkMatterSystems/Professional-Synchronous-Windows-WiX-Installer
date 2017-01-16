
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_product(
    void);

void adm_sim_display_entity_icon(
    void);

void adm_sim_display_entity_package(
    void);

void adm_sim_display_entity_property(
    void);

void adm_sim_display_entity_directory(
    void);

void adm_sim_display_entity_component(
    void);

void adm_sim_display_entity_file(
    void);

void adm_sim_display_entity_shortcut(
    void);

void adm_sim_display_entity_file_shortcut(
    void);

void adm_sim_display_entity_uninstall_shortcut(
    void);

void adm_sim_display_entity_create_folder(
    void);

void adm_sim_display_entity_remove_folder(
    void);

void adm_sim_display_entity_environment(
    void);

void adm_sim_display_entity_registry_key(
    void);

void adm_sim_display_entity_registry_value(
    void);

void adm_sim_display_entity_feature(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_product_generate(
    void);


/* Acquire Identifier Event Prototypes */


/* Display Event Prototypes */

void adm_sim_display_event_product_generate(
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_product_generating(
    adm_pool_target_product_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */