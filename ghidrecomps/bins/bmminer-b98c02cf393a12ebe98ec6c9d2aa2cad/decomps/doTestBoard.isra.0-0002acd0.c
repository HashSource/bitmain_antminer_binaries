
undefined4 doTestBoard_isra_0(void)

{
  char cVar1;
  undefined uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  uint *puVar16;
  byte *pbVar17;
  int *piVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  uint uVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int *piVar28;
  char *pcVar29;
  int iVar30;
  int *piVar31;
  undefined *puVar32;
  uint *puVar33;
  uint uVar34;
  byte *pbVar35;
  bool bVar36;
  int *local_9e4;
  undefined4 *local_9e0;
  uint *local_9dc;
  undefined local_9d8;
  int *local_9d4;
  int *local_9d0;
  uint local_9cc;
  int local_9c8;
  int *local_9c0;
  undefined4 *local_9ac;
  int *local_9a8;
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
  undefined local_943;
  undefined4 local_940;
  byte local_93c [44];
  uint local_910 [3];
  undefined local_904;
  uint local_8ec;
  uint local_8dc;
  uint local_8d8;
  uint local_8d4;
  undefined local_8d0;
  uint uStack_8cc;
  uint local_8c8 [7];
  undefined4 uStack_8ac;
  int local_8a8 [15];
  uint uStack_86c;
  uint local_868 [16];
  char acStack_828 [1024];
  undefined4 local_428;
  undefined4 uStack_424;
  undefined4 uStack_420;
  undefined4 uStack_41c;
  undefined4 local_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  
  local_9a8 = DAT_0002aef8;
  local_9c0 = DAT_0002aef8;
  memset(asic_nonce_num,0,0x4000);
  memset(asic_core_nonce_num,0,0x400000);
  memset(DAT_0002aefc,0xff,0x4000);
  memset(DAT_0002af00,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(DAT_0002af04,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(DAT_0002af08,0,0x40);
  start_receive = 1;
  total_valid_nonce_num = 0;
  iVar3 = 0;
  piVar18 = local_9a8;
  do {
    iVar27 = iVar3 + 1;
    iVar3 = getChainExistFlag(iVar3);
    piVar18 = piVar18 + 1;
    *piVar18 = iVar3;
    uVar10 = conf._44_4_;
    uVar21 = conf._0_4_;
    iVar3 = iVar27;
  } while (iVar27 != 0x10);
  if (0 < (int)conf._44_4_) {
    iVar3 = conf._44_4_ + 0x9c526;
    puVar4 = (undefined4 *)0x830a8;
    puVar5 = DAT_0002af0c;
    do {
      if (0 < (int)uVar21) {
        puVar15 = puVar4;
        do {
          puVar15 = puVar15 + 1;
          *puVar15 = 0;
        } while (puVar15 != puVar4 + uVar21);
      }
      puVar5 = puVar5 + 1;
      *puVar5 = 0;
      puVar4 = puVar4 + 5000;
    } while (puVar5 != &cgpu + iVar3);
  }
  iVar27 = 0;
  *(undefined4 *)(DAT_0002af10 + 0x18a0) = 0;
  iVar3 = DAT_0002af1c;
  puVar32 = DAT_0002af18;
  DAT_002f44b4 = 0;
  DAT_002f44b8 = 0;
  DAT_002f44bc = 0;
  DAT_002f44f8 = 0;
  *(undefined4 *)(DAT_0002af10 + 0x18c0) = 0x54;
  DAT_002f44ec = 0x56b;
  DAT_002f44d4 = uVar10;
  DAT_002f44d8 = conf._16_4_;
  pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
  piVar18 = local_9a8;
  do {
    while (piVar18 = piVar18 + 1, *piVar18 == 0) {
LAB_0002ae5e:
      iVar27 = iVar27 + 1;
      puVar32 = puVar32 + 1;
      if (piVar18 == DAT_0002af14) goto LAB_0002aec8;
    }
    uVar2 = getChainAsicNum(iVar27);
    cVar1 = *(char *)(iVar27 + iVar3);
    *puVar32 = uVar2;
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
    puVar32 = puVar32 + 1;
  } while (piVar18 != DAT_0002af14);
LAB_0002aec8:
  pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
  if (gBegin_get_nonce == '\0') {
    puts("clement2 set_nonce_fifo_interrupt");
    uVar6 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar6 | 0x10000);
    gBegin_get_nonce = '\x01';
  }
  iVar3 = 0;
  piVar18 = local_9a8;
  do {
    while (piVar18 = piVar18 + 1, *piVar18 != 0) {
      sprintf(acStack_828,"start send works on chain[%d]\n",iVar3);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      DAT_0002b204[iVar3] = '\x01';
      iVar3 = iVar3 + 1;
      if (piVar18 == DAT_0002b200) goto LAB_0002af52;
    }
    iVar3 = iVar3 + 1;
  } while (piVar18 != DAT_0002b200);
LAB_0002af52:
  ClearWorkFIFOAndResetRegisters();
  puVar32 = DAT_0002b208;
  memset(local_978,0,0x34);
  local_978[0] = 0xff;
  memset(local_910,0,0x34);
  memset(&local_8dc,0,0x34);
  puVar16 = &uStack_86c;
  puVar5 = &uStack_8ac;
  puVar11 = (undefined *)((int)&local_98c + 3);
  do {
    puVar32 = puVar32 + 1;
    uVar2 = *puVar32;
    puVar16 = puVar16 + 1;
    *puVar16 = 0;
    puVar5 = puVar5 + 1;
    *puVar5 = 0;
    puVar11 = puVar11 + 1;
    *puVar11 = uVar2;
  } while (puVar16 != local_868 + 0xf);
  iVar3 = 0;
LAB_0002afb2:
  piVar18 = local_8a8;
  puVar16 = local_868;
  piVar31 = DAT_0002b20c + -0x18;
  local_9d4 = DAT_0002b20c;
  local_9e4 = local_9a8;
  local_9e0 = (undefined4 *)0x0;
  iVar27 = iVar3;
LAB_0002afc8:
  local_9e4 = local_9e4 + 1;
  iVar3 = iVar27;
  if ((*local_9e4 != 0) && (local_988[(int)local_9e0] != '\0')) {
    iVar25 = *piVar18;
    if (iVar25 < 0x54) {
      piVar28 = &cgpu + iVar25 + 0xa7;
LAB_0002b010:
      iVar25 = iVar25 + 1;
      uVar6 = get_buffer_space();
      if ((uVar6 & 1 << ((uint)local_9e0 & 0xff)) != 0) {
        uVar6 = *puVar16;
        uVar34 = *DAT_0002b210;
        local_9d8 = (undefined)((uint)local_9e0 | 0xffffff80);
        if (uVar34 != 0) {
          local_910[0] = 0;
          local_910[1] = 0;
          iVar3 = uVar6 * 0x34 + *piVar28;
          local_910[2] = 0;
          local_904 = 0;
          memset(local_978,0,0x34);
          pbVar7 = (byte *)(iVar3 + 0x13);
          pbVar35 = local_978 + 3;
          local_978[1] = local_9d8;
          local_978[0] = 1;
          pbVar17 = pbVar7;
          do {
            pbVar17 = pbVar17 + 1;
            pbVar35 = pbVar35 + 1;
            *pbVar35 = *pbVar17;
          } while (pbVar35 != local_978 + 0x23);
          pbVar17 = (byte *)(iVar3 + 7);
          pbVar35 = &bStack_951;
          do {
            pbVar17 = pbVar17 + 1;
            pbVar35 = pbVar35 + 1;
            *pbVar35 = *pbVar17;
          } while (pbVar17 != pbVar7);
          pbVar17 = local_978;
          iVar3 = 1;
          puVar33 = local_910;
          do {
            *puVar33 = (uint)pbVar17[3] | (uint)pbVar17[1] << 0x10 | (uint)*pbVar17 << 0x18 |
                       (uint)pbVar17[2] << 8;
            if (iVar3 == 10) {
              local_8ec = uVar6;
            }
            else if (iVar3 == 0xd) goto code_r0x0002b0da;
            pbVar17 = pbVar17 + 4;
            iVar3 = iVar3 + 1;
            puVar33 = puVar33 + 1;
          } while( true );
        }
        iVar3 = uVar6 * 0x34 + *piVar28;
        local_8d0 = 0;
        local_8dc = uVar34;
        local_8d8 = uVar34;
        local_8d4 = uVar34;
        memset(&local_944,0,0x34);
        pbVar17 = (byte *)(iVar3 + 7);
        pbVar7 = (byte *)(iVar3 + 0x13);
        pbVar35 = (byte *)((int)&local_940 + 3);
        local_940 = uVar6;
        local_943 = local_9d8;
        local_944 = 1;
        do {
          pbVar17 = pbVar17 + 1;
          pbVar35 = pbVar35 + 1;
          *pbVar35 = *pbVar17;
        } while (pbVar17 != pbVar7);
        pbVar17 = local_93c + 0xb;
        do {
          pbVar7 = pbVar7 + 1;
          pbVar17 = pbVar17 + 1;
          *pbVar17 = *pbVar7;
        } while (pbVar17 != local_93c + 0x2b);
        puVar33 = &local_8d8;
        local_8d8 = uVar6;
        local_8dc = (((uint)local_9e0 | 0xffffff80) & 0xff) << 0x10 | 0x1000000;
        pbVar17 = &local_944;
        do {
          pbVar35 = pbVar17 + 4;
          puVar33 = puVar33 + 1;
          *puVar33 = (uint)pbVar17[0xb] | (uint)pbVar17[9] << 0x10 | (uint)pbVar17[8] << 0x18 |
                     (uint)pbVar17[10] << 8;
          pbVar17 = pbVar35;
        } while (pbVar35 != local_93c + 4);
        puVar33 = &uStack_8cc;
        pbVar17 = &local_944;
        do {
          pbVar35 = pbVar17 + 4;
          puVar33 = puVar33 + 1;
          *puVar33 = (uint)pbVar17[0x17] | (uint)pbVar17[0x15] << 0x10 | (uint)pbVar17[0x14] << 0x18
                     | (uint)pbVar17[0x16] << 8;
          pbVar17 = pbVar35;
        } while (pbVar35 != local_93c + 0x18);
        pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
        set_TW_write_command_vil(&local_8dc);
        pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
        *piVar18 = iVar25;
        goto LAB_0002b0f0;
      }
      iVar3 = iVar27 + 1;
      if (iVar3 < 0x7d1) goto LAB_0002b12e;
      goto LAB_0002b36a;
    }
    uVar6 = *puVar16;
    *piVar18 = 0;
    iVar25 = *local_9d4;
    *puVar16 = uVar6 + 1;
    if (iVar25 <= (int)(uVar6 + 1)) goto LAB_0002b11e;
    goto LAB_0002b126;
  }
  goto LAB_0002b12e;
code_r0x0002b0da:
  pthread_mutex_lock((pthread_mutex_t *)opencore_readtemp_mutex);
  set_TW_write_command(local_910);
  pthread_mutex_unlock((pthread_mutex_t *)opencore_readtemp_mutex);
  *piVar18 = iVar25;
LAB_0002b0f0:
  piVar28 = piVar28 + 1;
  iVar27 = 0;
  iVar3 = 0;
  *piVar31 = *piVar31 + 1;
  if (iVar25 == 0x54) goto code_r0x0002b108;
  goto LAB_0002b010;
code_r0x0002b108:
  uVar6 = *puVar16;
  *piVar18 = 0;
  iVar25 = *local_9d4;
  *puVar16 = uVar6 + 1;
  iVar27 = iVar3;
  if (iVar25 <= (int)(uVar6 + 1)) {
LAB_0002b11e:
    local_988[(int)local_9e0] = '\0';
    iVar3 = iVar27;
LAB_0002b126:
    if (2000 < iVar3) {
LAB_0002b36a:
      uVar21._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[0];
      uVar21._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[1];
      uVar21._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[2];
      uVar21._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[3];
      uVar10._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[4];
      uVar10._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[5];
      uVar10._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[6];
      uVar10._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[7];
      uVar13._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[8];
      uVar13._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[9];
      uVar13._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[10];
      uVar13._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[11];
      uVar19._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[12];
      uVar19._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[13];
      uVar19._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[14];
      uVar19._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[15];
      local_428._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[0];
      local_428._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[1];
      local_428._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[2];
      local_428._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[3];
      uStack_424._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[4];
      uStack_424._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[5];
      uStack_424._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[6];
      uStack_424._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[7];
      uStack_420._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[8];
      uStack_420._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[9];
      uStack_420._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[10];
      uStack_420._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[11];
      uStack_41c._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[12];
      uStack_41c._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[13];
      uStack_41c._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[14];
      uStack_41c._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[15];
      uVar8._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[16];
      uVar8._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[17];
      uVar8._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[18];
      uVar8._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[19];
      uVar12._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[20];
      uVar12._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[21];
      uVar12._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[22];
      uVar12._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[23];
      uVar14._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[24];
      uVar14._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[25];
      uVar14._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[26];
      uVar14._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[27];
      uVar20._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[28];
      uVar20._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[29];
      uVar20._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[30];
      uVar20._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[31];
      local_418._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[16];
      local_418._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[17];
      local_418._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[18];
      local_418._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[19];
      uStack_414._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[20];
      uStack_414._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[21];
      uStack_414._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[22];
      uStack_414._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[23];
      uStack_410._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[24];
      uStack_410._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[25];
      uStack_410._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[26];
      uStack_410._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[27];
      uStack_40c._0_1_ = s_Fatal_Error__send_work_timeout_000607ac[28];
      uStack_40c._1_1_ = s_Fatal_Error__send_work_timeout_000607ac[29];
      uStack_40c._2_1_ = s_Fatal_Error__send_work_timeout_000607ac[30];
      uStack_40c._3_1_ = s_Fatal_Error__send_work_timeout_000607ac[31];
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
        uVar21 = local_428;
        uVar10 = uStack_424;
        uVar13 = uStack_420;
        uVar19 = uStack_41c;
        uVar8 = local_418;
        uVar12 = uStack_414;
        uVar14 = uStack_410;
        uVar20 = uStack_40c;
      }
      goto LAB_0002b14e;
    }
  }
LAB_0002b12e:
  piVar18 = piVar18 + 1;
  puVar16 = puVar16 + 1;
  piVar31 = piVar31 + 1;
  local_9e0 = (undefined4 *)((int)local_9e0 + 1);
  local_9d4 = local_9d4 + 1;
  iVar27 = iVar3;
  uVar21 = local_428;
  uVar10 = uStack_424;
  uVar13 = uStack_420;
  uVar19 = uStack_41c;
  uVar8 = local_418;
  uVar12 = uStack_414;
  uVar14 = uStack_410;
  uVar20 = uStack_40c;
  if (local_9e4 == DAT_0002b200) goto LAB_0002b14e;
  goto LAB_0002afc8;
LAB_0002b14e:
  uStack_40c = uVar20;
  uStack_410 = uVar14;
  uStack_414 = uVar12;
  local_418 = uVar8;
  uStack_41c = uVar19;
  uStack_420 = uVar13;
  uStack_424 = uVar10;
  local_428 = uVar21;
  usleep(5000);
  bVar36 = true;
  iVar27 = 0;
  piVar18 = local_9a8;
  do {
    piVar18 = piVar18 + 1;
    if (((*piVar18 != 0) && (DAT_0002b204[iVar27] != '\0')) &&
       ((int)local_868[iVar27] < DAT_0002b20c[iVar27])) {
      bVar36 = false;
    }
    iVar27 = iVar27 + 1;
  } while (piVar18 != DAT_0002b200);
  if (bVar36) goto code_r0x0002b188;
  goto LAB_0002afb2;
code_r0x0002b188:
  iVar3 = 0;
  pcVar29 = DAT_0002b204;
  piVar18 = local_9a8;
  do {
    while ((iVar27 = DAT_0002b214, piVar18 = piVar18 + 1, *piVar18 == 0 || (*pcVar29 == '\0'))) {
LAB_0002b1a2:
      iVar3 = iVar3 + 1;
      pcVar29 = pcVar29 + 1;
      if (piVar18 == DAT_0002b200) goto LAB_0002b1e8;
    }
    *pcVar29 = '\0';
    sprintf((char *)&local_428,"get send work num :%d on Chain[%d]\n",
            *(undefined4 *)(iVar27 + iVar3 * 4),iVar3);
    if (showLogToKernelLog == '\0') goto LAB_0002b1a2;
    iVar3 = iVar3 + 1;
    writeInitLogFile(&local_428);
    pcVar29 = pcVar29 + 1;
  } while (piVar18 != DAT_0002b200);
LAB_0002b1e8:
  iVar3 = 0;
  local_9e4 = local_9a8;
  do {
    local_9e4 = local_9e4 + 1;
    if (*local_9e4 != 0) {
      sprintf(acStack_828,"wait recv nonce on chain[%d]\n",iVar3);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      iVar27 = DAT_0002b53c;
      iVar30 = 0;
      iVar25 = 0;
      do {
        while( true ) {
          iVar26 = *(int *)(DAT_0002b520 + iVar3 * 4);
          if (*(int *)(iVar27 + iVar3 * 4) <= iVar26) goto LAB_0002b218;
          if (iVar26 == iVar25) break;
          usleep(100000);
          iVar30 = 0;
          iVar25 = iVar26;
        }
        iVar30 = iVar30 + 1;
        usleep(100000);
        iVar25 = iVar26;
      } while (iVar30 != 0x14);
    }
LAB_0002b218:
    iVar3 = iVar3 + 1;
  } while (local_9e4 != DAT_0002b51c);
  local_99c = DAT_0002b524;
  local_998 = DAT_0002b528;
  local_9ac = DAT_0002b52c;
  local_9a0 = DAT_0002b530;
  local_98c = "get nonces on chain[%d]\n";
  local_9a4 = DAT_0002b534;
  local_9c8 = 0;
  gBegin_get_nonce = 0;
  start_receive = 0;
  do {
    local_9a8 = local_9a8 + 1;
    if (*local_9a8 != 0) {
      sprintf(acStack_828,local_98c,local_9c8);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(acStack_828);
      }
      iVar3 = *(int *)(DAT_0002b538 + local_9c8 * 4);
      iVar27 = local_9c8 * 4;
      uVar21 = *(undefined4 *)(DAT_0002b53c + local_9c8 * 4);
      puts(
          "\n------------------------------------------------------------------------------------------------------"
          );
      if (conf._52_4_ == 0) {
        puts("Command mode is VIL");
      }
      else {
        puts("Command mode is FIL");
      }
      local_9cc = *(uint *)(DAT_0002b540 + 0x18c0);
      if (local_9cc == 1) {
        printf("Open core number : Conf.OpenCoreNum1 = %ud = 0x%x\n",Conf._132_4_);
        printf("Open core number : Conf.OpenCoreNum2 = %ud = 0x%x\n",Conf._136_4_);
        printf("Open core number : Conf.OpenCoreNum3 = %ud = 0x%x\n",Conf._140_4_);
        printf("Open core number : Conf.OpenCoreNum4 = %ud = 0x%x\n",Conf._144_4_);
        local_9cc = Conf._48_4_;
      }
      sprintf((char *)&local_428,"require nonce number:%d\n",iVar3);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"require validnonce number:%d\n",uVar21);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      if (0 < (int)local_9cc) {
        uVar6 = 0;
        iVar25 = *(int *)(DAT_0002b540 + 0x18c0);
        puVar5 = local_9ac;
        do {
          while( true ) {
            pcVar29 = "asic[%02d]=%02d\t";
            if (iVar25 == 1) {
              pcVar29 = "core[%02d]=%02d\t";
            }
            sprintf((char *)&local_428,pcVar29,uVar6,*puVar5);
            if (showLogToKernelLog != '\0') {
              writeInitLogFile(&local_428);
            }
            uVar34 = -uVar6;
            bVar36 = (int)uVar6 < 1;
            uVar22 = uVar6 & 7;
            uVar6 = uVar6 + 1;
            if (bVar36) {
              uVar22 = -(uVar34 & 7);
            }
            puVar5 = puVar5 + 1;
            if (uVar22 == 7) break;
LAB_0002b55c:
            iVar25 = *(int *)(DAT_0002b7dc + 0x18c0);
            if (uVar6 == local_9cc) goto LAB_0002b5b2;
          }
          local_428._0_2_ = 10;
          if (showLogToKernelLog == '\0') goto LAB_0002b55c;
          writeInitLogFile(&local_428);
          iVar25 = *(int *)(DAT_0002b7dc + 0x18c0);
        } while (uVar6 != local_9cc);
      }
LAB_0002b5b2:
      if (((int)Conf._204_4_ < 1) || (*(int *)(DAT_0002b7dc + 0x18c0) == 1)) {
        local_428._0_3_ = (undefined3)DAT_00060a5c;
        if (showLogToKernelLog != '\0') goto LAB_0002b91e;
LAB_0002b914:
        if (0 < (int)local_9cc) {
LAB_0002b6fa:
          uVar6 = 0;
          do {
            while( true ) {
              getChainAsicFreqIndex(local_9c8,uVar6);
              uVar10 = get_freqvalue_by_index();
              sprintf((char *)&local_428,"freq[%02d]=%d\t",uVar6,uVar10);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
              uVar34 = -uVar6;
              bVar36 = (int)uVar6 < 1;
              uVar22 = uVar6 & 7;
              uVar6 = uVar6 + 1;
              if (bVar36) {
                uVar22 = -(uVar34 & 7);
              }
              if (uVar22 == 7) break;
LAB_0002b724:
              if ((int)local_9cc <= (int)uVar6) goto LAB_0002b7f8;
            }
            local_428 = CONCAT22(local_428._2_2_,10);
            if (showLogToKernelLog == '\0') goto LAB_0002b724;
            writeInitLogFile(&local_428);
          } while ((int)uVar6 < (int)local_9cc);
        }
LAB_0002b7f8:
        local_428._0_2_ = (short)DAT_00060a5c;
        if (showLogToKernelLog != '\0') {
          writeInitLogFile(&local_428);
        }
      }
      else {
        iVar25 = __aeabi_idiv(iVar3,Conf._48_4_);
        sprintf((char *)&local_428,
                "\n\n\nBelow ASIC\'s core didn\'t receive all the nonce, they should receive %d nonce each!\n\n"
                ,iVar25);
        if (showLogToKernelLog != '\0') {
          writeInitLogFile(&local_428);
        }
        if (0 < (int)local_9cc) {
          uVar6 = 0;
          local_9d0 = local_9ac + -1;
          local_9d4 = local_9a4;
          local_9e0 = local_9a0;
          local_9dc = local_99c;
          local_9e4 = local_998;
          do {
            iVar30 = 0;
            if (0 < (int)Conf._48_4_) {
              iVar26 = 0;
              piVar18 = local_9e4;
              do {
                while ((piVar18 = piVar18 + 1, 0 < *piVar18 ||
                       (iVar9 = isDisabledCore(local_9c8,uVar6,iVar26), iVar9 != 0))) {
                  iVar26 = iVar26 + 1;
                  iVar30 = iVar30 + 1;
                  if ((int)Conf._48_4_ <= iVar26) goto LAB_0002b676;
                }
                iVar26 = iVar26 + 1;
              } while (iVar26 < (int)Conf._48_4_);
            }
LAB_0002b676:
            local_9d4 = local_9d4 + 1;
            iVar9 = *local_9d4;
            bVar36 = SBORROW4(iVar9,0xe);
            iVar26 = iVar9 + -0xe;
            if (iVar9 < 0xf) {
              bVar36 = SBORROW4(iVar30,Conf._48_4_ - iVar9);
              iVar26 = iVar30 - (Conf._48_4_ - iVar9);
            }
            if (iVar26 < 0 == bVar36) {
              *local_9e0 = 1;
            }
            else {
              *local_9e0 = 0;
            }
            iVar26 = iVar3 - iVar9 * iVar25;
            local_9d0 = local_9d0 + 1;
            iVar23 = *local_9d0;
            bVar36 = SBORROW4(iVar9,0xe);
            iVar30 = iVar9 + -0xe;
            if (iVar9 < 0xf) {
              bVar36 = SBORROW4(iVar23,iVar26);
              iVar30 = iVar23 - iVar26;
            }
            *local_9dc = (uint)(iVar30 < 0 == bVar36);
            if (iVar23 < iVar3) {
              sprintf((char *)&local_428,"asic[%02d]=%02d\n",uVar6);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
              if (0 < (int)Conf._48_4_) {
                iVar30 = 0;
                piVar18 = local_9e4;
                do {
                  while( true ) {
                    piVar18 = piVar18 + 1;
                    iVar26 = iVar30 + 1;
                    if ((iVar25 != *piVar18) &&
                       (sprintf((char *)&local_428,"core[%03d]=%d\t",iVar30,*piVar18),
                       showLogToKernelLog != '\0')) break;
                    iVar30 = iVar26;
                    if ((int)Conf._48_4_ <= iVar26) goto LAB_0002b7b0;
                  }
                  writeInitLogFile(&local_428);
                  iVar30 = iVar26;
                } while (iVar26 < (int)Conf._48_4_);
              }
LAB_0002b7b0:
              local_428._0_2_ = (short)DAT_00060a5c;
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(&local_428);
              }
            }
            uVar6 = uVar6 + 1;
            local_9e4 = local_9e4 + 0x100;
            local_9dc = local_9dc + 1;
            local_9e0 = local_9e0 + 1;
          } while (local_9cc != uVar6);
          local_428 = CONCAT22(local_428._2_2_,(short)DAT_00060a5c);
          if (showLogToKernelLog != '\0') goto LAB_0002b91e;
          goto LAB_0002b6fa;
        }
        local_428._0_3_ = (undefined3)DAT_00060a5c;
        if (showLogToKernelLog != '\0') {
LAB_0002b91e:
          writeInitLogFile(&local_428);
          goto LAB_0002b914;
        }
        local_428._0_2_ = (short)DAT_00060a5c;
                    /* WARNING: Ignoring partial resolution of indirect */
        local_428._2_1_ = (char)((uint)DAT_00060a5c >> 0x10);
      }
      sprintf((char *)&local_428,"total valid nonce number:%d\n",
              *(undefined4 *)(DAT_0002bb14 + iVar27));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"total send work number:%d\n",
              *(undefined4 *)(DAT_0002bb18 + iVar27));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"require valid nonce number:%d\n",uVar21);
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"repeated_nonce_num:%d\n",*(undefined4 *)(DAT_0002bb1c + iVar27));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"err_nonce_num:%d\n",*(undefined4 *)(DAT_0002bb20 + iVar27));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
      sprintf((char *)&local_428,"last_nonce_num:%d\n",*(undefined4 *)(DAT_0002bb24 + iVar27));
      if (showLogToKernelLog != '\0') {
        writeInitLogFile(&local_428);
      }
    }
    piVar18 = DAT_0002bb28;
    local_9c8 = local_9c8 + 1;
    local_9ac = local_9ac + 0x100;
    local_998 = local_998 + 0x10000;
    local_99c = local_99c + 0x100;
    local_9a0 = local_9a0 + 0x100;
    local_9a4 = local_9a4 + 0x100;
    if (local_9a8 == DAT_0002b51c) {
      uVar21 = 1;
      iVar3 = 0;
      piVar31 = DAT_0002bb28;
      piVar28 = DAT_0002bb34;
      do {
        local_9c0 = local_9c0 + 1;
        if (*local_9c0 != 0) {
          piVar24 = piVar28;
          do {
            piVar24 = piVar24 + 1;
            if (*piVar24 == 0) {
              sprintf(acStack_828,"chain[%d]: some chip cores are not opened FAILED!\n",iVar3);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(acStack_828);
              }
              isChainAllCoresOpened[iVar3] = 0;
              *(undefined *)((int)piVar18 + iVar3 + -0x9c) = 1;
              goto LAB_0002b99a;
            }
          } while (piVar28 + 0x54 != piVar24);
          sprintf(acStack_828,"chain[%d]: All chip cores are opened OK!\n",iVar3);
          if (showLogToKernelLog != '\0') {
            writeInitLogFile(acStack_828);
          }
          isChainAllCoresOpened[iVar3] = 1;
          *(undefined *)((int)piVar18 + iVar3 + -0x9c) = 0;
LAB_0002b99a:
          piVar24 = piVar31;
          do {
            piVar24 = piVar24 + 1;
            if (*piVar24 == 0) {
              sprintf(acStack_828,"Test Patten on chain[%d]: FAILED!\n",iVar3);
              if (showLogToKernelLog != '\0') {
                writeInitLogFile(acStack_828);
              }
              saveChainTestPattenResult(iVar3,0);
              uVar21 = 0;
              *(undefined *)(iVar3 + DAT_0002bb2c) = 0;
              goto LAB_0002b9d4;
            }
          } while (piVar31 + 0x54 != piVar24);
          sprintf(acStack_828,"Test Patten on chain[%d]: OK!\n",iVar3);
          if (showLogToKernelLog != '\0') {
            writeInitLogFile(acStack_828);
          }
          saveChainTestPattenResult(iVar3,1);
        }
LAB_0002b9d4:
        iVar3 = iVar3 + 1;
        piVar31 = piVar31 + 0x100;
        piVar28 = piVar28 + 0x100;
        if (local_9c0 == DAT_0002bb30) {
          return uVar21;
        }
      } while( true );
    }
  } while( true );
}

