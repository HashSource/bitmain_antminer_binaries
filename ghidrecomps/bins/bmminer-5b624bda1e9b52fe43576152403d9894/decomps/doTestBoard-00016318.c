
_Bool doTestBoard(int test_times)

{
  uint *puVar1;
  char cVar2;
  undefined2 uVar3;
  bool bVar4;
  int iVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar *puVar8;
  pthread_mutex_t *__mutex;
  int iVar9;
  int i_1;
  uint uVar10;
  int iVar11;
  testpatten_work *work;
  int n;
  uchar *puVar12;
  uint *puVar13;
  char *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  int j;
  undefined4 uVar18;
  vil_work_1387 *pvVar19;
  undefined4 *puVar20;
  int iVar21;
  byte *pbVar22;
  vil_work_1387 *pvVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int i;
  undefined4 *puVar28;
  int iVar29;
  int iVar30;
  uint OpenCoreNum1;
  int iVar31;
  _Bool _Var32;
  int iVar33;
  int last_recv_num;
  uint OpenCoreNum2;
  uint uVar34;
  uint OpenCoreNum3;
  uint uVar35;
  uint OpenCoreNum4;
  uint uVar36;
  uint uVar37;
  int *piVar38;
  uint uVar39;
  uint local_3d0;
  uint local_3cc;
  int local_3c8;
  int local_3c0;
  int local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  int local_3ac;
  undefined4 *local_3a8;
  int local_3a4;
  int *local_39c;
  _Bool sendStartFlag [16];
  uchar data_fil [52];
  vil_work_1387 work_vil_1387;
  uint buf [13];
  uint buf_vil [13];
  int which_asic [16];
  int index [16];
  char logstr [256];
  char logstr_1 [256];
  
  piVar38 = DAT_000164ac;
  iVar9 = DAT_000164a8;
  local_39c = DAT_000164ac;
  memset(asic_nonce_num,0,0x4000);
  memset((void *)(iVar9 + 0xa54),0,0x400000);
  memset(DAT_000164b0,0xff,0x4000);
  memset(DAT_000164b4,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(DAT_000164b8,0,0x40);
  memset((void *)(iVar9 + 0xa10),0,0x40);
  memset(DAT_000164bc,0,0x40);
  *(undefined4 *)(iVar9 + 0xa50) = 0;
  start_receive = true;
  iVar9 = 0;
  do {
    iVar27 = iVar9 + 1;
    iVar9 = getChainExistFlag(iVar9);
    piVar38 = piVar38 + 1;
    *piVar38 = iVar9;
    iVar17 = conf.asicNum;
    iVar9 = iVar27;
  } while (iVar27 != 0x10);
  if (conf.asicNum < 1) {
    local_3bc = DAT_000164c4;
  }
  else {
    iVar27 = *(int *)(DAT_000164c0 + 0xd2c);
    iVar9 = 0;
    local_3bc = DAT_000164c8 + -0x498;
    puVar16 = (undefined4 *)(DAT_000164c8 + iVar27 * 4);
    puVar28 = DAT_000164cc;
    do {
      if (0 < iVar27) {
        puVar20 = (undefined4 *)(iVar9 * 20000 + local_3bc + 0x498);
        do {
          puVar20 = puVar20 + 1;
          *puVar20 = 0;
        } while (puVar20 != puVar16);
      }
      iVar9 = iVar9 + 1;
      puVar16 = puVar16 + 5000;
      puVar28 = puVar28 + 1;
      *puVar28 = 0;
    } while (iVar9 != iVar17);
  }
  iVar27 = conf.core;
  puVar28 = DAT_000164d0;
  puVar1 = DAT_000164d0 + 8;
  *puVar1 = 0x12;
  piVar38 = puVar28 + 0x12;
  *puVar28 = 0;
  iVar9 = DAT_000164d4;
  *(undefined4 *)((int)cgpu.results[0x6b] + local_3bc + 0x41e8) = 0;
  *(undefined4 *)((int)cgpu.results[0x6b] + local_3bc + 0x41e4) = 0;
  *(int *)((int)cgpu.results[0x6b] + local_3bc + 0x4200) = iVar17;
  *(undefined4 *)((int)cgpu.results[0x6b] + local_3bc + 0x41e0) = 0;
  *(undefined4 *)((int)cgpu.results[0x6b] + local_3bc + 0x4224) = 0;
  *(undefined4 *)((int)cgpu.results[0x6b] + local_3bc + 0x4218) = 0x56b;
  __mutex = DAT_000164d8;
  *(int *)((int)cgpu.results[0x6b] + local_3bc + 0x4204) = iVar27;
  pthread_mutex_lock(__mutex);
  iVar17 = 0;
LAB_000164e2:
  do {
    piVar38 = piVar38 + 1;
    if (*piVar38 != 0) {
      iVar27 = getChainAsicNum(iVar17);
      cVar2 = *(char *)(iVar17 + iVar9);
      *(char *)((int)cgpu.results[0x6b] + local_3bc + iVar17 + 0x426c) = (char)iVar27;
      if (cVar2 != '\0') {
        sprintf(logstr,DAT_000166fc,iVar17);
        writeLogFile(logstr);
        open_core_one_chain(iVar17,true);
        iVar27 = iVar17 + 1;
        sprintf(logstr,DAT_00016700,iVar17);
        writeLogFile(logstr);
        iVar17 = iVar27;
        if (iVar27 == 0x10) break;
        goto LAB_000164e2;
      }
    }
    iVar17 = iVar17 + 1;
  } while (iVar17 != 0x10);
  iVar9 = DAT_00016708;
  pthread_mutex_unlock(DAT_00016704);
  if (gBegin_get_nonce == false) {
    puts(DAT_00017100);
    uVar10 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar10 | 0x10000);
    *(undefined *)(iVar9 + 0xce9) = 1;
  }
  iVar9 = 0;
  puVar13 = DAT_0001670c;
  do {
    puVar13 = puVar13 + 1;
    if (*puVar13 != 0) {
      sprintf(logstr,DAT_00016710,iVar9);
      writeLogFile(logstr);
      *(undefined *)(DAT_00016714 + iVar9) = 1;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 != 0x10);
  iVar17 = 0;
  data_fil[0] = 0xff;
  data_fil[1] = '\0';
  data_fil[2] = '\0';
  data_fil[3] = '\0';
  iVar9 = 0;
  buf[4] = 0;
  buf[5] = 0;
  buf[6] = 0;
  buf[7] = 0;
  buf[8] = 0;
  buf[9] = 0;
  buf[10] = 0;
  buf_vil[5] = 0;
  buf[11] = 0;
  buf[12] = 0;
  data_fil[4] = '\0';
  data_fil[5] = '\0';
  data_fil[6] = '\0';
  data_fil[7] = '\0';
  data_fil[8] = '\0';
  data_fil[9] = '\0';
  data_fil[10] = '\0';
  data_fil[11] = '\0';
  data_fil[12] = '\0';
  data_fil[13] = '\0';
  data_fil[14] = '\0';
  data_fil[15] = '\0';
  data_fil[16] = '\0';
  data_fil[17] = '\0';
  data_fil[18] = '\0';
  data_fil[19] = '\0';
  data_fil[20] = '\0';
  data_fil[21] = '\0';
  data_fil[22] = '\0';
  data_fil[23] = '\0';
  data_fil[24] = '\0';
  data_fil[25] = '\0';
  data_fil[26] = '\0';
  data_fil[27] = '\0';
  data_fil[28] = '\0';
  data_fil[29] = '\0';
  data_fil[30] = '\0';
  data_fil[31] = '\0';
  data_fil[32] = '\0';
  data_fil[33] = '\0';
  data_fil[34] = '\0';
  data_fil[35] = '\0';
  data_fil[36] = '\0';
  data_fil[37] = '\0';
  data_fil[38] = '\0';
  data_fil[39] = '\0';
  data_fil[40] = '\0';
  data_fil[41] = '\0';
  data_fil[42] = '\0';
  data_fil[43] = '\0';
  data_fil[44] = '\0';
  data_fil[45] = '\0';
  data_fil[46] = '\0';
  data_fil[47] = '\0';
  data_fil[48] = '\0';
  data_fil[49] = '\0';
  data_fil[50] = '\0';
  data_fil[51] = '\0';
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  buf[3] = 0;
  buf_vil[0] = 0;
  buf_vil[1] = 0;
  buf_vil[2] = 0;
  buf_vil[3] = 0;
  buf_vil[4] = 0;
  buf_vil[6] = 0;
  buf_vil[7] = 0;
  buf_vil[8] = 0;
  buf_vil[9] = 0;
  buf_vil[10] = 0;
  buf_vil[11] = 0;
  buf_vil[12] = 0;
  do {
    *(undefined4 *)((int)index + iVar17) = 0;
    _Var32 = *(_Bool *)(DAT_00016714 + iVar9);
    *(undefined4 *)((int)which_asic + iVar17) = 0;
    iVar17 = iVar17 + 4;
    sendStartFlag[iVar9] = _Var32;
    iVar9 = iVar9 + 1;
  } while (iVar9 != 0x10);
  iVar9 = 0;
  iVar17 = DAT_00016714 + -0x50;
  do {
    iVar27 = 0;
    local_3d0 = 0;
    do {
      if ((*(int *)((int)cgpu.results[0x6b] + local_3bc + iVar27 + 0x4228) != 0) &&
         (sendStartFlag[local_3d0] != false)) {
        iVar29 = *(int *)((int)which_asic + iVar27);
        if (iVar29 < 0x12) {
          iVar33 = 0;
          iVar11 = iVar9;
          iVar30 = iVar29;
LAB_0001665c:
          iVar30 = iVar30 + 1;
          uVar10 = get_buffer_space();
          if ((uVar10 & 1 << (local_3d0 & 0xff)) != 0) {
            uVar10 = *DAT_0001670c;
            if (uVar10 != 0) {
              uVar10 = *(uint *)((int)index + iVar27);
              buf[0] = 0;
              buf[1] = 0;
              buf[2] = 0;
              iVar11 = uVar10 * 0x34 + *(int *)((int)cgpu.works + iVar33 + iVar29 * 4);
              buf[3] = buf[3] & 0xffffff00;
              data_fil[4] = '\0';
              data_fil[5] = '\0';
              data_fil[6] = '\0';
              data_fil[7] = '\0';
              data_fil[8] = '\0';
              data_fil[9] = '\0';
              data_fil[10] = '\0';
              data_fil[11] = '\0';
              data_fil[12] = '\0';
              data_fil[13] = '\0';
              data_fil[14] = '\0';
              data_fil[15] = '\0';
              data_fil[16] = '\0';
              data_fil[17] = '\0';
              data_fil[18] = '\0';
              data_fil[19] = '\0';
              data_fil[20] = '\0';
              data_fil[21] = '\0';
              data_fil[22] = '\0';
              data_fil[23] = '\0';
              data_fil[24] = '\0';
              data_fil[25] = '\0';
              data_fil[26] = '\0';
              data_fil[27] = '\0';
              data_fil[28] = '\0';
              data_fil[29] = '\0';
              data_fil[30] = '\0';
              data_fil[31] = '\0';
              data_fil[32] = '\0';
              data_fil[33] = '\0';
              data_fil[34] = '\0';
              data_fil[35] = '\0';
              data_fil[36] = '\0';
              data_fil[37] = '\0';
              data_fil[38] = '\0';
              data_fil[39] = '\0';
              data_fil[40] = '\0';
              data_fil[41] = '\0';
              data_fil[42] = '\0';
              data_fil[43] = '\0';
              data_fil[44] = '\0';
              data_fil[45] = '\0';
              data_fil[46] = '\0';
              data_fil[47] = '\0';
              data_fil[48] = '\0';
              data_fil[49] = '\0';
              data_fil[50] = '\0';
              data_fil[51] = '\0';
              data_fil._0_4_ = CONCAT11((char)local_3d0,1) | 0x8000;
              iVar9 = 0;
              do {
                iVar21 = iVar9 + 1;
                data_fil[iVar9 + 4] = *(uchar *)(iVar11 + iVar9 + 0x14);
                iVar9 = iVar21;
              } while (iVar21 != 0x20);
              iVar9 = 0;
              do {
                pbVar22 = data_fil;
                iVar21 = iVar9 + 1;
                data_fil[iVar9 + 0x28] = *(uchar *)(iVar11 + iVar9 + 8);
                iVar9 = iVar21;
              } while (iVar21 != 0xc);
              puVar12 = work_vil_1387.midstate + 0x1c;
              iVar9 = 1;
              do {
                puVar12 = puVar12 + 4;
                *(uint *)puVar12 =
                     (uint)pbVar22[1] << 0x10 | (uint)*pbVar22 << 0x18 | (uint)pbVar22[3] |
                     (uint)pbVar22[2] << 8;
                if (iVar9 == 10) {
                  buf[9] = uVar10;
                }
                else if (iVar9 == 0xd) goto code_r0x0001674a;
                pbVar22 = pbVar22 + 4;
                iVar9 = iVar9 + 1;
              } while( true );
            }
            work_vil_1387.work_type = (char)uVar10;
            work_vil_1387.chain_id = (char)(uVar10 >> 8);
            work_vil_1387.reserved1[0] = (char)(uVar10 >> 0x10);
            work_vil_1387.reserved1[1] = (char)(uVar10 >> 0x18);
            work_vil_1387.data[0] = (char)uVar10;
            work_vil_1387.data[1] = (char)(uVar10 >> 8);
            work_vil_1387.data[2] = (char)(uVar10 >> 0x10);
            work_vil_1387.data[3] = (char)(uVar10 >> 0x18);
            work_vil_1387.work_count = *(uint *)((int)index + iVar27);
            work_vil_1387.data[8] = (char)uVar10;
            work_vil_1387.data[9] = (char)(uVar10 >> 8);
            work_vil_1387.data[10] = (char)(uVar10 >> 0x10);
            work_vil_1387.data[11] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[0] = (char)uVar10;
            work_vil_1387.midstate[1] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[2] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[3] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[4] = (char)uVar10;
            work_vil_1387.midstate[5] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[6] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[7] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[8] = (char)uVar10;
            work_vil_1387.midstate[9] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[10] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[11] = (char)(uVar10 >> 0x18);
            iVar11 = work_vil_1387.work_count * 0x34 +
                     *(int *)((int)cgpu.works + iVar33 + iVar29 * 4);
            work_vil_1387.midstate[12] = (char)uVar10;
            work_vil_1387.midstate[13] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[14] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[15] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[16] = (char)uVar10;
            work_vil_1387.midstate[17] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[18] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[19] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[20] = (char)uVar10;
            work_vil_1387.midstate[21] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[22] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[23] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[24] = (char)uVar10;
            work_vil_1387.midstate[25] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[26] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[27] = (char)(uVar10 >> 0x18);
            buf_vil[2] = uVar10;
            buf_vil[3] = buf_vil[3] & 0xffffff00;
            work_vil_1387.data[4] = (char)uVar10;
            work_vil_1387.data[5] = (char)(uVar10 >> 8);
            work_vil_1387.data[6] = (char)(uVar10 >> 0x10);
            work_vil_1387.data[7] = (char)(uVar10 >> 0x18);
            work_vil_1387.midstate[28] = (char)uVar10;
            work_vil_1387.midstate[29] = (char)(uVar10 >> 8);
            work_vil_1387.midstate[30] = (char)(uVar10 >> 0x10);
            work_vil_1387.midstate[31] = (char)(uVar10 >> 0x18);
            work_vil_1387._0_4_ = CONCAT11((char)local_3d0,1) | 0x8000;
            iVar9 = 0;
            do {
              iVar21 = iVar9 + 1;
              work_vil_1387.data[iVar9] = *(uchar *)(iVar11 + iVar9 + 8);
              iVar9 = iVar21;
            } while (iVar21 != 0xc);
            iVar9 = 0;
            do {
              pvVar23 = &work_vil_1387;
              iVar21 = iVar9 + 1;
              work_vil_1387.midstate[iVar9] = *(uchar *)(iVar11 + iVar9 + 0x14);
              iVar9 = iVar21;
            } while (iVar21 != 0x20);
            puVar13 = buf_vil + 1;
            buf_vil[1] = work_vil_1387.work_count;
            buf_vil[0] = local_3d0 << 0x10 | 0x1800000;
            pvVar19 = pvVar23;
            do {
              puVar6 = pvVar19->data;
              puVar12 = pvVar19->data;
              puVar7 = pvVar19->data;
              puVar8 = pvVar19->data;
              pvVar19 = (vil_work_1387 *)&pvVar19->work_count;
              puVar13 = puVar13 + 1;
              *puVar13 = (uint)puVar6[1] << 0x10 | (uint)*puVar12 << 0x18 | (uint)puVar7[3] |
                         (uint)puVar8[2] << 8;
            } while (pvVar19 != (vil_work_1387 *)(work_vil_1387.data + 4));
            puVar13 = buf_vil + 4;
            do {
              puVar6 = pvVar23->midstate;
              puVar12 = pvVar23->midstate;
              puVar7 = pvVar23->midstate;
              puVar8 = pvVar23->midstate;
              pvVar23 = (vil_work_1387 *)&pvVar23->work_count;
              puVar13 = puVar13 + 1;
              *puVar13 = (uint)puVar6[1] << 0x10 | (uint)*puVar12 << 0x18 | (uint)puVar7[3] |
                         (uint)puVar8[2] << 8;
            } while (pvVar23 != (vil_work_1387 *)(work_vil_1387.midstate + 0xc));
            pthread_mutex_lock(DAT_00016a4c);
            set_TW_write_command_vil(buf_vil);
            pthread_mutex_unlock(DAT_00016a4c);
            *(int *)((int)which_asic + iVar27) = iVar30;
            goto LAB_00016768;
          }
          iVar9 = iVar11 + 1;
          goto joined_r0x000169dc;
        }
LAB_00016786:
        *(undefined4 *)((int)which_asic + iVar27) = 0;
        iVar29 = *(int *)(iVar27 + DAT_00016a50);
        iVar11 = *(int *)((int)index + iVar27) + 1;
        *(int *)((int)index + iVar27) = iVar11;
        if (iVar29 <= iVar11) {
          sendStartFlag[local_3d0] = false;
        }
joined_r0x000169dc:
        if (2000 < iVar9) {
          logstr_1._0_4_ = *DAT_00016a6c;
          logstr_1._4_4_ = DAT_00016a6c[1];
          logstr_1._8_4_ = DAT_00016a6c[2];
          logstr_1._12_4_ = DAT_00016a6c[3];
          logstr_1._16_4_ = DAT_00016a6c[4];
          logstr_1._20_4_ = DAT_00016a6c[5];
          logstr_1._24_4_ = DAT_00016a6c[6];
          logstr_1._28_4_ = DAT_00016a6c[7];
          writeLogFile(logstr_1);
          break;
        }
      }
      iVar27 = iVar27 + 4;
      local_3d0 = local_3d0 + 1;
    } while (local_3d0 != 0x10);
    bVar4 = true;
    usleep(5000);
    iVar27 = DAT_00016a54;
    iVar11 = 0;
    iVar29 = 0;
    do {
      if (((*(int *)((int)cgpu.results[0x6b] + local_3bc + iVar11 + 0x4228) != 0) &&
          (*(char *)(DAT_00016a54 + iVar29) != '\0')) &&
         (*(int *)((int)index + iVar11) < *(int *)(iVar11 + DAT_00016a54 + 0x10))) {
        bVar4 = false;
      }
      iVar29 = iVar29 + 1;
      iVar11 = iVar11 + 4;
    } while (iVar29 != 0x10);
  } while (!bVar4);
  iVar17 = 0;
  iVar9 = 0;
  iVar29 = DAT_00016a54 + -0x50;
  do {
    while ((pcVar14 = DAT_00016a58,
           *(int *)((int)cgpu.results[0x6b] + local_3bc + iVar17 + 0x4228) != 0 &&
           (*(char *)(DAT_00016a54 + iVar9) != '\0'))) {
      uVar18 = *(undefined4 *)(iVar29 + iVar17);
      *(undefined *)(iVar9 + iVar27) = 0;
      iVar17 = iVar17 + 4;
      sprintf(logstr_1,pcVar14,uVar18,iVar9);
      writeLogFile(logstr_1);
      *(undefined *)(iVar9 + DAT_00016a5c) = 1;
      iVar9 = iVar9 + 1;
      if (iVar9 == 0x10) goto LAB_0001686e;
    }
    iVar9 = iVar9 + 1;
    iVar17 = iVar17 + 4;
  } while (iVar9 != 0x10);
LAB_0001686e:
  iVar17 = DAT_00016a64;
  iVar9 = DAT_00016a60;
  iVar27 = 0;
  iVar29 = 0;
  do {
    while (*(int *)((int)cgpu.results[0x6b] + local_3bc + iVar27 + 0x4228) != 0) {
      iVar11 = 0;
      sprintf(logstr,DAT_00016a68,iVar29);
      writeLogFile(logstr);
      iVar30 = 0;
      do {
        while( true ) {
          iVar33 = *(int *)(iVar9 + iVar27);
          if (*(int *)(iVar17 + iVar27) <= iVar33) goto LAB_00016878;
          if (iVar30 == iVar33) break;
          usleep(100000);
          iVar11 = 0;
          iVar30 = iVar33;
        }
        iVar11 = iVar11 + 1;
        usleep(100000);
      } while (iVar11 < 0x14);
      iVar27 = iVar27 + 4;
      iVar29 = iVar29 + 1;
      if (iVar27 == 0x40) goto LAB_00016a1c;
    }
LAB_00016878:
    iVar27 = iVar27 + 4;
    iVar29 = iVar29 + 1;
  } while (iVar27 != 0x40);
LAB_00016a1c:
  iVar17 = DAT_00016a74;
  iVar9 = DAT_00016a70;
  local_3c8 = DAT_00016a70;
  gBegin_get_nonce = false;
  local_3ac = 0;
  local_3b0 = 0;
  local_3a4 = 0;
  local_3b4 = DAT_00016a78;
  local_3c0 = DAT_00016a7c;
  local_3b8 = DAT_00016a74;
  start_receive = false;
  do {
    iVar29 = DAT_00016de0;
    iVar27 = DAT_00016dd8;
    if (*(int *)((int)cgpu.results[0x6b] + local_3bc + local_3b0 + 0x4228) != 0) {
      sprintf(logstr,DAT_00016ddc,local_3a4);
      writeLogFile(logstr);
      uVar36 = conf.OpenCoreNum4;
      uVar35 = conf.OpenCoreNum3;
      uVar34 = conf.OpenCoreNum2;
      uVar10 = conf.OpenCoreNum1;
      iVar27 = *(int *)(local_3b0 + iVar27);
      iVar29 = *(int *)(local_3b0 + iVar29);
      puts(DAT_00016de4);
      if (conf.CommandMode == 0) {
        puts(DAT_000170e4);
      }
      else {
        puts(DAT_00016de8);
      }
      iVar11 = DAT_00016e00;
      local_3d0 = *puVar1;
      if (local_3d0 == 1) {
        printf(DAT_00017104,*(undefined4 *)(DAT_00016e00 + 0xf60),
               *(undefined4 *)(DAT_00016e00 + 0xf60));
        printf(DAT_00017108,*(undefined4 *)(iVar11 + 0xf64),*(undefined4 *)(iVar11 + 0xf64));
        printf(DAT_0001710c,*(undefined4 *)(iVar11 + 0xf68),*(undefined4 *)(iVar11 + 0xf68));
        printf(DAT_00017110,*(undefined4 *)(iVar11 + 0xf6c),*(undefined4 *)(iVar11 + 0xf6c));
        local_3d0 = *(uint *)(iVar11 + 0xf0c);
      }
      sprintf(logstr_1,DAT_00016dec,iVar29);
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_00016df0,iVar27);
      writeLogFile(logstr_1);
      if ((int)local_3d0 < 1) {
        uVar18 = 3;
      }
      else {
        local_3cc = 0;
        uVar37 = 0;
        uVar39 = *puVar1;
        piVar38 = (int *)(DAT_00016df4 + local_3a4 * 0x400);
        uVar18 = 3;
        do {
          while( true ) {
            pcVar14 = DAT_00016df8;
            if (uVar39 != 1) {
              pcVar14 = DAT_00016dfc;
            }
            sprintf(logstr_1,pcVar14,uVar37,*piVar38);
            writeLogFile(logstr_1);
            if ((uVar37 & 7) == 7) {
              logstr_1[0] = '\n';
              logstr_1[1] = '\0';
              writeLogFile(logstr_1);
            }
            uVar39 = *puVar1;
            if (uVar39 == 1) break;
            if (*piVar38 < iVar29) {
              uVar18 = 2;
            }
LAB_00016b8e:
            uVar37 = uVar37 + 1;
            piVar38 = piVar38 + 1;
            if (uVar37 == local_3d0) goto LAB_00016c48;
          }
          if (0x7f < local_3cc) goto LAB_00016b8e;
          iVar33 = 0;
          iVar30 = DAT_00016df4 + (local_3cc + local_3ac) * 4;
          do {
            while ((int)local_3cc < 0x20) {
              if ((int)(uVar10 << 0x1f) < 0) {
                uVar10 = uVar10 >> 1;
                if (*(int *)(iVar30 + iVar33) < iVar29) {
                  uVar18 = 2;
                }
              }
              else {
                uVar10 = uVar10 >> 1;
              }
LAB_00016bfe:
              local_3cc = local_3cc + 1;
              iVar33 = iVar33 + 4;
              if (local_3cc == 0x80) goto LAB_00016c2e;
            }
            if (0x1f < local_3cc - 0x20) {
              if (local_3cc - 0x40 < 0x20) {
                if ((uVar35 & 1) == 0) {
                  uVar35 = uVar35 >> 1;
                }
                else {
                  uVar35 = uVar35 >> 1;
                  if (*(int *)(iVar30 + iVar33) < iVar29) {
                    uVar18 = 2;
                  }
                }
              }
              else if ((uVar36 & 1) == 0) {
                uVar36 = uVar36 >> 1;
              }
              else {
                uVar36 = uVar36 >> 1;
                if (*(int *)(iVar30 + iVar33) < iVar29) {
                  uVar18 = 2;
                }
              }
              goto LAB_00016bfe;
            }
            if (-1 < (int)(uVar34 << 0x1f)) {
              uVar34 = uVar34 >> 1;
              goto LAB_00016bfe;
            }
            piVar24 = (int *)(iVar30 + iVar33);
            local_3cc = local_3cc + 1;
            uVar34 = uVar34 >> 1;
            iVar33 = iVar33 + 4;
            if (*piVar24 < iVar29) {
              uVar18 = 2;
            }
          } while (local_3cc != 0x80);
LAB_00016c2e:
          uVar37 = uVar37 + 1;
          piVar38 = piVar38 + 1;
          local_3cc = 0x80;
        } while (uVar37 != local_3d0);
      }
LAB_00016c48:
      if ((*(int *)(iVar11 + 0xfa8) < 1) || (*puVar1 == 1)) {
        local_3a8 = DAT_000170b8;
        logstr_1._0_3_ = (undefined3)*DAT_000170b8;
        writeLogFile(logstr_1);
        if (0 < (int)local_3d0) goto LAB_00016d4c;
      }
      else {
        iVar30 = __aeabi_idiv(iVar29,*(undefined4 *)(DAT_00016e00 + 0xf0c));
        sprintf(logstr_1,DAT_00016e04);
        piVar38 = (int *)logstr_1;
        writeLogFile((char *)piVar38);
        puVar28 = DAT_00016e08;
        if ((int)local_3d0 < 1) {
          local_3a8 = DAT_000170b8;
          logstr_1._0_3_ = (undefined3)*DAT_000170b8;
          writeLogFile(logstr_1);
        }
        else {
          iVar33 = 0;
          uVar10 = 0;
          local_3a8 = DAT_00016e08;
          iVar21 = local_3a4 << 0x10;
          do {
            iVar31 = *(int *)(iVar11 + 0xf0c);
            if (iVar31 < 1) {
              iVar15 = 0;
            }
            else {
              iVar15 = 0;
              piVar38 = (int *)(DAT_00016e10 + -4 + (iVar31 + iVar21) * 4);
              piVar24 = (int *)(DAT_00016e10 + (local_3a4 * 0x100 + uVar10) * 0x400 + -4);
              do {
                piVar24 = piVar24 + 1;
                if (0 < *piVar24) {
                  iVar15 = iVar15 + 1;
                }
              } while (piVar24 != piVar38);
            }
            iVar25 = *(int *)(local_3b4 + iVar33);
            iVar31 = iVar31 - iVar25;
            if (iVar15 < iVar31) {
              piVar38 = (int *)0x0;
              iVar5 = local_3b8;
            }
            else {
              *(undefined4 *)(local_3b8 + iVar33) = 1;
              iVar5 = iVar31;
            }
            iVar26 = *(int *)(local_3c0 + iVar33);
            if (iVar15 < iVar31) {
              *(int **)(iVar5 + iVar33) = piVar38;
            }
            if (iVar26 < iVar29 - iVar25 * iVar30) {
              piVar38 = (int *)0x0;
              *(undefined4 *)(local_3c8 + iVar33) = 0;
            }
            else {
              *(undefined4 *)(local_3c8 + iVar33) = 1;
            }
            if (iVar26 < iVar29) {
              sprintf(logstr_1,DAT_000170b0);
              writeLogFile(logstr_1);
              if (0 < *(int *)(iVar11 + 0xf0c)) {
                iVar31 = 0;
                piVar38 = (int *)(DAT_00017114 + (local_3a4 * 0x100 + uVar10) * 0x400 + -4);
                do {
                  piVar38 = piVar38 + 1;
                  iVar31 = iVar31 + 1;
                  if (iVar30 != *piVar38) {
                    sprintf(logstr_1,DAT_000170b4);
                    writeLogFile(logstr_1);
                  }
                } while (iVar31 < *(int *)(iVar11 + 0xf0c));
              }
              piVar38 = (int *)logstr_1;
              uVar3 = (undefined2)*puVar28;
              logstr_1[0] = (char)uVar3;
              logstr_1[1] = (char)((ushort)uVar3 >> 8);
              writeLogFile((char *)piVar38);
            }
            uVar10 = uVar10 + 1;
            iVar33 = iVar33 + 4;
            iVar21 = iVar21 + 0x100;
          } while (uVar10 != local_3d0);
          uVar3 = (undefined2)*puVar28;
          logstr_1[0] = (char)uVar3;
          logstr_1[1] = (char)((ushort)uVar3 >> 8);
          writeLogFile(logstr_1);
LAB_00016d4c:
          iVar29 = getChainAsicFreqIndex(local_3a4,0);
          iVar29 = get_freqvalue_by_index(iVar29);
          iVar11 = 0;
          sprintf(logstr_1,DAT_00016e0c,0,iVar29);
          writeLogFile(logstr_1);
          while (iVar11 = iVar11 + 1, iVar11 < (int)local_3d0) {
            iVar29 = getChainAsicFreqIndex(local_3a4,iVar11);
            iVar29 = get_freqvalue_by_index(iVar29);
            sprintf(logstr_1,DAT_00016e0c,iVar11,iVar29);
            writeLogFile(logstr_1);
            if (iVar11 % 8 == 7) {
              logstr_1[0] = '\n';
              logstr_1[1] = '\0';
              writeLogFile(logstr_1);
            }
          }
        }
      }
      iVar29 = DAT_000170bc;
      logstr_1[0] = (char)(short)*local_3a8;
      logstr_1[1] = (char)((ushort)(short)*local_3a8 >> 8);
      writeLogFile(logstr_1);
      if (*(int *)(local_3b0 + DAT_000170c0) < iVar27) {
        uVar18 = 2;
      }
      sprintf(logstr_1,DAT_000170c4,*(int *)(local_3b0 + DAT_000170c0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_000170c8,*(undefined4 *)(iVar29 + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_000170cc,iVar27);
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_000170d0,*(undefined4 *)(iVar29 + -0x84 + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_000170d4,*(undefined4 *)(iVar29 + -0x44 + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,DAT_000170dc,*(undefined4 *)(DAT_000170d8 + local_3b0));
      writeLogFile(logstr_1);
      *(undefined4 *)(DAT_000170e0 + 0xd70) = uVar18;
    }
    iVar11 = DAT_00017118;
    iVar29 = DAT_000170ec;
    iVar27 = DAT_000170e8;
    local_3b0 = local_3b0 + 4;
    local_3c8 = local_3c8 + 0x400;
    local_3a4 = local_3a4 + 1;
    local_3ac = local_3ac + 0x100;
    local_3c0 = local_3c0 + 0x400;
    local_3b8 = local_3b8 + 0x400;
    local_3b4 = local_3b4 + 0x400;
    if (local_3b0 == 0x40) {
      _Var32 = true;
      iVar30 = 0;
      do {
        local_39c = local_39c + 1;
        if (*local_39c != 0) {
          iVar33 = 0;
          do {
            piVar38 = (int *)(iVar17 + iVar33);
            iVar33 = iVar33 + 4;
            if (*piVar38 == 0) {
              sprintf(logstr,DAT_000170fc,iVar30);
              writeLogFile(logstr);
              *(undefined *)(iVar30 + iVar27) = 1;
              *(undefined *)(iVar30 + iVar29) = 0;
              goto LAB_00016fe0;
            }
          } while (iVar33 != 0x48);
          sprintf(logstr,DAT_000170f0,iVar30);
          writeLogFile(logstr);
          *(undefined *)(iVar30 + iVar27) = 0;
          *(undefined *)(iVar30 + iVar29) = 1;
LAB_00016fe0:
          iVar33 = 0;
          do {
            piVar38 = (int *)(iVar9 + iVar33);
            iVar33 = iVar33 + 4;
            if (*piVar38 == 0) {
              sprintf(logstr,DAT_000170f8,iVar30);
              writeLogFile(logstr);
              *(undefined *)(iVar30 + iVar11) = 0;
              _Var32 = false;
              goto LAB_00016ffe;
            }
          } while (iVar33 != 0x48);
          sprintf(logstr,DAT_000170f4,iVar30);
          writeLogFile(logstr);
        }
LAB_00016ffe:
        iVar30 = iVar30 + 1;
        iVar9 = iVar9 + 0x400;
        iVar17 = iVar17 + 0x400;
        if (iVar30 == 0x10) {
          return _Var32;
        }
      } while( true );
    }
  } while( true );
code_r0x0001674a:
  pthread_mutex_lock(DAT_00016a4c);
  set_TW_write_command(buf);
  pthread_mutex_unlock(DAT_00016a4c);
  *(int *)((int)which_asic + iVar27) = iVar30;
LAB_00016768:
  iVar33 = iVar33 + 4;
  iVar11 = 0;
  iVar9 = 0;
  *(int *)(iVar27 + iVar17) = *(int *)(iVar27 + iVar17) + 1;
  if (0x11 < iVar30) goto LAB_00016786;
  goto LAB_0001665c;
}

