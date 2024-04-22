
/* WARNING: Unknown calling convention */

void * read_temp_func(void)

{
  undefined2 *puVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  bool bVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  _Bool _Var14;
  int16_t iVar15;
  uint uVar16;
  char *pcVar17;
  uint uVar18;
  ushort uVar19;
  ushort uVar20;
  int iVar21;
  undefined2 *puVar22;
  int iVar23;
  int iVar24;
  undefined2 *puVar25;
  undefined4 uVar26;
  ushort uVar27;
  int iVar28;
  uint uVar29;
  undefined4 *puVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  ushort uVar35;
  ushort uVar36;
  int iVar37;
  ushort uVar38;
  int iVar39;
  int local_158;
  int local_140;
  int16_t temp_top [4];
  int16_t temp_low [4];
  char logstr [256];
  
  piVar12 = DAT_00039c98;
  local_140 = 0;
  bVar10 = false;
  clearTempLogFile();
  do {
    puVar30 = DAT_00039c84;
    clearTempLogFile();
    puVar11 = DAT_00039c88;
    logstr._0_4_ = *puVar30;
    logstr._4_4_ = puVar30[1];
    logstr._8_4_ = puVar30[2];
    logstr._12_4_ = puVar30[3];
    logstr._16_4_ = puVar30[4];
    logstr._20_4_ = puVar30[5];
    logstr._24_3_ = (undefined3)puVar30[6];
    writeLogFile(logstr);
    pthread_mutex_lock(DAT_00039c8c);
    logstr._0_4_ = *puVar11;
    logstr._4_4_ = puVar11[1];
    logstr._8_4_ = puVar11[2];
    logstr._12_4_ = puVar11[3];
    logstr._16_4_ = puVar11[4];
    logstr._20_4_ = puVar11[5];
    writeLogFile(logstr);
    if (doTestPatten == false) {
      _Var14 = check_asic_reg(8);
      if (_Var14) {
        showAllBadRTInfo();
      }
      else {
        logstr._0_4_ = *DAT_0003a670;
        logstr._4_4_ = DAT_0003a670[1];
        logstr._8_4_ = DAT_0003a670[2];
        logstr._12_4_ = DAT_0003a670[3];
        logstr._16_4_ = DAT_0003a670[4];
        logstr._20_4_ = DAT_0003a670[5];
        logstr._24_4_ = DAT_0003a670[6];
        logstr._28_4_ = DAT_0003a670[7];
        logstr._32_4_ = DAT_0003a670[8];
        writeInitLogFile(logstr);
      }
    }
    else {
      usleep(100000);
    }
    iVar34 = DAT_00039c9c;
    piVar13 = DAT_00039c98;
    logstr._0_4_ = *DAT_00039c90;
    logstr._4_4_ = DAT_00039c90[1];
    logstr._8_4_ = DAT_00039c90[2];
    logstr._12_4_ = DAT_00039c90[3];
    logstr._16_4_ = DAT_00039c90[4];
    logstr[20] = (char)DAT_00039c90[5];
    writeLogFile(logstr);
    iVar31 = *piVar12;
    local_158 = 0;
    uVar29 = 0;
    temp_top[0] = 0;
    temp_top[1] = 0;
    uVar8 = 0;
    temp_low[0] = 0;
    temp_low[1] = 0;
    uVar9 = 0;
    do {
      if (*(int *)(iVar31 + (uVar29 + 2) * 4) == 1) {
        if (fpga_version < 0xe) {
          if ((int)uVar29 % 3 == 1) goto LAB_00039c48;
        }
        else if (((uVar29 & 0xfffffffd) == 8) || (uVar29 == 0xc)) {
LAB_00039c48:
          sprintf(logstr,DAT_00039c94,uVar29);
          writeLogFile(logstr);
          iVar31 = *piVar12;
          if (*(char *)(iVar31 + uVar29 + 0x458) < '\x01') {
            uVar35 = 1000;
            uVar36 = 1000;
            uVar20 = 0;
            iVar32 = uVar29 << 3;
            uVar27 = uVar20;
            uVar19 = uVar20;
            uVar38 = uVar36;
          }
          else {
            iVar28 = 0;
            uVar20 = 0;
            iVar32 = uVar29 * 8;
            uVar36 = 1000;
            uVar27 = 0;
            uVar19 = 0;
            uVar38 = 1000;
            uVar35 = 1000;
            do {
              iVar31 = iVar31 + iVar32 + iVar28;
              sprintf(logstr,DAT_00039f2c,uVar29,(*(byte *)(iVar31 + 0x4e8) >> 2) + 1,
                      (uint)*(byte *)(iVar31 + 0x468),(int)*(char *)(iVar34 + iVar28));
              writeLogFile(logstr);
              uVar16 = check_reg_temp(0x98,0,'\0','\0',
                                      *(uchar *)(*piVar12 + iVar32 + iVar28 + 0x4e8),uVar29);
              pcVar17 = DAT_00039f20;
              if (uVar16 == 0) {
                sVar7 = *(short *)(*piVar13 + (iVar32 + iVar28 + 0xad) * 8);
                bVar2 = *(byte *)(*piVar13 + iVar32 + iVar28 + 0x4e8);
                pcVar17 = DAT_00039f30;
              }
              else {
                iVar31 = *piVar13;
                sVar7 = ((ushort)uVar16 & 0xff) - 0x40;
                *(short *)(iVar31 + (iVar32 + iVar28 + 0xad) * 8) = sVar7;
                bVar2 = *(byte *)(iVar31 + iVar32 + iVar28 + 0x4e8);
              }
              sprintf(logstr,pcVar17,uVar29,(bVar2 >> 2) + 1,(int)sVar7);
              writeLogFile(logstr);
              set_baud_with_addr(*(uchar *)(*piVar12 + 0x2fea),0,
                                 *(uchar *)(*piVar12 + iVar32 + iVar28 + 0x4e8),uVar29,1,0,1);
              check_asic_reg_with_addr
                        (0x1c,(uint)*(byte *)(*piVar12 + iVar32 + iVar28 + 0x4e8),uVar29,1);
              uVar16 = check_reg_temp(0x98,1,'\0','\0',
                                      *(uchar *)(*piVar12 + iVar32 + iVar28 + 0x4e8),uVar29);
              if (uVar16 == 0) {
                sprintf(logstr,DAT_00039f34,uVar29,
                        (*(byte *)(*piVar13 + iVar32 + iVar28 + 0x4e8) >> 2) + 1,
                        (int)*(short *)(*piVar13 + (iVar32 + iVar28) * 8 + 0x56a));
                writeLogFile(logstr);
              }
              else {
                iVar33 = *piVar13;
                iVar15 = get_remote((ushort)uVar16 & 0xff);
                pcVar17 = DAT_00039f24;
                iVar31 = *piVar13;
                iVar23 = (iVar32 + iVar28) * 8;
                bVar2 = *(byte *)(iVar31 + iVar32 + iVar28 + 0x4e8);
                *(int16_t *)(iVar33 + iVar23 + 0x56a) = iVar15;
                sprintf(logstr,pcVar17,uVar29,(bVar2 >> 2) + 1,
                        (int)*(short *)(iVar31 + iVar23 + 0x56a));
                writeLogFile(logstr);
              }
              if (is218_Temp != false) {
                iVar23 = *piVar12;
                iVar31 = (int)*(short *)(iVar23 + (iVar32 + iVar28 + 0xad) * 8);
                if (iVar31 < 1) {
                  uVar18 = 0;
                  uVar16 = uVar18;
                }
                else if (iVar31 < 0x33) {
                  uVar18 = iVar31 + 0x19;
                  uVar16 = uVar18 & 0xffff;
                }
                else if (iVar31 < 0x3d) {
                  uVar18 = iVar31 + 0x1e;
                  uVar16 = uVar18 & 0xffff;
                }
                else {
                  uVar18 = (uint)(short)(iVar31 + 0x23U);
                  uVar16 = iVar31 + 0x23U & 0xffff;
                }
                bVar2 = *(byte *)(iVar23 + iVar32 + iVar28 + 0x4e8);
                *(short *)(iVar23 + (iVar32 + iVar28) * 8 + 0x56a) = (short)uVar16;
                sprintf(logstr,DAT_00039f28,uVar29,(bVar2 >> 2) + 1,uVar18);
                writeLogFile(logstr);
              }
              iVar31 = *piVar12;
              iVar23 = iVar32 + iVar28;
              iVar28 = iVar28 + 1;
              uVar6 = *(ushort *)(iVar31 + (iVar23 + 0xad) * 8);
              iVar23 = iVar31 + iVar23 * 8;
              if ((short)uVar20 < (short)uVar6) {
                uVar20 = uVar6;
              }
              uVar4 = *(ushort *)(iVar23 + 0x56a);
              uVar5 = *(ushort *)(iVar23 + 0x56c);
              if ((short)uVar6 <= (short)uVar36) {
                uVar36 = uVar6;
              }
              if ((short)uVar27 < (short)uVar4) {
                uVar27 = uVar4;
              }
              if ((short)uVar4 <= (short)uVar38) {
                uVar38 = uVar4;
              }
              if ((short)uVar19 < (short)uVar5) {
                uVar19 = uVar5;
              }
              if ((short)uVar5 <= (short)uVar35) {
                uVar35 = uVar5;
              }
            } while (iVar28 < *(char *)(iVar31 + uVar29 + 0x458));
          }
          _Var14 = check_temp_offside;
          *(ushort *)(iVar31 + (uVar29 + 0x12d) * 8) = uVar20;
          *(ushort *)(iVar31 + (uVar29 + 0x13d) * 8) = uVar36;
          iVar28 = iVar31 + iVar32;
          *(ushort *)(iVar28 + 0x96a) = uVar27;
          *(ushort *)(iVar28 + 0x96c) = uVar19;
          *(ushort *)(iVar28 + 0x9ea) = uVar38;
          *(ushort *)(iVar28 + 0x9ec) = uVar35;
          if (_Var14 != false) {
            uVar27 = *(ushort *)(iVar28 + 0x96a);
            if (uVar27 - 0x4b < 0x33) {
              bVar10 = false;
            }
            else if (!bVar10) {
              bVar10 = true;
              *(int *)(DAT_0003a338 + local_158) = *(int *)(DAT_0003a338 + local_158) + 1;
            }
          }
          sVar7 = *(short *)(iVar31 + (uVar29 + 0x12d) * 8);
          iVar15 = temp_top[1];
          if (temp_top[0] < sVar7) {
            temp_top[0] = sVar7;
          }
          if (iVar15 < (short)uVar27) {
            temp_top[1] = uVar27;
          }
          sVar7 = *(short *)(iVar31 + (uVar29 + 0x13d) * 8);
          if ((short)uVar8 < (short)uVar19) {
            uVar8 = uVar19;
          }
          if ((((sVar7 < temp_low[0]) && (0 < sVar7)) && (*(int *)(DAT_0003a328 + local_158) == 0))
             || (temp_low[0] == 0)) {
            temp_low[0] = sVar7;
          }
          sVar7 = *(short *)(iVar31 + iVar32 + 0x9ea);
          if ((((sVar7 < temp_low[1]) && (0 < sVar7)) && (*(int *)(DAT_0003a328 + local_158) == 0))
             || (temp_low[1] == 0)) {
            temp_low[1] = sVar7;
          }
          if (((((short)uVar35 < (short)uVar9) && (0 < (short)uVar35)) &&
              (*(int *)(DAT_0003a328 + local_158) == 0)) || (uVar9 == 0)) {
            uVar9 = uVar35;
          }
          sprintf(logstr,DAT_0003a32c,uVar29);
          writeLogFile(logstr);
          iVar31 = *piVar12;
        }
      }
      uVar29 = uVar29 + 1;
      iVar34 = iVar34 + 8;
      local_158 = local_158 + 4;
    } while (uVar29 != 0x10);
    iVar37 = iVar31 + 0x568;
    iVar33 = 0;
    *(int *)(iVar31 + 0x2fc3) = (int)temp_top[0];
    iVar39 = 0;
    uVar29 = 0;
    *(int *)(iVar31 + 0x2fc7) = (int)temp_top[1];
    *(int *)(iVar31 + 0x2fcb) = (int)(short)uVar8;
    *(int *)(iVar31 + 0x2fd3) = (int)temp_low[0];
    *(int *)(iVar31 + 0x2fd7) = (int)temp_low[1];
    *(int *)(iVar31 + 0x2fdb) = (int)(short)uVar9;
    iVar34 = fpga_version;
    iVar32 = iVar31;
    iVar28 = iVar31;
    iVar23 = iVar31;
    do {
      if (*(int *)(iVar28 + 8) == 1) {
        if (iVar34 < 0xe) {
          iVar24 = ((int)uVar29 / 3) * 3;
          if ((int)uVar29 % 3 != 1) {
            cVar3 = *(char *)(iVar23 + 0x458);
            iVar21 = iVar24 + 1;
            if (0 < cVar3) {
              puVar25 = (undefined2 *)(iVar31 + iVar21 * 0x40 + 0x568);
              puVar22 = (undefined2 *)(iVar31 + uVar29 * 0x40 + 0x56a);
              do {
                puVar22[-1] = *puVar25;
                *puVar22 = puVar25[1];
                puVar1 = puVar25 + 2;
                puVar25 = puVar25 + 4;
                puVar22[1] = *puVar1;
                puVar22 = puVar22 + 4;
              } while (puVar25 != (undefined2 *)(iVar37 + ((int)cVar3 + iVar21 * 8) * 8));
            }
            iVar21 = iVar21 * 8 + iVar31;
            *(undefined2 *)(iVar32 + 0x968) = *(undefined2 *)(iVar31 + (iVar24 + 0x12e) * 8);
            *(undefined2 *)(iVar32 + 0x96a) = *(undefined2 *)(iVar21 + 0x96a);
            *(undefined2 *)(iVar32 + 0x96c) = *(undefined2 *)(iVar21 + 0x96c);
            *(undefined2 *)(iVar32 + 0x9e8) = *(undefined2 *)(iVar31 + (iVar24 + 0x13e) * 8);
            *(undefined2 *)(iVar32 + 0x9ea) = *(undefined2 *)(iVar21 + 0x9ea);
            *(undefined2 *)(iVar32 + 0x9ec) = *(undefined2 *)(iVar21 + 0x9ec);
          }
        }
        else if (uVar29 < 0xe) {
          uVar16 = 1 << (uVar29 & 0xff);
          if ((uVar16 & 0x2008) == 0) {
            if ((uVar16 & 0x804) == 0) {
              if ((uVar16 & 0x202) != 0) {
                cVar3 = *(char *)(iVar23 + 0x458);
                if (0 < cVar3) {
                  iVar21 = iVar31 + uVar29 * 0x40 + 0x568;
                  iVar24 = iVar31;
                  do {
                    *(undefined2 *)(iVar24 + iVar33 + 0x568) = *(undefined2 *)(iVar24 + 0x768);
                    *(undefined2 *)(iVar21 + 2) = *(undefined2 *)(iVar24 + 0x76a);
                    puVar22 = (undefined2 *)(iVar24 + 0x76c);
                    iVar24 = iVar24 + 8;
                    *(undefined2 *)(iVar21 + 4) = *puVar22;
                    iVar21 = iVar21 + 8;
                  } while (iVar21 != iVar37 + (cVar3 + iVar39) * 8);
                }
                *(undefined2 *)(iVar32 + 0x968) = *(undefined2 *)(iVar31 + 0x9a8);
                *(undefined2 *)(iVar32 + 0x96a) = *(undefined2 *)(iVar31 + 0x9aa);
                *(undefined2 *)(iVar32 + 0x96c) = *(undefined2 *)(iVar31 + 0x9ac);
                *(undefined2 *)(iVar32 + 0x9e8) = *(undefined2 *)(iVar31 + 0xa28);
                *(undefined2 *)(iVar32 + 0x9ea) = *(undefined2 *)(iVar31 + 0xa2a);
                *(undefined2 *)(iVar32 + 0x9ec) = *(undefined2 *)(iVar31 + 0xa2c);
              }
            }
            else {
              cVar3 = *(char *)(iVar23 + 0x458);
              if (0 < cVar3) {
                iVar21 = iVar31 + uVar29 * 0x40 + 0x568;
                iVar24 = iVar31;
                do {
                  *(undefined2 *)(iVar24 + iVar33 + 0x568) = *(undefined2 *)(iVar24 + 0x7e8);
                  *(undefined2 *)(iVar21 + 2) = *(undefined2 *)(iVar24 + 0x7ea);
                  puVar22 = (undefined2 *)(iVar24 + 0x7ec);
                  iVar24 = iVar24 + 8;
                  *(undefined2 *)(iVar21 + 4) = *puVar22;
                  iVar21 = iVar21 + 8;
                } while (iVar21 != iVar37 + (cVar3 + iVar39) * 8);
              }
              *(undefined2 *)(iVar32 + 0x968) = *(undefined2 *)(iVar31 + 0x9b8);
              *(undefined2 *)(iVar32 + 0x96a) = *(undefined2 *)(iVar31 + 0x9ba);
              *(undefined2 *)(iVar32 + 0x96c) = *(undefined2 *)(iVar31 + 0x9bc);
              *(undefined2 *)(iVar32 + 0x9e8) = *(undefined2 *)(iVar31 + 0xa38);
              *(undefined2 *)(iVar32 + 0x9ea) = *(undefined2 *)(iVar31 + 0xa3a);
              *(undefined2 *)(iVar32 + 0x9ec) = *(undefined2 *)(iVar31 + 0xa3c);
            }
          }
          else {
            cVar3 = *(char *)(iVar23 + 0x458);
            if (0 < cVar3) {
              iVar21 = iVar31 + uVar29 * 0x40 + 0x568;
              iVar24 = iVar31;
              do {
                *(undefined2 *)(iVar24 + iVar33 + 0x568) = *(undefined2 *)(iVar24 + 0x868);
                *(undefined2 *)(iVar21 + 2) = *(undefined2 *)(iVar24 + 0x86a);
                puVar22 = (undefined2 *)(iVar24 + 0x86c);
                iVar24 = iVar24 + 8;
                *(undefined2 *)(iVar21 + 4) = *puVar22;
                iVar21 = iVar21 + 8;
              } while (iVar21 != iVar37 + (cVar3 + iVar39) * 8);
            }
            *(undefined2 *)(iVar32 + 0x968) = *(undefined2 *)(iVar31 + 0x9c8);
            *(undefined2 *)(iVar32 + 0x96a) = *(undefined2 *)(iVar31 + 0x9ca);
            *(undefined2 *)(iVar32 + 0x96c) = *(undefined2 *)(iVar31 + 0x9cc);
            *(undefined2 *)(iVar32 + 0x9e8) = *(undefined2 *)(iVar31 + 0xa48);
            *(undefined2 *)(iVar32 + 0x9ea) = *(undefined2 *)(iVar31 + 0xa4a);
            *(undefined2 *)(iVar32 + 0x9ec) = *(undefined2 *)(iVar31 + 0xa4c);
          }
        }
      }
      uVar29 = uVar29 + 1;
      iVar28 = iVar28 + 4;
      iVar39 = iVar39 + 8;
      iVar32 = iVar32 + 8;
      iVar23 = iVar23 + 1;
      iVar33 = iVar33 + 0x40;
    } while (uVar29 != 0x10);
    check_fan();
    set_PWM_according_to_temperature();
    iVar34 = DAT_0003a330;
    if (startCheckNetworkJob == false) {
      if (0x5a < *(int *)(*piVar12 + 0x2fc3)) {
        uVar29 = 2;
        goto LAB_0003a28c;
      }
LAB_0003a59e:
      global_stop = false;
      if (once_error == false) {
        status_error = once_error;
        local_140 = 0;
      }
      else {
        local_140 = 0;
      }
    }
    else {
      cgtime((timeval *)(DAT_0003a330 + 0x978));
      iVar31 = *(int *)(iVar34 + 0x978) - *(int *)(iVar34 + 0x970);
      if (*(int *)(iVar34 + 0x97c) - *(int *)(iVar34 + 0x974) < 0) {
        iVar31 = iVar31 + -1;
      }
      uVar29 = (uint)*(byte *)(*piVar12 + 0x2fbd);
      if (iVar31 < 0x79) {
        if ((*(int *)(*piVar12 + 0x2fc3) < 0x5b) && (1 < uVar29)) goto LAB_0003a59e;
      }
      else {
        logstr._0_4_ = *DAT_0003a64c;
        logstr._4_4_ = DAT_0003a64c[1];
        logstr._8_4_ = DAT_0003a64c[2];
        logstr._12_4_ = DAT_0003a64c[3];
        logstr._16_4_ = DAT_0003a64c[4];
        logstr._20_4_ = DAT_0003a64c[5];
        logstr._24_4_ = DAT_0003a64c[6];
        logstr._28_4_ = DAT_0003a64c[7];
        logstr._32_4_ = DAT_0003a64c[8];
        logstr._36_2_ = (undefined2)DAT_0003a64c[9];
        logstr[38] = (char)((uint)DAT_0003a64c[9] >> 0x10);
        writeInitLogFile(logstr);
      }
LAB_0003a28c:
      local_140 = local_140 + 1;
      if (local_140 < 3) {
        global_stop = false;
        if (once_error == false) {
          status_error = once_error;
        }
      }
      else {
        iVar31 = *piVar12;
        global_stop = true;
        iVar34 = *(int *)(iVar31 + 0x2fc3);
        if (iVar34 < 0x5b) {
          if (uVar29 < 2) {
            iVar34 = 2;
          }
          if (uVar29 < 2) {
            *(int *)(DAT_0003a330 + 0x9d0) = iVar34;
            goto LAB_0003a5c0;
          }
          if (*(uint *)(iVar31 + 0x2fbf) < uVar29 * 0x28) {
            uVar26 = 3;
          }
          else {
            uVar26 = 4;
          }
          *(undefined4 *)(DAT_0003a330 + 0x9d0) = uVar26;
        }
        else {
          *(undefined4 *)(DAT_0003a330 + 0x9d0) = 1;
LAB_0003a5c0:
          iVar34 = 0;
          status_error = true;
          once_error = true;
          while( true ) {
            if (*(int *)(iVar31 + (iVar34 + 2) * 4) == 1) {
              pthread_mutex_lock(DAT_0003a674);
              disable_pic_dac((uchar)iVar34);
              pthread_mutex_unlock(DAT_0003a674);
            }
            iVar34 = iVar34 + 1;
            if (iVar34 == 0x10) break;
            iVar31 = *piVar12;
          }
        }
        uVar29 = get_dhash_acc_control();
        set_dhash_acc_control(uVar29 & 0xffffffbf);
      }
    }
    if (stop_mining == false) {
      if (*(char *)(DAT_0003a334 + 8) != '\0') goto LAB_0003a30c;
      goto LAB_0003a35e;
    }
    *(undefined *)(DAT_0003a334 + 8) = 1;
LAB_0003a30c:
    switch(FatalErrorValue) {
    case 1:
      puVar30 = DAT_0003a668;
      goto LAB_0003a33e;
    case 2:
      logstr._0_4_ = *DAT_0003a664;
      logstr._4_4_ = DAT_0003a664[1];
      logstr._8_4_ = DAT_0003a664[2];
      logstr._12_4_ = DAT_0003a664[3];
      logstr._16_4_ = DAT_0003a664[4];
      logstr._20_4_ = DAT_0003a664[5];
      break;
    case 3:
      logstr._0_4_ = *DAT_0003a660;
      logstr._4_4_ = DAT_0003a660[1];
      logstr._8_4_ = DAT_0003a660[2];
      logstr._12_4_ = DAT_0003a660[3];
      logstr._16_4_ = DAT_0003a660[4];
      logstr._20_4_ = DAT_0003a660[5];
      logstr._24_4_ = DAT_0003a660[6];
      logstr._28_4_ = DAT_0003a660[7];
      logstr[32] = (char)DAT_0003a660[8];
      break;
    case 4:
      puVar30 = DAT_0003a64c;
LAB_0003a33e:
      logstr._0_4_ = *puVar30;
      logstr._4_4_ = puVar30[1];
      logstr._8_4_ = puVar30[2];
      logstr._12_4_ = puVar30[3];
      logstr._16_4_ = puVar30[4];
      logstr._20_4_ = puVar30[5];
      logstr._24_4_ = puVar30[6];
      logstr._28_4_ = puVar30[7];
      logstr._32_4_ = puVar30[8];
      logstr._36_2_ = (undefined2)puVar30[9];
      logstr[38] = (char)((uint)puVar30[9] >> 0x10);
      break;
    default:
      logstr._0_4_ = *DAT_0003a66c;
      logstr._4_4_ = DAT_0003a66c[1];
      logstr._8_4_ = DAT_0003a66c[2];
      logstr._12_4_ = DAT_0003a66c[3];
      logstr._16_4_ = DAT_0003a66c[4];
      logstr._20_4_ = DAT_0003a66c[5];
      logstr._24_4_ = DAT_0003a66c[6];
      logstr[28] = (char)DAT_0003a66c[7];
    }
    writeInitLogFile(logstr);
LAB_0003a35e:
    processTEST();
    puVar30 = DAT_0003a650;
    sprintf(logstr,DAT_0003a654,(uint)*(byte *)(*piVar12 + 0x2fed));
    writeLogFile(logstr);
    pthread_mutex_unlock(DAT_0003a658);
    logstr._0_4_ = *puVar30;
    logstr._4_4_ = puVar30[1];
    logstr._8_4_ = puVar30[2];
    logstr._12_4_ = puVar30[3];
    logstr._16_4_ = puVar30[4];
    logstr[20] = (char)(short)puVar30[5];
    logstr[21] = (char)((ushort)(short)puVar30[5] >> 8);
    writeLogFile(logstr);
    sprintf(logstr,DAT_0003a65c,(uint)*(ushort *)(axi_fpga_addr + 0x3e));
    writeLogFile(logstr);
    updateLogFile();
    if (doTestPatten == false) {
      sleep(1);
    }
    else {
      sleep(3);
    }
  } while( true );
}

