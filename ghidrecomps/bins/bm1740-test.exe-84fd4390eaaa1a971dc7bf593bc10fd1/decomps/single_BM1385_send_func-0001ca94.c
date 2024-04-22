
undefined1 * single_BM1385_send_func(byte *param_1)

{
  undefined1 *puVar1;
  undefined local_94 [44];
  undefined local_68;
  undefined local_67;
  undefined local_66;
  undefined local_65;
  undefined local_61;
  undefined auStack_60 [12];
  void *local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  byte local_35;
  byte *local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_35 = *param_1;
  local_3c = 0;
  local_40 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_34 = param_1;
  memset(local_94,0,0x40);
  local_94[0] = 0xff;
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  local_20 = Conf._204_4_;
  local_24 = Conf._208_4_;
  local_28 = Conf._212_4_;
  local_2c = Conf._216_4_;
  for (local_30 = 0; local_30 < 0x20; local_30 = local_30 + 1) {
    if ((local_20 & 1) != 0) {
      local_18 = local_18 + 1;
    }
    local_20 = local_20 >> 1;
    if ((local_24 & 1) != 0) {
      local_18 = local_18 + 1;
    }
    local_24 = local_24 >> 1;
    if ((local_28 & 1) != 0) {
      local_18 = local_18 + 1;
    }
    local_28 = local_28 >> 1;
    if ((local_2c & 1) != 0) {
      local_18 = local_18 + 1;
    }
    local_2c = local_2c >> 1;
  }
  printf("%s: There are %d cores should be test\n\n","single_BM1385_send_func",local_18);
  for (local_1c = 0; local_1c < local_18; local_1c = local_1c + 1) {
    local_50 = *(int *)(cgpu + (local_1c + 0x402a) * 4 + 4);
    for (local_14 = 0; local_14 < (uint)Conf._64_4_; local_14 = local_14 + 1) {
      local_54 = (void *)(local_50 + local_14 * 0x38);
      memset(local_94,0,0x40);
      for (local_30 = 0; local_30 < 0x20; local_30 = local_30 + 1) {
        local_94[local_30] = *(undefined *)((int)local_54 + local_30 + 0x14);
      }
      local_4c = *(undefined4 *)((int)local_54 + 4);
      local_68 = (undefined)((uint)local_4c >> 0x18);
      local_67 = (undefined)((uint)local_4c >> 0x10);
      local_66 = (undefined)((uint)local_4c >> 8);
      local_65 = (undefined)local_4c;
      local_61 = (undefined)local_14;
      for (local_30 = 0; local_30 < 0xc; local_30 = local_30 + 1) {
        auStack_60[local_30] = *(undefined *)((int)local_54 + local_30 + 8);
      }
      uart_send(local_35,local_94,0x40);
      pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + (uint)local_35 * 0x18));
      for (local_30 = 8; -1 < local_30; local_30 = local_30 + -1) {
        memcpy(gWorks_For_Hw_Check + (uint)local_35 * 0x230 + local_30 * 0x38 + 0x38,
               gWorks_For_Hw_Check + (uint)local_35 * 0x230 + local_30 * 0x38,0x38);
      }
      gWork_Num_For_Hw_Check = gWork_Num_For_Hw_Check + 1;
      if (8 < gWork_Num_For_Hw_Check) {
        gWork_Num_For_Hw_Check = 9;
      }
      memcpy(gWorks_For_Hw_Check + (uint)local_35 * 0x230,local_54,0x38);
      pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + (uint)local_35 * 0x18));
      (&gSend_Work_Num)[local_35] = (&gSend_Work_Num)[local_35] + 1;
      usleep(Conf._196_4_);
    }
  }
  while ((uint)(&gSend_Work_Num)[local_35] < local_18 * Conf._64_4_) {
    printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","single_BM1385_send_func",
           (uint)local_35,(&gSend_Work_Num)[local_35],Conf._64_4_ * 0x32);
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","single_BM1385_send_func",(uint)local_35,
         (&gSend_Work_Num)[local_35]);
  puts("\nsend test pattern done");
  system("date");
  putchar(10);
  usleep(50000);
  puVar1 = &start_receive;
  start_receive = 0;
  puts("to stop receive");
  return puVar1;
}

