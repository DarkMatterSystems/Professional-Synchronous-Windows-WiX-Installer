
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Remove Folder Simulator Display Entity */

void adm_sim_display_entity_remove_folder(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_remove_folder_typ * ent_remove_folder;

    adm_sim_width_remove_folder_typ width_remove_folder;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_remove_folder");
    #endif

    width_remove_folder.identity = strlen("Identity");
    width_remove_folder.atb_id = strlen("Id");
    width_remove_folder.atb_on = strlen("On");

    ent_remove_folder = adm_entity_system.ent_remove_folder.live_list_head;

    while (ent_remove_folder != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_remove_folder->identity);
        if (width > width_remove_folder.identity) width_remove_folder.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_remove_folder->atb_id);
        if (width > width_remove_folder.atb_id) width_remove_folder.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_remove_folder->atb_on);
        if (width > width_remove_folder.atb_on) width_remove_folder.atb_on = width;

        ent_remove_folder = ent_remove_folder->next;
    }

    printf(NEWLINE);
    printf("Remove_Folder:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_remove_folder.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_remove_folder.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_remove_folder.atb_on, "On");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_remove_folder.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_remove_folder.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_remove_folder.atb_on);

    ent_remove_folder = adm_entity_system.ent_remove_folder.live_list_head;

    while (ent_remove_folder != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_remove_folder.identity, ent_remove_folder->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_remove_folder->atb_id);
        printf("%-*s", width_remove_folder.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_remove_folder->atb_on);
        printf("%-*s", width_remove_folder.atb_on, buffer);

        ent_remove_folder = ent_remove_folder->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_remove_folder");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */