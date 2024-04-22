
void set_frequency(undefined4 param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  FILE *pFVar10;
  void *pvVar11;
  long lVar12;
  int iVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  byte *pbVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  void *pvVar21;
  byte *pbVar22;
  uint uVar23;
  int *piVar24;
  void *__src;
  uint *puVar25;
  byte *pbVar26;
  undefined4 *puVar27;
  uint uVar28;
  void *pvVar29;
  uint uVar30;
  uint *puVar31;
  int iVar32;
  uint uVar33;
  int iVar34;
  byte *pbVar35;
  uint local_898;
  byte *local_88c;
  int local_888;
  uint *local_880;
  int local_87c;
  byte *local_878;
  undefined2 local_85a;
  undefined4 local_858;
  undefined4 local_854;
  char acStack_850 [2052];
  
  local_858 = 0;
  local_85a = 0;
  local_854 = 0;
  bVar7 = get_pll_index();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_850,0x800,"\n--- %s\n",DAT_00030a7c);
    _applog(7,acStack_850,0);
  }
  get_plldata_constprop_17(param_1,&local_858,&local_85a,&local_854);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_850,0x800,"%s: frequency = %d\n",DAT_00030a7c,param_1);
    _applog(7,acStack_850,0);
  }
  pbVar26 = DAT_00030508;
  iVar8 = 1;
  pbVar22 = DAT_00030508;
  puVar27 = DAT_0003050c;
  do {
    while ((iVar19 = iVar8 + 1, *(int *)(dev + iVar19 * 4) == 1 &&
           (*(char *)(dev + iVar8 + 0x53eb) != '\0'))) {
      if ((opt_fixed_freq == '\0') && (pbVar22[-1] == 0x7d)) {
LAB_0003054e:
        if (3 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: Chain[J%d] has no core num in PIC\n","driver-btm-c5.c",0x11c1
                    ,DAT_000307d0,iVar8);
          }
          fclose(pFVar10);
        }
      }
      else {
        pbVar22[-1] = 0x7d;
        isUseDefaultFreq = '\x01';
        pbVar35 = pbVar22;
        do {
          pbVar35 = pbVar35 + 1;
          *pbVar35 = bVar7;
        } while (pbVar35 != pbVar22 + 0x54);
        if (3 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: Chain[J%d] has no freq in PIC, set default freq=%dM\n",
                    "driver-btm-c5.c",0x1184,DAT_000307d0,iVar8,param_1);
          }
          fclose(pFVar10);
          goto LAB_0003054e;
        }
      }
      puVar15 = puVar27;
      do {
        puVar15 = puVar15 + 1;
        *puVar15 = 0;
      } while (puVar15 != puVar27 + 0x54);
      puVar27 = puVar27 + 0x100;
      pbVar22 = pbVar22 + 0x80;
      iVar8 = iVar19;
      if (iVar19 == 0x11) goto LAB_00030312;
    }
    puVar27 = puVar27 + 0x100;
    pbVar22 = pbVar22 + 0x80;
    iVar8 = iVar19;
  } while (iVar19 != 0x11);
LAB_00030312:
  if ((opt_economic_mode == '\0') || (iVar8 = GetTotalRate_part_12(), opt_economic_mode == '\0')) {
    iVar8 = get_total_rate_from_eeprom();
  }
  if (iVar8 % 1000 < 500) {
    iVar19 = 0;
  }
  else {
    iVar19 = 500;
  }
  ideal_total_hash_rate = (iVar8 / 1000) * 1000 + iVar19;
  if (log_level < 4) {
    if (opt_fixed_freq == '\0') {
LAB_0003036a:
      dVar4 = DAT_00030500;
      dVar3 = DAT_000304f8;
      dVar2 = DAT_000304f0;
      dVar1 = DAT_000304e8;
      uVar33 = 0;
      local_880 = (uint *)DAT_00030510;
      local_88c = DAT_00030514;
      local_888 = 1;
      do {
        if ((*(int *)(dev + (uVar33 + 2) * 4) == 1) && (*(char *)(dev + uVar33 + 0x53ec) != '\0')) {
          iVar8 = write_EEPROM_iic(1,1,0x90,uVar33 & 0xff,0);
          if (3 < log_level) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,"%s:%d:%s: read PIC voltage=%d on chain[%d]\n","driver-btm-c5.c",
                      0x1209,DAT_000311e4,
                      ((int)(longlong)
                            (((dVar2 / ((double)(longlong)iVar8 + dVar1) + dVar3) * dVar4) / 4.75) /
                      10) * 10,uVar33);
            }
            fclose(pFVar10);
            if (3 < log_level) {
              pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar10 != (FILE *)0x0) {
                fprintf(pFVar10,"%s:%d:%s: Chain:%d chipnum=%d\n","driver-btm-c5.c",0x120b,
                        DAT_000311e4,uVar33,(uint)*(byte *)(dev + uVar33 + 0x53ec));
              }
              fclose(pFVar10);
              if (3 < log_level) {
                pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar10 != (FILE *)0x0) {
                  fprintf(pFVar10,"%s:%d:%s: S9+ can not record Chain[J%d] voltage added value\n",
                          "driver-btm-c5.c",0x121d,DAT_000311e4,local_888);
                }
                fclose(pFVar10);
              }
            }
          }
          uVar30 = log_level;
          if (isUseDefaultFreq == '\0') {
            *local_88c = 0xc;
          }
          else {
            *local_88c = bVar7;
          }
          if (3 < uVar30) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,"%s:%d:%s: Chain:%d base freq=%s\n","driver-btm-c5.c",0x1299,
                      DAT_00030a7c,uVar33,*(undefined4 *)(freq_pll_1385 + (uint)*local_88c * 0x10));
            }
            fclose(pFVar10);
            uVar30 = log_level;
          }
          uVar23 = 100;
          uVar28 = 0;
          uVar9 = (uint)*(byte *)(dev + uVar33 + 0x53ec);
          pbVar22 = (byte *)local_880;
          for (uVar20 = 1; (int)(uVar20 - 1) < (int)uVar9; uVar20 = uVar20 + 1) {
            uVar16 = (uint)*pbVar22;
            if (uVar16 < 4) {
              uVar16 = 4;
              *pbVar22 = 4;
            }
            else if (0x6a < uVar16) {
              uVar16 = 0x6a;
              *pbVar22 = 0x6a;
            }
            if (uVar28 < uVar16) {
              uVar28 = uVar16;
            }
            if (uVar16 <= uVar23) {
              uVar23 = uVar16;
            }
            if (3 < uVar30) {
              pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar10 != (FILE *)0x0) {
                fprintf(pFVar10,"Asic[%2d]:%s ",uVar20 - 1,
                        *(undefined4 *)(freq_pll_1385 + (uint)*pbVar22 * 0x10));
              }
              fclose(pFVar10);
              if ((uVar20 & 7) == 0) {
                if (log_level < 4) {
                  uVar9 = (uint)*(byte *)(dev + uVar33 + 0x53ec);
                  uVar30 = log_level;
                  goto LAB_0003043a;
                }
                pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar10 != (FILE *)0x0) {
                  fputc(10,pFVar10);
                }
                fclose(pFVar10);
              }
              uVar9 = (uint)*(byte *)(dev + uVar33 + 0x53ec);
              uVar30 = log_level;
            }
LAB_0003043a:
            pbVar22 = pbVar22 + 1;
          }
          if (3 < uVar30) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fputc(10,pFVar10);
            }
            fclose(pFVar10);
            if (3 < log_level) {
              pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar10 != (FILE *)0x0) {
                fprintf(pFVar10,"%s:%d:%s: Chain:%d max freq=%s\n","driver-btm-c5.c",0x12de,
                        DAT_00030d88,uVar33,*(undefined4 *)(freq_pll_1385 + uVar28 * 0x10));
              }
              fclose(pFVar10);
              if (3 < log_level) {
                pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar10 != (FILE *)0x0) {
                  fprintf(pFVar10,"%s:%d:%s: Chain:%d min freq=%s\n","driver-btm-c5.c",0x12df,
                          DAT_00030d88,uVar33,*(undefined4 *)(freq_pll_1385 + uVar23 * 0x10));
                }
                fclose(pFVar10);
                if (3 < log_level) {
                  pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
                  if (pFVar10 != (FILE *)0x0) {
                    fputc(10,pFVar10);
                  }
                  fclose(pFVar10);
                }
              }
            }
          }
        }
        uVar33 = uVar33 + 1;
        local_888 = local_888 + 1;
        local_880 = (uint *)((int)local_880 + 0x80);
        local_88c = local_88c + 1;
      } while (uVar33 != 0x10);
      goto LAB_0003058e;
    }
  }
  else {
    pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar10 != (FILE *)0x0) {
      fprintf(pFVar10,"%s:%d:%s: miner total rate=%dGH/s ideal_total_hash_rate = %dGH/s\n",
              "driver-btm-c5.c",0x11f0,DAT_00030d88,iVar8,ideal_total_hash_rate);
    }
    fclose(pFVar10);
    if (opt_fixed_freq == '\0') goto LAB_0003036a;
LAB_0003058e:
    if (3 < log_level) {
      pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar10 != (FILE *)0x0) {
        fputc(10,pFVar10);
      }
      fclose(pFVar10);
      if (3 < log_level) {
        pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar10 != (FILE *)0x0) {
          fprintf(pFVar10,"%s:%d:%s: Miner fix freq ...\n","driver-btm-c5.c",0x12e8,DAT_00030a7c);
        }
        fclose(pFVar10);
      }
    }
  }
  iVar8 = dev;
  __src = DAT_000307d4;
  piVar24 = (int *)(dev + 4);
  pvVar29 = (void *)((int)DAT_000307d8 + 0x1000);
  pvVar11 = DAT_000307d8;
  pvVar21 = DAT_000307d4;
  do {
    while (piVar24 = piVar24 + 1, *piVar24 == 1) {
      pvVar11 = memcpy(pvVar11,pvVar21,0x80);
      pvVar11 = (void *)((int)pvVar11 + 0x100);
      pvVar21 = (void *)((int)pvVar21 + 0x80);
      if (pvVar11 == pvVar29) goto LAB_000305d4;
    }
    pvVar11 = (void *)((int)pvVar11 + 0x100);
    pvVar21 = (void *)((int)pvVar21 + 0x80);
  } while (pvVar11 != pvVar29);
LAB_000305d4:
  dVar4 = DAT_000307c8;
  dVar3 = DAT_000307c0;
  dVar2 = DAT_000307b8;
  dVar1 = DAT_000307b0;
  local_878 = DAT_000307dc;
  local_880 = DAT_000307e0;
  local_898 = 0;
  uVar33 = 0;
  local_87c = 1;
  do {
    if ((*(int *)(iVar8 + (local_898 + 2) * 4) == 1) &&
       (*(char *)(iVar8 + local_898 + 0x53ec) != '\0')) {
      iVar8 = write_EEPROM_iic(1,1,0x90,local_898 & 0xff,0);
      if (3 < log_level) {
        pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar10 != (FILE *)0x0) {
          fprintf(pFVar10,"%s:%d:%s: read PIC voltage=%d on chain[%d]\n","driver-btm-c5.c",0x130b,
                  DAT_00030d88,
                  ((int)(longlong)
                        (((dVar2 / ((double)(longlong)iVar8 + dVar1) + dVar3) * dVar4) / 4.75) / 10)
                  * 10,local_898);
        }
        fclose(pFVar10);
        if (3 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: Chain:%d chipnum=%d\n","driver-btm-c5.c",0x130c,DAT_00030d88,
                    local_898,(uint)*(byte *)(dev + local_898 + 0x53ec));
          }
          fclose(pFVar10);
        }
      }
      if (opt_fixed_freq == '\0') {
        if (3 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: S9+ can not record Chain[J%d] voltage added value\n",
                    "driver-btm-c5.c",0x131d,DAT_000311e4,local_87c);
          }
          fclose(pFVar10);
          if (opt_fixed_freq != '\0') goto LAB_000306d8;
        }
        uVar30 = log_level;
        iVar8 = DAT_000307e4;
        if (isUseDefaultFreq == '\0') {
          *(undefined *)(DAT_000307e4 + local_898) = 0xc;
        }
        else {
          *(byte *)(DAT_000307e4 + local_898) = bVar7;
        }
        if (3 < uVar30) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: Chain:%d base freq=%s\n","driver-btm-c5.c",0x13b1,
                    DAT_000307d0,local_898,
                    *(undefined4 *)(freq_pll_1385 + (uint)*(byte *)(iVar8 + local_898) * 0x10));
          }
          fclose(pFVar10);
        }
      }
LAB_000306d8:
      uVar30 = 100;
      uVar23 = 0;
      pbVar22 = local_878;
      puVar31 = local_880;
      for (uVar28 = 1; iVar8 = dev, iVar19 = uVar28 - 1,
          iVar19 < (int)(uint)*(byte *)(dev + local_898 + 0x53ec); uVar28 = uVar28 + 1) {
        uVar9 = (uint)*pbVar22;
        if (uVar9 < 4) {
          uVar9 = 4;
          *pbVar22 = 4;
        }
        else if (0x6a < uVar9) {
          uVar9 = 0x6a;
          *pbVar22 = 0x6a;
        }
        if (uVar33 < uVar9) {
          uVar33 = uVar9;
        }
        if (uVar23 < uVar9) {
          uVar23 = uVar9;
        }
        if (uVar9 <= uVar30) {
          uVar30 = uVar9;
        }
        set_frequency_with_addr_plldatai
                  (uVar9,0,(int)(short)iVar19 * (int)(short)(ushort)*(byte *)(iVar8 + 0x542d) & 0xff
                   ,local_898 & 0xff);
        uVar9 = log_level;
        puVar31 = puVar31 + 1;
        *puVar31 = (uint)*pbVar22;
        if (3 < uVar9) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"Asic[%2d]:%s ",iVar19,
                    *(undefined4 *)(freq_pll_1385 + (uint)*pbVar22 * 0x10));
          }
          fclose(pFVar10);
          if (((uVar28 & 7) == 0) && (3 < log_level)) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fputc(10,pFVar10);
            }
            fclose(pFVar10);
          }
        }
        pbVar22 = pbVar22 + 1;
      }
      if (3 < log_level) {
        pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar10 != (FILE *)0x0) {
          fputc(10,pFVar10);
        }
        fclose(pFVar10);
        if (3 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: Chain:%d max freq=%s\n","driver-btm-c5.c",0x140b,DAT_00030a7c
                    ,local_898,*(undefined4 *)(freq_pll_1385 + uVar23 * 0x10));
          }
          fclose(pFVar10);
          if (3 < log_level) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,"%s:%d:%s: Chain:%d min freq=%s\n","driver-btm-c5.c",0x140c,
                      DAT_00030a7c,local_898,*(undefined4 *)(freq_pll_1385 + uVar30 * 0x10));
            }
            fclose(pFVar10);
            if (3 < log_level) {
              pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar10 != (FILE *)0x0) {
                fputc(10,pFVar10);
              }
              fclose(pFVar10);
            }
          }
        }
      }
    }
    local_87c = local_87c + 1;
    local_898 = local_898 + 1;
    local_878 = local_878 + 0x80;
    local_880 = local_880 + 0x100;
    iVar8 = dev;
  } while (local_898 != 0x10);
  lVar12 = strtol(*(char **)(freq_pll_1385 + uVar33 * 0x10),(char **)0x0,10);
  uVar33 = log_level;
  *(short *)(dev + 0x5443) = (short)lVar12;
  if (3 < uVar33) {
    pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar10 != (FILE *)0x0) {
      fprintf(pFVar10,"%s:%d:%s: max freq = %d\n","driver-btm-c5.c",0x1414,DAT_00031014,
              (uint)*(ushort *)(dev + 0x5443));
    }
    fclose(pFVar10);
  }
  iVar8 = ideal_total_hash_rate;
  if (isUseDefaultFreq == '\0') {
    if (ideal_total_hash_rate % 1000 < 500) {
      iVar19 = 0;
    }
    else {
      iVar19 = 500;
    }
    iVar19 = (ideal_total_hash_rate / 1000) * 1000 + iVar19;
    if (3 < log_level) {
      pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar10 != (FILE *)0x0) {
        fprintf(pFVar10,"%s:%d:%s: totalRate = %d, fixed_totalRate = %d\n","driver-btm-c5.c",0x1057,
                DAT_000311e8,iVar8,iVar19);
      }
      fclose(pFVar10);
      iVar8 = ideal_total_hash_rate;
    }
    ideal_total_hash_rate = iVar8;
    if (opt_economic_mode != '\0') {
      iVar8 = GetTotalRate_part_12();
    }
    iVar13 = dev;
    if (iVar19 < iVar8) {
      do {
        puVar31 = DAT_00030d90;
        piVar24 = (int *)(iVar13 + 4);
        pbVar35 = (byte *)(DAT_00030d8c + 0x801);
        pbVar22 = pbVar26;
        puVar25 = DAT_00030d90;
        do {
          while (piVar24 = piVar24 + 1, *piVar24 == 1) {
            puVar14 = puVar25;
            pbVar17 = pbVar22;
            do {
              pbVar17 = pbVar17 + 1;
              puVar14 = puVar14 + 1;
              *puVar14 = (uint)*pbVar17;
            } while (pbVar22 + 0x54 != pbVar17);
            pbVar22 = pbVar22 + 0x80;
            puVar25 = puVar25 + 0x100;
            if (pbVar22 == pbVar35) goto LAB_00030d6e;
          }
          pbVar22 = pbVar22 + 0x80;
          puVar25 = puVar25 + 0x100;
        } while (pbVar22 != pbVar35);
LAB_00030d6e:
        if (5 < log_level) {
          pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar10 != (FILE *)0x0) {
            fprintf(pFVar10,"%s:%d:%s: DownOneChipFreqOneStep enter\n","driver-btm-c5.c",0xfd9,
                    DAT_00031010);
          }
          fclose(pFVar10);
          iVar13 = dev;
        }
        iVar32 = 0;
        iVar8 = -1;
        iVar34 = 0;
        while( true ) {
          if (*(int *)(iVar13 + (iVar34 + 2) * 4) == 1) {
            if (*(char *)(iVar13 + iVar34 + 0x53ec) != 'T') goto LAB_00030e36;
            if ((iVar32 == 0) || (iVar13 = GetBoardRate(iVar34), iVar32 < iVar13)) {
              iVar32 = GetBoardRate(iVar34);
              iVar8 = iVar34;
            }
          }
          iVar13 = dev;
          cVar5 = opt_economic_mode;
          dev = iVar13;
          if (iVar34 == 0xf) break;
          iVar34 = iVar34 + 1;
        }
        if (iVar8 == -1) {
          if (3 < log_level) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep has Wrong chain index=%d\n",
                      "driver-btm-c5.c",0xfef,DAT_00031010,0xffffffff);
            }
LAB_00030fbe:
            fclose(pFVar10);
            iVar13 = dev;
          }
          break;
        }
        uVar33 = (uint)*(byte *)(iVar13 + iVar8 + 0x53ec);
        if (uVar33 == 0) {
LAB_00030ef0:
          if (3 < log_level) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n"
                      ,"driver-btm-c5.c",0x1022,DAT_00031010,0xffffffff);
            }
            fclose(pFVar10);
            iVar13 = dev;
          }
          break;
        }
        bVar7 = 0;
        uVar23 = 0;
        uVar30 = 0xffffffff;
        piVar24 = (int *)(DAT_00031004 + iVar8 * 0x400);
        pbVar22 = (byte *)(iVar8 * 0x80 + 2 + DAT_00031008);
        do {
          piVar24 = piVar24 + 1;
          if (*piVar24 < 0xf) {
            if (bVar7 == 0) {
              bVar6 = *pbVar22;
            }
            else {
              bVar6 = *pbVar22;
              if (*pbVar22 <= bVar7) goto LAB_00030e1a;
            }
            bVar7 = bVar6;
            uVar30 = uVar23;
          }
LAB_00030e1a:
          uVar23 = uVar23 + 1;
          pbVar22 = pbVar22 + 1;
        } while (uVar23 != uVar33);
        if (uVar30 == 0xffffffff) goto LAB_00030ef0;
        if (bVar7 < 5) {
          if (3 < log_level) {
            pFVar10 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar10 != (FILE *)0x0) {
              fprintf(pFVar10,
                      "%s:%d:%s: Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n"
                      ,"driver-btm-c5.c",0x1029,DAT_00031010,iVar8);
            }
            goto LAB_00030fbe;
          }
          break;
        }
        iVar8 = uVar30 + iVar8 * 0x80 + 0x707d9a;
        *(char *)(iVar8 + 0xd3c) = *(char *)(iVar8 + 0xd3c) + -1;
        iVar8 = ideal_total_hash_rate;
        if (cVar5 != '\0') {
          iVar8 = GetTotalRate_part_12();
          iVar13 = dev;
        }
      } while (iVar19 < iVar8);
LAB_00030e36:
      puVar25 = DAT_0003100c;
      piVar24 = (int *)(iVar13 + 4);
      piVar18 = piVar24;
      do {
        piVar18 = piVar18 + 1;
        if (*piVar18 == 1) {
          pbVar22 = pbVar26;
          puVar14 = puVar31;
          do {
            puVar14 = puVar14 + 1;
            pbVar22 = pbVar22 + 1;
            *pbVar22 = (byte)*puVar14;
          } while (puVar31 + 0x54 != puVar14);
        }
        puVar31 = puVar31 + 0x100;
        pbVar26 = pbVar26 + 0x80;
      } while (puVar25 != puVar31);
      goto LAB_00030916;
    }
  }
  piVar24 = (int *)(dev + 4);
LAB_00030916:
  pvVar21 = (void *)((int)DAT_00030a80 + 0x1000);
  pvVar11 = DAT_00030a80;
  do {
    while (piVar24 = piVar24 + 1, *piVar24 != 1) {
      pvVar11 = (void *)((int)pvVar11 + 0x100);
      __src = (void *)((int)__src + 0x80);
      if (pvVar21 == pvVar11) {
        return;
      }
    }
    pvVar11 = memcpy(pvVar11,__src,0x80);
    pvVar11 = (void *)((int)pvVar11 + 0x100);
    __src = (void *)((int)__src + 0x80);
  } while (pvVar21 != pvVar11);
  return;
}

