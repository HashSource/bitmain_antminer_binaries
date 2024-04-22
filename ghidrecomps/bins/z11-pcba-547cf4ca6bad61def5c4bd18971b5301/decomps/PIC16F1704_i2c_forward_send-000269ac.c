
undefined4
PIC16F1704_i2c_forward_send
          (undefined param_1,undefined param_2,char param_3,int param_4,undefined param_5,
          size_t param_6,byte *param_7)

{
  undefined uVar1;
  char acStack_450 [1024];
  undefined local_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  byte local_44 [32];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  ushort local_12;
  
  memset(local_44,0,0x20);
  local_50 = (undefined  [4])0x0;
  local_4c = 0;
  local_48 = 0;
  local_12 = 0;
  local_1c = 0;
  local_44[0] = 0x55;
  local_44[1] = 0xaa;
  local_44[2] = 0;
  local_44[3] = 0x26;
  local_44[4] = (byte)param_4 | param_3 << 1;
  local_44[5] = param_5;
  if (param_4 == 0) {
    local_18 = param_6 + 4;
    memcpy(local_44 + 6,param_7,param_6);
  }
  else {
    local_18 = 5;
    local_44[6] = (char)param_6;
  }
  local_44[2] = (char)local_18 + '\x02';
  for (local_20 = 0; local_20 < local_18; local_20 = local_20 + 1) {
    local_12 = local_12 + local_44[local_20 + 2];
  }
  local_44[local_18 + 2] = (byte)(local_12 >> 8);
  local_44[local_18 + 3] = (byte)local_12;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_1c = 0; local_1c < local_18 + 4; local_1c = local_1c + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_450,0x400,"write pic i2c[%d] %02x\n",local_1c,(uint)local_44[local_1c]);
      _applog(2,acStack_450,0);
    }
    write_pic(param_1,param_2,local_44[local_1c]);
  }
  usleep(200000);
  if (param_4 == 1) {
    for (local_1c = 0; local_1c < (int)(param_6 + 5); local_1c = local_1c + 1) {
      uVar1 = read_pic(param_1,param_2);
      local_50[local_1c] = uVar1;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_450,0x400,"read pic i2c[%d] %02x\n",local_1c,(uint)(byte)local_50[local_1c]
                );
        _applog(2,acStack_450,0);
      }
    }
    for (local_24 = 0; local_24 < (int)(param_6 + 3); local_24 = local_24 + 1) {
      local_12 = local_12 + (byte)local_50[local_24];
    }
    if (local_12 != *(ushort *)(local_50 + param_6 + 3)) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_450,0x400,"crc failed 0x%x\n",(uint)local_12);
        _applog(2,acStack_450,0);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return 0xffffffff;
    }
    if (((((uint)local_50 & 0xff) != local_18 + 2U) || (local_50[1] != '&')) ||
       (local_50[2] != '\x01')) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_450,0x400,"pic read failed %d %d %d\n",(uint)*param_7,(uint)param_7[1],
                 (uint)param_7[2]);
        _applog(2,acStack_450,0);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return 0xffffffff;
    }
    memcpy(param_7,local_50 + 3,param_6);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  return 0;
}

