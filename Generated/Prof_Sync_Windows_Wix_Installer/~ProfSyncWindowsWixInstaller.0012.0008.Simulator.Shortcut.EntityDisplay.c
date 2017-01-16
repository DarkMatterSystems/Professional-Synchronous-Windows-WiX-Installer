
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Shortcut Simulator Display Entity */

void adm_sim_display_entity_shortcut(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_shortcut_typ * ent_shortcut;

    adm_sim_width_shortcut_typ width_shortcut;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_shortcut");
    #endif

    width_shortcut.identity = strlen("Identity");
    width_shortcut.atb_id = strlen("Id");
    width_shortcut.atb_name = strlen("Name");
    width_shortcut.atb_description = strlen("Description");

    ent_shortcut = adm_entity_system.ent_shortcut.live_list_head;

    while (ent_shortcut != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_shortcut->identity);
        if (width > width_shortcut.identity) width_shortcut.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_id);
        if (width > width_shortcut.atb_id) width_shortcut.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_name);
        if (width > width_shortcut.atb_name) width_shortcut.atb_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_description);
        if (width > width_shortcut.atb_description) width_shortcut.atb_description = width;

        ent_shortcut = ent_shortcut->next;
    }

    printf(NEWLINE);
    printf("Shortcut:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_shortcut.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_shortcut.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_shortcut.atb_name, "Name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_shortcut.atb_description, "Description");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_shortcut.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_shortcut.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_shortcut.atb_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_shortcut.atb_description);

    ent_shortcut = adm_entity_system.ent_shortcut.live_list_head;

    while (ent_shortcut != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_shortcut.identity, ent_shortcut->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_id);
        printf("%-*s", width_shortcut.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_name);
        printf("%-*s", width_shortcut.atb_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_shortcut->atb_description);
        printf("%-*s", width_shortcut.atb_description, buffer);

        ent_shortcut = ent_shortcut->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_shortcut");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */