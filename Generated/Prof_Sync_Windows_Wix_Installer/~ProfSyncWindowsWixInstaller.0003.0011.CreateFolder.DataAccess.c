
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Create Folder Data Access */

/* Make Entity Object */

adm_ent_create_folder_typ * adm_make_object_create_folder(
    void)
{
    adm_ent_create_folder_typ * ent_create_folder;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_create_folder");
    #endif

    if (adm_entity_system.ent_create_folder.dead_list_head != NULL) {

        ent_create_folder = adm_entity_system.ent_create_folder.dead_list_head;

        if (adm_entity_system.ent_create_folder.dead_list_head == ent_create_folder) {

            adm_entity_system.ent_create_folder.dead_list_head = ent_create_folder->next;

        } else {

            (ent_create_folder->back)->next = ent_create_folder->next;
        }

        if (adm_entity_system.ent_create_folder.dead_list_tail == ent_create_folder) {

            adm_entity_system.ent_create_folder.dead_list_tail = ent_create_folder->back;

        } else {

            (ent_create_folder->next)->back = ent_create_folder->back;
        }

    } else {

        ent_create_folder = (adm_ent_create_folder_typ*)adm_allocate_memory(sizeof(adm_ent_create_folder_typ));
    }

    ent_create_folder->identity = ++adm_entity_system.ent_create_folder.tote;

    ent_create_folder->unique  = FALSE;
    ent_create_folder->deleted = FALSE;
    ent_create_folder->marked  = FALSE;
    ent_create_folder->ignore  = null;

    ent_create_folder->back = NULL;
    ent_create_folder->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_create_folder");
    #endif

    return (ent_create_folder);
}


/* Bind Entity Object */

void adm_bind_object_create_folder(
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_create_folder");
    #endif

    adm_object_existent_create_folder(
        ent_create_folder,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_create_folder.live_list_head == NULL) {

        ent_create_folder->back = NULL;

        adm_entity_system.ent_create_folder.live_list_head = ent_create_folder;

    } else {

        ent_create_folder->back = adm_entity_system.ent_create_folder.live_list_tail;

        (adm_entity_system.ent_create_folder.live_list_tail)->next = ent_create_folder;
    }

    ent_create_folder->next = NULL;

    adm_entity_system.ent_create_folder.live_list_tail = ent_create_folder;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_create_folder");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_create_folder(
    void * source_object,
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_create_folder");
    #endif

    adm_object_existent_create_folder(
        ent_create_folder,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_create_folder) {

        if (adm_entity_system.ent_create_folder.live_list_head == ent_create_folder) {

            adm_entity_system.ent_create_folder.live_list_head = ent_create_folder->next;

        } else {

            (ent_create_folder->back)->next = ent_create_folder->next;
        }

        if (adm_entity_system.ent_create_folder.live_list_tail == ent_create_folder) {

            adm_entity_system.ent_create_folder.live_list_tail = ent_create_folder->back;

        } else {

            (ent_create_folder->next)->back = ent_create_folder->back;
        }

        ent_create_folder->deleted = TRUE;

        if (adm_entity_system.ent_create_folder.dead_list_head == NULL) {

            ent_create_folder->back = NULL;

            adm_entity_system.ent_create_folder.dead_list_head = ent_create_folder;

        } else {

            ent_create_folder->back = adm_entity_system.ent_create_folder.dead_list_tail;

            (adm_entity_system.ent_create_folder.dead_list_tail)->next = ent_create_folder;
        }

        ent_create_folder->next = NULL;

        adm_entity_system.ent_create_folder.dead_list_tail = ent_create_folder;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Create_Folder",
            ent_create_folder->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_create_folder");
    #endif
}


/* Object Existent */

void adm_object_existent_create_folder(
    adm_ent_create_folder_typ * ent_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_create_folder");
    #endif

    if (ent_create_folder->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Create_Folder",
            ent_create_folder->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_create_folder");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */