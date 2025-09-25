
_Bool check_asic_sensor_type(char *asic_sensor_type)

{
  int iVar1;
  char *asic_sensor_type_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_data [16];
  
  memset(lcd_data,0,0x10);
  iVar1 = strcmp(asic_sensor_type,"TMP451");
  if ((iVar1 == 0) || (iVar1 = strcmp(asic_sensor_type,"NCT218"), iVar1 == 0)) {
    gAsic_sensor_i2c_addr = 0x98;
  }
  else {
    iVar1 = strcmp(asic_sensor_type,"TMP411B");
    if (iVar1 == 0) {
      gAsic_sensor_i2c_addr = 0x9a;
    }
    else {
      iVar1 = strcmp(asic_sensor_type,"TMP411C");
      if (iVar1 != 0) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Not support");
        lcd_show(2,"asic sensor");
        strcpy(lcd_data,asic_sensor_type);
        lcd_show(3,lcd_data);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Not support the type asic sensor: %s\n","check_asic_sensor_type",
               asic_sensor_type);
        snprintf(tmp1,0x100,"Not support the type asic sensor: %s",asic_sensor_type);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      gAsic_sensor_i2c_addr = 0x9c;
    }
  }
  return true;
}

