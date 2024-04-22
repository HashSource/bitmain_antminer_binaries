
undefined4 write_temperature_offset_PIC16F1704(undefined param_1,undefined param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  undefined local_14;
  byte local_13;
  short local_12;
  
  local_14 = 0xc;
  local_1c = 0xff;
  local_28 = 0;
  local_24 = 0;
  local_12 = 0x2e;
  for (local_13 = 0; local_13 < 8; local_13 = local_13 + 1) {
    local_12 = (ushort)*(byte *)(param_3 + (uint)local_13) + local_12;
  }
  uVar1 = (undefined)((ushort)local_12 >> 8);
  local_18 = CONCAT11((char)local_12,uVar1);
  local_2c = 0x220caa55;
  for (local_13 = 0; local_13 < 8; local_13 = local_13 + 1) {
    *(undefined *)((int)&local_28 + (uint)local_13) = *(undefined *)(param_3 + (uint)local_13);
  }
  local_20 = CONCAT11((char)local_12,uVar1);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; local_13 < 0xe; local_13 = local_13 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_2c + (uint)local_13));
  }
  usleep(200000);
  for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((byte)local_1c == 0x22) && (local_1c._1_1_ == 1)) {
    printf("\n--- %s ok\n\n","write_temperature_offset_PIC16F1704");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "write_temperature_offset_PIC16F1704",(uint)(byte)local_1c,(uint)local_1c._1_1_);
    uVar2 = 0;
  }
  return uVar2;
}

