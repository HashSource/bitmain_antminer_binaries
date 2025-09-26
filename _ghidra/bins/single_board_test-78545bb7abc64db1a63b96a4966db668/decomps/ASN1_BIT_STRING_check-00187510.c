
int ASN1_BIT_STRING_check(ASN1_BIT_STRING *a,uchar *flags,int flags_len)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 1;
  }
  if ((a->data != (uchar *)0x0) && (0 < a->length)) {
    pbVar3 = a->data + -1;
    iVar2 = 0;
    while( true ) {
      bVar1 = 0xff;
      if (iVar2 < flags_len) {
        bVar1 = flags[iVar2];
      }
      pbVar3 = pbVar3 + 1;
      if (iVar2 < flags_len) {
        bVar1 = ~bVar1;
      }
      if (iVar2 + 1 == a->length) break;
      iVar2 = iVar2 + 1;
      if ((bVar1 & *pbVar3) != 0) {
        return 0;
      }
    }
    return (uint)((bVar1 & *pbVar3) == 0);
  }
  return 1;
}

