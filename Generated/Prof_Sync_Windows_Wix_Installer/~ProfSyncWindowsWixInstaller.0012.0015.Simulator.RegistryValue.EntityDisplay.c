
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Registry Value Simulator Display Entity */

void adm_sim_display_entity_registry_value(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_registry_value_typ * ent_registry_value;

    adm_sim_width_registry_value_typ width_registry_value;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_registry_value");
    #endif

    width_registry_value.identity = strlen("Identity");
    width_registry_value.atb_root = strlen("Root");
    width_registry_value.atb_key = strlen("Key");
    width_registry_value.atb_value = strlen("Value");

    ent_registry_value = adm_entity_system.ent_registry_value.live_list_head;

    while (ent_registry_value != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_registry_value->identity);
        if (width > width_registry_value.identity) width_registry_value.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_root);
        if (width > width_registry_value.atb_root) width_registry_value.atb_root = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_key);
        if (width > width_registry_value.atb_key) width_registry_value.atb_key = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_value);
        if (width > width_registry_value.atb_value) width_registry_value.atb_value = width;

        ent_registry_value = ent_registry_value->next;
    }

    printf(NEWLINE);
    printf("Registry_Value:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_registry_value.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_registry_value.atb_root, "Root");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_registry_value.atb_key, "Key");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_registry_value.atb_value, "Value");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_registry_value.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_registry_value.atb_root);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_registry_value.atb_key);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_registry_value.atb_value);

    ent_registry_value = adm_entity_system.ent_registry_value.live_list_head;

    while (ent_registry_value != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_registry_value.identity, ent_registry_value->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_root);
        printf("%-*s", width_registry_value.atb_root, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_key);
        printf("%-*s", width_registry_value.atb_key, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_registry_value->atb_value);
        printf("%-*s", width_registry_value.atb_value, buffer);

        ent_registry_value = ent_registry_value->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_registry_value");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */