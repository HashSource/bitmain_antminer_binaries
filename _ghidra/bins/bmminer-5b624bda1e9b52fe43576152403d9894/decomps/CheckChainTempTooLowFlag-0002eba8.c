
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CheckChainTempTooLowFlag(void)

{
  int *piVar1;
  all_parameters *paVar2;
  bool bVar3;
  int iVar4;
  
  paVar2 = dev;
  iVar4 = 0;
  bVar3 = false;
  do {
    while (*(int *)((int)dev->chain_exist + iVar4) == 1) {
      piVar1 = (int *)((int)chain_temp_toolow + iVar4);
      iVar4 = iVar4 + 4;
      if (*piVar1 == 0) {
        bVar3 = true;
      }
      if (iVar4 == 0x40) goto LAB_0002ebd2;
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x40);
LAB_0002ebd2:
  if (!bVar3) {
    iVar4 = 0;
    do {
      if (*(int *)((int)paVar2->chain_exist + iVar4) == 1) {
        *(undefined4 *)((int)chain_temp_toolow + iVar4) = 0;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 != 0x40);
  }
  return;
}

