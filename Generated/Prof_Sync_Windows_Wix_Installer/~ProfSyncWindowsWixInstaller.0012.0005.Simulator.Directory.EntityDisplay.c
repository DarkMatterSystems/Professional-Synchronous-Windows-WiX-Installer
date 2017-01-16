
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Directory Simulator Display Entity */

void adm_sim_display_entity_directory(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_directory_typ * ent_directory;

    adm_sim_width_directory_typ width_directory;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_directory");
    #endif

    width_directory.identity = strlen("Identity");
    width_directory.atb_id = strlen("Id");
    width_directory.atb_name = strlen("Name");
    width_directory.atb_heading = strlen("Heading");

    ent_directory = adm_entity_system.ent_directory.live_list_head;

    while (ent_directory != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_directory->identity);
        if (width > width_directory.identity) width_directory.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_id);
        if (width > width_directory.atb_id) width_directory.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_name);
        if (width > width_directory.atb_name) width_directory.atb_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_heading);
        if (width > width_directory.atb_heading) width_directory.atb_heading = width;

        ent_directory = ent_directory->next;
    }

    printf(NEWLINE);
    printf("Directory:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_directory.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_directory.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_directory.atb_name, "Name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_directory.atb_heading, "Heading");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_directory.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_directory.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_directory.atb_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_directory.atb_heading);

    ent_directory = adm_entity_system.ent_directory.live_list_head;

    while (ent_directory != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_directory.identity, ent_directory->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_id);
        printf("%-*s", width_directory.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_name);
        printf("%-*s", width_directory.atb_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_directory->atb_heading);
        printf("%-*s", width_directory.atb_heading, buffer);

        ent_directory = ent_directory->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_directory");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */