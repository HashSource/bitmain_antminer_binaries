
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1391_send_func(void *arg)

{
  uint uVar1;
  uint uVar2;
  work *__dest;
  uint uVar3;
  work *works;
  uchar *puVar4;
  int iVar5;
  uchar *puVar6;
  uint OpenCoreNum4;
  uint OpenCoreNum8;
  uint uVar7;
  uchar *puVar8;
  vil_work_1391 *pvVar9;
  int iVar10;
  uint OpenCoreNum1;
  uint uVar11;
  work *work;
  uint OpenCoreNum2;
  uint uVar12;
  void *__src;
  uchar which_chain;
  uint uVar13;
  uint OpenCoreNum5;
  uint uVar14;
  uint *puVar15;
  work *__src_00;
  uint OpenCoreNum6;
  uint uVar16;
  uint OpenCoreNum7;
  uint uVar17;
  uint *puVar18;
  uchar local_b0;
  int local_98;
  int *local_94;
  vil_work_1391 work_vil_1391;
  uint buf_vil [13];
  
                    /* WARNING: Load size is inaccurate */
  uVar13 = (uint)*arg;
  memset(buf_vil,0,0x34);
  uVar7 = Conf.OpenCoreNum8;
  uVar17 = Conf.OpenCoreNum7;
  uVar16 = Conf.OpenCoreNum6;
  uVar14 = Conf.OpenCoreNum5;
  uVar2 = Conf.OpenCoreNum4;
  uVar3 = Conf.OpenCoreNum3;
  uVar12 = Conf.OpenCoreNum2;
  uVar11 = Conf.OpenCoreNum1;
  if (gBegin_Get_Nonce == false) {
    uVar1 = read_axi_fpga(7);
    write_axi_fpga(7,uVar1 | 0x10000);
    gBegin_Get_Nonce = true;
  }
  iVar10 = 0x20;
  iVar5 = 0;
  do {
    uVar1 = uVar11 & 1;
    uVar11 = uVar11 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar12 & 1;
    uVar12 = uVar12 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar3 & 1;
    uVar3 = uVar3 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar2 & 1;
    uVar2 = uVar2 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar14 & 1;
    uVar14 = uVar14 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar16 & 1;
    uVar16 = uVar16 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar17 & 1;
    uVar17 = uVar17 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    uVar1 = uVar7 & 1;
    uVar7 = uVar7 >> 1;
    if (uVar1 != 0) {
      iVar5 = iVar5 + 1;
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  printf("%s: There are %d cores should be test\n","single_BM1391_send_func");
  if (iVar5 == 0) {
    uVar11 = gSend_Work_Num[uVar13];
  }
  else {
    local_94 = DAT_000127f0;
    local_98 = 0;
    uVar12 = Conf.pattern_number;
    do {
      uVar11 = 0;
      local_94 = local_94 + 1;
      iVar10 = *local_94;
      if (uVar12 != 0) {
        do {
          if (gReadingTemp != false) {
            usleep(500000);
          }
          uVar12 = read_axi_fpga(3);
          if ((1 << gChain & uVar12) == 0) {
            usleep(5000);
          }
          else {
            __src = (void *)(iVar10 + uVar11 * 0x44);
            memset(buf_vil,0,0x34);
            memset(&work_vil_1391,0,0x34);
            local_b0 = (uchar)(uVar13 | 0x80);
            puVar8 = (uchar *)((int)__src + 7);
            puVar6 = (uchar *)((int)__src + 0x13);
            puVar4 = (uchar *)((int)&work_vil_1391.work_count + 3);
            work_vil_1391.work_type = '\x01';
            work_vil_1391.chain_id = local_b0;
            do {
              puVar8 = puVar8 + 1;
              puVar4 = puVar4 + 1;
              *puVar4 = *puVar8;
            } while (puVar6 != puVar8);
            puVar8 = work_vil_1391.data + 0xb;
            do {
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 1;
              *puVar8 = *puVar6;
            } while (puVar8 != work_vil_1391.midstate + 0x1f);
            buf_vil[0] = (uVar13 | 0x80) << 0x10 | 0x1000000;
            puVar15 = buf_vil + 1;
            pvVar9 = &work_vil_1391;
            do {
              puVar18 = &pvVar9->work_count;
              puVar15 = puVar15 + 1;
              *puVar15 = (uint)pvVar9->data[3] |
                         (uint)pvVar9->data[1] << 0x10 | (uint)pvVar9->data[0] << 0x18 |
                         (uint)pvVar9->data[2] << 8;
              pvVar9 = (vil_work_1391 *)puVar18;
            } while (puVar18 != (uint *)(work_vil_1391.data + 4));
            puVar15 = buf_vil + 4;
            pvVar9 = &work_vil_1391;
            do {
              puVar18 = &pvVar9->work_count;
              puVar15 = puVar15 + 1;
              *puVar15 = (uint)pvVar9->midstate[3] |
                         (uint)pvVar9->midstate[1] << 0x10 | (uint)pvVar9->midstate[0] << 0x18 |
                         (uint)pvVar9->midstate[2] << 8;
              pvVar9 = (vil_work_1391 *)puVar18;
            } while (puVar18 != (uint *)(work_vil_1391.midstate + 0xc));
            work_vil_1391.work_count = uVar11;
            buf_vil[1] = uVar11;
            set_TW_write_command(buf_vil);
            pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + uVar13));
            __dest = gWorks_For_Hw_Check[uVar13] + 0x7f;
            do {
              __src_00 = __dest + -1;
              memcpy(__dest,__src_00,0x44);
              __dest = __src_00;
            } while (gWorks_For_Hw_Check[uVar13] != __src_00);
            uVar11 = uVar11 + 1;
            gWork_Num_For_Hw_Check = gWork_Num_For_Hw_Check + 1;
            if (0x7e < gWork_Num_For_Hw_Check) {
              gWork_Num_For_Hw_Check = 0x7f;
            }
            memcpy(gWorks_For_Hw_Check[uVar13],__src,0x44);
            pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + uVar13));
            gSend_Work_Num[uVar13] = gSend_Work_Num[uVar13] + 1;
          }
          uVar12 = Conf.pattern_number;
        } while (uVar11 < Conf.pattern_number);
      }
      local_98 = local_98 + 1;
    } while (iVar5 != local_98);
    uVar12 = uVar12 * iVar5;
    uVar11 = gSend_Work_Num[uVar13];
    if (uVar11 < uVar12) {
      do {
        printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","single_BM1391_send_func",
               uVar13,uVar11,uVar12);
        uVar11 = gSend_Work_Num[uVar13];
        uVar12 = Conf.pattern_number * iVar5;
      } while (uVar11 < uVar12);
    }
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","single_BM1391_send_func",uVar13,uVar11);
  puts("\nsend test pattern done");
  system("date");
  uVar12 = 1;
  putchar(10);
  uVar11 = gValid_Nonce_Num[uVar13];
  while (uVar12 < 3) {
    usleep(1000000);
    while( true ) {
      uVar3 = gValid_Nonce_Num[uVar13];
      uVar12 = uVar12 + 1;
      if (uVar11 == uVar3) break;
      usleep(1000000);
      uVar12 = 0;
      uVar11 = uVar3;
    }
  }
  while (gReadingTemp != false) {
    usleep(10000);
  }
  start_receive = false;
  puts("to stop receive");
  return (void *)0x0;
}

