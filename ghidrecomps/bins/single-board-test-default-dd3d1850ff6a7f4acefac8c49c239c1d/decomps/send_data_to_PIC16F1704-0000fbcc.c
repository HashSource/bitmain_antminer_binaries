
undefined4 send_data_to_PIC16F1704(undefined param_1,undefined param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_34;
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
  
  local_14 = 0x14;
  local_1c = 0xff;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_12 = 0x16;
  for (local_13 = 0; local_13 < 0x10; local_13 = local_13 + 1) {
    local_12 = (ushort)*(byte *)(param_3 + (uint)local_13) + local_12;
  }
  uVar1 = (undefined)((ushort)local_12 >> 8);
  local_18 = CONCAT11((char)local_12,uVar1);
  local_34 = 0x214aa55;
  for (local_13 = 0; local_13 < 0x10; local_13 = local_13 + 1) {
    *(undefined *)((int)&local_30 + (uint)local_13) = *(undefined *)(param_3 + (uint)local_13);
  }
  local_20 = CONCAT11((char)local_12,uVar1);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; local_13 < 0x16; local_13 = local_13 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_34 + (uint)local_13));
  }
  usleep(100000);
  for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((byte)local_1c == 2) && (local_1c._1_1_ == 1)) {
    printf("\n--- %s ok\n\n","send_data_to_PIC16F1704");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "send_data_to_PIC16F1704",(uint)(byte)local_1c,(uint)local_1c._1_1_);
    uVar2 = 0;
  }
  return uVar2;
}

