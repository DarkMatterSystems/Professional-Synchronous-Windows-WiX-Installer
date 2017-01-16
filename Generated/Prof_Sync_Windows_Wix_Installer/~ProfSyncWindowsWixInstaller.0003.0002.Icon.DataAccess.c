
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Icon Data Access */

/* Make Entity Object */

adm_ent_icon_typ * adm_make_object_icon(
    void)
{
    adm_ent_icon_typ * ent_icon;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_icon");
    #endif

    if (adm_entity_system.ent_icon.dead_list_head != NULL) {

        ent_icon = adm_entity_system.ent_icon.dead_list_head;

        if (adm_entity_system.ent_icon.dead_list_head == ent_icon) {

            adm_entity_system.ent_icon.dead_list_head = ent_icon->next;

        } else {

            (ent_icon->back)->next = ent_icon->next;
        }

        if (adm_entity_system.ent_icon.dead_list_tail == ent_icon) {

            adm_entity_system.ent_icon.dead_list_tail = ent_icon->back;

        } else {

            (ent_icon->next)->back = ent_icon->back;
        }

    } else {

        ent_icon = (adm_ent_icon_typ*)adm_allocate_memory(sizeof(adm_ent_icon_typ));
    }

    ent_icon->identity = ++adm_entity_system.ent_icon.tote;

    ent_icon->unique  = FALSE;
    ent_icon->deleted = FALSE;
    ent_icon->marked  = FALSE;
    ent_icon->ignore  = null;

    ent_icon->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_icon->atb_source_file = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_icon->back = NULL;
    ent_icon->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_icon");
    #endif

    return (ent_icon);
}


/* Bind Entity Object */

void adm_bind_object_icon(
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_icon");
    #endif

    adm_object_existent_icon(
        ent_icon,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_icon.live_list_head == NULL) {

        ent_icon->back = NULL;

        adm_entity_system.ent_icon.live_list_head = ent_icon;

    } else {

        ent_icon->back = adm_entity_system.ent_icon.live_list_tail;

        (adm_entity_system.ent_icon.live_list_tail)->next = ent_icon;
    }

    ent_icon->next = NULL;

    adm_entity_system.ent_icon.live_list_tail = ent_icon;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_icon");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_icon(
    void * source_object,
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_icon");
    #endif

    adm_object_existent_icon(
        ent_icon,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_icon) {

        if (adm_entity_system.ent_icon.live_list_head == ent_icon) {

            adm_entity_system.ent_icon.live_list_head = ent_icon->next;

        } else {

            (ent_icon->back)->next = ent_icon->next;
        }

        if (adm_entity_system.ent_icon.live_list_tail == ent_icon) {

            adm_entity_system.ent_icon.live_list_tail = ent_icon->back;

        } else {

            (ent_icon->next)->back = ent_icon->back;
        }

        adm_deallocate_memory(ent_icon->atb_id);
        adm_deallocate_memory(ent_icon->atb_source_file);

        ent_icon->deleted = TRUE;

        if (adm_entity_system.ent_icon.dead_list_head == NULL) {

            ent_icon->back = NULL;

            adm_entity_system.ent_icon.dead_list_head = ent_icon;

        } else {

            ent_icon->back = adm_entity_system.ent_icon.dead_list_tail;

            (adm_entity_system.ent_icon.dead_list_tail)->next = ent_icon;
        }

        ent_icon->next = NULL;

        adm_entity_system.ent_icon.dead_list_tail = ent_icon;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Icon",
            ent_icon->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_icon");
    #endif
}


/* Object Existent */

void adm_object_existent_icon(
    adm_ent_icon_typ * ent_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_icon");
    #endif

    if (ent_icon->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Icon",
            ent_icon->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_icon");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */