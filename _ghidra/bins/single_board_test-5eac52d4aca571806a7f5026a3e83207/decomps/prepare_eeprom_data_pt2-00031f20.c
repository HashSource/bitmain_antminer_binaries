
_Bool prepare_eeprom_data_pt2(uint32_t test_loop_index,_Bool pass)

{
  int iVar1;
  char *pcVar2;
  double dVar3;
  uint16_t local_25c;
  _Bool pass_local;
  uint32_t test_loop_index_local;
  char time_stamp [48];
  char tmp1 [256];
  char buf [256];
  size_t len;
  uint32_t frequency;
  uint32_t voltage;
  uint32_t level;
  _Bool temp;
  uint32_t i;
  
  temp = true;
  if (eeprom_ctx.pt2_store == (_func_int_eeprom_v1_t_ptr *)0x0) {
    eeprom_v1_init(&eeprom_ctx,(uint8_t)gChain,eeprom_nonce);
    eeprom_ctx.data.field_2.format_v1.pt2.pt2_count = '\0';
  }
  eeprom_ctx.data.field_2.format_v1.pt2.voltage = (uint16_t)gHistory_Result[test_loop_index].voltage
  ;
  eeprom_ctx.data.field_2.format_v1.pt2.frequency =
       (uint16_t)gHistory_Result[test_loop_index].frequence;
  dVar3 = gHistory_Result[test_loop_index].nonce_rate * 10000.0;
  local_25c = (ushort)(0.0 < dVar3) * (short)(longlong)dVar3;
  eeprom_ctx.data.field_2.format_v1.pt2.nonce_rate = local_25c;
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    for (i = 0; i < gPic_sensor_num; i = i + 1) {
      temp = (gHistory_Result[test_loop_index].pic_sensor_OK[i] & temp) != 0;
    }
    if (temp == false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %d PIC sensors are not all ok. They are: \n","prepare_eeprom_data_pt2",
             gPic_sensor_num);
      snprintf(tmp1,0x100,"%d PIC sensors are not all ok. They are: ",gPic_sensor_num);
      log_to_file(tmp1,time_stamp);
      for (i = 0; i < gPic_sensor_num; i = i + 1) {
        if (gHistory_Result[test_loop_index].pic_sensor_OK[i] == false) {
          pcVar2 = "false";
        }
        else {
          pcVar2 = "true";
        }
        printf("%s ",pcVar2);
      }
      putchar(10);
      return true;
    }
    eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_in =
         get_min_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_pic,
                       (uint8_t)gPic_sensor_num);
    eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_out =
         get_max_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_pic,
                       (uint8_t)gPic_sensor_num);
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false) {
    for (i = 0; i < gCtrlBoard_sensor_num; i = i + 1) {
      temp = (gHistory_Result[test_loop_index].ctrlboard_sensor_OK[i] & temp) != 0;
    }
    if (temp == false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %d PIC sensors are not all ok. They are: \n","prepare_eeprom_data_pt2",
             gCtrlBoard_sensor_num);
      snprintf(tmp1,0x100,"%d PIC sensors are not all ok. They are: ",gCtrlBoard_sensor_num);
      log_to_file(tmp1,time_stamp);
      for (i = 0; i < gPic_sensor_num; i = i + 1) {
        if (gHistory_Result[test_loop_index].ctrlboard_sensor_OK[i] == false) {
          pcVar2 = "false";
        }
        else {
          pcVar2 = "true";
        }
        printf("%s ",pcVar2);
      }
      putchar(10);
      return true;
    }
    eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_in =
         get_min_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_ctrlboard,
                       (uint8_t)gCtrlBoard_sensor_num);
    eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_out =
         get_max_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_ctrlboard,
                       (uint8_t)gCtrlBoard_sensor_num);
  }
  iVar1 = atoi((Local_Config_Information->Test_Info).Test_Config_Data_Version);
  eeprom_ctx.data.field_2.format_v1.pt2.test_version = (uint8_t)iVar1;
  eeprom_ctx.data.field_2.format_v1.pt2.test_standard =
       gHistory_Result[test_loop_index].test_standard;
  eeprom_ctx.data.field_2.format_v1.pt2.pt2_count =
       eeprom_ctx.data.field_2.format_v1.pt2.pt2_count + '\x01';
  eeprom_ctx.data.field_2.format_v1.pt2.pt2_result = pass;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom version: %d\n","prepare_eeprom_data_pt2",(uint)eeprom_ctx.data.version);
  snprintf(tmp1,0x100,"pt2 eeprom version: %d",(uint)eeprom_ctx.data.version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom board_name: %s\n","prepare_eeprom_data_pt2",0xb2715d);
  snprintf(tmp1,0x100,"pt2 eeprom board_name: %s",0xb2715d);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom voltage: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.voltage);
  snprintf(tmp1,0x100,"pt2 eeprom voltage: %d",(uint)eeprom_ctx.data.field_2.format_v1.pt2.voltage);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom frequency: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.frequency);
  snprintf(tmp1,0x100,"pt2 eeprom frequency: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.frequency);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom nonce_rate: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.nonce_rate);
  snprintf(tmp1,0x100,"pt2 eeprom nonce_rate: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.nonce_rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom pcb_temp_in: %d\n","prepare_eeprom_data_pt2",
         (int)eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_in);
  snprintf(tmp1,0x100,"pt2 eeprom pcb_temp_in: %d",
           (int)eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_in);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom pcb_temp_out: %d\n","prepare_eeprom_data_pt2",
         (int)eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_out);
  snprintf(tmp1,0x100,"pt2 eeprom pcb_temp_out: %d",
           (int)eeprom_ctx.data.field_2.format_v1.pt2.pcb_temp_out);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom pt2_result: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_result);
  snprintf(tmp1,0x100,"pt2 eeprom pt2_result: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_result);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom pt2_count: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_count);
  snprintf(tmp1,0x100,"pt2 eeprom pt2_count: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_count);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom test_version: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.test_version);
  snprintf(tmp1,0x100,"pt2 eeprom test_version: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.test_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt2 eeprom test_standard: %d\n","prepare_eeprom_data_pt2",
         (uint)eeprom_ctx.data.field_2.format_v1.pt2.test_standard);
  snprintf(tmp1,0x100,"pt2 eeprom test_standard: %d",
           (uint)eeprom_ctx.data.field_2.format_v1.pt2.test_standard);
  log_to_file(tmp1,time_stamp);
  return true;
}

