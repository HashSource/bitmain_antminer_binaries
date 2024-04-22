
undefined4 write_hash_ID_PIC16F1704(undefined param_1,undefined param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_430 [1024];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  undefined local_14;
  byte local_13;
  short local_12;
  
  local_14 = 0x10;
  local_1c = 0xff;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_12 = 0x22;
  for (local_13 = 0; local_13 < 0xc; local_13 = local_13 + 1) {
    local_12 = local_12 + (ushort)*(byte *)((uint)local_13 + param_3);
  }
  uVar1 = (undefined)((ushort)local_12 >> 8);
  local_18 = CONCAT11((char)local_12,uVar1);
  local_30 = 0x1210aa55;
  for (local_13 = 0; local_13 < 0xc; local_13 = local_13 + 1) {
    *(undefined *)((int)&local_2c + (uint)local_13) = *(undefined *)((uint)local_13 + param_3);
  }
  local_20 = CONCAT11((char)local_12,uVar1);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; local_13 < 0x12; local_13 = local_13 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_30 + (uint)local_13));
  }
  usleep(400000);
  for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((byte)local_1c == 0x12) && (local_1c._1_1_ == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_430,0x400,"--- %s ok\n\n","write_hash_ID_PIC16F1704");
      _applog(2,acStack_430,0);
    }
    uVar2 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_430,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "write_hash_ID_PIC16F1704",(uint)(byte)local_1c,(uint)local_1c._1_1_);
      _applog(2,acStack_430,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

