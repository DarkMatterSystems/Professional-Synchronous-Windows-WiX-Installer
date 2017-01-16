
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Create Folder Simulator Display Entity */

void adm_sim_display_entity_create_folder(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_create_folder_typ * ent_create_folder;

    adm_sim_width_create_folder_typ width_create_folder;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_create_folder");
    #endif

    width_create_folder.identity = strlen("Identity");

    ent_create_folder = adm_entity_system.ent_create_folder.live_list_head;

    while (ent_create_folder != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_create_folder->identity);
        if (width > width_create_folder.identity) width_create_folder.identity = width;

        ent_create_folder = ent_create_folder->next;
    }

    printf(NEWLINE);
    printf("Create_Folder:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_create_folder.identity, "Identity");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_create_folder.identity);

    ent_create_folder = adm_entity_system.ent_create_folder.live_list_head;

    while (ent_create_folder != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_create_folder.identity, ent_create_folder->identity);

        ent_create_folder = ent_create_folder->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_create_folder");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */