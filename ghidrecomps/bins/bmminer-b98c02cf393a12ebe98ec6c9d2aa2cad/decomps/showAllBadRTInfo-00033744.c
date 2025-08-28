
void showAllBadRTInfo(void)

{
  int iVar1;
  double *pdVar2;
  int iVar3;
  undefined1 *puVar4;
  double dVar5;
  char acStack_428 [1024];
  
  puVar4 = chain_asic_RT;
  iVar1 = 1;
  do {
    iVar3 = iVar1 + 1;
    if (*(int *)(dev + iVar3 * 4) == 1) {
      sprintf(acStack_428,"Check Chain[J%d] ASIC RT error: (asic index start from 1-%d)\n",iVar1,
              0x54);
      writeLogFile(acStack_428);
      iVar1 = 1;
      pdVar2 = (double *)puVar4;
      do {
        dVar5 = *pdVar2;
        pdVar2 = pdVar2 + 1;
        if (100.0 < dVar5) {
          sprintf(acStack_428,"Asic[%02d]=%f\n",iVar1);
          writeLogFile(acStack_428);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x55);
    }
    puVar4 = (undefined1 *)((int)puVar4 + 0x2a0);
    iVar1 = iVar3;
  } while (iVar3 != 0x11);
  return;
}

