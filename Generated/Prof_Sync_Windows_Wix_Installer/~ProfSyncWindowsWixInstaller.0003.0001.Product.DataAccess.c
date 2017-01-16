
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product Data Access */

/* Make Entity Object */

adm_ent_product_typ * adm_make_object_product(
    adm_sta_product_typ status)
{
    adm_ent_product_typ * ent_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_product");
    #endif

    if (adm_entity_system.ent_product.dead_list_head != NULL) {

        ent_product = adm_entity_system.ent_product.dead_list_head;

        if (adm_entity_system.ent_product.dead_list_head == ent_product) {

            adm_entity_system.ent_product.dead_list_head = ent_product->next;

        } else {

            (ent_product->back)->next = ent_product->next;
        }

        if (adm_entity_system.ent_product.dead_list_tail == ent_product) {

            adm_entity_system.ent_product.dead_list_tail = ent_product->back;

        } else {

            (ent_product->next)->back = ent_product->back;
        }

    } else {

        ent_product = (adm_ent_product_typ*)adm_allocate_memory(sizeof(adm_ent_product_typ));
    }

    ent_product->identity = ++adm_entity_system.ent_product.tote;

    ent_product->unique  = FALSE;
    ent_product->deleted = FALSE;
    ent_product->marked  = FALSE;
    ent_product->status  = status;

    ent_product->atb_id = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_product->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_product->atb_upgrade_code = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_product->atb_version = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_product->atb_manufacturer = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);
    ent_product->atb_download_version = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_product->rel_includes_icon_head = NULL;
    ent_product->rel_includes_icon_tail = NULL;

    ent_product->rel_includes_package_head = NULL;
    ent_product->rel_includes_package_tail = NULL;

    ent_product->rel_includes_property_head = NULL;
    ent_product->rel_includes_property_tail = NULL;

    ent_product->rel_includes_directory_head = NULL;
    ent_product->rel_includes_directory_tail = NULL;

    ent_product->rel_includes_feature_head = NULL;
    ent_product->rel_includes_feature_tail = NULL;

    ent_product->back = NULL;
    ent_product->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_product");
    #endif

    return (ent_product);
}


/* Bind Entity Object */

void adm_bind_object_product(
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_product");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_product.live_list_head == NULL) {

        ent_product->back = NULL;

        adm_entity_system.ent_product.live_list_head = ent_product;

    } else {

        ent_product->back = adm_entity_system.ent_product.live_list_tail;

        (adm_entity_system.ent_product.live_list_tail)->next = ent_product;
    }

    ent_product->next = NULL;

    adm_entity_system.ent_product.live_list_tail = ent_product;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_product");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_product(
    void * source_object,
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_product");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_product) {

        if (ent_product->rel_includes_icon_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Icon");
        }

        if (ent_product->rel_includes_package_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Package");
        }

        if (ent_product->rel_includes_property_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Property");
        }

        if (ent_product->rel_includes_directory_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Directory");
        }

        if (ent_product->rel_includes_feature_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Feature");
        }

        if (adm_entity_system.ent_product.live_list_head == ent_product) {

            adm_entity_system.ent_product.live_list_head = ent_product->next;

        } else {

            (ent_product->back)->next = ent_product->next;
        }

        if (adm_entity_system.ent_product.live_list_tail == ent_product) {

            adm_entity_system.ent_product.live_list_tail = ent_product->back;

        } else {

            (ent_product->next)->back = ent_product->back;
        }

        adm_deallocate_memory(ent_product->atb_id);
        adm_deallocate_memory(ent_product->atb_name);
        adm_deallocate_memory(ent_product->atb_upgrade_code);
        adm_deallocate_memory(ent_product->atb_version);
        adm_deallocate_memory(ent_product->atb_manufacturer);
        adm_deallocate_memory(ent_product->atb_download_version);

        ent_product->deleted = TRUE;

        if (adm_entity_system.ent_product.dead_list_head == NULL) {

            ent_product->back = NULL;

            adm_entity_system.ent_product.dead_list_head = ent_product;

        } else {

            ent_product->back = adm_entity_system.ent_product.dead_list_tail;

            (adm_entity_system.ent_product.dead_list_tail)->next = ent_product;
        }

        ent_product->next = NULL;

        adm_entity_system.ent_product.dead_list_tail = ent_product;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_product");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_product_includes_icon(
    adm_ent_product_typ * ent_source_product,
    adm_ent_icon_typ * ent_target_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_product_includes_icon_typ * rel_product_includes_icon;

    adm_base_boolean_typ icon_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_icon");
    #endif

    adm_object_existent_product(
        ent_source_product,
        error_file,
        error_line,
        error_rank);

    icon_not_found = TRUE;

    rel_product_includes_icon = ent_source_product->rel_includes_icon_head;

    while (
        icon_not_found &&
        rel_product_includes_icon != NULL) {

        if (rel_product_includes_icon->ent_icon == ent_target_icon) {

            icon_not_found = FALSE;
        }

        rel_product_includes_icon = rel_product_includes_icon->next;
    }

    if (icon_not_found) {

        rel_product_includes_icon = (adm_rel_product_includes_icon_typ*)
            adm_allocate_memory(sizeof(adm_rel_product_includes_icon_typ));

        rel_product_includes_icon->ent_icon = ent_target_icon;

        if (ent_source_product->rel_includes_icon_head == NULL) {

            rel_product_includes_icon->back = NULL;

            ent_source_product->rel_includes_icon_head = rel_product_includes_icon;

        } else {

            rel_product_includes_icon->back = ent_source_product->rel_includes_icon_tail;

            (ent_source_product->rel_includes_icon_tail)->next = rel_product_includes_icon;
        }

        rel_product_includes_icon->next = NULL;

        ent_source_product->rel_includes_icon_tail = rel_product_includes_icon;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_source_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_icon");
    #endif
}

