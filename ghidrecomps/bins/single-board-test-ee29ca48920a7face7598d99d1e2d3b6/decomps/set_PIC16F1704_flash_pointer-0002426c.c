
undefined4
set_PIC16F1704_flash_pointer(undefined param_1,undefined param_2,byte param_3,byte param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_424 [1024];
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  short local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 6;
  local_1c = 0xff;
  local_14 = (ushort)param_4 + (ushort)param_3 + 7;
  uVar1 = (undefined)((ushort)local_14 >> 8);
  local_18 = CONCAT11((char)local_14,uVar1);
  local_24 = 0x106aa55;
  local_20 = CONCAT13((char)local_14,CONCAT12(uVar1,CONCAT11(param_4,param_3)));
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 8; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_24 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((byte)local_1c == 1) && (local_1c._1_1_ == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_424,0x400,"--- %s ok\n\n","set_PIC16F1704_flash_pointer");
      _applog(2,acStack_424,0);
    }
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "set_PIC16F1704_flash_pointer",(uint)(byte)local_1c,(uint)local_1c._1_1_);
      _applog(2,acStack_424,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

