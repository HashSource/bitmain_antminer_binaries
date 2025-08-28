
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 doTestBoard_isra_0(void)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  char *__format;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint uVar19;
  int iVar20;
  int *piVar21;
  undefined4 *puVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint *puVar28;
  int *piVar29;
  int *piVar30;
  undefined1 *puVar31;
  uint *puVar32;
  byte *pbVar33;
  bool bVar34;
  uint *local_9e4;
  undefined4 *local_9e0;
  uint *local_9dc;
  undefined1 local_9d8;
  int *local_9d4;
  int *local_9d0;
  uint local_9cc;
  int local_9c8;
  uint *local_9c0;
  undefined4 *local_9ac;
  uint *local_9a8;
  int *local_9a4;
  undefined4 *local_9a0;
  uint *local_99c;
  int *local_998;
  undefined4 local_98c;
  char local_988 [16];
  byte local_978 [39];
  byte bStack_951;
  byte local_950 [12];
  byte local_944;
  undefined1 local_943;
  undefined4 local_940;
  byte local_93c [44];
  uint local_910 [3];
  undefined1 local_904;
  uint local_8ec;
  uint local_8dc;
  uint local_8d8;
  uint local_8d4;
  undefined1 local_8d0;
  uint uStack_8cc;
  uint local_8c8 [7];
  undefined4 uStack_8ac;
  int local_8a8 [15];
  uint uStack_86c;
  uint local_868 [16];
  char acStack_828 [1024];
  undefined4 local_428;
  char acStack_424 [1024];
  
  puVar28 = &DAT_002f44f8;
  local_9c0 = &DAT_002f44f8;
  memset(asic_nonce_num,0,0x4000);
  memset(asic_core_nonce_num,0,0x400000);
  memset(repeated_nonce_id,0xff,0x4000);
  memset(err_nonce_num,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(repeated_nonce_num,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(send_work_num,0,0x40);
  start_receive = 1;
  total_valid_nonce_num = 0;
  iVar27 = 0;
  do {
    iVar26 = iVar27 + 1;
    uVar4 = getChainExistFlag(iVar27);
    puVar28 = puVar28 + 1;
    *puVar28 = uVar4;
    uVar9 = conf._44_4_;
    uVar18 = conf._0_4_;
    iVar27 = iVar26;
  } while (iVar26 != 0x10);
  if (0 < (int)conf._44_4_) {
    iVar27 = conf._44_4_ + 0x9c526;
    puVar22 = (undefined4 *)0x2f40a8;
    puVar5 = (undefined4 *)0x830a8;
    do {
      if (0 < (int)uVar18) {
        puVar14 = puVar5;
        do {
          puVar14 = puVar14 + 1;
          *puVar14 = 0;
        } while (puVar14 != puVar5 + uVar18);
      }
      puVar22 = puVar22 + 1;
      *puVar22 = 0;
      puVar5 = puVar5 + 5000;
    } while (puVar22 != &cgpu + iVar27);
  }
  iVar27 = 0;
  DAT_002f44b0 = 0;
  DAT_002f44b4 = 0;
  DAT_002f44b8 = 0;
  DAT_002f44bc = 0;
  DAT_002f44f8 = 0;
  puVar31 = &DAT_002f4540;
  DAT_002f44d0 = 0x54;
  DAT_002f44ec = 0x56b;
  DAT_002f44d4 = uVar9;
  DAT_002f44d8 = conf._16_4_;
  pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
  puVar28 = local_9c0;
  do {
    while (puVar28 = puVar28 + 1, *puVar28 == 0) {
LAB_0002ae5e:
      iVar27 = iVar27 + 1;
      puVar31 = puVar31 + 1;
      if (puVar28 == (uint *)&DAT_002f4538) goto LAB_0002aec8;
    }
    uVar3 = getChainAsicNum(iVar27);
    cVar1 = chain_need_opencore[iVar27];
    *puVar31 = uVar3;
    if (cVar1 == '\0') goto LAB_0002ae5e;
    sprintf(acStack_828,"do open core on Chain[%d]...\n",iVar27);
    if (showLogToKernelLog != '\0') {
      writeInitLogFile(acStack_828);
    }
    open_core_one_chain(iVar27,1);
    sprintf(acStack_828,"Done open core on Chain[%d]!\n",iVar27);
    if (showLogToKernelLog == '\0') goto LAB_0002ae5e;
    iVar27 = iVar27 + 1;
    writeInitLogFile(acStack_828);
    puVar31 = puVar31 + 1;
  } while (puVar28 != (uint *)&DAT_002f4538);
LAB_0002aec8:
  pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
  if (gBegin_get_nonce == '\0') {
    puts("clement2 set_nonce_fifo_interrupt");
    uVar4 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar4 | 0x10000);
    gBegin_get_nonce = '\x01';
  }
  iVar27 = 0;
  puVar28 = local_9c0;
  do {
    while (puVar28 = puVar28 + 1, *puVar28 != 0) {
      sprintf(acStack_828,"start send works on chain[%d]\n",iVar27);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      StartSendFlag[iVar27] = 1;
      iVar27 = iVar27 + 1;
      if (puVar28 == (uint *)&DAT_002f4538) goto LAB_0002af52;
    }
    iVar27 = iVar27 + 1;
  } while (puVar28 != (uint *)&DAT_002f4538);
LAB_0002af52:
  ClearWorkFIFOAndResetRegisters();
  puVar31 = chain_need_opencore + 0xf;
  memset(local_978,0,0x34);
  local_978[0] = 0xff;
  memset(local_910,0,0x34);
  memset(&local_8dc,0,0x34);
  puVar28 = &uStack_86c;
  puVar22 = &uStack_8ac;
  puVar10 = (undefined1 *)((int)&local_98c + 3);
  do {
    puVar31 = puVar31 + 1;
    uVar3 = *puVar31;
    puVar28 = puVar28 + 1;
    *puVar28 = 0;
    puVar22 = puVar22 + 1;
    *puVar22 = 0;
    puVar10 = puVar10 + 1;
    *puVar10 = uVar3;
  } while (puVar28 != local_868 + 0xf);
  iVar27 = 0;
LAB_0002afb2:
  piVar29 = local_8a8;
  puVar28 = local_868;
  puVar31 = send_work_num;
  local_9d4 = (int *)chain_DataCount;
  local_9e4 = &DAT_002f44f8;
  local_9e0 = (undefined4 *)0x0;
  iVar26 = iVar27;
LAB_0002afc8:
  local_9e4 = local_9e4 + 1;
  iVar27 = iVar26;
  if ((*local_9e4 != 0) && (local_988[(int)local_9e0] != '\0')) {
    iVar23 = *piVar29;
    if (iVar23 < 0x54) {
      piVar30 = &cgpu + iVar23 + 0xa7;
LAB_0002b010:
      iVar23 = iVar23 + 1;
      uVar4 = get_buffer_space();
      if ((uVar4 & 1 << ((uint)local_9e0 & 0xff)) != 0) {
        uVar4 = *puVar28;
        local_9d8 = (undefined1)((uint)local_9e0 | 0xffffff80);
        if (DAT_002f44f8 != 0) {
          local_910[0] = 0;
          local_910[1] = 0;
          iVar27 = uVar4 * 0x34 + *piVar30;
          local_910[2] = 0;
          local_904 = 0;
          memset(local_978,0,0x34);
          pbVar6 = (byte *)(iVar27 + 0x13);
          pbVar33 = local_978 + 3;
          local_978[1] = local_9d8;
          local_978[0] = 1;
          pbVar15 = pbVar6;
          do {
            pbVar15 = pbVar15 + 1;
            pbVar33 = pbVar33 + 1;
            *pbVar33 = *pbVar15;
          } while (pbVar33 != local_978 + 0x23);
          pbVar15 = (byte *)(iVar27 + 7);
          pbVar33 = &bStack_951;
          do {
            pbVar15 = pbVar15 + 1;
            pbVar33 = pbVar33 + 1;
            *pbVar33 = *pbVar15;
          } while (pbVar15 != pbVar6);
          pbVar15 = local_978;
          iVar27 = 1;
          puVar32 = local_910;
          do {
            *puVar32 = (uint)pbVar15[3] | (uint)pbVar15[1] << 0x10 | (uint)*pbVar15 << 0x18 |
                       (uint)pbVar15[2] << 8;
            if (iVar27 == 10) {
              local_8ec = uVar4;
            }
            else if (iVar27 == 0xd) goto code_r0x0002b0da;
            pbVar15 = pbVar15 + 4;
            iVar27 = iVar27 + 1;
            puVar32 = puVar32 + 1;
          } while( true );
        }
        local_8dc = DAT_002f44f8;
        local_8d8 = DAT_002f44f8;
        iVar27 = uVar4 * 0x34 + *piVar30;
        local_8d4 = DAT_002f44f8;
        local_8d0 = 0;
        memset(&local_944,0,0x34);
        pbVar15 = (byte *)(iVar27 + 7);
        pbVar6 = (byte *)(iVar27 + 0x13);
        pbVar33 = (byte *)((int)&local_940 + 3);
        local_940 = uVar4;
        local_943 = local_9d8;
        local_944 = 1;
        do {
          pbVar15 = pbVar15 + 1;
          pbVar33 = pbVar33 + 1;
          *pbVar33 = *pbVar15;
        } while (pbVar15 != pbVar6);
        pbVar15 = local_93c + 0xb;
        do {
          pbVar6 = pbVar6 + 1;
          pbVar15 = pbVar15 + 1;
          *pbVar15 = *pbVar6;
        } while (pbVar15 != local_93c + 0x2b);
        puVar32 = &local_8d8;
        local_8d8 = uVar4;
        local_8dc = (((uint)local_9e0 | 0xffffff80) & 0xff) << 0x10 | 0x1000000;
        pbVar15 = &local_944;
        do {
          pbVar33 = pbVar15 + 4;
          puVar32 = puVar32 + 1;
          *puVar32 = (uint)pbVar15[0xb] | (uint)pbVar15[9] << 0x10 | (uint)pbVar15[8] << 0x18 |
                     (uint)pbVar15[10] << 8;
          pbVar15 = pbVar33;
        } while (pbVar33 != local_93c + 4);
        puVar32 = &uStack_8cc;
        pbVar15 = &local_944;
        do {
          pbVar33 = pbVar15 + 4;
          puVar32 = puVar32 + 1;
          *puVar32 = (uint)pbVar15[0x17] | (uint)pbVar15[0x15] << 0x10 | (uint)pbVar15[0x14] << 0x18
                     | (uint)pbVar15[0x16] << 8;
          pbVar15 = pbVar33;
        } while (pbVar33 != local_93c + 0x18);
        pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
        set_TW_write_command_vil(&local_8dc);
        pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
        *piVar29 = iVar23;
        goto LAB_0002b0f0;
      }
      iVar27 = iVar26 + 1;
      if (iVar27 < 0x7d1) goto LAB_0002b12e;
      goto LAB_0002b36a;
    }
    uVar4 = *puVar28;
    *piVar29 = 0;
    iVar23 = *local_9d4;
    *puVar28 = uVar4 + 1;
    if (iVar23 <= (int)(uVar4 + 1)) goto LAB_0002b11e;
    goto LAB_0002b126;
  }
  goto LAB_0002b12e;
code_r0x0002b0da:
  pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
  set_TW_write_command(local_910);
  pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
  *piVar29 = iVar23;
LAB_0002b0f0:
  piVar30 = piVar30 + 1;
  iVar26 = 0;
  iVar27 = 0;
  *(int *)puVar31 = *(int *)puVar31 + 1;
  if (iVar23 == 0x54) goto code_r0x0002b108;
  goto LAB_0002b010;
code_r0x0002b108:
  uVar4 = *puVar28;
  *piVar29 = 0;
  iVar23 = *local_9d4;
  *puVar28 = uVar4 + 1;
  iVar26 = iVar27;
  if (iVar23 <= (int)(uVar4 + 1)) {
LAB_0002b11e:
    local_988[(int)local_9e0] = '\0';
    iVar27 = iVar26;
LAB_0002b126:
    if (2000 < iVar27) {
LAB_0002b36a:
      uVar18._0_1_ = 'F';
      uVar18._1_1_ = 'a';
      uVar18._2_1_ = 't';
      uVar18._3_1_ = 'a';
      uVar9._0_1_ = 'l';
      uVar9._1_1_ = ' ';
      uVar9._2_1_ = 'E';
      uVar9._3_1_ = 'r';
      uVar12._0_1_ = 'r';
      uVar12._1_1_ = 'o';
      uVar12._2_1_ = 'r';
      uVar12._3_1_ = ':';
      uVar16._0_1_ = ' ';
      uVar16._1_1_ = 's';
      uVar16._2_1_ = 'e';
      uVar16._3_1_ = 'n';
      local_428._0_1_ = 'F';
      local_428._1_1_ = 'a';
      local_428._2_1_ = 't';
      local_428._3_1_ = 'a';
      builtin_strncpy(acStack_424,"l Error: send work timeout\n",0x1c);
      uVar7._0_1_ = 'd';
      uVar7._1_1_ = ' ';
      uVar7._2_1_ = 'w';
      uVar7._3_1_ = 'o';
      uVar11._0_1_ = 'r';
      uVar11._1_1_ = 'k';
      uVar11._2_1_ = ' ';
      uVar11._3_1_ = 't';
      uVar13._0_1_ = 'i';
      uVar13._1_1_ = 'm';
      uVar13._2_1_ = 'e';
      uVar13._3_1_ = 'o';
      uVar17._0_1_ = 'u';
      uVar17._1_1_ = 't';
      uVar17._2_1_ = '\n';
      uVar17._3_1_ = '\0';
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
        uVar18 = local_428;
        uVar9 = acStack_424._0_4_;
        uVar12 = acStack_424._4_4_;
        uVar16 = acStack_424._8_4_;
        uVar7 = acStack_424._12_4_;
        uVar11 = acStack_424._16_4_;
        uVar13 = acStack_424._20_4_;
        uVar17 = acStack_424._24_4_;
      }
      goto LAB_0002b14e;
    }
  }
LAB_0002b12e:
  piVar29 = piVar29 + 1;
  puVar28 = puVar28 + 1;
  puVar31 = (undefined1 *)((int)puVar31 + 4);
  local_9e0 = (undefined4 *)((int)local_9e0 + 1);
  local_9d4 = local_9d4 + 1;
  iVar26 = iVar27;
  uVar18 = local_428;
  uVar9 = acStack_424._0_4_;
  uVar12 = acStack_424._4_4_;
  uVar16 = acStack_424._8_4_;
  uVar7 = acStack_424._12_4_;
  uVar11 = acStack_424._16_4_;
  uVar13 = acStack_424._20_4_;
  uVar17 = acStack_424._24_4_;
  if (local_9e4 == (uint *)&DAT_002f4538) goto LAB_0002b14e;
  goto LAB_0002afc8;
LAB_0002b14e:
  acStack_424._24_4_ = uVar17;
  acStack_424._20_4_ = uVar13;
  acStack_424._16_4_ = uVar11;
  acStack_424._12_4_ = uVar7;
  acStack_424._8_4_ = uVar16;
  acStack_424._4_4_ = uVar12;
  acStack_424._0_4_ = uVar9;
  local_428 = uVar18;
  usleep(5000);
  bVar34 = true;
  iVar26 = 0;
  puVar28 = local_9c0;
  do {
    puVar28 = puVar28 + 1;
    if (((*puVar28 != 0) && (StartSendFlag[iVar26] != '\0')) &&
       ((int)local_868[iVar26] < *(int *)(chain_DataCount + iVar26 * 4))) {
      bVar34 = false;
    }
    iVar26 = iVar26 + 1;
  } while (puVar28 != (uint *)&DAT_002f4538);
  if (bVar34) goto code_r0x0002b188;
  goto LAB_0002afb2;
code_r0x0002b188:
  iVar27 = 0;
  puVar31 = StartSendFlag;
  puVar28 = local_9c0;
  do {
    while ((puVar28 = puVar28 + 1, *puVar28 == 0 || (*puVar31 == '\0'))) {
LAB_0002b1a2:
      iVar27 = iVar27 + 1;
      puVar31 = puVar31 + 1;
      if (puVar28 == (uint *)&DAT_002f4538) goto LAB_0002b1e8;
    }
    *puVar31 = '\0';
    sprintf((char *)&local_428,"get send work num :%d on Chain[%d]\n",
            *(undefined4 *)(send_work_num + iVar27 * 4),iVar27);
    if (showLogToKernelLog == '\0') goto LAB_0002b1a2;
    iVar27 = iVar27 + 1;
    writeInitLogFile(&local_428);
    puVar31 = puVar31 + 1;
  } while (puVar28 != (uint *)&DAT_002f4538);
LAB_0002b1e8:
  iVar27 = 0;
  local_9e4 = &DAT_002f44f8;
  do {
    local_9e4 = local_9e4 + 1;
    if (*local_9e4 != 0) {
      sprintf(acStack_828,"wait recv nonce on chain[%d]\n",iVar27);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      iVar23 = 0;
      iVar26 = 0;
      do {
        while( true ) {
          iVar24 = *(int *)(valid_nonce_num + iVar27 * 4);
          if (*(int *)(chain_ValidNonce + iVar27 * 4) <= iVar24) goto LAB_0002b218;
          if (iVar24 == iVar26) break;
          usleep(100000);
          iVar23 = 0;
          iVar26 = iVar24;
        }
        iVar23 = iVar23 + 1;
        usleep(100000);
        iVar26 = iVar24;
      } while (iVar23 != 0x14);
    }
LAB_0002b218:
    iVar27 = iVar27 + 1;
  } while (local_9e4 != (uint *)&DAT_002f4538);
  local_99c = (uint *)last_result;
  local_998 = &total_valid_nonce_num;
  local_9ac = (undefined4 *)asic_nonce_num;
  local_9a0 = (undefined4 *)last_result_opencore;
  local_98c = "get nonces on chain[%d]\n";
  local_9a4 = (int *)(iic_mutex + 0x14);
  local_9c8 = 0;
  local_9a8 = &DAT_002f44f8;
  gBegin_get_nonce = '\0';
  start_receive = 0;
  do {
    local_9a8 = local_9a8 + 1;
    if (*local_9a8 != 0) {
      sprintf(acStack_828,local_98c,local_9c8);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      iVar27 = *(int *)(chain_PassCount + local_9c8 * 4);
      iVar26 = local_9c8 * 4;
      uVar18 = *(undefined4 *)(chain_ValidNonce + local_9c8 * 4);
      puts(
          "\n------------------------------------------------------------------------------------------------------"
          );
      if (conf._52_4_ == 0) {
        puts("Command mode is VIL");
      }
      else {
        puts("Command mode is FIL");
      }
      if (DAT_002f44d0 == 1) {
        printf("Open core number : Conf.OpenCoreNum1 = %ud = 0x%x\n",Conf._132_4_);
        printf("Open core number : Conf.OpenCoreNum2 = %ud = 0x%x\n",Conf._136_4_);
        printf("Open core number : Conf.OpenCoreNum3 = %ud = 0x%x\n",Conf._140_4_);
        printf("Open core number : Conf.OpenCoreNum4 = %ud = 0x%x\n",Conf._144_4_);
        local_9cc = Conf._48_4_;
      }
      else {
        local_9cc = DAT_002f44d0;
      }
      sprintf((char *)&local_428,"require nonce number:%d\n",iVar27);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"require validnonce number:%d\n",uVar18);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      if (0 < (int)local_9cc) {
        uVar4 = 0;
        puVar22 = local_9ac;
        do {
          while( true ) {
            __format = "asic[%02d]=%02d\t";
            if (DAT_002f44d0 == 1) {
              __format = "core[%02d]=%02d\t";
            }
            sprintf((char *)&local_428,__format,uVar4,*puVar22);
            if (showLogToKernelLog != '\0') {
              writeInitLogFile(&local_428);
            }
            uVar2 = -uVar4;
            bVar34 = (int)uVar4 < 1;
            uVar19 = uVar4 & 7;
            uVar4 = uVar4 + 1;
            if (bVar34) {
              uVar19 = -(uVar2 & 7);
            }
            puVar22 = puVar22 + 1;
            if (uVar19 == 7) break;
LAB_0002b55c:
            if (uVar4 == local_9cc) goto LAB_0002b5b2;
          }
          local_428._0_2_ = 10;
          if (showLogToKernelLog == '\0') goto LAB_0002b55c;
          writeInitLogFile(&local_428);
        } while (uVar4 != local_9cc);
      }
LAB_0002b5b2:
      if (((int)Conf._204_4_ < 1) || (DAT_002f44d0 == 1)) {
        local_428 = CONCAT13(local_428._3_1_,0xa0a);
        if (showLogToKernelLog != '\0') goto LAB_0002b91e;
LAB_0002b914:
        if (0 < (int)local_9cc) {
LAB_0002b6fa:
          uVar4 = 0;
          do {
            while( true ) {
              getChainAsicFreqIndex(local_9c8,uVar4);
              uVar9 = get_freqvalue_by_index();
              sprintf((char *)&local_428,"freq[%02d]=%d\t",uVar4,uVar9);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
              uVar2 = -uVar4;
              bVar34 = (int)uVar4 < 1;
              uVar19 = uVar4 & 7;
              uVar4 = uVar4 + 1;
              if (bVar34) {
                uVar19 = -(uVar2 & 7);
              }
              if (uVar19 == 7) break;
LAB_0002b724:
              if ((int)local_9cc <= (int)uVar4) goto LAB_0002b7f8;
            }
            local_428 = CONCAT22(local_428._2_2_,10);
            if (showLogToKernelLog == '\0') goto LAB_0002b724;
            writeInitLogFile(&local_428);
          } while ((int)uVar4 < (int)local_9cc);
        }
LAB_0002b7f8:
        local_428._0_2_ = 0xa0a;
        if (showLogToKernelLog != '\0') {
          writeInitLogFile(&local_428);
        }
      }
      else {
        iVar23 = __aeabi_idiv(iVar27,Conf._48_4_);
        sprintf((char *)&local_428,
                "\n\n\nBelow ASIC\'s core didn\'t receive all the nonce, they should receive %d nonce each!\n\n"
                ,iVar23);
        if (showLogToKernelLog != '\0') {
          writeInitLogFile(&local_428);
        }
        if (0 < (int)local_9cc) {
          uVar4 = 0;
          local_9d0 = local_9ac + -1;
          local_9d4 = local_9a4;
          local_9e0 = local_9a0;
          local_9dc = local_99c;
          local_9e4 = (uint *)local_998;
          do {
            iVar24 = 0;
            if (0 < (int)Conf._48_4_) {
              iVar25 = 0;
              puVar28 = local_9e4;
              do {
                while ((puVar28 = (uint *)((int *)puVar28 + 1), 0 < (int)*puVar28 ||
                       (iVar8 = isDisabledCore(local_9c8,uVar4,iVar25), iVar8 != 0))) {
                  iVar25 = iVar25 + 1;
                  iVar24 = iVar24 + 1;
                  if ((int)Conf._48_4_ <= iVar25) goto LAB_0002b676;
                }
                iVar25 = iVar25 + 1;
              } while (iVar25 < (int)Conf._48_4_);
            }
LAB_0002b676:
            local_9d4 = local_9d4 + 1;
            iVar8 = *local_9d4;
            bVar34 = SBORROW4(iVar8,0xe);
            iVar25 = iVar8 + -0xe;
            if (iVar8 < 0xf) {
              bVar34 = SBORROW4(iVar24,Conf._48_4_ - iVar8);
              iVar25 = iVar24 - (Conf._48_4_ - iVar8);
            }
            if (iVar25 < 0 == bVar34) {
              *local_9e0 = 1;
            }
            else {
              *local_9e0 = 0;
            }
            iVar25 = iVar27 - iVar8 * iVar23;
            local_9d0 = local_9d0 + 1;
            iVar20 = *local_9d0;
            bVar34 = SBORROW4(iVar8,0xe);
            iVar24 = iVar8 + -0xe;
            if (iVar8 < 0xf) {
              bVar34 = SBORROW4(iVar20,iVar25);
              iVar24 = iVar20 - iVar25;
            }
            *local_9dc = (uint)(iVar24 < 0 == bVar34);
            if (iVar20 < iVar27) {
              sprintf((char *)&local_428,"asic[%02d]=%02d\n",uVar4);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
              if (0 < (int)Conf._48_4_) {
                iVar24 = 0;
                puVar28 = local_9e4;
                do {
                  while( true ) {
                    puVar28 = (uint *)((int *)puVar28 + 1);
                    iVar25 = iVar24 + 1;
                    if ((iVar23 != *puVar28) &&
                       (sprintf((char *)&local_428,"core[%03d]=%d\t",iVar24,*puVar28),
                       showLogToKernelLog != '\0')) break;
                    iVar24 = iVar25;
                    if ((int)Conf._48_4_ <= iVar25) goto LAB_0002b7b0;
                  }
                  writeInitLogFile(&local_428);
                  iVar24 = iVar25;
                } while (iVar25 < (int)Conf._48_4_);
              }
LAB_0002b7b0:
              local_428._0_2_ = 0xa0a;
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
            }
            uVar4 = uVar4 + 1;
            local_9e4 = local_9e4 + 0x100;
            local_9dc = local_9dc + 1;
            local_9e0 = local_9e0 + 1;
          } while (local_9cc != uVar4);
          local_428 = CONCAT22(local_428._2_2_,0xa0a);
          if (showLogToKernelLog != '\0') goto LAB_0002b91e;
          goto LAB_0002b6fa;
        }
        local_428 = CONCAT13(local_428._3_1_,0xa0a);
        if (showLogToKernelLog != '\0') {
LAB_0002b91e:
          writeInitLogFile(&local_428);
          goto LAB_0002b914;
        }
        local_428._0_2_ = 0xa0a;
                    /* WARNING: Ignoring partial resolution of indirect */
        local_428._2_1_ = 0;
      }
      sprintf((char *)&local_428,"total valid nonce number:%d\n",
              *(undefined4 *)(valid_nonce_num + iVar26));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"total send work number:%d\n",
              *(undefined4 *)(send_work_num + iVar26));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"require valid nonce number:%d\n",uVar18);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"repeated_nonce_num:%d\n",
              *(undefined4 *)(repeated_nonce_num + iVar26));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"err_nonce_num:%d\n",*(undefined4 *)(err_nonce_num + iVar26));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"last_nonce_num:%d\n",*(undefined4 *)(last_nonce_num + iVar26));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
    }
    local_9c8 = local_9c8 + 1;
    local_9ac = local_9ac + 0x100;
    local_998 = local_998 + 0x10000;
    local_99c = local_99c + 0x100;
    local_9a0 = local_9a0 + 0x100;
    local_9a4 = local_9a4 + 0x100;
    if (local_9a8 == (uint *)&DAT_002f4538) {
      piVar29 = (int *)(chain_ValidNonce + 0x3c);
      piVar30 = (int *)(last_result + 0x3ffc);
      uVar18 = 1;
      iVar27 = 0;
      do {
        local_9c0 = local_9c0 + 1;
        if (*local_9c0 != 0) {
          piVar21 = piVar30;
          do {
            piVar21 = piVar21 + 1;
            if (*piVar21 == 0) {
              sprintf(acStack_828,"chain[%d]: some chip cores are not opened FAILED!\n",iVar27);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(acStack_828);
              }
              isChainAllCoresOpened[iVar27] = 0;
              chain_need_opencore[iVar27] = 1;
              goto LAB_0002b99a;
            }
          } while (piVar30 + 0x54 != piVar21);
          sprintf(acStack_828,"chain[%d]: All chip cores are opened OK!\n",iVar27);
          if (showLogToKernelLog != '\0') {
            writeInitLogFile(acStack_828);
          }
          isChainAllCoresOpened[iVar27] = 1;
          chain_need_opencore[iVar27] = 0;
LAB_0002b99a:
          piVar21 = piVar29;
          do {
            piVar21 = piVar21 + 1;
            if (*piVar21 == 0) {
              sprintf(acStack_828,"Test Patten on chain[%d]: FAILED!\n",iVar27);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(acStack_828);
              }
              saveChainTestPattenResult(iVar27,0);
              uVar18 = 0;
              search_freq_result[iVar27] = 0;
              goto LAB_0002b9d4;
            }
          } while (piVar29 + 0x54 != piVar21);
          sprintf(acStack_828,"Test Patten on chain[%d]: OK!\n",iVar27);
          if (showLogToKernelLog != '\0') {
            writeInitLogFile(acStack_828);
          }
          saveChainTestPattenResult(iVar27,1);
        }
LAB_0002b9d4:
        iVar27 = iVar27 + 1;
        piVar29 = piVar29 + 0x100;
        piVar30 = piVar30 + 0x100;
        if (local_9c0 == (uint *)&DAT_002f4538) {
          return uVar18;
        }
      } while( true );
    }
  } while( true );
}

