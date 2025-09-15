
/* WARNING: Unknown calling convention */

int GetBoardRate(int chainIndex)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (dev->chain_exist[chainIndex] == 1) {
    iVar9 = 0;
    iVar1 = (chainIndex - 1U) * 4;
    iVar4 = 0;
    iVar8 = 0;
    do {
      if (fpga_version < 0xe) {
        bVar2 = *(byte *)((int)chain_pic_buf +
                         chainIndex * 0x1f + (chainIndex / 3) * 0x123 + iVar8 + 0xb);
      }
      else {
        iVar5 = 0xb;
        iVar7 = 0;
        if (chainIndex - 1U < 0xd) {
          iVar7 = *(int *)(CSWTCH_824 + iVar1);
          iVar5 = *(int *)(CSWTCH_825 + iVar1) * 0x1f + 0xb;
        }
        bVar2 = chain_pic_buf[iVar7][iVar5 + iVar8];
      }
      iVar8 = iVar8 + 1;
      lVar6 = strtol(freq_pll_1385[bVar2].freq,(char **)0x0,10);
      piVar3 = (int *)((int)chain_badcore_num[chainIndex] + iVar9);
      iVar9 = iVar9 + 4;
      iVar4 = lVar6 * (0x72 - *piVar3) + iVar4;
    } while (iVar8 != 0x12);
    iVar4 = iVar4 / 1000;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

