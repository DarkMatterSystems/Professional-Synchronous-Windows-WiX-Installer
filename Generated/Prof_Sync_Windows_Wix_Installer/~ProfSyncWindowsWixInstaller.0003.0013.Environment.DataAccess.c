
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Environment Data Access */

/* Make Entity Object */

adm_ent_environment_typ * adm_make_object_environment(
    void)
{
    adm_ent_environment_typ * ent_environment;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_environment");
    #endif

    if (adm_entity_system.ent_environment.dead_list_head != NULL) {

        ent_environment = adm_entity_system.ent_environment.dead_list_head;

        if (adm_entity_system.ent_environment.dead_list_head == ent_environment) {

            adm_entity_system.ent_environment.dead_list_head = ent_environment->next;

        } else {

            (ent_environment->back)->next = ent_environment->next;
        }

        if (adm_entity_system.ent_environment.dead_list_tail == ent_environment) {

            adm_entity_system.ent_environment.dead_list_tail = ent_environment->back;

        } else {

            (ent_environment->next)->back = ent_environment->back;
        }

    } else {

        ent_environment = (adm_ent_environment_typ*)adm_allocate_memory(sizeof(adm_ent_environment_typ));
    }

    ent_environment->identity = ++adm_entity_system.ent_environment.tote;

    ent_environment->unique  = FALSE;
    ent_environment->deleted = FALSE;
    ent_environment->marked  = FALSE;
    ent_environment->ignore  = null;

    ent_environment->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_environment->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_environment->atb_value = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_environment->back = NULL;
    ent_environment->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_environment");
    #endif

    return (ent_environment);
}


/* Bind Entity Object */

void adm_bind_object_environment(
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_environment");
    #endif

    adm_object_existent_environment(
        ent_environment,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_environment.live_list_head == NULL) {

        ent_environment->back = NULL;

        adm_entity_system.ent_environment.live_list_head = ent_environment;

    } else {

        ent_environment->back = adm_entity_system.ent_environment.live_list_tail;

        (adm_entity_system.ent_environment.live_list_tail)->next = ent_environment;
    }

    ent_environment->next = NULL;

    adm_entity_system.ent_environment.live_list_tail = ent_environment;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_environment");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_environment(
    void * source_object,
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_environment");
    #endif

    adm_object_existent_environment(
        ent_environment,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_environment) {

        if (adm_entity_system.ent_environment.live_list_head == ent_environment) {

            adm_entity_system.ent_environment.live_list_head = ent_environment->next;

        } else {

            (ent_environment->back)->next = ent_environment->next;
        }

        if (adm_entity_system.ent_environment.live_list_tail == ent_environment) {

            adm_entity_system.ent_environment.live_list_tail = ent_environment->back;

        } else {

            (ent_environment->next)->back = ent_environment->back;
        }

        adm_deallocate_memory(ent_environment->atb_id);
        adm_deallocate_memory(ent_environment->atb_name);
        adm_deallocate_memory(ent_environment->atb_value);

        ent_environment->deleted = TRUE;

        if (adm_entity_system.ent_environment.dead_list_head == NULL) {

            ent_environment->back = NULL;

            adm_entity_system.ent_environment.dead_list_head = ent_environment;

        } else {

            ent_environment->back = adm_entity_system.ent_environment.dead_list_tail;

            (adm_entity_system.ent_environment.dead_list_tail)->next = ent_environment;
        }

        ent_environment->next = NULL;

        adm_entity_system.ent_environment.dead_list_tail = ent_environment;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Environment",
            ent_environment->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_environment");
    #endif
}


/* Object Existent */

void adm_object_existent_environment(
    adm_ent_environment_typ * ent_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_environment");
    #endif

    if (ent_environment->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Environment",
            ent_environment->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_environment");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */