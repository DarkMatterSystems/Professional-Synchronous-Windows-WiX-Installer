
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Icon Simulator Display Entity */

void adm_sim_display_entity_icon(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_icon_typ * ent_icon;

    adm_sim_width_icon_typ width_icon;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_icon");
    #endif

    width_icon.identity = strlen("Identity");
    width_icon.atb_id = strlen("Id");
    width_icon.atb_source_file = strlen("Source_file");

    ent_icon = adm_entity_system.ent_icon.live_list_head;

    while (ent_icon != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_icon->identity);
        if (width > width_icon.identity) width_icon.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_icon->atb_id);
        if (width > width_icon.atb_id) width_icon.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_icon->atb_source_file);
        if (width > width_icon.atb_source_file) width_icon.atb_source_file = width;

        ent_icon = ent_icon->next;
    }

    printf(NEWLINE);
    printf("Icon:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_icon.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_icon.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_icon.atb_source_file, "Source_file");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_icon.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_icon.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_icon.atb_source_file);

    ent_icon = adm_entity_system.ent_icon.live_list_head;

    while (ent_icon != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_icon.identity, ent_icon->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_icon->atb_id);
        printf("%-*s", width_icon.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_icon->atb_source_file);
        printf("%-*s", width_icon.atb_source_file, buffer);

        ent_icon = ent_icon->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_icon");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */