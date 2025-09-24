
_Bool save_MES_system_config_information(uint32_t which_information)

{
  size_t sVar1;
  FILE *__s;
  _Bool _Var2;
  uint32_t which_information_local;
  char time_stamp [48];
  char tmp1 [256];
  FILE *fp;
  
  if (which_information == 0) {
    memset(factory_config_file,0,200);
    strcpy(factory_config_file,base_factory_config_file);
    strcat(factory_config_file,(Local_Config_Information->Hash_Board).Miner_Type);
    sVar1 = strlen(factory_config_file);
    (factory_config_file + sVar1)[0] = '-';
    (factory_config_file + sVar1)[1] = '\0';
    strcat(factory_config_file,(Local_Config_Information->Hash_Board).Board_Name);
  }
  else {
    if (which_information != 1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Don\'t support");
      lcd_show(2,"this type config");
      lcd_show(3,"information");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Don\'t support save this type information. type = %d\n",
             "save_MES_system_config_information",which_information);
      snprintf(tmp1,0x100,"Don\'t support save this type information. type = %d",which_information);
      log_to_file(tmp1,time_stamp);
      return false;
    }
    memset(factory_config_file,0,200);
    strcpy(factory_config_file,base_factory_config_file);
    strcat(factory_config_file,(Local_Config_Information->Hash_Board).Miner_Type);
    sVar1 = strlen(factory_config_file);
    (factory_config_file + sVar1)[0] = '-';
    (factory_config_file + sVar1)[1] = '\0';
    strcat(factory_config_file,(Local_Config_Information->Hash_Board).Board_Name);
    sVar1 = strlen(factory_config_file);
    (factory_config_file + sVar1)[0] = '-';
    (factory_config_file + sVar1)[1] = '\0';
    strcat(factory_config_file,qr_code.chip_ftversion);
    sVar1 = strlen(factory_config_file);
    (factory_config_file + sVar1)[0] = '-';
    (factory_config_file + sVar1)[1] = '\0';
    strcat(factory_config_file,qr_code.chip_bin);
    sVar1 = strlen(factory_config_file);
    (factory_config_file + sVar1)[0] = '-';
    (factory_config_file + sVar1)[1] = '\0';
    strcat(factory_config_file,qr_code.hashboard_ctrl_code);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Save MES system config information into %s\n","save_MES_system_config_information",
         factory_config_file);
  snprintf(tmp1,0x100,"Save MES system config information into %s",factory_config_file);
  log_to_file(tmp1,time_stamp);
  __s = fopen(factory_config_file,"w");
  if (__s == (FILE *)0x0) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"open file to");
    lcd_show(2,"save MES system");
    lcd_show(3,"config info fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Open %s fail\n","save_MES_system_config_information",factory_config_file);
    snprintf(tmp1,0x100,"Open %s fail",factory_config_file);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Open %s success\n","save_MES_system_config_information",factory_config_file);
    snprintf(tmp1,0x100,"Open %s success",factory_config_file);
    log_to_file(tmp1,time_stamp);
    sVar1 = fwrite(MES_system_Config_information,mes_system_config_file_length,1,__s);
    if (sVar1 == 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Write %s success\n","save_MES_system_config_information",factory_config_file);
      snprintf(tmp1,0x100,"Write %s success",factory_config_file);
      log_to_file(tmp1,time_stamp);
      fclose(__s);
      _Var2 = true;
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"write MES system");
      lcd_show(2,"config infor");
      lcd_show(3,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Write %s fail\n","save_MES_system_config_information",factory_config_file);
      snprintf(tmp1,0x100,"Write %s fail",factory_config_file);
      log_to_file(tmp1,time_stamp);
      fclose(__s);
      _Var2 = false;
    }
  }
  return _Var2;
}

