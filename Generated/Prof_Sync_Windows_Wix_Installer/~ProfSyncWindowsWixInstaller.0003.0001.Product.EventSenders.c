
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product Event Senders */

void adm_send_event_product_generate(
    void * source_object,
    adm_ent_product_typ * ent_product,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_product_typ * pool_target;
    adm_pool_target_product_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_product_generate");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_product_generate(
            ent_product,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_product(
            ent_product,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_product_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_product_typ));

        pool_target->evente = ADM_EVENT_PRODUCT_GENERATE;
        pool_target->ent_product = ent_product;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_product) {

            if (adm_entity_system.ent_product.home_pool_head == NULL) {

                adm_entity_system.ent_product.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_product.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_product == ent_product) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Product",
                            ent_product->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_product.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_product.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_product.away_pool_head == NULL) {

                adm_entity_system.ent_product.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_product.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_product.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_product_generate");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */