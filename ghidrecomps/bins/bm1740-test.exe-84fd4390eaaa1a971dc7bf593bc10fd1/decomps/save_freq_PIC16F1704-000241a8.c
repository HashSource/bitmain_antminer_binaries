
undefined4 save_freq_PIC16F1704(undefined param_1,undefined param_2,ushort param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  short local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 6;
  local_1c = 0xff;
  local_14 = (param_3 >> 8) + (param_3 & 0xff) + 0x2a;
  uVar1 = (undefined)((ushort)local_14 >> 8);
  local_18 = CONCAT11((char)local_14,uVar1);
  local_24 = 0x2406aa55;
  local_20 = CONCAT13((char)local_14,CONCAT12(uVar1,CONCAT11((char)param_3,(char)(param_3 >> 8))));
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 8; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_24 + (uint)local_11));
  }
  usleep(300000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_1c + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((byte)local_1c == 0x24) && (local_1c._1_1_ == 1)) {
    printf("\n--- %s ok\n\n","save_freq_PIC16F1704");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "save_freq_PIC16F1704",(uint)(byte)local_1c,(uint)local_1c._1_1_);
    uVar2 = 0;
  }
  return uVar2;
}

