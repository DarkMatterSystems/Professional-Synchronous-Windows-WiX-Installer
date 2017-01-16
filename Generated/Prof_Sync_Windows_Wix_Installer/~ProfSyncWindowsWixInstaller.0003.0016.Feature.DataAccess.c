
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Feature Data Access */

/* Make Entity Object */

adm_ent_feature_typ * adm_make_object_feature(
    void)
{
    adm_ent_feature_typ * ent_feature;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_feature");
    #endif

    if (adm_entity_system.ent_feature.dead_list_head != NULL) {

        ent_feature = adm_entity_system.ent_feature.dead_list_head;

        if (adm_entity_system.ent_feature.dead_list_head == ent_feature) {

            adm_entity_system.ent_feature.dead_list_head = ent_feature->next;

        } else {

            (ent_feature->back)->next = ent_feature->next;
        }

        if (adm_entity_system.ent_feature.dead_list_tail == ent_feature) {

            adm_entity_system.ent_feature.dead_list_tail = ent_feature->back;

        } else {

            (ent_feature->next)->back = ent_feature->back;
        }

    } else {

        ent_feature = (adm_ent_feature_typ*)adm_allocate_memory(sizeof(adm_ent_feature_typ));
    }

    ent_feature->identity = ++adm_entity_system.ent_feature.tote;

    ent_feature->unique  = FALSE;
    ent_feature->deleted = FALSE;
    ent_feature->marked  = FALSE;
    ent_feature->ignore  = null;

    ent_feature->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_feature->atb_title = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_feature->atb_display = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_feature->atb_description = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_feature->atb_configurable_directory = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_feature->atb_heading = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_feature->rel_includes_component_head = NULL;
    ent_feature->rel_includes_component_tail = NULL;

    ent_feature->rel_includes_feature_head = NULL;
    ent_feature->rel_includes_feature_tail = NULL;

    ent_feature->back = NULL;
    ent_feature->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_feature");
    #endif

    return (ent_feature);
}


/* Bind Entity Object */

void adm_bind_object_feature(
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_feature");
    #endif

    adm_object_existent_feature(
        ent_feature,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_feature.live_list_head == NULL) {

        ent_feature->back = NULL;

        adm_entity_system.ent_feature.live_list_head = ent_feature;

    } else {

        ent_feature->back = adm_entity_system.ent_feature.live_list_tail;

        (adm_entity_system.ent_feature.live_list_tail)->next = ent_feature;
    }

    ent_feature->next = NULL;

    adm_entity_system.ent_feature.live_list_tail = ent_feature;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_feature");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_feature(
    void * source_object,
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_feature");
    #endif

    adm_object_existent_feature(
        ent_feature,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_feature) {

        if (ent_feature->rel_includes_component_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Feature",
                ent_feature->identity,
                "Includes",
                "Component");
        }

        if (ent_feature->rel_includes_feature_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Feature",
                ent_feature->identity,
                "Includes",
                "Feature");
        }

        if (adm_entity_system.ent_feature.live_list_head == ent_feature) {

            adm_entity_system.ent_feature.live_list_head = ent_feature->next;

        } else {

            (ent_feature->back)->next = ent_feature->next;
        }

        if (adm_entity_system.ent_feature.live_list_tail == ent_feature) {

            adm_entity_system.ent_feature.live_list_tail = ent_feature->back;

        } else {

            (ent_feature->next)->back = ent_feature->back;
        }

        adm_deallocate_memory(ent_feature->atb_id);
        adm_deallocate_memory(ent_feature->atb_title);
        adm_deallocate_memory(ent_feature->atb_display);
        adm_deallocate_memory(ent_feature->atb_description);
        adm_deallocate_memory(ent_feature->atb_configurable_directory);
        adm_deallocate_memory(ent_feature->atb_heading);

        ent_feature->deleted = TRUE;

        if (adm_entity_system.ent_feature.dead_list_head == NULL) {

            ent_feature->back = NULL;

            adm_entity_system.ent_feature.dead_list_head = ent_feature;

        } else {

            ent_feature->back = adm_entity_system.ent_feature.dead_list_tail;

            (adm_entity_system.ent_feature.dead_list_tail)->next = ent_feature;
        }

        ent_feature->next = NULL;

        adm_entity_system.ent_feature.dead_list_tail = ent_feature;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Feature",
            ent_feature->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_feature");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_feature_includes_component(
    adm_ent_feature_typ * ent_source_feature,
    adm_ent_component_typ * ent_target_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_feature_includes_component_typ * rel_feature_includes_component;

    adm_base_boolean_typ component_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_feature_includes_component");
    #endif

    adm_object_existent_feature(
        ent_source_feature,
        error_file,
        error_line,
        error_rank);

    component_not_found = TRUE;

    rel_feature_includes_component = ent_source_feature->rel_includes_component_head;

    while (
        component_not_found &&
        rel_feature_includes_component != NULL) {

        if (rel_feature_includes_component->ent_component == ent_target_component) {

            component_not_found = FALSE;
        }

        rel_feature_includes_component = rel_feature_includes_component->next;
    }

    if (component_not_found) {

        rel_feature_includes_component = (adm_rel_feature_includes_component_typ*)
            adm_allocate_memory(sizeof(adm_rel_feature_includes_component_typ));

        rel_feature_includes_component->ent_component = ent_target_component;

        if (ent_source_feature->rel_includes_component_head == NULL) {

            rel_feature_includes_component->back = NULL;

            ent_source_feature->rel_includes_component_head = rel_feature_includes_component;

        } else {

            rel_feature_includes_component->back = ent_source_feature->rel_includes_component_tail;

            (ent_source_feature->rel_includes_component_tail)->next = rel_feature_includes_component;
        }

        rel_feature_includes_component->next = NULL;

        ent_source_feature->rel_includes_component_tail = rel_feature_includes_component;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Feature",
            ent_source_feature->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_feature_includes_component");
    #endif
}

