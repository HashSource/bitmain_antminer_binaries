
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void set_frequency(ushort frequency)

{
  uint *puVar1;
  undefined4 *puVar2;
  uchar uVar3;
  byte bVar4;
  _Bool _Var5;
  uint uVar6;
  int iVar7;
  uchar (*pauVar8) [256];
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  uchar (*pauVar12) [128];
  uchar *mac;
  uchar *mac_00;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int fixed_totalRate;
  int (*paiVar17) [256];
  all_parameters *paVar18;
  uint uVar19;
  char cVar20;
  undefined1 *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  all_parameters *paVar28;
  undefined1 *puVar29;
  uint *in_stack_fffff638;
  undefined1 *local_990;
  int local_988;
  uint local_984;
  undefined1 *local_980;
  undefined1 *local_978;
  undefined1 *local_974;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  uint reg_data_vil;
  uchar minerMAC [6];
  uchar hashMAC [6];
  char logstr [256];
  char tmp42 [2048];
  uchar chain;
  
  uVar25 = (uint)frequency;
  reg_data_pll = 0;
  reg_data_pll2 = 0;
  reg_data_vil = 0;
  uVar6 = get_pll_index(uVar25);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"\n--- %s\n","set_frequency");
    _applog(7,tmp42,false);
  }
  get_plldata(uVar25,(int)&reg_data_pll,(uint *)&reg_data_pll2,(uint16_t *)&reg_data_vil,
              in_stack_fffff638);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: frequency = %d\n","set_frequency",uVar25);
    _applog(7,tmp42,false);
  }
  paiVar17 = chain_badcore_num;
  uVar26 = 0xffffffff;
  local_978 = CSWTCH_824;
  puVar21 = CSWTCH_825;
  puVar29 = CSWTCH_824;
  local_974 = CSWTCH_825;
  iVar15 = 1;
  do {
    iVar24 = iVar15 + 1;
    iVar27 = iVar15 + -1;
    uVar3 = (uchar)uVar6;
    if ((dev->chain_exist[iVar15 + -1] == 1) && (*(char *)((int)dev->temp + iVar15 + 0x3f) != '\0'))
    {
      if ((opt_fixed_freq != false) || (iVar7 = getChainPICMagicNumber(iVar27), iVar7 != 0x7d)) {
        isUseDefaultFreq = true;
        if (fpga_version < 0xe) {
          chain_pic_buf[(iVar27 / 3) * 3][0] = '}';
          iVar7 = iVar27;
          do {
            iVar13 = 0;
            do {
              iVar14 = iVar7 * 0x1f + (iVar7 / 3) * 0x123 + iVar13;
              iVar13 = iVar13 + 1;
              *(uchar *)((int)chain_pic_buf + iVar14 + 0xb) = uVar3;
            } while (iVar13 != 0x12);
            iVar7 = iVar7 + 1;
          } while (iVar7 != iVar15 + 2);
        }
        else {
          if (uVar26 < 0xd) {
            iVar7 = *(int *)(puVar29 + -4);
          }
          else {
            iVar7 = 0;
          }
          chain_pic_buf[iVar7][0] = '}';
          puVar11 = chain_pic_buf[iVar7];
          do {
            iVar13 = 0;
            do {
              iVar14 = iVar13 + 1;
              puVar11[iVar13 + 0xb] = uVar3;
              iVar13 = iVar14;
            } while (iVar14 != 0x12);
            puVar11 = puVar11 + 0x1f;
          } while (puVar11 != (uchar *)(iVar7 * 0x80 + 0x6e6c71));
        }
        sprintf(logstr,"Chain[J%d] has no freq in PIC, set default freq=%dM\n",iVar15,uVar25);
        writeInitLogFile(logstr);
      }
      if (fpga_version < 0xe) {
        if ((chain_pic_buf[(iVar27 / 3) * 3][0] == '}') && (isUseDefaultFreq == false)) {
          sprintf(logstr,"Chain[J%d] has core num in PIC\n",iVar15);
          writeInitLogFile(logstr);
          iVar7 = 0;
          uVar19 = 0;
          do {
            iVar13 = (iVar27 / 3) * 0x123 + iVar27 * 0x1f + 0x6e6b5d + ((int)uVar19 >> 1);
            if ((uVar19 & 1) == 0) {
              uVar9 = (uint)(*(byte *)(iVar13 + 0xd4) >> 4);
            }
            else {
              uVar9 = *(byte *)(iVar13 + 0xd4) & 0xf;
            }
            *(uint *)((int)*paiVar17 + iVar7) = uVar9;
            if (uVar9 != 0) {
              sprintf(logstr,"Chain[J%d] ASIC[%d] has core num=%d\n",iVar15,uVar19,uVar9);
              writeInitLogFile(logstr);
            }
            uVar19 = uVar19 + 1;
            iVar7 = iVar7 + 4;
          } while (uVar19 != 0x12);
        }
        else {
          sprintf(logstr,"Chain[J%d] has no core num in PIC\n",iVar15);
          writeInitLogFile(logstr);
          iVar15 = 0;
          do {
            *(undefined4 *)((int)*paiVar17 + iVar15) = 0;
            iVar15 = iVar15 + 4;
          } while (iVar15 != 0x48);
        }
      }
      else {
        if (uVar26 < 0xd) {
          iVar27 = *(int *)(puVar29 + -4);
          iVar7 = *(int *)(puVar21 + -4);
        }
        else {
          iVar7 = 0;
          iVar27 = iVar7;
        }
        if ((chain_pic_buf[iVar27][0] == '}') && (isUseDefaultFreq == false)) {
          sprintf(logstr,"Chain[J%d] has core num in PIC\n",iVar15);
          writeInitLogFile(logstr);
          iVar13 = 0;
          uVar19 = 0;
          do {
            iVar14 = iVar27 * 0x80 + iVar7 * 0x1f + 0x6e6b5d + ((int)uVar19 >> 1);
            if ((uVar19 & 1) == 0) {
              uVar9 = (uint)(*(byte *)(iVar14 + 0xd4) >> 4);
            }
            else {
              uVar9 = *(byte *)(iVar14 + 0xd4) & 0xf;
            }
            *(uint *)((int)*paiVar17 + iVar13) = uVar9;
            if (uVar9 != 0) {
              sprintf(logstr,"Chain[J%d] ASIC[%d] has core num=%d\n",iVar15,uVar19,uVar9);
              writeInitLogFile(logstr);
            }
            uVar19 = uVar19 + 1;
            iVar13 = iVar13 + 4;
          } while (uVar19 != 0x12);
        }
        else {
          sprintf(logstr,"Chain[J%d] has no core num in PIC\n",iVar15);
          writeInitLogFile(logstr);
          iVar15 = 0;
          do {
            *(undefined4 *)((int)*paiVar17 + iVar15) = 0;
            iVar15 = iVar15 + 4;
          } while (iVar15 != 0x48);
        }
      }
    }
    paiVar17 = paiVar17 + 1;
    uVar26 = uVar26 + 1;
    puVar29 = puVar29 + 4;
    puVar21 = puVar21 + 4;
    iVar15 = iVar24;
  } while (iVar24 != 0x11);
  if (isUseDefaultFreq == false) {
    iVar24 = GetTotalRate();
    iVar27 = GetTotalRate();
    iVar15 = 0;
    if (500 < iVar27 % 1000) {
      iVar15 = 500;
    }
    sprintf(logstr,"miner total rate=%dGH/s fixed rate=%dGH/s\n",iVar24,
            (iVar27 / 1000) * 1000 + iVar15);
    writeInitLogFile(logstr);
  }
  if (opt_fixed_freq == false) {
    local_984 = 0xffffffff;
    local_990 = CSWTCH_825;
    local_988 = 1;
    local_980 = CSWTCH_824;
    iVar15 = 0;
    do {
      if ((dev->chain_exist[iVar15] == 1) && (dev->chain_asic_num[iVar15] != '\0')) {
        bVar4 = get_pic_voltage((uchar)iVar15);
        sprintf(logstr,"read PIC voltage=%d on chain[%d]\n",
                ((int)(longlong)(((364.0704 / ((double)bVar4 + 30.72) + 32.79) * 100.0) / 4.75) / 10
                ) * 10,iVar15);
        writeInitLogFile(logstr);
        sprintf(logstr,"Chain:%d chipnum=%d\n",iVar15,(uint)dev->chain_asic_num[iVar15]);
        writeInitLogFile(logstr);
        if (fpga_version < 0xe) {
          sprintf(logstr,"Chain[J%d] voltage added=0.%dV\n",local_988,
                  (uint)*(byte *)((int)chain_pic_buf + iVar15 * 0x1f + (iVar15 / 3) * 0x123 + 9));
        }
        else {
          if (local_984 < 0xd) {
            iVar24 = *(int *)(local_980 + -4);
            iVar27 = *(int *)(local_990 + -4) * 0x1f + 9;
          }
          else {
            iVar24 = 0;
            iVar27 = 9;
          }
          sprintf(logstr,"Chain[J%d] voltage added=0.%dV\n",local_988,
                  (uint)chain_pic_buf[iVar24][iVar27]);
        }
        writeInitLogFile(logstr);
        get_macBytes((char *)minerMAC,mac_00);
        if (fpga_version < 0xe) {
          iVar24 = (iVar15 / 3) * 0x180;
        }
        else {
          if (local_984 < 0xd) {
            iVar24 = *(int *)(local_980 + -4);
          }
          else {
            iVar24 = 0;
          }
          iVar24 = iVar24 << 7;
        }
        hashMAC[0] = chain_pic_buf[0][iVar24 + 1];
        hashMAC[1] = chain_pic_buf[0][iVar24 + 2];
        hashMAC[2] = chain_pic_buf[0][iVar24 + 3];
        hashMAC[3] = chain_pic_buf[0][iVar24 + 4];
        hashMAC[4] = chain_pic_buf[0][iVar24 + 5];
        hashMAC[5] = chain_pic_buf[0][iVar24 + 6];
        iVar24 = memcmp(hashMAC,minerMAC,6);
        if (iVar24 == 0) {
          uVar26 = (uint)minerMAC[2];
          uVar22 = (uint)minerMAC[1];
          uVar25 = (uint)minerMAC[3];
          uVar19 = (uint)minerMAC[4];
          uVar9 = (uint)minerMAC[5];
          sprintf(logstr,
                  "OK: Chain[J%d] is for this machine! [minerMAC: %02x:%02x:%02x:%02x:%02x:%02x]\n",
                  local_988,(uint)minerMAC[0],uVar22,uVar26,uVar25,uVar19,uVar9);
          writeInitLogFile(logstr);
        }
        else {
          uVar22 = (uint)minerMAC[1];
          uVar26 = (uint)minerMAC[2];
          uVar25 = (uint)minerMAC[3];
          uVar19 = (uint)minerMAC[4];
          uVar9 = (uint)minerMAC[5];
          sprintf(logstr,
                  "Chain[J%d] [minerMAC: %02x:%02x:%02x:%02x:%02x:%02x hashMAC: %02x:%02x:%02x:%02x:%02x:%02x]\n"
                  ,local_988,(uint)minerMAC[0],uVar22,uVar26,uVar25,uVar19,uVar9,(uint)hashMAC[0],
                  (uint)hashMAC[1],(uint)hashMAC[2],(uint)hashMAC[3],(uint)hashMAC[4],
                  (uint)hashMAC[5]);
          writeInitLogFile(logstr);
        }
        if (fpga_version < 0xe) {
          if (isUseDefaultFreq == false) {
            bVar4 = *(byte *)((int)chain_pic_buf + iVar15 * 0x1f + (iVar15 / 3) * 0x123 + 7);
            uVar16 = (uint)bVar4;
            base_freq_index[iVar15] = bVar4;
          }
          else {
            uVar16 = uVar6 & 0xff;
            base_freq_index[iVar15] = uVar3;
          }
          sprintf(logstr,"Chain:%d base freq=%s\n",iVar15,freq_pll_1385[uVar16].freq,uVar22,uVar26,
                  uVar25,uVar19,uVar9);
          writeInitLogFile(logstr);
          uVar25 = (uint)dev->chain_asic_num[iVar15];
          if (uVar25 == 0) goto LAB_00031982;
          uVar25 = 0;
          iVar24 = iVar15 / 3;
          uVar19 = 0;
          uVar26 = 100;
          iVar27 = (iVar15 % 3) * 0x1f + 0xb;
          do {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: freq index=%d\n","set_frequency",
                       (uint)chain_pic_buf[iVar24 * 3][iVar27]);
              _applog(7,tmp42,false);
            }
            iVar7 = iVar27 + iVar24 * 0x180;
            bVar4 = *(byte *)((int)&h + iVar7 + 0xd4);
            if (bVar4 < 4) {
              *(undefined1 *)((int)&h + iVar7 + 0xd4) = 4;
            }
            else if (100 < bVar4) {
              *(undefined1 *)((int)&h + iVar7 + 0xd4) = 100;
            }
            uVar9 = (uint)chain_pic_buf[iVar24 * 3][iVar27];
            if (uVar25 < uVar9) {
              uVar25 = uVar9;
            }
            if (uVar9 <= uVar26) {
              uVar26 = uVar9;
            }
            sprintf(logstr,"Asic[%2d]:%s ",uVar19,freq_pll_1385[uVar9].freq);
            writeInitLogFile(logstr);
            if ((uVar19 & 7) == 0) {
              logstr[0] = '\n';
              logstr[1] = '\0';
              writeInitLogFile(logstr);
            }
            uVar19 = uVar19 + 1;
            iVar27 = iVar27 + 1;
          } while ((int)uVar19 < (int)(uint)dev->chain_asic_num[iVar15]);
        }
        else {
          if (local_984 < 0xd) {
            iVar24 = *(int *)(local_980 + -4);
            iVar27 = *(int *)(local_990 + -4);
          }
          else {
            iVar27 = 0;
            iVar24 = iVar27;
          }
          if (isUseDefaultFreq == false) {
            uVar16 = (uint)chain_pic_buf[iVar24][iVar27 * 0x1f + 7];
            base_freq_index[iVar15] = chain_pic_buf[iVar24][iVar27 * 0x1f + 7];
          }
          else {
            uVar16 = uVar6 & 0xff;
            base_freq_index[iVar15] = uVar3;
          }
          sprintf(logstr,"Chain:%d base freq=%s\n",iVar15,freq_pll_1385[uVar16].freq,uVar22,uVar26,
                  uVar25,uVar19,uVar9);
          writeInitLogFile(logstr);
          uVar25 = (uint)dev->chain_asic_num[iVar15];
          if (uVar25 == 0) {
LAB_00031982:
            uVar26 = 100;
          }
          else {
            uVar25 = 0;
            uVar26 = 100;
            iVar27 = iVar27 * 0x1f + 0xb;
            uVar19 = 0;
            do {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: freq index=%d\n","set_frequency",
                         (uint)chain_pic_buf[iVar24][iVar27]);
                _applog(7,tmp42,false);
              }
              iVar7 = iVar27 + iVar24 * 0x80;
              bVar4 = *(byte *)((int)&h + iVar7 + 0xd4);
              if (bVar4 < 4) {
                *(undefined1 *)((int)&h + iVar7 + 0xd4) = 4;
              }
              else if (100 < bVar4) {
                *(undefined1 *)((int)&h + iVar7 + 0xd4) = 100;
              }
              uVar9 = (uint)chain_pic_buf[iVar24][iVar27];
              if (uVar25 < uVar9) {
                uVar25 = uVar9;
              }
              if (uVar9 <= uVar26) {
                uVar26 = uVar9;
              }
              sprintf(logstr,"Asic[%2d]:%s ",uVar19,freq_pll_1385[uVar9].freq);
              writeInitLogFile(logstr);
              if ((uVar19 & 7) == 0) {
                logstr[0] = '\n';
                logstr[1] = '\0';
                writeInitLogFile(logstr);
              }
              uVar19 = uVar19 + 1;
              iVar27 = iVar27 + 1;
            } while ((int)uVar19 < (int)(uint)dev->chain_asic_num[iVar15]);
          }
        }
        sprintf(logstr,"\nChain:%d max freq=%s\n",iVar15,freq_pll_1385[uVar25].freq);
        writeInitLogFile(logstr);
        sprintf(logstr,"Chain:%d min freq=%s\n",iVar15,freq_pll_1385[uVar26].freq);
        writeInitLogFile(logstr);
        logstr[0] = '\n';
        logstr[1] = '\0';
        writeInitLogFile(logstr);
      }
      iVar15 = iVar15 + 1;
      local_988 = local_988 + 1;
      local_984 = local_984 + 1;
      local_980 = local_980 + 4;
      local_990 = local_990 + 4;
    } while (iVar15 != 0x10);
  }
  builtin_strncpy(logstr,"\nMiner fix freq ...\n",0x14);
  logstr[0x14] = '\0';
  writeInitLogFile(logstr);
  paVar18 = dev;
  if (isUseDefaultFreq == false) {
    iVar15 = 0;
    iVar24 = 0;
    do {
      iVar27 = iVar24 + 4;
      if (*(int *)((int)dev->chain_exist + iVar24) == 1) {
        iVar15 = iVar15 + 1;
      }
      iVar24 = iVar27;
    } while (iVar27 != 0x40);
    if (8 < iVar15) {
      iVar15 = GetTotalRate();
      if (iVar15 % 1000 < 0x1f5) {
        iVar24 = 0;
      }
      else {
        iVar24 = 500;
      }
      iVar15 = (((iVar15 / 1000) * 1000 + iVar24) * 0x66) / 100;
      iVar24 = GetTotalRate();
      paVar18 = dev;
      if (iVar15 < iVar24) {
        do {
          uVar25 = dev->chain_exist[0];
          iVar24 = 0;
          iVar27 = fpga_version;
          while( true ) {
            fpga_version = iVar27;
            if (uVar25 == 1) {
              iVar7 = (iVar24 - 1U) * 4;
              iVar13 = 0;
              iVar14 = 0;
              do {
                if (iVar27 < 0xe) {
                  *(uint *)((int)last_record_freq[iVar24] + iVar13) =
                       (uint)*(byte *)((int)chain_pic_buf +
                                      iVar24 * 0x1f + (iVar24 / 3) * 0x123 + iVar14 + 0xb);
                }
                else {
                  iVar10 = 0xb;
                  iVar23 = 0;
                  if (iVar24 - 1U < 0xd) {
                    iVar23 = *(int *)(CSWTCH_824 + iVar7);
                    iVar10 = *(int *)(CSWTCH_825 + iVar7) * 0x1f + 0xb;
                  }
                  *(uint *)((int)last_record_freq[iVar24] + iVar13) =
                       (uint)chain_pic_buf[iVar23][iVar10 + iVar14];
                }
                iVar14 = iVar14 + 1;
                iVar13 = iVar13 + 4;
              } while (iVar14 != 0x12);
            }
            if (0xf < iVar24 + 1) break;
            uVar25 = dev->chain_exist[iVar24 + 1];
            iVar24 = iVar24 + 1;
            iVar27 = fpga_version;
          }
          _Var5 = DownOneChipFreqOneStep();
        } while ((_Var5) && (iVar24 = GetTotalRate(), iVar15 < iVar24));
        paVar18 = dev;
        iVar15 = fpga_version;
        iVar24 = 0;
        iVar27 = 0;
        paiVar17 = last_record_freq;
        do {
          if (*(int *)((int)paVar18->chain_exist + iVar24) == 1) {
            iVar7 = 0;
            iVar13 = 0;
            do {
              if (iVar15 < 0xe) {
                *(char *)((int)chain_pic_buf + iVar27 * 0x1f + (iVar27 / 3) * 0x123 + iVar13 + 0xb)
                     = (char)*(undefined4 *)((int)*paiVar17 + iVar7);
              }
              else {
                iVar23 = 0xb;
                iVar14 = 0;
                if (iVar27 - 1U < 0xd) {
                  iVar14 = *(int *)("" + iVar24 + 0xfc);
                  iVar23 = *(int *)(CSWTCH_824 + iVar24 + 0x30) * 0x1f + 0xb;
                }
                chain_pic_buf[iVar14][iVar23 + iVar13] =
                     (uchar)*(undefined4 *)((int)*paiVar17 + iVar7);
              }
              iVar13 = iVar13 + 1;
              iVar7 = iVar7 + 4;
            } while (iVar13 != 0x12);
          }
          iVar27 = iVar27 + 1;
          iVar24 = iVar24 + 4;
          paiVar17 = paiVar17 + 1;
        } while (iVar27 != 0x10);
      }
    }
  }
  iVar15 = 0;
  paVar28 = paVar18;
  do {
    while (puVar1 = paVar28->chain_exist, paVar28 = (all_parameters *)&paVar28->pwm_value,
          *puVar1 != 1) {
      iVar15 = iVar15 + 1;
      if (iVar15 == 0x10) goto LAB_0003065e;
    }
    pauVar8 = chip_last_freq + iVar15;
    pauVar12 = chain_pic_buf + iVar15;
    iVar15 = iVar15 + 1;
    memcpy(pauVar8,pauVar12,0x80);
  } while (iVar15 != 0x10);
LAB_0003065e:
  iVar15 = 0;
  local_990 = (undefined1 *)0x0;
  local_980 = (undefined1 *)0x1;
  do {
    if ((paVar18->chain_exist[iVar15] == 1) && (paVar18->chain_asic_num[iVar15] != '\0')) {
      chain = (uchar)iVar15;
      bVar4 = get_pic_voltage(chain);
      sprintf(logstr,"read PIC voltage=%d on chain[%d]\n",
              ((int)(longlong)(((364.0704 / ((double)bVar4 + 30.72) + 32.79) * 100.0) / 4.75) / 10)
              * 10,iVar15);
      writeInitLogFile(logstr);
      sprintf(logstr,"Chain:%d chipnum=%d\n",iVar15,(uint)dev->chain_asic_num[iVar15]);
      writeInitLogFile(logstr);
      if (opt_fixed_freq == false) {
        if (fpga_version < 0xe) {
          sprintf(logstr,"Chain[J%d] voltage added=0.%dV\n",local_980,
                  (uint)*(byte *)((int)chain_pic_buf + iVar15 * 0x1f + (iVar15 / 3) * 0x123 + 9));
        }
        else {
          if (iVar15 - 1U < 0xd) {
            iVar24 = *(int *)(local_978 + -4);
            iVar27 = *(int *)(local_974 + -4) * 0x1f + 9;
          }
          else {
            iVar27 = 9;
            iVar24 = 0;
          }
          sprintf(logstr,"Chain[J%d] voltage added=0.%dV\n",local_980,
                  (uint)chain_pic_buf[iVar24][iVar27]);
        }
        writeInitLogFile(logstr);
        get_macBytes((char *)minerMAC,mac);
        if (fpga_version < 0xe) {
          iVar24 = (iVar15 / 3) * 0x180;
        }
        else {
          if (iVar15 - 1U < 0xd) {
            iVar24 = *(int *)(local_978 + -4);
          }
          else {
            iVar24 = 0;
          }
          iVar24 = iVar24 << 7;
        }
        hashMAC[0] = chain_pic_buf[0][iVar24 + 1];
        hashMAC[1] = chain_pic_buf[0][iVar24 + 2];
        hashMAC[2] = chain_pic_buf[0][iVar24 + 3];
        hashMAC[3] = chain_pic_buf[0][iVar24 + 4];
        hashMAC[4] = chain_pic_buf[0][iVar24 + 5];
        hashMAC[5] = chain_pic_buf[0][iVar24 + 6];
        iVar24 = memcmp(hashMAC,minerMAC,6);
        if (iVar24 == 0) {
          uVar9 = (uint)minerMAC[1];
          uVar26 = (uint)minerMAC[2];
          uVar25 = (uint)minerMAC[3];
          uVar22 = (uint)minerMAC[5];
          uVar19 = (uint)minerMAC[4];
          sprintf(logstr,
                  "OK: Chain[J%d] is for this machine! [minerMAC: %02x:%02x:%02x:%02x:%02x:%02x]\n",
                  local_980,(uint)minerMAC[0],uVar9,uVar26,uVar25,uVar19,uVar22);
          writeInitLogFile(logstr);
        }
        else {
          uVar9 = (uint)minerMAC[1];
          uVar26 = (uint)minerMAC[2];
          uVar25 = (uint)minerMAC[3];
          uVar19 = (uint)minerMAC[4];
          uVar22 = (uint)minerMAC[5];
          sprintf(logstr,
                  "Chain[J%d] [minerMAC: %02x:%02x:%02x:%02x:%02x:%02x hashMAC: %02x:%02x:%02x:%02x:%02x:%02x]\n"
                  ,local_980,(uint)minerMAC[0],uVar9,uVar26,uVar25,uVar19,uVar22,(uint)hashMAC[0],
                  (uint)hashMAC[1],(uint)hashMAC[2],(uint)hashMAC[3],(uint)hashMAC[4],
                  (uint)hashMAC[5]);
          writeInitLogFile(logstr);
        }
        cVar20 = opt_fixed_freq;
        if (fpga_version < 0xe) {
          if (opt_fixed_freq == false) {
            if (isUseDefaultFreq == false) {
              bVar4 = *(byte *)((int)chain_pic_buf + iVar15 * 0x1f + (iVar15 / 3) * 0x123 + 7);
              uVar16 = (uint)bVar4;
              base_freq_index[iVar15] = bVar4;
            }
            else {
              uVar16 = uVar6 & 0xff;
              base_freq_index[iVar15] = uVar3;
            }
            sprintf(logstr,"Chain:%d base freq=%s\n",iVar15,freq_pll_1385[uVar16].freq,uVar9,uVar26,
                    uVar25,uVar19,uVar22);
            writeInitLogFile(logstr);
          }
          goto LAB_000307b2;
        }
LAB_000308fe:
        if (iVar15 - 1U < 0xd) {
          iVar24 = *(int *)(local_978 + -4);
          iVar27 = *(int *)(local_974 + -4);
        }
        else {
          iVar27 = 0;
          iVar24 = iVar27;
        }
        if (cVar20 == '\0') {
          if (isUseDefaultFreq == false) {
            uVar25 = (uint)chain_pic_buf[iVar24][iVar27 * 0x1f + 7];
            base_freq_index[iVar15] = chain_pic_buf[iVar24][iVar27 * 0x1f + 7];
          }
          else {
            uVar25 = uVar6 & 0xff;
            base_freq_index[iVar15] = uVar3;
          }
          sprintf(logstr,"Chain:%d base freq=%s\n",iVar15,freq_pll_1385[uVar25].freq);
          writeInitLogFile(logstr);
        }
        uVar25 = (uint)dev->chain_asic_num[iVar15];
        if (uVar25 == 0) {
LAB_00031974:
          uVar26 = 100;
        }
        else {
          uVar25 = 0;
          uVar26 = 100;
          iVar27 = iVar27 * 0x1f + 0xb;
          uVar19 = 0;
          do {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: freq index=%d\n","set_frequency",
                       (uint)chain_pic_buf[iVar24][iVar27]);
              _applog(7,tmp42,false);
            }
            iVar7 = iVar27 + iVar24 * 0x80;
            bVar4 = *(byte *)((int)&h + iVar7 + 0xd4);
            if (bVar4 < 4) {
              *(undefined1 *)((int)&h + iVar7 + 0xd4) = 4;
            }
            else if (100 < bVar4) {
              *(undefined1 *)((int)&h + iVar7 + 0xd4) = 100;
            }
            iVar7 = iVar27 + iVar24 * 0x80;
            uVar9 = (uint)*(byte *)((int)&h + iVar7 + 0xd4);
            if (local_990 < uVar9) {
              local_990 = (undefined1 *)uVar9;
            }
            if (uVar25 < uVar9) {
              uVar25 = uVar9;
            }
            if (uVar9 <= uVar26) {
              uVar26 = uVar9;
            }
            set_frequency_with_addr_plldatai(uVar9,'\0',(char)uVar19 * dev->addrInterval,chain);
            sprintf(logstr,"Asic[%2d]:%s ",uVar19,
                    freq_pll_1385[*(byte *)((int)&h + iVar7 + 0xd4)].freq);
            writeInitLogFile(logstr);
            if ((uVar19 & 7) == 0) {
              logstr[0] = '\n';
              logstr[1] = '\0';
              writeInitLogFile(logstr);
            }
            uVar19 = uVar19 + 1;
            iVar27 = iVar27 + 1;
          } while ((int)uVar19 < (int)(uint)dev->chain_asic_num[iVar15]);
        }
      }
      else {
        cVar20 = '\x01';
        if (0xd < fpga_version) goto LAB_000308fe;
LAB_000307b2:
        uVar25 = (uint)dev->chain_asic_num[iVar15];
        if (uVar25 == 0) goto LAB_00031974;
        uVar25 = 0;
        uVar19 = 0;
        uVar26 = 100;
        iVar27 = (iVar15 / 3) * 0x180;
        iVar24 = (iVar15 % 3) * 0x1f + 0xb;
        do {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: freq index=%d\n","set_frequency",
                     (uint)chain_pic_buf[(iVar15 / 3) * 3][iVar24]);
            _applog(7,tmp42,false);
          }
          iVar7 = iVar24 + iVar27;
          bVar4 = *(byte *)((int)&h + iVar7 + 0xd4);
          if (bVar4 < 4) {
            *(undefined1 *)((int)&h + iVar7 + 0xd4) = 4;
          }
          else if (100 < bVar4) {
            *(undefined1 *)((int)&h + iVar7 + 0xd4) = 100;
          }
          iVar7 = iVar24 + iVar27;
          uVar9 = (uint)*(byte *)((int)&h + iVar7 + 0xd4);
          if (local_990 < uVar9) {
            local_990 = (undefined1 *)uVar9;
          }
          if (uVar25 < uVar9) {
            uVar25 = uVar9;
          }
          if (uVar9 <= uVar26) {
            uVar26 = uVar9;
          }
          set_frequency_with_addr_plldatai(uVar9,'\0',(char)uVar19 * dev->addrInterval,chain);
          sprintf(logstr,"Asic[%2d]:%s ",uVar19,
                  freq_pll_1385[*(byte *)((int)&h + iVar7 + 0xd4)].freq);
          writeInitLogFile(logstr);
          if ((uVar19 & 7) == 0) {
            logstr[0] = '\n';
            logstr[1] = '\0';
            writeInitLogFile(logstr);
          }
          uVar19 = uVar19 + 1;
          iVar24 = iVar24 + 1;
        } while ((int)uVar19 < (int)(uint)dev->chain_asic_num[iVar15]);
      }
      sprintf(logstr,"\nChain:%d max freq=%s\n",iVar15,freq_pll_1385[uVar25].freq);
      writeInitLogFile(logstr);
      sprintf(logstr,"Chain:%d min freq=%s\n",iVar15,freq_pll_1385[uVar26].freq);
      writeInitLogFile(logstr);
      logstr[0] = '\n';
      logstr[1] = '\0';
      writeInitLogFile(logstr);
    }
    iVar15 = iVar15 + 1;
    local_980 = (undefined1 *)((int)local_980 + 1);
    local_978 = local_978 + 4;
    local_974 = local_974 + 4;
    paVar18 = dev;
  } while (iVar15 != 0x10);
  uVar25 = strtol(freq_pll_1385[(int)local_990].freq,(char **)0x0,10);
  dev->frequency = (ushort)uVar25;
  sprintf(logstr,"max freq = %d\n",uVar25 & 0xffff);
  writeInitLogFile(logstr);
  paVar18 = dev;
  if (isUseDefaultFreq == false) {
    iVar24 = GetTotalRate();
    iVar15 = 0;
    if (500 < iVar24 % 1000) {
      iVar15 = 500;
    }
    iVar15 = (iVar24 / 1000) * 1000 + iVar15;
    iVar24 = GetTotalRate();
    paVar18 = dev;
    if (iVar15 < iVar24) {
      do {
        uVar25 = dev->chain_exist[0];
        iVar24 = 0;
        iVar27 = fpga_version;
        while( true ) {
          fpga_version = iVar27;
          if (uVar25 == 1) {
            iVar13 = 0;
            iVar7 = (iVar24 - 1U) * 4;
            iVar14 = 0;
            do {
              if (iVar27 < 0xe) {
                *(uint *)((int)last_record_freq[iVar24] + iVar13) =
                     (uint)*(byte *)((int)chain_pic_buf +
                                    iVar24 * 0x1f + (iVar24 / 3) * 0x123 + iVar14 + 0xb);
              }
              else {
                iVar10 = 0xb;
                iVar23 = 0;
                if (iVar24 - 1U < 0xd) {
                  iVar23 = *(int *)(CSWTCH_824 + iVar7);
                  iVar10 = *(int *)(CSWTCH_825 + iVar7) * 0x1f + 0xb;
                }
                *(uint *)((int)last_record_freq[iVar24] + iVar13) =
                     (uint)chain_pic_buf[iVar23][iVar10 + iVar14];
              }
              iVar14 = iVar14 + 1;
              iVar13 = iVar13 + 4;
            } while (iVar14 != 0x12);
          }
          if (0xf < iVar24 + 1) break;
          uVar25 = dev->chain_exist[iVar24 + 1];
          iVar24 = iVar24 + 1;
          iVar27 = fpga_version;
        }
        _Var5 = DownOneChipFreqOneStep();
      } while ((_Var5) && (iVar24 = GetTotalRate(), iVar15 < iVar24));
      paVar18 = dev;
      iVar15 = fpga_version;
      iVar27 = 0;
      paiVar17 = last_record_freq;
      iVar24 = 0;
      do {
        while (*(int *)((int)paVar18->chain_exist + iVar27) != 1) {
          iVar24 = iVar24 + 1;
          iVar27 = iVar27 + 4;
          paiVar17 = paiVar17 + 1;
          if (iVar24 == 0x10) goto LAB_00030af4;
        }
        uVar25 = iVar24 - 1;
        iVar13 = 0;
        iVar7 = 0;
        do {
          while (0xd < iVar15) {
            iVar14 = 0;
            if (uVar25 < 0xd) {
              iVar14 = *(int *)("" + iVar27 + 0xfc);
            }
            iVar23 = 0xb;
            if (uVar25 < 0xd) {
              iVar23 = *(int *)(CSWTCH_824 + iVar27 + 0x30);
            }
            puVar2 = (undefined4 *)((int)*paiVar17 + iVar13);
            iVar13 = iVar13 + 4;
            if (uVar25 < 0xd) {
              iVar23 = iVar23 * 0x1f;
            }
            iVar10 = iVar7 + 1;
            if (uVar25 < 0xd) {
              iVar23 = iVar23 + 0xb;
            }
            chain_pic_buf[iVar14][iVar23 + iVar7] = (uchar)*puVar2;
            iVar7 = iVar10;
            if (iVar10 == 0x12) goto LAB_000318a2;
          }
          puVar2 = (undefined4 *)((int)*paiVar17 + iVar13);
          iVar14 = iVar7 + 1;
          iVar13 = iVar13 + 4;
          *(char *)((int)chain_pic_buf + iVar24 * 0x1f + (iVar24 / 3) * 0x123 + iVar7 + 0xb) =
               (char)*puVar2;
          iVar7 = iVar14;
        } while (iVar14 != 0x12);
LAB_000318a2:
        iVar27 = iVar27 + 4;
        paiVar17 = paiVar17 + 1;
        iVar24 = iVar24 + 1;
      } while (iVar24 != 0x10);
    }
  }
LAB_00030af4:
  iVar15 = 0;
  do {
    while (puVar1 = paVar18->chain_exist, paVar18 = (all_parameters *)&paVar18->pwm_value,
          *puVar1 == 1) {
      pauVar8 = show_last_freq + iVar15;
      pauVar12 = chain_pic_buf + iVar15;
      iVar15 = iVar15 + 1;
      memcpy(pauVar8,pauVar12,0x80);
      if (iVar15 == 0x10) {
        return;
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 != 0x10);
  return;
}

