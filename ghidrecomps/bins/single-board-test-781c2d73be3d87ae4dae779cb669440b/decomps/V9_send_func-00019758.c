
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * V9_send_func(void *arg)

{
  byte which_uart;
  work *__dest;
  work **works;
  undefined4 uVar1;
  uchar *puVar2;
  uint uVar3;
  int iVar4;
  uchar *puVar5;
  void *__src;
  work *work;
  uint uVar6;
  work *__src_00;
  uchar which_chain;
  uint uVar7;
  int local_7c;
  undefined4 local_6c;
  uchar data_fil [64];
  
                    /* WARNING: Load size is inaccurate */
  which_uart = *arg;
  uVar7 = (uint)which_uart;
  memset(data_fil,0,0x40);
  local_6c = DAT_00019940;
  uVar3 = Conf.pattern_number;
  do {
    local_6c = local_6c + 1;
    iVar4 = *local_6c;
    local_7c = 0;
    do {
      if (uVar3 != 0) {
        uVar6 = 0;
        do {
          puVar2 = (uchar *)((int)&local_6c + 3);
          __src = (void *)(iVar4 + (uVar3 * local_7c + uVar6) * 0x44);
          puVar5 = (uchar *)((int)__src + 0x13);
          do {
            puVar5 = puVar5 + 1;
            puVar2 = puVar2 + 1;
            *puVar2 = *puVar5;
          } while (data_fil + 0x1f != puVar2);
          uVar1 = *(undefined4 *)((int)__src + 4);
          puVar5 = (uchar *)((int)__src + 7);
          puVar2 = data_fil + 0x33;
          data_fil[51] = (uchar)uVar6;
          data_fil[47] = (uchar)uVar1;
          data_fil[44] = (uchar)((uint)uVar1 >> 0x18);
          data_fil[45] = (uchar)((uint)uVar1 >> 0x10);
          data_fil[46] = (uchar)((uint)uVar1 >> 8);
          do {
            puVar5 = puVar5 + 1;
            puVar2 = puVar2 + 1;
            *puVar2 = *puVar5;
          } while (puVar5 != (uchar *)((int)__src + 0x13));
          uart_send(which_uart,data_fil,0x40);
          pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + uVar7));
          __dest = gWorks_For_Hw_Check[uVar7] + 0x7f;
          do {
            __src_00 = __dest + -1;
            memcpy(__dest,__src_00,0x44);
            __dest = __src_00;
          } while (__src_00 != gWorks_For_Hw_Check[uVar7]);
          uVar6 = uVar6 + 1;
          gWork_Num_For_Hw_Check = gWork_Num_For_Hw_Check + 1;
          if (0x7e < gWork_Num_For_Hw_Check) {
            gWork_Num_For_Hw_Check = 0x7f;
          }
          memcpy(gWorks_For_Hw_Check[uVar7],__src,0x44);
          pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + uVar7));
          gSend_Work_Num[uVar7] = gSend_Work_Num[uVar7] + 1;
          usleep(2000);
          uVar3 = Conf.pattern_number;
        } while (uVar6 < Conf.pattern_number);
      }
      local_7c = local_7c + 1;
    } while (local_7c != 0x32);
  } while (local_6c != DAT_00019944);
  uVar6 = gSend_Work_Num[uVar7];
  uVar3 = uVar3 * 0x8ca;
  if (uVar6 < uVar3) {
    do {
      printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","V9_send_func",uVar7,uVar6,
             uVar3);
      uVar6 = gSend_Work_Num[uVar7];
      uVar3 = Conf.pattern_number * 0x8ca;
    } while (uVar6 < uVar3);
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","V9_send_func",uVar7);
  puts("\nsend test pattern done");
  system("date");
  putchar(10);
  usleep(40000);
  start_receive = false;
  puts("to stop receive");
  return (void *)0x0;
}

