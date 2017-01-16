
#include "~ProfSyncWindowsWixInstaller.0000.0000.Header.h"


/* Product Process Includes */

void adm_ent_pro_product_001_005_001_process_generate_directory(
    adm_ent_directory_typ * ent_directory_0000000007)
{
    /* Entity Objects */
    adm_ent_component_typ * ent_component_0000000009;
    adm_ent_directory_typ * ent_directory_0000000011;
    adm_ent_component_typ * ent_component_0000000012;
    adm_ent_file_typ * ent_file_0000000015;
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000016;
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000019;
    adm_ent_shortcut_typ * ent_shortcut_0000000019;
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000020;
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut_0000000023;
    adm_ent_shortcut_typ * ent_shortcut_0000000023;
    adm_ent_create_folder_typ * ent_create_folder_0000000025;
    adm_ent_remove_folder_typ * ent_remove_folder_0000000027;
    adm_ent_environment_typ * ent_environment_0000000029;
    adm_ent_registry_key_typ * ent_registry_key_0000000031;
    adm_ent_registry_value_typ * ent_registry_value_0000000032;
    adm_ent_registry_value_typ * ent_registry_value_0000000034;
    adm_ent_directory_typ * ent_directory_0000000036;
    adm_ent_component_typ * ent_component_0000000037;
    adm_ent_directory_typ * ent_directory_0000000039;

    /* Relationship Relations */
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000009;
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000011;
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000012;
    adm_rel_component_includes_file_typ * rel_component_includes_file_0000000015;
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000016;
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000019;
    adm_rel_file_shortcut_specialisation_shortcut_typ * rel_file_shortcut_specialisation_shortcut_0000000019;
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000020;
    adm_rel_component_includes_uninstall_shortcut_typ * rel_component_includes_uninstall_shortcut_0000000023;
    adm_rel_uninstall_shortcut_specialisation_shortcut_typ * rel_uninstall_shortcut_specialisation_shortcut_0000000023;
    adm_rel_component_includes_create_folder_typ * rel_component_includes_create_folder_0000000025;
    adm_rel_component_includes_remove_folder_typ * rel_component_includes_remove_folder_0000000027;
    adm_rel_component_includes_environment_typ * rel_component_includes_environment_0000000029;
    adm_rel_component_includes_registry_key_typ * rel_component_includes_registry_key_0000000031;
    adm_rel_registry_key_includes_registry_value_typ * rel_registry_key_includes_registry_value_0000000032;
    adm_rel_component_includes_registry_value_typ * rel_component_includes_registry_value_0000000034;
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000036;
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000037;
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000039;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000010;
    adm_base_boolean_typ traverse_not_found_0000000017;
    adm_base_boolean_typ traverse_not_found_0000000021;
    adm_base_boolean_typ traverse_not_found_0000000038;
    adm_base_boolean_typ traverse_not_found_0000000040;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_005_001_process_generate_directory");
    #endif

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_directory_0000000007->atb_heading, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_newline();
        adm_write_str("<!-- ");
        adm_write_str(ent_directory_0000000007->atb_heading);
        adm_write_str(" -->");
    }

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Directory");
    adm_template_tab_in(6, 16, 5);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_directory_0000000007->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Name='");
    adm_write_str(ent_directory_0000000007->atb_name);
    adm_write_str("'");

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory_0000000007,
        6, 24, 13);

    traverse_not_found_0000000010 = TRUE;

    rel_directory_includes_component_0000000009 = ent_directory_0000000007->rel_includes_component_head;

    while (rel_directory_includes_component_0000000009 != NULL) {

        ent_component_0000000009 = rel_directory_includes_component_0000000009->ent_component;

        traverse_not_found_0000000010 = FALSE;

        /* SelectionHead */

        adm_object_existent_directory(
            ent_directory_0000000007,
            6, 24, 13);

        if (rel_directory_includes_component_0000000009 == ent_directory_0000000007->rel_includes_component_head) {

            /* Template */

            adm_write_str(">");
        }

        rel_directory_includes_component_0000000009 = rel_directory_includes_component_0000000009->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000010) {

        /* Traverse - TraverseSelection */

        adm_object_existent_directory(
            ent_directory_0000000007,
            6, 32, 21);

        rel_directory_includes_directory_0000000011 = ent_directory_0000000007->rel_includes_directory_head;

        while (rel_directory_includes_directory_0000000011 != NULL) {

            ent_directory_0000000011 = rel_directory_includes_directory_0000000011->ent_directory;

            /* SelectionHead */

            adm_object_existent_directory(
                ent_directory_0000000011,
                6, 32, 21);

            if (rel_directory_includes_directory_0000000011 == ent_directory_0000000007->rel_includes_directory_head) {

                /* Template */

                adm_write_str(">");
            }

            rel_directory_includes_directory_0000000011 = rel_directory_includes_directory_0000000011->next;
        }
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory_0000000007,
        6, 39, 13);

    rel_directory_includes_component_0000000012 = ent_directory_0000000007->rel_includes_component_head;

    while (rel_directory_includes_component_0000000012 != NULL) {

        ent_component_0000000012 = rel_directory_includes_component_0000000012->ent_component;

        /* ProcessEntityInclude - Enter: 001_006_001_Process_Generate_Component */

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_str("<Component");
        adm_template_tab_in(7, 6, 5);
        adm_write_newline();
        adm_write_str("Id='");
        adm_write_str(ent_component_0000000012->atb_id);
        adm_write_str("'");
        adm_write_newline();
        adm_write_str("Guid='");
        adm_write_str(ent_component_0000000012->atb_guid);
        adm_write_str("'>");

        /* CaseSelection */

        if (
            (
                (
                    strcmp(ent_component_0000000012->atb_condition, "")
                )
            )) {

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<Condition>");
            adm_template_tab_in(7, 18, 17);
            adm_write_newline();
            adm_write_newline();
            adm_write_str(ent_component_0000000012->atb_condition);
            adm_template_tab_out(7, 18, 17);
            adm_write_newline();
            adm_write_newline();
            adm_write_str("</Condition>");
        }

        /* ProcessEntityInclude - Enter: 001_007_001_Process_Generate_File */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            8, 8, 13);

        rel_component_includes_file_0000000015 = ent_component_0000000012->rel_includes_file_head;

        if (rel_component_includes_file_0000000015 != NULL) {

            ent_file_0000000015 = rel_component_includes_file_0000000015->ent_file;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<File");
            adm_template_tab_in(8, 10, 13);
            adm_write_newline();
            adm_write_str("Id='");
            adm_write_str(ent_file_0000000015->atb_id);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Name='");
            adm_write_str(ent_file_0000000015->atb_name);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("DiskId='1'");
            adm_write_newline();
            adm_write_str("Source='");
            adm_write_str(ent_file_0000000015->atb_source);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("KeyPath='yes'");

            /* Traverse - TraverseSelection */

            adm_object_existent_file(
                ent_file_0000000015,
                8, 21, 21);

            traverse_not_found_0000000017 = TRUE;

            rel_file_includes_file_shortcut_0000000016 = ent_file_0000000015->rel_includes_file_shortcut_head;

            while (rel_file_includes_file_shortcut_0000000016 != NULL) {

                ent_file_shortcut_0000000016 = rel_file_includes_file_shortcut_0000000016->ent_file_shortcut;

                traverse_not_found_0000000017 = FALSE;

                /* SelectionHead */

                adm_object_existent_file(
                    ent_file_0000000015,
                    8, 21, 21);

                if (rel_file_includes_file_shortcut_0000000016 == ent_file_0000000015->rel_includes_file_shortcut_head) {

                    /* Template */

                    adm_write_str(">");
                }

                rel_file_includes_file_shortcut_0000000016 = rel_file_includes_file_shortcut_0000000016->next;
            }

            /* Traverse - Null Traverse Selection */

            if (traverse_not_found_0000000017) {

                /* Template */

                adm_write_str("/>");
            }

            /* ProcessEntityInclude - Enter: 001_009_001_Process_Generate_File_Shortcut */

            /* Traverse - TraverseSelection */

            adm_object_existent_file(
                ent_file_0000000015,
                9, 8, 13);

            rel_file_includes_file_shortcut_0000000019 = ent_file_0000000015->rel_includes_file_shortcut_head;

            while (rel_file_includes_file_shortcut_0000000019 != NULL) {

                ent_file_shortcut_0000000019 = rel_file_includes_file_shortcut_0000000019->ent_file_shortcut;

                rel_file_shortcut_specialisation_shortcut_0000000019 = ent_file_shortcut_0000000019->rel_specialisation_shortcut_head;

                ent_shortcut_0000000019 = rel_file_shortcut_specialisation_shortcut_0000000019->ent_shortcut;

                /* Template */

                adm_write_newline();
                adm_write_newline();
                adm_write_str("<Shortcut");
                adm_template_tab_in(9, 11, 13);
                adm_write_newline();
                adm_write_str("Id='");
                adm_write_str(ent_shortcut_0000000019->atb_id);
                adm_write_str("'");
                adm_write_newline();
                adm_write_str("Directory='");
                adm_write_str(ent_file_shortcut_0000000019->atb_directory);
                adm_write_str("'");
                adm_write_newline();
                adm_write_str("Name='");
                adm_write_str(ent_shortcut_0000000019->atb_name);
                adm_write_str("'");
                adm_write_newline();
                adm_write_str("WorkingDirectory='INSTALLDIR'");
                adm_write_newline();
                adm_write_str("Icon='");
                adm_write_str(ent_file_shortcut_0000000019->atb_icon);
                adm_write_str("'");
                adm_write_newline();
                adm_write_str("IconIndex='0'");
                adm_write_newline();
                adm_write_str("Advertise='yes'");
                adm_write_newline();
                adm_write_str("Description='");
                adm_write_str(ent_shortcut_0000000019->atb_description);
                adm_write_str("'/>");
                adm_template_tab_out(9, 11, 13);

                rel_file_includes_file_shortcut_0000000019 = rel_file_includes_file_shortcut_0000000019->next;
            }

            /* ProcessEntityInclude - Leave: 001_009_001_Process_Generate_File_Shortcut */

            /* Traverse - TraverseSelection */

            adm_object_existent_file(
                ent_file_0000000015,
                8, 33, 21);

            traverse_not_found_0000000021 = TRUE;

            rel_file_includes_file_shortcut_0000000020 = ent_file_0000000015->rel_includes_file_shortcut_head;

            while (rel_file_includes_file_shortcut_0000000020 != NULL) {

                ent_file_shortcut_0000000020 = rel_file_includes_file_shortcut_0000000020->ent_file_shortcut;

                traverse_not_found_0000000021 = FALSE;

                /* SelectionHead */

                adm_object_existent_file(
                    ent_file_0000000015,
                    8, 33, 21);

                if (rel_file_includes_file_shortcut_0000000020 == ent_file_0000000015->rel_includes_file_shortcut_head) {

                    /* Template */

                    adm_write_newline();
                    adm_template_tab_out(8, 36, 25);
                    adm_write_newline();
                    adm_write_str("</File>");
                }

                rel_file_includes_file_shortcut_0000000020 = rel_file_includes_file_shortcut_0000000020->next;
            }

            /* Traverse - Null Traverse Selection */

            if (traverse_not_found_0000000021) {

                /* Template */

                adm_template_tab_out(8, 41, 21);
            }
        }

        /* ProcessEntityInclude - Leave: 001_007_001_Process_Generate_File */

        /* ProcessEntityInclude - Enter: 001_010_001_Process_Generate_Uninstall_Shortcut */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            10, 8, 13);

        rel_component_includes_uninstall_shortcut_0000000023 = ent_component_0000000012->rel_includes_uninstall_shortcut_head;

        if (rel_component_includes_uninstall_shortcut_0000000023 != NULL) {

            ent_uninstall_shortcut_0000000023 = rel_component_includes_uninstall_shortcut_0000000023->ent_uninstall_shortcut;

            rel_uninstall_shortcut_specialisation_shortcut_0000000023 = ent_uninstall_shortcut_0000000023->rel_specialisation_shortcut_head;

            ent_shortcut_0000000023 = rel_uninstall_shortcut_specialisation_shortcut_0000000023->ent_shortcut;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<Shortcut");
            adm_template_tab_in(10, 11, 13);
            adm_write_newline();
            adm_write_str("Id='");
            adm_write_str(ent_shortcut_0000000023->atb_id);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Name='");
            adm_write_str(ent_shortcut_0000000023->atb_name);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Target='");
            adm_write_str(ent_uninstall_shortcut_0000000023->atb_target);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Arguments='");
            adm_write_str(ent_uninstall_shortcut_0000000023->atb_arguments);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Description='");
            adm_write_str(ent_shortcut_0000000023->atb_description);
            adm_write_str("'/>");
            adm_template_tab_out(10, 11, 13);
        }

        /* ProcessEntityInclude - Leave: 001_010_001_Process_Generate_Uninstall_Shortcut */

        /* ProcessEntityInclude - Enter: 001_011_001_Process_Generate_Create_Folder */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            11, 8, 13);

        rel_component_includes_create_folder_0000000025 = ent_component_0000000012->rel_includes_create_folder_head;

        if (rel_component_includes_create_folder_0000000025 != NULL) {

            ent_create_folder_0000000025 = rel_component_includes_create_folder_0000000025->ent_create_folder;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<CreateFolder/>");
        }

        /* ProcessEntityInclude - Leave: 001_011_001_Process_Generate_Create_Folder */

        /* ProcessEntityInclude - Enter: 001_012_001_Process_Generate_Remove_Folder */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            12, 8, 13);

        rel_component_includes_remove_folder_0000000027 = ent_component_0000000012->rel_includes_remove_folder_head;

        if (rel_component_includes_remove_folder_0000000027 != NULL) {

            ent_remove_folder_0000000027 = rel_component_includes_remove_folder_0000000027->ent_remove_folder;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<RemoveFolder");
            adm_template_tab_in(12, 10, 13);
            adm_write_newline();
            adm_write_str("Id='");
            adm_write_str(ent_remove_folder_0000000027->atb_id);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("On='");
            adm_write_str(ent_remove_folder_0000000027->atb_on);
            adm_write_str("'/>");
            adm_template_tab_out(12, 10, 13);
        }

        /* ProcessEntityInclude - Leave: 001_012_001_Process_Generate_Remove_Folder */

        /* ProcessEntityInclude - Enter: 001_013_001_Process_Generate_Environment */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            13, 8, 13);

        rel_component_includes_environment_0000000029 = ent_component_0000000012->rel_includes_environment_head;

        if (rel_component_includes_environment_0000000029 != NULL) {

            ent_environment_0000000029 = rel_component_includes_environment_0000000029->ent_environment;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<Environment");
            adm_template_tab_in(13, 10, 13);
            adm_write_newline();
            adm_write_str("Id='");
            adm_write_str(ent_environment_0000000029->atb_id);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Action='set'");
            adm_write_newline();
            adm_write_str("Part='all'");
            adm_write_newline();
            adm_write_str("Name='");
            adm_write_str(ent_environment_0000000029->atb_name);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Permanent='no'");
            adm_write_newline();
            adm_write_str("System='yes'");
            adm_write_newline();
            adm_write_str("Value='");
            adm_write_str(ent_environment_0000000029->atb_value);
            adm_write_str("'/>");
            adm_template_tab_out(13, 10, 13);
        }

        /* ProcessEntityInclude - Leave: 001_013_001_Process_Generate_Environment */

        /* ProcessEntityInclude - Enter: 001_014_001_Process_Generate_Registry_Key */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            14, 8, 13);

        rel_component_includes_registry_key_0000000031 = ent_component_0000000012->rel_includes_registry_key_head;

        if (rel_component_includes_registry_key_0000000031 != NULL) {

            ent_registry_key_0000000031 = rel_component_includes_registry_key_0000000031->ent_registry_key;

            /* Template */

            adm_write_newline();
            adm_write_newline();
            adm_write_str("<RegistryKey");
            adm_template_tab_in(14, 10, 13);
            adm_write_newline();
            adm_write_str("Root='");
            adm_write_str(ent_registry_key_0000000031->atb_root);
            adm_write_str("'");
            adm_write_newline();
            adm_write_str("Key='");
            adm_write_str(ent_registry_key_0000000031->atb_key);
            adm_write_str("'>");

            /* Traverse - TraverseSelection */

            adm_object_existent_registry_key(
                ent_registry_key_0000000031,
                14, 18, 21);

            rel_registry_key_includes_registry_value_0000000032 = ent_registry_key_0000000031->rel_includes_registry_value_head;

            ent_registry_value_0000000032 = rel_registry_key_includes_registry_value_0000000032->ent_registry_value;

            /* ProcessEntityInclude - Procedure: 001_015_001_Process_Generate_Registry_Value */

            adm_ent_pro_product_001_015_001_process_generate_registry_value(
                ent_registry_value_0000000032);

            /* Template */

            adm_write_newline();
            adm_template_tab_out(14, 22, 13);
            adm_write_newline();
            adm_write_str("</RegistryKey>");
        }

        /* ProcessEntityInclude - Leave: 001_014_001_Process_Generate_Registry_Key */

        /* Traverse - TraverseSelection */

        adm_object_existent_component(
            ent_component_0000000012,
            7, 36, 13);

        rel_component_includes_registry_value_0000000034 = ent_component_0000000012->rel_includes_registry_value_head;

        if (rel_component_includes_registry_value_0000000034 != NULL) {

            ent_registry_value_0000000034 = rel_component_includes_registry_value_0000000034->ent_registry_value;

            /* ProcessEntityInclude - Procedure: 001_015_001_Process_Generate_Registry_Value */

            adm_ent_pro_product_001_015_001_process_generate_registry_value(
                ent_registry_value_0000000034);
        }

        /* Template */

        adm_write_newline();
        adm_template_tab_out(7, 40, 5);
        adm_write_newline();
        adm_write_str("</Component>");

        /* ProcessEntityInclude - Leave: 001_006_001_Process_Generate_Component */

        rel_directory_includes_component_0000000012 = rel_directory_includes_component_0000000012->next;
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory_0000000007,
        6, 45, 13);

    rel_directory_includes_directory_0000000036 = ent_directory_0000000007->rel_includes_directory_head;

    while (rel_directory_includes_directory_0000000036 != NULL) {

        ent_directory_0000000036 = rel_directory_includes_directory_0000000036->ent_directory;

        /* ProcessEntityInclude - Recursive - Procedure: 001_005_001_Process_Generate_Directory */

        adm_ent_pro_product_001_005_001_process_generate_directory(
            ent_directory_0000000036);

        rel_directory_includes_directory_0000000036 = rel_directory_includes_directory_0000000036->next;
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory_0000000007,
        6, 51, 13);

    traverse_not_found_0000000038 = TRUE;

    rel_directory_includes_component_0000000037 = ent_directory_0000000007->rel_includes_component_head;

    while (rel_directory_includes_component_0000000037 != NULL) {

        ent_component_0000000037 = rel_directory_includes_component_0000000037->ent_component;

        traverse_not_found_0000000038 = FALSE;

        /* SelectionHead */

        adm_object_existent_directory(
            ent_directory_0000000007,
            6, 51, 13);

        if (rel_directory_includes_component_0000000037 == ent_directory_0000000007->rel_includes_component_head) {

            /* Template */

            adm_write_newline();
            adm_template_tab_out(6, 54, 17);
            adm_write_newline();
            adm_write_str("</Directory>");
        }

        rel_directory_includes_component_0000000037 = rel_directory_includes_component_0000000037->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000038) {

        /* Traverse - TraverseSelection */

        adm_object_existent_directory(
            ent_directory_0000000007,
            6, 61, 21);

        traverse_not_found_0000000040 = TRUE;

        rel_directory_includes_directory_0000000039 = ent_directory_0000000007->rel_includes_directory_head;

        while (rel_directory_includes_directory_0000000039 != NULL) {

            ent_directory_0000000039 = rel_directory_includes_directory_0000000039->ent_directory;

            traverse_not_found_0000000040 = FALSE;

            /* SelectionHead */

            adm_object_existent_directory(
                ent_directory_0000000039,
                6, 61, 21);

            if (rel_directory_includes_directory_0000000039 == ent_directory_0000000007->rel_includes_directory_head) {

                /* Template */

                adm_write_newline();
                adm_template_tab_out(6, 64, 25);
                adm_write_newline();
                adm_write_str("</Directory>");
            }

            rel_directory_includes_directory_0000000039 = rel_directory_includes_directory_0000000039->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000040) {

            /* Template */

            adm_write_str("/>");
            adm_template_tab_out(6, 69, 21);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_005_001_process_generate_directory");
    #endif
}

void adm_ent_pro_product_001_015_001_process_generate_registry_value(
    adm_ent_registry_value_typ * ent_registry_value_0000000032)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_015_001_process_generate_registry_value");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<RegistryValue");
    adm_template_tab_in(15, 6, 5);

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_registry_value_0000000032->atb_root, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Root='");
        adm_write_str(ent_registry_value_0000000032->atb_root);
        adm_write_str("'");
    }

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_registry_value_0000000032->atb_key, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Key='");
        adm_write_str(ent_registry_value_0000000032->atb_key);
        adm_write_str("'");
    }

    /* Template */

    adm_write_newline();
    adm_write_str("Value='");
    adm_write_str(ent_registry_value_0000000032->atb_value);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Type='string'");
    adm_write_newline();
    adm_write_str("KeyPath='yes'/>");
    adm_template_tab_out(15, 26, 5);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_015_001_process_generate_registry_value");
    #endif
}

void adm_ent_pro_product_001_016_001_process_generate_feature(
    adm_ent_feature_typ * ent_feature_0000000041)
{
    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000043;
    adm_ent_component_typ * ent_component_0000000045;

    /* Relationship Relations */
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature_0000000043;
    adm_rel_feature_includes_component_typ * rel_feature_includes_component_0000000045;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000044;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_016_001_process_generate_feature");
    #endif

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature_0000000041->atb_heading, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_newline();
        adm_write_str("<!-- ");
        adm_write_str(ent_feature_0000000041->atb_heading);
        adm_write_str(" -->");
    }

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Feature");
    adm_template_tab_in(16, 16, 5);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_feature_0000000041->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Title='");
    adm_write_str(ent_feature_0000000041->atb_title);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Level='1'");

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature_0000000041->atb_description, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Description='");
        adm_write_str(ent_feature_0000000041->atb_description);
        adm_write_str("'");
    }

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature_0000000041->atb_display, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Display='");
        adm_write_str(ent_feature_0000000041->atb_display);
        adm_write_str("'");
    }

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature_0000000041->atb_configurable_directory, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("ConfigurableDirectory='");
        adm_write_str(ent_feature_0000000041->atb_configurable_directory);
        adm_write_str("'");
    }

    /* Template */

    adm_write_str(">");

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature_0000000041,
        16, 51, 13);

    traverse_not_found_0000000044 = TRUE;

    rel_feature_includes_feature_0000000043 = ent_feature_0000000041->rel_includes_feature_head;

    while (rel_feature_includes_feature_0000000043 != NULL) {

        ent_feature_0000000043 = rel_feature_includes_feature_0000000043->ent_feature;

        traverse_not_found_0000000044 = FALSE;

        /* ProcessEntityInclude - Recursive - Procedure: 001_016_001_Process_Generate_Feature */

        adm_ent_pro_product_001_016_001_process_generate_feature(
            ent_feature_0000000043);

        rel_feature_includes_feature_0000000043 = rel_feature_includes_feature_0000000043->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000044) {

        /* Traverse - TraverseSelection */

        adm_object_existent_feature(
            ent_feature_0000000041,
            16, 58, 21);

        rel_feature_includes_component_0000000045 = ent_feature_0000000041->rel_includes_component_head;

        while (rel_feature_includes_component_0000000045 != NULL) {

            ent_component_0000000045 = rel_feature_includes_component_0000000045->ent_component;

            /* SelectionHead */

            adm_object_existent_feature(
                ent_feature_0000000041,
                16, 58, 21);

            if (rel_feature_includes_component_0000000045 == ent_feature_0000000041->rel_includes_component_head) {

                /* Template */

                adm_write_newline();
            }

            /* Template */

            adm_write_newline();
            adm_write_str("<ComponentRef Id='");
            adm_write_str(ent_component_0000000045->atb_id);
            adm_write_str("'/>");

            rel_feature_includes_component_0000000045 = rel_feature_includes_component_0000000045->next;
        }
    }

    /* Template */

    adm_write_newline();
    adm_template_tab_out(16, 65, 5);
    adm_write_newline();
    adm_write_str("</Feature>");

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_product_001_016_001_process_generate_feature");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */