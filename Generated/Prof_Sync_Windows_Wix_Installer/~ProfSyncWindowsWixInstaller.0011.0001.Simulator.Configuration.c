
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Matrix_Installer"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Product", TRUE, adm_sim_display_entity_product},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Icon", FALSE, adm_sim_display_entity_icon},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Package", FALSE, adm_sim_display_entity_package},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Property", FALSE, adm_sim_display_entity_property},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Directory", FALSE, adm_sim_display_entity_directory},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Component", FALSE, adm_sim_display_entity_component},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "File", FALSE, adm_sim_display_entity_file},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Shortcut", FALSE, adm_sim_display_entity_shortcut},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "File_Shortcut", FALSE, adm_sim_display_entity_file_shortcut},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Uninstall_Shortcut", FALSE, adm_sim_display_entity_uninstall_shortcut},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Create_Folder", FALSE, adm_sim_display_entity_create_folder},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Remove_Folder", FALSE, adm_sim_display_entity_remove_folder},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Environment", FALSE, adm_sim_display_entity_environment},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Registry_Key", FALSE, adm_sim_display_entity_registry_key},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Registry_Value", FALSE, adm_sim_display_entity_registry_value},
    {ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER, "Feature", FALSE, adm_sim_display_entity_feature},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_MATRIX_INSTALLER,
        ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_PRODUCT,
        "Generate",
        FALSE,
        adm_sim_acquire_identity_event_product_generate
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */