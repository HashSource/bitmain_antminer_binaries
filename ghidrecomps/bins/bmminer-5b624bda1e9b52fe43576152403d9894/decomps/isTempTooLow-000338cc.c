
/* WARNING: Unknown calling convention */

_Bool isTempTooLow(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char logstr [256];
  
  iVar1 = 0;
  iVar2 = 0;
  iVar4 = *DAT_00033944;
  do {
    if (((*(int *)(*DAT_00033944 + iVar1 + 8) == 1) && (*(int *)(iVar1 + DAT_00033948) == 0)) &&
       (iVar5 = (int)*(short *)(iVar4 + 0x572), 0 < iVar5)) {
      iVar3 = *(int *)(iVar1 + DAT_00033954);
      if (iVar3 < 1) {
        if (iVar5 < 0x50) {
          sprintf(logstr,DAT_00033950,iVar2,iVar5);
          writeLogFile(logstr);
          return true;
        }
      }
      else if (iVar5 < iVar3) {
        sprintf(logstr,DAT_0003394c,iVar2,iVar3,iVar5);
        writeLogFile(logstr);
        return true;
      }
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x40;
  } while (iVar1 != 0x40);
  return false;
}

