
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* File Data Access */

/* Make Entity Object */

adm_ent_file_typ * adm_make_object_file(
    void)
{
    adm_ent_file_typ * ent_file;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_file");
    #endif

    if (adm_entity_system.ent_file.dead_list_head != NULL) {

        ent_file = adm_entity_system.ent_file.dead_list_head;

        if (adm_entity_system.ent_file.dead_list_head == ent_file) {

            adm_entity_system.ent_file.dead_list_head = ent_file->next;

        } else {

            (ent_file->back)->next = ent_file->next;
        }

        if (adm_entity_system.ent_file.dead_list_tail == ent_file) {

            adm_entity_system.ent_file.dead_list_tail = ent_file->back;

        } else {

            (ent_file->next)->back = ent_file->back;
        }

    } else {

        ent_file = (adm_ent_file_typ*)adm_allocate_memory(sizeof(adm_ent_file_typ));
    }

    ent_file->identity = ++adm_entity_system.ent_file.tote;

    ent_file->unique  = FALSE;
    ent_file->deleted = FALSE;
    ent_file->marked  = FALSE;
    ent_file->ignore  = null;

    ent_file->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_file->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_file->atb_source = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_file->rel_includes_file_shortcut_head = NULL;
    ent_file->rel_includes_file_shortcut_tail = NULL;

    ent_file->back = NULL;
    ent_file->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_file");
    #endif

    return (ent_file);
}


/* Bind Entity Object */

void adm_bind_object_file(
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_file");
    #endif

    adm_object_existent_file(
        ent_file,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_file.live_list_head == NULL) {

        ent_file->back = NULL;

        adm_entity_system.ent_file.live_list_head = ent_file;

    } else {

        ent_file->back = adm_entity_system.ent_file.live_list_tail;

        (adm_entity_system.ent_file.live_list_tail)->next = ent_file;
    }

    ent_file->next = NULL;

    adm_entity_system.ent_file.live_list_tail = ent_file;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_file");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_file(
    void * source_object,
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_file");
    #endif

    adm_object_existent_file(
        ent_file,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_file) {

        if (ent_file->rel_includes_file_shortcut_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "File",
                ent_file->identity,
                "Includes",
                "File_Shortcut");
        }

        if (adm_entity_system.ent_file.live_list_head == ent_file) {

            adm_entity_system.ent_file.live_list_head = ent_file->next;

        } else {

            (ent_file->back)->next = ent_file->next;
        }

        if (adm_entity_system.ent_file.live_list_tail == ent_file) {

            adm_entity_system.ent_file.live_list_tail = ent_file->back;

        } else {

            (ent_file->next)->back = ent_file->back;
        }

        adm_deallocate_memory(ent_file->atb_id);
        adm_deallocate_memory(ent_file->atb_name);
        adm_deallocate_memory(ent_file->atb_source);

        ent_file->deleted = TRUE;

        if (adm_entity_system.ent_file.dead_list_head == NULL) {

            ent_file->back = NULL;

            adm_entity_system.ent_file.dead_list_head = ent_file;

        } else {

            ent_file->back = adm_entity_system.ent_file.dead_list_tail;

            (adm_entity_system.ent_file.dead_list_tail)->next = ent_file;
        }

        ent_file->next = NULL;

        adm_entity_system.ent_file.dead_list_tail = ent_file;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "File",
            ent_file->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_file");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_file_includes_file_shortcut(
    adm_ent_file_typ * ent_source_file,
    adm_ent_file_shortcut_typ * ent_target_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut;

    adm_base_boolean_typ file_shortcut_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_file_includes_file_shortcut");
    #endif

    adm_object_existent_file(
        ent_source_file,
        error_file,
        error_line,
        error_rank);

    file_shortcut_not_found = TRUE;

    rel_file_includes_file_shortcut = ent_source_file->rel_includes_file_shortcut_head;

    while (
        file_shortcut_not_found &&
        rel_file_includes_file_shortcut != NULL) {

        if (rel_file_includes_file_shortcut->ent_file_shortcut == ent_target_file_shortcut) {

            file_shortcut_not_found = FALSE;
        }

        rel_file_includes_file_shortcut = rel_file_includes_file_shortcut->next;
    }

    if (file_shortcut_not_found) {

        rel_file_includes_file_shortcut = (adm_rel_file_includes_file_shortcut_typ*)
            adm_allocate_memory(sizeof(adm_rel_file_includes_file_shortcut_typ));

        rel_file_includes_file_shortcut->ent_file_shortcut = ent_target_file_shortcut;

        if (ent_source_file->rel_includes_file_shortcut_head == NULL) {

            rel_file_includes_file_shortcut->back = NULL;

            ent_source_file->rel_includes_file_shortcut_head = rel_file_includes_file_shortcut;

        } else {

            rel_file_includes_file_shortcut->back = ent_source_file->rel_includes_file_shortcut_tail;

            (ent_source_file->rel_includes_file_shortcut_tail)->next = rel_file_includes_file_shortcut;
        }

        rel_file_includes_file_shortcut->next = NULL;

        ent_source_file->rel_includes_file_shortcut_tail = rel_file_includes_file_shortcut;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "File",
            ent_source_file->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_file_includes_file_shortcut");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_file_includes_file_shortcut(
    adm_ent_file_typ * ent_file,
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_file_includes_file_shortcut");
    #endif

    adm_object_existent_file(
        ent_file,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_file_includes_file_shortcut->next !=
        (adm_base_integer_typ)rel_file_includes_file_shortcut->ent_file_shortcut) {

        if (ent_file->rel_includes_file_shortcut_head != NULL) {

            if (ent_file->rel_includes_file_shortcut_head == rel_file_includes_file_shortcut) {

                ent_file->rel_includes_file_shortcut_head = rel_file_includes_file_shortcut->next;

            } else {

                (rel_file_includes_file_shortcut->back)->next = rel_file_includes_file_shortcut->next;
            }

            if (ent_file->rel_includes_file_shortcut_tail == rel_file_includes_file_shortcut) {

                ent_file->rel_includes_file_shortcut_tail = rel_file_includes_file_shortcut->back;

            } else {

                (rel_file_includes_file_shortcut->next)->back = rel_file_includes_file_shortcut->back;
            }

            adm_deallocate_memory(rel_file_includes_file_shortcut);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "File",
                ent_file->identity,
                "Includes",
                "File_Shortcut");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "File",
            ent_file->identity,
            "Includes",
            "File_Shortcut");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_file_includes_file_shortcut");
    #endif
}


/* Object Existent */

void adm_object_existent_file(
    adm_ent_file_typ * ent_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_file");
    #endif

    if (ent_file->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "File",
            ent_file->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_file");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */