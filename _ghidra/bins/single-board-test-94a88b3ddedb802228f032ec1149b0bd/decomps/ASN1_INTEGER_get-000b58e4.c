
long ASN1_INTEGER_get(ASN1_INTEGER *a)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  if (a->type == 0x102) {
    bVar1 = true;
  }
  else {
    if (a->type != 2) {
      return -1;
    }
    bVar1 = false;
  }
  iVar3 = a->length;
  if (4 < iVar3) {
    return -1;
  }
  pbVar4 = a->data;
  if (pbVar4 == (byte *)0x0) {
    return 0;
  }
  uVar2 = 0;
  if (0 < iVar3) {
    pbVar6 = pbVar4;
    do {
      pbVar5 = pbVar6 + 1;
      uVar2 = (uint)*pbVar6 | uVar2 << 8;
      pbVar6 = pbVar5;
    } while (pbVar5 != pbVar4 + iVar3);
  }
  if (bVar1) {
    return -uVar2;
  }
  return uVar2;
}

