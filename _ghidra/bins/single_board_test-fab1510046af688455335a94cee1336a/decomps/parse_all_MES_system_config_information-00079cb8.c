
/* WARNING: Removing unreachable block (ram,0x0007beb2) */
/* WARNING: Unknown calling convention */

_Bool parse_all_MES_system_config_information(void)

{
  json_t *pjVar1;
  json_t *pjVar2;
  char *pcVar3;
  int iVar4;
  mes_system_configs *__dest;
  json_t *pjVar5;
  mes_system_hw_info *pmVar6;
  json_t *pjVar7;
  mes_system_pattern *pmVar8;
  mes_system_asic_reg *pmVar9;
  mes_system_test_method *pmVar10;
  json_t *pjVar11;
  mes_system_test_loop *pmVar12;
  mes_system_test_config *__dest_00;
  mes_system_data *__dest_01;
  json_t *pjVar13;
  size_t sVar14;
  Mes_System_Result *pMVar15;
  json_int_t jVar16;
  char time_stamp [48];
  char tmp1 [2048];
  json_error_t error;
  uint8_t i;
  size_t test_loop_id_array_size;
  json_t *test_loop_id_array;
  json_t *test_loop_array;
  json_t *data_array;
  json_t *test_config_array;
  json_t *test_method_array;
  json_t *asic_reg_array;
  json_t *pattern_array;
  json_t *power_version_array;
  json_t *hw_info_array;
  json_t *configs_array;
  Mes_System_Data *Mes_System_Data_temp;
  Mes_System_Test_Config *Mes_System_Test_Config_temp;
  Mes_System_Test_Loop *Mes_System_Test_Loop_temp;
  Mes_System_Test_Method *Mes_System_Test_Method_temp;
  Mes_System_Asic_Reg *Mes_System_Asic_Reg_temp;
  Mes_System_Pattern *Mes_System_Pattern_temp;
  Mes_System_Hw_Info *Mes_System_Hw_Info_temp;
  Mes_System_Configs *Mes_System_Configs_temp;
  json_t *test_loop_id;
  json_t *test_loop;
  json_t *data;
  json_t *test_method;
  json_t *test_config;
  json_t *pattern;
  json_t *rule;
  json_t *power_version;
  json_t *asic_reg;
  json_t *hw_info;
  json_t *miner_type;
  json_t *configs;
  json_t *msg;
  json_t *code;
  json_t *version;
  json_t *result;
  json_t *Config_File;
  _Bool ret;
  size_t test_loop_id_array_index;
  size_t test_loop_array_index;
  size_t data_array_index;
  size_t test_config_array_index;
  size_t test_method_array_index;
  size_t asic_reg_array_index;
  size_t pattern_array_index;
  size_t power_version_array_index;
  size_t hw_info_array_index;
  size_t configs_array_index;
  Mes_System_Data *Mes_System_Data_ptr;
  Mes_System_Test_Config *Mes_System_Test_Config_ptr;
  Mes_System_Test_Loop *Mes_System_Test_Loop_ptr;
  Mes_System_Test_Method *Mes_System_Test_Method_ptr;
  Mes_System_Asic_Reg *Mes_System_Asic_Reg_ptr;
  Mes_System_Pattern *Mes_System_Pattern_ptr;
  Mes_System_Hw_Info *Mes_System_Hw_Info_ptr;
  Mes_System_Configs *Mes_System_Configs_ptr;
  
  ret = true;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: begin\n","parse_all_MES_system_config_information");
  builtin_strncpy(tmp1,"begi",4);
  tmp1[4] = 'n';
  tmp1[5] = '\0';
  log_to_file(tmp1,time_stamp);
  MES_system_config_File =
       json_loadb(MES_system_Config_information,mes_system_config_file_length - 1,0,&error);
  if ((MES_system_config_File == (json_t *)0x0) || (MES_system_config_File->type != JSON_OBJECT)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: The received MES system all config information is not in JSON format\n",
           "parse_all_MES_system_config_information");
    memcpy(tmp1,"The received MES system all config information is not in JSON format",0x45);
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    pjVar1 = json_object_get(MES_system_config_File,"result");
    if ((pjVar1 == (json_t *)0x0) || (pjVar1->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t find result in MES system paticular config information\n",
             "parse_all_MES_system_config_information");
      builtin_strncpy(tmp1,"Can\'t find result in MES system paticular config information",0x3c);
      tmp1[0x3c] = '\0';
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pjVar2 = json_object_get(pjVar1,"version");
      if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_STRING)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t find version in result\n","parse_all_MES_system_config_information");
        builtin_strncpy(tmp1,"Can\'t find version in result",0x1c);
        tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        pMVar15 = &Mes_System_Config_File_Information->result;
        pcVar3 = json_string_value(pjVar2);
        strcpy(pMVar15->version,pcVar3);
        pjVar2 = json_object_get(pjVar1,"code");
        if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_STRING)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Can\'t find code in result\n","parse_all_MES_system_config_information");
          builtin_strncpy(tmp1,"Can\'t find code in result",0x1a);
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          pMVar15 = &Mes_System_Config_File_Information->result;
          pcVar3 = json_string_value(pjVar2);
          strcpy(pMVar15->code,pcVar3);
          iVar4 = strcmp((Mes_System_Config_File_Information->result).code,"000000");
          if (iVar4 == 0) {
            pjVar2 = json_object_get(pjVar1,"msg");
            if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t find msg in result\n","parse_all_MES_system_config_information");
              builtin_strncpy(tmp1,"Can\'t find msg in result",0x18);
              tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              ret = false;
            }
            else {
              pMVar15 = &Mes_System_Config_File_Information->result;
              pcVar3 = json_string_value(pjVar2);
              strcpy(pMVar15->msg,pcVar3);
              iVar4 = strcmp((Mes_System_Config_File_Information->result).msg,"ok");
              if (iVar4 == 0) {
                pjVar1 = json_object_get(pjVar1,"configs");
                if ((pjVar1 == (json_t *)0x0) || (pjVar1->type != JSON_ARRAY)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t find configs in result\n",
                         "parse_all_MES_system_config_information");
                  builtin_strncpy(tmp1,"Can\'t find configs in result",0x1c);
                  tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                }
                else {
                  gConfigs_array_size = json_array_size(pjVar1);
                  for (configs_array_index = 0; configs_array_index < gConfigs_array_size;
                      configs_array_index = configs_array_index + 1) {
                    pjVar2 = json_array_get(pjVar1,configs_array_index);
                    if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t read out configs[%d] in result, error\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t read out configs[%d] in result, error",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    __dest = (mes_system_configs *)malloc(0x34);
                    if (__dest == (mes_system_configs *)0x0) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: malloc for configs[%d] in result fail\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"malloc for configs[%d] in result fail",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    __dest->next = (mes_system_configs *)0x0;
                    if ((Mes_System_Config_File_Information->result).configs ==
                        (mes_system_configs *)0x0) {
                      (Mes_System_Config_File_Information->result).configs = __dest;
                      ((Mes_System_Config_File_Information->result).configs)->next =
                           (mes_system_configs *)0x0;
                    }
                    else {
                      for (Mes_System_Configs_ptr =
                                (Mes_System_Config_File_Information->result).configs;
                          Mes_System_Configs_ptr->next != (mes_system_configs *)0x0;
                          Mes_System_Configs_ptr = Mes_System_Configs_ptr->next) {
                      }
                      Mes_System_Configs_ptr->next = __dest;
                    }
                    pjVar5 = json_object_get(pjVar2,"miner_type");
                    if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_STRING)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find miner_type in configs[%d] in result\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find miner_type in configs[%d] in result",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    pcVar3 = json_string_value(pjVar5);
                    strcpy((char *)__dest,pcVar3);
                    pjVar5 = json_object_get(pjVar2,"hw_info");
                    if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find hw_info in configs[%d] in result\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find hw_info in configs[%d] in result",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gHw_info_array_size = json_array_size(pjVar5);
                    for (hw_info_array_index = 0; hw_info_array_index < gHw_info_array_size;
                        hw_info_array_index = hw_info_array_index + 1) {
                      pjVar7 = json_array_get(pjVar5,hw_info_array_index);
                      if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t read out hw_info_array[%d] in configs[%d], error\n",
                               "parse_all_MES_system_config_information",hw_info_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,
                                 "Can\'t read out hw_info_array[%d] in configs[%d], error",
                                 hw_info_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar6 = (mes_system_hw_info *)malloc(100);
                      if (pmVar6 == (mes_system_hw_info *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d] in result fail\n",
                               "parse_all_MES_system_config_information",configs_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d] in result fail",
                                 configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar6->next = (mes_system_hw_info *)0x0;
                      if (__dest->hw_info == (mes_system_hw_info *)0x0) {
                        __dest->hw_info = pmVar6;
                        __dest->hw_info->next = (mes_system_hw_info *)0x0;
                      }
                      else {
                        for (Mes_System_Hw_Info_ptr = __dest->hw_info;
                            Mes_System_Hw_Info_ptr->next != (mes_system_hw_info *)0x0;
                            Mes_System_Hw_Info_ptr = Mes_System_Hw_Info_ptr->next) {
                        }
                        Mes_System_Hw_Info_ptr->next = pmVar6;
                      }
                      pjVar13 = json_object_get(pjVar7,"id");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar6->id = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar7,"board_name");
                      pcVar3 = json_string_value(pjVar13);
                      strcpy(pmVar6->board_name,pcVar3);
                      pjVar13 = json_object_get(pjVar7,"asic_type");
                      pcVar3 = json_string_value(pjVar13);
                      strcpy(pmVar6->asic_type,pcVar3);
                      pjVar13 = json_object_get(pjVar7,"asic_num");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar6->asic_num = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar7,"voltage_domain");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar6->voltage_domain = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar7,"asic_num_per_voltage_domain");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar6->asic_num_per_voltage_domain = (uint32_t)jVar16;
                      pjVar7 = json_object_get(pjVar7,"power_version");
                      if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find power_version in configs[%d]->hw_info[%d]\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               hw_info_array_index);
                        snprintf(tmp1,0x800,"Can\'t find power_version in configs[%d]->hw_info[%d]",
                                 configs_array_index,hw_info_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      gPower_version_array_size = json_array_size(pjVar7);
                      for (power_version_array_index = 0;
                          power_version_array_index < gPower_version_array_size;
                          power_version_array_index = power_version_array_index + 1) {
                        pjVar13 = json_array_get(pjVar7,power_version_array_index);
                        if ((pjVar13 == (json_t *)0x0) || (pjVar13->type != JSON_INTEGER)) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s: Can\'t find power_version_array[%d] in configs[%d]->hw_info[%d], error\n"
                                 ,"parse_all_MES_system_config_information",
                                 power_version_array_index,configs_array_index,hw_info_array_index);
                          snprintf(tmp1,0x800,
                                   "Can\'t find power_version_array[%d] in configs[%d]->hw_info[%d], error"
                                   ,power_version_array_index,configs_array_index,
                                   hw_info_array_index);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                          goto LAB_0007beaa;
                        }
                        jVar16 = json_integer_value(pjVar13);
                        pmVar6->power_version[power_version_array_index] = (uint32_t)jVar16;
                        APW_power_version[power_version_array_index] =
                             (uint8_t)pmVar6->power_version[power_version_array_index];
                      }
                    }
                    pjVar5 = json_object_get(pjVar2,"rule");
                    if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_OBJECT)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find rule configs[%d] in result\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find rule configs[%d] in result",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    pjVar7 = json_object_get(pjVar5,"pattern");
                    if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find pattern in configs[%d]->rule\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find pattern in configs[%d]->rule",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gPattern_array_size = json_array_size(pjVar7);
                    for (pattern_array_index = 0; pattern_array_index < gPattern_array_size;
                        pattern_array_index = pattern_array_index + 1) {
                      pjVar13 = json_array_get(pjVar7,pattern_array_index);
                      if ((pjVar13 == (json_t *)0x0) || (pjVar13->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find pattern[%d] in configs[%d]->rule, error\n",
                               "parse_all_MES_system_config_information",pattern_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,"Can\'t find pattern[%d] in configs[%d]->rule, error",
                                 pattern_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar8 = (mes_system_pattern *)malloc(0x20);
                      if (pmVar8 == (mes_system_pattern *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d]->rule->pattern[%d] fail\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               pattern_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d]->rule->pattern[%d] fail",
                                 configs_array_index,pattern_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar8->next = (mes_system_pattern *)0x0;
                      if ((__dest->rule).pattern == (mes_system_pattern *)0x0) {
                        (__dest->rule).pattern = pmVar8;
                        ((__dest->rule).pattern)->next = (mes_system_pattern *)0x0;
                      }
                      else {
                        for (Mes_System_Pattern_ptr = (__dest->rule).pattern;
                            Mes_System_Pattern_ptr->next != (mes_system_pattern *)0x0;
                            Mes_System_Pattern_ptr = Mes_System_Pattern_ptr->next) {
                        }
                        Mes_System_Pattern_ptr->next = pmVar8;
                      }
                      pjVar11 = json_object_get(pjVar13,"id");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->id = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"pattern_number");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->pattern_number = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"invalid_core_num");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->invalid_core_num = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"most_hw_num");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->most_hw_num = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"least_nonce_per_core");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->least_nonce_per_core = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"nonce_rate");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar8->nonce_rate = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar13,"midstate_number");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar8->midstate_number = (uint32_t)jVar16;
                    }
                    pjVar7 = json_object_get(pjVar5,"asic_reg");
                    if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find asic_reg in configs[%d]->rule\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find asic_reg in configs[%d]->rule",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gAsic_reg_array_size = json_array_size(pjVar7);
                    for (asic_reg_array_index = 0; asic_reg_array_index < gAsic_reg_array_size;
                        asic_reg_array_index = asic_reg_array_index + 1) {
                      pjVar13 = json_array_get(pjVar7,asic_reg_array_index);
                      if ((pjVar13 == (json_t *)0x0) || (pjVar13->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find asic_reg[%d] in configs[%d]->rule, error\n",
                               "parse_all_MES_system_config_information",asic_reg_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,"Can\'t find asic_reg[%d] in configs[%d]->rule, error",
                                 asic_reg_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar9 = (mes_system_asic_reg *)malloc(0x28);
                      if (pmVar9 == (mes_system_asic_reg *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d]->rule->asic_reg[%d] fail\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               asic_reg_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d]->rule->asic_reg[%d] fail",
                                 configs_array_index,asic_reg_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar9->next = (mes_system_asic_reg *)0x0;
                      if ((__dest->rule).asic_reg == (mes_system_asic_reg *)0x0) {
                        (__dest->rule).asic_reg = pmVar9;
                        ((__dest->rule).asic_reg)->next = (mes_system_asic_reg *)0x0;
                      }
                      else {
                        for (Mes_System_Asic_Reg_ptr = (__dest->rule).asic_reg;
                            Mes_System_Asic_Reg_ptr->next != (mes_system_asic_reg *)0x0;
                            Mes_System_Asic_Reg_ptr = Mes_System_Asic_Reg_ptr->next) {
                        }
                        Mes_System_Asic_Reg_ptr->next = pmVar9;
                      }
                      pjVar11 = json_object_get(pjVar13,"id");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->id = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"ccdly_sel");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->ccdly_sel = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"pwth_sel");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->pwth_sel = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"swpf_mode");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->swpf_mode = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"pulse_mode");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->pulse_mode = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"clk_sel");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->clk_sel = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"ro_relay_en");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->ro_relay_en = (uint32_t)jVar16;
                      pjVar11 = json_object_get(pjVar13,"co_relay_en");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar9->co_relay_en = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar13,"diode_vdd_mux_sel");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar9->diode_vdd_mux_sel = (uint32_t)jVar16;
                    }
                    pjVar7 = json_object_get(pjVar5,"test_method");
                    if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find test_method in configs[%d]->rule\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find test_method in configs[%d]->rule",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gTest_method_array_size = json_array_size(pjVar7);
                    for (test_method_array_index = 0;
                        test_method_array_index < gTest_method_array_size;
                        test_method_array_index = test_method_array_index + 1) {
                      pjVar13 = json_array_get(pjVar7,test_method_array_index);
                      if ((pjVar13 == (json_t *)0x0) || (pjVar13->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find test_method[%d] in configs[%d]->rule, error\n",
                               "parse_all_MES_system_config_information",test_method_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,
                                 "Can\'t find test_method[%d] in configs[%d]->rule, error",
                                 test_method_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar10 = (mes_system_test_method *)malloc(0x20);
                      if (pmVar10 == (mes_system_test_method *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d]->rule->test_method[%d] fail\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               test_method_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d]->rule->test_method[%d] fail",
                                 configs_array_index,test_method_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar10->next = (mes_system_test_method *)0x0;
                      if ((__dest->rule).test_method == (mes_system_test_method *)0x0) {
                        (__dest->rule).test_method = pmVar10;
                        ((__dest->rule).test_method)->next = (mes_system_test_method *)0x0;
                      }
                      else {
                        for (Mes_System_Test_Method_ptr = (__dest->rule).test_method;
                            Mes_System_Test_Method_ptr->next != (mes_system_test_method *)0x0;
                            Mes_System_Test_Method_ptr = Mes_System_Test_Method_ptr->next) {
                        }
                        Mes_System_Test_Method_ptr->next = pmVar10;
                      }
                      pjVar11 = json_object_get(pjVar13,"id");
                      jVar16 = json_integer_value(pjVar11);
                      pmVar10->id = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar13,"method");
                      pcVar3 = json_string_value(pjVar13);
                      strcpy(pmVar10->method,pcVar3);
                    }
                    pjVar5 = json_object_get(pjVar5,"test_loop");
                    if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find test_loop in configs[%d]->rule\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find test_loop in configs[%d]->rule",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gTest_loop_array_size = json_array_size(pjVar5);
                    for (test_loop_array_index = 0; test_loop_array_index < gTest_loop_array_size;
                        test_loop_array_index = test_loop_array_index + 1) {
                      pjVar7 = json_array_get(pjVar5,test_loop_array_index);
                      if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find test_loop[%d] in configs[%d]->rule, error\n",
                               "parse_all_MES_system_config_information",test_loop_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,"Can\'t find test_loop[%d] in configs[%d]->rule, error",
                                 test_loop_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar12 = (mes_system_test_loop *)malloc(0x10);
                      if (pmVar12 == (mes_system_test_loop *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d]->rule->test_loop[%d] fail\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               test_method_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d]->rule->test_loop[%d] fail",
                                 configs_array_index,test_method_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      pmVar12->next = (mes_system_test_loop *)0x0;
                      if ((__dest->rule).test_loop == (mes_system_test_loop *)0x0) {
                        (__dest->rule).test_loop = pmVar12;
                        ((__dest->rule).test_loop)->next = (mes_system_test_loop *)0x0;
                      }
                      else {
                        for (Mes_System_Test_Loop_ptr = (__dest->rule).test_loop;
                            Mes_System_Test_Loop_ptr->next != (mes_system_test_loop *)0x0;
                            Mes_System_Test_Loop_ptr = Mes_System_Test_Loop_ptr->next) {
                        }
                        Mes_System_Test_Loop_ptr->next = pmVar12;
                      }
                      pjVar13 = json_object_get(pjVar7,"id");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar12->id = (uint32_t)jVar16;
                      pjVar13 = json_object_get(pjVar7,"frequency");
                      jVar16 = json_integer_value(pjVar13);
                      pmVar12->frequency = (uint32_t)jVar16;
                      pjVar7 = json_object_get(pjVar7,"voltage");
                      jVar16 = json_integer_value(pjVar7);
                      pmVar12->voltage = (uint32_t)jVar16;
                    }
                    pjVar2 = json_object_get(pjVar2,"test_config");
                    if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_ARRAY)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: Can\'t find test_config in configs[%d] in result\n",
                             "parse_all_MES_system_config_information",configs_array_index);
                      snprintf(tmp1,0x800,"Can\'t find test_config in configs[%d] in result",
                               configs_array_index);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                      break;
                    }
                    gTest_config_array_size = json_array_size(pjVar2);
                    for (test_config_array_index = 0;
                        test_config_array_index < gTest_config_array_size;
                        test_config_array_index = test_config_array_index + 1) {
                      pjVar5 = json_array_get(pjVar2,test_config_array_index);
                      if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_OBJECT)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find test_config[%d] in configs[%d], error\n",
                               "parse_all_MES_system_config_information",test_config_array_index,
                               configs_array_index);
                        snprintf(tmp1,0x800,"Can\'t find test_config[%d] in configs[%d], error",
                                 test_config_array_index,configs_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      __dest_00 = (mes_system_test_config *)malloc(0x84);
                      if (__dest_00 == (mes_system_test_config *)0x0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: malloc for configs[%d]->test_config[%d] fail\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               test_config_array_index);
                        snprintf(tmp1,0x800,"malloc for configs[%d]->test_config[%d] fail",
                                 configs_array_index,test_config_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      __dest_00->next = (mes_system_test_config *)0x0;
                      if (__dest->test_config == (mes_system_test_config *)0x0) {
                        __dest->test_config = __dest_00;
                        __dest->test_config->next = (mes_system_test_config *)0x0;
                      }
                      else {
                        for (Mes_System_Test_Config_ptr = __dest->test_config;
                            Mes_System_Test_Config_ptr->next != (mes_system_test_config *)0x0;
                            Mes_System_Test_Config_ptr = Mes_System_Test_Config_ptr->next) {
                        }
                        Mes_System_Test_Config_ptr->next = __dest_00;
                      }
                      pjVar7 = json_object_get(pjVar5,"hardware_version");
                      pcVar3 = json_string_value(pjVar7);
                      strcpy((char *)__dest_00,pcVar3);
                      pjVar7 = json_object_get(pjVar5,"bom_version");
                      pcVar3 = json_string_value(pjVar7);
                      strcpy(__dest_00->bom_version,pcVar3);
                      pjVar7 = json_object_get(pjVar5,"chip_technology");
                      pcVar3 = json_string_value(pjVar7);
                      strcpy(__dest_00->chip_technology,pcVar3);
                      pjVar7 = json_object_get(pjVar5,"ft_vesrion");
                      pcVar3 = json_string_value(pjVar7);
                      strcpy(__dest_00->ft_version,pcVar3);
                      pjVar7 = json_object_get(pjVar5,"bin");
                      jVar16 = json_integer_value(pjVar7);
                      __dest_00->bin = (uint32_t)jVar16;
                      pjVar7 = json_object_get(pjVar5,"leakageCurrent");
                      jVar16 = json_integer_value(pjVar7);
                      __dest_00->leakage_current = (uint32_t)jVar16;
                      pjVar5 = json_object_get(pjVar5,"data");
                      if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_ARRAY)) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: Can\'t find data in configs[%d]->test_config[%d]\n",
                               "parse_all_MES_system_config_information",configs_array_index,
                               test_config_array_index);
                        snprintf(tmp1,0x800,"Can\'t find data in configs[%d]->test_config[%d]",
                                 configs_array_index,test_config_array_index);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                        goto LAB_0007beaa;
                      }
                      gData_array_size = json_array_size(pjVar5);
                      for (data_array_index = 0; data_array_index < gData_array_size;
                          data_array_index = data_array_index + 1) {
                        pjVar7 = json_array_get(pjVar5,data_array_index);
                        if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_OBJECT)) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s: Can\'t find data[%d] in configs[%d]->test_config[%d], error\n"
                                 ,"parse_all_MES_system_config_information",data_array_index,
                                 configs_array_index,test_config_array_index);
                          snprintf(tmp1,0x800,
                                   "Can\'t find data[%d] in configs[%d]->test_config[%d], error",
                                   data_array_index,configs_array_index,test_config_array_index);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                          goto LAB_0007beaa;
                        }
                        __dest_01 = (mes_system_data *)malloc(0x60);
                        if (__dest_01 == (mes_system_data *)0x0) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s: malloc for configs[%d]->test_loop[%d]->data[%d] fail\n",
                                 "parse_all_MES_system_config_information",configs_array_index,
                                 test_config_array_index,data_array_index);
                          snprintf(tmp1,0x800,"malloc for configs[%d]->test_loop[%d]->data[%d] fail"
                                   ,configs_array_index,test_config_array_index,data_array_index);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                          goto LAB_0007beaa;
                        }
                        __dest_01->next = (mes_system_data *)0x0;
                        if (__dest_00->data == (mes_system_data *)0x0) {
                          __dest_00->data = __dest_01;
                          __dest_00->data->next = (mes_system_data *)0x0;
                        }
                        else {
                          for (Mes_System_Data_ptr = __dest_00->data;
                              Mes_System_Data_ptr->next != (mes_system_data *)0x0;
                              Mes_System_Data_ptr = Mes_System_Data_ptr->next) {
                          }
                          Mes_System_Data_ptr->next = __dest_01;
                        }
                        pjVar13 = json_object_get(pjVar7,"version");
                        pcVar3 = json_string_value(pjVar13);
                        strcpy((char *)__dest_01,pcVar3);
                        pjVar13 = json_object_get(pjVar7,"pattern_id");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->pattern_id = (uint32_t)jVar16;
                        pjVar13 = json_object_get(pjVar7,"asic_reg_id");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->asic_reg_id = (uint32_t)jVar16;
                        pjVar13 = json_object_get(pjVar7,"test_method_id");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->test_method_id = (uint32_t)jVar16;
                        pjVar13 = json_object_get(pjVar7,"voltage_accuracy");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->voltage_accuracy = (uint32_t)jVar16;
                        pjVar13 = json_object_get(pjVar7,"fan_speed");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->fan_speed = (uint32_t)jVar16;
                        pjVar13 = json_object_get(pjVar7,"pre_open_core_voltage");
                        jVar16 = json_integer_value(pjVar13);
                        __dest_01->pre_open_core_voltage = (uint32_t)jVar16;
                        pjVar7 = json_object_get(pjVar7,"test_loop_id");
                        if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s: Can\'t find test_loop_id in configs[%d]->test_config[%d]->data[%d]\n"
                                 ,"parse_all_MES_system_config_information",configs_array_index,
                                 test_config_array_index,data_array_index);
                          snprintf(tmp1,0x800,
                                   "Can\'t find test_loop_id in configs[%d]->test_config[%d]->data[%d]"
                                   ,configs_array_index,test_config_array_index,data_array_index);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                          goto LAB_0007beaa;
                        }
                        sVar14 = json_array_size(pjVar7);
                        if (10 < sVar14) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s: Test_loop_id_array_size is %d, bigger than %d\n",
                                 "parse_all_MES_system_config_information",sVar14,10);
                          snprintf(tmp1,0x800,"Test_loop_id_array_size is %d, bigger than %d",sVar14
                                   ,10);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                          goto LAB_0007beaa;
                        }
                        __dest_01->test_loop_id_number = sVar14;
                        for (test_loop_id_array_index = 0; test_loop_id_array_index < sVar14;
                            test_loop_id_array_index = test_loop_id_array_index + 1) {
                          pjVar13 = json_array_get(pjVar7,test_loop_id_array_index);
                          if ((pjVar13 == (json_t *)0x0) || (pjVar13->type != JSON_INTEGER)) {
                            print_time_stamp(time_stamp,0x30);
                            printf("%s ",time_stamp);
                            printf("%s: Can\'t find test_loop_id[%d] in configs[%d]->test_config[%d]->data[%d], error\n"
                                   ,"parse_all_MES_system_config_information",
                                   test_loop_id_array_index,configs_array_index,
                                   test_config_array_index,data_array_index);
                            snprintf(tmp1,0x800,
                                     "Can\'t find test_loop_id[%d] in configs[%d]->test_config[%d]->data[%d], error"
                                     ,test_loop_id_array_index,configs_array_index,
                                     test_config_array_index,data_array_index);
                            log_to_file(tmp1,time_stamp);
                            ret = false;
                            goto LAB_0007beaa;
                          }
                          jVar16 = json_integer_value(pjVar13);
                          __dest_01->test_loop_id[test_loop_id_array_index] = (uint32_t)jVar16;
                        }
                      }
                    }
                  }
                }
              }
              else {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Get all config information fail. msg: %s\n",
                       "parse_all_MES_system_config_information",
                       (Mes_System_Config_File_Information->result).msg);
                snprintf(tmp1,0x800,"Get all config information fail. msg: %s",
                         (Mes_System_Config_File_Information->result).msg);
                log_to_file(tmp1,time_stamp);
                ret = false;
              }
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Get all config information fail. code: %s\n",
                   "parse_all_MES_system_config_information",
                   (Mes_System_Config_File_Information->result).code);
            snprintf(tmp1,0x800,"Get all config information fail. code: %s",
                     (Mes_System_Config_File_Information->result).code);
            log_to_file(tmp1,time_stamp);
            ret = false;
          }
        }
      }
    }
  }
LAB_0007beaa:
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: done\n","parse_all_MES_system_config_information");
  builtin_strncpy(tmp1,"done",4);
  tmp1._4_4_ = tmp1._4_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  return ret;
}