void adm_link_relation_product_includes_package(
    adm_ent_product_typ * ent_source_product,
    adm_ent_package_typ * ent_target_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_product_includes_package_typ * rel_product_includes_package;

    adm_base_boolean_typ package_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_package");
    #endif

    adm_object_existent_product(
        ent_source_product,
        error_file,
        error_line,
        error_rank);

    package_not_found = TRUE;

    rel_product_includes_package = ent_source_product->rel_includes_package_head;

    while (
        package_not_found &&
        rel_product_includes_package != NULL) {

        if (rel_product_includes_package->ent_package == ent_target_package) {

            package_not_found = FALSE;
        }

        rel_product_includes_package = rel_product_includes_package->next;
    }

    if (package_not_found) {

        rel_product_includes_package = (adm_rel_product_includes_package_typ*)
            adm_allocate_memory(sizeof(adm_rel_product_includes_package_typ));

        rel_product_includes_package->ent_package = ent_target_package;

        if (ent_source_product->rel_includes_package_head == NULL) {

            rel_product_includes_package->back = NULL;

            ent_source_product->rel_includes_package_head = rel_product_includes_package;

        } else {

            rel_product_includes_package->back = ent_source_product->rel_includes_package_tail;

            (ent_source_product->rel_includes_package_tail)->next = rel_product_includes_package;
        }

        rel_product_includes_package->next = NULL;

        ent_source_product->rel_includes_package_tail = rel_product_includes_package;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_source_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_package");
    #endif
}

void adm_link_relation_product_includes_property(
    adm_ent_product_typ * ent_source_product,
    adm_ent_property_typ * ent_target_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_product_includes_property_typ * rel_product_includes_property;

    adm_base_boolean_typ property_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_property");
    #endif

    adm_object_existent_product(
        ent_source_product,
        error_file,
        error_line,
        error_rank);

    property_not_found = TRUE;

    rel_product_includes_property = ent_source_product->rel_includes_property_head;

    while (
        property_not_found &&
        rel_product_includes_property != NULL) {

        if (rel_product_includes_property->ent_property == ent_target_property) {

            property_not_found = FALSE;
        }

        rel_product_includes_property = rel_product_includes_property->next;
    }

    if (property_not_found) {

        rel_product_includes_property = (adm_rel_product_includes_property_typ*)
            adm_allocate_memory(sizeof(adm_rel_product_includes_property_typ));

        rel_product_includes_property->ent_property = ent_target_property;

        if (ent_source_product->rel_includes_property_head == NULL) {

            rel_product_includes_property->back = NULL;

            ent_source_product->rel_includes_property_head = rel_product_includes_property;

        } else {

            rel_product_includes_property->back = ent_source_product->rel_includes_property_tail;

            (ent_source_product->rel_includes_property_tail)->next = rel_product_includes_property;
        }

        rel_product_includes_property->next = NULL;

        ent_source_product->rel_includes_property_tail = rel_product_includes_property;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_source_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_property");
    #endif
}

void adm_link_relation_product_includes_directory(
    adm_ent_product_typ * ent_source_product,
    adm_ent_directory_typ * ent_target_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_product_includes_directory_typ * rel_product_includes_directory;

    adm_base_boolean_typ directory_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_directory");
    #endif

    adm_object_existent_product(
        ent_source_product,
        error_file,
        error_line,
        error_rank);

    directory_not_found = TRUE;

    rel_product_includes_directory = ent_source_product->rel_includes_directory_head;

    while (
        directory_not_found &&
        rel_product_includes_directory != NULL) {

        if (rel_product_includes_directory->ent_directory == ent_target_directory) {

            directory_not_found = FALSE;
        }

        rel_product_includes_directory = rel_product_includes_directory->next;
    }

    if (directory_not_found) {

        rel_product_includes_directory = (adm_rel_product_includes_directory_typ*)
            adm_allocate_memory(sizeof(adm_rel_product_includes_directory_typ));

        rel_product_includes_directory->ent_directory = ent_target_directory;

        if (ent_source_product->rel_includes_directory_head == NULL) {

            rel_product_includes_directory->back = NULL;

            ent_source_product->rel_includes_directory_head = rel_product_includes_directory;

        } else {

            rel_product_includes_directory->back = ent_source_product->rel_includes_directory_tail;

            (ent_source_product->rel_includes_directory_tail)->next = rel_product_includes_directory;
        }

        rel_product_includes_directory->next = NULL;

        ent_source_product->rel_includes_directory_tail = rel_product_includes_directory;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_source_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_directory");
    #endif
}

void adm_link_relation_product_includes_feature(
    adm_ent_product_typ * ent_source_product,
    adm_ent_feature_typ * ent_target_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_product_includes_feature_typ * rel_product_includes_feature;

    adm_base_boolean_typ feature_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_feature");
    #endif

    adm_object_existent_product(
        ent_source_product,
        error_file,
        error_line,
        error_rank);

    feature_not_found = TRUE;

    rel_product_includes_feature = ent_source_product->rel_includes_feature_head;

    while (
        feature_not_found &&
        rel_product_includes_feature != NULL) {

        if (rel_product_includes_feature->ent_feature == ent_target_feature) {

            feature_not_found = FALSE;
        }

        rel_product_includes_feature = rel_product_includes_feature->next;
    }

    if (feature_not_found) {

        rel_product_includes_feature = (adm_rel_product_includes_feature_typ*)
            adm_allocate_memory(sizeof(adm_rel_product_includes_feature_typ));

        rel_product_includes_feature->ent_feature = ent_target_feature;

        if (ent_source_product->rel_includes_feature_head == NULL) {

            rel_product_includes_feature->back = NULL;

            ent_source_product->rel_includes_feature_head = rel_product_includes_feature;

        } else {

            rel_product_includes_feature->back = ent_source_product->rel_includes_feature_tail;

            (ent_source_product->rel_includes_feature_tail)->next = rel_product_includes_feature;
        }

        rel_product_includes_feature->next = NULL;

        ent_source_product->rel_includes_feature_tail = rel_product_includes_feature;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_source_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_product_includes_feature");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_product_includes_icon(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_icon_typ * rel_product_includes_icon,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_icon");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_product_includes_icon->next !=
        (adm_base_integer_typ)rel_product_includes_icon->ent_icon) {

        if (ent_product->rel_includes_icon_head != NULL) {

            if (ent_product->rel_includes_icon_head == rel_product_includes_icon) {

                ent_product->rel_includes_icon_head = rel_product_includes_icon->next;

            } else {

                (rel_product_includes_icon->back)->next = rel_product_includes_icon->next;
            }

            if (ent_product->rel_includes_icon_tail == rel_product_includes_icon) {

                ent_product->rel_includes_icon_tail = rel_product_includes_icon->back;

            } else {

                (rel_product_includes_icon->next)->back = rel_product_includes_icon->back;
            }

            adm_deallocate_memory(rel_product_includes_icon);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Icon");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            "Includes",
            "Icon");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_icon");
    #endif
}

void adm_kill_relation_product_includes_package(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_package_typ * rel_product_includes_package,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_package");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_product_includes_package->next !=
        (adm_base_integer_typ)rel_product_includes_package->ent_package) {

        if (ent_product->rel_includes_package_head != NULL) {

            if (ent_product->rel_includes_package_head == rel_product_includes_package) {

                ent_product->rel_includes_package_head = rel_product_includes_package->next;

            } else {

                (rel_product_includes_package->back)->next = rel_product_includes_package->next;
            }

            if (ent_product->rel_includes_package_tail == rel_product_includes_package) {

                ent_product->rel_includes_package_tail = rel_product_includes_package->back;

            } else {

                (rel_product_includes_package->next)->back = rel_product_includes_package->back;
            }

            adm_deallocate_memory(rel_product_includes_package);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Package");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            "Includes",
            "Package");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_package");
    #endif
}

void adm_kill_relation_product_includes_property(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_property_typ * rel_product_includes_property,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_property");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_product_includes_property->next !=
        (adm_base_integer_typ)rel_product_includes_property->ent_property) {

        if (ent_product->rel_includes_property_head != NULL) {

            if (ent_product->rel_includes_property_head == rel_product_includes_property) {

                ent_product->rel_includes_property_head = rel_product_includes_property->next;

            } else {

                (rel_product_includes_property->back)->next = rel_product_includes_property->next;
            }

            if (ent_product->rel_includes_property_tail == rel_product_includes_property) {

                ent_product->rel_includes_property_tail = rel_product_includes_property->back;

            } else {

                (rel_product_includes_property->next)->back = rel_product_includes_property->back;
            }

            adm_deallocate_memory(rel_product_includes_property);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Property");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            "Includes",
            "Property");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_property");
    #endif
}

void adm_kill_relation_product_includes_directory(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_directory_typ * rel_product_includes_directory,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_directory");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_product_includes_directory->next !=
        (adm_base_integer_typ)rel_product_includes_directory->ent_directory) {

        if (ent_product->rel_includes_directory_head != NULL) {

            if (ent_product->rel_includes_directory_head == rel_product_includes_directory) {

                ent_product->rel_includes_directory_head = rel_product_includes_directory->next;

            } else {

                (rel_product_includes_directory->back)->next = rel_product_includes_directory->next;
            }

            if (ent_product->rel_includes_directory_tail == rel_product_includes_directory) {

                ent_product->rel_includes_directory_tail = rel_product_includes_directory->back;

            } else {

                (rel_product_includes_directory->next)->back = rel_product_includes_directory->back;
            }

            adm_deallocate_memory(rel_product_includes_directory);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Directory");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            "Includes",
            "Directory");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_directory");
    #endif
}

void adm_kill_relation_product_includes_feature(
    adm_ent_product_typ * ent_product,
    adm_rel_product_includes_feature_typ * rel_product_includes_feature,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_feature");
    #endif

    adm_object_existent_product(
        ent_product,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_product_includes_feature->next !=
        (adm_base_integer_typ)rel_product_includes_feature->ent_feature) {

        if (ent_product->rel_includes_feature_head != NULL) {

            if (ent_product->rel_includes_feature_head == rel_product_includes_feature) {

                ent_product->rel_includes_feature_head = rel_product_includes_feature->next;

            } else {

                (rel_product_includes_feature->back)->next = rel_product_includes_feature->next;
            }

            if (ent_product->rel_includes_feature_tail == rel_product_includes_feature) {

                ent_product->rel_includes_feature_tail = rel_product_includes_feature->back;

            } else {

                (rel_product_includes_feature->next)->back = rel_product_includes_feature->back;
            }

            adm_deallocate_memory(rel_product_includes_feature);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Product",
                ent_product->identity,
                "Includes",
                "Feature");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            "Includes",
            "Feature");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_product_includes_feature");
    #endif
}


/* Object Existent */

void adm_object_existent_product(
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_product");
    #endif

    if (ent_product->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Product",
            ent_product->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_product");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */