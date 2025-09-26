
_Bool prepare_MES_system_handshake_information(uint32_t which_information)

{
  byte bVar1;
  json_t *pjVar2;
  json_t *pjVar3;
  uint32_t which_information_local;
  char time_stamp [48];
  char tmp1 [2048];
  char data [10];
  json_error_t error;
  json_t *array_table [1];
  json_t *config_ids;
  json_t *software_commit_id;
  json_t *params;
  _Bool ret;
  char *template_ptr;
  json_t *Config_File;
  
  Config_File = (json_t *)0x0;
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
  template_ptr = (char *)0x0;
  memset(download_configuration_handshake_information,0,200);
  if (which_information == 0) {
    Config_File = json_load_file("/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini"
                                 ,0,&error);
    if ((Config_File == (json_t *)0x0) || (Config_File->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t read out %s file.\n","prepare_MES_system_handshake_information",
             "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
      snprintf(tmp1,0x800,"Can\'t read out %s file.",
               "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      template_ptr = json_dumps(Config_File,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: content: %s\n","prepare_MES_system_handshake_information",template_ptr);
      snprintf(tmp1,0x800,"content: %s",template_ptr);
      log_to_file(tmp1,time_stamp);
      pjVar2 = json_object_get(Config_File,"params");
      if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t read out params in %s\n","prepare_MES_system_handshake_information",
               "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
        snprintf(tmp1,0x800,"Can\'t read out params in %s",
                 "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        pjVar3 = json_object_get(pjVar2,"software_commit_id");
        if ((pjVar3 == (json_t *)0x0) || (pjVar3->type != JSON_STRING)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Can\'t read out software_commit_id in %s\n",
                 "prepare_MES_system_handshake_information",
                 "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
          snprintf(tmp1,0x800,"Can\'t read out software_commit_id in %s",
                   "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          json_string_set(pjVar3,zhiju_software_commit_id);
          pjVar2 = json_object_get(pjVar2,"config_ids");
          if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_ARRAY)) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Can\'t read out config_ids in %s\n",
                   "prepare_MES_system_handshake_information",
                   "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
            snprintf(tmp1,0x800,"Can\'t read out config_ids in %s",
                     "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
            log_to_file(tmp1,time_stamp);
            ret = false;
          }
          else {
            pjVar2 = json_array_get(pjVar2,0);
            if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Can\'t read out array_table in config_ids in %s\n",
                     "prepare_MES_system_handshake_information",
                     "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
              snprintf(tmp1,0x800,"Can\'t read out array_table in config_ids in %s",
                       "/mnt/card/Config/MES_system/MES_system_get_all_config_template.ini");
              log_to_file(tmp1,time_stamp);
              ret = false;
            }
            else {
              pjVar3 = json_object_get(pjVar2,"miner_type");
              json_string_set(pjVar3,(Local_Config_Information->Hash_Board).Miner_Type);
              pjVar2 = json_object_get(pjVar2,"board_name");
              json_string_set(pjVar2,(Local_Config_Information->Hash_Board).Board_Name);
              template_ptr = json_dumps(Config_File,0);
              mes_system_handshake_file_length = strlen(template_ptr);
              memcpy(download_configuration_handshake_information,template_ptr,
                     mes_system_handshake_file_length);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: size: %d, content: %s\n","prepare_MES_system_handshake_information",
                     mes_system_handshake_file_length,download_configuration_handshake_information);
              snprintf(tmp1,0x800,"size: %d, content: %s",mes_system_handshake_file_length,
                       download_configuration_handshake_information);
              log_to_file(tmp1,time_stamp);
              ret = true;
            }
          }
        }
      }
    }
  }
  else if (which_information == 1) {
    Config_File = json_load_file("/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini"
                                 ,0,&error);
    if ((Config_File == (json_t *)0x0) || (Config_File->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t read out %s file.\n","prepare_MES_system_handshake_information",
             "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
      snprintf(tmp1,0x800,"Can\'t read out %s file.",
               "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      template_ptr = json_dumps(Config_File,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: content: %s\n","prepare_MES_system_handshake_information",template_ptr);
      snprintf(tmp1,0x800,"content: %s",template_ptr);
      log_to_file(tmp1,time_stamp);
      pjVar2 = json_object_get(Config_File,"params");
      if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t read out params in %s\n","prepare_MES_system_handshake_information",
               "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
        snprintf(tmp1,0x800,"Can\'t read out params in %s",
                 "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        pjVar2 = json_object_get(pjVar2,"config_ids");
        if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_ARRAY)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Can\'t read out config_ids in %s\n","prepare_MES_system_handshake_information"
                 ,"/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
          snprintf(tmp1,0x800,"Can\'t read out config_ids in %s",
                   "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          pjVar2 = json_array_get(pjVar2,0);
          if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Can\'t read out array_table in config_ids in %s\n",
                   "prepare_MES_system_handshake_information",
                   "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
            snprintf(tmp1,0x800,"Can\'t read out array_table in config_ids in %s",
                     "/mnt/card/Config/MES_system/MES_system_get_particular_config_template.ini");
            log_to_file(tmp1,time_stamp);
            ret = false;
          }
          else {
            pjVar3 = json_object_get(pjVar2,"miner_type");
            json_string_set(pjVar3,(Local_Config_Information->Hash_Board).Miner_Type);
            pjVar3 = json_object_get(pjVar2,"board_name");
            json_string_set(pjVar3,(Local_Config_Information->Hash_Board).Board_Name);
            pjVar3 = json_object_get(pjVar2,"sn");
            json_string_set(pjVar3,sn.board_sn);
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,5,2,data);
            pjVar3 = json_object_get(pjVar2,"chip_technology");
            json_string_set(pjVar3,data);
            pjVar3 = json_object_get(pjVar2,"ft_version");
            json_string_set(pjVar3,qr_code.chip_ftversion);
            pjVar3 = json_object_get(pjVar2,"bin");
            bVar1 = get_chip_bin(&qr_code);
            json_integer_set(pjVar3,(ulonglong)bVar1);
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,0,3,data);
            pjVar3 = json_object_get(pjVar2,"hardware_version");
            json_string_set(pjVar3,data);
            memset(data,0x30,10);
            substr(qr_code.hashboard_ctrl_code,3,2,data);
            pjVar2 = json_object_get(pjVar2,"bom_version");
            json_string_set(pjVar2,data);
            template_ptr = json_dumps(Config_File,0);
            mes_system_handshake_file_length = strlen(template_ptr);
            memcpy(download_configuration_handshake_information,template_ptr,
                   mes_system_handshake_file_length);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: size: %d, content: %s\n","prepare_MES_system_handshake_information",
                   mes_system_handshake_file_length,download_configuration_handshake_information);
            snprintf(tmp1,0x800,"size: %d, content: %s",mes_system_handshake_file_length,
                     download_configuration_handshake_information);
            log_to_file(tmp1,time_stamp);
            ret = true;
          }
        }
      }
    }
  }
  else if (which_information == 2) {
    Config_File = json_load_file("/mnt/card/Config/MES_system/MES_system_get_version_template.ini",0
                                 ,&error);
    if ((Config_File == (json_t *)0x0) || (Config_File->type != JSON_OBJECT)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t read out %s file.\n","prepare_MES_system_handshake_information",
             "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
      snprintf(tmp1,0x800,"Can\'t read out %s file.",
               "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      template_ptr = json_dumps(Config_File,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: content: %s\n","prepare_MES_system_handshake_information",template_ptr);
      snprintf(tmp1,0x800,"content: %s",template_ptr);
      log_to_file(tmp1,time_stamp);
      pjVar2 = json_object_get(Config_File,"params");
      if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t read out params in %s\n","prepare_MES_system_handshake_information",
               "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
        snprintf(tmp1,0x800,"Can\'t read out params in %s",
                 "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        pjVar2 = json_object_get(pjVar2,"config_ids");
        if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_ARRAY)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Can\'t read out configIds in %s\n","prepare_MES_system_handshake_information",
                 "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
          snprintf(tmp1,0x800,"Can\'t read out configIds in %s",
                   "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          pjVar2 = json_array_get(pjVar2,0);
          if ((pjVar2 == (json_t *)0x0) || (pjVar2->type != JSON_OBJECT)) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Can\'t read out array_table in configIds in %s\n",
                   "prepare_MES_system_handshake_information",
                   "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
            snprintf(tmp1,0x800,"Can\'t read out array_table in configIds in %s",
                     "/mnt/card/Config/MES_system/MES_system_get_version_template.ini");
            log_to_file(tmp1,time_stamp);
            ret = false;
          }
          else {
            pjVar3 = json_object_get(pjVar2,"miner_type");
            json_string_set(pjVar3,(Local_Config_Information->Hash_Board).Miner_Type);
            pjVar2 = json_object_get(pjVar2,"board_name");
            json_string_set(pjVar2,(Local_Config_Information->Hash_Board).Board_Name);
            template_ptr = json_dumps(Config_File,0);
            mes_system_handshake_file_length = strlen(template_ptr);
            memcpy(download_configuration_handshake_information,template_ptr,
                   mes_system_handshake_file_length);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: size: %d, content: %s\n","prepare_MES_system_handshake_information",
                   mes_system_handshake_file_length,download_configuration_handshake_information);
            snprintf(tmp1,0x800,"size: %d, content: %s",mes_system_handshake_file_length,
                     download_configuration_handshake_information);
            log_to_file(tmp1,time_stamp);
            ret = true;
          }
        }
      }
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Do not support get information type %d from MES system\n",
           "prepare_MES_system_handshake_information",which_information);
    snprintf(tmp1,0x800,"Do not support get information type %d from MES system",which_information);
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  if (Config_File != (json_t *)0x0) {
    json_decref(Config_File);
  }
  if (template_ptr != (char *)0x0) {
    free(template_ptr);
  }
  if (ret != true) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"prepare MES");
    lcd_show(2,"handshake infor");
    lcd_show(3,"fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: prepare MES system handshake information fail\n",
           "prepare_MES_system_handshake_information");
    builtin_strncpy(tmp1,"prepare MES system handshake information fai",0x2c);
    tmp1[0x2c] = 'l';
    tmp1[0x2d] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return ret;
}

