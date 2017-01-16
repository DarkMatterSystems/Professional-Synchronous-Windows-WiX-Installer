
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Directory Data Access */

/* Make Entity Object */

adm_ent_directory_typ * adm_make_object_directory(
    void)
{
    adm_ent_directory_typ * ent_directory;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_directory");
    #endif

    if (adm_entity_system.ent_directory.dead_list_head != NULL) {

        ent_directory = adm_entity_system.ent_directory.dead_list_head;

        if (adm_entity_system.ent_directory.dead_list_head == ent_directory) {

            adm_entity_system.ent_directory.dead_list_head = ent_directory->next;

        } else {

            (ent_directory->back)->next = ent_directory->next;
        }

        if (adm_entity_system.ent_directory.dead_list_tail == ent_directory) {

            adm_entity_system.ent_directory.dead_list_tail = ent_directory->back;

        } else {

            (ent_directory->next)->back = ent_directory->back;
        }

    } else {

        ent_directory = (adm_ent_directory_typ*)adm_allocate_memory(sizeof(adm_ent_directory_typ));
    }

    ent_directory->identity = ++adm_entity_system.ent_directory.tote;

    ent_directory->unique  = FALSE;
    ent_directory->deleted = FALSE;
    ent_directory->marked  = FALSE;
    ent_directory->ignore  = null;

    ent_directory->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_directory->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_directory->atb_heading = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_directory->rel_includes_component_head = NULL;
    ent_directory->rel_includes_component_tail = NULL;

    ent_directory->rel_includes_directory_head = NULL;
    ent_directory->rel_includes_directory_tail = NULL;

    ent_directory->back = NULL;
    ent_directory->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_directory");
    #endif

    return (ent_directory);
}


/* Bind Entity Object */

void adm_bind_object_directory(
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_directory");
    #endif

    adm_object_existent_directory(
        ent_directory,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_directory.live_list_head == NULL) {

        ent_directory->back = NULL;

        adm_entity_system.ent_directory.live_list_head = ent_directory;

    } else {

        ent_directory->back = adm_entity_system.ent_directory.live_list_tail;

        (adm_entity_system.ent_directory.live_list_tail)->next = ent_directory;
    }

    ent_directory->next = NULL;

    adm_entity_system.ent_directory.live_list_tail = ent_directory;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_directory");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_directory(
    void * source_object,
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_directory");
    #endif

    adm_object_existent_directory(
        ent_directory,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_directory) {

        if (ent_directory->rel_includes_component_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Directory",
                ent_directory->identity,
                "Includes",
                "Component");
        }

        if (ent_directory->rel_includes_directory_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Directory",
                ent_directory->identity,
                "Includes",
                "Directory");
        }

        if (adm_entity_system.ent_directory.live_list_head == ent_directory) {

            adm_entity_system.ent_directory.live_list_head = ent_directory->next;

        } else {

            (ent_directory->back)->next = ent_directory->next;
        }

        if (adm_entity_system.ent_directory.live_list_tail == ent_directory) {

            adm_entity_system.ent_directory.live_list_tail = ent_directory->back;

        } else {

            (ent_directory->next)->back = ent_directory->back;
        }

        adm_deallocate_memory(ent_directory->atb_id);
        adm_deallocate_memory(ent_directory->atb_name);
        adm_deallocate_memory(ent_directory->atb_heading);

        ent_directory->deleted = TRUE;

        if (adm_entity_system.ent_directory.dead_list_head == NULL) {

            ent_directory->back = NULL;

            adm_entity_system.ent_directory.dead_list_head = ent_directory;

        } else {

            ent_directory->back = adm_entity_system.ent_directory.dead_list_tail;

            (adm_entity_system.ent_directory.dead_list_tail)->next = ent_directory;
        }

        ent_directory->next = NULL;

        adm_entity_system.ent_directory.dead_list_tail = ent_directory;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Directory",
            ent_directory->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_directory");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_directory_includes_component(
    adm_ent_directory_typ * ent_source_directory,
    adm_ent_component_typ * ent_target_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_directory_includes_component_typ * rel_directory_includes_component;

    adm_base_boolean_typ component_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_directory_includes_component");
    #endif

    adm_object_existent_directory(
        ent_source_directory,
        error_file,
        error_line,
        error_rank);

    component_not_found = TRUE;

    rel_directory_includes_component = ent_source_directory->rel_includes_component_head;

    while (
        component_not_found &&
        rel_directory_includes_component != NULL) {

        if (rel_directory_includes_component->ent_component == ent_target_component) {

            component_not_found = FALSE;
        }

        rel_directory_includes_component = rel_directory_includes_component->next;
    }

    if (component_not_found) {

        rel_directory_includes_component = (adm_rel_directory_includes_component_typ*)
            adm_allocate_memory(sizeof(adm_rel_directory_includes_component_typ));

        rel_directory_includes_component->ent_component = ent_target_component;

        if (ent_source_directory->rel_includes_component_head == NULL) {

            rel_directory_includes_component->back = NULL;

            ent_source_directory->rel_includes_component_head = rel_directory_includes_component;

        } else {

            rel_directory_includes_component->back = ent_source_directory->rel_includes_component_tail;

            (ent_source_directory->rel_includes_component_tail)->next = rel_directory_includes_component;
        }

        rel_directory_includes_component->next = NULL;

        ent_source_directory->rel_includes_component_tail = rel_directory_includes_component;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Directory",
            ent_source_directory->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_directory_includes_component");
    #endif
}

