
undefined4
set_PIC16F1704_flash_pointer(undefined1 param_1,undefined1 param_2,byte param_3,byte param_4)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  char acStack_424 [1024];
  undefined4 local_24;
  byte local_20;
  byte bStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  byte local_1c [4];
  undefined1 local_18;
  undefined1 uStack_17;
  short local_14;
  undefined1 local_12;
  byte local_11;
  
  local_12 = 6;
  local_1c[0] = 0xff;
  local_1c[1] = 0;
  local_14 = (ushort)param_4 + (ushort)param_3 + 7;
  uVar1 = (undefined1)((ushort)local_14 >> 8);
  _local_18 = CONCAT11((char)local_14,uVar1);
  local_24 = 0x106aa55;
  _local_20 = CONCAT13((char)local_14,CONCAT12(uVar1,CONCAT11(param_4,param_3)));
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 8; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined1 *)((int)&local_24 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar4 = (uint)local_11;
    bVar2 = read_pic(param_1,param_2);
    local_1c[uVar4] = bVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((local_1c[0] == 1) && (local_1c[1] == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_424,0x400,"--- %s ok\n\n","set_PIC16F1704_flash_pointer");
      _applog(2,acStack_424,0);
    }
    uVar3 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "set_PIC16F1704_flash_pointer",(uint)local_1c[0],(uint)local_1c[1]);
      _applog(2,acStack_424,0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

