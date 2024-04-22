
undefined4 enable_PIC16F1704_dc_dc(undefined param_1,undefined param_2,byte param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_424 [1024];
  byte local_24 [8];
  undefined2 local_1c;
  undefined2 local_18;
  short local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 5;
  local_1c = 0xff;
  local_14 = param_3 + 0x1a;
  local_24[5] = (byte)((ushort)local_14 >> 8);
  local_24[6] = (byte)local_14;
  local_18 = CONCAT11(local_24[6],local_24[5]);
  local_24[0] = 0x55;
  local_24[1] = 0xaa;
  local_24[2] = 5;
  local_24[3] = 0x15;
  local_24[4] = param_3;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 7; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,local_24[local_11]);
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((byte)local_1c == 0x15) && (local_1c._1_1_ == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_424,0x400,"--- %s ok\n\n","enable_PIC16F1704_dc_dc");
      _applog(2,acStack_424,0);
    }
    usleep(500000);
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "enable_PIC16F1704_dc_dc",(uint)(byte)local_1c,(uint)local_1c._1_1_);
      _applog(2,acStack_424,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

