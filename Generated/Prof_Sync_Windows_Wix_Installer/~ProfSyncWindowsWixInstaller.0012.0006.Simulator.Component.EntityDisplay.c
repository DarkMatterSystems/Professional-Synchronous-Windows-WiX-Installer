
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Component Simulator Display Entity */

void adm_sim_display_entity_component(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_component_typ * ent_component;

    adm_sim_width_component_typ width_component;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_component");
    #endif

    width_component.identity = strlen("Identity");
    width_component.atb_id = strlen("Id");
    width_component.atb_guid = strlen("Guid");
    width_component.atb_condition = strlen("Condition");

    ent_component = adm_entity_system.ent_component.live_list_head;

    while (ent_component != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_component->identity);
        if (width > width_component.identity) width_component.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_id);
        if (width > width_component.atb_id) width_component.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_guid);
        if (width > width_component.atb_guid) width_component.atb_guid = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_condition);
        if (width > width_component.atb_condition) width_component.atb_condition = width;

        ent_component = ent_component->next;
    }

    printf(NEWLINE);
    printf("Component:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_component.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_component.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_component.atb_guid, "Guid");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_component.atb_condition, "Condition");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_component.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_component.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_component.atb_guid);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_component.atb_condition);

    ent_component = adm_entity_system.ent_component.live_list_head;

    while (ent_component != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_component.identity, ent_component->identity);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_id);
        printf("%-*s", width_component.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_guid);
        printf("%-*s", width_component.atb_guid, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_component->atb_condition);
        printf("%-*s", width_component.atb_condition, buffer);

        ent_component = ent_component->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_component");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */