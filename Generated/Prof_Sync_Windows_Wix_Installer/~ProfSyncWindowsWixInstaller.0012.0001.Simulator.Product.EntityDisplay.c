
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product Simulator Display Entity */

void adm_sim_display_entity_product(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_product_typ * ent_product;

    adm_sim_width_product_typ width_product;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_product");
    #endif

    width_product.identity = strlen("Identity");
    width_product.status = strlen("Status");
    width_product.atb_id = strlen("Id");
    width_product.atb_name = strlen("Name");
    width_product.atb_upgrade_code = strlen("Upgrade_code");
    width_product.atb_version = strlen("Version");
    width_product.atb_manufacturer = strlen("Manufacturer");
    width_product.atb_download_version = strlen("Download_version");

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (ent_product != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_product->identity);
        if (width > width_product.identity) width_product.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_product[ent_product->status]);
        if (width > width_product.status) width_product.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_id);
        if (width > width_product.atb_id) width_product.atb_id = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_name);
        if (width > width_product.atb_name) width_product.atb_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_upgrade_code);
        if (width > width_product.atb_upgrade_code) width_product.atb_upgrade_code = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_version);
        if (width > width_product.atb_version) width_product.atb_version = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_manufacturer);
        if (width > width_product.atb_manufacturer) width_product.atb_manufacturer = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_download_version);
        if (width > width_product.atb_download_version) width_product.atb_download_version = width;

        ent_product = ent_product->next;
    }

    printf(NEWLINE);
    printf("Product:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_product.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_id, "Id");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_name, "Name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_upgrade_code, "Upgrade_code");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_version, "Version");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_manufacturer, "Manufacturer");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_product.atb_download_version, "Download_version");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_product.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_id);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_upgrade_code);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_version);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_manufacturer);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_product.atb_download_version);

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (ent_product != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_product.identity, ent_product->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_product->status) {
            case ADM_STATUS_PRODUCT_GENERATING :
                printf("%-*s", width_product.status, "Generating");
            break;
            default :
                printf("%-*s", width_product.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_id);
        printf("%-*s", width_product.atb_id, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_name);
        printf("%-*s", width_product.atb_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_upgrade_code);
        printf("%-*s", width_product.atb_upgrade_code, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_version);
        printf("%-*s", width_product.atb_version, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_manufacturer);
        printf("%-*s", width_product.atb_manufacturer, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_product->atb_download_version);
        printf("%-*s", width_product.atb_download_version, buffer);

        ent_product = ent_product->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_product");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */