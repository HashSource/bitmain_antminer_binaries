
void set_frequency(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  FILE *pFVar6;
  void *pvVar7;
  long lVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  undefined1 *__dest;
  undefined1 *puVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  byte *pbVar19;
  uint uVar20;
  int *piVar21;
  undefined4 *puVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint local_898;
  byte *local_88c;
  int local_888;
  uint *local_880;
  int local_87c;
  byte *local_878;
  byte *local_868;
  undefined1 *local_864;
  undefined2 local_85a;
  undefined4 local_858;
  undefined4 local_854;
  char acStack_850 [2052];
  
  local_858 = 0;
  local_85a = 0;
  local_854 = 0;
  bVar3 = get_pll_index();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_850,0x800,"\n--- %s\n","set_frequency");
    _applog(7,acStack_850,0);
  }
  get_plldata_constprop_17(param_1,&local_858,&local_85a,&local_854);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_850,0x800,"%s: frequency = %d\n","set_frequency",param_1);
    _applog(7,acStack_850,0);
  }
  local_868 = chain_pic_buf + 1;
  pbVar19 = chain_pic_buf + 1;
  puVar22 = (undefined4 *)(iic_mutex + 0x14);
  iVar4 = 1;
  do {
    while ((iVar17 = iVar4 + 1, *(int *)(dev + iVar17 * 4) == 1 &&
           (*(char *)(dev + iVar4 + 0x53eb) != '\0'))) {
      if ((opt_fixed_freq == '\0') && (pbVar19[-1] == 0x7d)) {
LAB_0003054e:
        if (3 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: Chain[J%d] has no core num in PIC\n","driver-btm-c5.c",0x11c1,
                    "set_frequency",iVar4);
          }
          fclose(pFVar6);
        }
      }
      else {
        pbVar19[-1] = 0x7d;
        isUseDefaultFreq = '\x01';
        pbVar13 = pbVar19;
        do {
          pbVar13 = pbVar13 + 1;
          *pbVar13 = bVar3;
        } while (pbVar13 != pbVar19 + 0x54);
        if (3 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: Chain[J%d] has no freq in PIC, set default freq=%dM\n",
                    "driver-btm-c5.c",0x1184,"set_frequency",iVar4,param_1);
          }
          fclose(pFVar6);
          goto LAB_0003054e;
        }
      }
      puVar14 = puVar22;
      do {
        puVar14 = puVar14 + 1;
        *puVar14 = 0;
      } while (puVar14 != puVar22 + 0x54);
      puVar22 = puVar22 + 0x100;
      pbVar19 = pbVar19 + 0x80;
      iVar4 = iVar17;
      if (iVar17 == 0x11) goto LAB_00030312;
    }
    puVar22 = puVar22 + 0x100;
    pbVar19 = pbVar19 + 0x80;
    iVar4 = iVar17;
  } while (iVar17 != 0x11);
LAB_00030312:
  if ((opt_economic_mode == '\0') || (iVar4 = GetTotalRate_part_12(), opt_economic_mode == '\0')) {
    iVar4 = get_total_rate_from_eeprom();
  }
  if (iVar4 % 1000 < 500) {
    iVar17 = 0;
  }
  else {
    iVar17 = 500;
  }
  ideal_total_hash_rate = (iVar4 / 1000) * 1000 + iVar17;
  if (log_level < 4) {
    if (opt_fixed_freq == '\0') {
LAB_0003036a:
      uVar26 = 0;
      local_880 = (uint *)(chain_pic_buf + 2);
      local_88c = base_freq_index;
      local_888 = 1;
      do {
        if ((*(int *)(dev + (uVar26 + 2) * 4) == 1) && (*(char *)(dev + uVar26 + 0x53ec) != '\0')) {
          iVar4 = write_EEPROM_iic(1,1,0x90,uVar26 & 0xff,0);
          if (3 < log_level) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,"%s:%d:%s: read PIC voltage=%d on chain[%d]\n","driver-btm-c5.c",0x1209
                      ,"set_frequency",
                      ((int)(longlong)
                            (((364.0704 / ((double)(longlong)iVar4 + 30.72) + 32.79) * 100.0) / 4.75
                            ) / 10) * 10,uVar26);
            }
            fclose(pFVar6);
            if (3 < log_level) {
              pFVar6 = fopen(log_file,"a+");
              if (pFVar6 != (FILE *)0x0) {
                fprintf(pFVar6,"%s:%d:%s: Chain:%d chipnum=%d\n","driver-btm-c5.c",0x120b,
                        "set_frequency",uVar26,(uint)*(byte *)(dev + uVar26 + 0x53ec));
              }
              fclose(pFVar6);
              if (3 < log_level) {
                pFVar6 = fopen(log_file,"a+");
                if (pFVar6 != (FILE *)0x0) {
                  fprintf(pFVar6,"%s:%d:%s: S9+ can not record Chain[J%d] voltage added value\n",
                          "driver-btm-c5.c",0x121d,"set_frequency",local_888);
                }
                fclose(pFVar6);
              }
            }
          }
          uVar24 = log_level;
          if (isUseDefaultFreq == '\0') {
            *local_88c = 0xc;
          }
          else {
            *local_88c = bVar3;
          }
          if (3 < uVar24) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,"%s:%d:%s: Chain:%d base freq=%s\n","driver-btm-c5.c",0x1299,
                      "set_frequency",uVar26,
                      *(undefined4 *)(freq_pll_1385 + (uint)*local_88c * 0x10));
            }
            fclose(pFVar6);
            uVar24 = log_level;
          }
          uVar20 = 100;
          uVar23 = 0;
          uVar5 = (uint)*(byte *)(dev + uVar26 + 0x53ec);
          puVar15 = local_880;
          for (uVar18 = 1; (int)(uVar18 - 1) < (int)uVar5; uVar18 = uVar18 + 1) {
            uVar11 = (uint)*(byte *)puVar15;
            if (uVar11 < 4) {
              uVar11 = 4;
              *(byte *)puVar15 = 4;
            }
            else if (0x6a < uVar11) {
              uVar11 = 0x6a;
              *(byte *)puVar15 = 0x6a;
            }
            if (uVar23 < uVar11) {
              uVar23 = uVar11;
            }
            if (uVar11 <= uVar20) {
              uVar20 = uVar11;
            }
            if (3 < uVar24) {
              pFVar6 = fopen(log_file,"a+");
              if (pFVar6 != (FILE *)0x0) {
                fprintf(pFVar6,"Asic[%2d]:%s ",uVar18 - 1,
                        *(undefined4 *)(freq_pll_1385 + (uint)*(byte *)puVar15 * 0x10));
              }
              fclose(pFVar6);
              if ((uVar18 & 7) == 0) {
                if (log_level < 4) {
                  uVar5 = (uint)*(byte *)(dev + uVar26 + 0x53ec);
                  uVar24 = log_level;
                  goto LAB_0003043a;
                }
                pFVar6 = fopen(log_file,"a+");
                if (pFVar6 != (FILE *)0x0) {
                  fputc(10,pFVar6);
                }
                fclose(pFVar6);
              }
              uVar5 = (uint)*(byte *)(dev + uVar26 + 0x53ec);
              uVar24 = log_level;
            }
LAB_0003043a:
            puVar15 = (uint *)((int)puVar15 + 1);
          }
          if (3 < uVar24) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fputc(10,pFVar6);
            }
            fclose(pFVar6);
            if (3 < log_level) {
              pFVar6 = fopen(log_file,"a+");
              if (pFVar6 != (FILE *)0x0) {
                fprintf(pFVar6,"%s:%d:%s: Chain:%d max freq=%s\n","driver-btm-c5.c",0x12de,
                        "set_frequency",uVar26,*(undefined4 *)(freq_pll_1385 + uVar23 * 0x10));
              }
              fclose(pFVar6);
              if (3 < log_level) {
                pFVar6 = fopen(log_file,"a+");
                if (pFVar6 != (FILE *)0x0) {
                  fprintf(pFVar6,"%s:%d:%s: Chain:%d min freq=%s\n","driver-btm-c5.c",0x12df,
                          "set_frequency",uVar26,*(undefined4 *)(freq_pll_1385 + uVar20 * 0x10));
                }
                fclose(pFVar6);
                if (3 < log_level) {
                  pFVar6 = fopen(log_file,"a+");
                  if (pFVar6 != (FILE *)0x0) {
                    fputc(10,pFVar6);
                  }
                  fclose(pFVar6);
                }
              }
            }
          }
        }
        uVar26 = uVar26 + 1;
        local_888 = local_888 + 1;
        local_880 = (uint *)((int)local_880 + 0x80);
        local_88c = local_88c + 1;
      } while (uVar26 != 0x10);
      goto LAB_0003058e;
    }
  }
  else {
    pFVar6 = fopen(log_file,"a+");
    if (pFVar6 != (FILE *)0x0) {
      fprintf(pFVar6,"%s:%d:%s: miner total rate=%dGH/s ideal_total_hash_rate = %dGH/s\n",
              "driver-btm-c5.c",0x11f0,"set_frequency",iVar4,ideal_total_hash_rate);
    }
    fclose(pFVar6);
    if (opt_fixed_freq == '\0') goto LAB_0003036a;
LAB_0003058e:
    if (3 < log_level) {
      pFVar6 = fopen(log_file,"a+");
      if (pFVar6 != (FILE *)0x0) {
        fputc(10,pFVar6);
      }
      fclose(pFVar6);
      if (3 < log_level) {
        pFVar6 = fopen(log_file,"a+");
        if (pFVar6 != (FILE *)0x0) {
          fprintf(pFVar6,"%s:%d:%s: Miner fix freq ...\n","driver-btm-c5.c",0x12e8,"set_frequency");
        }
        fclose(pFVar6);
      }
    }
  }
  iVar4 = dev;
  __dest = chip_last_freq;
  local_864 = chain_pic_buf;
  piVar21 = (int *)(dev + 4);
  puVar12 = chain_pic_buf;
  do {
    while (piVar21 = piVar21 + 1, *piVar21 == 1) {
      pvVar7 = memcpy(__dest,puVar12,0x80);
      __dest = (undefined1 *)((int)pvVar7 + 0x100);
      puVar12 = puVar12 + 0x80;
      if (__dest == init_log_mutex) goto LAB_000305d4;
    }
    __dest = __dest + 0x100;
    puVar12 = puVar12 + 0x80;
  } while (__dest != init_log_mutex);
