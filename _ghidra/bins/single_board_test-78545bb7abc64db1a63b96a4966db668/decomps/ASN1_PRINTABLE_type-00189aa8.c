
int ASN1_PRINTABLE_type(uchar *s,int max)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  size_t sVar5;
  byte *pbVar6;
  
  if (s == (uchar *)0x0) {
    return 0x13;
  }
  if (max < 0) {
    max = strlen((char *)s);
  }
  bVar2 = false;
  bVar3 = false;
  while (sVar5 = max - 1, 0 < max) {
    pbVar6 = s + 1;
    bVar1 = *s;
    iVar4 = ossl_ctype_check(bVar1,0x800);
    if (iVar4 == 0) {
      bVar3 = true;
    }
    max = sVar5;
    s = pbVar6;
    if ((bVar1 & 0x80) != 0) {
      bVar2 = true;
    }
  }
  if (!bVar2) {
    if (!bVar3) {
      return 0x13;
    }
    return 0x16;
  }
  return 0x14;
}

