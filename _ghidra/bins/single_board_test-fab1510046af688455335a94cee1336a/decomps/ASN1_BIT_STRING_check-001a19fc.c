
int ASN1_BIT_STRING_check(ASN1_BIT_STRING *a,uchar *flags,int flags_len)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (((a == (ASN1_BIT_STRING *)0x0) || (a->data == (uchar *)0x0)) || (a->length < 1)) {
    uVar2 = 1;
  }
  else {
    iVar3 = 0;
    do {
      bVar1 = 0xff;
      if (iVar3 < flags_len) {
        bVar1 = flags[iVar3];
      }
      if (iVar3 < flags_len) {
        bVar1 = ~bVar1;
      }
      uVar2 = (uint)((bVar1 & a->data[iVar3]) == 0);
    } while ((iVar3 + 1 != a->length) && (iVar3 = iVar3 + 1, uVar2 != 0));
  }
  return uVar2;
}

