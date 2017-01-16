
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_PRODUCT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_ICON,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_PACKAGE,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_PROPERTY,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_DIRECTORY,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_COMPONENT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_FILE,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_SHORTCUT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_FILE_SHORTCUT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_UNINSTALL_SHORTCUT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_CREATE_FOLDER,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_REMOVE_FOLDER,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_ENVIRONMENT,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_REGISTRY_KEY,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_REGISTRY_VALUE,
    ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_FEATURE
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_MATRIX_INSTALLER_PRODUCT_GENERATE
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_name;
    adm_base_integer_typ atb_upgrade_code;
    adm_base_integer_typ atb_version;
    adm_base_integer_typ atb_manufacturer;
    adm_base_integer_typ atb_download_version;
} adm_sim_width_product_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_source_file;
} adm_sim_width_icon_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_description;
    adm_base_integer_typ atb_comments;
    adm_base_integer_typ atb_manufacture;
} adm_sim_width_package_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_value;
} adm_sim_width_property_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_name;
    adm_base_integer_typ atb_heading;
} adm_sim_width_directory_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_guid;
    adm_base_integer_typ atb_condition;
} adm_sim_width_component_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_name;
    adm_base_integer_typ atb_source;
} adm_sim_width_file_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_name;
    adm_base_integer_typ atb_description;
} adm_sim_width_shortcut_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_directory;
    adm_base_integer_typ atb_icon;
} adm_sim_width_file_shortcut_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_target;
    adm_base_integer_typ atb_arguments;
} adm_sim_width_uninstall_shortcut_typ;

typedef struct {
    adm_base_integer_typ identity;
} adm_sim_width_create_folder_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_on;
} adm_sim_width_remove_folder_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_name;
    adm_base_integer_typ atb_value;
} adm_sim_width_environment_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_root;
    adm_base_integer_typ atb_key;
} adm_sim_width_registry_key_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_root;
    adm_base_integer_typ atb_key;
    adm_base_integer_typ atb_value;
} adm_sim_width_registry_value_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_id;
    adm_base_integer_typ atb_title;
    adm_base_integer_typ atb_display;
    adm_base_integer_typ atb_description;
    adm_base_integer_typ atb_configurable_directory;
    adm_base_integer_typ atb_heading;
} adm_sim_width_feature_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */