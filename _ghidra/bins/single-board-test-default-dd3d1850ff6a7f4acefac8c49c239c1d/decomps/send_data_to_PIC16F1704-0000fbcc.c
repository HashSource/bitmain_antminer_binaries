
undefined4 send_data_to_PIC16F1704(undefined1 param_1,undefined1 param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 uStack_1f;
  byte local_1c [4];
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 local_14;
  byte local_13;
  short local_12;
  
  local_14 = 0x14;
  local_1c[0] = 0xff;
  local_1c[1] = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_12 = 0x16;
  for (local_13 = 0; local_13 < 0x10; local_13 = local_13 + 1) {
    local_12 = (ushort)*(byte *)(param_3 + (uint)local_13) + local_12;
  }
  uVar1 = (undefined1)((ushort)local_12 >> 8);
  _local_18 = CONCAT11((char)local_12,uVar1);
  local_34 = 0x214aa55;
  for (local_13 = 0; local_13 < 0x10; local_13 = local_13 + 1) {
    *(undefined1 *)((int)&local_30 + (uint)local_13) = *(undefined1 *)(param_3 + (uint)local_13);
  }
  _local_20 = CONCAT11((char)local_12,uVar1);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; local_13 < 0x16; local_13 = local_13 + 1) {
    write_pic(param_1,param_2,*(undefined1 *)((int)&local_34 + (uint)local_13));
  }
  usleep(100000);
  for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
    uVar4 = (uint)local_13;
    bVar2 = read_pic(param_1,param_2);
    local_1c[uVar4] = bVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((local_1c[0] == 2) && (local_1c[1] == 1)) {
    printf("\n--- %s ok\n\n","send_data_to_PIC16F1704");
    uVar3 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "send_data_to_PIC16F1704",(uint)local_1c[0],(uint)local_1c[1]);
    uVar3 = 0;
  }
  return uVar3;
}

