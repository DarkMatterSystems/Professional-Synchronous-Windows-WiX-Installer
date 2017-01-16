
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_PRODUCT_GENERATING
} adm_sta_product_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_PRODUCT_GENERATE
} adm_evt_product_typ;


/* Entity Type Defines */

/* Product */

typedef struct adm_ent_product {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_product_typ status;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_name;
    adm_str_text_typ * atb_upgrade_code;
    adm_str_text_typ * atb_version;
    adm_str_text_typ * atb_manufacturer;
    adm_str_text_typ * atb_download_version;
    struct adm_rel_product_includes_icon * rel_includes_icon_head;
    struct adm_rel_product_includes_icon * rel_includes_icon_tail;
    struct adm_rel_product_includes_package * rel_includes_package_head;
    struct adm_rel_product_includes_package * rel_includes_package_tail;
    struct adm_rel_product_includes_property * rel_includes_property_head;
    struct adm_rel_product_includes_property * rel_includes_property_tail;
    struct adm_rel_product_includes_directory * rel_includes_directory_head;
    struct adm_rel_product_includes_directory * rel_includes_directory_tail;
    struct adm_rel_product_includes_feature * rel_includes_feature_head;
    struct adm_rel_product_includes_feature * rel_includes_feature_tail;
    struct adm_ent_product * back;
    struct adm_ent_product * next;
} adm_ent_product_typ;

/* Icon */

typedef struct adm_ent_icon {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_source_file;
    struct adm_ent_icon * back;
    struct adm_ent_icon * next;
} adm_ent_icon_typ;

/* Package */

typedef struct adm_ent_package {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_description;
    adm_str_text_typ * atb_comments;
    adm_str_text_typ * atb_manufacture;
    struct adm_ent_package * back;
    struct adm_ent_package * next;
} adm_ent_package_typ;

/* Property */

typedef struct adm_ent_property {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_value;
    struct adm_ent_property * back;
    struct adm_ent_property * next;
} adm_ent_property_typ;

/* Directory */

typedef struct adm_ent_directory {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_name;
    adm_str_text_typ * atb_heading;
    struct adm_rel_directory_includes_component * rel_includes_component_head;
    struct adm_rel_directory_includes_component * rel_includes_component_tail;
    struct adm_rel_directory_includes_directory * rel_includes_directory_head;
    struct adm_rel_directory_includes_directory * rel_includes_directory_tail;
    struct adm_ent_directory * back;
    struct adm_ent_directory * next;
} adm_ent_directory_typ;

/* Component */

typedef struct adm_ent_component {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_guid;
    adm_str_text_typ * atb_condition;
    struct adm_rel_component_includes_file * rel_includes_file_head;
    struct adm_rel_component_includes_file * rel_includes_file_tail;
    struct adm_rel_component_includes_uninstall_shortcut * rel_includes_uninstall_shortcut_head;
    struct adm_rel_component_includes_uninstall_shortcut * rel_includes_uninstall_shortcut_tail;
    struct adm_rel_component_includes_create_folder * rel_includes_create_folder_head;
    struct adm_rel_component_includes_create_folder * rel_includes_create_folder_tail;
    struct adm_rel_component_includes_remove_folder * rel_includes_remove_folder_head;
    struct adm_rel_component_includes_remove_folder * rel_includes_remove_folder_tail;
    struct adm_rel_component_includes_environment * rel_includes_environment_head;
    struct adm_rel_component_includes_environment * rel_includes_environment_tail;
    struct adm_rel_component_includes_registry_key * rel_includes_registry_key_head;
    struct adm_rel_component_includes_registry_key * rel_includes_registry_key_tail;
    struct adm_rel_component_includes_registry_value * rel_includes_registry_value_head;
    struct adm_rel_component_includes_registry_value * rel_includes_registry_value_tail;
    struct adm_ent_component * back;
    struct adm_ent_component * next;
} adm_ent_component_typ;

/* File */

typedef struct adm_ent_file {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_name;
    adm_str_text_typ * atb_source;
    struct adm_rel_file_includes_file_shortcut * rel_includes_file_shortcut_head;
    struct adm_rel_file_includes_file_shortcut * rel_includes_file_shortcut_tail;
    struct adm_ent_file * back;
    struct adm_ent_file * next;
} adm_ent_file_typ;

/* Shortcut */

typedef struct adm_ent_shortcut {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_name;
    adm_str_text_typ * atb_description;
    struct adm_ent_shortcut * back;
    struct adm_ent_shortcut * next;
} adm_ent_shortcut_typ;

/* File Shortcut */

typedef struct adm_ent_file_shortcut {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_directory;
    adm_str_text_typ * atb_icon;
    struct adm_rel_file_shortcut_specialisation_shortcut * rel_specialisation_shortcut_head;
    struct adm_rel_file_shortcut_specialisation_shortcut * rel_specialisation_shortcut_tail;
    struct adm_ent_file_shortcut * back;
    struct adm_ent_file_shortcut * next;
} adm_ent_file_shortcut_typ;

/* Uninstall Shortcut */

typedef struct adm_ent_uninstall_shortcut {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_target;
    adm_str_text_typ * atb_arguments;
    struct adm_rel_uninstall_shortcut_specialisation_shortcut * rel_specialisation_shortcut_head;
    struct adm_rel_uninstall_shortcut_specialisation_shortcut * rel_specialisation_shortcut_tail;
    struct adm_ent_uninstall_shortcut * back;
    struct adm_ent_uninstall_shortcut * next;
} adm_ent_uninstall_shortcut_typ;

/* Create Folder */

typedef struct adm_ent_create_folder {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    struct adm_ent_create_folder * back;
    struct adm_ent_create_folder * next;
} adm_ent_create_folder_typ;

/* Remove Folder */

typedef struct adm_ent_remove_folder {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_on;
    struct adm_ent_remove_folder * back;
    struct adm_ent_remove_folder * next;
} adm_ent_remove_folder_typ;

/* Environment */

typedef struct adm_ent_environment {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_name;
    adm_str_text_typ * atb_value;
    struct adm_ent_environment * back;
    struct adm_ent_environment * next;
} adm_ent_environment_typ;

/* Registry Key */

typedef struct adm_ent_registry_key {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_root;
    adm_str_text_typ * atb_key;
    struct adm_rel_registry_key_includes_registry_value * rel_includes_registry_value_head;
    struct adm_rel_registry_key_includes_registry_value * rel_includes_registry_value_tail;
    struct adm_ent_registry_key * back;
    struct adm_ent_registry_key * next;
} adm_ent_registry_key_typ;

/* Registry Value */

typedef struct adm_ent_registry_value {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_root;
    adm_str_text_typ * atb_key;
    adm_str_text_typ * atb_value;
    struct adm_ent_registry_value * back;
    struct adm_ent_registry_value * next;
} adm_ent_registry_value_typ;

/* Feature */

typedef struct adm_ent_feature {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_str_text_typ * atb_id;
    adm_str_text_typ * atb_title;
    adm_str_text_typ * atb_display;
    adm_str_text_typ * atb_description;
    adm_str_text_typ * atb_configurable_directory;
    adm_str_text_typ * atb_heading;
    struct adm_rel_feature_includes_component * rel_includes_component_head;
    struct adm_rel_feature_includes_component * rel_includes_component_tail;
    struct adm_rel_feature_includes_feature * rel_includes_feature_head;
    struct adm_rel_feature_includes_feature * rel_includes_feature_tail;
    struct adm_ent_feature * back;
    struct adm_ent_feature * next;
} adm_ent_feature_typ;


/* Relationship Type Defines */

typedef struct adm_rel_product_includes_icon {
    adm_ent_icon_typ * ent_icon;
    struct adm_rel_product_includes_icon * back;
    struct adm_rel_product_includes_icon * next;
} adm_rel_product_includes_icon_typ;

typedef struct adm_rel_product_includes_package {
    adm_ent_package_typ * ent_package;
    struct adm_rel_product_includes_package * back;
    struct adm_rel_product_includes_package * next;
} adm_rel_product_includes_package_typ;

typedef struct adm_rel_product_includes_property {
    adm_ent_property_typ * ent_property;
    struct adm_rel_product_includes_property * back;
    struct adm_rel_product_includes_property * next;
} adm_rel_product_includes_property_typ;

typedef struct adm_rel_product_includes_directory {
    adm_ent_directory_typ * ent_directory;
    struct adm_rel_product_includes_directory * back;
    struct adm_rel_product_includes_directory * next;
} adm_rel_product_includes_directory_typ;

typedef struct adm_rel_product_includes_feature {
    adm_ent_feature_typ * ent_feature;
    struct adm_rel_product_includes_feature * back;
    struct adm_rel_product_includes_feature * next;
} adm_rel_product_includes_feature_typ;

typedef struct adm_rel_directory_includes_component {
    adm_ent_component_typ * ent_component;
    struct adm_rel_directory_includes_component * back;
    struct adm_rel_directory_includes_component * next;
} adm_rel_directory_includes_component_typ;

typedef struct adm_rel_directory_includes_directory {
    adm_ent_directory_typ * ent_directory;
    struct adm_rel_directory_includes_directory * back;
    struct adm_rel_directory_includes_directory * next;
} adm_rel_directory_includes_directory_typ;

typedef struct adm_rel_component_includes_file {
    adm_ent_file_typ * ent_file;
    struct adm_rel_component_includes_file * back;
    struct adm_rel_component_includes_file * next;
} adm_rel_component_includes_file_typ;

typedef struct adm_rel_component_includes_uninstall_shortcut {
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut;
    struct adm_rel_component_includes_uninstall_shortcut * back;
    struct adm_rel_component_includes_uninstall_shortcut * next;
} adm_rel_component_includes_uninstall_shortcut_typ;

typedef struct adm_rel_component_includes_create_folder {
    adm_ent_create_folder_typ * ent_create_folder;
    struct adm_rel_component_includes_create_folder * back;
    struct adm_rel_component_includes_create_folder * next;
} adm_rel_component_includes_create_folder_typ;

typedef struct adm_rel_component_includes_remove_folder {
    adm_ent_remove_folder_typ * ent_remove_folder;
    struct adm_rel_component_includes_remove_folder * back;
    struct adm_rel_component_includes_remove_folder * next;
} adm_rel_component_includes_remove_folder_typ;

typedef struct adm_rel_component_includes_environment {
    adm_ent_environment_typ * ent_environment;
    struct adm_rel_component_includes_environment * back;
    struct adm_rel_component_includes_environment * next;
} adm_rel_component_includes_environment_typ;

typedef struct adm_rel_component_includes_registry_key {
    adm_ent_registry_key_typ * ent_registry_key;
    struct adm_rel_component_includes_registry_key * back;
    struct adm_rel_component_includes_registry_key * next;
} adm_rel_component_includes_registry_key_typ;

typedef struct adm_rel_component_includes_registry_value {
    adm_ent_registry_value_typ * ent_registry_value;
    struct adm_rel_component_includes_registry_value * back;
    struct adm_rel_component_includes_registry_value * next;
} adm_rel_component_includes_registry_value_typ;

typedef struct adm_rel_file_includes_file_shortcut {
    adm_ent_file_shortcut_typ * ent_file_shortcut;
    struct adm_rel_file_includes_file_shortcut * back;
    struct adm_rel_file_includes_file_shortcut * next;
} adm_rel_file_includes_file_shortcut_typ;

typedef struct adm_rel_file_shortcut_specialisation_shortcut {
    adm_ent_shortcut_typ * ent_shortcut;
    struct adm_rel_file_shortcut_specialisation_shortcut * back;
    struct adm_rel_file_shortcut_specialisation_shortcut * next;
} adm_rel_file_shortcut_specialisation_shortcut_typ;

typedef struct adm_rel_uninstall_shortcut_specialisation_shortcut {
    adm_ent_shortcut_typ * ent_shortcut;
    struct adm_rel_uninstall_shortcut_specialisation_shortcut * back;
    struct adm_rel_uninstall_shortcut_specialisation_shortcut * next;
} adm_rel_uninstall_shortcut_specialisation_shortcut_typ;

typedef struct adm_rel_registry_key_includes_registry_value {
    adm_ent_registry_value_typ * ent_registry_value;
    struct adm_rel_registry_key_includes_registry_value * back;
    struct adm_rel_registry_key_includes_registry_value * next;
} adm_rel_registry_key_includes_registry_value_typ;

typedef struct adm_rel_feature_includes_component {
    adm_ent_component_typ * ent_component;
    struct adm_rel_feature_includes_component * back;
    struct adm_rel_feature_includes_component * next;
} adm_rel_feature_includes_component_typ;

