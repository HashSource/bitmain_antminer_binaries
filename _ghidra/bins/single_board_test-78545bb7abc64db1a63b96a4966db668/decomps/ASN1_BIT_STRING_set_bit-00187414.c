
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a,int n,int value)

{
  uchar uVar1;
  uchar *puVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  
  bVar5 = (byte)(1 << (~n & 7U));
  uVar3 = n & ~(n >> 0x20);
  if (n < 0) {
    uVar3 = n + 7;
  }
  bVar6 = bVar5;
  if (value == 0) {
    bVar6 = 0;
  }
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  iVar4 = (int)uVar3 >> 3;
  a->flags = a->flags & 0xfffffff0;
  if ((a->length <= iVar4) || (puVar2 = a->data, puVar2 == (uchar *)0x0)) {
    if (value == 0) {
      return 1;
    }
    iVar7 = iVar4 + 1;
    puVar2 = (uchar *)CRYPTO_clear_realloc(a->data,a->length,iVar7,"crypto/asn1/a_bitstr.c",0xa5);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xb7,0x41,"crypto/asn1/a_bitstr.c",0xa7);
      return 0;
    }
    __n = iVar7 - a->length;
    if (0 < (int)__n) {
      memset(puVar2 + a->length,0,__n);
    }
    a->data = puVar2;
    a->length = iVar7;
  }
  puVar2[iVar4] = bVar6 | puVar2[iVar4] & ~bVar5;
  if (0 < a->length) {
    iVar4 = a->length + -1;
    uVar1 = a->data[iVar4];
    puVar2 = a->data + iVar4;
    for (; (uVar1 == '\0' && (a->length = iVar4, iVar4 != 0)); iVar4 = iVar4 + -1) {
      puVar2 = puVar2 + -1;
      uVar1 = *puVar2;
    }
  }
  return 1;
}

