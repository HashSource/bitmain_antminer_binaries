
char set_iic_power_voltage(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  FILE *pFVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 extraout_s1;
  double dVar9;
  
  uVar6 = 0;
  iVar5 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  do {
    sleep(1);
    iVar2 = is7007_Board();
    if (iVar2 == 0) {
      uVar8 = get_avg_voltage();
      dVar9 = (double)(ulonglong)uVar8;
    }
    else {
      uVar7 = get_min_voltage();
      dVar9 = (double)CONCAT44(extraout_s1,uVar7);
      if (param_2 != 0) {
        dVar9 = (dVar9 * 324.0) / 330.0;
      }
    }
    uVar8 = voltage_tunning(SUB84(dVar9,0),uVar6,param_1);
    if (log_level < 4) {
      if (0x32 < iVar5) goto LAB_00042886;
LAB_000428ca:
      iVar2 = iVar5 + 1;
      iVar5 = iVar5 + 2;
      if (0x14 < iVar2) {
        if (log_level < 6) {
          uVar6 = 1;
        }
        else {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: tuning up 20 times\n","power.c",0x27a,"set_iic_power_voltage")
            ;
          }
          uVar6 = 1;
          fclose(pFVar3);
        }
      }
    }
    else {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: voltage_tunning, set to %f, N=%d\n","power.c",0x272,
                "set_iic_power_voltage");
      }
      fclose(pFVar3);
      if (iVar5 < 0x33) goto LAB_000428ca;
      if (3 < log_level) {
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: power voltage abnormal\n","power.c",0x275,
                  "set_iic_power_voltage");
        }
        fclose(pFVar3);
      }
LAB_00042886:
      iVar5 = iVar5 + 1;
      stop_mining("power abnormal");
    }
    if (*param_1 == 1) {
      uVar4 = 0x7f;
    }
    else {
      uVar4 = 0xff;
    }
    if (uVar8 == 0 || uVar4 <= uVar8) {
      return (char)param_1[1];
    }
    if (log_level < 6) {
      cVar1 = (char)param_1[1];
    }
    else {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: tunning %d times\n","power.c",0x283,"set_iic_power_voltage",iVar5)
        ;
      }
      fclose(pFVar3);
      cVar1 = (char)param_1[1];
    }
    if (cVar1 != '\0') {
      return cVar1;
    }
  } while( true );
}

