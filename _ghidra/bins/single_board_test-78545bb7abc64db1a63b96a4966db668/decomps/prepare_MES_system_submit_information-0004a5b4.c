
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffe44 : 0x0004d522 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

_Bool prepare_MES_system_submit_information(uint32_t test_loop_index,_Bool sweep_mode)

{
  undefined4 uVar1;
  _Bool _Var2;
  byte bVar3;
  json_t *json;
  char *pcVar4;
  json_t *pjVar5;
  json_t *pjVar6;
  size_t sVar7;
  json_t *pjVar8;
  int iVar9;
  size_t sVar10;
  size_t sVar11;
  json_t *pjVar12;
  size_t sVar13;
  json_t *pjVar14;
  json_t *pjVar15;
  json_t *pjVar16;
  float fVar17;
  double dVar18;
  json_int_t jVar19;
  _Bool sweep_mode_local;
  uint32_t test_loop_index_local;
  char time_stamp_85 [48];
  char time_stamp [48];
  char tmp1 [256];
  uint8_t sensor_temp [2];
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
  json_t *ft_bin_list;
  uint32_t bin_num;
  char *template_ptr;
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
  size_t commons_array_index;
  size_t pattern_asic_nonces_array_index;
  size_t sensors_datas_values_array_index;
  size_t sensors_array_index;
  size_t datas_array_index;
  size_t sensors_datas_array_index;
  
  datas_array[0] = (json_t *)0x0;
  datas_array[1] = (json_t *)0x0;
  datas_array[2] = (json_t *)0x0;
  datas_array[3] = (json_t *)0x0;
  datas_array[4] = (json_t *)0x0;
  datas_array[5] = (json_t *)0x0;
  datas_array[6] = (json_t *)0x0;
  datas_array[7] = (json_t *)0x0;
  sensors_array[0] = (json_t *)0x0;
  sensors_array[1] = (json_t *)0x0;
  sensors_array[2] = (json_t *)0x0;
  sensors_array[3] = (json_t *)0x0;
  sensors_array[4] = (json_t *)0x0;
  sensors_array[5] = (json_t *)0x0;
  sensors_array[6] = (json_t *)0x0;
  sensors_array[7] = (json_t *)0x0;
  commons_array[0] = (json_t *)0x0;
  commons_array[1] = (json_t *)0x0;
  commons_array[2] = (json_t *)0x0;
  commons_array[3] = (json_t *)0x0;
  commons_array[4] = (json_t *)0x0;
  commons_array[5] = (json_t *)0x0;
  commons_array[6] = (json_t *)0x0;
  commons_array[7] = (json_t *)0x0;
  sensors_datas_array[0] = (json_t *)0x0;
  sensors_datas_array[1] = (json_t *)0x0;
  sensors_datas_array[2] = (json_t *)0x0;
  sensors_datas_array[3] = (json_t *)0x0;
  sensors_datas_array[4] = (json_t *)0x0;
  sensors_datas_array[5] = (json_t *)0x0;
  sensors_datas_array[6] = (json_t *)0x0;
  sensors_datas_array[7] = (json_t *)0x0;
  sensors_datas_values_array[0] = (json_t *)0x0;
  sensors_datas_values_array[1] = (json_t *)0x0;
  sensors_datas_values_array[2] = (json_t *)0x0;
  sensors_datas_values_array[3] = (json_t *)0x0;
  sensors_datas_values_array[4] = (json_t *)0x0;
  sensors_datas_values_array[5] = (json_t *)0x0;
  sensors_datas_values_array[6] = (json_t *)0x0;
  sensors_datas_values_array[7] = (json_t *)0x0;
  memset(pattern_asic_nonces_array,0,0x400);
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
  test_result = 0x3f;
  ret = true;
  if (sweep_mode) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : this is sweep mode mes info.\n","prepare_MES_system_submit_information");
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
    printf("%s : Can\'t read out %s file.\n","prepare_MES_system_submit_information",
           "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
    snprintf(tmp1,0x100,"Can\'t read out %s file.",
             "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    pcVar4 = json_dumps(json,0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : content: %s\n","prepare_MES_system_submit_information",pcVar4);
    snprintf(tmp1,0x100,"content: %s",pcVar4);
    log_to_file(tmp1,time_stamp);
    pjVar5 = json_object_get(json,"params");
    if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Can\'t read out params in %s\n","prepare_MES_system_submit_information",
             "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
      snprintf(tmp1,0x100,"Can\'t read out params in %s",
               "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pjVar6 = json_object_get(pjVar5,"software_commit_id");
      if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Can\'t read out software_commit_id in %s\n",
               "prepare_MES_system_submit_information",
               "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
        snprintf(tmp1,0x100,"Can\'t read out software_commit_id in %s",
                 "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        json_string_set(pjVar6,zhiju_software_commit_id);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        pcVar4 = json_string_value(pjVar6);
        printf("%s : software_commit_id: %s\n","prepare_MES_system_submit_information",pcVar4);
        pcVar4 = json_string_value(pjVar6);
        snprintf(tmp1,0x100,"software_commit_id: %s",pcVar4);
        log_to_file(tmp1,time_stamp);
        pjVar5 = json_object_get(pjVar5,"datas");
        if ((pjVar5 == (json_t *)0x0) || (pjVar5->type != JSON_ARRAY)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Can\'t read out datas in %s\n","prepare_MES_system_submit_information",
                 "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
          snprintf(tmp1,0x100,"Can\'t read out datas in %s",
                   "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          sVar7 = json_array_size(pjVar5);
          for (datas_array_index = 0; datas_array_index < sVar7;
              datas_array_index = datas_array_index + 1) {
            pjVar6 = json_array_get(pjVar5,datas_array_index);
            datas_array[datas_array_index] = pjVar6;
            if ((datas_array[datas_array_index] == (json_t *)0x0) ||
               (datas_array[datas_array_index]->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out datas_array[%d] in datas\n",
                     "prepare_MES_system_submit_information",datas_array_index);
              snprintf(tmp1,0x100,"Can\'t read out datas_array[%d] in datas",datas_array_index);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            pjVar6 = json_object_get(datas_array[datas_array_index],"miner_type");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out miner_type in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out miner_type in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_string_set(pjVar6,(Local_Config_Information->Hash_Board).Miner_Type);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : miner_type: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"miner_type: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"board_name");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out board_name in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out board_name in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_string_set(pjVar6,(Local_Config_Information->Hash_Board).Board_Name);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : board_name: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"board_name: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"sn");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out sn in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out sn in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_string_set(pjVar6,sn.board_sn);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : sn: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"sn: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"order_id");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out order_id in %s\n","prepare_MES_system_submit_information"
                     ,"/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out order_id in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_string_set(pjVar6,qr_code.factory_job);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : order_id: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"order_id: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"hardware_version");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out hardware_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out hardware_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,0,3,data);
            json_string_set(pjVar6,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : hardware_version: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"hardware_version: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"bom_version");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out bom_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out bom_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,3,2,data);
            json_string_set(pjVar6,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : bom_version: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"bom_version: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"chip_technology");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out chip_technology in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out chip_technology in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,5,2,data);
            json_string_set(pjVar6,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : chip_technology: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"chip_technology: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            _Var2 = check_is_multiple_ft_version(qr_code.chip_ftversion);
            if (_Var2) {
              pjVar6 = create_ft_bin_json_info(&qr_code.ft_bin_list);
              json_object_set(datas_array[datas_array_index],"ft_bin_list",pjVar6);
            }
            else {
              pjVar6 = json_object_get(datas_array[datas_array_index],"ft_version");
              if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out ft_version in %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x100,"Can\'t read out ft_version in %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              json_string_set(pjVar6,qr_code.chip_ftversion);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar4 = json_string_value(pjVar6);
              printf("%s : ft_version: %s\n","prepare_MES_system_submit_information",pcVar4);
              pcVar4 = json_string_value(pjVar6);
              snprintf(tmp1,0x100,"ft_version: %s",pcVar4);
              log_to_file(tmp1,time_stamp);
              pjVar6 = json_object_get(datas_array[datas_array_index],"bin");
              if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out bin in %s\n","prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x100,"Can\'t read out bin in %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              bVar3 = get_chip_bin(&qr_code);
              if (bVar3 == 0xff) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : chip bin is BIN%d, error\n","prepare_MES_system_submit_information",
                       0xff);
                snprintf(tmp1,0x100,"chip bin is BIN%d, error",0xff);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              json_integer_set(pjVar6,(ulonglong)(uint)bVar3);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              jVar19 = json_integer_value(pjVar6);
              printf("%s : bin: %d\n","prepare_MES_system_submit_information",(int)jVar19);
              jVar19 = json_integer_value(pjVar6);
              snprintf(tmp1,0x100,"bin: %d",(int)jVar19);
              log_to_file(tmp1,time_stamp);
            }
            pjVar6 = json_object_get(datas_array[datas_array_index],"rule_version");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out rule_version in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out rule_version in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_string_set(pjVar6,(Local_Config_Information->Test_Info).Test_Config_Data_Version);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar6);
            printf("%s : rule_version: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar6);
            snprintf(tmp1,0x100,"rule_version: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"rule_level");
            level_info.level = 0;
            level_info.pre_open_core_voltage = 0;
            level_info.voltage = 0;
            level_info.freq = 0;
            if (sweep_mode) {
              get_match_level(&level_info);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Sweep levevl:%d\n","prepare_MES_system_submit_information",
                     level_info.level);
              snprintf(tmp1,0x100,"Sweep levevl:%d",level_info.level);
              log_to_file(tmp1,time_stamp);
            }
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out rule_level in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out rule_level in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            if (sweep_mode) {
              if (level_info.level < 1) {
                json_integer_set(pjVar6,(ulonglong)(gHistory_Result[test_loop_index].level + 100));
              }
              else {
                json_integer_set(pjVar6,(longlong)level_info.level);
              }
            }
            else if (gHistory_Result[test_loop_index].test_standard == 0xf0) {
              json_integer_set(pjVar6,(ulonglong)(gHistory_Result[test_loop_index].level + 100));
            }
            else {
              json_integer_set(pjVar6,(ulonglong)
                                      ((uint)gHistory_Result[test_loop_index].test_standard * 100 +
                                      gHistory_Result[test_loop_index].level));
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar19 = json_integer_value(pjVar6);
            printf("%s : rule_level: %d\n","prepare_MES_system_submit_information",(int)jVar19);
            jVar19 = json_integer_value(pjVar6);
            snprintf(tmp1,0x100,"rule_level: %d",(int)jVar19);
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(datas_array[datas_array_index],"rule_result");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out rule_result in %s\n",
                     "prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out rule_result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            pjVar8 = json_object_get(pjVar6,"result");
            if (((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_TRUE)) &&
               ((pjVar8 == (json_t *)0x0 || (pjVar8->type != JSON_FALSE)))) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out result in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            temp = true;
            if (sweep_mode) {
              if (level_info.level < 1) {
                test_result = test_result & 0xfffffffc;
              }
              temp = level_info.level >= 1;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : sweep test_result: 0x%08x\n","prepare_MES_system_submit_information",
                     test_result);
              snprintf(tmp1,0x100,"sweep test_result: 0x%08x",test_result);
              log_to_file(tmp1,time_stamp);
            }
            else {
              if (gHistory_Result[test_loop_index].test_standard == '\0') {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : STRICT_STANDARD: ASIC_OK, NONCE_RATE_OK\n",
                       "prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"STRICT_STANDARD: ASIC_OK, NONCE_RATE_OK",0x28);
                log_to_file(tmp1,time_stamp);
              }
              else if (gHistory_Result[test_loop_index].test_standard == '\x01') {
                test_result = test_result & 0xfffffffe;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : LOOSE_STANDARD: ASIC_OK, fail\n",
                       "prepare_MES_system_submit_information");
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
                printf("%s : PATTERN NG: ASIC_OK, NONCE_RATE_OK, fail\n",
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
                printf("%s : EEPROM_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"EEPROM_OK, fail",0x10);
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic !=
                   false) && (gHistory_Result[test_loop_index].pic_sensor_all_OK != true)) {
                temp = false;
                test_result = test_result & 0xfffffff7;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : PIC_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"PIC_SENSOR_OK, fail",0x14);
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic !=
                   false) && (gHistory_Result[test_loop_index].asic_sensor_all_OK != true)) {
                temp = false;
                test_result = test_result & 0xffffffef;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : ASIC_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                builtin_strncpy(tmp1,"ASIC_SENSOR_OK, fail",0x14);
                tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.
                   Read_Temperature_From_CtrlBoard != false) &&
                 (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK != true)) {
                temp = false;
                test_result = test_result & 0xffffffdf;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : CTRLBOARD_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                uVar1 = tmp1._24_4_;
                builtin_strncpy(tmp1,"CTRLBOARD_SENSOR_OK, fail",0x1a);
                tmp1._26_2_ = SUB42(uVar1,2);
                log_to_file(tmp1,time_stamp);
              }
              if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch
                   != false) && (gHistory_Result[test_loop_index].switch_sensor_all_ok != true)) {
                temp = false;
                test_result = test_result & 0xffffffdf;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : CTRLBOARD_SENSOR_OK, fail\n","prepare_MES_system_submit_information");
                uVar1 = tmp1._24_4_;
                builtin_strncpy(tmp1,"CTRLBOARD_SENSOR_OK, fail",0x1a);
                tmp1._26_2_ = SUB42(uVar1,2);
                log_to_file(tmp1,time_stamp);
              }
            }
            if (temp) {
              pjVar8 = json_true();
              json_object_set(pjVar6,"result",pjVar8);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : set result as true\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"set result as tr",0x10);
              tmp1[0x10] = 'u';
              tmp1[0x11] = 'e';
              tmp1[0x12] = '\0';
              log_to_file(tmp1,time_stamp);
            }
            else {
              pjVar8 = json_false();
              json_object_set(pjVar6,"result",pjVar8);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : set result as false\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"set result as false",0x14);
              log_to_file(tmp1,time_stamp);
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : test_result: 0x%08x\n","prepare_MES_system_submit_information",test_result)
            ;
            snprintf(tmp1,0x100,"test_result: 0x%08x",test_result);
            log_to_file(tmp1,time_stamp);
            pjVar8 = json_object_get(pjVar6,"result");
            if (((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_TRUE)) &&
               ((pjVar8 == (json_t *)0x0 || (pjVar8->type != JSON_FALSE)))) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out result in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out result in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_TRUE)) {
              pcVar4 = "false";
            }
            else {
              pcVar4 = "true";
            }
            printf("%s : result: %s\n","prepare_MES_system_submit_information",pcVar4);
            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_TRUE)) {
              pcVar4 = "false";
            }
            else {
              pcVar4 = "true";
            }
            snprintf(tmp1,0x100,"result: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar8 = json_object_get(pjVar6,"sensors");
            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out sensors in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out sensors in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_array_size(pjVar8);
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard
                != true) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : remove CtrlBoard sensors template\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._32_4_;
              builtin_strncpy(tmp1,"remove CtrlBoard sensors template",0x22);
              tmp1._34_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              iVar9 = json_array_remove(pjVar8,2);
              if (iVar9 != 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t remove CtrlBoard sensors template %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x100,"Can\'t remove CtrlBoard sensors template %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
            }
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic !=
                true) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : remove asic sensors template\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"remove asic sensors template",0x1c);
              tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              iVar9 = json_array_remove(pjVar8,1);
              if (iVar9 != 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t remove asic sensors template %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x100,"Can\'t remove asic sensors template %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
            }
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != true
               ) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : remove pic sensors template\n","prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"remove pic sensors template",0x1c);
              log_to_file(tmp1,time_stamp);
              iVar9 = json_array_remove(pjVar8,0);
              if (iVar9 != 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t remove pic sensors template %s\n",
                       "prepare_MES_system_submit_information",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                snprintf(tmp1,0x100,"Can\'t remove pic sensors template %s",
                         "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
            }
            sVar10 = json_array_size(pjVar8);
            for (sensors_array_index = 0; sensors_array_index < sVar10;
                sensors_array_index = sensors_array_index + 1) {
              pjVar15 = json_array_get(pjVar8,sensors_array_index);
              sensors_array[sensors_array_index] = pjVar15;
              if ((sensors_array[sensors_array_index] == (json_t *)0x0) ||
                 (sensors_array[sensors_array_index]->type != JSON_OBJECT)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out sensors[%d] in sensor\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x100,"Can\'t read out sensors[%d] in sensor",sensors_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              pjVar15 = json_object_get(sensors_array[sensors_array_index],"name");
              if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out name in sensors[%d]\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x100,"Can\'t read out name in sensors[%d]",sensors_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar4 = json_string_value(pjVar15);
              printf("%s : name in sensors[%d]: %s\n","prepare_MES_system_submit_information",
                     sensors_array_index,pcVar4);
              pcVar4 = json_string_value(pjVar15);
              snprintf(tmp1,0x100,"name in sensors[%d]: %s",sensors_array_index,pcVar4);
              log_to_file(tmp1,time_stamp);
              pjVar16 = json_object_get(sensors_array[sensors_array_index],"datas");
              if ((pjVar16 == (json_t *)0x0) || (pjVar16->type != JSON_ARRAY)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out datas in sensors_array[%d]\n",
                       "prepare_MES_system_submit_information",sensors_array_index);
                snprintf(tmp1,0x100,"Can\'t read out datas in sensors_array[%d]",sensors_array_index
                        );
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              sVar11 = json_array_size(pjVar16);
              for (sensors_datas_array_index = 0; sensors_datas_array_index < sVar11;
                  sensors_datas_array_index = sensors_datas_array_index + 1) {
                pjVar12 = json_array_get(pjVar16,sensors_datas_array_index);
                sensors_datas_array[sensors_datas_array_index] = pjVar12;
                if ((sensors_datas_array[sensors_datas_array_index] == (json_t *)0x0) ||
                   (sensors_datas_array[sensors_datas_array_index]->type != JSON_OBJECT)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out sensors[%d]->datas[%d]",sensors_array_index,
                           sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                pjVar12 = json_object_get(sensors_datas_array[sensors_datas_array_index],"id");
                if ((pjVar12 == (json_t *)0x0) || (pjVar12->type != JSON_INTEGER)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out id in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out id in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                json_integer_set(pjVar12,(ulonglong)sensors_datas_array_index);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                jVar19 = json_integer_value(pjVar12);
                printf("%s : sensors[%d]->datas[%d]->id: %d\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,(int)jVar19);
                jVar19 = json_integer_value(pjVar12);
                snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->id: %d",sensors_array_index,
                         sensors_datas_array_index,(int)jVar19);
                log_to_file(tmp1,time_stamp);
                pjVar12 = json_object_get(sensors_datas_array[sensors_datas_array_index],"type");
                if ((pjVar12 == (json_t *)0x0) || (pjVar12->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out type in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out type in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"PIC");
                if (iVar9 == 0) {
                  json_string_set(pjVar12,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar4 = json_string_value(pjVar12);
                  printf("%s : sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar4);
                  pcVar4 = json_string_value(pjVar12);
                  snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar4);
                  log_to_file(tmp1,time_stamp);
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"CHIP");
                if (iVar9 == 0) {
                  json_string_set(pjVar12,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar4 = json_string_value(pjVar12);
                  printf("%s : sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar4);
                  pcVar4 = json_string_value(pjVar12);
                  snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar4);
                  log_to_file(tmp1,time_stamp);
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"CTRLBOARD");
                if (iVar9 == 0) {
                  json_string_set(pjVar12,qr_code.temp_sensor_type);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  pcVar4 = json_string_value(pjVar12);
                  printf("%s : sensors[%d]->datas[%d]->type: %s\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,pcVar4);
                  pcVar4 = json_string_value(pjVar12);
                  snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->type: %s",sensors_array_index,
                           sensors_datas_array_index,pcVar4);
                  log_to_file(tmp1,time_stamp);
                }
                pjVar12 = json_object_get(sensors_datas_array[sensors_datas_array_index],"code");
                if ((pjVar12 == (json_t *)0x0) || (pjVar12->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out code in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out code in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                json_string_set(pjVar12,"0");
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                pcVar4 = json_string_value(pjVar12);
                printf("%s : sensors[%d]->datas[%d]->code: %s\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,pcVar4);
                pcVar4 = json_string_value(pjVar12);
                snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->code: %s",sensors_array_index,
                         sensors_datas_array_index,pcVar4);
                log_to_file(tmp1,time_stamp);
                pjVar12 = json_object_get(sensors_datas_array[sensors_datas_array_index],"msg");
                if ((pjVar12 == (json_t *)0x0) || (pjVar12->type != JSON_STRING)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out msg in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out msg in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"PIC");
                if (iVar9 == 0) {
                  if ((test_result & 8) == 0) {
                    json_string_set(pjVar12,"ng");
                  }
                  else {
                    json_string_set(pjVar12,"ok");
                  }
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"ASIC");
                if (iVar9 == 0) {
                  if ((test_result & 0x10) == 0) {
                    json_string_set(pjVar12,"ng");
                  }
                  else {
                    json_string_set(pjVar12,"ok");
                  }
                }
                pcVar4 = json_string_value(pjVar15);
                iVar9 = strcmp(pcVar4,"CTRLBOARD");
                if (iVar9 == 0) {
                  if ((test_result & 0x20) == 0) {
                    json_string_set(pjVar12,"ng");
                  }
                  else {
                    json_string_set(pjVar12,"ok");
                  }
                }
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                pcVar4 = json_string_value(pjVar12);
                printf("%s : sensors[%d]->datas[%d]->msg: %s\n",
                       "prepare_MES_system_submit_information",sensors_array_index,
                       sensors_datas_array_index,pcVar4);
                pcVar4 = json_string_value(pjVar12);
                snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->msg: %s",sensors_array_index,
                         sensors_datas_array_index,pcVar4);
                log_to_file(tmp1,time_stamp);
                pjVar12 = json_object_get(sensors_datas_array[sensors_datas_array_index],"values");
                if ((pjVar12 == (json_t *)0x0) || (pjVar12->type != JSON_ARRAY)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out values in sensors[%d]->datas[%d]\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index);
                  snprintf(tmp1,0x100,"Can\'t read out values in sensors[%d]->datas[%d]",
                           sensors_array_index,sensors_datas_array_index);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                  goto LAB_0004e76e;
                }
                sVar13 = json_array_size(pjVar12);
                for (sensors_datas_values_array_index = 0; sensors_datas_values_array_index < sVar13
                    ; sensors_datas_values_array_index = sensors_datas_values_array_index + 1) {
                  pjVar14 = json_array_get(pjVar12,sensors_datas_values_array_index);
                  sensors_datas_values_array[sensors_datas_values_array_index] = pjVar14;
                  if ((sensors_datas_values_array[sensors_datas_values_array_index] == (json_t *)0x0
                      ) || (sensors_datas_values_array[sensors_datas_values_array_index]->type !=
                            JSON_INTEGER)) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : Can\'t find values[%d] in sensors[%d]->datas[%d]\n",
                           "prepare_MES_system_submit_information",sensors_datas_values_array_index,
                           sensors_array_index,sensors_datas_array_index);
                    snprintf(tmp1,0x100,"Can\'t find values[%d] in sensors[%d]->datas[%d]",
                             sensors_datas_values_array_index,sensors_array_index,
                             sensors_datas_array_index);
                    log_to_file(tmp1,time_stamp);
                    ret = false;
                    goto LAB_0004e76e;
                  }
                  pcVar4 = json_string_value(pjVar15);
                  iVar9 = strcmp(pcVar4,"PIC");
                  if (iVar9 == 0) {
                    json_integer_set(sensors_datas_values_array[sensors_datas_values_array_index],
                                     (longlong)
                                     (int)gHistory_Result[test_loop_index].
                                          sensor_local_temperature_from_pic
                                          [sensors_datas_array_index]);
                  }
                  pcVar4 = json_string_value(pjVar15);
                  strcmp(pcVar4,"CHIP");
                  pcVar4 = json_string_value(pjVar15);
                  iVar9 = strcmp(pcVar4,"CTRLBOARD");
                  if (iVar9 == 0) {
                    if (sweep_mode) {
                      get_last_pattern_temp(sensor_temp,2);
                      if (sensors_datas_values_array_index == 0) {
                        json_integer_set(sensors_datas_values_array[0],
                                         (ulonglong)sensor_temp[sensors_datas_array_index]);
                      }
                      if (sensors_datas_values_array_index == 1) {
                        json_integer_set(sensors_datas_values_array[1],
                                         (ulonglong)sensor_temp[sensors_datas_array_index]);
                      }
                    }
                    else {
                      if (sensors_datas_values_array_index == 0) {
                        json_integer_set(sensors_datas_values_array[0],
                                         (longlong)
                                         (int)gHistory_Result[test_loop_index].
                                              sensor_local_temperature_from_ctrlboard
                                              [sensors_datas_array_index]);
                      }
                      if (sensors_datas_values_array_index == 1) {
                        json_integer_set(sensors_datas_values_array[1],
                                         (longlong)
                                         (int)gHistory_Result[test_loop_index].
                                              sensor_local_temperature_from_ctrlboard
                                              [sensors_datas_array_index]);
                      }
                    }
                  }
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  jVar19 = json_integer_value(sensors_datas_values_array
                                              [sensors_datas_values_array_index]);
                  printf("%s : sensors[%d]->datas[%d]->values[%d]: %d\n",
                         "prepare_MES_system_submit_information",sensors_array_index,
                         sensors_datas_array_index,sensors_datas_values_array_index,(int)jVar19);
                  jVar19 = json_integer_value(sensors_datas_values_array
                                              [sensors_datas_values_array_index]);
                  snprintf(tmp1,0x100,"sensors[%d]->datas[%d]->values[%d]: %d",sensors_array_index,
                           sensors_datas_array_index,sensors_datas_values_array_index,(int)jVar19);
                  log_to_file(tmp1,time_stamp);
                }
              }
            }
            pjVar8 = json_object_get(pjVar6,"pattern");
            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out pattern in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out pattern in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            pjVar15 = json_object_get(pjVar8,"nonce_rate");
            if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out nonce_rate in pattern\n",
                     "prepare_MES_system_submit_information");
              builtin_strncpy(tmp1,"Can\'t read out nonce_rate in pattern",0x24);
              tmp1._36_4_ = tmp1._36_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            if (sweep_mode) {
              fVar17 = get_sweep_noncerate();
              nonce_rate_temp = (uint)(0.0 < fVar17 * 10000.0) * (int)(fVar17 * 10000.0);
            }
            else {
              dVar18 = gHistory_Result[test_loop_index].nonce_rate * 10000.0;
              nonce_rate_temp = (uint)(0.0 < dVar18) * (int)(longlong)dVar18;
            }
            json_integer_set(pjVar15,(ulonglong)nonce_rate_temp);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar19 = json_integer_value(pjVar15);
            printf("%s : nonce_rate: %d\n","prepare_MES_system_submit_information",(int)jVar19);
            jVar19 = json_integer_value(pjVar15);
            snprintf(tmp1,0x100,"nonce_rate: %d",(int)jVar19);
            log_to_file(tmp1,time_stamp);
            pjVar15 = json_object_get(pjVar8,"code");
            if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out code in pattern\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._28_4_;
              builtin_strncpy(tmp1,"Can\'t read out code in pattern",0x1f);
              tmp1[0x1f] = SUB41(uVar1,3);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            memset(data,0x30,10);
            sprintf(data,"%u",test_loop_index + 1);
            json_string_set(pjVar15,data);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar15);
            printf("%s : code: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar15);
            snprintf(tmp1,0x100,"code: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar15 = json_object_get(pjVar8,"msg");
            if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out msg in pattern\n","prepare_MES_system_submit_information"
                    );
              uVar1 = tmp1._28_4_;
              builtin_strncpy(tmp1,"Can\'t read out msg in pattern",0x1e);
              tmp1._30_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            if (gHistory_Result[test_loop_index].test_standard == 0xf0) {
              json_string_set(pjVar15,"ng");
            }
            else {
              json_string_set(pjVar15,"ok");
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            pcVar4 = json_string_value(pjVar15);
            printf("%s : msg: %s\n","prepare_MES_system_submit_information",pcVar4);
            pcVar4 = json_string_value(pjVar15);
            snprintf(tmp1,0x100,"msg: %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            pjVar15 = json_object_get(pjVar8,"asic_number");
            if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_INTEGER)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out asic_number in pattern\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._36_4_;
              builtin_strncpy(tmp1,"Can\'t read out asic_number in pattern",0x26);
              tmp1._38_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            json_integer_set(pjVar15,(ulonglong)(Local_Config_Information->Hash_Board).Asic_Num);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            jVar19 = json_integer_value(pjVar15);
            printf("%s : asic_number: %d\n","prepare_MES_system_submit_information",(int)jVar19);
            jVar19 = json_integer_value(pjVar15);
            snprintf(tmp1,0x100,"asic_number: %d",(int)jVar19);
            log_to_file(tmp1,time_stamp);
            pjVar8 = json_object_get(pjVar8,"asic_nonces");
            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out asic_nonces in pattern\n",
                     "prepare_MES_system_submit_information");
              uVar1 = tmp1._36_4_;
              builtin_strncpy(tmp1,"Can\'t read out asic_nonces in pattern",0x26);
              tmp1._38_2_ = SUB42(uVar1,2);
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            i = json_array_size(pjVar8);
            for (pattern_asic_nonces_array_index = 0; pattern_asic_nonces_array_index < i;
                pattern_asic_nonces_array_index = pattern_asic_nonces_array_index + 1) {
              pjVar16 = json_array_get(pjVar8,pattern_asic_nonces_array_index);
              pattern_asic_nonces_array[pattern_asic_nonces_array_index] = pjVar16;
              if ((pattern_asic_nonces_array[pattern_asic_nonces_array_index] == (json_t *)0x0) ||
                 (pattern_asic_nonces_array[pattern_asic_nonces_array_index]->type != JSON_INTEGER))
              {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t find asic_nonces[%d] in pattern\n",
                       "prepare_MES_system_submit_information",pattern_asic_nonces_array_index);
                snprintf(tmp1,0x100,"Can\'t find asic_nonces[%d] in pattern",
                         pattern_asic_nonces_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
            }
            for (; jVar19 = json_integer_value(pjVar15), i < (uint)jVar19; i = i + 1) {
              pjVar16 = json_integer((ulonglong)i);
              pattern_asic_nonces_array[i] = pjVar16;
              json_array_append(pjVar8,pattern_asic_nonces_array[i]);
            }
            sVar10 = json_array_size(pjVar8);
            for (pattern_asic_nonces_array_index = 0; pattern_asic_nonces_array_index < sVar10;
                pattern_asic_nonces_array_index = pattern_asic_nonces_array_index + 1) {
              pjVar15 = json_array_get(pjVar8,pattern_asic_nonces_array_index);
              pattern_asic_nonces_array[pattern_asic_nonces_array_index] = pjVar15;
              if ((pattern_asic_nonces_array[pattern_asic_nonces_array_index] == (json_t *)0x0) ||
                 (pattern_asic_nonces_array[pattern_asic_nonces_array_index]->type != JSON_INTEGER))
              {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t find asic_nonces[%d] in pattern\n",
                       "prepare_MES_system_submit_information",pattern_asic_nonces_array_index);
                snprintf(tmp1,0x100,"Can\'t find asic_nonces[%d] in pattern",
                         pattern_asic_nonces_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              if (sweep_mode) {
                get_succ_asic_nonce_num((uint16_t *)tmp1,0x100);
                json_integer_set(pattern_asic_nonces_array[pattern_asic_nonces_array_index],
                                 (ulonglong)*(ushort *)(tmp1 + pattern_asic_nonces_array_index * 2))
                ;
                print_time_stamp(time_stamp_85,0x30);
                printf("%s ",time_stamp_85);
                jVar19 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                printf("%s : sensors->asic_nonces[%d]: %d\n","prepare_MES_system_submit_information"
                       ,pattern_asic_nonces_array_index,(int)jVar19);
                jVar19 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                snprintf(time_stamp,0x100,"sensors->asic_nonces[%d]: %d",
                         pattern_asic_nonces_array_index,(int)jVar19);
                log_to_file(time_stamp,time_stamp_85);
              }
              else {
                json_integer_set(pattern_asic_nonces_array[pattern_asic_nonces_array_index],
                                 (ulonglong)
                                 gHistory_Result[test_loop_index].every_asic_got_nonce_num
                                 [pattern_asic_nonces_array_index]);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                jVar19 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                printf("%s : sensors->asic_nonces[%d]: %d\n","prepare_MES_system_submit_information"
                       ,pattern_asic_nonces_array_index,(int)jVar19);
                jVar19 = json_integer_value(pattern_asic_nonces_array
                                            [pattern_asic_nonces_array_index]);
                snprintf(tmp1,0x100,"sensors->asic_nonces[%d]: %d",pattern_asic_nonces_array_index,
                         (int)jVar19);
                log_to_file(tmp1,time_stamp);
              }
            }
            pjVar6 = json_object_get(pjVar6,"commons");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_ARRAY)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out commons in %s\n","prepare_MES_system_submit_information",
                     "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              snprintf(tmp1,0x100,"Can\'t read out commons in %s",
                       "/mnt/card/Config/MES_system/MES_system_submit_result_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
              goto LAB_0004e76e;
            }
            sVar10 = json_array_size(pjVar6);
            for (commons_array_index = 0; commons_array_index < sVar10;
                commons_array_index = commons_array_index + 1) {
              pjVar8 = json_array_get(pjVar6,commons_array_index);
              commons_array[commons_array_index] = pjVar8;
              if ((commons_array[commons_array_index] == (json_t *)0x0) ||
                 (commons_array[commons_array_index]->type != JSON_OBJECT)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out commons[%d]\n","prepare_MES_system_submit_information",
                       commons_array_index);
                snprintf(tmp1,0x100,"Can\'t read out commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              pjVar8 = json_object_get(commons_array[commons_array_index],"name");
              if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out name in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x100,"Can\'t read out name in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar4 = json_string_value(pjVar8);
              printf("%s : commons[%d]->name: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar4);
              pcVar4 = json_string_value(pjVar8);
              snprintf(tmp1,0x100,"commons[%d]->name: %s",commons_array_index,pcVar4);
              log_to_file(tmp1,time_stamp);
              pjVar15 = json_object_get(commons_array[commons_array_index],"code");
              if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out code in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x100,"Can\'t read out code in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              json_string_set(pjVar15,"0");
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar4 = json_string_value(pjVar15);
              printf("%s : commons[%d]->code: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar4);
              pcVar4 = json_string_value(pjVar15);
              snprintf(tmp1,0x100,"commons[%d]->code: %s",commons_array_index,pcVar4);
              log_to_file(tmp1,time_stamp);
              pjVar15 = json_object_get(commons_array[commons_array_index],"msg");
              if ((pjVar15 == (json_t *)0x0) || (pjVar15->type != JSON_STRING)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out msg in commons[%d]\n",
                       "prepare_MES_system_submit_information",commons_array_index);
                snprintf(tmp1,0x100,"Can\'t read out msg in commons[%d]",commons_array_index);
                log_to_file(tmp1,time_stamp);
                ret = false;
                goto LAB_0004e76e;
              }
              pcVar4 = json_string_value(pjVar8);
              iVar9 = strcmp(pcVar4,"eeprom");
              if (iVar9 == 0) {
                if ((test_result & 4) == 0) {
                  json_string_set(pjVar15,"ng");
                }
                else {
                  json_string_set(pjVar15,"ok");
                }
              }
              pcVar4 = json_string_value(pjVar8);
              iVar9 = strcmp(pcVar4,"pic");
              if (iVar9 == 0) {
                if (gHistory_Result[gPattern_test_counter].pic_ok == false) {
                  json_string_set(pjVar15,"ng");
                }
                else {
                  json_string_set(pjVar15,"ok");
                }
              }
              pcVar4 = json_string_value(pjVar8);
              iVar9 = strcmp(pcVar4,"power");
              if (iVar9 == 0) {
                if (gHistory_Result[gPattern_test_counter].apw_power_ok == false) {
                  json_string_set(pjVar15,"ng");
                }
                else {
                  json_string_set(pjVar15,"ok");
                }
                if (sweep_mode) {
                  json_string_set(pjVar15,"ok");
                }
              }
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              pcVar4 = json_string_value(pjVar15);
              printf("%s : commons[%d]->msg: %s\n","prepare_MES_system_submit_information",
                     commons_array_index,pcVar4);
              pcVar4 = json_string_value(pjVar15);
              snprintf(tmp1,0x100,"commons[%d]->msg: %s",commons_array_index,pcVar4);
              log_to_file(tmp1,time_stamp);
            }
          }
          pcVar4 = json_dumps(json,0);
          mes_system_submit_result_file_length = strlen(pcVar4);
          memcpy(submit_result_handshake_information,pcVar4,mes_system_submit_result_file_length);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : size: %d, content: %s\n","prepare_MES_system_submit_information",
                 mes_system_submit_result_file_length,submit_result_handshake_information);
          snprintf(tmp1,0x100,"size: %d, content: %s",mes_system_submit_result_file_length,
                   submit_result_handshake_information);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
  }
LAB_0004e76e:
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  return ret;
}

