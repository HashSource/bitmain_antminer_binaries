
void ASN1_put_object(uchar **pp,int constructed,int length,int tag,int xclass)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if (constructed == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = 0x20;
  }
  pbVar7 = *pp;
  bVar4 = bVar4 | (byte)xclass & 0xc0;
  if (tag < 0x1f) {
    pbVar8 = pbVar7 + 1;
    *pbVar7 = bVar4 | (byte)tag & 0x1f;
  }
  else {
    *pbVar7 = bVar4 | 0x1f;
    iVar3 = tag;
    iVar6 = 0;
    do {
      iVar5 = iVar6;
      iVar3 = iVar3 >> 7;
      iVar6 = iVar5 + 1;
    } while (iVar3 != 0);
    pbVar7[iVar5 + 1] = (byte)tag & 0x7f;
    iVar3 = iVar5;
    while( true ) {
      iVar6 = iVar3 + -1;
      tag = tag >> 7;
      bVar4 = (byte)tag & 0x7f;
      if (iVar3 < 1) break;
      if (iVar6 == iVar5) {
        pbVar7[iVar3] = bVar4;
        iVar3 = iVar6;
      }
      else {
        pbVar7[iVar3] = bVar4 | 0x80;
        iVar3 = iVar6;
      }
    }
    pbVar8 = pbVar7 + iVar5 + 2;
  }
  if (constructed == 2) {
    pbVar7 = pbVar8 + 1;
    *pbVar8 = 0x80;
  }
  else if (length < 0x80) {
    pbVar7 = pbVar8 + 1;
    *pbVar8 = (byte)length;
  }
  else {
    iVar3 = length;
    iVar6 = 0;
    do {
      iVar5 = iVar6;
      iVar3 = iVar3 >> 8;
      iVar6 = iVar5 + 1;
    } while (iVar3 != 0);
    iVar3 = 0;
    if (iVar5 < 0x20) {
      iVar3 = length;
    }
    *pbVar8 = (byte)iVar6 | 0x80;
    if (0x1f < iVar5) {
      pbVar7 = pbVar8 + iVar5;
      iVar1 = iVar5;
      do {
        iVar6 = iVar1;
        pbVar7[1] = (byte)length;
        HintPreloadData(pbVar8 + iVar6 + -0x21);
        pbVar8[iVar6] = (byte)((uint)length >> 8);
        bVar4 = (byte)iVar3;
        pbVar7[-3] = bVar4;
        pbVar7[-4] = bVar4;
        pbVar7[-5] = bVar4;
        pbVar7[-6] = bVar4;
        pbVar7[-7] = bVar4;
        pbVar7[-8] = bVar4;
        pbVar7[-9] = bVar4;
        pbVar7[-10] = bVar4;
        pbVar7[-0xb] = bVar4;
        pbVar7[-0xc] = bVar4;
        pbVar7[-0xd] = bVar4;
        pbVar7[-0xe] = bVar4;
        pbVar7[-0xf] = bVar4;
        pbVar7[-0x10] = bVar4;
        pbVar7[-0x11] = bVar4;
        pbVar7[-0x12] = bVar4;
        pbVar7[-0x13] = bVar4;
        pbVar7[-0x14] = bVar4;
        pbVar7[-0x15] = bVar4;
        pbVar7[-0x16] = bVar4;
        pbVar7[-0x17] = bVar4;
        pbVar7[-0x18] = bVar4;
        pbVar7[-0x19] = bVar4;
        pbVar7[-0x1a] = bVar4;
        pbVar7[-0x1b] = bVar4;
        pbVar7[-0x1c] = bVar4;
        pbVar7[-0x1d] = bVar4;
        pbVar7[-0x1e] = bVar4;
        pbVar7[-1] = (byte)((uint)length >> 0x10);
        pbVar7[-2] = (byte)((uint)length >> 0x18);
        pbVar7 = pbVar7 + -0x20;
        length = 0;
        iVar1 = iVar6 + -0x20;
      } while (0x1f < iVar6 + -0x20);
      iVar6 = iVar6 + -0x1f;
    }
    pbVar7 = pbVar8 + iVar6;
    do {
      pbVar2 = pbVar7 + -1;
      *pbVar7 = (byte)iVar3;
      iVar3 = iVar3 >> 8;
      pbVar7 = pbVar2;
    } while (0 < (int)pbVar2 - (int)pbVar8);
    pbVar7 = pbVar8 + iVar5 + 2;
  }
  *pp = pbVar7;
  return;
}

