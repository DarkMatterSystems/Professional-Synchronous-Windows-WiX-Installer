
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product Dispatcher */

/* Dispatcher */

void adm_dispatcher_product(
    void)
{
    adm_pool_target_product_typ * pool_target_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_product");
    #endif

    pool_target_product = adm_find_away_target_event_product();

    adm_dispatch_state_action_product(pool_target_product);

    adm_dispatch_home_pool_product();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_product");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_product(
    void)
{
    adm_pool_target_product_typ * pool_target_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_product");
    #endif

    while (adm_entity_system.ent_product.home_pool_head != NULL) {

        pool_target_product = adm_find_home_target_event_product();

        adm_dispatch_state_action_product(pool_target_product);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_product");
    #endif
}


/* Find Home Target Event */

adm_pool_target_product_typ * adm_find_home_target_event_product(
    void)
{
    adm_pool_target_product_typ * pool_target_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_product");
    #endif

    pool_target_product = adm_entity_system.ent_product.home_pool_head;

    adm_entity_system.ent_product.home_pool_head = pool_target_product->next;

    if (adm_entity_system.ent_product.home_pool_head == NULL) {

        adm_entity_system.ent_product.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_product");
    #endif

    return (pool_target_product);
}


/* Find Away Target Event */

adm_pool_target_product_typ * adm_find_away_target_event_product(
    void)
{
    adm_pool_target_product_typ * pool_target_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_product");
    #endif

    pool_target_product = adm_entity_system.ent_product.away_pool_head;

    adm_entity_system.ent_product.away_pool_head = pool_target_product->next;

    if (adm_entity_system.ent_product.away_pool_head == NULL) {

        adm_entity_system.ent_product.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_product");
    #endif

    return (pool_target_product);
}


/* Dispatch State Action */

void adm_dispatch_state_action_product(
    adm_pool_target_product_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_product");
    #endif

    if (pool_target->ent_product != NULL) {

        adm_object_existent_product(
            pool_target->ent_product,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_PRODUCT_GENERATE :

            switch ((pool_target->ent_product)->status) {

                case ADM_STATUS_PRODUCT_GENERATING :

                    adm_sim_display_state_product_generating(pool_target);

                    (pool_target->ent_product)->status = ADM_STATUS_PRODUCT_GENERATING;

                    adm_state_action_product_generating(
                        pool_target->ent_product);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_product");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */