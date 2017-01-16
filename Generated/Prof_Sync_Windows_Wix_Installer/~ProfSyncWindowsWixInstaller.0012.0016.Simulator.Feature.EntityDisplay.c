
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Feature Simulator Display Entity */

void adm_sim_display_entity_feature(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_feature_typ * ent_feature;

    adm_sim_width_feature_typ width_feature;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_feature");
    #endif

    width_feature.identity = strlen("Identity");
    width_feature.atb_id = strlen("Id");
    width_feature.atb_title = strlen("Title");
    width_feature.atb_display = strlen("Display");
    width_feature.atb_description = strlen("Description");
    width_feature.atb_configurable_directory = strlen("Configurable_directory");
    width_feature.atb_heading = strlen("Heading");

    ent_feature = adm_entity_system.ent_feature.live_list_head;

    while (ent_feature != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_feature->identity);
        if (width > width_feature.identity) width_feature.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_id);
        if (width > width_feature.atb_id) width_feature.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_title);
        if (width > width_feature.atb_title) width_feature.atb_title = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_display);
        if (width > width_feature.atb_display) width_feature.atb_display = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_description);
        if (width > width_feature.atb_description) width_feature.atb_description = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_configurable_directory);
        if (width > width_feature.atb_configurable_directory) width_feature.atb_configurable_directory = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_heading);
        if (width > width_feature.atb_heading) width_feature.atb_heading = width;

        ent_feature = ent_feature->next;
    }

    printf(NEWLINE);
    printf("Feature:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_feature.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_title, "Title");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_display, "Display");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_description, "Description");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_configurable_directory, "Configurable_directory");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_feature.atb_heading, "Heading");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_feature.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_title);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_display);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_description);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_configurable_directory);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_feature.atb_heading);

    ent_feature = adm_entity_system.ent_feature.live_list_head;

    while (ent_feature != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_feature.identity, ent_feature->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_id);
        printf("%-*s", width_feature.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_title);
        printf("%-*s", width_feature.atb_title, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_display);
        printf("%-*s", width_feature.atb_display, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_description);
        printf("%-*s", width_feature.atb_description, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_configurable_directory);
        printf("%-*s", width_feature.atb_configurable_directory, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_feature->atb_heading);
        printf("%-*s", width_feature.atb_heading, buffer);

        ent_feature = ent_feature->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_feature");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */