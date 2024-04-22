
undefined4
read_dc_dc(undefined param_1,undefined param_2,char param_3,undefined param_4,int param_5,
          int param_6)

{
  uint3 uVar1;
  undefined uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_3c;
  uint local_38;
  undefined local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  byte local_1d;
  int local_1c;
  int local_18;
  byte local_13;
  short local_12;
  
  local_1d = 7;
  local_20 = 0xff;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0xff;
  local_12 = 0;
  local_34 = 0;
  local_3c = 0x3207aa55;
  uVar1 = CONCAT12((char)param_6,CONCAT11(param_4,param_3 << 1));
  local_38 = (uint)(uVar1 | 1);
  for (local_18 = 2; local_18 < 7; local_18 = local_18 + 1) {
    local_12 = local_12 + (ushort)*(byte *)((int)&local_3c + local_18);
  }
  uVar2 = (undefined)((ushort)local_12 >> 8);
  local_34 = (undefined)local_12;
  local_20 = CONCAT11(local_34,uVar2);
  local_38 = CONCAT13(uVar2,uVar1) | 1;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; (uint)local_13 < local_1d + 2; local_13 = local_13 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_3c + (uint)local_13));
  }
  usleep(100000);
  memset(&local_30,0,0x10);
  for (local_13 = 0; (int)(uint)local_13 < param_6 + 5; local_13 = local_13 + 1) {
    uVar4 = (uint)local_13;
    uVar2 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_30 + uVar4) = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(1000000);
  if ((local_30._1_1_ == 0x32) && (local_30._2_1_ == 1)) {
    for (local_1c = 0; local_1c < param_6; local_1c = local_1c + 1) {
      *(undefined *)(local_1c + param_5) = *(undefined *)((int)&local_30 + local_1c + 3);
    }
    uVar3 = 0;
  }
  else {
    printf("--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n"
           ,"read_dc_dc",local_30 & 0xff,(uint)local_30._1_1_,(uint)local_30._2_1_,local_30 >> 0x18)
    ;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

