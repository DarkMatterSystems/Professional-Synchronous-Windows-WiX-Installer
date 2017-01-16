
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Uninstall Shortcut Data Access */

/* Make Entity Object */

adm_ent_uninstall_shortcut_typ * adm_make_object_uninstall_shortcut(
    void)
{
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_uninstall_shortcut");
    #endif

    if (adm_entity_system.ent_uninstall_shortcut.dead_list_head != NULL) {

        ent_uninstall_shortcut = adm_entity_system.ent_uninstall_shortcut.dead_list_head;

        if (adm_entity_system.ent_uninstall_shortcut.dead_list_head == ent_uninstall_shortcut) {

            adm_entity_system.ent_uninstall_shortcut.dead_list_head = ent_uninstall_shortcut->next;

        } else {

            (ent_uninstall_shortcut->back)->next = ent_uninstall_shortcut->next;
        }

        if (adm_entity_system.ent_uninstall_shortcut.dead_list_tail == ent_uninstall_shortcut) {

            adm_entity_system.ent_uninstall_shortcut.dead_list_tail = ent_uninstall_shortcut->back;

        } else {

            (ent_uninstall_shortcut->next)->back = ent_uninstall_shortcut->back;
        }

    } else {

        ent_uninstall_shortcut = (adm_ent_uninstall_shortcut_typ*)adm_allocate_memory(sizeof(adm_ent_uninstall_shortcut_typ));
    }

    ent_uninstall_shortcut->identity = ++adm_entity_system.ent_uninstall_shortcut.tote;

    ent_uninstall_shortcut->unique  = FALSE;
    ent_uninstall_shortcut->deleted = FALSE;
    ent_uninstall_shortcut->marked  = FALSE;
    ent_uninstall_shortcut->ignore  = null;

    ent_uninstall_shortcut->atb_target = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_uninstall_shortcut->atb_arguments = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_uninstall_shortcut->rel_specialisation_shortcut_head = NULL;
    ent_uninstall_shortcut->rel_specialisation_shortcut_tail = NULL;

    ent_uninstall_shortcut->back = NULL;
    ent_uninstall_shortcut->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_uninstall_shortcut");
    #endif

    return (ent_uninstall_shortcut);
}


/* Bind Entity Object */

void adm_bind_object_uninstall_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_uninstall_shortcut");
    #endif

    adm_object_existent_uninstall_shortcut(
        ent_uninstall_shortcut,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_uninstall_shortcut.live_list_head == NULL) {

        ent_uninstall_shortcut->back = NULL;

        adm_entity_system.ent_uninstall_shortcut.live_list_head = ent_uninstall_shortcut;

    } else {

        ent_uninstall_shortcut->back = adm_entity_system.ent_uninstall_shortcut.live_list_tail;

        (adm_entity_system.ent_uninstall_shortcut.live_list_tail)->next = ent_uninstall_shortcut;
    }

    ent_uninstall_shortcut->next = NULL;

    adm_entity_system.ent_uninstall_shortcut.live_list_tail = ent_uninstall_shortcut;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_uninstall_shortcut");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_uninstall_shortcut(
    void * source_object,
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_uninstall_shortcut");
    #endif

    adm_object_existent_uninstall_shortcut(
        ent_uninstall_shortcut,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_uninstall_shortcut) {

        if (ent_uninstall_shortcut->rel_specialisation_shortcut_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Uninstall_Shortcut",
                ent_uninstall_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

        if (adm_entity_system.ent_uninstall_shortcut.live_list_head == ent_uninstall_shortcut) {

            adm_entity_system.ent_uninstall_shortcut.live_list_head = ent_uninstall_shortcut->next;

        } else {

            (ent_uninstall_shortcut->back)->next = ent_uninstall_shortcut->next;
        }

        if (adm_entity_system.ent_uninstall_shortcut.live_list_tail == ent_uninstall_shortcut) {

            adm_entity_system.ent_uninstall_shortcut.live_list_tail = ent_uninstall_shortcut->back;

        } else {

            (ent_uninstall_shortcut->next)->back = ent_uninstall_shortcut->back;
        }

        adm_deallocate_memory(ent_uninstall_shortcut->atb_target);
        adm_deallocate_memory(ent_uninstall_shortcut->atb_arguments);

        ent_uninstall_shortcut->deleted = TRUE;

        if (adm_entity_system.ent_uninstall_shortcut.dead_list_head == NULL) {

            ent_uninstall_shortcut->back = NULL;

            adm_entity_system.ent_uninstall_shortcut.dead_list_head = ent_uninstall_shortcut;

        } else {

            ent_uninstall_shortcut->back = adm_entity_system.ent_uninstall_shortcut.dead_list_tail;

            (adm_entity_system.ent_uninstall_shortcut.dead_list_tail)->next = ent_uninstall_shortcut;
        }

        ent_uninstall_shortcut->next = NULL;

        adm_entity_system.ent_uninstall_shortcut.dead_list_tail = ent_uninstall_shortcut;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Uninstall_Shortcut",
            ent_uninstall_shortcut->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_uninstall_shortcut");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_uninstall_shortcut_specialisation_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_source_uninstall_shortcut,
    adm_ent_shortcut_typ * ent_target_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_uninstall_shortcut_specialisation_shortcut_typ * rel_uninstall_shortcut_specialisation_shortcut;

    adm_base_boolean_typ shortcut_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_uninstall_shortcut_specialisation_shortcut");
    #endif

    adm_object_existent_uninstall_shortcut(
        ent_source_uninstall_shortcut,
        error_file,
        error_line,
        error_rank);

    shortcut_not_found = TRUE;

    rel_uninstall_shortcut_specialisation_shortcut = ent_source_uninstall_shortcut->rel_specialisation_shortcut_head;

    while (
        shortcut_not_found &&
        rel_uninstall_shortcut_specialisation_shortcut != NULL) {

        if (rel_uninstall_shortcut_specialisation_shortcut->ent_shortcut == ent_target_shortcut) {

            shortcut_not_found = FALSE;
        }

        rel_uninstall_shortcut_specialisation_shortcut = rel_uninstall_shortcut_specialisation_shortcut->next;
    }

    if (shortcut_not_found) {

        rel_uninstall_shortcut_specialisation_shortcut = (adm_rel_uninstall_shortcut_specialisation_shortcut_typ*)
            adm_allocate_memory(sizeof(adm_rel_uninstall_shortcut_specialisation_shortcut_typ));

        rel_uninstall_shortcut_specialisation_shortcut->ent_shortcut = ent_target_shortcut;

        if (ent_source_uninstall_shortcut->rel_specialisation_shortcut_head == NULL) {

            rel_uninstall_shortcut_specialisation_shortcut->back = NULL;

            ent_source_uninstall_shortcut->rel_specialisation_shortcut_head = rel_uninstall_shortcut_specialisation_shortcut;

        } else {

            rel_uninstall_shortcut_specialisation_shortcut->back = ent_source_uninstall_shortcut->rel_specialisation_shortcut_tail;

            (ent_source_uninstall_shortcut->rel_specialisation_shortcut_tail)->next = rel_uninstall_shortcut_specialisation_shortcut;
        }

        rel_uninstall_shortcut_specialisation_shortcut->next = NULL;

        ent_source_uninstall_shortcut->rel_specialisation_shortcut_tail = rel_uninstall_shortcut_specialisation_shortcut;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Uninstall_Shortcut",
            ent_source_uninstall_shortcut->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_uninstall_shortcut_specialisation_shortcut");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_uninstall_shortcut_specialisation_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_rel_uninstall_shortcut_specialisation_shortcut_typ * rel_uninstall_shortcut_specialisation_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_uninstall_shortcut_specialisation_shortcut");
    #endif

    adm_object_existent_uninstall_shortcut(
        ent_uninstall_shortcut,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_uninstall_shortcut_specialisation_shortcut->next !=
        (adm_base_integer_typ)rel_uninstall_shortcut_specialisation_shortcut->ent_shortcut) {

        if (ent_uninstall_shortcut->rel_specialisation_shortcut_head != NULL) {

            if (ent_uninstall_shortcut->rel_specialisation_shortcut_head == rel_uninstall_shortcut_specialisation_shortcut) {

                ent_uninstall_shortcut->rel_specialisation_shortcut_head = rel_uninstall_shortcut_specialisation_shortcut->next;

            } else {

                (rel_uninstall_shortcut_specialisation_shortcut->back)->next = rel_uninstall_shortcut_specialisation_shortcut->next;
            }

            if (ent_uninstall_shortcut->rel_specialisation_shortcut_tail == rel_uninstall_shortcut_specialisation_shortcut) {

                ent_uninstall_shortcut->rel_specialisation_shortcut_tail = rel_uninstall_shortcut_specialisation_shortcut->back;

            } else {

                (rel_uninstall_shortcut_specialisation_shortcut->next)->back = rel_uninstall_shortcut_specialisation_shortcut->back;
            }

            adm_deallocate_memory(rel_uninstall_shortcut_specialisation_shortcut);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Uninstall_Shortcut",
                ent_uninstall_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Uninstall_Shortcut",
            ent_uninstall_shortcut->identity,
            "Specialisation",
            "Shortcut");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_uninstall_shortcut_specialisation_shortcut");
    #endif
}


/* Object Existent */

void adm_object_existent_uninstall_shortcut(
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_uninstall_shortcut");
    #endif

    if (ent_uninstall_shortcut->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Uninstall_Shortcut",
            ent_uninstall_shortcut->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_uninstall_shortcut");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */