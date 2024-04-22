
undefined4
write_data_to_PIC16F1704_flash(undefined param_1,undefined param_2,void *param_3,size_t param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_434 [1024];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined local_24;
  undefined2 local_20;
  int local_1c;
  undefined local_15;
  byte local_14;
  byte local_13;
  short local_12;
  
  local_14 = 6;
  local_20 = 0xff;
  local_24 = 0;
  local_28 = 0xff;
  local_12 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_15 = 0;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (3 < opt_log_level)))) {
    snprintf(acStack_434,0x400,"\n--- %s\n","write_data_to_PIC16F1704_flash");
    _applog(4,acStack_434,0);
  }
  local_12 = (short)param_4 * 2 + (ushort)local_14 + 0x33;
  for (local_13 = 0; (int)(uint)local_13 < (int)param_4; local_13 = local_13 + 1) {
    local_12 = local_12 + (ushort)*(byte *)((uint)local_13 + (int)param_3);
  }
  local_20._0_1_ = (byte)((ushort)local_12 >> 8);
  local_20._1_1_ = (byte)local_12;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_434,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "write_data_to_PIC16F1704_flash",(uint)(byte)local_20,(uint)local_20._1_1_);
    _applog(2,acStack_434,0);
  }
  local_34 = CONCAT13(0x33,CONCAT12(local_14 + (char)param_4,0xaa55));
  local_30 = (uint)CONCAT21(local_30._2_2_,(char)param_4) << 8;
  memcpy((void *)((int)&local_30 + 2),param_3,param_4);
  *(byte *)((int)&local_30 + param_4 + 2) = (byte)local_20;
  *(byte *)((int)&local_30 + param_4 + 3) = local_20._1_1_;
  for (local_13 = 0; (int)(uint)local_13 < (int)(param_4 + 8); local_13 = local_13 + 1) {
    printf("%02x ",(uint)*(byte *)((int)&local_34 + (uint)local_13));
  }
  putchar(10);
  local_1c = param_4 + local_14 + 2;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; (int)(uint)local_13 < local_1c; local_13 = local_13 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_34 + (uint)local_13));
  }
  usleep(200000);
  for (local_13 = 0; local_13 < 5; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_28 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (local_13 = 0; local_13 < 5; local_13 = local_13 + 1) {
    printf("%02x ",(uint)*(byte *)((int)&local_28 + (uint)local_13));
  }
  putchar(10);
  if ((((char)local_28 == '\x05') && (local_28._1_1_ == 0x33)) && (local_28._2_1_ == 1)) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_434,0x400,"\n--- %s ok\n\n","write_data_to_PIC16F1704_flash");
      _applog(2,acStack_434,0);
    }
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_434,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"write_data_to_PIC16F1704_flash",local_28 & 0xff,(uint)local_28._1_1_,
               (uint)local_28._2_1_);
      _applog(0,acStack_434,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

