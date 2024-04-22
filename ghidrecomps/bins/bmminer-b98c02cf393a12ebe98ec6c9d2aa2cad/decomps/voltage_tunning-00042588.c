
uint voltage_tunning(int param_1,int *param_2)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  double in_d0;
  double in_d1;
  double dVar5;
  
  uVar4 = param_2[6];
  if (uVar4 == 0 || in_d0 == 0.0) {
    uVar4 = get_power_iic_value_from_voltage(param_2);
    write_iic_of_S9_plus_power(uVar4,param_2);
    is7007_Board();
    return uVar4;
  }
  dVar5 = ABS(in_d1 - in_d0);
  if (3 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: last_iic_data = %d\n","power.c",0x172,DAT_00042820,uVar4);
    }
    fclose(pFVar1);
  }
  if ((int)((uint)(dVar5 < DAT_000427f8) << 0x1f) < 0) {
    iVar2 = is7007_Board();
    if (iVar2 == 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: It\'s very close to target voltage, stop tunning\n","power.c",
                  0x17e,DAT_00042820);
        }
        fclose(pFVar1);
      }
      *(undefined *)(param_2 + 1) = 1;
      return uVar4;
    }
    iVar2 = param_2[9];
    param_2[9] = iVar2 + 1U;
    if (iVar2 + 1U < 2) {
      return uVar4;
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: It\'s very close to target voltage, stop tunning\n","power.c",
                0x178,DAT_00042820);
      }
      fclose(pFVar1);
    }
    *(undefined *)(param_2 + 1) = 1;
    param_2[9] = 0;
    return uVar4;
  }
  if (param_1 == 0) {
    if (dVar5 == 0.25 || dVar5 < 0.25 != NAN(dVar5)) {
      iVar2 = *param_2;
      if (dVar5 == DAT_00042800 || dVar5 < DAT_00042800 != (NAN(dVar5) || NAN(DAT_00042800))) {
LAB_0004274a:
        if (dVar5 == DAT_00042808 || dVar5 < DAT_00042808 != (NAN(dVar5) || NAN(DAT_00042808))) {
          if (dVar5 == DAT_00042810 || dVar5 < DAT_00042810 != (NAN(dVar5) || NAN(DAT_00042810))) {
            iVar3 = 1;
          }
          else {
            iVar3 = 2;
          }
        }
        else {
          iVar3 = 4;
        }
        goto LAB_000425e6;
      }
      if (iVar2 != 2) goto LAB_0004263c;
      iVar3 = 8;
    }
    else {
      iVar2 = *param_2;
      if (iVar2 != 2) {
        if (dVar5 == DAT_00042800 || dVar5 < DAT_00042800 != (NAN(dVar5) || NAN(DAT_00042800)))
        goto LAB_0004274a;
LAB_0004263c:
        if (dVar5 == DAT_00042808 || dVar5 < DAT_00042808 != (NAN(dVar5) || NAN(DAT_00042808))) {
          if (dVar5 == DAT_00042810 || dVar5 < DAT_00042810 != (NAN(dVar5) || NAN(DAT_00042810))) {
            iVar3 = 1;
          }
          else {
            iVar3 = 2;
          }
        }
        else {
          iVar3 = 4;
        }
        goto LAB_000425ec;
      }
      iVar3 = 0x10;
    }
LAB_0004270a:
    iVar2 = (uint)(dVar5 < DAT_00042818) << 0x1f;
    if (-1 < iVar2) {
      iVar3 = iVar3 << 1;
    }
    if (iVar2 < 0) {
      iVar3 = 1;
    }
    if (in_d1 == in_d0 || in_d1 < in_d0 != (NAN(in_d1) || NAN(in_d0))) {
LAB_000426ea:
      uVar4 = uVar4 + iVar3;
      if (0xfe < (int)uVar4) {
        uVar4 = 0xff;
      }
      goto LAB_00042602;
    }
  }
  else {
    iVar2 = *param_2;
    iVar3 = 1;
LAB_000425e6:
    if (iVar2 == 2) goto LAB_0004270a;
LAB_000425ec:
    if (in_d1 == in_d0 || in_d1 < in_d0 != (NAN(in_d1) || NAN(in_d0))) {
      if (iVar2 == 1) goto LAB_000425fc;
      goto LAB_000426ea;
    }
    if (iVar2 == 1) {
      uVar4 = uVar4 + iVar3;
      if (0x7e < (int)uVar4) {
        uVar4 = 0x7f;
      }
      goto LAB_00042602;
    }
  }
LAB_000425fc:
  uVar4 = uVar4 - iVar3 & ~((int)(uVar4 - iVar3) >> 0x1f);
LAB_00042602:
  write_iic_of_S9_plus_power(uVar4 & 0xff,param_2);
  return uVar4;
}

