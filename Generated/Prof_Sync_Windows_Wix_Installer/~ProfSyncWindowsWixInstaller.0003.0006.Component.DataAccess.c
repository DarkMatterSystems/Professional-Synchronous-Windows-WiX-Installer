
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Component Data Access */

/* Make Entity Object */

adm_ent_component_typ * adm_make_object_component(
    void)
{
    adm_ent_component_typ * ent_component;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_component");
    #endif

    if (adm_entity_system.ent_component.dead_list_head != NULL) {

        ent_component = adm_entity_system.ent_component.dead_list_head;

        if (adm_entity_system.ent_component.dead_list_head == ent_component) {

            adm_entity_system.ent_component.dead_list_head = ent_component->next;

        } else {

            (ent_component->back)->next = ent_component->next;
        }

        if (adm_entity_system.ent_component.dead_list_tail == ent_component) {

            adm_entity_system.ent_component.dead_list_tail = ent_component->back;

        } else {

            (ent_component->next)->back = ent_component->back;
        }

    } else {

        ent_component = (adm_ent_component_typ*)adm_allocate_memory(sizeof(adm_ent_component_typ));
    }

    ent_component->identity = ++adm_entity_system.ent_component.tote;

    ent_component->unique  = FALSE;
    ent_component->deleted = FALSE;
    ent_component->marked  = FALSE;
    ent_component->ignore  = null;

    ent_component->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_component->atb_guid = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_component->atb_condition = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_component->rel_includes_file_head = NULL;
    ent_component->rel_includes_file_tail = NULL;

    ent_component->rel_includes_uninstall_shortcut_head = NULL;
    ent_component->rel_includes_uninstall_shortcut_tail = NULL;

    ent_component->rel_includes_create_folder_head = NULL;
    ent_component->rel_includes_create_folder_tail = NULL;

    ent_component->rel_includes_remove_folder_head = NULL;
    ent_component->rel_includes_remove_folder_tail = NULL;

    ent_component->rel_includes_environment_head = NULL;
    ent_component->rel_includes_environment_tail = NULL;

    ent_component->rel_includes_registry_key_head = NULL;
    ent_component->rel_includes_registry_key_tail = NULL;

    ent_component->rel_includes_registry_value_head = NULL;
    ent_component->rel_includes_registry_value_tail = NULL;

    ent_component->back = NULL;
    ent_component->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_component");
    #endif

    return (ent_component);
}


/* Bind Entity Object */

void adm_bind_object_component(
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_component");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_component.live_list_head == NULL) {

        ent_component->back = NULL;

        adm_entity_system.ent_component.live_list_head = ent_component;

    } else {

        ent_component->back = adm_entity_system.ent_component.live_list_tail;

        (adm_entity_system.ent_component.live_list_tail)->next = ent_component;
    }

    ent_component->next = NULL;

    adm_entity_system.ent_component.live_list_tail = ent_component;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_component");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_component(
    void * source_object,
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_component");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_component) {

        if (ent_component->rel_includes_file_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "File");
        }

        if (ent_component->rel_includes_uninstall_shortcut_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Uninstall_Shortcut");
        }

        if (ent_component->rel_includes_create_folder_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Create_Folder");
        }

        if (ent_component->rel_includes_remove_folder_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Remove_Folder");
        }

        if (ent_component->rel_includes_environment_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Environment");
        }

        if (ent_component->rel_includes_registry_key_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Key");
        }

        if (ent_component->rel_includes_registry_value_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Value");
        }

        if (adm_entity_system.ent_component.live_list_head == ent_component) {

            adm_entity_system.ent_component.live_list_head = ent_component->next;

        } else {

            (ent_component->back)->next = ent_component->next;
        }

        if (adm_entity_system.ent_component.live_list_tail == ent_component) {

            adm_entity_system.ent_component.live_list_tail = ent_component->back;

        } else {

            (ent_component->next)->back = ent_component->back;
        }

        adm_deallocate_memory(ent_component->atb_id);
        adm_deallocate_memory(ent_component->atb_guid);
        adm_deallocate_memory(ent_component->atb_condition);

        ent_component->deleted = TRUE;

        if (adm_entity_system.ent_component.dead_list_head == NULL) {

            ent_component->back = NULL;

            adm_entity_system.ent_component.dead_list_head = ent_component;

        } else {

            ent_component->back = adm_entity_system.ent_component.dead_list_tail;

            (adm_entity_system.ent_component.dead_list_tail)->next = ent_component;
        }

        ent_component->next = NULL;

        adm_entity_system.ent_component.dead_list_tail = ent_component;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_component");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_component_includes_file(
    adm_ent_component_typ * ent_source_component,
    adm_ent_file_typ * ent_target_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_file_typ * rel_component_includes_file;

    adm_base_boolean_typ file_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_file");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    file_not_found = TRUE;

    rel_component_includes_file = ent_source_component->rel_includes_file_head;

    while (
        file_not_found &&
        rel_component_includes_file != NULL) {

        if (rel_component_includes_file->ent_file == ent_target_file) {

            file_not_found = FALSE;
        }

        rel_component_includes_file = rel_component_includes_file->next;
    }

    if (file_not_found) {

        rel_component_includes_file = (adm_rel_component_includes_file_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_file_typ));

        rel_component_includes_file->ent_file = ent_target_file;

        if (ent_source_component->rel_includes_file_head == NULL) {

            rel_component_includes_file->back = NULL;

            ent_source_component->rel_includes_file_head = rel_component_includes_file;

        } else {

            rel_component_includes_file->back = ent_source_component->rel_includes_file_tail;

            (ent_source_component->rel_includes_file_tail)->next = rel_component_includes_file;
        }

        rel_component_includes_file->next = NULL;

        ent_source_component->rel_includes_file_tail = rel_component_includes_file;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_file");
    #endif
}

void adm_link_relation_component_includes_uninstall_shortcut(
    adm_ent_component_typ * ent_source_component,
    adm_ent_uninstall_shortcut_typ * ent_target_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_uninstall_shortcut_typ * rel_component_includes_uninstall_shortcut;

    adm_base_boolean_typ uninstall_shortcut_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_uninstall_shortcut");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    uninstall_shortcut_not_found = TRUE;

    rel_component_includes_uninstall_shortcut = ent_source_component->rel_includes_uninstall_shortcut_head;

    while (
        uninstall_shortcut_not_found &&
        rel_component_includes_uninstall_shortcut != NULL) {

        if (rel_component_includes_uninstall_shortcut->ent_uninstall_shortcut == ent_target_uninstall_shortcut) {

            uninstall_shortcut_not_found = FALSE;
        }

        rel_component_includes_uninstall_shortcut = rel_component_includes_uninstall_shortcut->next;
    }

    if (uninstall_shortcut_not_found) {

        rel_component_includes_uninstall_shortcut = (adm_rel_component_includes_uninstall_shortcut_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_uninstall_shortcut_typ));

        rel_component_includes_uninstall_shortcut->ent_uninstall_shortcut = ent_target_uninstall_shortcut;

        if (ent_source_component->rel_includes_uninstall_shortcut_head == NULL) {

            rel_component_includes_uninstall_shortcut->back = NULL;

            ent_source_component->rel_includes_uninstall_shortcut_head = rel_component_includes_uninstall_shortcut;

        } else {

            rel_component_includes_uninstall_shortcut->back = ent_source_component->rel_includes_uninstall_shortcut_tail;

            (ent_source_component->rel_includes_uninstall_shortcut_tail)->next = rel_component_includes_uninstall_shortcut;
        }

        rel_component_includes_uninstall_shortcut->next = NULL;

        ent_source_component->rel_includes_uninstall_shortcut_tail = rel_component_includes_uninstall_shortcut;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_uninstall_shortcut");
    #endif
}

void adm_link_relation_component_includes_create_folder(
    adm_ent_component_typ * ent_source_component,
    adm_ent_create_folder_typ * ent_target_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_create_folder_typ * rel_component_includes_create_folder;

    adm_base_boolean_typ create_folder_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_create_folder");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    create_folder_not_found = TRUE;

    rel_component_includes_create_folder = ent_source_component->rel_includes_create_folder_head;

    while (
        create_folder_not_found &&
        rel_component_includes_create_folder != NULL) {

        if (rel_component_includes_create_folder->ent_create_folder == ent_target_create_folder) {

            create_folder_not_found = FALSE;
        }

        rel_component_includes_create_folder = rel_component_includes_create_folder->next;
    }

    if (create_folder_not_found) {

        rel_component_includes_create_folder = (adm_rel_component_includes_create_folder_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_create_folder_typ));

        rel_component_includes_create_folder->ent_create_folder = ent_target_create_folder;

        if (ent_source_component->rel_includes_create_folder_head == NULL) {

            rel_component_includes_create_folder->back = NULL;

            ent_source_component->rel_includes_create_folder_head = rel_component_includes_create_folder;

        } else {

            rel_component_includes_create_folder->back = ent_source_component->rel_includes_create_folder_tail;

            (ent_source_component->rel_includes_create_folder_tail)->next = rel_component_includes_create_folder;
        }

        rel_component_includes_create_folder->next = NULL;

        ent_source_component->rel_includes_create_folder_tail = rel_component_includes_create_folder;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_create_folder");
    #endif
}

void adm_link_relation_component_includes_remove_folder(
    adm_ent_component_typ * ent_source_component,
    adm_ent_remove_folder_typ * ent_target_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_remove_folder_typ * rel_component_includes_remove_folder;

    adm_base_boolean_typ remove_folder_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_remove_folder");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    remove_folder_not_found = TRUE;

    rel_component_includes_remove_folder = ent_source_component->rel_includes_remove_folder_head;

    while (
        remove_folder_not_found &&
        rel_component_includes_remove_folder != NULL) {

        if (rel_component_includes_remove_folder->ent_remove_folder == ent_target_remove_folder) {

            remove_folder_not_found = FALSE;
        }

        rel_component_includes_remove_folder = rel_component_includes_remove_folder->next;
    }

    if (remove_folder_not_found) {

        rel_component_includes_remove_folder = (adm_rel_component_includes_remove_folder_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_remove_folder_typ));

        rel_component_includes_remove_folder->ent_remove_folder = ent_target_remove_folder;

        if (ent_source_component->rel_includes_remove_folder_head == NULL) {

            rel_component_includes_remove_folder->back = NULL;

            ent_source_component->rel_includes_remove_folder_head = rel_component_includes_remove_folder;

        } else {

            rel_component_includes_remove_folder->back = ent_source_component->rel_includes_remove_folder_tail;

            (ent_source_component->rel_includes_remove_folder_tail)->next = rel_component_includes_remove_folder;
        }

        rel_component_includes_remove_folder->next = NULL;

        ent_source_component->rel_includes_remove_folder_tail = rel_component_includes_remove_folder;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_remove_folder");
    #endif
}

void adm_link_relation_component_includes_environment(
    adm_ent_component_typ * ent_source_component,
    adm_ent_environment_typ * ent_target_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_environment_typ * rel_component_includes_environment;

    adm_base_boolean_typ environment_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_environment");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    environment_not_found = TRUE;

    rel_component_includes_environment = ent_source_component->rel_includes_environment_head;

    while (
        environment_not_found &&
        rel_component_includes_environment != NULL) {

        if (rel_component_includes_environment->ent_environment == ent_target_environment) {

            environment_not_found = FALSE;
        }

        rel_component_includes_environment = rel_component_includes_environment->next;
    }

    if (environment_not_found) {

        rel_component_includes_environment = (adm_rel_component_includes_environment_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_environment_typ));

        rel_component_includes_environment->ent_environment = ent_target_environment;

        if (ent_source_component->rel_includes_environment_head == NULL) {

            rel_component_includes_environment->back = NULL;

            ent_source_component->rel_includes_environment_head = rel_component_includes_environment;

        } else {

            rel_component_includes_environment->back = ent_source_component->rel_includes_environment_tail;

            (ent_source_component->rel_includes_environment_tail)->next = rel_component_includes_environment;
        }

        rel_component_includes_environment->next = NULL;

        ent_source_component->rel_includes_environment_tail = rel_component_includes_environment;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_environment");
    #endif
}

void adm_link_relation_component_includes_registry_key(
    adm_ent_component_typ * ent_source_component,
    adm_ent_registry_key_typ * ent_target_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_registry_key_typ * rel_component_includes_registry_key;

    adm_base_boolean_typ registry_key_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_registry_key");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    registry_key_not_found = TRUE;

    rel_component_includes_registry_key = ent_source_component->rel_includes_registry_key_head;

    while (
        registry_key_not_found &&
        rel_component_includes_registry_key != NULL) {

        if (rel_component_includes_registry_key->ent_registry_key == ent_target_registry_key) {

            registry_key_not_found = FALSE;
        }

        rel_component_includes_registry_key = rel_component_includes_registry_key->next;
    }

    if (registry_key_not_found) {

        rel_component_includes_registry_key = (adm_rel_component_includes_registry_key_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_registry_key_typ));

        rel_component_includes_registry_key->ent_registry_key = ent_target_registry_key;

        if (ent_source_component->rel_includes_registry_key_head == NULL) {

            rel_component_includes_registry_key->back = NULL;

            ent_source_component->rel_includes_registry_key_head = rel_component_includes_registry_key;

        } else {

            rel_component_includes_registry_key->back = ent_source_component->rel_includes_registry_key_tail;

            (ent_source_component->rel_includes_registry_key_tail)->next = rel_component_includes_registry_key;
        }

        rel_component_includes_registry_key->next = NULL;

        ent_source_component->rel_includes_registry_key_tail = rel_component_includes_registry_key;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_registry_key");
    #endif
}

void adm_link_relation_component_includes_registry_value(
    adm_ent_component_typ * ent_source_component,
    adm_ent_registry_value_typ * ent_target_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_component_includes_registry_value_typ * rel_component_includes_registry_value;

    adm_base_boolean_typ registry_value_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_registry_value");
    #endif

    adm_object_existent_component(
        ent_source_component,
        error_file,
        error_line,
        error_rank);

    registry_value_not_found = TRUE;

    rel_component_includes_registry_value = ent_source_component->rel_includes_registry_value_head;

    while (
        registry_value_not_found &&
        rel_component_includes_registry_value != NULL) {

        if (rel_component_includes_registry_value->ent_registry_value == ent_target_registry_value) {

            registry_value_not_found = FALSE;
        }

        rel_component_includes_registry_value = rel_component_includes_registry_value->next;
    }

    if (registry_value_not_found) {

        rel_component_includes_registry_value = (adm_rel_component_includes_registry_value_typ*)
            adm_allocate_memory(sizeof(adm_rel_component_includes_registry_value_typ));

        rel_component_includes_registry_value->ent_registry_value = ent_target_registry_value;

        if (ent_source_component->rel_includes_registry_value_head == NULL) {

            rel_component_includes_registry_value->back = NULL;

            ent_source_component->rel_includes_registry_value_head = rel_component_includes_registry_value;

        } else {

            rel_component_includes_registry_value->back = ent_source_component->rel_includes_registry_value_tail;

            (ent_source_component->rel_includes_registry_value_tail)->next = rel_component_includes_registry_value;
        }

        rel_component_includes_registry_value->next = NULL;

        ent_source_component->rel_includes_registry_value_tail = rel_component_includes_registry_value;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_source_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_component_includes_registry_value");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_component_includes_file(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_file_typ * rel_component_includes_file,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_file");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_file->next !=
        (adm_base_integer_typ)rel_component_includes_file->ent_file) {

        if (ent_component->rel_includes_file_head != NULL) {

            if (ent_component->rel_includes_file_head == rel_component_includes_file) {

                ent_component->rel_includes_file_head = rel_component_includes_file->next;

            } else {

                (rel_component_includes_file->back)->next = rel_component_includes_file->next;
            }

            if (ent_component->rel_includes_file_tail == rel_component_includes_file) {

                ent_component->rel_includes_file_tail = rel_component_includes_file->back;

            } else {

                (rel_component_includes_file->next)->back = rel_component_includes_file->back;
            }

            adm_deallocate_memory(rel_component_includes_file);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "File");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "File");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_file");
    #endif
}

void adm_kill_relation_component_includes_uninstall_shortcut(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_uninstall_shortcut_typ * rel_component_includes_uninstall_shortcut,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_uninstall_shortcut");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_uninstall_shortcut->next !=
        (adm_base_integer_typ)rel_component_includes_uninstall_shortcut->ent_uninstall_shortcut) {

        if (ent_component->rel_includes_uninstall_shortcut_head != NULL) {

            if (ent_component->rel_includes_uninstall_shortcut_head == rel_component_includes_uninstall_shortcut) {

                ent_component->rel_includes_uninstall_shortcut_head = rel_component_includes_uninstall_shortcut->next;

            } else {

                (rel_component_includes_uninstall_shortcut->back)->next = rel_component_includes_uninstall_shortcut->next;
            }

            if (ent_component->rel_includes_uninstall_shortcut_tail == rel_component_includes_uninstall_shortcut) {

                ent_component->rel_includes_uninstall_shortcut_tail = rel_component_includes_uninstall_shortcut->back;

            } else {

                (rel_component_includes_uninstall_shortcut->next)->back = rel_component_includes_uninstall_shortcut->back;
            }

            adm_deallocate_memory(rel_component_includes_uninstall_shortcut);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Uninstall_Shortcut");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Uninstall_Shortcut");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_uninstall_shortcut");
    #endif
}

void adm_kill_relation_component_includes_create_folder(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_create_folder_typ * rel_component_includes_create_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_create_folder");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_create_folder->next !=
        (adm_base_integer_typ)rel_component_includes_create_folder->ent_create_folder) {

        if (ent_component->rel_includes_create_folder_head != NULL) {

            if (ent_component->rel_includes_create_folder_head == rel_component_includes_create_folder) {

                ent_component->rel_includes_create_folder_head = rel_component_includes_create_folder->next;

            } else {

                (rel_component_includes_create_folder->back)->next = rel_component_includes_create_folder->next;
            }

            if (ent_component->rel_includes_create_folder_tail == rel_component_includes_create_folder) {

                ent_component->rel_includes_create_folder_tail = rel_component_includes_create_folder->back;

            } else {

                (rel_component_includes_create_folder->next)->back = rel_component_includes_create_folder->back;
            }

            adm_deallocate_memory(rel_component_includes_create_folder);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Create_Folder");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Create_Folder");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_create_folder");
    #endif
}

void adm_kill_relation_component_includes_remove_folder(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_remove_folder_typ * rel_component_includes_remove_folder,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_remove_folder");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_remove_folder->next !=
        (adm_base_integer_typ)rel_component_includes_remove_folder->ent_remove_folder) {

        if (ent_component->rel_includes_remove_folder_head != NULL) {

            if (ent_component->rel_includes_remove_folder_head == rel_component_includes_remove_folder) {

                ent_component->rel_includes_remove_folder_head = rel_component_includes_remove_folder->next;

            } else {

                (rel_component_includes_remove_folder->back)->next = rel_component_includes_remove_folder->next;
            }

            if (ent_component->rel_includes_remove_folder_tail == rel_component_includes_remove_folder) {

                ent_component->rel_includes_remove_folder_tail = rel_component_includes_remove_folder->back;

            } else {

                (rel_component_includes_remove_folder->next)->back = rel_component_includes_remove_folder->back;
            }

            adm_deallocate_memory(rel_component_includes_remove_folder);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Remove_Folder");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Remove_Folder");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_remove_folder");
    #endif
}

void adm_kill_relation_component_includes_environment(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_environment_typ * rel_component_includes_environment,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_environment");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_environment->next !=
        (adm_base_integer_typ)rel_component_includes_environment->ent_environment) {

        if (ent_component->rel_includes_environment_head != NULL) {

            if (ent_component->rel_includes_environment_head == rel_component_includes_environment) {

                ent_component->rel_includes_environment_head = rel_component_includes_environment->next;

            } else {

                (rel_component_includes_environment->back)->next = rel_component_includes_environment->next;
            }

            if (ent_component->rel_includes_environment_tail == rel_component_includes_environment) {

                ent_component->rel_includes_environment_tail = rel_component_includes_environment->back;

            } else {

                (rel_component_includes_environment->next)->back = rel_component_includes_environment->back;
            }

            adm_deallocate_memory(rel_component_includes_environment);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Environment");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Environment");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_environment");
    #endif
}

void adm_kill_relation_component_includes_registry_key(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_registry_key_typ * rel_component_includes_registry_key,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_registry_key");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_registry_key->next !=
        (adm_base_integer_typ)rel_component_includes_registry_key->ent_registry_key) {

        if (ent_component->rel_includes_registry_key_head != NULL) {

            if (ent_component->rel_includes_registry_key_head == rel_component_includes_registry_key) {

                ent_component->rel_includes_registry_key_head = rel_component_includes_registry_key->next;

            } else {

                (rel_component_includes_registry_key->back)->next = rel_component_includes_registry_key->next;
            }

            if (ent_component->rel_includes_registry_key_tail == rel_component_includes_registry_key) {

                ent_component->rel_includes_registry_key_tail = rel_component_includes_registry_key->back;

            } else {

                (rel_component_includes_registry_key->next)->back = rel_component_includes_registry_key->back;
            }

            adm_deallocate_memory(rel_component_includes_registry_key);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Key");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Registry_Key");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_registry_key");
    #endif
}

void adm_kill_relation_component_includes_registry_value(
    adm_ent_component_typ * ent_component,
    adm_rel_component_includes_registry_value_typ * rel_component_includes_registry_value,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_registry_value");
    #endif

    adm_object_existent_component(
        ent_component,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_component_includes_registry_value->next !=
        (adm_base_integer_typ)rel_component_includes_registry_value->ent_registry_value) {

        if (ent_component->rel_includes_registry_value_head != NULL) {

            if (ent_component->rel_includes_registry_value_head == rel_component_includes_registry_value) {

                ent_component->rel_includes_registry_value_head = rel_component_includes_registry_value->next;

            } else {

                (rel_component_includes_registry_value->back)->next = rel_component_includes_registry_value->next;
            }

            if (ent_component->rel_includes_registry_value_tail == rel_component_includes_registry_value) {

                ent_component->rel_includes_registry_value_tail = rel_component_includes_registry_value->back;

            } else {

                (rel_component_includes_registry_value->next)->back = rel_component_includes_registry_value->back;
            }

            adm_deallocate_memory(rel_component_includes_registry_value);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Value");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            "Includes",
            "Registry_Value");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_component_includes_registry_value");
    #endif
}


/* Object Existent */

void adm_object_existent_component(
    adm_ent_component_typ * ent_component,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_component");
    #endif

    if (ent_component->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Component",
            ent_component->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_component");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */