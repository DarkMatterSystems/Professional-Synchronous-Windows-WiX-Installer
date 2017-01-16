
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Uninstall Shortcut Simulator Display Entity */

void adm_sim_display_entity_uninstall_shortcut(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut;

    adm_sim_width_uninstall_shortcut_typ width_uninstall_shortcut;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_uninstall_shortcut");
    #endif

    width_uninstall_shortcut.identity = strlen("Identity");
    width_uninstall_shortcut.atb_target = strlen("Target");
    width_uninstall_shortcut.atb_arguments = strlen("Arguments");

    ent_uninstall_shortcut = adm_entity_system.ent_uninstall_shortcut.live_list_head;

    while (ent_uninstall_shortcut != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_uninstall_shortcut->identity);
        if (width > width_uninstall_shortcut.identity) width_uninstall_shortcut.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_uninstall_shortcut->atb_target);
        if (width > width_uninstall_shortcut.atb_target) width_uninstall_shortcut.atb_target = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_uninstall_shortcut->atb_arguments);
        if (width > width_uninstall_shortcut.atb_arguments) width_uninstall_shortcut.atb_arguments = width;

        ent_uninstall_shortcut = ent_uninstall_shortcut->next;
    }

    printf(NEWLINE);
    printf("Uninstall_Shortcut:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_uninstall_shortcut.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_uninstall_shortcut.atb_target, "Target");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_uninstall_shortcut.atb_arguments, "Arguments");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_uninstall_shortcut.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_uninstall_shortcut.atb_target);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_uninstall_shortcut.atb_arguments);

    ent_uninstall_shortcut = adm_entity_system.ent_uninstall_shortcut.live_list_head;

    while (ent_uninstall_shortcut != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_uninstall_shortcut.identity, ent_uninstall_shortcut->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_uninstall_shortcut->atb_target);
        printf("%-*s", width_uninstall_shortcut.atb_target, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_uninstall_shortcut->atb_arguments);
        printf("%-*s", width_uninstall_shortcut.atb_arguments, buffer);

        ent_uninstall_shortcut = ent_uninstall_shortcut->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_uninstall_shortcut");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */