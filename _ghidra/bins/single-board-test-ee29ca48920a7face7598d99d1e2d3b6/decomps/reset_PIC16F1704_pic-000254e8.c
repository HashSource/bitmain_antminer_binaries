
undefined4 reset_PIC16F1704_pic(undefined1 param_1,undefined1 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_424 [1024];
  undefined4 local_24;
  undefined2 local_20;
  byte local_1c [4];
  undefined2 local_18;
  undefined2 local_14;
  undefined1 local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c[0] = 0xff;
  local_1c[1] = 0;
  local_14 = 0xb;
  local_18 = 0xb00;
  local_24 = 0x704aa55;
  local_20 = 0xb00;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,*(undefined1 *)((int)&local_24 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    bVar1 = read_pic(param_2,param_1);
    local_1c[uVar3] = bVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(1000000);
  if ((local_1c[0] == 7) && (local_1c[1] == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_424,0x400,"--- %s ok\n\n","reset_PIC16F1704_pic");
      _applog(2,acStack_424,0);
    }
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "reset_PIC16F1704_pic",(uint)local_1c[0],(uint)local_1c[1]);
      _applog(2,acStack_424,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

