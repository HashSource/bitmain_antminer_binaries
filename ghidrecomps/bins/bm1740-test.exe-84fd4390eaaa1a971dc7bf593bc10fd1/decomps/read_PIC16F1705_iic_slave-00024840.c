
undefined4 read_PIC16F1705_iic_slave(undefined param_1,undefined param_2,int param_3,byte param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  byte local_e0 [4];
  undefined auStack_dc [96];
  byte local_7c [100];
  undefined2 local_18;
  byte local_14;
  byte local_13;
  short local_12;
  
  local_14 = param_4 + 4;
  local_18 = 0xff;
  memset(local_7c,0,100);
  local_7c[0] = 0xff;
  local_12 = 0;
  memset(local_e0,0,100);
  printf("\n--- %s\n","read_PIC16F1705_iic_slave");
  local_12 = local_14 + 0x26;
  for (local_13 = 0; local_13 < param_4; local_13 = local_13 + 1) {
    local_12 = (ushort)*(byte *)(param_3 + (uint)local_13) + local_12;
  }
  bVar1 = (byte)((ushort)local_12 >> 8);
  local_18 = CONCAT11((byte)local_12,bVar1);
  printf("--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","read_PIC16F1705_iic_slave",(uint)bVar1,
         (uint)(byte)local_12);
  local_e0[0] = 0x55;
  local_e0[1] = 0xaa;
  local_e0[2] = local_14;
  local_e0[3] = 0x26;
  for (local_13 = 0; local_13 < param_4; local_13 = local_13 + 1) {
    auStack_dc[local_13] = *(undefined *)(param_3 + (uint)local_13);
  }
  auStack_dc[param_4] = (undefined)local_18;
  auStack_dc[param_4 + 1] = local_18._1_1_;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; (uint)local_13 < local_14 + 2; local_13 = local_13 + 1) {
    write_pic(param_1,param_2,local_e0[local_13]);
  }
  usleep(200000);
  for (local_13 = 0; (uint)local_13 < *(byte *)(param_3 + 2) + 3; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    bVar1 = read_pic(param_1,param_2);
    local_7c[uVar3] = bVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((local_7c[1] == '&') && (local_7c[2] == '\x01')) {
    printf("\n--- %s ok\n\n","read_PIC16F1705_iic_slave");
    uVar2 = 1;
  }
  else {
    for (local_13 = 0; (uint)local_13 < *(byte *)(param_3 + 2) + 3; local_13 = local_13 + 1) {
      printf("\n--- %s failed! read_back_data[%d] = 0x%02x\n\n","read_PIC16F1705_iic_slave",
             (uint)local_13,(uint)local_7c[local_13]);
    }
    uVar2 = 0;
  }
  return uVar2;
}

