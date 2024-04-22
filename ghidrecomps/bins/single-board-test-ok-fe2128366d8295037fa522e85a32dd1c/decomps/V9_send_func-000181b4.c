
undefined1 * V9_send_func(byte *param_1)

{
  undefined1 *puVar1;
  undefined local_7c [44];
  undefined local_50;
  undefined local_4f;
  undefined local_4e;
  undefined local_4d;
  undefined local_49;
  undefined auStack_48 [12];
  int local_3c;
  int local_38;
  undefined4 local_34;
  byte local_2d;
  byte *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_2d = *param_1;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_2c = param_1;
  memset(local_7c,0,0x40);
  local_7c[0] = 0xff;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_34 = 0;
  memset(local_7c,0,0x40);
  for (local_14 = 0; local_14 < 0x2d; local_14 = local_14 + 1) {
    local_38 = *(int *)(cgpu + (local_14 + 0x402a) * 4 + 4);
    for (local_18 = 0; local_18 < 0x32; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < (uint)Conf._64_4_; local_1c = local_1c + 1) {
        local_3c = local_38 + (local_18 * Conf._64_4_ + local_1c) * 0x74;
        for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
          local_7c[local_20] = *(undefined *)(local_3c + local_20 + 0x14);
        }
        local_34 = *(undefined4 *)(local_3c + 4);
        local_50 = (undefined)((uint)local_34 >> 0x18);
        local_4f = (undefined)((uint)local_34 >> 0x10);
        local_4e = (undefined)((uint)local_34 >> 8);
        local_4d = (undefined)local_34;
        local_49 = (undefined)local_1c;
        for (local_20 = 0; local_20 < 0xc; local_20 = local_20 + 1) {
          auStack_48[local_20] = *(undefined *)(local_3c + local_20 + 8);
        }
        uart_send(local_2d,local_7c,0x40);
        *(int *)(gSend_Work_Num + (uint)local_2d * 4) =
             *(int *)(gSend_Work_Num + (uint)local_2d * 4) + 1;
        usleep(Conf._196_4_);
      }
    }
  }
  while (*(uint *)(gSend_Work_Num + (uint)local_2d * 4) < (uint)(Conf._64_4_ * 0x8ca)) {
    printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","V9_send_func",(uint)local_2d,
           *(undefined4 *)(gSend_Work_Num + (uint)local_2d * 4),Conf._64_4_ * 0x8ca);
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","V9_send_func",(uint)local_2d,
         *(undefined4 *)(gSend_Work_Num + (uint)local_2d * 4));
  puts("\nsend test pattern done");
  system("date");
  putchar(10);
  local_28 = *(int *)(gValid_Nonce_Num + (uint)local_2d * 4);
  while( true ) {
    while (*(int *)(gValid_Nonce_Num + (uint)local_2d * 4) != local_28) {
      local_24 = 0;
      local_28 = *(int *)(gValid_Nonce_Num + (uint)local_2d * 4);
    }
    local_24 = local_24 + 1;
    if (2 < local_24) break;
    usleep(50000);
  }
  puVar1 = &start_receive;
  start_receive = 0;
  puts("to stop receive");
  return puVar1;
}

