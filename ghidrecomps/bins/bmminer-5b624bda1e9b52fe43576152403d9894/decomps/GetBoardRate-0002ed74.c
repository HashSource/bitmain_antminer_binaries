
/* WARNING: Unknown calling convention */

int GetBoardRate(int chainIndex)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int new_T9_PLUS_chainIndex;
  int iVar10;
  int j;
  int iVar11;
  int iVar12;
  int iVar13;
  
  piVar4 = DAT_0002ee64;
  iVar3 = DAT_0002ee60;
  if (*(int *)(*DAT_0002ee58 + (chainIndex + 2) * 4) == 1) {
    iVar11 = 0;
    iVar13 = DAT_0002ee5c + chainIndex * 0x400;
    iVar12 = DAT_0002ee60 + (chainIndex - 1U) * 4;
    iVar5 = 0;
    iVar10 = 0;
    iVar8 = DAT_0002ee5c + chainIndex * 0x1f + (chainIndex / 3) * 0x123;
    do {
      if (*piVar4 < 0xe) {
        bVar1 = *(byte *)(iVar8 + iVar10 + -0x7f9);
      }
      else {
        iVar6 = 0xb;
        iVar9 = 0;
        if (chainIndex - 1U < 0xd) {
          iVar9 = *(int *)(iVar12 + 0x9b8);
          iVar6 = *(int *)(iVar12 + 0x9ec) * 0x1f + 0xb;
        }
        bVar1 = chain_pic_buf[iVar9][iVar6 + iVar10];
      }
      iVar10 = iVar10 + 1;
      lVar7 = strtol(*(char **)(iVar3 + (uint)bVar1 * 0x10 + 0x38),(char **)0x0,10);
      piVar2 = (int *)(iVar13 + iVar11);
      iVar11 = iVar11 + 4;
      iVar5 = lVar7 * (0x72 - *piVar2) + iVar5;
    } while (iVar10 != 0x12);
    iVar5 = iVar5 / 1000;
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}

