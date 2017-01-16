
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* File Simulator Display Entity */

void adm_sim_display_entity_file(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_file_typ * ent_file;

    adm_sim_width_file_typ width_file;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_file");
    #endif

    width_file.identity = strlen("Identity");
    width_file.atb_id = strlen("Id");
    width_file.atb_name = strlen("Name");
    width_file.atb_source = strlen("Source");

    ent_file = adm_entity_system.ent_file.live_list_head;

    while (ent_file != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_file->identity);
        if (width > width_file.identity) width_file.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_id);
        if (width > width_file.atb_id) width_file.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_name);
        if (width > width_file.atb_name) width_file.atb_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_source);
        if (width > width_file.atb_source) width_file.atb_source = width;

        ent_file = ent_file->next;
    }

    printf(NEWLINE);
    printf("File:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_file.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_file.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_file.atb_name, "Name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_file.atb_source, "Source");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_file.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_file.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_file.atb_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_file.atb_source);

    ent_file = adm_entity_system.ent_file.live_list_head;

    while (ent_file != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_file.identity, ent_file->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_id);
        printf("%-*s", width_file.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_name);
        printf("%-*s", width_file.atb_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_file->atb_source);
        printf("%-*s", width_file.atb_source, buffer);

        ent_file = ent_file->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_file");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */