
void print_history_result(uint32_t test_loop_counter)

{
  char *pcVar1;
  uint32_t test_loop_counter_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t j;
  uint32_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].asic_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].asic_ok: %s\n","print_history_result",test_loop_counter,pcVar1);
  if (gHistory_Result[test_loop_counter].asic_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].asic_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].nonce_rate_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].nonce_rate_ok: %s\n","print_history_result",test_loop_counter,
         pcVar1);
  if (gHistory_Result[test_loop_counter].nonce_rate_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].nonce_rate_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].eeprom_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].eeprom_ok: %s\n","print_history_result",test_loop_counter,pcVar1)
  ;
  if (gHistory_Result[test_loop_counter].eeprom_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].eeprom_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].pic_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].pic_sensor_all_OK: %s\n","print_history_result",test_loop_counter
         ,pcVar1);
  if (gHistory_Result[test_loop_counter].pic_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].pic_sensor_all_OK: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].asic_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].asic_sensor_all_OK: %s\n","print_history_result",
         test_loop_counter,pcVar1);
  if (gHistory_Result[test_loop_counter].asic_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].asic_sensor_all_OK: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].ctrlboard_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].ctrlborad_sensor_all_OK: %s\n","print_history_result",
         test_loop_counter,pcVar1);
  if (gHistory_Result[test_loop_counter].ctrlboard_sensor_all_OK == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].ctrlborad_sensor_all_OK: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].switch_sensor_all_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].switch_sensor_all_ok: %s\n","print_history_result",
         test_loop_counter,pcVar1);
  if (gHistory_Result[test_loop_counter].switch_sensor_all_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].switch_sensor_all_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].apw_power_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].apw_power_ok: %s\n","print_history_result",test_loop_counter,
         pcVar1);
  if (gHistory_Result[test_loop_counter].apw_power_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].apw_power_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if (gHistory_Result[test_loop_counter].pic_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s : gHistory_Result[%d].pic_ok: %s\n","print_history_result",test_loop_counter,pcVar1);
  if (gHistory_Result[test_loop_counter].pic_ok == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x100,"gHistory_Result[%d].pic_ok: %s",test_loop_counter,pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].nonce_rate: %f\n","print_history_result",test_loop_counter,
         *(undefined4 *)&gHistory_Result[test_loop_counter].nonce_rate,
         *(undefined4 *)&gHistory_Result[test_loop_counter].nonce_rate,
         *(undefined4 *)((int)&gHistory_Result[test_loop_counter].nonce_rate + 4));
  snprintf(tmp1,0x100,"gHistory_Result[%d].nonce_rate: %f",test_loop_counter,
           *(undefined4 *)&gHistory_Result[test_loop_counter].nonce_rate,
           *(undefined4 *)((int)&gHistory_Result[test_loop_counter].nonce_rate + 4));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].level: %d\n","print_history_result",test_loop_counter,
         gHistory_Result[test_loop_counter].level);
  snprintf(tmp1,0x100,"gHistory_Result[%d].level: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].level);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].voltage: %d\n","print_history_result",test_loop_counter,
         gHistory_Result[test_loop_counter].voltage);
  snprintf(tmp1,0x100,"gHistory_Result[%d].voltage: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].voltage);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].pre_open_core_voltage: %d\n","print_history_result",
         test_loop_counter,gHistory_Result[test_loop_counter].pre_open_core_voltage);
  snprintf(tmp1,0x100,"gHistory_Result[%d].pre_open_core_voltage: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].pre_open_core_voltage);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].frequence: %d\n","print_history_result",test_loop_counter,
         gHistory_Result[test_loop_counter].frequence);
  snprintf(tmp1,0x100,"gHistory_Result[%d].frequence: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].frequence);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].valid_nonce_num: %d\n","print_history_result",test_loop_counter,
         gHistory_Result[test_loop_counter].valid_nonce_num);
  snprintf(tmp1,0x100,"gHistory_Result[%d].valid_nonce_num: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].valid_nonce_num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].repeat_nonce_number: %d\n","print_history_result",
         test_loop_counter,gHistory_Result[test_loop_counter].repeat_nonce_number);
  snprintf(tmp1,0x100,"gHistory_Result[%d].repeat_nonce_number: %d",test_loop_counter,
           gHistory_Result[test_loop_counter].repeat_nonce_number);
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
  }
  for (i = 0; i < 0x100; i = i + 1) {
  }
  for (i = 0; i < 4; i = i + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    if (gHistory_Result[test_loop_counter].pic_sensor_OK[i] == false) {
      pcVar1 = "false";
    }
    else {
      pcVar1 = "true";
    }
    printf("%s : gHistory_Result[%d].pic_sensor_OK[%d]: %s\n","print_history_result",
           test_loop_counter,i,pcVar1);
    if (gHistory_Result[test_loop_counter].pic_sensor_OK[i] == false) {
      pcVar1 = "false";
    }
    else {
      pcVar1 = "true";
    }
    snprintf(tmp1,0x100,"gHistory_Result[%d].pic_sensor_OK[%d]: %s",test_loop_counter,i,pcVar1);
    log_to_file(tmp1,time_stamp);
  }
  for (i = 0; i < 0x100; i = i + 1) {
  }
  for (i = 0; i < 2; i = i + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    if (gHistory_Result[test_loop_counter].ctrlboard_sensor_OK[i] == false) {
      pcVar1 = "false";
    }
    else {
      pcVar1 = "true";
    }
    printf("%s : gHistory_Result[%d].ctrlboard_sensor_OK[%d]: %s\n","print_history_result",
           test_loop_counter,i,pcVar1);
    if (gHistory_Result[test_loop_counter].ctrlboard_sensor_OK[i] == false) {
      pcVar1 = "false";
    }
    else {
      pcVar1 = "true";
    }
    snprintf(tmp1,0x100,"gHistory_Result[%d].ctrlboard_sensor_OK[%d]: %s",test_loop_counter,i,pcVar1
            );
    log_to_file(tmp1,time_stamp);
  }
  for (i = 0; i < 4; i = i + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : gHistory_Result[%d].sensor_local_temperature_from_pic[%d]: %d\n",
           "print_history_result",test_loop_counter,i,
           (int)gHistory_Result[test_loop_counter].sensor_local_temperature_from_pic[i]);
    snprintf(tmp1,0x100,"gHistory_Result[%d].sensor_local_temperature_from_pic[%d]: %d",
             test_loop_counter,i,
             (int)gHistory_Result[test_loop_counter].sensor_local_temperature_from_pic[i]);
    log_to_file(tmp1,time_stamp);
  }
  for (i = 0; i < 2; i = i + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : gHistory_Result[%d].sensor_local_temperature_from_ctrlboard[%d]: %d\n",
           "print_history_result",test_loop_counter,i,
           (int)gHistory_Result[test_loop_counter].sensor_local_temperature_from_ctrlboard[i]);
    snprintf(tmp1,0x100,"gHistory_Result[%d].sensor_local_temperature_from_ctrlboard[%d]: %d",
             test_loop_counter,i,
             (int)gHistory_Result[test_loop_counter].sensor_local_temperature_from_ctrlboard[i]);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gHistory_Result[%d].test_standard: %d\n","print_history_result",test_loop_counter,
         (uint)gHistory_Result[test_loop_counter].test_standard);
  snprintf(tmp1,0x100,"gHistory_Result[%d].test_standard: %d",test_loop_counter,
           (uint)gHistory_Result[test_loop_counter].test_standard);
  log_to_file(tmp1,time_stamp);
  return;
}

