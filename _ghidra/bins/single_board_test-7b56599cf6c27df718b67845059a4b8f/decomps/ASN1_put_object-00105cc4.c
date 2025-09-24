
void ASN1_put_object(uchar **pp,int constructed,int length,int tag,int xclass)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  
  if (constructed == 0) {
    bVar7 = 0;
  }
  else {
    bVar7 = 0x20;
  }
  pbVar4 = *pp;
  bVar7 = bVar7 | (byte)xclass & 0xc0;
  if (tag < 0x1f) {
    pbVar10 = pbVar4 + 1;
    *pbVar4 = bVar7 | (byte)tag & 0x1f;
  }
  else {
    *pbVar4 = bVar7 | 0x1f;
    iVar3 = tag;
    iVar1 = 0;
    do {
      iVar9 = iVar1;
      iVar3 = iVar3 >> 7;
      iVar1 = iVar9 + 1;
    } while (iVar3 != 0);
    pbVar4[iVar9 + 1] = (byte)tag & 0x7f;
    iVar3 = iVar9;
    pbVar10 = pbVar4 + iVar9;
    while( true ) {
      iVar3 = iVar3 + -1;
      tag = tag >> 7;
      bVar7 = (byte)tag & 0x7f;
      if (iVar3 == -1) break;
      if (iVar9 == iVar3) {
        *pbVar10 = bVar7;
        pbVar10 = pbVar10 + -1;
      }
      else {
        *pbVar10 = bVar7 | 0x80;
        pbVar10 = pbVar10 + -1;
      }
    }
    pbVar10 = pbVar4 + iVar9 + 2;
  }
  if (constructed == 2) {
    *pbVar10 = 0x80;
    *pp = pbVar10 + 1;
    return;
  }
  if (0x7f < length) {
    iVar3 = length;
    uVar8 = 0;
    do {
      uVar5 = uVar8;
      iVar3 = iVar3 >> 8;
      uVar8 = uVar5 + 1;
    } while (iVar3 != 0);
    *pbVar10 = (byte)uVar8 | 0x80;
    if (0x1f < (int)uVar5) {
      pbVar4 = pbVar10 + (uVar5 - 0x21);
      uVar6 = uVar5;
      do {
        uVar8 = uVar6;
        uVar6 = uVar8 - 0x20;
        pbVar4[0x22] = (byte)length;
        HintPreloadData(pbVar4);
        pbVar4[0x1e] = 0;
        pbVar4[0x1d] = 0;
        pbVar4[0x1c] = 0;
        pbVar4[0x1b] = 0;
        pbVar4[0x1a] = 0;
        pbVar4[0x19] = 0;
        pbVar4[0x18] = 0;
        pbVar4[0x17] = 0;
        pbVar4[0x16] = 0;
        pbVar4[0x15] = 0;
        pbVar4[0x14] = 0;
        pbVar4[0x13] = 0;
        pbVar4[0x12] = 0;
        pbVar4[0x11] = 0;
        pbVar4[0x10] = 0;
        pbVar4[0xf] = 0;
        pbVar4[0xe] = 0;
        pbVar4[0xd] = 0;
        pbVar4[0xc] = 0;
        pbVar4[0xb] = 0;
        pbVar4[10] = 0;
        pbVar4[9] = 0;
        pbVar4[8] = 0;
        pbVar4[7] = 0;
        pbVar4[6] = 0;
        pbVar4[5] = 0;
        pbVar4[4] = 0;
        pbVar4[0x21] = (byte)((uint)length >> 8);
        pbVar4[0x20] = (byte)((uint)length >> 0x10);
        pbVar4[0x1f] = (byte)((uint)length >> 0x18);
        pbVar4[3] = 0;
        length = 0;
        pbVar4 = pbVar4 + -0x20;
      } while (0x1f < uVar6);
      uVar8 = uVar8 - 0x1f;
      length = 0;
    }
    pbVar4 = pbVar10 + uVar8;
    do {
      pbVar2 = pbVar4 + -1;
      *pbVar4 = (byte)length;
      length = length >> 8;
      pbVar4 = pbVar2;
    } while (0 < (int)pbVar2 - (int)pbVar10);
    *pp = pbVar10 + uVar5 + 2;
    return;
  }
  *pbVar10 = (byte)length;
  *pp = pbVar10 + 1;
  return;
}