LAB_000305d4:
  local_878 = chain_pic_buf + 2;
  local_880 = (uint *)(base_freq_index + 0xc);
  local_898 = 0;
  uVar26 = 0;
  local_87c = 1;
  do {
    if ((*(int *)(iVar4 + (local_898 + 2) * 4) == 1) &&
       (*(char *)(iVar4 + local_898 + 0x53ec) != '\0')) {
      iVar4 = write_EEPROM_iic(1,1,0x90,local_898 & 0xff,0);
      if (3 < log_level) {
        pFVar6 = fopen(log_file,"a+");
        if (pFVar6 != (FILE *)0x0) {
          fprintf(pFVar6,"%s:%d:%s: read PIC voltage=%d on chain[%d]\n","driver-btm-c5.c",0x130b,
                  "set_frequency",
                  ((int)(longlong)
                        (((364.0704 / ((double)(longlong)iVar4 + 30.72) + 32.79) * 100.0) / 4.75) /
                  10) * 10,local_898);
        }
        fclose(pFVar6);
        if (3 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: Chain:%d chipnum=%d\n","driver-btm-c5.c",0x130c,
                    "set_frequency",local_898,(uint)*(byte *)(dev + local_898 + 0x53ec));
          }
          fclose(pFVar6);
        }
      }
      if (opt_fixed_freq == '\0') {
        if (3 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: S9+ can not record Chain[J%d] voltage added value\n",
                    "driver-btm-c5.c",0x131d,"set_frequency",local_87c);
          }
          fclose(pFVar6);
          if (opt_fixed_freq != '\0') goto LAB_000306d8;
        }
        uVar24 = log_level;
        if (isUseDefaultFreq == '\0') {
          base_freq_index[local_898] = 0xc;
        }
        else {
          base_freq_index[local_898] = bVar3;
        }
        if (3 < uVar24) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: Chain:%d base freq=%s\n","driver-btm-c5.c",0x13b1,
                    "set_frequency",local_898,
                    *(undefined4 *)(freq_pll_1385 + (uint)(byte)base_freq_index[local_898] * 0x10));
          }
          fclose(pFVar6);
        }
      }
LAB_000306d8:
      uVar24 = 100;
      uVar20 = 0;
      pbVar19 = local_878;
      puVar15 = local_880;
      for (uVar23 = 1; iVar4 = dev, iVar17 = uVar23 - 1,
          iVar17 < (int)(uint)*(byte *)(dev + local_898 + 0x53ec); uVar23 = uVar23 + 1) {
        uVar5 = (uint)*pbVar19;
        if (uVar5 < 4) {
          uVar5 = 4;
          *pbVar19 = 4;
        }
        else if (0x6a < uVar5) {
          uVar5 = 0x6a;
          *pbVar19 = 0x6a;
        }
        if (uVar26 < uVar5) {
          uVar26 = uVar5;
        }
        if (uVar20 < uVar5) {
          uVar20 = uVar5;
        }
        if (uVar5 <= uVar24) {
          uVar24 = uVar5;
        }
        set_frequency_with_addr_plldatai
                  (uVar5,0,(int)(short)iVar17 * (int)(short)(ushort)*(byte *)(iVar4 + 0x542d) & 0xff
                   ,local_898 & 0xff);
        uVar5 = log_level;
        puVar15 = puVar15 + 1;
        *puVar15 = (uint)*pbVar19;
        if (3 < uVar5) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"Asic[%2d]:%s ",iVar17,
                    *(undefined4 *)(freq_pll_1385 + (uint)*pbVar19 * 0x10));
          }
          fclose(pFVar6);
          if (((uVar23 & 7) == 0) && (3 < log_level)) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fputc(10,pFVar6);
            }
            fclose(pFVar6);
          }
        }
        pbVar19 = pbVar19 + 1;
      }
      if (3 < log_level) {
        pFVar6 = fopen(log_file,"a+");
        if (pFVar6 != (FILE *)0x0) {
          fputc(10,pFVar6);
        }
        fclose(pFVar6);
        if (3 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: Chain:%d max freq=%s\n","driver-btm-c5.c",0x140b,
                    "set_frequency",local_898,*(undefined4 *)(freq_pll_1385 + uVar20 * 0x10));
          }
          fclose(pFVar6);
          if (3 < log_level) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,"%s:%d:%s: Chain:%d min freq=%s\n","driver-btm-c5.c",0x140c,
                      "set_frequency",local_898,*(undefined4 *)(freq_pll_1385 + uVar24 * 0x10));
            }
            fclose(pFVar6);
            if (3 < log_level) {
              pFVar6 = fopen(log_file,"a+");
              if (pFVar6 != (FILE *)0x0) {
                fputc(10,pFVar6);
              }
              fclose(pFVar6);
            }
          }
        }
      }
    }
    local_87c = local_87c + 1;
    local_898 = local_898 + 1;
    local_878 = local_878 + 0x80;
    local_880 = local_880 + 0x100;
    iVar4 = dev;
  } while (local_898 != 0x10);
  lVar8 = strtol(*(char **)(freq_pll_1385 + uVar26 * 0x10),(char **)0x0,10);
  uVar26 = log_level;
  *(short *)(dev + 0x5443) = (short)lVar8;
  if (3 < uVar26) {
    pFVar6 = fopen(log_file,"a+");
    if (pFVar6 != (FILE *)0x0) {
      fprintf(pFVar6,"%s:%d:%s: max freq = %d\n","driver-btm-c5.c",0x1414,"set_frequency",
              (uint)*(ushort *)(dev + 0x5443));
    }
    fclose(pFVar6);
  }
  iVar4 = ideal_total_hash_rate;
  if (isUseDefaultFreq == '\0') {
    if (ideal_total_hash_rate % 1000 < 500) {
      iVar17 = 0;
    }
    else {
      iVar17 = 500;
    }
    iVar17 = (ideal_total_hash_rate / 1000) * 1000 + iVar17;
    if (3 < log_level) {
      pFVar6 = fopen(log_file,"a+");
      if (pFVar6 != (FILE *)0x0) {
        fprintf(pFVar6,"%s:%d:%s: totalRate = %d, fixed_totalRate = %d\n","driver-btm-c5.c",0x1057,
                "ProcessFixFreq",iVar4,iVar17);
      }
      fclose(pFVar6);
      iVar4 = ideal_total_hash_rate;
    }
    ideal_total_hash_rate = iVar4;
    if (opt_economic_mode != '\0') {
      iVar4 = GetTotalRate_part_12();
    }
    iVar9 = dev;
    if (iVar17 < iVar4) {
      do {
        puVar22 = (undefined4 *)(show_last_freq + 0xffc);
        piVar21 = (int *)(iVar9 + 4);
        puVar15 = (uint *)(show_last_freq + 0xffc);
        pbVar19 = local_868;
        do {
          while (piVar21 = piVar21 + 1, *piVar21 == 1) {
            puVar10 = puVar15;
            pbVar13 = pbVar19;
            do {
              pbVar13 = pbVar13 + 1;
              puVar10 = puVar10 + 1;
              *puVar10 = (uint)*pbVar13;
            } while (pbVar19 + 0x54 != pbVar13);
            pbVar19 = pbVar19 + 0x80;
            puVar15 = puVar15 + 0x100;
            if (pbVar19 == nonce_mutex + 1) goto LAB_00030d6e;
          }
          pbVar19 = pbVar19 + 0x80;
          puVar15 = puVar15 + 0x100;
        } while (pbVar19 != nonce_mutex + 1);
LAB_00030d6e:
        if (5 < log_level) {
          pFVar6 = fopen(log_file,"a+");
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: DownOneChipFreqOneStep enter\n","driver-btm-c5.c",0xfd9,
                    "DownOneChipFreqOneStep");
          }
          fclose(pFVar6);
          iVar9 = dev;
        }
        iVar25 = 0;
        iVar4 = -1;
        iVar27 = 0;
        while( true ) {
          if (*(int *)(iVar9 + (iVar27 + 2) * 4) == 1) {
            if (*(char *)(iVar9 + iVar27 + 0x53ec) != 'T') goto LAB_00030e36;
            if ((iVar25 == 0) || (iVar9 = GetBoardRate(iVar27), iVar25 < iVar9)) {
              iVar25 = GetBoardRate(iVar27);
              iVar4 = iVar27;
            }
          }
          iVar9 = dev;
          cVar1 = opt_economic_mode;
          dev = iVar9;
          if (iVar27 == 0xf) break;
          iVar27 = iVar27 + 1;
        }
        if (iVar4 == -1) {
          if (3 < log_level) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep has Wrong chain index=%d\n",
                      "driver-btm-c5.c",0xfef,"DownOneChipFreqOneStep",0xffffffff);
            }
