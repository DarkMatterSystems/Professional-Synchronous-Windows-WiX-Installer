
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Domain Scheduler */

void adm_scheduler_dom_matrix_installer(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_matrix_installer");
    #endif

    if (adm_entity_system.ent_product.away_pool_head != NULL) adm_dispatcher_product();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_matrix_installer");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination_dom_matrix_installer(
    void)
{
    adm_base_boolean_typ event_pending;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_matrix_installer");
    #endif

    event_pending =
        (adm_entity_system.ent_product.away_pool_head != NULL);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_matrix_installer");
    #endif

    return (event_pending);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */