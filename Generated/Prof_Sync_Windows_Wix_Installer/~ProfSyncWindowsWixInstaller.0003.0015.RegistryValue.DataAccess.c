
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Registry Value Data Access */

/* Make Entity Object */

adm_ent_registry_value_typ * adm_make_object_registry_value(
    void)
{
    adm_ent_registry_value_typ * ent_registry_value;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_registry_value");
    #endif

    if (adm_entity_system.ent_registry_value.dead_list_head != NULL) {

        ent_registry_value = adm_entity_system.ent_registry_value.dead_list_head;

        if (adm_entity_system.ent_registry_value.dead_list_head == ent_registry_value) {

            adm_entity_system.ent_registry_value.dead_list_head = ent_registry_value->next;

        } else {

            (ent_registry_value->back)->next = ent_registry_value->next;
        }

        if (adm_entity_system.ent_registry_value.dead_list_tail == ent_registry_value) {

            adm_entity_system.ent_registry_value.dead_list_tail = ent_registry_value->back;

        } else {

            (ent_registry_value->next)->back = ent_registry_value->back;
        }

    } else {

        ent_registry_value = (adm_ent_registry_value_typ*)adm_allocate_memory(sizeof(adm_ent_registry_value_typ));
    }

    ent_registry_value->identity = ++adm_entity_system.ent_registry_value.tote;

    ent_registry_value->unique  = FALSE;
    ent_registry_value->deleted = FALSE;
    ent_registry_value->marked  = FALSE;
    ent_registry_value->ignore  = null;

    ent_registry_value->atb_root = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_registry_value->atb_key = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_registry_value->atb_value = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_registry_value->back = NULL;
    ent_registry_value->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_registry_value");
    #endif

    return (ent_registry_value);
}


/* Bind Entity Object */

void adm_bind_object_registry_value(
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_registry_value");
    #endif

    adm_object_existent_registry_value(
        ent_registry_value,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_registry_value.live_list_head == NULL) {

        ent_registry_value->back = NULL;

        adm_entity_system.ent_registry_value.live_list_head = ent_registry_value;

    } else {

        ent_registry_value->back = adm_entity_system.ent_registry_value.live_list_tail;

        (adm_entity_system.ent_registry_value.live_list_tail)->next = ent_registry_value;
    }

    ent_registry_value->next = NULL;

    adm_entity_system.ent_registry_value.live_list_tail = ent_registry_value;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_registry_value");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_registry_value(
    void * source_object,
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_registry_value");
    #endif

    adm_object_existent_registry_value(
        ent_registry_value,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_registry_value) {

        if (adm_entity_system.ent_registry_value.live_list_head == ent_registry_value) {

            adm_entity_system.ent_registry_value.live_list_head = ent_registry_value->next;

        } else {

            (ent_registry_value->back)->next = ent_registry_value->next;
        }

        if (adm_entity_system.ent_registry_value.live_list_tail == ent_registry_value) {

            adm_entity_system.ent_registry_value.live_list_tail = ent_registry_value->back;

        } else {

            (ent_registry_value->next)->back = ent_registry_value->back;
        }

        adm_deallocate_memory(ent_registry_value->atb_root);
        adm_deallocate_memory(ent_registry_value->atb_key);
        adm_deallocate_memory(ent_registry_value->atb_value);

        ent_registry_value->deleted = TRUE;

        if (adm_entity_system.ent_registry_value.dead_list_head == NULL) {

            ent_registry_value->back = NULL;

            adm_entity_system.ent_registry_value.dead_list_head = ent_registry_value;

        } else {

            ent_registry_value->back = adm_entity_system.ent_registry_value.dead_list_tail;

            (adm_entity_system.ent_registry_value.dead_list_tail)->next = ent_registry_value;
        }

        ent_registry_value->next = NULL;

        adm_entity_system.ent_registry_value.dead_list_tail = ent_registry_value;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Registry_Value",
            ent_registry_value->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_registry_value");
    #endif
}


/* Object Existent */

void adm_object_existent_registry_value(
    adm_ent_registry_value_typ * ent_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_registry_value");
    #endif

    if (ent_registry_value->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Registry_Value",
            ent_registry_value->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_registry_value");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */