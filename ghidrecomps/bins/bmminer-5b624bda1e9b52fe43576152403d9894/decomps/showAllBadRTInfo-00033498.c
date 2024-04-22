
/* WARNING: Unknown calling convention */

void showAllBadRTInfo(void)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  double dVar7;
  char logstr [256];
  
  piVar3 = DAT_0003352c;
  iVar2 = DAT_00033520;
  dVar1 = DAT_00033518;
  iVar4 = 1;
  do {
    iVar6 = iVar4 + 1;
    if (*(int *)(*piVar3 + iVar6 * 4) == 1) {
      sprintf(logstr,DAT_00033524,iVar4,0x12);
      pdVar5 = (double *)(iVar2 + (iVar4 + -1) * 0x90);
      writeLogFile(logstr);
      iVar4 = 1;
      do {
        dVar7 = *pdVar5;
        pdVar5 = pdVar5 + 1;
        if (dVar7 != dVar1 && dVar7 < dVar1 == (NAN(dVar7) || NAN(dVar1))) {
          sprintf(logstr,DAT_00033528,iVar4);
          writeLogFile(logstr);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x13);
    }
    iVar4 = iVar6;
  } while (iVar6 != 0x11);
  return;
}

