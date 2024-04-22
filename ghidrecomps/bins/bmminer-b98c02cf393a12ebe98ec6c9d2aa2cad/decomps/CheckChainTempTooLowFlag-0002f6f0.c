
void CheckChainTempTooLowFlag(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  
  bVar6 = false;
  piVar4 = DAT_0002f740 + 0x10;
  piVar5 = (int *)(dev + 4);
  piVar2 = piVar5;
  piVar3 = DAT_0002f740;
  do {
    while (piVar2 = piVar2 + 1, *piVar2 == 1) {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar1 == 0) {
        bVar6 = true;
      }
      if (piVar3 == piVar4) goto LAB_0002f728;
    }
    piVar3 = piVar3 + 1;
  } while (piVar3 != piVar4);
LAB_0002f728:
  piVar2 = DAT_0002f740;
  if (!bVar6) {
    do {
      piVar5 = piVar5 + 1;
      piVar3 = piVar2 + 1;
      if (*piVar5 == 1) {
        *piVar2 = 0;
      }
      piVar2 = piVar3;
    } while (piVar3 != piVar4);
  }
  return;
}

