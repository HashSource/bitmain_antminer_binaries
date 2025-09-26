
_Bool prepare_MES_system_submit_information(uint32_t test_loop_index,_Bool sweep_mode)

{
  undefined4 uVar1;
  byte bVar2;
  json_t *json;
  json_t *pjVar3;
  json_t *pjVar4;
  char *pcVar5;
  size_t sVar6;
  json_t *pjVar7;
  int iVar8;
  size_t sVar9;
  size_t sVar10;
  json_t *pjVar11;
  size_t sVar12;
  json_t *pjVar13;
  json_t *pjVar14;
  json_t *pjVar15;
  float fVar16;
  double dVar17;
  json_int_t jVar18;
  _Bool sweep_mode_local;
  uint32_t test_loop_index_local;
  char time_stamp_83 [48];
  char time_stamp [48];
  char tmp1 [2048];
  test_ctx level_info;
  char data [10];
  json_error_t error;
  json_t *pattern_asic_nonces_array [256];
  json_t *sensors_datas_values_array [8];
  json_t *sensors_datas_array [8];
  json_t *commons_array [8];
  json_t *asic_nonces_array [8];
  json_t *sensors_array [8];
  json_t *datas_array [8];
  uint32_t bin_num;
  size_t sensors_chip_datas_array_index;
  size_t sensors_pic_datas_array_index;
  size_t sensors_chip_datas_array_size;
  size_t sensors_pic_datas_array_size;
  size_t pattern_asic_nonces_array_size;
  size_t sensors_datas_values_array_size;
  size_t sensors_datas_array_size;
  size_t commons_array_size;
  size_t asic_nonces_array_size;
  size_t sensors_array_size;
  size_t datas_array_size;
  json_t *commons_msg;
  json_t *commons_code;
  json_t *commons_name;
  json_t *pattern_asic_nonces;
  json_t *pattern_asic_number;
  json_t *pattern_msg;
  json_t *pattern_code;
  json_t *pattern_nonce_rate;
  json_t *sensors_datas_values;
  json_t *sensors_datas_msg;
  json_t *sensors_datas_code;
  json_t *sensors_datas_type;
  json_t *sensors_datas_id;
  json_t *sensors_datas;
  json_t *sensors_name;
  json_t *commons;
  json_t *pattern;
  json_t *sensors;
  json_t *result;
  json_t *rule_result;
  json_t *rule_level;
  json_t *rule_version;
  json_t *bin;
  json_t *ft_version;
  json_t *chip_technology;
  json_t *bom_version;
  json_t *hardware_version;
  json_t *order_id;
  json_t *sn1;
  json_t *board_name;
  json_t *miner_type;
  json_t *datas;
  json_t *software_commit_id;
  json_t *params;
  json_t *Config_File;
  _Bool temp;
  _Bool ret;
  uint32_t test_result;
  uint32_t nonce_rate_temp;
  uint32_t i;
  char *template_ptr;
  size_t commons_array_index;
  size_t pattern_asic_nonces_array_index;
  size_t sensors_datas_values_array_index;
  size_t sensors_array_index;
  size_t datas_array_index;
  size_t sensors_datas_array_index;
  
  memset(datas_array,0,0x20);
  memset(sensors_array,0,0x20);
  memset(asic_nonces_array,0,0x20);
  memset(commons_array,0,0x20);
  memset(sensors_datas_array,0,0x20);
  memset(sensors_datas_values_array,0,0x20);
  memset(pattern_asic_nonces_array,0,0x400);
  template_ptr = (char *)0x0;
  data[0] = '\0';
  data[1] = '\0';
  data[2] = '\0';
  data[3] = '\0';
  data[4] = '\0';
  data[5] = '\0';
  data[6] = '\0';
  data[7] = '\0';
  data[8] = '\0';
  data[9] = '\0';
  test_result = 0x1f;
  ret = true;
  if (sweep_mode) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: this is sweep mode mes info.\n","prepare_MES_system_submit_information");
    builtin_strncpy(tmp1,"this is sweep mode mes info.",0x1c);
    tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  memset(submit_result_handshake_information,0,0x800);
  json = json_load_file("/mnt/card/Config/MES_system/MES_system_submit_result_template.ini",0,&error
                       );
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Can\'t read out %s file.\n","prepare_MES_system_submit_information",
           "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
    snprintf(tmp1,0x800,"Can\'t read out %s file.",
             "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    template_ptr = json_dumps(json,0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: content: %s\n","prepare_MES_system_submit_information",template_ptr);
    snprintf(tmp1,0x800,"content: %s",template_ptr);
    log_to_file(tmp1,time_stamp);
    pjVar3 = json_object_get(json,"params");
    if ((pjVar3 == (json_t *)0x0) || (pjVar3->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t read out params in %s\n","prepare_MES_system_submit_information",
             "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
      snprintf(tmp1,0x800,"Can\'t read out params in %s",
               "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pjVar4 = json_object_get(pjVar3,"software_commit_id");
      if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t read out software_commit_id in %s\n",
               "prepare_MES_system_submit_information",
               "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
        snprintf(tmp1,0x800,"Can\'t read out software_commit_id in %s",
                 "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        json_string_set(pjVar4,zhiju_software_commit_id);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        pcVar5 = json_string_value(pjVar4);
        printf("%s: software_commit_id: %s\n","prepare_MES_system_submit_information",pcVar5);
        pcVar5 = json_string_value(pjVar4);
        snprintf(tmp1,0x800,"software_commit_id: %s",pcVar5);
        log_to_file(tmp1,time_stamp);
        pjVar3 = json_object_get(pjVar3,"datas");
        if ((pjVar3 == (json_t *)0x0) || (pjVar3->type != JSON_ARRAY)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Can\'t read out datas in %s\n","prepare_MES_system_submit_information",
                 "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
          snprintf(tmp1,0x800,"Can\'t read out datas in %s",
                   "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          sVar6 = json_array_size(pjVar3);
          for (datas_array_index = 0; datas_array_index < sVar6;
              datas_array_index = datas_array_index + 1) {
            pjVar4 = json_array_get(pjVar3,datas_array_index);
            datas_array[datas_array_index] = pjVar4;
            if ((datas_array[datas_array_index] == (json_t *)0x0) ||
               (datas_array[datas_array_index]->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out datas_array[%d] in datas\n",
                     "prepare_MES_system_submit_information",datas_array_index);
              snprintf(tmp1,0x800,"Can\'t read out datas_array[%d] in datas",datas_array_index);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            pjVar4 = json_object_get(datas_array[datas_array_index],"miner_type");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out miner_type in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out miner_type in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,(Local_Config_Information->Hash_Board).Miner_Type);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: miner_type: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"miner_type: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"board_name");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out board_name in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out board_name in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,(Local_Config_Information->Hash_Board).Board_Name);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: board_name: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"board_name: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"sn");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out sn in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out sn in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,sn.board_sn);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: sn: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"sn: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"order_id");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out order_id in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out order_id in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,qr_code.factory_job);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: order_id: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"order_id: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"hardware_version");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out hardware_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out hardware_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,0,3,data);
            json_string_set(pjVar4,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: hardware_version: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"hardware_version: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"bom_version");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out bom_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out bom_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,3,2,data);
            json_string_set(pjVar4,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: bom_version: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"bom_version: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"chip_technology");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out chip_technology in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out chip_technology in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,5,2,data);
            json_string_set(pjVar4,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: chip_technology: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"chip_technology: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"ft_version");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out ft_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out ft_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,qr_code.chip_ftversion);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: ft_version: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"ft_version: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"bin");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out bin in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out bin in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            bVar2 = get_chip_bin(&qr_code);
            if (bVar2 == 0xff) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: chip bin is BIN%d, error\n","prepare_MES_system_submit_information",0xff);
              snprintf(tmp1,0x800,"chip bin is BIN%d, error",0xff);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_integer_set(pjVar4,(ulonglong)(uint)bVar2);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar18 = json_integer_value(pjVar4);
            printf("%s: bin: %d\n","prepare_MES_system_submit_information",(int)jVar18);
            jVar18 = json_integer_value(pjVar4);
            snprintf(tmp1,0x800,"bin: %d",(int)jVar18);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"rule_version");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out rule_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out rule_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_string_set(pjVar4,(Local_Config_Information->Test_Info).Test_Config_Data_Version);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar4);
            printf("%s: rule_version: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar4);
            snprintf(tmp1,0x800,"rule_version: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar4 = json_object_get(datas_array[datas_array_index],"rule_level");
            level_info.level = 0;
            level_info.pre_open_core_voltage = 0;
            level_info.voltage = 0;
            level_info.freq = 0;
            if (sweep_mode) {
              get_match_level(&level_info);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Sweep level:%d\n","prepare_MES_system_submit_information",level_info.level
                    );
              snprintf(tmp1,0x800,"Sweep level:%d",level_info.level);
              log_to_file(tmp1,time_stamp);
            }
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out rule_level in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out rule_level in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            if (sweep_mode) {
              if (level_info.level < 1) {
                json_integer_set(pjVar4,(ulonglong)(gHistory_Result[test_loop_index].level + 100));
              }
              else {
                json_integer_set(pjVar4,(longlong)level_info.level);
              }
            }
            else {
              if (gHistory_Result[test_loop_index].test_standard == 0xf0) {
                json_integer_set(pjVar4,(ulonglong)(gHistory_Result[test_loop_index].level + 100));
              }
              else {
                json_integer_set(pjVar4,(ulonglong)
                                        ((uint)gHistory_Result[test_loop_index].test_standard * 100
                                        + gHistory_Result[test_loop_index].level));
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              jVar18 = json_integer_value(pjVar4);
              printf("%s: rule_level: %d\n","prepare_MES_system_submit_information",(int)jVar18);
              jVar18 = json_integer_value(pjVar4);
              snprintf(tmp1,0x800,"rule_level: %d",(int)jVar18);
              log_to_file(tmp1,time_stamp);
            }
            pjVar4 = json_object_get(datas_array[datas_array_index],"rule_result");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out rule_result in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out rule_result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            pjVar7 = json_object_get(pjVar4,"result");
            if (((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) &&
               ((pjVar7 == (json_t *)0x0 || (pjVar7->type != JSON_FALSE)))) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out result in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            temp = true;
            if (sweep_mode) {
              if (level_info.level < 1) {
                test_result = test_result & 0xfffffffc;
              }
              temp = level_info.level >= 1;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: sweep test_result: 0x%08x\n","prepare_MES_system_submit_information",
                     test_result);
              snprintf(tmp1,0x800,"sweep test_result: 0x%08x",test_result);
              log_to_file(tmp1,time_stamp);
            }
            else {
              if (gHistory_Result[test_loop_index].test_standard == '\0') {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: STRICT_STANDARD: ASIC_OK, NONCE_RATE_OK\n",
                       "prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"STRICT_STANDARD: ASIC_OK, NONCE_RATE_OK",0x28);
                log_to_file(tmp1,time_stamp);
              }
              else if (gHistory_Result[test_loop_index].test_standard == '\x01') {
                test_result = test_result & 0xfffffffe;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: LOOSE_STANDARD: ASIC_OK, fail\n","prepare_MES_system_submit_information"
                      );
                uVar1 = tmp1._28_4_;
                builtin_strncpy(tmp1,"LOOSE_STANDARD: ASIC_OK, fail",0x1e);
                tmp1._30_2_ = SUB42(uVar1,2);
                log_to_file(tmp1,time_stamp);
              }
              else {
                temp = false;
                test_result = test_result & 0xfffffffc;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: PATTERN NG: ASIC_OK, NONCE_RATE_OK, fail\n",
                       "prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"PATTERN NG: ASIC_OK, NONCE_RATE_OK, fail",0x28);
                tmp1[0x28] = '\0';
                log_to_file(tmp1,time_stamp);
              }
              if (gHistory_Result[test_loop_index].eeprom_ok != true) {
                temp = false;
                test_result = test_result & 0xfffffffb;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: EEPROM_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"EEPROM_OK, fail",0x10);
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic !=
                   false) && (gHistory_Result[test_loop_index].pic_sensor_all_OK != true)) {
                temp = false;
                test_result = test_result & 0xfffffff7;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: PIC_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"PIC_SENSOR_OK, fail",0x14);
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic !=
                   false) && (gHistory_Result[test_loop_index].asic_sensor_all_OK != true)) {
                temp = false;
                test_result = test_result & 0xffffffef;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: ASIC_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"ASIC_SENSOR_OK, fail",0x14);
                tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
                log_to_file(tmp1,time_stamp);
              }
            }
            if (temp) {
              pjVar7 = json_true();
              json_object_set(pjVar4,"result",pjVar7);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: set result as true\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"set result as tr",0x10);
              tmp1[0x10] = 'u';
              tmp1[0x11] = 'e';
              tmp1[0x12] = '\0';
              log_to_file(tmp1,time_stamp);
            }
            else {
              pjVar7 = json_false();
              json_object_set(pjVar4,"result",pjVar7);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: set result as false\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"set result as false",0x14);
              log_to_file(tmp1,time_stamp);
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: test_result: 0x%08x\n","prepare_MES_system_submit_information",test_result);
            snprintf(tmp1,0x800,"test_result: 0x%08x",test_result);
            log_to_file(tmp1,time_stamp);
            pjVar7 = json_object_get(pjVar4,"result");
            if (((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) &&
               ((pjVar7 == (json_t *)0x0 || (pjVar7->type != JSON_FALSE)))) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out result in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) {
              pcVar5 = "false";
            }
            else {
              pcVar5 = "true";
            }
            printf("%s: result: %s\n","prepare_MES_system_submit_information",pcVar5);
            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) {
              pcVar5 = "false";
            }
            else {
              pcVar5 = "true";
            }
            snprintf(tmp1,0x800,"result: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar7 = json_object_get(pjVar4,"sensors");
            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out sensors in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out sensors in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_array_size(pjVar7);
            if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic !=
                 true) && (iVar8 = json_array_remove(pjVar7,0), iVar8 != 0)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t remove pic sensors template %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t remove pic sensors template %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard
                 != true) && (iVar8 = json_array_remove(pjVar7,0), iVar8 != 0)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t remove CtrlBoard sensors template %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t remove CtrlBoard sensors template %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic !=
                true) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: remove asic sensors template\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"remove asic sensors template",0x1c);
              tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              iVar8 = json_array_remove(pjVar7,0);
              if (iVar8 != 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t remove asic sensors template %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x800,"Can\'t remove asic sensors template %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
            }
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch !=
                true) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: remove Switch sensors template\n","prepare_MES_system_submit_information")
              ;
              uVar1 = tmp1._28_4_;
              builtin_strncpy(tmp1,"remove Switch sensors template",0x1f);
              tmp1[0x1f] = SUB41(uVar1,3);
              log_to_file(tmp1,time_stamp);
              iVar8 = json_array_remove(pjVar7,0);
              if (iVar8 != 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t remove Switch sensors template %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x800,"Can\'t remove Switch sensors template %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
            }
            sVar9 = json_array_size(pjVar7);
            for (sensors_array_index = 0; sensors_array_index < sVar9;
                sensors_array_index = sensors_array_index + 1) {
              pjVar14 = json_array_get(pjVar7,sensors_array_index);
              sensors_array[sensors_array_index] = pjVar14;
              if ((sensors_array[sensors_array_index] == (json_t *)0x0) ||
                 (sensors_array[sensors_array_index]->type != JSON_OBJECT)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out sensors[%d] in sensor\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x800,"Can\'t read out sensors[%d] in sensor",sensors_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              pjVar14 = json_object_get(sensors_array[sensors_array_index],"name");
              if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out name in sensors[%d]\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x800,"Can\'t read out name in sensors[%d]",sensors_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar5 = json_string_value(pjVar14);
              printf("%s: name in sensors[%d]: %s\n","prepare_MES_system_submit_information",
                     sensors_array_index,pcVar5);
              pcVar5 = json_string_value(pjVar14);
              snprintf(tmp1,0x800,"name in sensors[%d]: %s",sensors_array_index,pcVar5);
              log_to_file(tmp1,time_stamp);
              pjVar15 = json_object_get(sensors_array[sensors_array_index],"datas");
              if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_ARRAY)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out datas in sensors_array[%d]\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x800,"Can\'t read out datas in sensors_array[%d]",sensors_array_index
                        );
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              sVar10 = json_array_size(pjVar15);
              for (sensors_datas_array_index = 0; sensors_datas_array_index < sVar10;
                  sensors_datas_array_index = sensors_datas_array_index + 1) {
                pjVar11 = json_array_get(pjVar15,sensors_datas_array_index);
                sensors_datas_array[sensors_datas_array_index] = pjVar11;
                if ((sensors_datas_array[sensors_datas_array_index] == (json_t *)0x0) ||
                   (sensors_datas_array[sensors_datas_array_index]->type != JSON_OBJECT)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out sensors[%d]->datas[%d]",sensors_array_index,
                           sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                pjVar11 = json_object_get(sensors_datas_array[sensors_datas_array_index],"id");
                if ((pjVar11 == (json_t *)0x0) || (pjVar11->type != JSON_INTEGER)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out id in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out id in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                json_integer_set(pjVar11,(ulonglong)sensors_datas_array_index);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                jVar18 = json_integer_value(pjVar11);
                printf("%s: sensors[%d]->datas[%d]->id: %d\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,(int)jVar18);
                jVar18 = json_integer_value(pjVar11);
                snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->id: %d",sensors_array_index,
                         sensors_datas_array_index,(int)jVar18);
                log_to_file(tmp1,time_stamp);
                pjVar11 = json_object_get(sensors_datas_array[sensors_datas_array_index],"type");
                if ((pjVar11 == (json_t *)0x0) || (pjVar11->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out type in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out type in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"PIC");
                if (iVar8 == 0) {
                  json_string_set(pjVar11,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar5 = json_string_value(pjVar11);
                  printf("%s: sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar5);
                  pcVar5 = json_string_value(pjVar11);
                  snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar5);
                  log_to_file(tmp1,time_stamp);
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"CTRLBOARD");
                if (iVar8 == 0) {
                  json_string_set(pjVar11,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar5 = json_string_value(pjVar11);
                  printf("%s: sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar5);
                  pcVar5 = json_string_value(pjVar11);
                  snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar5);
                  log_to_file(tmp1,time_stamp);
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"CHIP");
                if (iVar8 == 0) {
                  json_string_set(pjVar11,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar5 = json_string_value(pjVar11);
                  printf("%s: sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar5);
                  pcVar5 = json_string_value(pjVar11);
                  snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar5);
                  log_to_file(tmp1,time_stamp);
                }
                pjVar11 = json_object_get(sensors_datas_array[sensors_datas_array_index],"code");
                if ((pjVar11 == (json_t *)0x0) || (pjVar11->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out code in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out code in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                json_string_set(pjVar11,"0");
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                pcVar5 = json_string_value(pjVar11);
                printf("%s: sensors[%d]->datas[%d]->code: %s\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,pcVar5);
                pcVar5 = json_string_value(pjVar11);
                snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->code: %s",sensors_array_index,
                         sensors_datas_array_index,pcVar5);
                log_to_file(tmp1,time_stamp);
                pjVar11 = json_object_get(sensors_datas_array[sensors_datas_array_index],"msg");
                if ((pjVar11 == (json_t *)0x0) || (pjVar11->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out msg in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out msg in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"PIC");
                if (iVar8 == 0) {
                  if ((test_result & 8) == 0) {
                    json_string_set(pjVar11,"ng");
                  }
                  else {
                    json_string_set(pjVar11,"ok");
                  }
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"CTRLBOARD");
                if (iVar8 == 0) {
                  if ((test_result & 8) == 0) {
                    json_string_set(pjVar11,"ng");
                  }
                  else {
                    json_string_set(pjVar11,"ok");
                  }
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"ASIC");
                if (iVar8 == 0) {
                  if ((test_result & 0x10) == 0) {
                    json_string_set(pjVar11,"ng");
                  }
                  else {
                    json_string_set(pjVar11,"ok");
                  }
                }
                pcVar5 = json_string_value(pjVar14);
                iVar8 = strcmp(pcVar5,"SWITCH");
                if (iVar8 == 0) {
                  json_string_set(pjVar11,"ng");
                }
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                pcVar5 = json_string_value(pjVar11);
                printf("%s: sensors[%d]->datas[%d]->msg: %s\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,pcVar5);
                pcVar5 = json_string_value(pjVar11);
                snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->msg: %s",sensors_array_index,
                         sensors_datas_array_index,pcVar5);
                log_to_file(tmp1,time_stamp);
                pjVar11 = json_object_get(sensors_datas_array[sensors_datas_array_index],"values");
                if ((pjVar11 == (json_t *)0x0) || (pjVar11->type != JSON_ARRAY)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Can\'t read out values in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x800,"Can\'t read out values in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0008148e;
                }
                sVar12 = json_array_size(pjVar11);
                for (sensors_datas_values_array_index = 0; sensors_datas_values_array_index < sVar12
                    ; sensors_datas_values_array_index = sensors_datas_values_array_index + 1) {
                  pjVar13 = json_array_get(pjVar11,sensors_datas_values_array_index);
                  sensors_datas_values_array[sensors_datas_values_array_index] = pjVar13;
                  if ((sensors_datas_values_array[sensors_datas_values_array_index] == (json_t *)0x0
                      ) || (sensors_datas_values_array[sensors_datas_values_array_index]->type !=
                            JSON_INTEGER)) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: Can\'t find values[%d] in sensors[%d]->datas[%d]\n",
                           "prepare_MES_system_submit_information",sensors_datas_values_array_index,
                           sensors_array_index,sensors_datas_array_index);
                    snprintf(tmp1,0x800,"Can\'t find values[%d] in sensors[%d]->datas[%d]",
                             sensors_datas_values_array_index,sensors_array_index,
                             sensors_datas_array_index);
                    log_to_file(tmp1,time_stamp);
                    ret = false;
                    goto LAB_0008148e;
                  }
                  pcVar5 = json_string_value(pjVar14);
                  iVar8 = strcmp(pcVar5,"PIC");
                  if (iVar8 == 0) {
                    json_integer_set(sensors_datas_values_array[sensors_datas_values_array_index],
                                     (longlong)
                                     (int)gHistory_Result[test_loop_index].
                                          sensor_local_temperature_from_pic
                                          [sensors_datas_array_index]);
                  }
                  pcVar5 = json_string_value(pjVar14);
                  iVar8 = strcmp(pcVar5,"CTRLBOARD");
                  if (iVar8 == 0) {
                    json_integer_set(sensors_datas_values_array[sensors_datas_values_array_index],
                                     (longlong)
                                     (int)gHistory_Result[test_loop_index].
                                          sensor_local_temperature_from_ctrlboard
                                          [sensors_datas_array_index]);
                  }
                  pcVar5 = json_string_value(pjVar14);
                  iVar8 = strcmp(pcVar5,"CHIP");
                  if (iVar8 == 0) {
                    if (sensors_datas_values_array_index == 0) {
                      json_integer_set(sensors_datas_values_array[0],
                                       (longlong)
                                       (int)gHistory_Result[test_loop_index].
                                            sensor_local_temperature_from_asic
                                            [sensors_datas_array_index]);
                    }
                    if (sensors_datas_values_array_index == 1) {
                      json_integer_set(sensors_datas_values_array[1],
                                       (longlong)
                                       (int)gHistory_Result[test_loop_index].
                                            sensor_remote_temperature_from_asic
                                            [sensors_datas_array_index]);
                    }
                  }
                  pcVar5 = json_string_value(pjVar14);
                  iVar8 = strcmp(pcVar5,"SWITCH");
                  if (iVar8 == 0) {
                    json_integer_set(sensors_datas_values_array[sensors_datas_values_array_index],
                                     (longlong)
                                     (int)gHistory_Result[test_loop_index].
                                          sensor_local_temperature_from_switch
                                          [sensors_datas_array_index]);
                  }
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  jVar18 = json_integer_value(sensors_datas_values_array
                                              [sensors_datas_values_array_index]);
                  printf("%s: sensors[%d]->datas[%d]->values[%d]: %d\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,sensors_datas_values_array_index,(int)jVar18);
                  jVar18 = json_integer_value(sensors_datas_values_array
                                              [sensors_datas_values_array_index]);
                  snprintf(tmp1,0x800,"sensors[%d]->datas[%d]->values[%d]: %d",sensors_array_index,
                           sensors_datas_array_index,sensors_datas_values_array_index,(int)jVar18);
                  log_to_file(tmp1,time_stamp);
                }
              }
            }
            pjVar7 = json_object_get(pjVar4,"pattern");
            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out pattern in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out pattern in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            pjVar14 = json_object_get(pjVar7,"nonce_rate");
            if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out nonce_rate in pattern\n",
                     "prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"Can\'t read out nonce_rate in pattern",0x24);
              tmp1._36_4_ = tmp1._36_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            if (sweep_mode) {
              fVar16 = get_sweep_noncerate();
              nonce_rate_temp = (uint)(0.0 < fVar16 * 10000.0) * (int)(fVar16 * 10000.0);
            }
            else {
              dVar17 = gHistory_Result[test_loop_index].nonce_rate * 10000.0;
              nonce_rate_temp = (uint)(0.0 < dVar17) * (int)(longlong)dVar17;
            }
            json_integer_set(pjVar14,(ulonglong)nonce_rate_temp);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar18 = json_integer_value(pjVar14);
            printf("%s: nonce_rate: %d\n","prepare_MES_system_submit_information",(int)jVar18);
            jVar18 = json_integer_value(pjVar14);
            snprintf(tmp1,0x800,"nonce_rate: %d",(int)jVar18);
            log_to_file(tmp1,time_stamp);
            pjVar14 = json_object_get(pjVar7,"code");
            if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out code in pattern\n","prepare_MES_system_submit_information"
                    );
              uVar1 = tmp1._28_4_;
              builtin_strncpy(tmp1,"Can\'t read out code in pattern",0x1f);
              tmp1[0x1f] = SUB41(uVar1,3);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            memset(data,0x30,10);
            sprintf(data,"%u",test_loop_index + 1);
            json_string_set(pjVar14,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar14);
            printf("%s: code: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar14);
            snprintf(tmp1,0x800,"code: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar14 = json_object_get(pjVar7,"msg");
            if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out msg in pattern\n","prepare_MES_system_submit_information")
              ;
              uVar1 = tmp1._28_4_;
              builtin_strncpy(tmp1,"Can\'t read out msg in pattern",0x1e);
              tmp1._30_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            if (gHistory_Result[test_loop_index].test_standard == 0xf0) {
              json_string_set(pjVar14,"ng");
            }
            else {
              json_string_set(pjVar14,"ok");
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar5 = json_string_value(pjVar14);
            printf("%s: msg: %s\n","prepare_MES_system_submit_information",pcVar5);
            pcVar5 = json_string_value(pjVar14);
            snprintf(tmp1,0x800,"msg: %s",pcVar5);
            log_to_file(tmp1,time_stamp);
            pjVar14 = json_object_get(pjVar7,"asic_number");
            if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out asic_number in pattern\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._36_4_;
              builtin_strncpy(tmp1,"Can\'t read out asic_number in pattern",0x26);
              tmp1._38_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            json_integer_set(pjVar14,(ulonglong)(Local_Config_Information->Hash_Board).Asic_Num);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar18 = json_integer_value(pjVar14);
            printf("%s: asic_number: %d\n","prepare_MES_system_submit_information",(int)jVar18);
            jVar18 = json_integer_value(pjVar14);
            snprintf(tmp1,0x800,"asic_number: %d",(int)jVar18);
            log_to_file(tmp1,time_stamp);
            pjVar7 = json_object_get(pjVar7,"asic_nonces");
            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out asic_nonces in pattern\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._36_4_;
              builtin_strncpy(tmp1,"Can\'t read out asic_nonces in pattern",0x26);
              tmp1._38_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            i = json_array_size(pjVar7);
            for (pattern_asic_nonces_array_index = 0; pattern_asic_nonces_array_index < i;
                pattern_asic_nonces_array_index = pattern_asic_nonces_array_index + 1) {
              pjVar15 = json_array_get(pjVar7,pattern_asic_nonces_array_index);
              pattern_asic_nonces_array[pattern_asic_nonces_array_index] = pjVar15;
              if ((pattern_asic_nonces_array[pattern_asic_nonces_array_index] == (json_t *)0x0) ||
                 (pattern_asic_nonces_array[pattern_asic_nonces_array_index]->type != JSON_INTEGER))
              {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t find asic_nonces[%d] in pattern\n",
                       "prepare_MES_system_submit_information",pattern_asic_nonces_array_index);
                snprintf(tmp1,0x800,"Can\'t find asic_nonces[%d] in pattern",
                         pattern_asic_nonces_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
            }
            for (; jVar18 = json_integer_value(pjVar14), i < (uint)jVar18; i = i + 1) {
              pjVar15 = json_integer((ulonglong)i);
              pattern_asic_nonces_array[i] = pjVar15;
              json_array_append(pjVar7,pattern_asic_nonces_array[i]);
            }
            sVar9 = json_array_size(pjVar7);
            for (pattern_asic_nonces_array_index = 0; pattern_asic_nonces_array_index < sVar9;
                pattern_asic_nonces_array_index = pattern_asic_nonces_array_index + 1) {
              pjVar14 = json_array_get(pjVar7,pattern_asic_nonces_array_index);
              pattern_asic_nonces_array[pattern_asic_nonces_array_index] = pjVar14;
              if ((pattern_asic_nonces_array[pattern_asic_nonces_array_index] == (json_t *)0x0) ||
                 (pattern_asic_nonces_array[pattern_asic_nonces_array_index]->type != JSON_INTEGER))
              {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t find asic_nonces[%d] in pattern\n",
                       "prepare_MES_system_submit_information",pattern_asic_nonces_array_index);
                snprintf(tmp1,0x800,"Can\'t find asic_nonces[%d] in pattern",
                         pattern_asic_nonces_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              if (sweep_mode) {
                get_succ_asic_nonce_num((uint16_t *)time_stamp,0x100);
                json_integer_set(pattern_asic_nonces_array[pattern_asic_nonces_array_index],
                                 (ulonglong)
                                 *(ushort *)(time_stamp + pattern_asic_nonces_array_index * 2));
                print_time_stamp(time_stamp_83,0x30);
                printf("%s ",time_stamp_83);
                jVar18 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                printf("%s: sensors->asic_nonces[%d]: %d\n","prepare_MES_system_submit_information",
                       pattern_asic_nonces_array_index,(int)jVar18);
                jVar18 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                snprintf(tmp1,0x800,"sensors->asic_nonces[%d]: %d",pattern_asic_nonces_array_index,
                         (int)jVar18);
                log_to_file(tmp1,time_stamp_83);
              }
              else {
                json_integer_set(pattern_asic_nonces_array[pattern_asic_nonces_array_index],
                                 (ulonglong)
                                 gHistory_Result[test_loop_index].every_asic_got_nonce_num
                                 [pattern_asic_nonces_array_index]);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                jVar18 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                printf("%s: sensors->asic_nonces[%d]: %d\n","prepare_MES_system_submit_information",
                       pattern_asic_nonces_array_index,(int)jVar18);
                jVar18 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                snprintf(tmp1,0x800,"sensors->asic_nonces[%d]: %d",pattern_asic_nonces_array_index,
                         (int)jVar18);
                log_to_file(tmp1,time_stamp);
              }
            }
            pjVar4 = json_object_get(pjVar4,"commons");
            if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out commons in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out commons in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0008148e;
            }
            sVar9 = json_array_size(pjVar4);
            for (commons_array_index = 0; commons_array_index < sVar9;
                commons_array_index = commons_array_index + 1) {
              pjVar7 = json_array_get(pjVar4,commons_array_index);
              commons_array[commons_array_index] = pjVar7;
              if ((commons_array[commons_array_index] == (json_t *)0x0) ||
                 (commons_array[commons_array_index]->type != JSON_OBJECT)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out commons[%d]\n","prepare_MES_system_submit_information",
                       commons_array_index);
                snprintf(tmp1,0x800,"Can\'t read out commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              pjVar7 = json_object_get(commons_array[commons_array_index],"name");
              if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out name in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x800,"Can\'t read out name in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar5 = json_string_value(pjVar7);
              printf("%s: commons[%d]->name: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar5);
              pcVar5 = json_string_value(pjVar7);
              snprintf(tmp1,0x800,"commons[%d]->name: %s",commons_array_index,pcVar5);
              log_to_file(tmp1,time_stamp);
              pjVar14 = json_object_get(commons_array[commons_array_index],"code");
              if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out code in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x800,"Can\'t read out code in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              json_string_set(pjVar14,"0");
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar5 = json_string_value(pjVar14);
              printf("%s: commons[%d]->code: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar5);
              pcVar5 = json_string_value(pjVar14);
              snprintf(tmp1,0x800,"commons[%d]->code: %s",commons_array_index,pcVar5);
              log_to_file(tmp1,time_stamp);
              pjVar14 = json_object_get(commons_array[commons_array_index],"msg");
              if ((pjVar14 == (json_t *)0x0) || (pjVar14->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t read out msg in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x800,"Can\'t read out msg in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0008148e;
              }
              pcVar5 = json_string_value(pjVar7);
              iVar8 = strcmp(pcVar5,"eeprom");
              if (iVar8 == 0) {
                if ((test_result & 4) == 0) {
                  json_string_set(pjVar14,"ng");
                }
                else {
                  json_string_set(pjVar14,"ok");
                }
              }
              pcVar5 = json_string_value(pjVar7);
              iVar8 = strcmp(pcVar5,"pic");
              if (iVar8 == 0) {
                if (gHistory_Result[gPattern_test_counter].pic_ok == false) {
                  json_string_set(pjVar14,"ng");
                }
                else {
                  json_string_set(pjVar14,"ok");
                }
              }
              pcVar5 = json_string_value(pjVar7);
              iVar8 = strcmp(pcVar5,"power");
              if (iVar8 == 0) {
                if (gHistory_Result[gPattern_test_counter].apw_power_ok == false) {
                  json_string_set(pjVar14,"ng");
                }
                else {
                  json_string_set(pjVar14,"ok");
                }
                if (sweep_mode) {
                  json_string_set(pjVar14,"ok");
                }
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar5 = json_string_value(pjVar14);
              printf("%s: commons[%d]->msg: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar5);
              pcVar5 = json_string_value(pjVar14);
              snprintf(tmp1,0x800,"commons[%d]->msg: %s",commons_array_index,pcVar5);
              log_to_file(tmp1,time_stamp);
            }
          }
          template_ptr = json_dumps(json,0);
          mes_system_submit_result_file_length = strlen(template_ptr);
          memcpy(submit_result_handshake_information,template_ptr,
                 mes_system_submit_result_file_length);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: size: %d, content: %s\n","prepare_MES_system_submit_information",
                 mes_system_submit_result_file_length,submit_result_handshake_information);
          snprintf(tmp1,0x800,"size: %d, content: %s",mes_system_submit_result_file_length,
                   submit_result_handshake_information);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
  }
LAB_0008148e:
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  if (template_ptr != (char *)0x0) {
    free(template_ptr);
  }
  return ret;
}

