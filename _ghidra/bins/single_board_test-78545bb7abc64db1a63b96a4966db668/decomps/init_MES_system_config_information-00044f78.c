
/* WARNING: Unknown calling convention */

_Bool init_MES_system_config_information(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [256];
  
  if (Mes_System_Config_File_Information == (Mes_System_Config_File_Info *)0x0) {
    Mes_System_Config_File_Information = (Mes_System_Config_File_Info *)malloc(0x68);
    if (Mes_System_Config_File_Information == (Mes_System_Config_File_Info *)0x0) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"malloc for parse");
      lcd_show(2,"MES system");
      lcd_show(3,"information fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : malloc for parse MES system config information fail!\n",
             "init_MES_system_config_information");
      builtin_strncpy(tmp1,"malloc for parse MES system config information fail!",0x34);
      tmp1._52_2_ = (ushort)(byte)tmp1[0x35] << 8;
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
    else {
      memset(Mes_System_Config_File_Information,0,0x68);
      (Mes_System_Config_File_Information->result).configs = (mes_system_configs *)0x0;
      _Var1 = true;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Already malloced parse MES system config information!\n",
           "init_MES_system_config_information");
    builtin_strncpy(tmp1,"Already malloced parse MES system config information",0x34);
    tmp1[0x34] = '!';
    tmp1[0x35] = '\0';
    log_to_file(tmp1,time_stamp);
    _Var1 = true;
  }
  return _Var1;
}

