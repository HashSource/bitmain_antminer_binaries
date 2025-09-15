
int GetRealBoardRate(int param_1)

{
  byte bVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  
  if (*(int *)(dev + (param_1 + 2) * 4) != 1) {
    return 0;
  }
  iVar6 = 0;
  pbVar5 = chip_last_freq + param_1 * 0x100 + 2;
  piVar3 = (int *)(chain_badcore_num + param_1 * 0x400);
  do {
    while (*piVar3 < 0xf) {
      bVar1 = *pbVar5;
      piVar4 = piVar3 + 1;
      pbVar5 = pbVar5 + 1;
      lVar2 = strtol(*(char **)(freq_pll_1385 + (uint)bVar1 * 0x10),(char **)0x0,10);
      iVar6 = lVar2 * (0x72 - *piVar3) + iVar6;
      piVar3 = piVar4;
      if (piVar4 == (int *)(chain_badcore_num + param_1 * 0x400 + 0x150)) goto LAB_0002ffe6;
    }
    piVar3 = piVar3 + 1;
    pbVar5 = pbVar5 + 1;
  } while (piVar3 != (int *)(chain_badcore_num + param_1 * 0x400 + 0x150));
LAB_0002ffe6:
  return iVar6 / 1000;
}

