
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_Bool doTestBoard(int test_times)

{
  bool bVar1;
  int (*paiVar2) [256];
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *extraout_r0;
  int *piVar9;
  int *extraout_r0_00;
  uchar *puVar10;
  uint *puVar11;
  char *__format;
  uint *puVar12;
  undefined4 uVar13;
  vil_work_1387 *pvVar14;
  uint *puVar15;
  int iVar16;
  byte *pbVar17;
  vil_work_1387 *pvVar18;
  int *piVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int (*paiVar25) [256];
  _Bool _Var26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint local_3d0;
  uint local_3cc;
  int (*local_3c8) [256];
  int (*local_3c0) [256];
  int (*local_3b8) [256];
  int (*local_3b4) [256];
  int local_3b0;
  int local_3ac;
  int local_3a4;
  uint *local_39c;
  int (*local_394) [256];
  int (*local_390) [256];
  _Bool sendStartFlag [16];
  uchar data_fil [52];
  vil_work_1387 work_vil_1387;
  uint buf [13];
  uint buf_vil [13];
  int which_asic [16];
  int index [16];
  char logstr [256];
  char logstr_1 [256];
  
  local_39c = &cgpu.CommandMode;
  memset(asic_nonce_num,0,0x4000);
  memset(asic_core_nonce_num,0,0x400000);
  puVar11 = &cgpu.CommandMode;
  memset(repeated_nonce_id,0xff,0x4000);
  memset(err_nonce_num,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(repeated_nonce_num,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(send_work_num,0,0x40);
  total_valid_nonce_num = 0;
  start_receive = true;
  iVar7 = 0;
  do {
    iVar22 = iVar7 + 1;
    uVar6 = getChainExistFlag(iVar7);
    puVar11 = puVar11 + 1;
    *puVar11 = uVar6;
    iVar23 = conf.asicNum;
    iVar8 = conf.dataCount;
    iVar7 = iVar22;
  } while (iVar22 != 0x10);
  if (0 < conf.asicNum) {
    iVar7 = 0;
    puVar11 = cgpu.results[0x7f] + 4999;
    puVar12 = (uint *)((int)(cgpu.results + -1) + 0x4e1c + conf.dataCount * 4);
    do {
      if (0 < iVar8) {
        puVar15 = cgpu.results[iVar7 + -1] + 4999;
        do {
          puVar15 = puVar15 + 1;
          *puVar15 = 0;
        } while (puVar15 != puVar12);
      }
      iVar7 = iVar7 + 1;
      puVar12 = puVar12 + 5000;
      puVar11 = puVar11 + 1;
      *puVar11 = 0;
    } while (iVar7 != iVar23);
  }
  cgpu.real_asic_num = 0x12;
  puVar11 = &cgpu.CommandMode;
  cgpu.index = 0;
  cgpu.repeated_nonce = 0;
  cgpu.err_nonce = 0;
  cgpu.asicNum = iVar23;
  cgpu.valid_nonce = 0;
  cgpu.CommandMode = 0;
  cgpu.AsicType = 0x56b;
  cgpu.core_num = conf.core;
  pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
  iVar7 = 0;
LAB_000164e2:
  do {
    puVar11 = puVar11 + 1;
    if (*puVar11 != 0) {
      iVar8 = getChainAsicNum(iVar7);
      _Var26 = chain_need_opencore[iVar7];
      cgpu.chain_asic_num[iVar7] = (uchar)iVar8;
      if (_Var26 != false) {
        sprintf(logstr,"do open core on Chain[%d]...\n",iVar7);
        writeLogFile(logstr);
        open_core_one_chain(iVar7,true);
        iVar8 = iVar7 + 1;
        sprintf(logstr,"Done open core on Chain[%d]!\n",iVar7);
        writeLogFile(logstr);
        iVar7 = iVar8;
        if (iVar8 == 0x10) break;
        goto LAB_000164e2;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
  if (gBegin_get_nonce == false) {
    puts("clement2 set_nonce_fifo_interrupt");
    uVar6 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar6 | 0x10000);
    gBegin_get_nonce = true;
  }
  puVar11 = &cgpu.CommandMode;
  iVar7 = 0;
  do {
    puVar11 = puVar11 + 1;
    if (*puVar11 != 0) {
      sprintf(logstr,"start send works on chain[%d]\n",iVar7);
      writeLogFile(logstr);
      StartSendFlag[iVar7] = true;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  iVar8 = 0;
  data_fil[0] = 0xff;
  data_fil[1] = '\0';
  data_fil[2] = '\0';
  data_fil[3] = '\0';
  iVar7 = 0;
  buf[4] = 0;
  buf[5] = 0;
  buf[6] = 0;
  buf[7] = 0;
  buf[8] = 0;
  buf[9] = 0;
  buf[10] = 0;
  buf_vil[5] = 0;
  buf[0xb] = 0;
  buf[0xc] = 0;
  data_fil[4] = '\0';
  data_fil[5] = '\0';
  data_fil[6] = '\0';
  data_fil[7] = '\0';
  data_fil[8] = '\0';
  data_fil[9] = '\0';
  data_fil[10] = '\0';
  data_fil[0xb] = '\0';
  data_fil[0xc] = '\0';
  data_fil[0xd] = '\0';
  data_fil[0xe] = '\0';
  data_fil[0xf] = '\0';
  data_fil[0x10] = '\0';
  data_fil[0x11] = '\0';
  data_fil[0x12] = '\0';
  data_fil[0x13] = '\0';
  data_fil[0x14] = '\0';
  data_fil[0x15] = '\0';
  data_fil[0x16] = '\0';
  data_fil[0x17] = '\0';
  data_fil[0x18] = '\0';
  data_fil[0x19] = '\0';
  data_fil[0x1a] = '\0';
  data_fil[0x1b] = '\0';
  data_fil[0x1c] = '\0';
  data_fil[0x1d] = '\0';
  data_fil[0x1e] = '\0';
  data_fil[0x1f] = '\0';
  data_fil[0x20] = '\0';
  data_fil[0x21] = '\0';
  data_fil[0x22] = '\0';
  data_fil[0x23] = '\0';
  data_fil[0x24] = '\0';
  data_fil[0x25] = '\0';
  data_fil[0x26] = '\0';
  data_fil[0x27] = '\0';
  data_fil[0x28] = '\0';
  data_fil[0x29] = '\0';
  data_fil[0x2a] = '\0';
  data_fil[0x2b] = '\0';
  data_fil[0x2c] = '\0';
  data_fil[0x2d] = '\0';
  data_fil[0x2e] = '\0';
  data_fil[0x2f] = '\0';
  data_fil[0x30] = '\0';
  data_fil[0x31] = '\0';
  data_fil[0x32] = '\0';
  data_fil[0x33] = '\0';
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
  buf_vil[0xb] = 0;
  buf_vil[0xc] = 0;
  do {
    *(undefined4 *)((int)index + iVar8) = 0;
    _Var26 = StartSendFlag[iVar7];
    *(undefined4 *)((int)which_asic + iVar8) = 0;
    iVar8 = iVar8 + 4;
    sendStartFlag[iVar7] = _Var26;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  iVar7 = 0;
  do {
    iVar8 = 0;
    local_3d0 = 0;
    do {
      if ((*(int *)((int)cgpu.chain_exist + iVar8) != 0) && (sendStartFlag[local_3d0] != false)) {
        iVar23 = *(int *)((int)which_asic + iVar8);
        if (iVar23 < 0x12) {
          iVar27 = 0;
          iVar22 = iVar7;
          iVar24 = iVar23;
LAB_0001665c:
          iVar24 = iVar24 + 1;
          uVar6 = get_buffer_space();
          if ((uVar6 & 1 << (local_3d0 & 0xff)) != 0) {
            if (cgpu.CommandMode != 0) {
              uVar6 = *(uint *)((int)index + iVar8);
              buf[0] = 0;
              buf[1] = 0;
              buf[2] = 0;
              iVar22 = uVar6 * 0x34 + *(int *)((int)cgpu.works + iVar27 + iVar23 * 4);
              buf[3] = buf[3] & 0xffffff00;
              data_fil[4] = '\0';
              data_fil[5] = '\0';
              data_fil[6] = '\0';
              data_fil[7] = '\0';
              data_fil[8] = '\0';
              data_fil[9] = '\0';
              data_fil[10] = '\0';
              data_fil[0xb] = '\0';
              data_fil[0xc] = '\0';
              data_fil[0xd] = '\0';
              data_fil[0xe] = '\0';
              data_fil[0xf] = '\0';
              data_fil[0x10] = '\0';
              data_fil[0x11] = '\0';
              data_fil[0x12] = '\0';
              data_fil[0x13] = '\0';
              data_fil[0x14] = '\0';
              data_fil[0x15] = '\0';
              data_fil[0x16] = '\0';
              data_fil[0x17] = '\0';
              data_fil[0x18] = '\0';
              data_fil[0x19] = '\0';
              data_fil[0x1a] = '\0';
              data_fil[0x1b] = '\0';
              data_fil[0x1c] = '\0';
              data_fil[0x1d] = '\0';
              data_fil[0x1e] = '\0';
              data_fil[0x1f] = '\0';
              data_fil[0x20] = '\0';
              data_fil[0x21] = '\0';
              data_fil[0x22] = '\0';
              data_fil[0x23] = '\0';
              data_fil[0x24] = '\0';
              data_fil[0x25] = '\0';
              data_fil[0x26] = '\0';
              data_fil[0x27] = '\0';
              data_fil[0x28] = '\0';
              data_fil[0x29] = '\0';
              data_fil[0x2a] = '\0';
              data_fil[0x2b] = '\0';
              data_fil[0x2c] = '\0';
              data_fil[0x2d] = '\0';
              data_fil[0x2e] = '\0';
              data_fil[0x2f] = '\0';
              data_fil[0x30] = '\0';
              data_fil[0x31] = '\0';
              data_fil[0x32] = '\0';
              data_fil[0x33] = '\0';
              data_fil._0_4_ = CONCAT11((char)local_3d0,1) | 0x8000;
              iVar7 = 0;
              do {
                iVar16 = iVar7 + 1;
                data_fil[iVar7 + 4] = *(uchar *)(iVar22 + iVar7 + 0x14);
                iVar7 = iVar16;
              } while (iVar16 != 0x20);
              iVar7 = 0;
              do {
                pbVar17 = data_fil;
                iVar16 = iVar7 + 1;
                data_fil[iVar7 + 0x28] = *(uchar *)(iVar22 + iVar7 + 8);
                iVar7 = iVar16;
              } while (iVar16 != 0xc);
              puVar10 = work_vil_1387.midstate + 0x1c;
              iVar7 = 1;
              do {
                puVar10 = puVar10 + 4;
                *(uint *)puVar10 =
                     (uint)pbVar17[1] << 0x10 | (uint)*pbVar17 << 0x18 | (uint)pbVar17[3] |
                     (uint)pbVar17[2] << 8;
                if (iVar7 == 10) {
                  buf[9] = uVar6;
                }
                else if (iVar7 == 0xd) goto code_r0x0001674a;
                pbVar17 = pbVar17 + 4;
                iVar7 = iVar7 + 1;
              } while( true );
            }
            work_vil_1387.work_type = (undefined1)cgpu.CommandMode;
            work_vil_1387.chain_id = cgpu.CommandMode._1_1_;
            work_vil_1387.reserved1[0] = cgpu.CommandMode._2_1_;
            work_vil_1387.reserved1[1] = cgpu.CommandMode._3_1_;
            work_vil_1387.data[0] = (undefined1)cgpu.CommandMode;
            work_vil_1387.data[1] = cgpu.CommandMode._1_1_;
            work_vil_1387.data[2] = cgpu.CommandMode._2_1_;
            work_vil_1387.data[3] = cgpu.CommandMode._3_1_;
            work_vil_1387.work_count = *(uint *)((int)index + iVar8);
            work_vil_1387.data[8] = (undefined1)cgpu.CommandMode;
            work_vil_1387.data[9] = cgpu.CommandMode._1_1_;
            work_vil_1387.data[10] = cgpu.CommandMode._2_1_;
            work_vil_1387.data[0xb] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[0] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[1] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[2] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[3] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[4] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[5] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[6] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[7] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[8] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[9] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[10] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0xb] = cgpu.CommandMode._3_1_;
            iVar22 = work_vil_1387.work_count * 0x34 +
                     *(int *)((int)cgpu.works + iVar27 + iVar23 * 4);
            work_vil_1387.midstate[0xc] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[0xd] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[0xe] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0xf] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[0x10] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[0x11] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[0x12] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0x13] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[0x14] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[0x15] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[0x16] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0x17] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[0x18] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[0x19] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[0x1a] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0x1b] = cgpu.CommandMode._3_1_;
            buf_vil[2] = cgpu.CommandMode;
            buf_vil[3] = buf_vil[3] & 0xffffff00;
            work_vil_1387.data[4] = (undefined1)cgpu.CommandMode;
            work_vil_1387.data[5] = cgpu.CommandMode._1_1_;
            work_vil_1387.data[6] = cgpu.CommandMode._2_1_;
            work_vil_1387.data[7] = cgpu.CommandMode._3_1_;
            work_vil_1387.midstate[0x1c] = (undefined1)cgpu.CommandMode;
            work_vil_1387.midstate[0x1d] = cgpu.CommandMode._1_1_;
            work_vil_1387.midstate[0x1e] = cgpu.CommandMode._2_1_;
            work_vil_1387.midstate[0x1f] = cgpu.CommandMode._3_1_;
            work_vil_1387._0_4_ = CONCAT11((char)local_3d0,1) | 0x8000;
            iVar7 = 0;
            do {
              iVar16 = iVar7 + 1;
              work_vil_1387.data[iVar7] = *(uchar *)(iVar22 + iVar7 + 8);
              iVar7 = iVar16;
            } while (iVar16 != 0xc);
            iVar7 = 0;
            do {
              pvVar18 = &work_vil_1387;
              iVar16 = iVar7 + 1;
              work_vil_1387.midstate[iVar7] = *(uchar *)(iVar22 + iVar7 + 0x14);
              iVar7 = iVar16;
            } while (iVar16 != 0x20);
            puVar11 = buf_vil + 1;
            buf_vil[1] = work_vil_1387.work_count;
            buf_vil[0] = local_3d0 << 0x10 | 0x1800000;
            pvVar14 = pvVar18;
            do {
              puVar3 = pvVar14->data;
              puVar10 = pvVar14->data;
              puVar4 = pvVar14->data;
              puVar5 = pvVar14->data;
              pvVar14 = (vil_work_1387 *)&pvVar14->work_count;
              puVar11 = puVar11 + 1;
              *puVar11 = (uint)puVar3[1] << 0x10 | (uint)*puVar10 << 0x18 | (uint)puVar4[3] |
                         (uint)puVar5[2] << 8;
            } while (pvVar14 != (vil_work_1387 *)(work_vil_1387.data + 4));
            puVar11 = buf_vil + 4;
            do {
              puVar3 = pvVar18->midstate;
              puVar10 = pvVar18->midstate;
              puVar4 = pvVar18->midstate;
              puVar5 = pvVar18->midstate;
              pvVar18 = (vil_work_1387 *)&pvVar18->work_count;
              puVar11 = puVar11 + 1;
              *puVar11 = (uint)puVar3[1] << 0x10 | (uint)*puVar10 << 0x18 | (uint)puVar4[3] |
                         (uint)puVar5[2] << 8;
            } while (pvVar18 != (vil_work_1387 *)(work_vil_1387.midstate + 0xc));
            pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
            set_TW_write_command_vil(buf_vil);
            pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
            *(int *)((int)which_asic + iVar8) = iVar24;
            goto LAB_00016768;
          }
          iVar7 = iVar22 + 1;
          goto joined_r0x000169dc;
        }
LAB_00016786:
        *(undefined4 *)((int)which_asic + iVar8) = 0;
        iVar23 = *(int *)((int)chain_DataCount + iVar8);
        iVar22 = *(int *)((int)index + iVar8) + 1;
        *(int *)((int)index + iVar8) = iVar22;
        if (iVar23 <= iVar22) {
          sendStartFlag[local_3d0] = false;
        }
joined_r0x000169dc:
        if (2000 < iVar7) {
          builtin_strncpy(logstr_1,"Fatal Error: send work timeout\n",0x20);
          writeLogFile(logstr_1);
          break;
        }
      }
      iVar8 = iVar8 + 4;
      local_3d0 = local_3d0 + 1;
    } while (local_3d0 != 0x10);
    bVar1 = true;
    usleep(5000);
    iVar23 = 0;
    iVar8 = 0;
    do {
      if (((*(int *)((int)cgpu.chain_exist + iVar23) != 0) && (StartSendFlag[iVar8] != false)) &&
         (*(int *)((int)index + iVar23) < *(int *)((int)chain_DataCount + iVar23))) {
        bVar1 = false;
      }
      iVar8 = iVar8 + 1;
      iVar23 = iVar23 + 4;
    } while (iVar8 != 0x10);
  } while (!bVar1);
  iVar8 = 0;
  iVar7 = 0;
  do {
    while ((*(int *)((int)cgpu.chain_exist + iVar8) != 0 && (StartSendFlag[iVar7] != false))) {
      uVar13 = *(undefined4 *)((int)send_work_num + iVar8);
      StartSendFlag[iVar7] = false;
      iVar8 = iVar8 + 4;
      sprintf(logstr_1,"get send work num :%d on Chain[%d]\n",uVar13,iVar7);
      writeLogFile(logstr_1);
      sendExit[iVar7] = true;
      iVar7 = iVar7 + 1;
      if (iVar7 == 0x10) goto LAB_0001686e;
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 != 0x10);
LAB_0001686e:
  iVar7 = 0;
  iVar8 = 0;
  do {
    while (*(int *)((int)cgpu.chain_exist + iVar7) != 0) {
      iVar23 = 0;
      sprintf(logstr,"wait recv nonce on chain[%d]\n",iVar8);
      writeLogFile(logstr);
      iVar22 = 0;
      do {
        while( true ) {
          iVar24 = *(int *)((int)valid_nonce_num + iVar7);
          if (*(int *)((int)chain_ValidNonce + iVar7) <= iVar24) goto LAB_00016878;
          if (iVar22 == iVar24) break;
          usleep(100000);
          iVar23 = 0;
          iVar22 = iVar24;
        }
        iVar23 = iVar23 + 1;
        usleep(100000);
      } while (iVar23 < 0x14);
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 1;
      if (iVar7 == 0x40) goto LAB_00016a1c;
    }
LAB_00016878:
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar7 != 0x40);
LAB_00016a1c:
  local_394 = last_result;
  local_3c8 = last_result;
  gBegin_get_nonce = false;
  local_3ac = 0;
  local_390 = last_result_opencore;
  local_3b0 = 0;
  local_3a4 = 0;
  local_3b4 = chain_badcore_num;
  local_3c0 = asic_nonce_num;
  local_3b8 = last_result_opencore;
  start_receive = false;
  do {
    if (*(int *)((int)cgpu.chain_exist + local_3b0) != 0) {
      sprintf(logstr,"get nonces on chain[%d]\n",local_3a4);
      writeLogFile(logstr);
      uVar30 = conf.OpenCoreNum4;
      uVar29 = conf.OpenCoreNum3;
      uVar28 = conf.OpenCoreNum2;
      uVar6 = conf.OpenCoreNum1;
      iVar7 = *(int *)((int)chain_ValidNonce + local_3b0);
      iVar8 = *(int *)((int)chain_PassCount + local_3b0);
      puts(
          "\n------------------------------------------------------------------------------------------------------"
          );
      if (conf.CommandMode == 0) {
        puts("Command mode is VIL");
      }
      else {
        puts("Command mode is FIL");
      }
      local_3d0 = cgpu.real_asic_num;
      if (cgpu.real_asic_num == 1) {
        printf("Open core number : Conf.OpenCoreNum1 = %ud = 0x%x\n",Conf.OpenCoreNum1,
               Conf.OpenCoreNum1);
        printf("Open core number : Conf.OpenCoreNum2 = %ud = 0x%x\n",Conf.OpenCoreNum2,
               Conf.OpenCoreNum2);
        printf("Open core number : Conf.OpenCoreNum3 = %ud = 0x%x\n",Conf.OpenCoreNum3,
               Conf.OpenCoreNum3);
        printf("Open core number : Conf.OpenCoreNum4 = %ud = 0x%x\n",Conf.OpenCoreNum4,
               Conf.OpenCoreNum4);
        local_3d0 = Conf.CoreNum;
      }
      sprintf(logstr_1,"require nonce number:%d\n",iVar8);
      writeLogFile(logstr_1);
      sprintf(logstr_1,"require validnonce number:%d\n",iVar7);
      writeLogFile(logstr_1);
      if ((int)local_3d0 < 1) {
        iVar23 = 3;
      }
      else {
        local_3cc = 0;
        uVar31 = 0;
        piVar9 = asic_nonce_num[local_3a4];
        iVar23 = 3;
        do {
          while( true ) {
            if (cgpu.real_asic_num == 1) {
              __format = "core[%02d]=%02d\t";
            }
            else {
              __format = "asic[%02d]=%02d\t";
            }
            sprintf(logstr_1,__format,uVar31,*piVar9);
            writeLogFile(logstr_1);
            if ((uVar31 & 7) == 7) {
              logstr_1[0] = '\n';
              logstr_1[1] = '\0';
              writeLogFile(logstr_1);
            }
            if (cgpu.real_asic_num == 1) break;
            if (*piVar9 < iVar8) {
              iVar23 = 2;
            }
LAB_00016b8e:
            uVar31 = uVar31 + 1;
            piVar9 = piVar9 + 1;
            if (uVar31 == local_3d0) goto LAB_00016c48;
          }
          if (0x7f < local_3cc) goto LAB_00016b8e;
          iVar24 = 0;
          iVar22 = local_3cc + local_3ac;
          do {
            while ((int)local_3cc < 0x20) {
              if ((int)(uVar6 << 0x1f) < 0) {
                uVar6 = uVar6 >> 1;
                if (*(int *)((int)asic_nonce_num[0] + iVar24 + iVar22 * 4) < iVar8) {
                  iVar23 = 2;
                }
              }
              else {
                uVar6 = uVar6 >> 1;
              }
LAB_00016bfe:
              local_3cc = local_3cc + 1;
              iVar24 = iVar24 + 4;
              if (local_3cc == 0x80) goto LAB_00016c2e;
            }
            if (0x1f < local_3cc - 0x20) {
              if (local_3cc - 0x40 < 0x20) {
                if ((uVar29 & 1) == 0) {
                  uVar29 = uVar29 >> 1;
                }
                else {
                  uVar29 = uVar29 >> 1;
                  if (*(int *)((int)asic_nonce_num[0] + iVar24 + iVar22 * 4) < iVar8) {
                    iVar23 = 2;
                  }
                }
              }
              else if ((uVar30 & 1) == 0) {
                uVar30 = uVar30 >> 1;
              }
              else {
                uVar30 = uVar30 >> 1;
                if (*(int *)((int)asic_nonce_num[0] + iVar24 + iVar22 * 4) < iVar8) {
                  iVar23 = 2;
                }
              }
              goto LAB_00016bfe;
            }
            if (-1 < (int)(uVar28 << 0x1f)) {
              uVar28 = uVar28 >> 1;
              goto LAB_00016bfe;
            }
            iVar27 = iVar24 + iVar22 * 4;
            local_3cc = local_3cc + 1;
            uVar28 = uVar28 >> 1;
            iVar24 = iVar24 + 4;
            if (*(int *)((int)asic_nonce_num[0] + iVar27) < iVar8) {
              iVar23 = 2;
            }
          } while (local_3cc != 0x80);
LAB_00016c2e:
          uVar31 = uVar31 + 1;
          piVar9 = piVar9 + 1;
          local_3cc = 0x80;
        } while (uVar31 != local_3d0);
      }
LAB_00016c48:
      if ((Conf.StartSensor < 1) || (cgpu.real_asic_num == 1)) {
        logstr_1[0] = '\n';
        logstr_1[1] = '\n';
        logstr_1[2] = '\0';
        writeLogFile(logstr_1);
        if (0 < (int)local_3d0) goto LAB_00016d4c;
      }
      else {
        iVar22 = __aeabi_idiv(iVar8,Conf.CoreNum);
        sprintf(logstr_1,
                "\n\n\nBelow ASIC\'s core didn\'t receive all the nonce, they should receive %d nonce each!\n\n"
                ,iVar22);
        writeLogFile(logstr_1);
        if ((int)local_3d0 < 1) {
          logstr_1[0] = '\n';
          logstr_1[1] = '\n';
          logstr_1[2] = '\0';
          writeLogFile(logstr_1);
        }
        else {
          iVar24 = 0;
          uVar6 = 0;
          iVar27 = local_3a4 << 0x10;
          piVar9 = extraout_r0;
          do {
            if (Conf.CoreNum < 1) {
              iVar16 = 0;
            }
            else {
              iVar16 = 0;
              piVar9 = &total_valid_nonce_num + Conf.CoreNum + iVar27;
              piVar19 = &total_valid_nonce_num + (local_3a4 * 0x100 + uVar6) * 0x100;
              do {
                piVar19 = piVar19 + 1;
                if (0 < *piVar19) {
                  iVar16 = iVar16 + 1;
                }
              } while (piVar19 != piVar9);
            }
            iVar20 = *(int *)((int)*local_3b4 + iVar24);
            paiVar25 = (int (*) [256])(Conf.CoreNum - iVar20);
            if (iVar16 < (int)paiVar25) {
              piVar9 = (int *)0x0;
              paiVar2 = local_3b8;
            }
            else {
              *(undefined4 *)((int)*local_3b8 + iVar24) = 1;
              paiVar2 = paiVar25;
            }
            iVar21 = *(int *)((int)*local_3c0 + iVar24);
            if (iVar16 < (int)paiVar25) {
              *(int **)((int)*paiVar2 + iVar24) = piVar9;
            }
            if (iVar21 < iVar8 - iVar20 * iVar22) {
              piVar9 = (int *)0x0;
              *(undefined4 *)((int)*local_3c8 + iVar24) = 0;
            }
            else {
              *(undefined4 *)((int)*local_3c8 + iVar24) = 1;
            }
            if (iVar21 < iVar8) {
              sprintf(logstr_1,"asic[%02d]=%02d\n",uVar6);
              writeLogFile(logstr_1);
              if (0 < Conf.CoreNum) {
                piVar9 = &total_valid_nonce_num + (local_3a4 * 0x100 + uVar6) * 0x100;
                iVar16 = 0;
                do {
                  piVar9 = piVar9 + 1;
                  iVar20 = iVar16 + 1;
                  if (iVar22 != *piVar9) {
                    sprintf(logstr_1,"core[%03d]=%d\t",iVar16);
                    writeLogFile(logstr_1);
                  }
                  iVar16 = iVar20;
                } while (iVar20 < Conf.CoreNum);
              }
              logstr_1[0] = '\n';
              logstr_1[1] = '\n';
              writeLogFile(logstr_1);
              piVar9 = extraout_r0_00;
            }
            uVar6 = uVar6 + 1;
            iVar24 = iVar24 + 4;
            iVar27 = iVar27 + 0x100;
          } while (uVar6 != local_3d0);
          logstr_1[0] = '\n';
          logstr_1[1] = '\n';
          writeLogFile(logstr_1);
LAB_00016d4c:
          iVar8 = getChainAsicFreqIndex(local_3a4,0);
          iVar8 = get_freqvalue_by_index(iVar8);
          iVar22 = 0;
          sprintf(logstr_1,"freq[%02d]=%d\t",0,iVar8);
          writeLogFile(logstr_1);
          while (iVar22 = iVar22 + 1, iVar22 < (int)local_3d0) {
            iVar8 = getChainAsicFreqIndex(local_3a4,iVar22);
            iVar8 = get_freqvalue_by_index(iVar8);
            sprintf(logstr_1,"freq[%02d]=%d\t",iVar22,iVar8);
            writeLogFile(logstr_1);
            if (iVar22 % 8 == 7) {
              logstr_1[0] = '\n';
              logstr_1[1] = '\0';
              writeLogFile(logstr_1);
            }
          }
        }
      }
      logstr_1[0] = '\n';
      logstr_1[1] = '\n';
      writeLogFile(logstr_1);
      if (*(int *)((int)valid_nonce_num + local_3b0) < iVar7) {
        iVar23 = 2;
      }
      sprintf(logstr_1,"total valid nonce number:%d\n",*(int *)((int)valid_nonce_num + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,"total send work number:%d\n",*(undefined4 *)((int)send_work_num + local_3b0)
             );
      writeLogFile(logstr_1);
      sprintf(logstr_1,"require valid nonce number:%d\n",iVar7);
      writeLogFile(logstr_1);
      sprintf(logstr_1,"repeated_nonce_num:%d\n",
              *(undefined4 *)((int)repeated_nonce_num + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,"err_nonce_num:%d\n",*(undefined4 *)((int)err_nonce_num + local_3b0));
      writeLogFile(logstr_1);
      sprintf(logstr_1,"last_nonce_num:%d\n",*(undefined4 *)((int)last_nonce_num + local_3b0));
      writeLogFile(logstr_1);
      result = iVar23;
    }
    local_3b0 = local_3b0 + 4;
    local_3c8 = local_3c8 + 1;
    local_3a4 = local_3a4 + 1;
    local_3ac = local_3ac + 0x100;
    local_3c0 = local_3c0 + 1;
    local_3b8 = local_3b8 + 1;
    local_3b4 = local_3b4 + 1;
    if (local_3b0 == 0x40) {
      _Var26 = true;
      iVar7 = 0;
      do {
        local_39c = local_39c + 1;
        if (*local_39c != 0) {
          iVar8 = 0;
          do {
            piVar9 = (int *)((int)*local_390 + iVar8);
            iVar8 = iVar8 + 4;
            if (*piVar9 == 0) {
              sprintf(logstr,"chain[%d]: some chip cores are not opened FAILED!\n",iVar7);
              writeLogFile(logstr);
              chain_need_opencore[iVar7] = true;
              isChainAllCoresOpened[iVar7] = false;
              goto LAB_00016fe0;
            }
          } while (iVar8 != 0x48);
          sprintf(logstr,"chain[%d]: All chip cores are opened OK!\n",iVar7);
          writeLogFile(logstr);
          chain_need_opencore[iVar7] = false;
          isChainAllCoresOpened[iVar7] = true;
LAB_00016fe0:
          iVar8 = 0;
          do {
            piVar9 = (int *)((int)*local_394 + iVar8);
            iVar8 = iVar8 + 4;
            if (*piVar9 == 0) {
              sprintf(logstr,"Test Patten on chain[%d]: FAILED!\n",iVar7);
              writeLogFile(logstr);
              search_freq_result[iVar7] = false;
              _Var26 = false;
              goto LAB_00016ffe;
            }
          } while (iVar8 != 0x48);
          sprintf(logstr,"Test Patten on chain[%d]: OK!\n",iVar7);
          writeLogFile(logstr);
        }
LAB_00016ffe:
        iVar7 = iVar7 + 1;
        local_394 = local_394 + 1;
        local_390 = local_390 + 1;
        if (iVar7 == 0x10) {
          return _Var26;
        }
      } while( true );
    }
  } while( true );
code_r0x0001674a:
  pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
  set_TW_write_command(buf);
  pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
  *(int *)((int)which_asic + iVar8) = iVar24;
LAB_00016768:
  iVar27 = iVar27 + 4;
  iVar22 = 0;
  iVar7 = 0;
  *(int *)((int)send_work_num + iVar8) = *(int *)((int)send_work_num + iVar8) + 1;
  if (0x11 < iVar24) goto LAB_00016786;
  goto LAB_0001665c;
}

