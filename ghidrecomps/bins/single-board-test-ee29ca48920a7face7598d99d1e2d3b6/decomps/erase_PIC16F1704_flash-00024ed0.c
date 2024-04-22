
undefined4 erase_PIC16F1704_flash(undefined param_1,undefined param_2)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_424 [1024];
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c = 0xff;
  local_14 = 8;
  local_18 = 0x800;
  local_24 = 0x404aa55;
  local_20 = 0x800;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_24 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((byte)local_1c == 4) && (local_1c._1_1_ == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_424,0x400,"--- %s ok\n\n","erase_PIC16F1704_flash");
      _applog(2,acStack_424,0);
    }
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "erase_PIC16F1704_flash",(uint)(byte)local_1c,(uint)local_1c._1_1_);
      _applog(2,acStack_424,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

