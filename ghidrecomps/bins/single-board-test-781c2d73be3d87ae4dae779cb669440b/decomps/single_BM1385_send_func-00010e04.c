
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1385_send_func(void *arg)

{
  byte which_uart;
  uint uVar1;
  uint OpenCoreNum1;
  uint uVar2;
  work *__dest;
  uint OpenCoreNum2;
  uint uVar3;
  undefined4 uVar4;
  uint OpenCoreNum3;
  uint uVar5;
  uchar *puVar6;
  uint OpenCoreNum4;
  uint uVar7;
  uchar *__src;
  work *work;
  uchar *puVar8;
  int iVar9;
  int iVar10;
  work *works;
  uchar *puVar11;
  uchar which_chain;
  uint uVar12;
  work *__src_00;
  int local_70;
  undefined4 local_6c;
  uchar data_fil [64];
  
                    /* WARNING: Load size is inaccurate */
  which_uart = *arg;
  uVar12 = (uint)which_uart;
  memset(data_fil,0,0x40);
  iVar10 = 0x20;
  data_fil[0] = 0xff;
  iVar9 = 0;
  uVar2 = Conf.OpenCoreNum1;
  uVar3 = Conf.OpenCoreNum2;
  uVar5 = Conf.OpenCoreNum3;
  uVar7 = Conf.OpenCoreNum4;
  do {
    uVar1 = uVar2 & 1;
    uVar2 = uVar2 >> 1;
    if (uVar1 != 0) {
      iVar9 = iVar9 + 1;
    }
    uVar1 = uVar3 & 1;
    uVar3 = uVar3 >> 1;
    if (uVar1 != 0) {
      iVar9 = iVar9 + 1;
    }
    uVar1 = uVar5 & 1;
    uVar5 = uVar5 >> 1;
    if (uVar1 != 0) {
      iVar9 = iVar9 + 1;
    }
    uVar1 = uVar7 & 1;
    uVar7 = uVar7 >> 1;
    if (uVar1 != 0) {
      iVar9 = iVar9 + 1;
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  printf("%s: There are %d cores should be test\n\n","single_BM1385_send_func",iVar9);
  if (iVar9 == 0) {
    uVar2 = gSend_Work_Num[uVar12];
  }
  else {
    local_6c = DAT_0001106c;
    local_70 = 0;
    uVar3 = Conf.pattern_number;
    do {
      local_6c = local_6c + 1;
      if (uVar3 != 0) {
        puVar11 = (uchar *)(*local_6c + 0x13);
        uVar2 = 0;
        do {
          __src = puVar11 + -0x13;
          memset(data_fil,0,0x40);
          puVar6 = (uchar *)((int)&local_6c + 3);
          puVar8 = puVar11;
          do {
            puVar8 = puVar8 + 1;
            puVar6 = puVar6 + 1;
            *puVar6 = *puVar8;
          } while (puVar6 != data_fil + 0x1f);
          uVar4 = *(undefined4 *)(puVar11 + -0xf);
          puVar8 = puVar11 + -0xc;
          puVar6 = data_fil + 0x33;
          data_fil[51] = (uchar)uVar2;
          data_fil[47] = (uchar)uVar4;
          data_fil[44] = (uchar)((uint)uVar4 >> 0x18);
          data_fil[45] = (uchar)((uint)uVar4 >> 0x10);
          data_fil[46] = (uchar)((uint)uVar4 >> 8);
          do {
            puVar8 = puVar8 + 1;
            puVar6 = puVar6 + 1;
            *puVar6 = *puVar8;
          } while (puVar8 != puVar11);
          uart_send(which_uart,data_fil,0x40);
          pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + uVar12));
          __dest = gWorks_For_Hw_Check[uVar12] + 0x7f;
          do {
            __src_00 = __dest + -1;
            memcpy(__dest,__src_00,0x44);
            __dest = __src_00;
          } while (gWorks_For_Hw_Check[uVar12] != __src_00);
          uVar2 = uVar2 + 1;
          puVar11 = puVar11 + 0x44;
          gWork_Num_For_Hw_Check = gWork_Num_For_Hw_Check + 1;
          if (0x7e < gWork_Num_For_Hw_Check) {
            gWork_Num_For_Hw_Check = 0x7f;
          }
          memcpy(gWorks_For_Hw_Check[uVar12],__src,0x44);
          pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + uVar12));
          uVar3 = Conf.timeout;
          gSend_Work_Num[uVar12] = gSend_Work_Num[uVar12] + 1;
          usleep(uVar3);
          uVar3 = Conf.pattern_number;
        } while (uVar2 < Conf.pattern_number);
      }
      local_70 = local_70 + 1;
    } while (iVar9 != local_70);
    uVar2 = gSend_Work_Num[uVar12];
    if (uVar2 <= uVar3 * iVar9 && uVar3 * iVar9 - uVar2 != 0) {
      do {
        printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","single_BM1385_send_func",
               uVar12,uVar2,uVar3 * 0x32);
        uVar2 = gSend_Work_Num[uVar12];
        uVar3 = Conf.pattern_number;
      } while (uVar2 < Conf.pattern_number * iVar9);
    }
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","single_BM1385_send_func",uVar12,uVar2);
  puts("\nsend test pattern done");
  system("date");
  putchar(10);
  usleep(50000);
  start_receive = false;
  puts("to stop receive");
  return (void *)0x0;
}

