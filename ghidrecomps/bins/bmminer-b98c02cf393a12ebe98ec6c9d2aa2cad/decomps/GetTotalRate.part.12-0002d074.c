
int GetTotalRate_part_12(void)

{
  long lVar1;
  int *piVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar5 = 0;
  piVar4 = DAT_0002d104;
  pbVar6 = DAT_0002d108;
  do {
    if (*(int *)(dev + (iVar5 + 2) * 4) == 1) {
      piVar2 = piVar4 + -0x54;
      pbVar3 = pbVar6;
      do {
        if (*piVar2 < 0xf) {
          lVar1 = strtol(*(char **)(freq_pll_1385 + (uint)*pbVar3 * 0x10),(char **)0x0,10);
          iVar7 = lVar1 * (0x72 - *piVar2) + iVar7;
        }
        piVar2 = piVar2 + 1;
        pbVar3 = pbVar3 + 1;
      } while (piVar2 != piVar4);
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 0x100;
    pbVar6 = pbVar6 + 0x80;
  } while (iVar5 != 0x10);
  return iVar7 / 1000;
}

