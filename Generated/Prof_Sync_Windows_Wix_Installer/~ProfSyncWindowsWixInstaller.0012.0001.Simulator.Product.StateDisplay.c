
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Simulator Product Display State */

void adm_sim_display_state_product_generating(
    adm_pool_target_product_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_product_generating");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (2:24:26) - Product[");
        printf("%d", (pool_target->ent_product)->identity);
        printf("] ");
        printf("Generating");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_MATRIX_INSTALLER_PRODUCT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_product[(pool_target->ent_product)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_product_generating");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */