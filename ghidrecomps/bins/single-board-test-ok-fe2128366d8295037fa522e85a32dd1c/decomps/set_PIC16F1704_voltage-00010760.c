
undefined4 set_PIC16F1704_voltage(undefined param_1,undefined param_2,byte param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_24;
  undefined2 local_20;
  undefined local_1e;
  undefined uStack_1d;
  undefined2 local_1c;
  undefined2 local_18;
  short local_14;
  byte local_12;
  byte local_11;
  
  local_12 = 5;
  local_18 = 0xff;
  local_1c = 0xff;
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1e = 0;
  printf("\n--- %s\n","set_PIC16F1704_voltage",0,&uStack_1d);
  local_14 = (ushort)local_12 + (ushort)param_3 + 0x10;
  uVar1 = (undefined)((ushort)local_14 >> 8);
  local_1e = (undefined)local_14;
  local_18 = CONCAT11(local_1e,uVar1);
  local_24 = CONCAT13(0x10,CONCAT12(local_12,0xaa55));
  local_20 = CONCAT11(uVar1,param_3);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 7; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_24 + (uint)local_11));
  }
  usleep(200000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((byte)local_1c == 0x10) && (local_1c._1_1_ == 1)) {
    printf("\n--- %s ok\n\n","set_PIC16F1704_voltage");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "set_PIC16F1704_voltage",(uint)(byte)local_1c,(uint)local_1c._1_1_);
    uVar2 = 0;
  }
  return uVar2;
}

