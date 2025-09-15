
void CheckChainTempTooLowFlag(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  bool bVar7;
  
  bVar7 = false;
  puVar5 = chain_temp_toolow;
  piVar6 = (int *)(dev + 4);
  piVar2 = piVar6;
  do {
    while (piVar2 = piVar2 + 1, *piVar2 == 1) {
      iVar1 = *(int *)puVar5;
      puVar5 = (undefined1 *)((int)puVar5 + 4);
      if (iVar1 == 0) {
        bVar7 = true;
      }
      if (puVar5 == lowest_testOK_temp) goto LAB_0002f728;
    }
    puVar5 = (undefined1 *)((int)puVar5 + 4);
  } while (puVar5 != lowest_testOK_temp);
LAB_0002f728:
  puVar3 = (undefined4 *)chain_temp_toolow;
  if (!bVar7) {
    do {
      piVar6 = piVar6 + 1;
      puVar4 = puVar3 + 1;
      if (*piVar6 == 1) {
        *puVar3 = 0;
      }
      puVar3 = puVar4;
    } while (puVar4 != (undefined4 *)lowest_testOK_temp);
  }
  return;
}

