
char set_iic_power_voltage(int *param_1,int param_2)

{
  char cVar1;
  double dVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  FILE *pFVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  
  dVar3 = DAT_00042a08;
  dVar2 = DAT_00042a00;
  uVar9 = 0;
  iVar8 = 0;
  *(undefined *)(param_1 + 1) = 0;
  do {
    sleep(1);
    iVar5 = is7007_Board();
    if (iVar5 == 0) {
      dVar10 = (double)get_avg_voltage();
    }
    else {
      dVar10 = (double)get_min_voltage();
      if (param_2 != 0) {
        dVar10 = (dVar10 * dVar2) / dVar3;
      }
    }
    uVar4 = voltage_tunning(SUB84(dVar10,0),uVar9,param_1);
    if (log_level < 4) {
      if (0x32 < iVar8) goto LAB_00042886;
LAB_000428ca:
      iVar5 = iVar8 + 1;
      iVar8 = iVar8 + 2;
      if (0x14 < iVar5) {
        if (log_level < 6) {
          uVar9 = 1;
        }
        else {
          pFVar6 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar6 != (FILE *)0x0) {
            fprintf(pFVar6,"%s:%d:%s: tuning up 20 times\n","power.c",0x27a,DAT_00042a10);
          }
          uVar9 = 1;
          fclose(pFVar6);
        }
      }
    }
    else {
      pFVar6 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar6 != (FILE *)0x0) {
        fprintf(pFVar6,"%s:%d:%s: voltage_tunning, set to %f, N=%d\n","power.c",0x272,DAT_00042a10);
      }
      fclose(pFVar6);
      if (iVar8 < 0x33) goto LAB_000428ca;
      if (3 < log_level) {
        pFVar6 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar6 != (FILE *)0x0) {
          fprintf(pFVar6,"%s:%d:%s: power voltage abnormal\n","power.c",0x275,DAT_00042a10);
        }
        fclose(pFVar6);
      }
LAB_00042886:
      iVar8 = iVar8 + 1;
      stop_mining("power abnormal");
    }
    if (*param_1 == 1) {
      uVar7 = 0x7f;
    }
    else {
      uVar7 = 0xff;
    }
    if (uVar4 != 0 && uVar7 < uVar4 || (uVar4 == 0 || uVar7 == uVar4)) {
      return *(char *)(param_1 + 1);
    }
    if (log_level < 6) {
      cVar1 = *(char *)(param_1 + 1);
    }
    else {
      pFVar6 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar6 != (FILE *)0x0) {
        fprintf(pFVar6,"%s:%d:%s: tunning %d times\n","power.c",0x283,DAT_00042a10,iVar8);
      }
      fclose(pFVar6);
      cVar1 = *(char *)(param_1 + 1);
    }
    if (cVar1 != '\0') {
      return cVar1;
    }
  } while( true );
}

