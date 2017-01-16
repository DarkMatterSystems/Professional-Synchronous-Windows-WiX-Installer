
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Shortcut Data Access */

/* Make Entity Object */

adm_ent_shortcut_typ * adm_make_object_shortcut(
    void)
{
    adm_ent_shortcut_typ * ent_shortcut;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_shortcut");
    #endif

    if (adm_entity_system.ent_shortcut.dead_list_head != NULL) {

        ent_shortcut = adm_entity_system.ent_shortcut.dead_list_head;

        if (adm_entity_system.ent_shortcut.dead_list_head == ent_shortcut) {

            adm_entity_system.ent_shortcut.dead_list_head = ent_shortcut->next;

        } else {

            (ent_shortcut->back)->next = ent_shortcut->next;
        }

        if (adm_entity_system.ent_shortcut.dead_list_tail == ent_shortcut) {

            adm_entity_system.ent_shortcut.dead_list_tail = ent_shortcut->back;

        } else {

            (ent_shortcut->next)->back = ent_shortcut->back;
        }

    } else {

        ent_shortcut = (adm_ent_shortcut_typ*)adm_allocate_memory(sizeof(adm_ent_shortcut_typ));
    }

    ent_shortcut->identity = ++adm_entity_system.ent_shortcut.tote;

    ent_shortcut->unique  = FALSE;
    ent_shortcut->deleted = FALSE;
    ent_shortcut->marked  = FALSE;
    ent_shortcut->ignore  = null;

    ent_shortcut->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_shortcut->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_shortcut->atb_description = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_shortcut->back = NULL;
    ent_shortcut->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_shortcut");
    #endif

    return (ent_shortcut);
}


/* Bind Entity Object */

void adm_bind_object_shortcut(
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_shortcut");
    #endif

    adm_object_existent_shortcut(
        ent_shortcut,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_shortcut.live_list_head == NULL) {

        ent_shortcut->back = NULL;

        adm_entity_system.ent_shortcut.live_list_head = ent_shortcut;

    } else {

        ent_shortcut->back = adm_entity_system.ent_shortcut.live_list_tail;

        (adm_entity_system.ent_shortcut.live_list_tail)->next = ent_shortcut;
    }

    ent_shortcut->next = NULL;

    adm_entity_system.ent_shortcut.live_list_tail = ent_shortcut;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_shortcut");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_shortcut(
    void * source_object,
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_shortcut");
    #endif

    adm_object_existent_shortcut(
        ent_shortcut,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_shortcut) {

        if (adm_entity_system.ent_shortcut.live_list_head == ent_shortcut) {

            adm_entity_system.ent_shortcut.live_list_head = ent_shortcut->next;

        } else {

            (ent_shortcut->back)->next = ent_shortcut->next;
        }

        if (adm_entity_system.ent_shortcut.live_list_tail == ent_shortcut) {

            adm_entity_system.ent_shortcut.live_list_tail = ent_shortcut->back;

        } else {

            (ent_shortcut->next)->back = ent_shortcut->back;
        }

        adm_deallocate_memory(ent_shortcut->atb_id);
        adm_deallocate_memory(ent_shortcut->atb_name);
        adm_deallocate_memory(ent_shortcut->atb_description);

        ent_shortcut->deleted = TRUE;

        if (adm_entity_system.ent_shortcut.dead_list_head == NULL) {

            ent_shortcut->back = NULL;

            adm_entity_system.ent_shortcut.dead_list_head = ent_shortcut;

        } else {

            ent_shortcut->back = adm_entity_system.ent_shortcut.dead_list_tail;

            (adm_entity_system.ent_shortcut.dead_list_tail)->next = ent_shortcut;
        }

        ent_shortcut->next = NULL;

        adm_entity_system.ent_shortcut.dead_list_tail = ent_shortcut;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Shortcut",
            ent_shortcut->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_shortcut");
    #endif
}


/* Object Existent */

void adm_object_existent_shortcut(
    adm_ent_shortcut_typ * ent_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_shortcut");
    #endif

    if (ent_shortcut->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Shortcut",
            ent_shortcut->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_shortcut");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */