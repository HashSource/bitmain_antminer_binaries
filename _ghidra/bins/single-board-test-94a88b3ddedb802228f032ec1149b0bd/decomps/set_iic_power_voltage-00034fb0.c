
/* WARNING: Heritage AFTER dead removal. Example location: s1 : 0x00035030 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined1 set_iic_power_voltage(int *param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  FILE *pFVar3;
  uint uVar4;
  double in_d0;
  double dVar5;
  undefined4 uStack_3c;
  undefined1 local_21;
  double local_20;
  int local_14;
  undefined4 uVar6;
  
  local_14 = 0;
  local_21 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  dVar5 = in_d0;
  do {
    sleep(1);
    iVar1 = is7007_Board();
    local_20 = dVar5;
    if (iVar1 == 0) {
      get_avg_voltage();
    }
    else {
      get_min_voltage();
      if (param_2 != '\0') {
        local_20 = (dVar5 * 324.0) / 330.0;
      }
    }
    uVar6 = (undefined4)((ulonglong)dVar5 >> 0x20);
    dVar5 = (double)CONCAT44(uVar6,SUB84(local_20,0));
    uVar2 = voltage_tunning(SUB84(local_20,0),uVar6,SUB84(in_d0,0),local_21,param_1);
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        uStack_3c = (undefined4)((ulonglong)in_d0 >> 0x20);
        fprintf(pFVar3,"%s:%d: voltage_tunning, set to %f, N=%d\n","power.c",0x272,SUB84(in_d0,0),
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
  } while ((char)param_1[1] != '\x01');
  return (char)param_1[1];
}

