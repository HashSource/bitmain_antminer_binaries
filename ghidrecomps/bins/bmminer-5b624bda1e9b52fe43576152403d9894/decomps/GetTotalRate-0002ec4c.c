
/* WARNING: Unknown calling convention */

int GetTotalRate(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  int new_T9_PLUS_chainIndex;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int j;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint local_38;
  
  piVar4 = DAT_0002ed70;
  uVar3 = DAT_0002ed64;
  iVar13 = 0;
  local_38 = DAT_0002ed64;
  iVar15 = DAT_0002ed64 + 0x34;
  iVar16 = 0;
  iVar14 = DAT_0002ed6c;
  do {
    if (dev->chain_exist[iVar13] == 1) {
      iVar12 = 0;
      iVar11 = 0;
      uVar9 = iVar13 - 1;
      uVar7 = DAT_0002ed68 + iVar13 * 0x1f + (iVar13 / 3) * 0x123;
      uVar10 = uVar9;
      do {
        if (*piVar4 < 0xe) {
          bVar1 = *(byte *)(uVar7 + iVar11 + 0xb);
          uVar10 = uVar7;
        }
        else {
          iVar5 = 0xb;
          if (uVar9 < 0xd) {
            uVar10 = local_38;
          }
          iVar8 = 0;
          if (uVar9 < 0xd) {
            iVar8 = *(int *)(uVar10 - 4);
            iVar5 = *(int *)(iVar15 + -4) * 0x1f + 0xb;
          }
          bVar1 = chain_pic_buf[iVar8][iVar5 + iVar11];
        }
        iVar11 = iVar11 + 1;
        lVar6 = strtol(*(char **)(uVar3 + (uint)bVar1 * 0x10 + -0x980),(char **)0x0,10);
        piVar2 = (int *)(iVar14 + iVar12);
        iVar12 = iVar12 + 4;
        iVar16 = lVar6 * (0x72 - *piVar2) + iVar16;
      } while (iVar11 != 0x12);
    }
    iVar13 = iVar13 + 1;
    iVar14 = iVar14 + 0x400;
    iVar15 = iVar15 + 4;
    local_38 = local_38 + 4;
  } while (iVar13 != 0x10);
  return iVar16 / 1000;
}

