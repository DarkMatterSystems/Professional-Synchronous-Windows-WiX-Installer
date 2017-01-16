
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Package Simulator Display Entity */

void adm_sim_display_entity_package(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_package_typ * ent_package;

    adm_sim_width_package_typ width_package;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_package");
    #endif

    width_package.identity = strlen("Identity");
    width_package.atb_description = strlen("Description");
    width_package.atb_comments = strlen("Comments");
    width_package.atb_manufacture = strlen("Manufacture");

    ent_package = adm_entity_system.ent_package.live_list_head;

    while (ent_package != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_package->identity);
        if (width > width_package.identity) width_package.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_description);
        if (width > width_package.atb_description) width_package.atb_description = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_comments);
        if (width > width_package.atb_comments) width_package.atb_comments = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_manufacture);
        if (width > width_package.atb_manufacture) width_package.atb_manufacture = width;

        ent_package = ent_package->next;
    }

    printf(NEWLINE);
    printf("Package:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_package.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_package.atb_description, "Description");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_package.atb_comments, "Comments");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_package.atb_manufacture, "Manufacture");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_package.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_package.atb_description);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_package.atb_comments);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_package.atb_manufacture);

    ent_package = adm_entity_system.ent_package.live_list_head;

    while (ent_package != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_package.identity, ent_package->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_description);
        printf("%-*s", width_package.atb_description, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_comments);
        printf("%-*s", width_package.atb_comments, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_package->atb_manufacture);
        printf("%-*s", width_package.atb_manufacture, buffer);

        ent_package = ent_package->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_package");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */