
undefined4 heart_beat_PIC16F1704(undefined param_1,undefined param_2)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c = 0;
  local_20 = 0xff;
  local_14 = 0x1a;
  local_18 = 0x1a00;
  local_28 = 0x1604aa55;
  local_24 = 0x1a00;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_28 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_20 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  if ((local_20._1_1_ == '\x16') && (local_20._2_1_ == '\x01')) {
    printf("\n--- %s ok\n\n","heart_beat_PIC16F1704");
    uVar2 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n","heart_beat_PIC16F1704");
    uVar2 = 0;
  }
  return uVar2;
}

