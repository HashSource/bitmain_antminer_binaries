
/* WARNING: Unknown calling convention */

void CheckChainTempTooLowFlag(void)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_0002ebf0;
  iVar5 = 0;
  bVar3 = false;
  iVar4 = *DAT_0002ebec;
  do {
    while (*(int *)(iVar4 + iVar5 + 8) == 1) {
      piVar1 = (int *)(iVar5 + DAT_0002ebf0);
      iVar5 = iVar5 + 4;
      if (*piVar1 == 0) {
        bVar3 = true;
      }
      if (iVar5 == 0x40) goto LAB_0002ebd2;
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 != 0x40);
LAB_0002ebd2:
  if (!bVar3) {
    iVar5 = 0;
    do {
      if (*(int *)(iVar4 + iVar5 + 8) == 1) {
        *(undefined4 *)(iVar5 + iVar2) = 0;
      }
      iVar5 = iVar5 + 4;
    } while (iVar5 != 0x40);
  }
  return;
}

