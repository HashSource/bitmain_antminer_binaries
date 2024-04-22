
undefined4 write_PIC16F1705_iic_slave(undefined param_1,undefined param_2,int param_3,byte param_4)

{
  byte bVar1;
  undefined uVar2;
  undefined4 uVar3;
  uint uVar4;
  char acStack_484 [1024];
  byte local_84 [4];
  undefined auStack_80 [96];
  undefined4 local_20;
  byte local_1c;
  undefined2 local_18;
  byte local_14;
  byte local_13;
  short local_12;
  
  local_14 = param_4 + 4;
  local_18 = 0xff;
  local_1c = 0;
  local_20 = 0xff;
  local_12 = 0;
  memset(local_84,0,100);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_484,0x400,"--- %s\n","write_PIC16F1705_iic_slave");
    _applog(2,acStack_484,0);
  }
  local_12 = local_14 + 0x26;
  for (local_13 = 0; local_13 < param_4; local_13 = local_13 + 1) {
    local_12 = local_12 + (ushort)*(byte *)((uint)local_13 + param_3);
  }
  bVar1 = (byte)((ushort)local_12 >> 8);
  local_18 = CONCAT11((byte)local_12,bVar1);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_484,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "write_PIC16F1705_iic_slave",(uint)bVar1,(uint)(byte)local_12);
    _applog(2,acStack_484,0);
  }
  local_84[0] = 0x55;
  local_84[1] = 0xaa;
  local_84[2] = local_14;
  local_84[3] = 0x26;
  for (local_13 = 0; local_13 < param_4; local_13 = local_13 + 1) {
    auStack_80[local_13] = *(undefined *)((uint)local_13 + param_3);
  }
  auStack_80[param_4] = (undefined)local_18;
  auStack_80[param_4 + 1] = local_18._1_1_;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; (uint)local_13 < local_14 + 2; local_13 = local_13 + 1) {
    write_pic(param_1,param_2,local_84[local_13]);
  }
  usleep(200000);
  for (local_13 = 0; local_13 < 5; local_13 = local_13 + 1) {
    uVar4 = (uint)local_13;
    uVar2 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_20 + uVar4) = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((local_20._1_1_ == 0x26) && (local_20._2_1_ == 1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
      snprintf(acStack_484,0x400,"--- %s ok\n\n","write_PIC16F1705_iic_slave");
      _applog(2,acStack_484,0);
    }
    uVar3 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_484,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x, read_back_data[4] = 0x%02x\n\n"
               ,"write_PIC16F1705_iic_slave",local_20 & 0xff,(uint)local_20._1_1_,
               (uint)local_20._2_1_,local_20 >> 0x18,(uint)local_1c);
      _applog(2,acStack_484,0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

