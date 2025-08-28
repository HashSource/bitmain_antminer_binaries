
/* WARNING: Unknown calling convention */

int GetTotalRate(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *extraout_r3;
  int iVar8;
  int iVar9;
  int iVar10;
  int (*paiVar11) [256];
  undefined1 *puVar12;
  int iVar13;
  undefined1 *local_38;
  
  paiVar11 = chain_badcore_num;
  iVar10 = 0;
  local_38 = CSWTCH_824;
  puVar12 = CSWTCH_825;
  iVar13 = 0;
  do {
    if (dev->chain_exist[iVar10] == 1) {
      iVar9 = 0;
      iVar8 = 0;
      puVar6 = (undefined1 *)(iVar10 - 1);
      puVar7 = puVar6;
      do {
        if (fpga_version < 0xe) {
          bVar1 = *(byte *)((int)chain_pic_buf + iVar10 * 0x1f + (iVar10 / 3) * 0x123 + iVar8 + 0xb)
          ;
        }
        else {
          iVar3 = 0xb;
          if (puVar6 < (undefined1 *)0xd) {
            puVar7 = local_38;
          }
          iVar5 = 0;
          if (puVar6 < (undefined1 *)0xd) {
            iVar5 = *(int *)(puVar7 + -4);
            iVar3 = *(int *)(puVar12 + -4) * 0x1f + 0xb;
          }
          bVar1 = chain_pic_buf[iVar5][iVar3 + iVar8];
        }
        iVar8 = iVar8 + 1;
        lVar4 = strtol(freq_pll_1385[bVar1].freq,(char **)0x0,10);
        piVar2 = (int *)((int)*paiVar11 + iVar9);
        iVar9 = iVar9 + 4;
        iVar13 = lVar4 * (0x72 - *piVar2) + iVar13;
        puVar7 = extraout_r3;
      } while (iVar8 != 0x12);
    }
    iVar10 = iVar10 + 1;
    paiVar11 = paiVar11 + 1;
    puVar12 = puVar12 + 4;
    local_38 = local_38 + 4;
  } while (iVar10 != 0x10);
  return iVar13 / 1000;
}

