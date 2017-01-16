
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Environment Simulator Display Entity */

void adm_sim_display_entity_environment(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_environment_typ * ent_environment;

    adm_sim_width_environment_typ width_environment;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_environment");
    #endif

    width_environment.identity = strlen("Identity");
    width_environment.atb_id = strlen("Id");
    width_environment.atb_name = strlen("Name");
    width_environment.atb_value = strlen("Value");

    ent_environment = adm_entity_system.ent_environment.live_list_head;

    while (ent_environment != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_environment->identity);
        if (width > width_environment.identity) width_environment.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_id);
        if (width > width_environment.atb_id) width_environment.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_name);
        if (width > width_environment.atb_name) width_environment.atb_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_value);
        if (width > width_environment.atb_value) width_environment.atb_value = width;

        ent_environment = ent_environment->next;
    }

    printf(NEWLINE);
    printf("Environment:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_environment.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_environment.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_environment.atb_name, "Name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_environment.atb_value, "Value");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_environment.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_environment.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_environment.atb_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_environment.atb_value);

    ent_environment = adm_entity_system.ent_environment.live_list_head;

    while (ent_environment != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_environment.identity, ent_environment->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_id);
        printf("%-*s", width_environment.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_name);
        printf("%-*s", width_environment.atb_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_environment->atb_value);
        printf("%-*s", width_environment.atb_value, buffer);

        ent_environment = ent_environment->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_environment");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */