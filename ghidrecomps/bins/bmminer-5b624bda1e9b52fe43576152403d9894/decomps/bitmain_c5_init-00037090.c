
int bitmain_c5_init(init_config config)

{
  int *piVar1;
  byte bVar2;
  ushort frequency;
  int iVar3;
  _func_void_ptr_void_ptr *p_Var4;
  thr_info **pptVar5;
  int *piVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  _Bool _Var11;
  uchar chCRCLo;
  uchar uVar12;
  undefined4 in_r0;
  uint uVar13;
  thr_info *ptVar14;
  uint uVar15;
  int hardware_version;
  char *pcVar16;
  uchar voltage;
  undefined4 in_r1;
  undefined4 uVar17;
  uint uVar18;
  int vol_value;
  undefined4 in_r2;
  undefined4 uVar19;
  byte *pbVar20;
  int new_T9_PLUS_chainIndex;
  int iVar21;
  undefined4 in_r3;
  undefined4 uVar22;
  undefined4 uVar23;
  int iVar24;
  int new_T9_PLUS_chainOffset;
  int iVar25;
  undefined4 *logstr_00;
  int iVar26;
  int iVar27;
  undefined4 *unaff_r7;
  undefined4 *puVar28;
  int iVar29;
  uchar vol_pic;
  uchar temp_voltage;
  int iVar30;
  int iVar31;
  uchar temp_voltage_1;
  undefined4 uVar32;
  bool bVar33;
  undefined4 *puVar34;
  double dVar35;
  int local_9b4;
  int local_9b0;
  sysinfo si;
  char logstr [256];
  char tmp42 [2048];
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = in_r0;
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  saveRestartNum(2);
  saveRebootTestNum(0);
  clearInitLogFile();
  _Var11 = isC5_Board();
  *(_Bool *)(DAT_000372c8 + 0x674) = _Var11;
  iVar25 = DAT_000372d0;
  if (_Var11) {
    logstr_00 = (undefined4 *)logstr;
    logstr._0_4_ = *DAT_000372cc;
    logstr._4_4_ = DAT_000372cc[1];
    logstr._8_4_ = DAT_000372cc[2];
    logstr._12_4_ = DAT_000372cc[3];
    puVar28 = DAT_000372cc + 4;
    *(undefined4 *)(DAT_000372d0 + 0x8c) = 0x3f000000;
    logstr._16_3_ = (undefined3)*puVar28;
  }
  else {
    sysinfo((sysinfo *)&si);
    puVar28 = DAT_00037300;
    iVar25 = DAT_000372d0;
    if (si.totalram < 0x3b9aca01) {
      if (500000000 < si.totalram) {
        unaff_r7 = DAT_000372f0;
      }
      puVar28 = (undefined4 *)logstr;
      if (si.totalram < 0x1dcd6501) {
        unaff_r7 = DAT_000372f4;
        puVar28 = &local_10;
      }
      logstr_00 = (undefined4 *)logstr;
      if (si.totalram < 0x1dcd6501) {
        uVar17 = 0xf000000;
      }
      else {
        uVar17 = 0x1f000000;
        logstr_00 = puVar28;
      }
      uVar19 = *unaff_r7;
      uVar22 = unaff_r7[1];
      uVar32 = unaff_r7[2];
      uVar23 = unaff_r7[3];
      *(undefined4 *)(DAT_000372d0 + 0x8c) = uVar17;
      *logstr_00 = uVar19;
      logstr_00[1] = uVar22;
      logstr_00[2] = uVar32;
      logstr_00[3] = uVar23;
      uVar17 = unaff_r7[5];
      uVar19 = unaff_r7[6];
      uVar22 = unaff_r7[7];
      logstr_00[4] = unaff_r7[4];
      logstr_00[5] = uVar17;
      logstr_00[6] = uVar19;
      logstr_00[7] = uVar22;
      uVar17 = unaff_r7[9];
      logstr_00[8] = unaff_r7[8];
      *(short *)(logstr_00 + 9) = (short)uVar17;
    }
    else {
      logstr_00 = (undefined4 *)logstr;
      logstr._0_4_ = *DAT_00037300;
      logstr._4_4_ = DAT_00037300[1];
      logstr._8_4_ = DAT_00037300[2];
      logstr._12_4_ = DAT_00037300[3];
      puVar34 = DAT_00037300 + 4;
      *(undefined4 *)(DAT_000372d0 + 0x8c) = 0x3f000000;
      logstr._16_4_ = *puVar34;
      logstr._20_4_ = puVar28[5];
      logstr._24_4_ = puVar28[6];
      logstr._28_4_ = puVar28[7];
      logstr._32_4_ = puVar28[8];
    }
  }
  writeInitLogFile((char *)logstr_00);
  iVar3 = DAT_000372d4;
  uVar17 = DAT_0003730c[1];
  uVar19 = DAT_0003730c[2];
  uVar22 = DAT_0003730c[3];
  uVar32 = DAT_0003730c[4];
  *logstr_00 = *DAT_0003730c;
  logstr_00[1] = uVar17;
  logstr_00[2] = uVar19;
  logstr_00[3] = uVar22;
  *(short *)(logstr_00 + 4) = (short)uVar32;
  puVar28 = (undefined4 *)(DAT_000372d4 + 0x94c);
  writeInitLogFile((char *)logstr_00);
  *puVar28 = local_10;
  *(undefined4 *)(iVar3 + 0x950) = uStack_c;
  *(undefined4 *)(iVar3 + 0x954) = uStack_8;
  *(undefined4 *)(iVar3 + 0x958) = uStack_4;
  *(undefined4 *)(iVar3 + 0x95c) = config._0_4_;
  *(undefined4 *)(iVar3 + 0x960) = config._4_4_;
  *(undefined4 *)(iVar3 + 0x964) = config._8_4_;
  *(undefined4 *)(iVar3 + 0x968) = config._12_4_;
  pptVar5 = DAT_00037310;
  iVar27 = DAT_000372d4;
  if (*(byte *)(iVar3 + 0x94c) != 0x51) {
    if ((*DAT_000372d8 != '\0') &&
       (((*DAT_000372dc != '\0' || (*DAT_000372e0 != '\0')) || (6 < *DAT_000372e4)))) {
      snprintf(tmp42,0x800,DAT_000372e8,DAT_000372ec,0x51,(uint)*(byte *)(iVar3 + 0x94c));
      _applog(7,tmp42,false);
      return -1;
    }
    return -1;
  }
  uVar18 = 0xff;
  uVar13 = 0xff;
  pbVar20 = (byte *)(iVar3 + 0x94c);
  uVar15 = 0x51;
  while( true ) {
    iVar24 = (uVar15 ^ uVar13) + DAT_000372f8;
    uVar13 = uVar18 ^ *(byte *)(iVar24 + 0x7b8);
    uVar18 = (uint)*(byte *)(iVar24 + 0x8b8);
    if (pbVar20 == (byte *)(iVar3 + 0x969)) break;
    pbVar20 = pbVar20 + 1;
    uVar15 = (uint)*pbVar20;
  }
  uVar13 = uVar13 | uVar18 << 8;
  if (*(ushort *)(iVar3 + 0x96a) != uVar13) {
    if ((*DAT_000372d8 != '\0') &&
       (((*DAT_000372dc != '\0' || (*DAT_000372e0 != '\0')) || (6 < *DAT_000372e4)))) {
      snprintf(tmp42,0x800,DAT_000372fc,DAT_000372ec,(uint)*(ushort *)(iVar3 + 0x96a),uVar13);
      _applog(7,tmp42,false);
      return -2;
    }
    return -2;
  }
  ptVar14 = (thr_info *)calloc(1,0x40);
  p_Var4 = DAT_00037304;
  *pptVar5 = ptVar14;
  iVar24 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,p_Var4,ptVar14);
  if (iVar24 != 0) {
    if ((*DAT_000372d8 != '\0') &&
       (((*DAT_000372dc != '\0' || (*DAT_000372e0 != '\0')) || (6 < *DAT_000372e4)))) {
      snprintf(tmp42,0x800,DAT_00037308,DAT_000372ec);
      _applog(7,tmp42,false);
      return -5;
    }
    return -5;
  }
  pthread_detach((*pptVar5)->pth);
  bitmain_axi_init();
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  if ((int)((uint)*(byte *)(iVar27 + 0x950) << 0x1f) < 0) {
    set_QN_write_data_command(0x8080800f);
    sleep(2);
    set_PWM('d');
  }
  iVar27 = DAT_00037660;
  piVar6 = DAT_00037634;
  iVar29 = 0;
  iVar24 = 0;
  *axi_fpga_addr = 0x80000000;
  uVar15 = get_hardware_version();
  pcVar16 = DAT_0003763c;
  uVar13 = (uVar15 << 1) >> 0x11;
  fpga_version = uVar15 & 0xff;
  *DAT_00037638 = uVar13;
  sprintf(pcVar16,DAT_00037640,uVar15 & 0xff,uVar13,1,3);
  set_reset_allhashboard(1);
  uVar15 = *(uint *)(iVar25 + 0x8c);
  *(undefined *)(*piVar6 + 0x2fea) = 0x1a;
  set_nonce2_and_job_id_store_address(uVar15);
  set_job_start_address(*(int *)(iVar25 + 0x8c) + 0x200000);
  check_chain();
  do {
    if (*(int *)(*piVar6 + (iVar24 + 2) * 4) == 1) {
      pthread_mutex_lock(DAT_00037644);
      get_hash_board_id_number((uchar)iVar24,hash_board_id[iVar24]);
      pcVar16 = bin2hex(hash_board_id[iVar24],0xc);
      iVar30 = iVar29 * 0x22;
      iVar29 = iVar29 + 1;
      sprintf((char *)(iVar27 + iVar30),DAT_00037648,pcVar16);
      free(pcVar16);
      pthread_mutex_unlock(DAT_00037644);
    }
    iVar24 = iVar24 + 1;
  } while (iVar24 != 0x10);
  iVar30 = 0;
  iVar24 = 0;
  uVar15 = 0xffffffff;
  *(undefined *)(iVar27 + iVar29 * 0x22 + -1) = 0;
  iVar27 = 1;
  do {
    if (*(int *)(*piVar6 + (iVar24 + 2) * 4) == 1) {
      uVar12 = (uchar)iVar24;
      if (fpga_version < 0xe) {
        pthread_mutex_lock(DAT_00037644);
        if (iVar24 % 3 == 0) {
          reset_iic_pic(uVar12);
          sleep(1);
          jump_to_app_CheckAndRestorePIC_T9_18(iVar24);
          if (opt_fixed_freq != false) goto LAB_000374da;
          read_freq_badcores(uVar12,(uchar *)(DAT_00037924 + (iVar24 / 3) * 0x180));
        }
        pcVar16 = DAT_000383cc;
        if (opt_fixed_freq == false) {
          iVar31 = iVar24 / 3;
          iVar29 = (iVar24 % 3) * 0x1f;
          if (chain_pic_buf[iVar31 * 3][0] == '}') {
            *(uint *)(iVar30 + DAT_000383c0) = (uint)chain_pic_buf[iVar31 * 3][iVar29 + 8] * 10;
            sprintf((char *)logstr_00,pcVar16,iVar27);
            writeInitLogFile((char *)logstr_00);
          }
          uVar12 = chain_pic_buf[iVar31 * 3][iVar29 + 10];
          goto LAB_00037598;
        }
      }
      else {
        if (uVar15 < 0xd) {
          local_9b0 = *(int *)(DAT_0003764c + iVar30 + -4);
          local_9b4 = *(int *)(DAT_0003764c + iVar30 + 0x30);
          pthread_mutex_lock(DAT_00037644);
          if (uVar15 < 3) {
            reset_iic_pic(uVar12);
            jump_to_app_CheckAndRestorePIC_T9_18(iVar24);
            if (opt_fixed_freq != false) goto LAB_000374da;
            read_freq_badcores(uVar12,(uchar *)(DAT_00037650 + iVar24 * 0x80));
            sprintf((char *)logstr_00,DAT_00037654,iVar24);
            writeInitLogFile((char *)logstr_00);
            uVar13 = 0;
            do {
              sprintf((char *)logstr_00,DAT_00037658,(uint)chain_pic_buf[iVar24][uVar13]);
              writeInitLogFile((char *)logstr_00);
              uVar13 = uVar13 + 1 & 0xff;
            } while (uVar13 != 0x80);
            *(undefined2 *)logstr_00 = 10;
            writeInitLogFile((char *)logstr_00);
          }
        }
        else {
          local_9b4 = 0;
          pthread_mutex_lock(DAT_00037644);
          local_9b0 = 0;
        }
        pcVar16 = DAT_00037934;
        if (opt_fixed_freq == false) {
          if (chain_pic_buf[local_9b0][0] == '}') {
            *(uint *)(iVar30 + DAT_00037940) =
                 (uint)chain_pic_buf[local_9b0][local_9b4 * 0x1f + 8] * 10;
            sprintf((char *)logstr_00,pcVar16,iVar27);
            writeInitLogFile((char *)logstr_00);
          }
          uVar12 = chain_pic_buf[local_9b0][local_9b4 * 0x1f + 10];
LAB_00037598:
          pcVar16 = DAT_0003765c;
          *(int *)(iVar30 + DAT_00037664) = (int)(char)uVar12;
          sprintf((char *)logstr_00,pcVar16,iVar27,(int)(char)uVar12);
          writeInitLogFile((char *)logstr_00);
        }
      }
LAB_000374da:
      pthread_mutex_unlock(DAT_00037644);
    }
    pptVar5 = DAT_00037938;
    iVar24 = iVar24 + 1;
    iVar27 = iVar27 + 1;
    iVar30 = iVar30 + 4;
    uVar15 = uVar15 + 1;
  } while (iVar24 != 0x10);
  ptVar14 = (thr_info *)calloc(1,0x40);
  p_Var4 = DAT_00037908;
  *pptVar5 = ptVar14;
  iVar27 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,p_Var4,ptVar14);
  if (iVar27 == 0) {
    iVar24 = 1;
    pthread_detach((*pptVar5)->pth);
    iVar27 = 0;
    do {
      if (*(int *)(*piVar6 + (iVar27 + 2) * 4) == 1) {
        pthread_mutex_lock(DAT_00037928);
        uVar12 = get_pic_voltage((uchar)iVar27);
        pcVar16 = DAT_0003792c;
        *(uchar *)(DAT_0003793c + iVar27) = uVar12;
        sprintf((char *)logstr_00,pcVar16,iVar24,0x3a2,1);
        writeInitLogFile((char *)logstr_00);
        if (fpga_version < 0xe) {
          if (iVar27 % 3 == 0) goto LAB_00037872;
        }
        else if (iVar27 - 1U < 3) {
LAB_00037872:
          set_voltage_T9_18_into_PIC((uchar)iVar27,'\x01');
        }
        pthread_mutex_unlock(DAT_00037928);
      }
      iVar30 = DAT_00037940;
      iVar29 = DAT_0003793c;
      dVar10 = DAT_00037900;
      dVar9 = DAT_000378f8;
      dVar8 = DAT_000378f0;
      dVar7 = DAT_000378e8;
      iVar27 = iVar27 + 1;
      iVar24 = iVar24 + 1;
    } while (iVar27 != 0x10);
    if (opt_fixed_freq == false) {
LAB_000377b0:
      iVar27 = DAT_0003793c;
      dVar10 = DAT_00037900;
      dVar9 = DAT_000378f8;
      dVar8 = DAT_000378f0;
      dVar7 = DAT_000378e8;
      iVar29 = 1;
      iVar24 = 0;
      cgsleep_ms(100);
      do {
        if (*(int *)(*piVar6 + (iVar24 + 2) * 4) == 1) {
          pthread_mutex_lock(DAT_00037928);
          uVar15 = (uint)*(byte *)(iVar27 + iVar24);
          iVar31 = ((int)(longlong)
                         (((dVar8 / ((double)(longlong)(int)uVar15 + dVar7) + dVar9) * dVar10) /
                         4.75) / 10) * 10;
          sprintf((char *)logstr_00,DAT_00037930,iVar29,uVar15,iVar31);
          writeInitLogFile((char *)logstr_00);
          iVar30 = getChainPICMagicNumber(iVar24);
          if ((iVar30 == 0x7d) && (iVar30 = *(int *)(DAT_000383c0 + iVar24 * 4), iVar30 != iVar31))
          {
            dVar35 = dVar8 / (((double)(longlong)iVar30 * 4.75) / dVar10 - dVar9) - dVar7;
            uVar13 = (uint)(0.0 < dVar35) * (int)(longlong)dVar35;
            uVar15 = uVar13 & 0xff;
            sprintf((char *)logstr_00,DAT_000383c4,iVar29,iVar30,uVar15);
            writeInitLogFile((char *)logstr_00);
            pcVar16 = DAT_000383c8;
            *(char *)(iVar24 + iVar27) = (char)uVar13;
            sprintf((char *)logstr_00,pcVar16,iVar29,uVar15);
            writeInitLogFile((char *)logstr_00);
          }
          pthread_mutex_unlock(DAT_00037928);
        }
        iVar24 = iVar24 + 1;
        iVar29 = iVar29 + 1;
      } while (iVar24 != 0x10);
      cgsleep_ms(1000);
    }
    else {
      iVar27 = 0;
      do {
        if (*(int *)(*piVar6 + (iVar27 + 2) * 4) == 1) {
          uVar15 = (uint)*(ushort *)(iVar3 + 0x958);
          if (uVar15 < 0x28a) {
            if (uVar15 < 0x271) {
              if (uVar15 < 600) {
                if (uVar15 < 0x23f) {
                  if (uVar15 < 0x21f) {
                    vol_value = 0x3a2;
                    if (0x203 < uVar15) {
                      vol_value = 0x398;
                    }
                  }
                  else {
                    vol_value = 0x37a;
                  }
                }
                else {
                  vol_value = 0x366;
                }
              }
              else {
                vol_value = 0x352;
              }
            }
            else {
              vol_value = 0x33e;
            }
          }
          else {
            vol_value = 0x32a;
          }
          *(int *)(iVar30 + iVar27 * 4) = vol_value;
          pcVar16 = DAT_00037d10;
          dVar35 = dVar8 / (((double)(longlong)vol_value * 4.75) / dVar10 - dVar9) - dVar7;
          uVar13 = (uint)(0.0 < dVar35) * (int)(longlong)dVar35;
          *(char *)(iVar29 + iVar27) = (char)uVar13;
          sprintf((char *)logstr_00,pcVar16,uVar15,iVar27,uVar13 & 0xff,vol_value);
          writeInitLogFile((char *)logstr_00);
        }
        iVar27 = iVar27 + 1;
      } while (iVar27 != 0x10);
      if (opt_fixed_freq == false) goto LAB_000377b0;
    }
    iVar27 = 0;
    do {
      if (*(int *)(*piVar6 + (iVar27 + 2) * 4) == 1) {
        pthread_mutex_lock(DAT_00037d14);
        enable_pic_dac((uchar)iVar27);
        pthread_mutex_unlock(DAT_00037d14);
      }
      iVar27 = iVar27 + 1;
    } while (iVar27 != 0x10);
    sleep(5);
    set_reset_allhashboard(1);
    sleep(3);
    set_reset_allhashboard(0);
    sleep(1);
    if (opt_multi_version != 0) {
      uVar15 = get_dhash_acc_control();
      set_dhash_acc_control(uVar15 & 0xffff70df | 0x8100);
    }
    piVar1 = DAT_00037d34;
    cgsleep_ms(10);
    *(undefined *)(*piVar6 + 0x2fe7) = 0x72;
    check_asic_reg(0);
    cgsleep_ms(10);
    iVar27 = 1;
    do {
      iVar24 = iVar27 + 1;
      if (*(int *)(*piVar6 + iVar24 * 4) == 1) {
        sprintf((char *)logstr_00,DAT_00037d18,iVar27,
                (uint)*(byte *)(*piVar6 + iVar27 + -1 + 0x2faa));
        writeInitLogFile((char *)logstr_00);
        if (*(char *)(*piVar1 + iVar27 + -1 + 0x2faa) == '\0') {
          *(undefined4 *)(*piVar1 + iVar24 * 4) = 0;
        }
      }
      iVar27 = iVar24;
    } while (iVar24 != 0x11);
    software_set_address();
    cgsleep_ms(10);
    if ((int)((uint)*(byte *)(iVar3 + 0x950) << 0x1c) < 0) {
      frequency = *(ushort *)(DAT_00037d1c + 0x958);
      *(ushort *)(*piVar6 + 0x2fee) = frequency;
      set_frequency(frequency);
      sprintf((char *)(*piVar6 + 0x2ff0),DAT_000380d0,(uint)*(ushort *)(*piVar6 + 0x2fee));
    }
    cgsleep_ms(10);
    _Var11 = opt_debug;
    iVar27 = *piVar6;
    bVar2 = *(byte *)(iVar3 + 0x956);
    uVar15 = (uint)*(byte *)(iVar3 + 0x950) << 0x1e;
    *(byte *)(iVar27 + 0x2fec) = (byte)(uVar15 >> 0x1f);
    *(byte *)(iVar27 + 0x2fed) = bVar2;
    if ((_Var11 != false) &&
       (((*DAT_00037d20 != '\0' || (*DAT_00037d24 != '\0')) || (6 < *DAT_00037d28)))) {
      snprintf(tmp42,0x800,DAT_00037d2c,DAT_00037d30,uVar15 >> 0x1f,(uint)bVar2);
      _applog(7,tmp42,false);
    }
    if (((int)((uint)*(byte *)(iVar3 + 0x950) << 0x1e) < 0) &&
       (*(byte *)(DAT_00037d1c + 0x956) < 0x65)) {
      set_PWM(*(byte *)(DAT_00037d1c + 0x956));
    }
    else {
      set_PWM_according_to_temperature();
    }
    if ((int)((uint)*(byte *)(iVar3 + 0x950) << 0x1d) < 0) {
      if (*(short *)(DAT_00037d1c + 0x95e) == 0) {
        iVar27 = calculate_core_number((uint)*(byte *)(*piVar6 + 0x2fe7));
        iVar24 = *piVar6;
        iVar27 = __aeabi_idiv(0x1000000,iVar27);
        iVar27 = __aeabi_idiv((uint)*(byte *)(iVar24 + 0x2fe8) * iVar27,
                              *(undefined2 *)(iVar24 + 0x2fee));
        _Var11 = opt_debug;
        uVar15 = (iVar27 * 0x5a) / 100;
        *(uint *)(iVar24 + 0x48) = uVar15;
        if ((_Var11 != false) &&
           (((*DAT_000380a8 != '\0' || (*DAT_000380ac != '\0')) || (6 < *DAT_000380b0)))) {
          snprintf(tmp42,0x800,DAT_000380d4);
          _applog(7,tmp42,false);
          iVar24 = *piVar6;
          uVar15 = *(uint *)(iVar24 + 0x48);
        }
      }
      else {
        iVar24 = *piVar6;
        uVar15 = (uint)*(byte *)(DAT_00037d1c + 0x95e) * 1000 +
                 (uint)*(byte *)(DAT_00037d1c + 0x95f);
        *(uint *)(iVar24 + 0x48) = uVar15;
      }
      if (0x1ffff < uVar15) {
        *(undefined4 *)(iVar24 + 0x48) = 0x1ffff;
      }
    }
    init_uart_baud();
    iVar24 = 0;
    cgsleep_ms(10);
    iVar27 = *piVar6;
    do {
      if ((*(int *)(iVar27 + (iVar24 + 2) * 4) == 1) &&
         (*(char *)(iVar27 + iVar24 + 0x2faa) == '\x12')) {
        calibration_sensor_offset(0x98,iVar24);
        cgsleep_ms(10);
        iVar27 = *piVar6;
      }
      iVar29 = fpga_version;
      iVar24 = iVar24 + 1;
    } while (iVar24 != 0x10);
    uVar15 = 0;
    iVar24 = iVar27;
    iVar30 = iVar27;
    iVar31 = iVar27;
    do {
      if ((*(int *)(iVar24 + 8) == 1) && (*(char *)(iVar27 + uVar15 + 0x2faa) == '\x12')) {
        if (iVar29 < 0xe) {
          iVar21 = ((int)uVar15 / 3) * 3;
          if ((int)uVar15 % 3 != 1) {
            iVar26 = iVar21 + 1;
            *(undefined *)(iVar31 + 0x458) = *(undefined *)(iVar27 + iVar26 + 0x458);
            *(undefined *)(iVar30 + 0x4e8) = *(undefined *)(iVar27 + (iVar21 + 0x9e) * 8);
            *(undefined *)(iVar30 + 0x4e9) = *(undefined *)(iVar27 + iVar26 * 8 + 0x4e9);
          }
        }
        else if (uVar15 < 0xe) {
          uVar13 = 1 << (uVar15 & 0xff);
          if ((uVar13 & 0x2008) == 0) {
            if ((uVar13 & 0x804) == 0) {
              if ((uVar13 & 0x202) != 0) {
                *(undefined *)(iVar31 + 0x458) = *(undefined *)(iVar27 + 0x460);
                *(undefined *)(iVar30 + 0x4e8) = *(undefined *)(iVar27 + 0x528);
                *(undefined *)(iVar30 + 0x4e9) = *(undefined *)(iVar27 + 0x529);
              }
            }
            else {
              *(undefined *)(iVar31 + 0x458) = *(undefined *)(iVar27 + 0x462);
              *(undefined *)(iVar30 + 0x4e8) = *(undefined *)(iVar27 + 0x538);
              *(undefined *)(iVar30 + 0x4e9) = *(undefined *)(iVar27 + 0x539);
            }
          }
          else {
            *(undefined *)(iVar31 + 0x458) = *(undefined *)(iVar27 + 0x464);
            *(undefined *)(iVar30 + 0x4e8) = *(undefined *)(iVar27 + 0x548);
            *(undefined *)(iVar30 + 0x4e9) = *(undefined *)(iVar27 + 0x549);
          }
        }
      }
      uVar15 = uVar15 + 1;
      iVar24 = iVar24 + 4;
      iVar31 = iVar31 + 1;
      iVar30 = iVar30 + 8;
    } while (uVar15 != 0x10);
    if (opt_multi_version == 0) {
      set_time_out_control
                ((uint)((int)((ulonglong)*(uint *)(iVar27 + 0x48) * 0xcccccccd >> 0x20) << 0xc) >>
                 0xf | 0x80000000);
    }
    else {
      set_time_out_control
                ((uint)((int)((ulonglong)*(uint *)(iVar27 + 0x48) * 0xcccccccd >> 0x20) << 0xc) >>
                 0xf | 0x80000000);
    }
    set_PWM('d');
    dVar10 = DAT_00037d08;
    dVar9 = DAT_00037d00;
    dVar8 = DAT_00037cf8;
    dVar7 = DAT_00037cf0;
    iVar29 = 1;
    iVar27 = *piVar6;
    iVar24 = 0;
    do {
      if (*(int *)(iVar27 + (iVar24 + 2) * 4) == 1) {
        open_core_one_chain(iVar24,true);
        sleep(1);
        iVar27 = DAT_000380bc;
        if (fpga_version < 0xe) {
          uVar12 = (char)(iVar24 / 3) * '\x03';
          if (iVar24 % 3 == 2) {
            pthread_mutex_lock(DAT_000383d4);
            voltage = *(uchar *)(iVar27 + iVar24);
            goto LAB_000381b8;
          }
        }
        else {
          uVar12 = (uchar)iVar24;
          if (iVar24 == 1) {
            uVar17 = DAT_000383e4[1];
            uVar19 = DAT_000383e4[2];
            uVar22 = DAT_000383e4[3];
            *logstr_00 = *DAT_000383e4;
            logstr_00[1] = uVar17;
            logstr_00[2] = uVar19;
            logstr_00[3] = uVar22;
            uVar17 = DAT_000383e4[5];
            uVar19 = DAT_000383e4[6];
            uVar22 = DAT_000383e4[7];
            uVar32 = DAT_000383e4[8];
            logstr_00[4] = DAT_000383e4[4];
            logstr_00[5] = uVar17;
            logstr_00[6] = uVar19;
            logstr_00[7] = uVar22;
            *(short *)(logstr_00 + 8) = (short)uVar32;
            writeInitLogFile((char *)logstr_00);
            open_core_one_chain(8,(_Bool)uVar12);
            sleep(1);
            open_core_one_chain(9,(_Bool)uVar12);
            sleep(1);
          }
          else if (iVar24 == 2) {
            uVar17 = DAT_000383f8[1];
            uVar19 = DAT_000383f8[2];
            uVar22 = DAT_000383f8[3];
            *logstr_00 = *DAT_000383f8;
            logstr_00[1] = uVar17;
            logstr_00[2] = uVar19;
            logstr_00[3] = uVar22;
            uVar17 = DAT_000383f8[5];
            uVar19 = DAT_000383f8[6];
            uVar22 = DAT_000383f8[7];
            uVar32 = DAT_000383f8[8];
            logstr_00[4] = DAT_000383f8[4];
            logstr_00[5] = uVar17;
            logstr_00[6] = uVar19;
            logstr_00[7] = uVar22;
            logstr_00[8] = uVar32;
            writeInitLogFile((char *)logstr_00);
            open_core_one_chain(10,true);
            sleep(1);
            open_core_one_chain(0xb,true);
            sleep(1);
          }
          else {
            if (iVar24 != 3) {
              iVar27 = *piVar6;
              break;
            }
            uVar17 = DAT_000383f4[1];
            uVar19 = DAT_000383f4[2];
            uVar22 = DAT_000383f4[3];
            *logstr_00 = *DAT_000383f4;
            logstr_00[1] = uVar17;
            logstr_00[2] = uVar19;
            logstr_00[3] = uVar22;
            uVar17 = DAT_000383f4[5];
            uVar19 = DAT_000383f4[6];
            uVar22 = DAT_000383f4[7];
            uVar32 = DAT_000383f4[8];
            logstr_00[4] = DAT_000383f4[4];
            logstr_00[5] = uVar17;
            logstr_00[6] = uVar19;
            logstr_00[7] = uVar22;
            logstr_00[8] = uVar32;
            writeInitLogFile((char *)logstr_00);
            open_core_one_chain(0xc,true);
            sleep(1);
            open_core_one_chain(0xd,true);
            sleep(1);
          }
          iVar27 = DAT_000383d0;
          pthread_mutex_lock(DAT_000383d4);
          voltage = *(uchar *)(iVar27 + iVar24);
LAB_000381b8:
          set_pic_voltage(uVar12,voltage);
          pthread_mutex_unlock(DAT_000383d4);
        }
        sprintf((char *)logstr_00,DAT_000380c0,iVar29,
                ((int)(longlong)
                      (((dVar8 / ((double)(longlong)(int)(uint)*(byte *)(iVar27 + iVar24) + dVar7) +
                        dVar9) * dVar10) / 4.75) / 10) * 10,(uint)*(byte *)(iVar27 + iVar24));
        writeInitLogFile((char *)logstr_00);
        iVar27 = *piVar6;
      }
      iVar24 = iVar24 + 1;
      iVar29 = iVar29 + 1;
    } while (iVar24 != 0x10);
    pptVar5 = DAT_000380a0;
    set_time_out_control
              ((uint)((int)((ulonglong)*(uint *)(iVar27 + 0x48) * 0xcccccccd >> 0x20) << 0xc) >> 0xf
               | 0x80000000);
    ptVar14 = (thr_info *)calloc(1,0x40);
    p_Var4 = DAT_000380a4;
    *pptVar5 = ptVar14;
    iVar27 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,p_Var4,ptVar14);
    if (iVar27 != 0) {
      if ((opt_debug != false) &&
         (((*DAT_000380a8 != '\0' || (*DAT_000380ac != '\0')) || (6 < *DAT_000380b0)))) {
        snprintf(tmp42,0x800,DAT_000380b4,DAT_000380b8);
        _applog(7,tmp42,false);
        return -7;
      }
      return -7;
    }
    pthread_detach((*pptVar5)->pth);
    iVar24 = DAT_000383ec;
    iVar27 = DAT_000383e8;
    if ((opt_fixed_freq == false) && (*(char *)(iVar25 + 0x92) != '\0')) {
      *(undefined *)(DAT_000383e8 + 0xdd4) = 1;
      iVar30 = DAT_000383e0;
      sleep(3);
      iVar31 = *piVar6;
      iVar29 = 0;
      do {
        piVar1 = (int *)(iVar31 + 8);
        iVar31 = iVar31 + 4;
        if (*piVar1 == 1) {
          memcpy((void *)(iVar24 + iVar29 * 0x80),(void *)(iVar30 + iVar29 * 0x100),0x80);
        }
        iVar29 = iVar29 + 1;
      } while (iVar29 != 0x10);
      iVar30 = 0;
      *(undefined *)(iVar3 + 0x96c) = 0;
      iVar24 = DAT_000383ec;
      clement_doTestBoard(true);
      iVar29 = DAT_000383f0;
      iVar31 = *piVar6;
      do {
        piVar1 = (int *)(iVar31 + 8);
        iVar31 = iVar31 + 4;
        if (*piVar1 == 1) {
          memcpy((void *)(iVar24 + iVar30 * 0x80),(void *)(iVar29 + iVar30 * 0x100),0x80);
        }
        iVar30 = iVar30 + 1;
      } while (iVar30 != 0x10);
      set_nonce2_and_job_id_store_address(*(uint *)(iVar25 + 0x8c));
      set_job_start_address(*(int *)(iVar25 + 0x8c) + 0x200000);
      *(undefined *)(iVar27 + 0xdd4) = 0;
    }
    set_asic_ticket_mask(0x3f);
    set_hcnt(0);
    cgsleep_ms(10);
    if (opt_multi_version == 0) {
      set_time_out_control(*(uint *)(*piVar6 + 0x48) & 0x1ffff | 0x80000000);
    }
    else {
      set_time_out_control(*(int *)(*piVar6 + 0x48) * opt_multi_version & 0x1ffffU | 0x80000000);
    }
    pptVar5 = DAT_000380c4;
    ptVar14 = (thr_info *)calloc(1,0x40);
    p_Var4 = DAT_000380c8;
    *pptVar5 = ptVar14;
    iVar25 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,p_Var4,ptVar14);
    if (iVar25 == 0) {
      pthread_detach((*pptVar5)->pth);
      iVar24 = *piVar6;
      iVar25 = 0;
      iVar27 = iVar24;
      do {
        if (*(int *)(iVar27 + 8) != 0) {
          uVar15 = (uint)*(byte *)(iVar24 + iVar25 + 0x2faa);
          if (uVar15 == 0) {
            local_9b4 = iVar25 << 3;
            iVar29 = 0;
          }
          else {
            local_9b4 = iVar25 * 8;
            iVar29 = 0;
            uVar13 = 0;
            iVar30 = iVar24 + iVar25 * 0x48;
            do {
              iVar31 = iVar30 + iVar29;
              bVar33 = (uVar13 & 7) == 0;
              if (bVar33) {
                iVar29 = iVar29 + 1;
              }
              iVar21 = iVar25 * 0x40 + uVar13;
              if (bVar33) {
                *(undefined *)(iVar31 + uVar13 + 0x2aba) = 0x20;
              }
              iVar31 = iVar30 + iVar29 + uVar13;
              uVar13 = uVar13 + 1;
              iVar21 = iVar24 + (iVar21 + 0x157) * 8;
              *(undefined *)(iVar31 + 0x2aba) = 0x6f;
              *(undefined2 *)(iVar21 + 2) = 0;
              *(undefined2 *)(iVar21 + 4) = 0;
              *(undefined2 *)(iVar21 + 6) = 0;
              *(undefined2 *)(iVar21 + 8) = 0;
            } while (uVar15 != uVar13);
          }
          *(undefined *)(iVar24 + (local_9b4 + iVar25) * 8 + iVar29 + uVar15 + 0x2aba) = 0;
        }
        iVar25 = iVar25 + 1;
        iVar27 = iVar27 + 4;
      } while (iVar25 != 0x10);
      cgtime(DAT_000383d8);
      cgtime(DAT_000383dc);
      *(undefined *)(iVar3 + 0x980) = 1;
      setStartTimePoint();
      return 0;
    }
    if (opt_debug == false) {
      return -6;
    }
    pcVar16 = DAT_000380cc;
    if ((*DAT_000380a8 != '\0') || (*DAT_000380ac != '\0')) goto LAB_000376aa;
    iVar25 = *DAT_000380b0;
  }
  else {
    if (*DAT_0003790c == '\0') {
      return -6;
    }
    pcVar16 = DAT_0003791c;
    if ((*DAT_00037910 != '\0') || (*DAT_00037914 != '\0')) goto LAB_000376aa;
    iVar25 = *DAT_00037918;
  }
  if (iVar25 < 7) {
    return -6;
  }
LAB_000376aa:
  snprintf(tmp42,0x800,pcVar16,DAT_00037920);
  _applog(7,tmp42,false);
  return -6;
}

