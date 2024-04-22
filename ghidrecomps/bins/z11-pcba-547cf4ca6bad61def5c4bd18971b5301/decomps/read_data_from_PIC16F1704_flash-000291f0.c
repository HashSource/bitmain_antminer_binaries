
undefined4
read_data_from_PIC16F1704_flash(undefined param_1,undefined param_2,void *param_3,byte param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_448 [1024];
  undefined4 local_48;
  int local_44;
  byte local_40 [40];
  undefined2 local_18;
  byte local_14;
  byte local_13;
  ushort local_12;
  
  local_14 = 6;
  local_18 = 0xff;
  memset(local_40,0,0x28);
  local_40[0] = 0xff;
  local_12 = 0;
  local_48 = 0;
  local_44 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_448,0x400,"\n--- %s\n","read_data_from_PIC16F1704_flash");
    _applog(2,acStack_448,0);
  }
  local_12 = (ushort)param_4 + (ushort)local_14 + 0x34;
  local_18._0_1_ = (byte)(local_12 >> 8);
  local_18._1_1_ = (byte)local_12;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_448,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "read_data_from_PIC16F1704_flash",(uint)(byte)local_18,(uint)(byte)local_12);
    _applog(2,acStack_448,0);
  }
  local_48 = CONCAT13(0x34,CONCAT12(local_14,0xaa55));
  local_44 = (uint)CONCAT12(local_18._1_1_,CONCAT11((byte)local_18,param_4)) << 8;
  for (local_13 = 0; local_13 < 8; local_13 = local_13 + 1) {
    printf("%02x ",(uint)*(byte *)((int)&local_48 + (uint)local_13));
  }
  putchar(10);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; local_13 < 8; local_13 = local_13 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_48 + (uint)local_13));
  }
  usleep(200000);
  for (local_13 = 0; (uint)local_13 < param_4 + 5; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    bVar1 = read_pic(param_2,param_1);
    local_40[uVar3] = bVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (local_13 = 0; (uint)local_13 < param_4 + 5; local_13 = local_13 + 1) {
    printf("%02x ",(uint)local_40[local_13]);
  }
  putchar(10);
  if (((local_40[1] == 0x34) && ((uint)local_40[0] == param_4 + 5)) && (local_40[2] == 1)) {
    local_12 = 0;
    for (local_13 = 0; (uint)local_13 < param_4 + 3; local_13 = local_13 + 1) {
      local_12 = local_12 + local_40[local_13];
    }
    if (((byte)(local_12 >> 8) == local_40[param_4 + 3]) &&
       ((byte)local_12 == local_40[param_4 + 4])) {
      memcpy(param_3,local_40 + 3,(uint)param_4);
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
        snprintf(acStack_448,0x400,"\n--- %s ok\n\n","read_data_from_PIC16F1704_flash");
        _applog(2,acStack_448,0);
      }
      uVar2 = 1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_448,0x400,"\n--- %s failed! crc = 0x%04x\n\n",
                 "read_data_from_PIC16F1704_flash",(uint)local_12);
        _applog(0,acStack_448,0);
      }
      uVar2 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_448,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"read_data_from_PIC16F1704_flash",(uint)local_40[0],(uint)local_40[1],
               (uint)local_40[2]);
      _applog(0,acStack_448,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

