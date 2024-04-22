
/* WARNING: Heritage AFTER dead removal. Example location: s1 : 0x00035030 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined set_iic_power_voltage(int *param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  FILE *pFVar3;
  uint uVar4;
  undefined8 in_d0;
  double dVar5;
  undefined4 uStack_3c;
  undefined local_21;
  double local_20;
  int local_14;
  
  local_14 = 0;
  local_21 = 0;
  *(undefined *)(param_1 + 1) = 0;
  do {
    sleep(1);
    iVar1 = is7007_Board();
    if (iVar1 == 0) {
      local_20 = (double)get_avg_voltage();
      dVar5 = local_20;
    }
    else {
      dVar5 = (double)get_min_voltage();
      local_20 = dVar5;
      if (param_2 != '\0') {
        local_20 = (dVar5 * DAT_000351e0) / DAT_000351e8;
      }
    }
    uVar2 = voltage_tunning(SUB84(local_20,0),(int)((ulonglong)dVar5 >> 0x20),(int)in_d0,local_21,
                            param_1);
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        uStack_3c = (undefined4)((ulonglong)in_d0 >> 0x20);
        fprintf(pFVar3,"%s:%d: voltage_tunning, set to %f, N=%d\n","power.c",0x272,(int)in_d0,
                uStack_3c,uVar2);
      }
      fclose(pFVar3);
    }
    iVar1 = local_14 + 1;
    if (local_14 < 0x33) {
      local_14 = local_14 + 2;
      if (0x14 < iVar1) {
        if (5 < log_level) {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d: tuning up 20 times\n","power.c",0x27b);
          }
          fclose(pFVar3);
        }
        local_21 = 1;
      }
    }
    else {
      if (3 < log_level) {
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d: power voltage abnormal\n","power.c",0x276);
        }
        fclose(pFVar3);
      }
      stop_mining("power abnormal");
      local_14 = iVar1;
    }
    if (*param_1 == 1) {
      uVar4 = 0x7f;
    }
    else {
      uVar4 = 0xff;
    }
    if (uVar4 <= uVar2) break;
    if (uVar2 == 0) break;
    if (5 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: tunning %d times\n","power.c",0x284,local_14);
      }
      fclose(pFVar3);
    }
  } while (*(char *)(param_1 + 1) != '\x01');
  return *(undefined *)(param_1 + 1);
}

