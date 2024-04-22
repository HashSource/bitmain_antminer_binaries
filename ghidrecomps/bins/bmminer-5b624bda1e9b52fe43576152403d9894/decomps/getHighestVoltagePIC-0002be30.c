
/* WARNING: Unknown calling convention */

uchar getHighestVoltagePIC(int chainIndex)

{
  uchar minVolPIC;
  byte bVar1;
  byte bVar2;
  int startIndex;
  uint uVar3;
  int iVar4;
  
  if (*DAT_0002bef4 < 0xe) {
    bVar2 = *(byte *)(DAT_0002bef8 + chainIndex + 0x7c);
    iVar4 = DAT_0002bef8 + (chainIndex / 3) * 3;
    bVar1 = *(byte *)(iVar4 + 0x7c);
    if (bVar2 <= *(byte *)(iVar4 + 0x7c)) {
      bVar1 = bVar2;
    }
    if (*(byte *)(iVar4 + 0x7d) <= bVar1) {
      bVar1 = *(byte *)(iVar4 + 0x7d);
    }
    if (*(byte *)(iVar4 + 0x7e) <= bVar1) {
      bVar1 = *(byte *)(iVar4 + 0x7e);
    }
    return bVar1;
  }
  if ((uint)chainIndex < 0xe) {
    uVar3 = 1 << (chainIndex & 0xffU);
    if ((uVar3 & 0x3008) != 0) {
      bVar2 = *(byte *)(DAT_0002bef8 + 0x88);
      if (*(byte *)(DAT_0002bef8 + 0x7f) <= *(byte *)(DAT_0002bef8 + 0x88)) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x7f);
      }
      if (*(byte *)(DAT_0002bef8 + 0x89) <= bVar2) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x89);
      }
      return bVar2;
    }
    if ((uVar3 & 0xc04) != 0) {
      bVar2 = *(byte *)(DAT_0002bef8 + 0x86);
      if (*(byte *)(DAT_0002bef8 + 0x7e) <= *(byte *)(DAT_0002bef8 + 0x86)) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x7e);
      }
      if (*(byte *)(DAT_0002bef8 + 0x87) <= bVar2) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x87);
      }
      return bVar2;
    }
    if ((uVar3 & 0x302) != 0) {
      bVar2 = *(byte *)(DAT_0002bef8 + 0x84);
      if (*(byte *)(DAT_0002bef8 + 0x7d) <= *(byte *)(DAT_0002bef8 + 0x84)) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x7d);
      }
      if (*(byte *)(DAT_0002bef8 + 0x85) <= bVar2) {
        bVar2 = *(byte *)(DAT_0002bef8 + 0x85);
      }
      return bVar2;
    }
  }
  minVolPIC = '\0';
  return minVolPIC;
}

