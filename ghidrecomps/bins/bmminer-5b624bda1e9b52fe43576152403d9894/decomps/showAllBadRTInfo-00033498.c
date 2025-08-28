
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void showAllBadRTInfo(void)

{
  int iVar1;
  double *pdVar2;
  int iVar3;
  double dVar4;
  char logstr [256];
  
  iVar1 = 1;
  do {
    iVar3 = iVar1 + 1;
    if (dev->chain_exist[iVar1 + -1] == 1) {
      sprintf(logstr,"Check Chain[J%d] ASIC RT error: (asic index start from 1-%d)\n",iVar1,0x12);
      pdVar2 = chain_asic_RT[iVar1 + -1];
      writeLogFile(logstr);
      iVar1 = 1;
      do {
        dVar4 = *pdVar2;
        pdVar2 = pdVar2 + 1;
        if (100.0 < dVar4) {
          sprintf(logstr,"Asic[%02d]=%f\n",iVar1);
          writeLogFile(logstr);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x13);
    }
    iVar1 = iVar3;
  } while (iVar3 != 0x11);
  return;
}

