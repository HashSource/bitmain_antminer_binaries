
/* WARNING: Unknown calling convention */

_Bool download_MES_system_Config_file(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [2048];
  json_error_t error;
  uint32_t length;
  _Bool ret;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","download_MES_system_Config_file");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  _Var1 = create_connection_to_MES_system_by_name(1);
  if (_Var1) {
    _Var1 = send_message_to_bitmain_MES_system
                      (download_configuration_handshake_information,mes_system_handshake_file_length
                      );
    if (_Var1) {
      mes_system_config_file_length = 0;
      if (MES_system_Config_information != (char *)0x0) {
        free(MES_system_Config_information);
        MES_system_Config_information = (char *)0x0;
      }
      MES_system_Config_information =
           receive_message_from_bitmain_MES_system(&mes_system_config_file_length);
      if (MES_system_Config_information == (char *)0x0) {
        _Var1 = false;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Get MES system Config information, and do integrity verification\n",
               "download_MES_system_Config_file");
        memcpy(tmp1,"Get MES system Config information, and do integrity verification",0x41);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: %s\n","download_MES_system_Config_file",MES_system_Config_information);
        snprintf(tmp1,0x800,"%s",MES_system_Config_information);
        log_to_file(tmp1,time_stamp);
        MES_system_config_File =
             json_loadb(MES_system_Config_information,mes_system_config_file_length - 1,0,&error);
        if ((MES_system_config_File == (json_t *)0x0) ||
           (MES_system_config_File->type != JSON_OBJECT)) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"MES config");
          lcd_show(2,"information");
          lcd_show(3,"is not in JSON");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: The received MES system Config information is not in JSON format\n",
                 "download_MES_system_Config_file");
          memcpy(tmp1,"The received MES system Config information is not in JSON format",0x41);
          log_to_file(tmp1,time_stamp);
          _Var1 = false;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: The received MES system Config information is in JSON format\n",
                 "download_MES_system_Config_file");
          builtin_strncpy(tmp1,"The received MES system Config information is in JSON format",0x3c);
          tmp1[0x3c] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var1 = true;
        }
      }
    }
    else {
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

