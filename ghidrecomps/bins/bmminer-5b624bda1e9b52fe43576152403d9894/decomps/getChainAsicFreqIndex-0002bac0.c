
/* WARNING: Unknown calling convention */

int getChainAsicFreqIndex(int chainIndex,int asicIndex)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int new_T9_PLUS_chainIndex;
  int iVar4;
  
  if (*DAT_0002bb28 < 0xe) {
    bVar1 = *(byte *)(DAT_0002bb30 + chainIndex * 0x1f + (chainIndex / 3) * 0x123 + asicIndex + 0xdf
                     );
  }
  else {
    uVar2 = chainIndex - 1;
    if (uVar2 < 0xd) {
      iVar4 = DAT_0002bb2c + uVar2 * 4;
      iVar3 = *(int *)(iVar4 + 0x9b8);
      iVar4 = *(int *)(iVar4 + 0x9ec) * 0x1f;
    }
    else {
      iVar3 = 0;
      iVar4 = 0xb;
    }
    if (uVar2 < 0xd) {
      iVar4 = iVar4 + 0xb;
    }
    bVar1 = *(byte *)(DAT_0002bb30 + iVar3 * 0x80 + iVar4 + asicIndex + 0xd4);
  }
  return (uint)bVar1;
}

