
/* WARNING: Unknown calling convention */

void setChainTempTooLowFlag(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char logstr [256];
  
  iVar2 = DAT_000338c8;
  piVar1 = DAT_000338c4;
  iVar5 = 0;
  puVar6 = DAT_000338b8;
  do {
    iVar4 = *piVar1;
    *puVar6 = 0;
    if ((*(int *)(iVar4 + (iVar5 + 2) * 4) == 1) &&
       (iVar4 = (int)*(short *)(iVar4 + iVar5 * 8 + 0x96a), 0 < iVar4)) {
      iVar3 = *(int *)(iVar2 + iVar5 * 4);
      if (iVar3 < 1) {
        if (iVar4 < 0x50) {
          sprintf(logstr,DAT_000338c0,iVar5);
          writeLogFile(logstr);
          *puVar6 = 1;
        }
      }
      else if (iVar4 < iVar3) {
        sprintf(logstr,DAT_000338bc,iVar5,iVar4,iVar3);
        writeLogFile(logstr);
        *puVar6 = 1;
      }
    }
    iVar5 = iVar5 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar5 != 0x10);
  CheckChainTempTooLowFlag();
  return;
}