void adm_link_relation_directory_includes_directory(
    adm_ent_directory_typ * ent_source_directory,
    adm_ent_directory_typ * ent_target_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory;

    adm_base_boolean_typ directory_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_directory_includes_directory");
    #endif

    adm_object_existent_directory(
        ent_source_directory,
        error_file,
        error_line,
        error_rank);

    directory_not_found = TRUE;

    rel_directory_includes_directory = ent_source_directory->rel_includes_directory_head;

    while (
        directory_not_found &&
        rel_directory_includes_directory != NULL) {

        if (rel_directory_includes_directory->ent_directory == ent_target_directory) {

            directory_not_found = FALSE;
        }

        rel_directory_includes_directory = rel_directory_includes_directory->next;
    }

    if (directory_not_found) {

        rel_directory_includes_directory = (adm_rel_directory_includes_directory_typ*)
            adm_allocate_memory(sizeof(adm_rel_directory_includes_directory_typ));

        rel_directory_includes_directory->ent_directory = ent_target_directory;

        if (ent_source_directory->rel_includes_directory_head == NULL) {

            rel_directory_includes_directory->back = NULL;

            ent_source_directory->rel_includes_directory_head = rel_directory_includes_directory;

        } else {

            rel_directory_includes_directory->back = ent_source_directory->rel_includes_directory_tail;

            (ent_source_directory->rel_includes_directory_tail)->next = rel_directory_includes_directory;
        }

        rel_directory_includes_directory->next = NULL;

        ent_source_directory->rel_includes_directory_tail = rel_directory_includes_directory;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Directory",
            ent_source_directory->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_directory_includes_directory");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_directory_includes_component(
    adm_ent_directory_typ * ent_directory,
    adm_rel_directory_includes_component_typ * rel_directory_includes_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_directory_includes_component");
    #endif

    adm_object_existent_directory(
        ent_directory,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_directory_includes_component->next !=
        (adm_base_integer_typ)rel_directory_includes_component->ent_component) {

        if (ent_directory->rel_includes_component_head != NULL) {

            if (ent_directory->rel_includes_component_head == rel_directory_includes_component) {

                ent_directory->rel_includes_component_head = rel_directory_includes_component->next;

            } else {

                (rel_directory_includes_component->back)->next = rel_directory_includes_component->next;
            }

            if (ent_directory->rel_includes_component_tail == rel_directory_includes_component) {

                ent_directory->rel_includes_component_tail = rel_directory_includes_component->back;

            } else {

                (rel_directory_includes_component->next)->back = rel_directory_includes_component->back;
            }

            adm_deallocate_memory(rel_directory_includes_component);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Directory",
                ent_directory->identity,
                "Includes",
                "Component");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Directory",
            ent_directory->identity,
            "Includes",
            "Component");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_directory_includes_component");
    #endif
}

void adm_kill_relation_directory_includes_directory(
    adm_ent_directory_typ * ent_directory,
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_directory_includes_directory");
    #endif

    adm_object_existent_directory(
        ent_directory,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_directory_includes_directory->next !=
        (adm_base_integer_typ)rel_directory_includes_directory->ent_directory) {

        if (ent_directory->rel_includes_directory_head != NULL) {

            if (ent_directory->rel_includes_directory_head == rel_directory_includes_directory) {

                ent_directory->rel_includes_directory_head = rel_directory_includes_directory->next;

            } else {

                (rel_directory_includes_directory->back)->next = rel_directory_includes_directory->next;
            }

            if (ent_directory->rel_includes_directory_tail == rel_directory_includes_directory) {

                ent_directory->rel_includes_directory_tail = rel_directory_includes_directory->back;

            } else {

                (rel_directory_includes_directory->next)->back = rel_directory_includes_directory->back;
            }

            adm_deallocate_memory(rel_directory_includes_directory);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Directory",
                ent_directory->identity,
                "Includes",
                "Directory");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Directory",
            ent_directory->identity,
            "Includes",
            "Directory");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_directory_includes_directory");
    #endif
}


/* Object Existent */

void adm_object_existent_directory(
    adm_ent_directory_typ * ent_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_directory");
    #endif

    if (ent_directory->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Directory",
            ent_directory->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_directory");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */