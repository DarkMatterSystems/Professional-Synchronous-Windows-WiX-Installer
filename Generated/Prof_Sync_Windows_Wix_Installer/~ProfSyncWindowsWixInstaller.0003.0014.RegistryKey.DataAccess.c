
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Registry Key Data Access */

/* Make Entity Object */

adm_ent_registry_key_typ * adm_make_object_registry_key(
    void)
{
    adm_ent_registry_key_typ * ent_registry_key;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_registry_key");
    #endif

    if (adm_entity_system.ent_registry_key.dead_list_head != NULL) {

        ent_registry_key = adm_entity_system.ent_registry_key.dead_list_head;

        if (adm_entity_system.ent_registry_key.dead_list_head == ent_registry_key) {

            adm_entity_system.ent_registry_key.dead_list_head = ent_registry_key->next;

        } else {

            (ent_registry_key->back)->next = ent_registry_key->next;
        }

        if (adm_entity_system.ent_registry_key.dead_list_tail == ent_registry_key) {

            adm_entity_system.ent_registry_key.dead_list_tail = ent_registry_key->back;

        } else {

            (ent_registry_key->next)->back = ent_registry_key->back;
        }

    } else {

        ent_registry_key = (adm_ent_registry_key_typ*)adm_allocate_memory(sizeof(adm_ent_registry_key_typ));
    }

    ent_registry_key->identity = ++adm_entity_system.ent_registry_key.tote;

    ent_registry_key->unique  = FALSE;
    ent_registry_key->deleted = FALSE;
    ent_registry_key->marked  = FALSE;
    ent_registry_key->ignore  = null;

    ent_registry_key->atb_root = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_registry_key->atb_key = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_registry_key->rel_includes_registry_value_head = NULL;
    ent_registry_key->rel_includes_registry_value_tail = NULL;

    ent_registry_key->back = NULL;
    ent_registry_key->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_registry_key");
    #endif

    return (ent_registry_key);
}


/* Bind Entity Object */

void adm_bind_object_registry_key(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_registry_key");
    #endif

    adm_object_existent_registry_key(
        ent_registry_key,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_registry_key.live_list_head == NULL) {

        ent_registry_key->back = NULL;

        adm_entity_system.ent_registry_key.live_list_head = ent_registry_key;

    } else {

        ent_registry_key->back = adm_entity_system.ent_registry_key.live_list_tail;

        (adm_entity_system.ent_registry_key.live_list_tail)->next = ent_registry_key;
    }

    ent_registry_key->next = NULL;

    adm_entity_system.ent_registry_key.live_list_tail = ent_registry_key;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_registry_key");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_registry_key(
    void * source_object,
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_registry_key");
    #endif

    adm_object_existent_registry_key(
        ent_registry_key,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_registry_key) {

        if (ent_registry_key->rel_includes_registry_value_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Registry_Key",
                ent_registry_key->identity,
                "Includes",
                "Registry_Value");
        }

        if (adm_entity_system.ent_registry_key.live_list_head == ent_registry_key) {

            adm_entity_system.ent_registry_key.live_list_head = ent_registry_key->next;

        } else {

            (ent_registry_key->back)->next = ent_registry_key->next;
        }

        if (adm_entity_system.ent_registry_key.live_list_tail == ent_registry_key) {

            adm_entity_system.ent_registry_key.live_list_tail = ent_registry_key->back;

        } else {

            (ent_registry_key->next)->back = ent_registry_key->back;
        }

        adm_deallocate_memory(ent_registry_key->atb_root);
        adm_deallocate_memory(ent_registry_key->atb_key);

        ent_registry_key->deleted = TRUE;

        if (adm_entity_system.ent_registry_key.dead_list_head == NULL) {

            ent_registry_key->back = NULL;

            adm_entity_system.ent_registry_key.dead_list_head = ent_registry_key;

        } else {

            ent_registry_key->back = adm_entity_system.ent_registry_key.dead_list_tail;

            (adm_entity_system.ent_registry_key.dead_list_tail)->next = ent_registry_key;
        }

        ent_registry_key->next = NULL;

        adm_entity_system.ent_registry_key.dead_list_tail = ent_registry_key;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Registry_Key",
            ent_registry_key->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_registry_key");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_registry_key_includes_registry_value(
    adm_ent_registry_key_typ * ent_source_registry_key,
    adm_ent_registry_value_typ * ent_target_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_registry_key_includes_registry_value_typ * rel_registry_key_includes_registry_value;

    adm_base_boolean_typ registry_value_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_registry_key_includes_registry_value");
    #endif

    adm_object_existent_registry_key(
        ent_source_registry_key,
        error_file,
        error_line,
        error_rank);

    registry_value_not_found = TRUE;

    rel_registry_key_includes_registry_value = ent_source_registry_key->rel_includes_registry_value_head;

    while (
        registry_value_not_found &&
        rel_registry_key_includes_registry_value != NULL) {

        if (rel_registry_key_includes_registry_value->ent_registry_value == ent_target_registry_value) {

            registry_value_not_found = FALSE;
        }

        rel_registry_key_includes_registry_value = rel_registry_key_includes_registry_value->next;
    }

    if (registry_value_not_found) {

        rel_registry_key_includes_registry_value = (adm_rel_registry_key_includes_registry_value_typ*)
            adm_allocate_memory(sizeof(adm_rel_registry_key_includes_registry_value_typ));

        rel_registry_key_includes_registry_value->ent_registry_value = ent_target_registry_value;

        if (ent_source_registry_key->rel_includes_registry_value_head == NULL) {

            rel_registry_key_includes_registry_value->back = NULL;

            ent_source_registry_key->rel_includes_registry_value_head = rel_registry_key_includes_registry_value;

        } else {

            rel_registry_key_includes_registry_value->back = ent_source_registry_key->rel_includes_registry_value_tail;

            (ent_source_registry_key->rel_includes_registry_value_tail)->next = rel_registry_key_includes_registry_value;
        }

        rel_registry_key_includes_registry_value->next = NULL;

        ent_source_registry_key->rel_includes_registry_value_tail = rel_registry_key_includes_registry_value;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Registry_Key",
            ent_source_registry_key->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_registry_key_includes_registry_value");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_registry_key_includes_registry_value(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_rel_registry_key_includes_registry_value_typ * rel_registry_key_includes_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_registry_key_includes_registry_value");
    #endif

    adm_object_existent_registry_key(
        ent_registry_key,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_registry_key_includes_registry_value->next !=
        (adm_base_integer_typ)rel_registry_key_includes_registry_value->ent_registry_value) {

        if (ent_registry_key->rel_includes_registry_value_head != NULL) {

            if (ent_registry_key->rel_includes_registry_value_head == rel_registry_key_includes_registry_value) {

                ent_registry_key->rel_includes_registry_value_head = rel_registry_key_includes_registry_value->next;

            } else {

                (rel_registry_key_includes_registry_value->back)->next = rel_registry_key_includes_registry_value->next;
            }

            if (ent_registry_key->rel_includes_registry_value_tail == rel_registry_key_includes_registry_value) {

                ent_registry_key->rel_includes_registry_value_tail = rel_registry_key_includes_registry_value->back;

            } else {

                (rel_registry_key_includes_registry_value->next)->back = rel_registry_key_includes_registry_value->back;
            }

            adm_deallocate_memory(rel_registry_key_includes_registry_value);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Registry_Key",
                ent_registry_key->identity,
                "Includes",
                "Registry_Value");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Registry_Key",
            ent_registry_key->identity,
            "Includes",
            "Registry_Value");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_registry_key_includes_registry_value");
    #endif
}


/* Object Existent */

void adm_object_existent_registry_key(
    adm_ent_registry_key_typ * ent_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_registry_key");
    #endif

    if (ent_registry_key->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Registry_Key",
            ent_registry_key->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_registry_key");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */