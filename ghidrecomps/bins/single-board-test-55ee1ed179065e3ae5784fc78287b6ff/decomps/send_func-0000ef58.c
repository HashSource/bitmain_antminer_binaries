
undefined4 * send_func(byte *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined local_f4;
  byte local_f3;
  undefined auStack_f2 [180];
  undefined local_3e;
  undefined local_3d;
  undefined2 local_3a;
  void *local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_25;
  byte *local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_25 = *param_1;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_2c = 0;
  local_30 = 0;
  local_20 = 0;
  local_24 = param_1;
  memset(&local_f4,0,0xb8);
  for (local_14 = 0; local_14 < (uint)Conf._108_4_; local_14 = local_14 + 1) {
    local_34 = *(int *)(cgpu + (local_14 + 0x20028) * 4);
    for (local_18 = 0; local_18 < (uint)Conf._112_4_; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < (uint)Conf._64_4_; local_1c = local_1c + 1) {
        local_38 = (void *)(local_34 + (local_18 * Conf._64_4_ + local_1c) * 0xcc);
        local_f4 = 0x30;
        bVar1 = (byte)local_1c;
        if ((Conf._116_4_ != 0x6ba) && (bVar1 = local_f3, Conf._116_4_ == 0x6bd)) {
          bVar1 = (byte)local_1c | 0x80;
        }
        local_f3 = bVar1;
        for (local_20 = 0; local_20 < 0xb4; local_20 = local_20 + 1) {
          auStack_f2[local_20] = *(undefined *)((int)local_38 + local_20 + 8);
        }
        auStack_f2[144] = 0;
        local_3a = CRC16(&local_f4,0xb6);
        local_3e = (undefined)((ushort)local_3a >> 8);
        local_3d = (undefined)local_3a;
        dcr_uart_send(local_25,&local_f4,0xb8);
        pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + (uint)local_25 * 0x18));
        for (local_20 = 8; -1 < local_20; local_20 = local_20 + -1) {
          memcpy(gWorks_For_Hw_Check + (uint)local_25 * 0x7f8 + local_20 * 0xcc + 0xcc,
                 gWorks_For_Hw_Check + (uint)local_25 * 0x7f8 + local_20 * 0xcc,0xcc);
        }
        *(char *)((int)&gWork_Num_For_Hw_Check + (uint)local_25) =
             *(char *)((int)&gWork_Num_For_Hw_Check + (uint)local_25) + '\x01';
        if (8 < *(byte *)((int)&gWork_Num_For_Hw_Check + (uint)local_25)) {
          *(undefined *)((int)&gWork_Num_For_Hw_Check + (uint)local_25) = 9;
        }
        memcpy(gWorks_For_Hw_Check + (uint)local_25 * 0x7f8,local_38,0xcc);
        pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + (uint)local_25 * 0x18));
        *(int *)(gSend_Work_Num + (uint)local_25 * 4) =
             *(int *)(gSend_Work_Num + (uint)local_25 * 4) + 1;
        usleep(Conf._200_4_);
      }
    }
  }
  while (*(uint *)(gSend_Work_Num + (uint)local_25 * 4) <
         (uint)(Conf._108_4_ * Conf._112_4_ * Conf._64_4_)) {
    printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","send_func",(uint)local_25,
           *(undefined4 *)(gSend_Work_Num + (uint)local_25 * 4),Conf._108_4_ * Conf._64_4_ * 0x114);
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","send_func",(uint)local_25,
         *(undefined4 *)(gSend_Work_Num + (uint)local_25 * 4));
  puts("\nsend test pattern done");
  system("date");
  putchar(10);
  puVar2 = &start_receive;
  *(undefined *)((int)&start_receive + (uint)local_25) = 0;
  puts("to stop receive");
  return puVar2;
}

