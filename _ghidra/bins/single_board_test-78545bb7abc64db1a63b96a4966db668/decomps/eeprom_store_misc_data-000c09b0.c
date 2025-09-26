
/* WARNING: Unknown calling convention */

_Bool eeprom_store_misc_data(void)

{
  int iVar1;
  _Bool _Var2;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 eeprom_tmp;
  int sensor_id;
  
  if (eeprom_ctx.sweep_store == (_func_int_eeprom_v1_t_ptr *)0x0) {
    eeprom_v1_init(&eeprom_ctx,(uint8_t)gChain,eeprom_nonce);
  }
  iVar1 = (*eeprom_ctx.board_name_retrieve)(&eeprom_ctx);
  if (((iVar1 == 0) && (iVar1 = (*eeprom_ctx.version_retrieve)(&eeprom_ctx), iVar1 == 0)) &&
     (iVar1 = (*eeprom_ctx.sweep_retrieve)(&eeprom_ctx), iVar1 == 0)) {
    for (sensor_id = 0;
        sensor_id <
        (int)(uint)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num;
        sensor_id = sensor_id + 1) {
      eeprom_ctx.private.key_raw[sensor_id + -0xf] = (char)sensor_id + 'Z';
    }
    memcpy(&eeprom_tmp.data,&eeprom_ctx.data,0x100);
    iVar1 = (*eeprom_ctx.sweep_store)(&eeprom_ctx);
    if (iVar1 == 0) {
      iVar1 = (*eeprom_ctx.sweep_retrieve)(&eeprom_ctx);
      if (iVar1 == 0) {
        iVar1 = memcmp((void *)((int)&eeprom_ctx.data.field_2 + 0x60),
                       (void *)((int)&eeprom_tmp.data.field_2 + 0x60),0x8f);
        if (iVar1 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sweep write EEPROM success\n\n","eeprom_store_misc_data");
          builtin_strncpy(tmp1,"sweep write EEPROM success\n",0x1c);
          log_to_file(tmp1,time_stamp);
          _Var2 = false;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sweep write EEPROM fail\n\n","eeprom_store_misc_data");
          builtin_strncpy(tmp1,"sweep write EEPROM fail\n",0x18);
          tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          _Var2 = true;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : sweep retrieve EEPROM fail\n\n","eeprom_store_misc_data");
        builtin_strncpy(tmp1,"sweep retrieve EEPROM fail\n",0x1c);
        log_to_file(tmp1,time_stamp);
        _Var2 = true;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep write EEPROM fail\n\n","eeprom_store_misc_data");
      builtin_strncpy(tmp1,"sweep write EEPROM fail\n",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      _Var2 = true;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s version_retrieve failed\n","eeprom_store_misc_data","eeprom_store_misc_data");
    snprintf(tmp1,0x100,"%s version_retrieve failed","eeprom_store_misc_data");
    log_to_file(tmp1,time_stamp);
    _Var2 = true;
  }
  return _Var2;
}