void adm_link_relation_feature_includes_feature(
    adm_ent_feature_typ * ent_source_feature,
    adm_ent_feature_typ * ent_target_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature;

    adm_base_boolean_typ feature_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_feature_includes_feature");
    #endif

    adm_object_existent_feature(
        ent_source_feature,
        error_file,
        error_line,
        error_rank);

    feature_not_found = TRUE;

    rel_feature_includes_feature = ent_source_feature->rel_includes_feature_head;

    while (
        feature_not_found &&
        rel_feature_includes_feature != NULL) {

        if (rel_feature_includes_feature->ent_feature == ent_target_feature) {

            feature_not_found = FALSE;
        }

        rel_feature_includes_feature = rel_feature_includes_feature->next;
    }

    if (feature_not_found) {

        rel_feature_includes_feature = (adm_rel_feature_includes_feature_typ*)
            adm_allocate_memory(sizeof(adm_rel_feature_includes_feature_typ));

        rel_feature_includes_feature->ent_feature = ent_target_feature;

        if (ent_source_feature->rel_includes_feature_head == NULL) {

            rel_feature_includes_feature->back = NULL;

            ent_source_feature->rel_includes_feature_head = rel_feature_includes_feature;

        } else {

            rel_feature_includes_feature->back = ent_source_feature->rel_includes_feature_tail;

            (ent_source_feature->rel_includes_feature_tail)->next = rel_feature_includes_feature;
        }

        rel_feature_includes_feature->next = NULL;

        ent_source_feature->rel_includes_feature_tail = rel_feature_includes_feature;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Feature",
            ent_source_feature->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_feature_includes_feature");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_feature_includes_component(
    adm_ent_feature_typ * ent_feature,
    adm_rel_feature_includes_component_typ * rel_feature_includes_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_feature_includes_component");
    #endif

    adm_object_existent_feature(
        ent_feature,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_feature_includes_component->next !=
        (adm_base_integer_typ)rel_feature_includes_component->ent_component) {

        if (ent_feature->rel_includes_component_head != NULL) {

            if (ent_feature->rel_includes_component_head == rel_feature_includes_component) {

                ent_feature->rel_includes_component_head = rel_feature_includes_component->next;

            } else {

                (rel_feature_includes_component->back)->next = rel_feature_includes_component->next;
            }

            if (ent_feature->rel_includes_component_tail == rel_feature_includes_component) {

                ent_feature->rel_includes_component_tail = rel_feature_includes_component->back;

            } else {

                (rel_feature_includes_component->next)->back = rel_feature_includes_component->back;
            }

            adm_deallocate_memory(rel_feature_includes_component);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Feature",
                ent_feature->identity,
                "Includes",
                "Component");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Feature",
            ent_feature->identity,
            "Includes",
            "Component");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_feature_includes_component");
    #endif
}

void adm_kill_relation_feature_includes_feature(
    adm_ent_feature_typ * ent_feature,
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_feature_includes_feature");
    #endif

    adm_object_existent_feature(
        ent_feature,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_feature_includes_feature->next !=
        (adm_base_integer_typ)rel_feature_includes_feature->ent_feature) {

        if (ent_feature->rel_includes_feature_head != NULL) {

            if (ent_feature->rel_includes_feature_head == rel_feature_includes_feature) {

                ent_feature->rel_includes_feature_head = rel_feature_includes_feature->next;

            } else {

                (rel_feature_includes_feature->back)->next = rel_feature_includes_feature->next;
            }

            if (ent_feature->rel_includes_feature_tail == rel_feature_includes_feature) {

                ent_feature->rel_includes_feature_tail = rel_feature_includes_feature->back;

            } else {

                (rel_feature_includes_feature->next)->back = rel_feature_includes_feature->back;
            }

            adm_deallocate_memory(rel_feature_includes_feature);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Feature",
                ent_feature->identity,
                "Includes",
                "Feature");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Feature",
            ent_feature->identity,
            "Includes",
            "Feature");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_feature_includes_feature");
    #endif
}


/* Object Existent */

void adm_object_existent_feature(
    adm_ent_feature_typ * ent_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_feature");
    #endif

    if (ent_feature->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Feature",
            ent_feature->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_feature");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */