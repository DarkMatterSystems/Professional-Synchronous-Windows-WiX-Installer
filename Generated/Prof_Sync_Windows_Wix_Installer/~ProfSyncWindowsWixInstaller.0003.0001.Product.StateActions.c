
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product State Actions */

void adm_state_action_product_generating(
    adm_ent_product_typ * ent_product)
{
    /* Entity Objects */
    adm_ent_package_typ * ent_package_0000000002;
    adm_ent_property_typ * ent_property_0000000004;
    adm_ent_icon_typ * ent_icon_0000000006;
    adm_ent_directory_typ * ent_directory_0000000007;
    adm_ent_feature_typ * ent_feature_0000000041;

    /* Relationship Relations */
    adm_rel_product_includes_package_typ * rel_product_includes_package_0000000002;
    adm_rel_product_includes_property_typ * rel_product_includes_property_0000000004;
    adm_rel_product_includes_icon_typ * rel_product_includes_icon_0000000006;
    adm_rel_product_includes_directory_typ * rel_product_includes_directory_0000000007;
    adm_rel_product_includes_feature_typ * rel_product_includes_feature_0000000041;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating");
    #endif

    /* Stream */

    adm_stream.index = 0;

    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "M:");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "\\Matrix");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "\\Scenarios");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "\\Prof_Sync_Windows_Wix_Installer");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "\\Logging");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "\\Matrix-V");
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, ent_product->atb_download_version);
    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, ".wxs");

    if (!strcmp(adm_stream.pathname, ADM_SYSTEM_STREAM_NULL)) {

        adm_close_stream_file(2, 26, 21);

        adm_stream.active = FALSE;

    } else if (!strcmp(adm_stream.pathname, ADM_SYSTEM_STREAM_DISPLAY)) {

        adm_close_stream_file(2, 26, 21);

        adm_stream.active = TRUE;

    } else {

        adm_open_stream_file(2, 26, 21);
    }

    /* Template */

    adm_write_str("<?xml version='1.0' encoding='windows-1252'?>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Learning Edition Installer -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~ -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");
    adm_write_newline();
    adm_template_tab_in(2, 33, 21);
    adm_write_newline();
    adm_write_str("<!-- Filename: Matrix-V");
    adm_write_str(ent_product->atb_download_version);
    adm_write_str(".wxs -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Product");
    adm_template_tab_in(2, 33, 21);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_product->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Name='");
    adm_write_str(ent_product->atb_name);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("UpgradeCode='");
    adm_write_str(ent_product->atb_upgrade_code);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Language='1033'");
    adm_write_newline();
    adm_write_str("Codepage='1252'");
    adm_write_newline();
    adm_write_str("Version='");
    adm_write_str(ent_product->atb_version);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Manufacturer='");
    adm_write_str(ent_product->atb_manufacturer);
    adm_write_str("'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Prologe -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~ -->");

    /* ProcessEntityInclude - Enter: 001_003_001_Process_Generate_Package */

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        3, 8, 13);

    rel_product_includes_package_0000000002 = ent_product->rel_includes_package_head;

    ent_package_0000000002 = rel_product_includes_package_0000000002->ent_package;

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Package");
    adm_template_tab_in(3, 10, 13);
    adm_write_newline();
    adm_write_str("Id='*'");
    adm_write_newline();
    adm_write_str("Keywords='Installer'");
    adm_write_newline();
    adm_write_str("Description='");
    adm_write_str(ent_package_0000000002->atb_description);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Comments='");
    adm_write_str(ent_package_0000000002->atb_comments);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Manufacturer='");
    adm_write_str(ent_package_0000000002->atb_manufacture);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("InstallerVersion='100'");
    adm_write_newline();
    adm_write_str("Languages='1033'");
    adm_write_newline();
    adm_write_str("Compressed='yes'");
    adm_write_newline();
    adm_write_str("SummaryCodepage='1252'/>");
    adm_template_tab_out(3, 10, 13);

    /* ProcessEntityInclude - Leave: 001_003_001_Process_Generate_Package */

    /* ProcessEntityInclude - Enter: 001_004_001_Process_Generate_Property */

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        4, 8, 13);

    rel_product_includes_property_0000000004 = ent_product->rel_includes_property_head;

    while (rel_product_includes_property_0000000004 != NULL) {

        ent_property_0000000004 = rel_product_includes_property_0000000004->ent_property;

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_str("<Property");
        adm_template_tab_in(4, 10, 13);
        adm_write_newline();
        adm_write_str("Id='");
        adm_write_str(ent_property_0000000004->atb_id);
        adm_write_str("'");
        adm_write_newline();
        adm_write_str("Value='");
        adm_write_str(ent_property_0000000004->atb_value);
        adm_write_str("'/>");
        adm_template_tab_out(4, 10, 13);

        rel_product_includes_property_0000000004 = rel_product_includes_property_0000000004->next;
    }

    /* ProcessEntityInclude - Leave: 001_004_001_Process_Generate_Property */

    /* ProcessEntityInclude - Enter: 001_002_001_Process_Generate_Icon */

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        5, 8, 13);

    rel_product_includes_icon_0000000006 = ent_product->rel_includes_icon_head;

    while (rel_product_includes_icon_0000000006 != NULL) {

        ent_icon_0000000006 = rel_product_includes_icon_0000000006->ent_icon;

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_str("<Icon");
        adm_template_tab_in(5, 10, 13);
        adm_write_newline();
        adm_write_str("Id='");
        adm_write_str(ent_icon_0000000006->atb_id);
        adm_write_str("'");
        adm_write_newline();
        adm_write_str("SourceFile='");
        adm_write_str(ent_icon_0000000006->atb_source_file);
        adm_write_str("'/>");
        adm_template_tab_out(5, 10, 13);

        rel_product_includes_icon_0000000006 = rel_product_includes_icon_0000000006->next;
    }

    /* ProcessEntityInclude - Leave: 001_002_001_Process_Generate_Icon */

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        2, 63, 29);

    rel_product_includes_directory_0000000007 = ent_product->rel_includes_directory_head;

    ent_directory_0000000007 = rel_product_includes_directory_0000000007->ent_directory;

    /* ProcessEntityInclude - Procedure: 001_005_001_Process_Generate_Directory */

    adm_ent_pro_product_001_005_001_process_generate_directory(
        ent_directory_0000000007);

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        2, 69, 29);

    rel_product_includes_feature_0000000041 = ent_product->rel_includes_feature_head;

    ent_feature_0000000041 = rel_product_includes_feature_0000000041->ent_feature;

    /* ProcessEntityInclude - Procedure: 001_016_001_Process_Generate_Feature */

    adm_ent_pro_product_001_016_001_process_generate_feature(
        ent_feature_0000000041);

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Miscellaneous -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~~~~~~~ -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Media");
    adm_write_newline();
    adm_write_str("    Id='1'");
    adm_write_newline();
    adm_write_str("    Cabinet='Sample.cab'");
    adm_write_newline();
    adm_write_str("    EmbedCab='yes'");
    adm_write_newline();
    adm_write_str("    DiskPrompt='CD-ROM #1'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<CustomAction");
    adm_write_newline();
    adm_write_str("    Id='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("    Property='TARGETDIR'");
    adm_write_newline();
    adm_write_str("    Value='C:\\'");
    adm_write_newline();
    adm_write_str("    Execute='firstSequence'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<InstallUISequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("    <Custom");
    adm_write_newline();
    adm_write_str("        Action='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("        Before='CostInitialize'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("        TARGETDIR=\"\"");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("     </Custom>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("</InstallUISequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<InstallExecuteSequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("    <Custom");
    adm_write_newline();
    adm_write_str("        Action='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("        Before='CostInitialize'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("        TARGETDIR=\"\"");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("     </Custom>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("</InstallExecuteSequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<UIRef Id='WixUI_Minimal'/>");
    adm_write_newline();
    adm_write_str("<UIRef Id='WixUI_ErrorProgressText'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Replace Standard License and Installer Icons -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUILicenseRtf' Value='Source\\Licence.rtf'/>");
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUIDialogBmp'  Value='Source\\Icons\\UIDialog.bmp'/>");
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUIBannerBmp'  Value='Source\\Icons\\UIBanner.bmp'/>");
    adm_write_newline();
    adm_template_tab_out(2, 73, 21);
    adm_write_newline();
    adm_write_str("</Product>");
    adm_write_newline();
    adm_template_tab_out(2, 73, 21);
    adm_write_newline();
    adm_write_str("</Wix>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. -->");
    adm_write_newline();

    /* Stream */

    adm_stream.index = 0;

    adm_stream.index += sprintf_s(adm_stream.pathname+adm_stream.index, ADM_SYSTEM_PATHNAME_SIZE-adm_stream.index, "DISPLAY:");

    if (!strcmp(adm_stream.pathname, ADM_SYSTEM_STREAM_NULL)) {

        adm_close_stream_file(2, 134, 21);

        adm_stream.active = FALSE;

    } else if (!strcmp(adm_stream.pathname, ADM_SYSTEM_STREAM_DISPLAY)) {

        adm_close_stream_file(2, 134, 21);

        adm_stream.active = TRUE;

    } else {

        adm_open_stream_file(2, 134, 21);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */