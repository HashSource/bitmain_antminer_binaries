
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void processTEST(void)

{
  int iVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  char acStack_48 [36];
  
  iVar1 = readTestID();
  if (iVar1 == 0xb) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d do 8xPatten test\n","driver-btm-c5.c",0x1e42,
                DAT_0003d004,0xb);
      }
      fclose(pFVar2);
    }
    do8xPattenTest();
    return;
  }
  if (iVar1 == 0xc) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d do bitmain_core_reInit test\n","driver-btm-c5.c",
                0x1e4b,DAT_0003d290,0xc);
      }
      fclose(pFVar2);
    }
    bitmain_core_reInit();
    reCalculateAVG();
    if (log_level < 4) {
      return;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Done bitmain_core_reInit test\n","driver-btm-c5.c",0x1e50,
              DAT_0003ccb8);
    }
  }
  else if (iVar1 == 0xd) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d do doReInitTest test\n","driver-btm-c5.c",0x1e57,
                DAT_0003d290,0xd);
      }
      fclose(pFVar2);
    }
    doReInitTest();
    reCalculateAVG();
    if (log_level < 4) {
      return;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Done doReInitTest test\n","driver-btm-c5.c",0x1e5c,DAT_0003d004);
    }
  }
  else if (iVar1 == 0xe) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d do do get asicnum\n","driver-btm-c5.c",0x1e63,
                DAT_0003d290,0xe);
      }
      fclose(pFVar2);
    }
    test_show_register = 1;
    reset_crc_count(1);
    iVar1 = 1;
    do {
      iVar4 = iVar1 + 1;
      iVar5 = iVar1 + -1;
      if (*(int *)(dev + iVar4 * 4) == 1) {
        *(undefined *)(dev + iVar5 + 0x53ec) = 0;
        check_asic_reg_oneChain_test(iVar5);
        if (3 < log_level) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x1e6f,
                    DAT_0003d004,iVar1,(uint)*(byte *)(dev + iVar5 + 0x53ec));
          }
          fclose(pFVar2);
        }
      }
      iVar1 = iVar4;
    } while (iVar4 != 0x11);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        uVar3 = get_crc_count();
        fprintf(pFVar2,"%s:%d:%s: test asicnum CRC error counter=%d\n","driver-btm-c5.c",0x1e73,
                DAT_0003d290,uVar3);
      }
      fclose(pFVar2);
    }
    reset_crc_count(0);
    test_show_register = 0;
    if (log_level < 4) {
      test_show_register = 0;
      return;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Done do get asicnum\n","driver-btm-c5.c",0x1e78,DAT_0003d004);
    }
  }
  else if (iVar1 == 0xf) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d do reCalculateAVG test\n","driver-btm-c5.c",0x1e7f,
                DAT_0003d290,0xf);
      }
      fclose(pFVar2);
    }
    reCalculateAVG();
    if (log_level < 4) {
      return;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Done reCalculateAVG test\n","driver-btm-c5.c",0x1e83,DAT_0003ccb8);
    }
  }
  else {
    if (iVar1 == 0x10) {
      saveTestID(0);
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d DUMP MODE : to show TM and HCN.\n",
                  "driver-btm-c5.c",0x1e89,DAT_0003d004,0x10);
        }
        fclose(pFVar2);
      }
      check_asic_reg(0x18);
      check_asic_reg(0x14);
      check_asic_reg(0x10);
      return;
    }
    if (iVar1 == 0x11) {
      saveTestID(0);
      pFVar2 = fopen("/etc/config/log_level","rb");
      if (pFVar2 == (FILE *)0x0) {
        return;
      }
      memset(acStack_48,0,0x20);
      fread(acStack_48,1,0x20,pFVar2);
      fclose(pFVar2);
      log_level = strtol(acStack_48,(char **)0x0,10);
      if (log_level < 2) {
        return;
      }
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: log level set to %d\n","driver-btm-c5.c",0x1e9d,DAT_0003d004,
                log_level);
      }
    }
    else if (iVar1 == 0x12) {
      saveTestID(0);
      pFVar2 = fopen("/etc/config/ideal_hash","rb");
      if (pFVar2 == (FILE *)0x0) {
        return;
      }
      memset(acStack_48,0,0x20);
      fread(acStack_48,1,0x20,pFVar2);
      fclose(pFVar2);
      ideal_total_hash_rate = strtol(acStack_48,(char **)0x0,10);
      if (log_level < 2) {
        return;
      }
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: ideal_hash set to %d\n","driver-btm-c5.c",0x1eae,DAT_0003d290,
                ideal_total_hash_rate);
      }
    }
    else {
      if (iVar1 == 0x13) {
        get_avg_voltage();
        return;
      }
      if (iVar1 == 0x14) {
        return;
      }
      if (iVar1 - 0x65U < 0x10) {
        saveTestID(0);
        iVar4 = iVar1 % 100;
        if (log_level < 4) {
          if (*(int *)(dev + (iVar4 + 1) * 4) != 1) {
            return;
          }
        }
        else {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d up voltage 0.1V on Chain[J%d]\n",
                    "driver-btm-c5.c",0x1ecb,DAT_0003d004,iVar1,iVar4);
          }
          fclose(pFVar2);
          if (*(int *)(dev + (iVar4 + 1) * 4) != 1) {
            if (log_level < 4) {
              return;
            }
            pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: There is hashboard on Chain[J%d]\n","driver-btm-c5.c",0x1edf
                      ,DAT_0003d004,iVar4);
            }
            goto LAB_0003ca9c;
          }
        }
        iVar1 = write_EEPROM_iic(1,1,0x90,iVar4 - 1U & 0xff,0);
        if (log_level < 4) {
          return;
        }
        iVar1 = ((int)(longlong)
                      (((DAT_0003cca0 / ((double)(longlong)iVar1 + DAT_0003cc98) + DAT_0003cca8) *
                       DAT_0003ccb0) / 4.75) / 10) * 10;
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        iVar5 = iVar1 + 10;
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Try to up 0.1V on chain[J%d] from vol=%d to %d...\n",
                  "driver-btm-c5.c",0x1ed6,DAT_0003ccb8,iVar4,iVar1,iVar5);
        }
        fclose(pFVar2);
        dVar6 = DAT_0003cca0 / (((double)(longlong)iVar5 * 4.75) / DAT_0003ccb0 - DAT_0003cca8) -
                DAT_0003cc98;
        if (log_level < 4) {
          return;
        }
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: now set pic voltage=%d on chain[J%d]\n","driver-btm-c5.c",0x1ed9
                  ,DAT_0003ccb8,(uint)(0.0 < dVar6) * (int)(longlong)dVar6 & 0xff,iVar4);
        }
      }
      else {
        if (0xf < iVar1 - 0xc9U) {
          return;
        }
        saveTestID(0);
        iVar4 = iVar1 % 100;
        if (log_level < 4) {
          if (*(int *)(dev + (iVar4 + 1) * 4) != 1) {
            return;
          }
        }
        else {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: get TEST ID=%d down voltage 0.1V on Chain[J%d]\n",
                    "driver-btm-c5.c",0x1eea,DAT_0003d290,iVar1,iVar4);
          }
          fclose(pFVar2);
          if (*(int *)(dev + (iVar4 + 1) * 4) != 1) {
            if (log_level < 4) {
              return;
            }
            pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: There is no hashboard on Chain[J%d]\n","driver-btm-c5.c",
                      0x1efe,DAT_0003d290,iVar4);
            }
            goto LAB_0003ca9c;
          }
        }
        iVar1 = write_EEPROM_iic(1,1,0x90,iVar4 - 1U & 0xff,0);
        if (log_level < 4) {
          return;
        }
        iVar1 = ((int)(longlong)
                      (((DAT_0003cca0 / ((double)(longlong)iVar1 + DAT_0003cc98) + DAT_0003cca8) *
                       DAT_0003ccb0) / 4.75) / 10) * 10;
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        iVar5 = iVar1 + -10;
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Try to down 0.1V on chain[J%d] from vol=%d to %d...\n",
                  "driver-btm-c5.c",0x1ef5,DAT_0003ccb8,iVar4,iVar1,iVar5);
        }
        fclose(pFVar2);
        dVar6 = DAT_0003cca0 / (((double)(longlong)iVar5 * 4.75) / DAT_0003ccb0 - DAT_0003cca8) -
                DAT_0003cc98;
        if (log_level < 4) {
          return;
        }
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: now set pic voltage=%d on chain[J%d]\n","driver-btm-c5.c",0x1ef8
                  ,DAT_0003ccb8,(uint)(0.0 < dVar6) * (int)(longlong)dVar6 & 0xff,iVar4);
        }
      }
    }
  }
LAB_0003ca9c:
  fclose(pFVar2);
  return;
}

