
/* WARNING: Unknown calling convention */

void set_frequency(ushort frequency)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  char *pcVar9;
  byte bVar10;
  uchar vol_pic;
  _Bool _Var11;
  uint uVar12;
  int default_freq_index;
  int iVar13;
  uint uVar14;
  uint value;
  int totalRate_1;
  int totalRate;
  int chainnum;
  uchar *mac;
  uchar *mac_00;
  int i_1;
  int i;
  int iVar15;
  int new_T9_PLUS_chainIndex_7;
  int new_T9_PLUS_chainIndex;
  int iVar16;
  int iVar17;
  int new_T9_PLUS_chainIndex_1;
  int iVar18;
  int new_T9_PLUS_chainIndex_8;
  uint uVar19;
  int new_T9_PLUS_chainIndex_9;
  int new_T9_PLUS_chainIndex_10;
  int j_1;
  int j;
  int fixed_totalRate;
  int iVar20;
  uint uVar21;
  int new_T9_PLUS_chainOffset_1;
  int new_T9_PLUS_chainOffset_2;
  int new_T9_PLUS_chainIndex_5;
  int new_T9_PLUS_chainIndex_3;
  int iVar22;
  int new_T9_PLUS_chainIndex_6;
  char cVar23;
  uint uVar24;
  int new_T9_PLUS_chainIndex_4;
  int iVar25;
  uint uVar26;
  uint uVar27;
  int new_T9_PLUS_chainIndex_2;
  int new_T9_PLUS_chainIndex_11;
  int iVar28;
  int new_T9_PLUS_chainOffset;
  int fixed_totalRate_1;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  uint *in_stack_fffff638;
  uint local_990;
  int *local_98c;
  int local_988;
  uint local_984;
  int local_980;
  int local_978;
  int local_974;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  uint reg_data_vil;
  uchar minerMAC [6];
  uchar hashMAC [6];
  char logstr [256];
  char tmp42 [2048];
  uchar chain;
  
  uVar26 = (uint)frequency;
  reg_data_pll = 0;
  reg_data_pll2 = 0;
  reg_data_vil = 0;
  uVar12 = get_pll_index(uVar26);
  if ((opt_debug != false) &&
     (((*DAT_000306a0 != '\0' || (*DAT_000306a4 != '\0')) || (6 < *DAT_000316f0)))) {
    snprintf(tmp42,0x800,DAT_000306a8,DAT_000306ac);
    _applog(7,tmp42,false);
  }
  get_plldata(uVar26,(int)&reg_data_pll,(uint *)&reg_data_pll2,(uint16_t *)&reg_data_vil,
              in_stack_fffff638);
  if ((opt_debug != false) &&
     (((*DAT_000306a0 != '\0' || (*DAT_000306a4 != '\0')) || (6 < *DAT_000316f0)))) {
    snprintf(tmp42,0x800,DAT_000306b0,DAT_000306ac,uVar26);
    _applog(7,tmp42,false);
  }
  piVar2 = DAT_000306d8;
  iVar31 = DAT_000306b8;
  uVar27 = 0xffffffff;
  local_978 = DAT_000306b4;
  local_974 = DAT_000306b4 + 0x34;
  iVar30 = DAT_000306b8 + -0x8d8;
  iVar20 = DAT_000306b8;
  iVar18 = 1;
  iVar29 = DAT_000306b4;
  iVar32 = local_974;
  do {
    iVar25 = iVar18 + 1;
    iVar28 = iVar18 + -1;
    uVar4 = (undefined)uVar12;
    if ((*(int *)(*piVar2 + iVar25 * 4) == 1) && (*(char *)(*piVar2 + iVar28 + 0x2faa) != '\0')) {
      if ((*(char *)(iVar31 + -0x808) == '\0') &&
         (iVar13 = getChainPICMagicNumber(iVar28), iVar13 == 0x7d)) {
        local_98c = DAT_000316e0;
      }
      else {
        isUseDefaultFreq = true;
        local_98c = DAT_000306bc;
        if (*DAT_000306bc < 0xe) {
          *(undefined *)(iVar30 + (iVar28 / 3) * 0x180 + 0xd4) = 0x7d;
          iVar13 = iVar28;
          do {
            iVar33 = 0;
            iVar16 = DAT_00030bb0 + iVar13 * 0x1f + (iVar13 / 3) * 0x123;
            do {
              iVar17 = iVar16 + iVar33;
              iVar33 = iVar33 + 1;
              *(undefined *)(iVar17 + 0xb) = uVar4;
            } while (iVar33 != 0x12);
            iVar13 = iVar13 + 1;
          } while (iVar13 != iVar18 + 2);
        }
        else {
          if (uVar27 < 0xd) {
            new_T9_PLUS_chainIndex = *(int *)(iVar29 + -4);
          }
          else {
            new_T9_PLUS_chainIndex = 0;
          }
          iVar33 = new_T9_PLUS_chainIndex * 0x80;
          *(undefined *)(iVar30 + iVar33 + 0xd4) = 0x7d;
          iVar16 = DAT_000306c0 + 0x5d;
          iVar13 = DAT_000306c0 + iVar33;
          do {
            iVar17 = 0;
            do {
              iVar15 = iVar13 + iVar17;
              iVar17 = iVar17 + 1;
              *(undefined *)(iVar15 + 0xb) = uVar4;
            } while (iVar17 != 0x12);
            iVar13 = iVar13 + 0x1f;
          } while (iVar13 != iVar33 + iVar16);
        }
        sprintf(logstr,DAT_000306c4,iVar18,uVar26);
        writeInitLogFile(logstr);
      }
      if (*local_98c < 0xe) {
        iVar13 = iVar30 + (iVar28 / 3) * 0x180;
        if ((*(char *)(iVar13 + 0xd4) == '}') && (isUseDefaultFreq == false)) {
          sprintf(logstr,DAT_00031988,iVar18);
          writeInitLogFile(logstr);
          iVar16 = 0;
          uVar21 = 0;
          do {
            iVar33 = iVar13 + (iVar28 % 3) * 0x1f + 0x1d + ((int)uVar21 >> 1);
            if ((uVar21 & 1) == 0) {
              uVar14 = (uint)(*(byte *)(iVar33 + 0xd4) >> 4);
            }
            else {
              uVar14 = *(byte *)(iVar33 + 0xd4) & 0xf;
            }
            *(uint *)(iVar20 + iVar16) = uVar14;
            if (uVar14 != 0) {
              sprintf(logstr,DAT_0003198c,iVar18,uVar21,uVar14);
              writeInitLogFile(logstr);
            }
            uVar21 = uVar21 + 1;
            iVar16 = iVar16 + 4;
          } while (uVar21 != 0x12);
        }
        else {
          sprintf(logstr,DAT_000306c8,iVar18);
          writeInitLogFile(logstr);
          iVar18 = 0;
          do {
            *(undefined4 *)(iVar20 + iVar18) = 0;
            iVar18 = iVar18 + 4;
          } while (iVar18 != 0x48);
        }
      }
      else {
        if (uVar27 < 0xd) {
          iVar28 = *(int *)(iVar29 + -4);
          new_T9_PLUS_chainOffset = *(int *)(iVar32 + -4);
        }
        else {
          new_T9_PLUS_chainOffset = 0;
          iVar28 = new_T9_PLUS_chainOffset;
        }
        new_T9_PLUS_chainIndex_1 = iVar30 + iVar28 * 0x80;
        if ((*(char *)(new_T9_PLUS_chainIndex_1 + 0xd4) == '}') && (isUseDefaultFreq == false)) {
          sprintf(logstr,DAT_000316f8,iVar18);
          writeInitLogFile(logstr);
          iVar28 = 0;
          uVar21 = 0;
          do {
            iVar13 = new_T9_PLUS_chainIndex_1 + new_T9_PLUS_chainOffset * 0x1f + 0x1d +
                     ((int)uVar21 >> 1);
            if ((uVar21 & 1) == 0) {
              uVar14 = (uint)(*(byte *)(iVar13 + 0xd4) >> 4);
            }
            else {
              uVar14 = *(byte *)(iVar13 + 0xd4) & 0xf;
            }
            *(uint *)(iVar20 + iVar28) = uVar14;
            if (uVar14 != 0) {
              sprintf(logstr,DAT_000316fc,iVar18,uVar21,uVar14);
              writeInitLogFile(logstr);
            }
            uVar21 = uVar21 + 1;
            iVar28 = iVar28 + 4;
          } while (uVar21 != 0x12);
        }
        else {
          sprintf(logstr,DAT_000306c8,iVar18);
          writeInitLogFile(logstr);
          iVar18 = 0;
          do {
            *(undefined4 *)(iVar20 + iVar18) = 0;
            iVar18 = iVar18 + 4;
          } while (iVar18 != 0x48);
        }
      }
    }
    iVar20 = iVar20 + 0x400;
    uVar27 = uVar27 + 1;
    iVar29 = iVar29 + 4;
    iVar32 = iVar32 + 4;
    iVar18 = iVar25;
  } while (iVar25 != 0x11);
  if (isUseDefaultFreq == false) {
    iVar18 = GetTotalRate();
    iVar29 = GetTotalRate();
    iVar20 = 0;
    if (500 < iVar29 % 1000) {
      iVar20 = 500;
    }
    sprintf(logstr,DAT_000316e4,iVar18,(iVar29 / 1000) * 1000 + iVar20);
    writeInitLogFile(logstr);
  }
  dVar8 = DAT_00030d30;
  dVar7 = DAT_00030d28;
  dVar6 = DAT_00030d20;
  dVar5 = DAT_00030d18;
  if (*(char *)(iVar31 + -0x808) == '\0') {
    local_984 = 0xffffffff;
    local_980 = DAT_00030d48 + -0x34;
    local_990 = DAT_00030d48;
    local_98c = (int *)(DAT_00030d48 + -0x9ec);
    local_988 = 1;
    iVar20 = 0;
    do {
      piVar1 = DAT_000310a0;
      if ((*(int *)(*piVar2 + (iVar20 + 2) * 4) == 1) &&
         (*(char *)(*piVar2 + iVar20 + 0x2faa) != '\0')) {
        bVar10 = get_pic_voltage((uchar)iVar20);
        sprintf(logstr,DAT_00031078,
                ((int)(longlong)
                      (((dVar6 / ((double)(longlong)(int)(uint)bVar10 + dVar5) + dVar7) * dVar8) /
                      4.75) / 10) * 10,iVar20);
        writeInitLogFile(logstr);
        sprintf(logstr,DAT_0003107c,iVar20,(uint)dev->chain_asic_num[iVar20]);
        writeInitLogFile(logstr);
        if (*piVar1 < 0xe) {
          sprintf(logstr,DAT_000316ec,local_988,
                  (uint)*(byte *)(iVar20 * 0x1f + (iVar20 / 3) * 0x123 + iVar30 + 0xdd));
        }
        else {
          if (local_984 < 0xd) {
            iVar29 = *(int *)(local_980 + -4);
            iVar18 = *(int *)(local_990 + -4) * 0x1f;
          }
          else {
            iVar29 = 0;
            iVar18 = 9;
          }
          if (local_984 < 0xd) {
            iVar18 = iVar18 + 9;
          }
          sprintf(logstr,DAT_00031080,local_988,
                  (uint)*(byte *)(iVar30 + iVar29 * 0x80 + iVar18 + 0xd4));
        }
        writeInitLogFile(logstr);
        get_macBytes((char *)minerMAC,mac_00);
        if (*piVar1 < 0xe) {
          iVar18 = (iVar20 / 3) * 0x180;
        }
        else {
          if (local_984 < 0xd) {
            new_T9_PLUS_chainIndex_10 = *(int *)(local_980 + -4);
          }
          else {
            new_T9_PLUS_chainIndex_10 = 0;
          }
          iVar18 = new_T9_PLUS_chainIndex_10 << 7;
        }
        new_T9_PLUS_chainIndex_10 = iVar30 + iVar18;
        hashMAC[0] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xd5);
        hashMAC[1] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xd6);
        hashMAC[2] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xd7);
        hashMAC[3] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xd8);
        hashMAC[4] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xd9);
        hashMAC[5] = *(uchar *)(new_T9_PLUS_chainIndex_10 + 0xda);
        iVar18 = memcmp(hashMAC,minerMAC,6);
        if (iVar18 == 0) {
          uVar27 = (uint)minerMAC[2];
          uVar24 = (uint)minerMAC[1];
          uVar26 = (uint)minerMAC[3];
          uVar21 = (uint)minerMAC[4];
          uVar14 = (uint)minerMAC[5];
          sprintf(logstr,DAT_00031084,local_988,(uint)minerMAC[0],uVar24,uVar27,uVar26,uVar21,uVar14
                 );
          writeInitLogFile(logstr);
        }
        else {
          uVar24 = (uint)minerMAC[1];
          uVar27 = (uint)minerMAC[2];
          uVar26 = (uint)minerMAC[3];
          uVar21 = (uint)minerMAC[4];
          uVar14 = (uint)minerMAC[5];
          sprintf(logstr,DAT_000313ec,local_988,(uint)minerMAC[0],uVar24,uVar27,uVar26,uVar21,uVar14
                  ,(uint)hashMAC[0],(uint)hashMAC[1],(uint)hashMAC[2],(uint)hashMAC[3],
                  (uint)hashMAC[4],(uint)hashMAC[5]);
          writeInitLogFile(logstr);
        }
        if (*piVar1 < 0xe) {
          if (isUseDefaultFreq == false) {
            bVar10 = *(byte *)(iVar20 * 0x1f + (iVar20 / 3) * 0x123 + iVar30 + 0xdb);
            uVar19 = (uint)bVar10;
            *(byte *)(iVar20 + DAT_000313f0) = bVar10;
          }
          else {
            uVar19 = uVar12 & 0xff;
            *(undefined *)(iVar20 + DAT_000316f4) = uVar4;
          }
          sprintf(logstr,DAT_000313f4,iVar20,*(undefined4 *)((int)local_98c + uVar19 * 0x10 + 0x38),
                  uVar24,uVar27,uVar26,uVar21,uVar14);
          writeInitLogFile(logstr);
          pcVar9 = DAT_00031404;
          uVar26 = (uint)*(byte *)(*piVar2 + iVar20 + 0x2faa);
          if (uVar26 == 0) goto LAB_00031982;
          uVar26 = 0;
          uVar21 = 0;
          uVar27 = 100;
          iVar32 = (iVar20 / 3) * 0x180;
          iVar18 = DAT_000313e8 + iVar32;
          iVar29 = (iVar20 % 3) * 0x1f + 0xb;
          do {
            if ((opt_debug != false) &&
               (((*pcVar9 != '\0' || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,DAT_000313f8,DAT_000313fc,(uint)*(byte *)(iVar18 + iVar29));
              _applog(7,tmp42,false);
            }
            iVar25 = iVar30 + iVar32 + iVar29;
            if (*(byte *)(iVar25 + 0xd4) < 4) {
              *(undefined *)(iVar25 + 0xd4) = 4;
            }
            else if (100 < *(byte *)(iVar25 + 0xd4)) {
              *(undefined *)(iVar25 + 0xd4) = 100;
            }
            uVar14 = (uint)*(byte *)(iVar30 + iVar32 + iVar29 + 0xd4);
            if (uVar26 < uVar14) {
              uVar26 = uVar14;
            }
            if (uVar14 <= uVar27) {
              uVar27 = uVar14;
            }
            sprintf(logstr,DAT_00031400,uVar21,
                    *(undefined4 *)((int)local_98c + uVar14 * 0x10 + 0x38));
            writeInitLogFile(logstr);
            if ((uVar21 & 7) == 0) {
              logstr[0] = '\n';
              logstr[1] = '\0';
              writeInitLogFile(logstr);
            }
            uVar21 = uVar21 + 1;
            iVar29 = iVar29 + 1;
          } while ((int)uVar21 < (int)(uint)*(byte *)(*piVar2 + iVar20 + 0x2faa));
        }
        else {
          if (local_984 < 0xd) {
            iVar18 = *(int *)(local_980 + -4);
            new_T9_PLUS_chainOffset_2 = *(int *)(local_990 + -4);
          }
          else {
            new_T9_PLUS_chainOffset_2 = 0;
            iVar18 = new_T9_PLUS_chainOffset_2;
          }
          if (isUseDefaultFreq == false) {
            bVar10 = *(byte *)(new_T9_PLUS_chainOffset_2 * 0x1f + iVar18 * 0x80 + iVar30 + 0xdb);
            uVar19 = (uint)bVar10;
            *(byte *)(iVar20 + DAT_00031088) = bVar10;
          }
          else {
            uVar19 = uVar12 & 0xff;
            *(undefined *)(iVar20 + DAT_000316f4) = uVar4;
          }
          sprintf(logstr,DAT_0003108c,iVar20,*(undefined4 *)((int)local_98c + uVar19 * 0x10 + 0x38),
                  uVar24,uVar27,uVar26,uVar21,uVar14);
          writeInitLogFile(logstr);
          uVar26 = (uint)*(byte *)(*piVar2 + iVar20 + 0x2faa);
          if (uVar26 == 0) {
LAB_00031982:
            uVar27 = 100;
          }
          else {
            iVar18 = iVar18 * 0x80;
            uVar26 = 0;
            uVar27 = 100;
            iVar29 = DAT_00031090 + iVar18;
            iVar32 = new_T9_PLUS_chainOffset_2 * 0x1f + 0xb;
            uVar21 = 0;
            do {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,DAT_00031094,DAT_00031098,(uint)*(byte *)(iVar29 + iVar32));
                _applog(7,tmp42,false);
              }
              iVar25 = iVar30 + iVar18 + iVar32;
              if (*(byte *)(iVar25 + 0xd4) < 4) {
                *(undefined *)(iVar25 + 0xd4) = 4;
              }
              else if (100 < *(byte *)(iVar25 + 0xd4)) {
                *(undefined *)(iVar25 + 0xd4) = 100;
              }
              uVar14 = (uint)*(byte *)(iVar30 + iVar18 + iVar32 + 0xd4);
              if (uVar26 < uVar14) {
                uVar26 = uVar14;
              }
              if (uVar14 <= uVar27) {
                uVar27 = uVar14;
              }
              sprintf(logstr,DAT_0003109c,uVar21,
                      *(undefined4 *)((int)local_98c + uVar14 * 0x10 + 0x38));
              writeInitLogFile(logstr);
              if ((uVar21 & 7) == 0) {
                logstr[0] = '\n';
                logstr[1] = '\0';
                writeInitLogFile(logstr);
              }
              uVar21 = uVar21 + 1;
              iVar32 = iVar32 + 1;
            } while ((int)uVar21 < (int)(uint)*(byte *)(*piVar2 + iVar20 + 0x2faa));
          }
        }
        sprintf(logstr,DAT_00031990,iVar20,*(undefined4 *)((int)local_98c + uVar26 * 0x10 + 0x38));
        writeInitLogFile(logstr);
        sprintf(logstr,DAT_00031994,iVar20,*(undefined4 *)((int)local_98c + uVar27 * 0x10 + 0x38));
        writeInitLogFile(logstr);
        logstr[0] = '\n';
        logstr[1] = '\0';
        writeInitLogFile(logstr);
      }
      iVar20 = iVar20 + 1;
      local_988 = local_988 + 1;
      local_984 = local_984 + 1;
      local_980 = local_980 + 4;
      local_990 = local_990 + 4;
    } while (iVar20 != 0x10);
  }
  else {
    local_98c = (int *)DAT_000306cc;
  }
  logstr._0_4_ = *DAT_000306d0;
  logstr._4_4_ = DAT_000306d0[1];
  logstr._8_4_ = DAT_000306d0[2];
  logstr._12_4_ = DAT_000306d0[3];
  logstr._16_4_ = DAT_000306d0[4];
  logstr[20] = (char)DAT_000306d0[5];
  writeInitLogFile(logstr);
  iVar20 = *piVar2;
  if (isUseDefaultFreq == false) {
    chainnum = 0;
    iVar18 = 0;
    do {
      iVar29 = iVar20 + iVar18;
      iVar18 = iVar18 + 4;
      if (*(int *)(iVar29 + 8) == 1) {
        chainnum = chainnum + 1;
      }
    } while (iVar18 != 0x40);
    if (8 < chainnum) {
      iVar20 = GetTotalRate();
      if (iVar20 % 1000 < 0x1f5) {
        iVar18 = 0;
      }
      else {
        iVar18 = 500;
      }
      iVar20 = (((iVar20 / 1000) * 1000 + iVar18) * 0x66) / 100;
      iVar29 = GetTotalRate();
      iVar18 = DAT_000313e4;
      piVar1 = DAT_000313e0;
      if (iVar20 < iVar29) {
        do {
          iVar32 = *(int *)(*piVar2 + 8);
          iVar29 = 0;
          while( true ) {
            if (iVar32 == 1) {
              uVar26 = iVar29 - 1;
              iVar33 = (int)local_98c + uVar26 * 4;
              iVar16 = *piVar1;
              iVar32 = 0;
              iVar13 = iVar18 + iVar29 * 0x400;
              iVar25 = 0;
              iVar28 = DAT_000313e8 + iVar29 * 0x1f + (iVar29 / 3) * 0x123;
              do {
                if (iVar16 < 0xe) {
                  *(uint *)(iVar13 + iVar32) = (uint)*(byte *)(iVar28 + iVar25 + 0xb);
                }
                else {
                  iVar17 = 0xb;
                  iVar15 = 0;
                  if (uVar26 < 0xd) {
                    iVar15 = *(int *)(iVar33 + 0x9b8);
                    iVar17 = *(int *)(iVar33 + 0x9ec) * 0x1f;
                  }
                  if (uVar26 < 0xd) {
                    iVar17 = iVar17 + 0xb;
                  }
                  *(uint *)(iVar13 + iVar32) =
                       (uint)*(byte *)(iVar30 + iVar15 * 0x80 + iVar25 + iVar17 + 0xd4);
                }
                iVar25 = iVar25 + 1;
                iVar32 = iVar32 + 4;
              } while (iVar25 != 0x12);
            }
            if (0xf < iVar29 + 1) break;
            iVar32 = *(int *)(*piVar2 + (iVar29 + 3) * 4);
            iVar29 = iVar29 + 1;
          }
          _Var11 = DownOneChipFreqOneStep();
        } while ((_Var11) && (iVar29 = GetTotalRate(), iVar20 < iVar29));
        iVar20 = *piVar2;
        iVar32 = 0;
        iVar25 = 0;
        iVar29 = *piVar1;
        iVar18 = DAT_00031998;
        do {
          if (*(int *)(iVar20 + iVar32 + 8) == 1) {
            iVar28 = 0;
            iVar13 = 0;
            iVar33 = DAT_0003199c + iVar32;
            iVar17 = DAT_0003199c + iVar32;
            iVar16 = DAT_000319a0 + iVar25 * 0x1f + (iVar25 / 3) * 0x123;
            do {
              if (iVar29 < 0xe) {
                *(char *)(iVar16 + iVar13 + 0xb) = (char)*(undefined4 *)(iVar18 + iVar28);
              }
              else {
                iVar15 = 0xb;
                iVar22 = 0;
                if (iVar25 - 1U < 0xd) {
                  iVar22 = *(int *)(iVar33 + -4);
                  iVar15 = *(int *)(iVar17 + 0x30) * 0x1f;
                }
                if (iVar25 - 1U < 0xd) {
                  iVar15 = iVar15 + 0xb;
                }
                *(char *)(iVar30 + iVar22 * 0x80 + iVar13 + iVar15 + 0xd4) =
                     (char)*(undefined4 *)(iVar18 + iVar28);
              }
              iVar13 = iVar13 + 1;
              iVar28 = iVar28 + 4;
            } while (iVar13 != 0x12);
          }
          iVar25 = iVar25 + 1;
          iVar32 = iVar32 + 4;
          iVar18 = iVar18 + 0x400;
        } while (iVar25 != 0x10);
      }
      else {
        iVar20 = *piVar2;
      }
    }
  }
  iVar29 = DAT_000306d4;
  iVar18 = DAT_000306c0;
  iVar25 = 0;
  iVar32 = iVar20;
  do {
    while (piVar1 = (int *)(iVar32 + 8), iVar32 = iVar32 + 4, *piVar1 == 1) {
      iVar28 = iVar25 * 0x100;
      iVar13 = iVar25 * 0x80;
      iVar25 = iVar25 + 1;
      memcpy((void *)(iVar29 + iVar28),(void *)(iVar18 + iVar13),0x80);
      if (iVar25 == 0x10) goto LAB_0003065e;
    }
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x10);
LAB_0003065e:
  dVar8 = DAT_00030698;
  dVar7 = DAT_00030690;
  dVar6 = DAT_00030688;
  dVar5 = DAT_00030680;
  iVar18 = 0;
  local_990 = 0;
  local_980 = 1;
  do {
    piVar1 = DAT_0003096c;
    if ((*(int *)(iVar20 + (iVar18 + 2) * 4) == 1) && (*(char *)(iVar20 + iVar18 + 0x2faa) != '\0'))
    {
      chain = (uchar)iVar18;
      bVar10 = get_pic_voltage(chain);
      sprintf(logstr,DAT_00030950,
              ((int)(longlong)
                    (((dVar6 / ((double)(longlong)(int)(uint)bVar10 + dVar5) + dVar7) * dVar8) /
                    4.75) / 10) * 10,iVar18);
      writeInitLogFile(logstr);
      sprintf(logstr,DAT_00030954,iVar18,(uint)*(byte *)(*piVar2 + iVar18 + 0x2faa));
      writeInitLogFile(logstr);
      if (*(char *)(iVar31 + -0x808) == '\0') {
        if (*piVar1 < 0xe) {
          sprintf(logstr,DAT_000316ec,local_980,
                  (uint)*(byte *)(DAT_00030958 + iVar18 * 0x1f + (iVar18 / 3) * 0x123 + 0xdd));
        }
        else {
          if (iVar18 - 1U < 0xd) {
            iVar29 = *(int *)(local_978 + -4);
            iVar20 = *(int *)(local_974 + -4) * 0x1f;
          }
          else {
            iVar20 = 9;
            iVar29 = 0;
          }
          if (iVar18 - 1U < 0xd) {
            iVar20 = iVar20 + 9;
          }
          sprintf(logstr,DAT_00030d38,local_980,
                  (uint)*(byte *)(iVar30 + iVar29 * 0x80 + iVar20 + 0xd4));
        }
        writeInitLogFile(logstr);
        get_macBytes((char *)minerMAC,mac);
        if (*piVar1 < 0xe) {
          iVar20 = (iVar18 / 3) * 0x180;
        }
        else {
          if (iVar18 - 1U < 0xd) {
            new_T9_PLUS_chainIndex_8 = *(int *)(local_978 + -4);
          }
          else {
            new_T9_PLUS_chainIndex_8 = 0;
          }
          iVar20 = new_T9_PLUS_chainIndex_8 << 7;
        }
        iVar20 = iVar30 + iVar20;
        hashMAC[0] = *(uchar *)(iVar20 + 0xd5);
        hashMAC[1] = *(uchar *)(iVar20 + 0xd6);
        hashMAC[2] = *(uchar *)(iVar20 + 0xd7);
        hashMAC[3] = *(uchar *)(iVar20 + 0xd8);
        hashMAC[4] = *(uchar *)(iVar20 + 0xd9);
        hashMAC[5] = *(uchar *)(iVar20 + 0xda);
        iVar20 = memcmp(hashMAC,minerMAC,6);
        if (iVar20 == 0) {
          uVar14 = (uint)minerMAC[1];
          uVar27 = (uint)minerMAC[2];
          uVar26 = (uint)minerMAC[3];
          uVar24 = (uint)minerMAC[5];
          uVar21 = (uint)minerMAC[4];
          sprintf(logstr,DAT_00030d3c,local_980,(uint)minerMAC[0],uVar14,uVar27,uVar26,uVar21,uVar24
                 );
          writeInitLogFile(logstr);
          cVar23 = *(char *)(iVar31 + -0x808);
        }
        else {
          uVar14 = (uint)minerMAC[1];
          uVar27 = (uint)minerMAC[2];
          uVar26 = (uint)minerMAC[3];
          uVar21 = (uint)minerMAC[4];
          uVar24 = (uint)minerMAC[5];
          sprintf(logstr,DAT_000313ec,local_980,(uint)minerMAC[0],uVar14,uVar27,uVar26,uVar21,uVar24
                  ,(uint)hashMAC[0],(uint)hashMAC[1],(uint)hashMAC[2],(uint)hashMAC[3],
                  (uint)hashMAC[4],(uint)hashMAC[5]);
          writeInitLogFile(logstr);
          cVar23 = *(char *)(iVar31 + -0x808);
        }
        if (0xd < *piVar1) goto LAB_000308fe;
        if (cVar23 == '\0') {
          if (isUseDefaultFreq == false) {
            bVar10 = *(byte *)(iVar18 * 0x1f + (iVar18 / 3) * 0x123 + iVar30 + 0xdb);
            uVar19 = (uint)bVar10;
            *(byte *)(iVar18 + DAT_00030d40) = bVar10;
          }
          else {
            uVar19 = uVar12 & 0xff;
            *(undefined *)(iVar18 + DAT_000316f4) = uVar4;
          }
          sprintf(logstr,DAT_00030d44,iVar18,*(undefined4 *)((int)local_98c + uVar19 * 0x10 + 0x38),
                  uVar14,uVar27,uVar26,uVar21,uVar24);
          writeInitLogFile(logstr);
        }
LAB_000307b2:
        uVar26 = (uint)*(byte *)(*piVar2 + iVar18 + 0x2faa);
        if (uVar26 == 0) {
LAB_00031974:
          uVar27 = 100;
        }
        else {
          uVar26 = 0;
          uVar21 = 0;
          uVar27 = 100;
          iVar32 = (iVar18 / 3) * 0x180;
          iVar20 = DAT_0003095c + iVar32;
          iVar29 = (iVar18 % 3) * 0x1f + 0xb;
          do {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,DAT_00030960,DAT_00030964,(uint)*(byte *)(iVar20 + iVar29));
              _applog(7,tmp42,false);
            }
            iVar25 = iVar30 + iVar32 + iVar29;
            if (*(byte *)(iVar25 + 0xd4) < 4) {
              *(undefined *)(iVar25 + 0xd4) = 4;
            }
            else if (100 < *(byte *)(iVar25 + 0xd4)) {
              *(undefined *)(iVar25 + 0xd4) = 100;
            }
            iVar25 = iVar30 + iVar32 + iVar29;
            uVar14 = (uint)*(byte *)(iVar25 + 0xd4);
            if (local_990 < uVar14) {
              local_990 = uVar14;
            }
            if (uVar26 < uVar14) {
              uVar26 = uVar14;
            }
            if (uVar14 <= uVar27) {
              uVar27 = uVar14;
            }
            set_frequency_with_addr_plldatai
                      (uVar14,'\0',(char)uVar21 * *(char *)(*piVar2 + 0x2fe8),chain);
            sprintf(logstr,DAT_00030968,uVar21,
                    *(undefined4 *)((int)local_98c + (uint)*(byte *)(iVar25 + 0xd4) * 0x10 + 0x38));
            writeInitLogFile(logstr);
            if ((uVar21 & 7) == 0) {
              logstr[0] = '\n';
              logstr[1] = '\0';
              writeInitLogFile(logstr);
            }
            uVar21 = uVar21 + 1;
            iVar29 = iVar29 + 1;
          } while ((int)uVar21 < (int)(uint)*(byte *)(*piVar2 + iVar18 + 0x2faa));
        }
      }
      else {
        cVar23 = '\x01';
        if (*piVar1 < 0xe) goto LAB_000307b2;
LAB_000308fe:
        if (iVar18 - 1U < 0xd) {
          iVar20 = *(int *)(local_978 + -4);
          new_T9_PLUS_chainOffset_1 = *(int *)(local_974 + -4);
        }
        else {
          new_T9_PLUS_chainOffset_1 = 0;
          iVar20 = new_T9_PLUS_chainOffset_1;
        }
        if (cVar23 == '\0') {
          if (isUseDefaultFreq == false) {
            bVar10 = *(byte *)(new_T9_PLUS_chainOffset_1 * 0x1f + iVar20 * 0x80 + iVar30 + 0xdb);
            uVar26 = (uint)bVar10;
            *(byte *)(iVar18 + DAT_00031088) = bVar10;
          }
          else {
            uVar26 = uVar12 & 0xff;
            *(undefined *)(iVar18 + DAT_000316f4) = uVar4;
          }
          sprintf(logstr,DAT_0003108c,iVar18,*(undefined4 *)((int)local_98c + uVar26 * 0x10 + 0x38))
          ;
          writeInitLogFile(logstr);
        }
        uVar26 = (uint)*(byte *)(*piVar2 + iVar18 + 0x2faa);
        if (uVar26 == 0) goto LAB_00031974;
        iVar20 = iVar20 * 0x80;
        uVar26 = 0;
        uVar27 = 100;
        iVar29 = DAT_0003095c + iVar20;
        iVar32 = new_T9_PLUS_chainOffset_1 * 0x1f + 0xb;
        uVar21 = 0;
        do {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,DAT_00030b90,DAT_00030b94,(uint)*(byte *)(iVar29 + iVar32));
            _applog(7,tmp42,false);
          }
          iVar25 = iVar30 + iVar20 + iVar32;
          if (*(byte *)(iVar25 + 0xd4) < 4) {
            *(undefined *)(iVar25 + 0xd4) = 4;
          }
          else if (100 < *(byte *)(iVar25 + 0xd4)) {
            *(undefined *)(iVar25 + 0xd4) = 100;
          }
          iVar25 = iVar30 + iVar20 + iVar32;
          uVar14 = (uint)*(byte *)(iVar25 + 0xd4);
          if (local_990 < uVar14) {
            local_990 = uVar14;
          }
          if (uVar26 < uVar14) {
            uVar26 = uVar14;
          }
          if (uVar14 <= uVar27) {
            uVar27 = uVar14;
          }
          set_frequency_with_addr_plldatai
                    (uVar14,'\0',(char)uVar21 * *(char *)(*piVar2 + 0x2fe8),chain);
          sprintf(logstr,DAT_00030b98,uVar21,
                  *(undefined4 *)((int)local_98c + (uint)*(byte *)(iVar25 + 0xd4) * 0x10 + 0x38));
          writeInitLogFile(logstr);
          if ((uVar21 & 7) == 0) {
            logstr[0] = '\n';
            logstr[1] = '\0';
            writeInitLogFile(logstr);
          }
          uVar21 = uVar21 + 1;
          iVar32 = iVar32 + 1;
        } while ((int)uVar21 < (int)(uint)*(byte *)(*piVar2 + iVar18 + 0x2faa));
      }
      sprintf(logstr,DAT_00030b9c,iVar18,*(undefined4 *)((int)local_98c + uVar26 * 0x10 + 0x38));
      writeInitLogFile(logstr);
      sprintf(logstr,DAT_00030ba0,iVar18,*(undefined4 *)((int)local_98c + uVar27 * 0x10 + 0x38));
      writeInitLogFile(logstr);
      logstr[0] = '\n';
      logstr[1] = '\0';
      writeInitLogFile(logstr);
    }
    piVar1 = DAT_00030ba4;
    iVar18 = iVar18 + 1;
    local_980 = local_980 + 1;
    local_978 = local_978 + 4;
    local_974 = local_974 + 4;
    if (iVar18 == 0x10) break;
    iVar20 = *piVar2;
  } while( true );
  uVar26 = strtol(*(char **)((int)local_98c + local_990 * 0x10 + 0x38),(char **)0x0,10);
  pcVar9 = DAT_00030ba8;
  *(short *)(*piVar2 + 0x2fee) = (short)uVar26;
  sprintf(logstr,pcVar9,uVar26 & 0xffff);
  writeInitLogFile(logstr);
  if (isUseDefaultFreq == false) {
    iVar20 = GetTotalRate();
    iVar31 = 0;
    if (500 < iVar20 % 1000) {
      iVar31 = 500;
    }
    iVar31 = (iVar20 / 1000) * 1000 + iVar31;
    iVar29 = GetTotalRate();
    iVar18 = DAT_00031700;
    iVar20 = DAT_000316e8;
    piVar1 = DAT_000316e0;
    if (iVar31 < iVar29) {
      do {
        iVar32 = *(int *)(*piVar2 + 8);
        iVar29 = 0;
        while( true ) {
          if (iVar32 == 1) {
            uVar26 = iVar29 - 1;
            iVar32 = 0;
            iVar13 = (int)local_98c + uVar26 * 4;
            iVar16 = *piVar1;
            iVar28 = iVar20 + iVar29 * 0x400;
            iVar25 = 0;
            do {
              if (iVar16 < 0xe) {
                *(uint *)(iVar28 + iVar32) =
                     (uint)*(byte *)(iVar18 + iVar29 * 0x1f + (iVar29 / 3) * 0x123 + iVar25 + 0xb);
              }
              else {
                iVar33 = 0xb;
                iVar17 = 0;
                if (uVar26 < 0xd) {
                  iVar17 = *(int *)(iVar13 + 0x9b8);
                  iVar33 = *(int *)(iVar13 + 0x9ec) * 0x1f;
                }
                if (uVar26 < 0xd) {
                  iVar33 = iVar33 + 0xb;
                }
                *(uint *)(iVar28 + iVar32) =
                     (uint)*(byte *)(iVar30 + iVar17 * 0x80 + iVar25 + iVar33 + 0xd4);
              }
              iVar25 = iVar25 + 1;
              iVar32 = iVar32 + 4;
            } while (iVar25 != 0x12);
          }
          if (0xf < iVar29 + 1) break;
          iVar32 = *(int *)(*piVar2 + (iVar29 + 3) * 4);
          iVar29 = iVar29 + 1;
        }
        _Var11 = DownOneChipFreqOneStep();
      } while ((_Var11) && (iVar29 = GetTotalRate(), iVar31 < iVar29));
      iVar31 = *piVar2;
      iVar32 = 0;
      iVar29 = 0;
      iVar18 = *piVar1;
      iVar20 = DAT_00031998;
      do {
        while (*(int *)(iVar31 + iVar32 + 8) == 1) {
          uVar26 = iVar29 - 1;
          iVar33 = DAT_0003199c + iVar32;
          iVar25 = 0;
          iVar16 = DAT_0003199c + iVar32;
          iVar28 = 0;
          iVar13 = DAT_000319a0 + iVar29 * 0x1f + (iVar29 / 3) * 0x123;
          do {
            while (iVar17 = iVar13 + iVar28, iVar18 < 0xe) {
              puVar3 = (undefined4 *)(iVar20 + iVar25);
              iVar28 = iVar28 + 1;
              iVar25 = iVar25 + 4;
              *(char *)(iVar17 + 0xb) = (char)*puVar3;
              if (iVar28 == 0x12) goto LAB_000318a2;
            }
            new_T9_PLUS_chainIndex_3 = 0;
            if (uVar26 < 0xd) {
              new_T9_PLUS_chainIndex_3 = *(int *)(iVar33 + -4);
            }
            iVar17 = 0xb;
            if (uVar26 < 0xd) {
              iVar17 = *(int *)(iVar16 + 0x30);
            }
            puVar3 = (undefined4 *)(iVar20 + iVar25);
            iVar25 = iVar25 + 4;
            if (uVar26 < 0xd) {
              iVar17 = iVar17 * 0x1f;
            }
            iVar15 = iVar30 + new_T9_PLUS_chainIndex_3 * 0x80 + iVar28;
            iVar28 = iVar28 + 1;
            if (uVar26 < 0xd) {
              iVar17 = iVar17 + 0xb;
            }
            *(char *)(iVar17 + iVar15 + 0xd4) = (char)*puVar3;
          } while (iVar28 != 0x12);
LAB_000318a2:
          iVar32 = iVar32 + 4;
          iVar20 = iVar20 + 0x400;
          iVar29 = iVar29 + 1;
          if (iVar29 == 0x10) goto LAB_00030af4;
        }
        iVar29 = iVar29 + 1;
        iVar32 = iVar32 + 4;
        iVar20 = iVar20 + 0x400;
      } while (iVar29 != 0x10);
    }
    else {
      iVar31 = *piVar2;
    }
  }
  else {
    iVar31 = *piVar1;
  }
LAB_00030af4:
  iVar18 = DAT_00030bb0;
  iVar20 = DAT_00030bac;
  iVar29 = 0;
  do {
    while (piVar2 = (int *)(iVar31 + 8), iVar31 = iVar31 + 4, *piVar2 != 1) {
      iVar29 = iVar29 + 1;
      if (iVar29 == 0x10) {
        return;
      }
    }
    iVar32 = iVar29 * 0x100;
    iVar30 = iVar29 * 0x80;
    iVar29 = iVar29 + 1;
    memcpy((void *)(iVar20 + iVar32),(void *)(iVar18 + iVar30),0x80);
  } while (iVar29 != 0x10);
  return;
}