LAB_00030fbe:
            fclose(pFVar6);
            iVar9 = dev;
          }
          break;
        }
        uVar26 = (uint)*(byte *)(iVar9 + iVar4 + 0x53ec);
        if (uVar26 == 0) {
LAB_00030ef0:
          if (3 < log_level) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n"
                      ,"driver-btm-c5.c",0x1022,"DownOneChipFreqOneStep",0xffffffff);
            }
            fclose(pFVar6);
            iVar9 = dev;
          }
          break;
        }
        bVar3 = 0;
        uVar20 = 0;
        uVar24 = 0xffffffff;
        piVar21 = (int *)(iic_mutex + iVar4 * 0x400 + 0x14);
        pbVar19 = chain_pic_buf + iVar4 * 0x80 + 2;
        do {
          piVar21 = piVar21 + 1;
          if (*piVar21 < 0xf) {
            if (bVar3 == 0) {
              bVar2 = *pbVar19;
            }
            else {
              bVar2 = *pbVar19;
              if (*pbVar19 <= bVar3) goto LAB_00030e1a;
            }
            bVar3 = bVar2;
            uVar24 = uVar20;
          }
LAB_00030e1a:
          uVar20 = uVar20 + 1;
          pbVar19 = pbVar19 + 1;
        } while (uVar20 != uVar26);
        if (uVar24 == 0xffffffff) goto LAB_00030ef0;
        if (bVar3 < 5) {
          if (3 < log_level) {
            pFVar6 = fopen(log_file,"a+");
            if (pFVar6 != (FILE *)0x0) {
              fprintf(pFVar6,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n"
                      ,"driver-btm-c5.c",0x1029,"DownOneChipFreqOneStep",iVar4);
            }
            goto LAB_00030fbe;
          }
          break;
        }
        iVar4 = uVar24 + iVar4 * 0x80 + 0x707d9a;
        *(char *)(iVar4 + 0xd3c) = *(char *)(iVar4 + 0xd3c) + -1;
        iVar4 = ideal_total_hash_rate;
        if (cVar1 != '\0') {
          iVar4 = GetTotalRate_part_12();
          iVar9 = dev;
        }
      } while (iVar17 < iVar4);
LAB_00030e36:
      piVar21 = (int *)(iVar9 + 4);
      piVar16 = piVar21;
      do {
        piVar16 = piVar16 + 1;
        if (*piVar16 == 1) {
          pbVar19 = local_868;
          puVar14 = puVar22;
          do {
            puVar14 = puVar14 + 1;
            pbVar19 = pbVar19 + 1;
            *pbVar19 = (byte)*puVar14;
          } while (puVar22 + 0x54 != puVar14);
        }
        puVar22 = puVar22 + 0x100;
        local_868 = local_868 + 0x80;
      } while (puVar22 != (undefined4 *)(last_record_freq + 0x3ffc));
      goto LAB_00030916;
    }
  }
  piVar21 = (int *)(dev + 4);
LAB_00030916:
  puVar12 = show_last_freq;
  do {
    while (piVar21 = piVar21 + 1, *piVar21 != 1) {
      puVar12 = puVar12 + 0x100;
      local_864 = local_864 + 0x80;
      if (puVar12 == last_record_freq) {
        return;
      }
    }
    pvVar7 = memcpy(puVar12,local_864,0x80);
    puVar12 = (undefined1 *)((int)pvVar7 + 0x100);
    local_864 = local_864 + 0x80;
  } while (puVar12 != last_record_freq);
  return;
}