typedef struct adm_rel_feature_includes_feature {
    adm_ent_feature_typ * ent_feature;
    struct adm_rel_feature_includes_feature * back;
    struct adm_rel_feature_includes_feature * next;
} adm_rel_feature_includes_feature_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_product {
    adm_evt_product_typ evente;
    adm_ent_product_typ * ent_product;
    adm_error_location_typ error_location;
    struct adm_pool_target_product * next;
} adm_pool_target_product_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_product_typ * live_list_head;
    adm_ent_product_typ * live_list_tail;
    adm_ent_product_typ * dead_list_head;
    adm_ent_product_typ * dead_list_tail;
    adm_pool_target_product_typ * home_pool_head;
    adm_pool_target_product_typ * home_pool_tail;
    adm_pool_target_product_typ * away_pool_head;
    adm_pool_target_product_typ * away_pool_tail;
} adm_entity_system_product_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_icon_typ * live_list_head;
    adm_ent_icon_typ * live_list_tail;
    adm_ent_icon_typ * dead_list_head;
    adm_ent_icon_typ * dead_list_tail;
} adm_entity_system_icon_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_package_typ * live_list_head;
    adm_ent_package_typ * live_list_tail;
    adm_ent_package_typ * dead_list_head;
    adm_ent_package_typ * dead_list_tail;
} adm_entity_system_package_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_property_typ * live_list_head;
    adm_ent_property_typ * live_list_tail;
    adm_ent_property_typ * dead_list_head;
    adm_ent_property_typ * dead_list_tail;
} adm_entity_system_property_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_directory_typ * live_list_head;
    adm_ent_directory_typ * live_list_tail;
    adm_ent_directory_typ * dead_list_head;
    adm_ent_directory_typ * dead_list_tail;
} adm_entity_system_directory_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_component_typ * live_list_head;
    adm_ent_component_typ * live_list_tail;
    adm_ent_component_typ * dead_list_head;
    adm_ent_component_typ * dead_list_tail;
} adm_entity_system_component_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_file_typ * live_list_head;
    adm_ent_file_typ * live_list_tail;
    adm_ent_file_typ * dead_list_head;
    adm_ent_file_typ * dead_list_tail;
} adm_entity_system_file_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_shortcut_typ * live_list_head;
    adm_ent_shortcut_typ * live_list_tail;
    adm_ent_shortcut_typ * dead_list_head;
    adm_ent_shortcut_typ * dead_list_tail;
} adm_entity_system_shortcut_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_file_shortcut_typ * live_list_head;
    adm_ent_file_shortcut_typ * live_list_tail;
    adm_ent_file_shortcut_typ * dead_list_head;
    adm_ent_file_shortcut_typ * dead_list_tail;
} adm_entity_system_file_shortcut_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_uninstall_shortcut_typ * live_list_head;
    adm_ent_uninstall_shortcut_typ * live_list_tail;
    adm_ent_uninstall_shortcut_typ * dead_list_head;
    adm_ent_uninstall_shortcut_typ * dead_list_tail;
} adm_entity_system_uninstall_shortcut_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_create_folder_typ * live_list_head;
    adm_ent_create_folder_typ * live_list_tail;
    adm_ent_create_folder_typ * dead_list_head;
    adm_ent_create_folder_typ * dead_list_tail;
} adm_entity_system_create_folder_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_remove_folder_typ * live_list_head;
    adm_ent_remove_folder_typ * live_list_tail;
    adm_ent_remove_folder_typ * dead_list_head;
    adm_ent_remove_folder_typ * dead_list_tail;
} adm_entity_system_remove_folder_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_environment_typ * live_list_head;
    adm_ent_environment_typ * live_list_tail;
    adm_ent_environment_typ * dead_list_head;
    adm_ent_environment_typ * dead_list_tail;
} adm_entity_system_environment_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_registry_key_typ * live_list_head;
    adm_ent_registry_key_typ * live_list_tail;
    adm_ent_registry_key_typ * dead_list_head;
    adm_ent_registry_key_typ * dead_list_tail;
} adm_entity_system_registry_key_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_registry_value_typ * live_list_head;
    adm_ent_registry_value_typ * live_list_tail;
    adm_ent_registry_value_typ * dead_list_head;
    adm_ent_registry_value_typ * dead_list_tail;
} adm_entity_system_registry_value_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_feature_typ * live_list_head;
    adm_ent_feature_typ * live_list_tail;
    adm_ent_feature_typ * dead_list_head;
    adm_ent_feature_typ * dead_list_tail;
} adm_entity_system_feature_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_product_typ ent_product;
    adm_entity_system_icon_typ ent_icon;
    adm_entity_system_package_typ ent_package;
    adm_entity_system_property_typ ent_property;
    adm_entity_system_directory_typ ent_directory;
    adm_entity_system_component_typ ent_component;
    adm_entity_system_file_typ ent_file;
    adm_entity_system_shortcut_typ ent_shortcut;
    adm_entity_system_file_shortcut_typ ent_file_shortcut;
    adm_entity_system_uninstall_shortcut_typ ent_uninstall_shortcut;
    adm_entity_system_create_folder_typ ent_create_folder;
    adm_entity_system_remove_folder_typ ent_remove_folder;
    adm_entity_system_environment_typ ent_environment;
    adm_entity_system_registry_key_typ ent_registry_key;
    adm_entity_system_registry_value_typ ent_registry_value;
    adm_entity_system_feature_typ ent_feature;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */