
undefined4
write_dc_dc(undefined param_1,undefined param_2,byte param_3,undefined param_4,int param_5,
           int param_6)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  local_20 = 0xff;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0xff;
  local_12 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_1d = (char)param_6 + 6;
  printf("%s dev addr = %02x\n","write_dc_dc",(uint)param_3);
  local_40 = CONCAT13(0x32,CONCAT12(local_1d,0xaa55));
  for (local_18 = 0; local_18 < param_6; local_18 = local_18 + 1) {
    *(undefined *)((int)&local_3c + local_18 + 2) = *(undefined *)(local_18 + param_5);
  }
  for (local_1c = 2; local_1c < param_6 + 6; local_1c = local_1c + 1) {
    local_12 = local_12 + (ushort)*(byte *)((int)&local_40 + local_1c);
  }
  local_20._0_1_ = (undefined)((ushort)local_12 >> 8);
  local_20._1_1_ = (undefined)local_12;
  *(undefined *)((int)&local_3c + param_6 + 2) = (undefined)local_20;
  *(undefined *)((int)&local_3c + param_6 + 3) = local_20._1_1_;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_13 = 0; (uint)local_13 < local_1d + 2; local_13 = local_13 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_40 + (uint)local_13));
  }
  usleep(100000);
  memset(&local_30,0,0x10);
  for (local_13 = 0; local_13 < 5; local_13 = local_13 + 1) {
    uVar3 = (uint)local_13;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_30 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((local_30._1_1_ == 0x32) && (local_30._2_1_ == 1)) {
    uVar2 = 0;
  }
  else {
    printf("--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n\n"
           ,"write_dc_dc",local_30 & 0xff,(uint)local_30._1_1_,(uint)local_30._2_1_,local_30 >> 0x18
          );
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

