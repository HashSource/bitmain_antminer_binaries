
/* WARNING: Unknown calling convention */

_Bool prepare_local_config_information(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","prepare_local_config_information");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  _Var1 = malloc_for_local_config_information();
  if (_Var1) {
    _Var1 = parse_local_config_file("/mnt/card/Config.ini");
    if (_Var1) {
      _Var1 = check_config_information((Local_Config_Information->Hash_Board).Asic_Type);
      if (_Var1) {
        _Var1 = true;
      }
      else {
        _Var1 = false;
      }
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"parse local");
      lcd_show(2,"config file");
      lcd_show(3,"fail");
      _Var1 = false;
    }
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"malloc local");
    lcd_show(2,"config file");
    lcd_show(3,"fail");
    _Var1 = false;
  }
  return _Var1;
}

