
void showAllBadRTInfo(void)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  int iVar4;
  double *pdVar5;
  double dVar6;
  char acStack_428 [1024];
  
  dVar1 = DAT_000337d8;
  iVar2 = 1;
  pdVar5 = DAT_000337e0;
  do {
    iVar4 = iVar2 + 1;
    if (*(int *)(dev + iVar4 * 4) == 1) {
      sprintf(acStack_428,"Check Chain[J%d] ASIC RT error: (asic index start from 1-%d)\n",iVar2,
              0x54);
      writeLogFile(acStack_428);
      iVar2 = 1;
      pdVar3 = pdVar5;
      do {
        dVar6 = *pdVar3;
        pdVar3 = pdVar3 + 1;
        if (dVar6 != dVar1 && dVar6 < dVar1 == (NAN(dVar6) || NAN(dVar1))) {
          sprintf(acStack_428,"Asic[%02d]=%f\n",iVar2);
          writeLogFile(acStack_428);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x55);
    }
    pdVar5 = pdVar5 + 0x54;
    iVar2 = iVar4;
  } while (iVar4 != 0x11);
  return;
}

