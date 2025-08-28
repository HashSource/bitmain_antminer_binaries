
undefined4 write_data_into_PIC16F1704_flash(undefined1 param_1,undefined1 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_24;
  undefined2 local_20;
  byte local_1c [4];
  undefined2 local_18;
  undefined2 local_14;
  undefined1 local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c[0] = 0xff;
  local_1c[1] = 0;
  local_14 = 9;
  local_18 = 0x900;
  local_24 = 0x504aa55;
  local_20 = 0x900;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined1 *)((int)&local_24 + (uint)local_11));
  }
  usleep(200000);
  for (local_11 = 0; local_11 < 2; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    bVar1 = read_pic(param_1,param_2);
    local_1c[uVar3] = bVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((local_1c[0] == 5) && (local_1c[1] == 1)) {
    printf("\n--- %s ok\n\n","write_data_into_PIC16F1704_flash");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
           "write_data_into_PIC16F1704_flash",(uint)local_1c[0],(uint)local_1c[1]);
    uVar2 = 0;
  }
  return uVar2;
}

