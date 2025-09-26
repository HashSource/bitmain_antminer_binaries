
_Bool check_pic_sensor_type(char *pic_sensor_type)

{
  int iVar1;
  _Bool _Var2;
  char *pic_sensor_type_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_data [16];
  
  memset(lcd_data,0,0x10);
  iVar1 = strcmp(pic_sensor_type,"LM75A");
  if ((((((iVar1 == 0) || (iVar1 = strcmp(pic_sensor_type,"TMP75A"), iVar1 == 0)) ||
        (iVar1 = strcmp(pic_sensor_type,"DS75S"), iVar1 == 0)) ||
       ((iVar1 = strcmp(pic_sensor_type,"DS75S+"), iVar1 == 0 ||
        (iVar1 = strcmp(pic_sensor_type,"GM452"), iVar1 == 0)))) ||
      ((iVar1 = strcmp(pic_sensor_type,"CT75"), iVar1 == 0 ||
       ((iVar1 = strcmp(pic_sensor_type,"SD177"), iVar1 == 0 ||
        (iVar1 = strcmp(pic_sensor_type,"GX21M"), iVar1 == 0)))))) ||
     ((iVar1 = strcmp(pic_sensor_type,"NT175"), iVar1 == 0 ||
      (iVar1 = strcmp(pic_sensor_type,"TMP75"), iVar1 != 0)))) {
    gPic_sensor_i2c_addr = 'H';
    gPic_temperature_reg_addr = '\0';
    _Var2 = true;
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Not support");
    lcd_show(2,"pic sensor");
    strcpy(lcd_data,pic_sensor_type);
    lcd_show(3,lcd_data);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Not support the type asic sensor: %s\n","check_pic_sensor_type",pic_sensor_type);
    snprintf(tmp1,0x100,"Not support the type asic sensor: %s",pic_sensor_type);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

