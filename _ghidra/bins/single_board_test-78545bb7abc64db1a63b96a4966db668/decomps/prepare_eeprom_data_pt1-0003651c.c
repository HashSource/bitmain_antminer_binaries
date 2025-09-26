
_Bool prepare_eeprom_data_pt1(_Bool pass)

{
  _Bool _Var1;
  byte bVar2;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t i;
  char buf [256];
  uint8_t tmp;
  
  i = 0;
  if (eeprom_ctx.pt1_store == (_func_int_eeprom_v1_t_ptr *)0x0) {
    eeprom_v1_init(&eeprom_ctx,(uint8_t)gChain,eeprom_nonce);
    eeprom_ctx.data.field_2.format_v1.pt1.pt1_count = '\0';
  }
  strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x12),qr_code.factory_job,0x18);
  strncpy((char *)eeprom_ctx.data.field_2.raw,sn.board_sn,0x12);
  strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x2a),qr_code.chip_die,3);
  strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x2d),qr_code.chip_marking,0xe);
  strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x45),qr_code.hashboard_ctrl_code + 5,3);
  _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
  if (_Var1) {
    eeprom_ctx.data.field_2._59_4_ = qr_code.ft_bin_list.ft_value._0_4_;
    eeprom_ctx.data.field_2._63_4_ = qr_code.ft_bin_list.ft_value._4_4_;
    eeprom_ctx.data.field_2._67_2_ = qr_code.ft_bin_list.ft_value._8_2_;
  }
  else {
    strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x3b),qr_code.chip_ftversion,10);
    eeprom_ctx.data.field_2.format_v1.pt1.chip_bin = qr_code.chip_bin[3] + 0xd0;
  }
  bVar2 = get_sensor_type(&qr_code);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
    eeprom_ctx.data.field_2.format_v1.pt1.sensor_type = '\0';
  }
  else {
    eeprom_ctx.data.field_2.format_v1.pt1.sensor_type = bVar2 | 0x80;
    strcpy((Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor.Pic_Sensor_Model,
           qr_code.temp_sensor_type);
  }
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code,3);
  __isoc99_sscanf(buf,&DAT_001f2e98,&i);
  eeprom_ctx.data.field_2.format_v1.pt1.pcb_version = (uint16_t)i;
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 3,2);
  __isoc99_sscanf(buf,&DAT_001f2e98,&i);
  eeprom_ctx.data.field_2.format_v1.pt1.bom_version = (uint8_t)i;
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 5,2);
  strncpy((char *)(eeprom_ctx.data.field_2.raw + 0x45),buf,3);
  strncpy(eeprom_ctx.data.board_name,(Local_Config_Information->Hash_Board).Board_Name,0xf);
  eeprom_ctx.data.field_2.format_v1.pt1.pt1_count =
       eeprom_ctx.data.field_2.format_v1.pt1.pt1_count + '\x01';
  eeprom_ctx.data.version = '\x01';
  eeprom_ctx.data.field_2.format_v1.pt1.pt1_result = pass;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom version: %d\n","prepare_eeprom_data_pt1",(uint)eeprom_ctx.data.version);
  snprintf(tmp1,0x100,"pt1 eeprom version: %d",(uint)eeprom_ctx.data.version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom board_name: %s\n","prepare_eeprom_data_pt1",0x21baead);
  snprintf(tmp1,0x100,"pt1 eeprom board_name: %s",0x21baead);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom board_sn: %s\n","prepare_eeprom_data_pt1",0x21baebc);
  snprintf(tmp1,0x100,"pt1 eeprom board_sn: %s",0x21baebc);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom bom_version: %x\n","prepare_eeprom_data_pt1",
         (uint)eeprom_ctx.data.field_2.format_v1.pt1.bom_version);
  snprintf(tmp1,0x100,"pt1 eeprom bom_version: %x",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.bom_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom chip_die: %s\n","prepare_eeprom_data_pt1",0x21baee6);
  snprintf(tmp1,0x100,"pt1 eeprom chip_die: %s",0x21baee6);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom chip_marking: %s\n","prepare_eeprom_data_pt1",0x21baee9);
  snprintf(tmp1,0x100,"pt1 eeprom chip_marking: %s",0x21baee9);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom chip_tech: %s\n","prepare_eeprom_data_pt1",0x21baf01);
  snprintf(tmp1,0x100,"pt1 eeprom chip_tech: %s",0x21baf01);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom factory_job: %s\n","prepare_eeprom_data_pt1",0x21baece);
  snprintf(tmp1,0x100,"pt1 eeprom factory_job: %s",0x21baece);
  log_to_file(tmp1,time_stamp);
  _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
  if (_Var1) {
    log_out_multiple_ft_bin_info(&qr_code.ft_bin_list);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pt1 eeprom ft_version: %s\n","prepare_eeprom_data_pt1",0x21baef7);
    snprintf(tmp1,0x100,"pt1 eeprom ft_version: %s",0x21baef7);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pt1 eeprom chip_bin: %d\n","prepare_eeprom_data_pt1",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.chip_bin);
    snprintf(tmp1,0x100,"pt1 eeprom chip_bin: %d",
             (uint)eeprom_ctx.data.field_2.format_v1.pt1.chip_bin);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom pcb_version: %x\n","prepare_eeprom_data_pt1",
         (uint)eeprom_ctx.data.field_2.format_v1.pt1.pcb_version);
  snprintf(tmp1,0x100,"pt1 eeprom pcb_version: %x",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.pcb_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom pt1_count: %d\n","prepare_eeprom_data_pt1",
         (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_count);
  snprintf(tmp1,0x100,"pt1 eeprom pt1_count: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_count);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom pt1_result: %d\n","prepare_eeprom_data_pt1",
         (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_result);
  snprintf(tmp1,0x100,"pt1 eeprom pt1_result: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_result);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt1 eeprom sensor_type: %d\n","prepare_eeprom_data_pt1",
         (uint)eeprom_ctx.data.field_2.format_v1.pt1.sensor_type);
  snprintf(tmp1,0x100,"pt1 eeprom sensor_type: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt1.sensor_type);
  log_to_file(tmp1,time_stamp);
  return true;
}

