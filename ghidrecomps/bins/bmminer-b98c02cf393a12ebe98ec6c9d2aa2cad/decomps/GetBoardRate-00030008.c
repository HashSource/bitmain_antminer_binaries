
int GetBoardRate(int param_1)

{
  byte bVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  
  if (*(int *)(dev + (param_1 + 2) * 4) != 1) {
    return 0;
  }
  iVar7 = 0;
  piVar6 = (int *)(param_1 * 0x400 + 0x150 + DAT_00030098);
  pbVar5 = (byte *)(DAT_00030094 + param_1 * 0x80 + 2);
  piVar3 = (int *)(param_1 * 0x400 + DAT_00030098);
  do {
    while (*piVar3 < 0xf) {
      bVar1 = *pbVar5;
      piVar4 = piVar3 + 1;
      pbVar5 = pbVar5 + 1;
      lVar2 = strtol(*(char **)(freq_pll_1385 + (uint)bVar1 * 0x10),(char **)0x0,10);
      iVar7 = lVar2 * (0x72 - *piVar3) + iVar7;
      piVar3 = piVar4;
      if (piVar4 == piVar6) goto LAB_0003007a;
    }
    piVar3 = piVar3 + 1;
    pbVar5 = pbVar5 + 1;
  } while (piVar3 != piVar6);
LAB_0003007a:
  return iVar7 / 1000;
}

