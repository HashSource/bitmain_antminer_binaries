
int ASN1_PRINTABLE_type(uchar *s,int max)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  bool bVar6;
  int iVar7;
  byte *pbVar8;
  
  if (max < 1) {
    max = -1;
  }
  if (s == (uchar *)0x0) {
    iVar7 = 0x13;
  }
  else {
    bVar2 = false;
    bVar1 = *s;
    bVar6 = false;
    pbVar3 = s + 1;
    while ((uVar4 = (uint)bVar1, uVar4 != 0 && (pbVar3 != s + 1 + max))) {
      if ((((0x19 < (uVar4 & 0xffffffdf) - 0x41) &&
           ((((uVar4 != 0x20 && (9 < uVar4 - 0x30)) && (uVar4 != 0x27)) &&
            ((1 < uVar4 - 0x28 && (1 < uVar4 - 0x2b)))))) && (1 < uVar4 - 0x2d)) &&
         ((uVar4 != 0x3a && uVar4 != 0x2f && ((uVar4 & 0xfd) != 0x3d)))) {
        bVar6 = true;
      }
      pbVar8 = pbVar3 + 1;
      bVar5 = bVar1 & 0x80;
      bVar1 = *pbVar3;
      pbVar3 = pbVar8;
      if (bVar5 != 0) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      iVar7 = 0x14;
    }
    else if (bVar6) {
      iVar7 = 0x16;
    }
    else {
      iVar7 = 0x13;
    }
  }
  return iVar7;
}

