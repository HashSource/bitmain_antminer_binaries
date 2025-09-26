
ASN1_BIT_STRING * c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **pp,long length)

{
  uchar *__dest;
  int reason;
  ASN1_BIT_STRING *a_00;
  byte *pbVar1;
  uint uVar2;
  size_t __n;
  
  if (length < 1) {
    reason = 0x98;
    a_00 = (ASN1_BIT_STRING *)0x0;
LAB_001873dc:
    ERR_put_error(0xd,0xbd,reason,"crypto/asn1/a_bitstr.c",0x89);
    if (a == (ASN1_BIT_STRING **)0x0) goto LAB_001873b8;
  }
  else {
    if ((a == (ASN1_BIT_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_BIT_STRING *)0x0)) {
      a_00 = ASN1_BIT_STRING_new();
      if (a_00 == (ASN1_BIT_STRING *)0x0) {
        return (ASN1_BIT_STRING *)0x0;
      }
      pbVar1 = *pp;
      uVar2 = (uint)*pbVar1;
      if (uVar2 < 8) goto LAB_0018732a;
      reason = 0xdc;
      goto LAB_001873dc;
    }
    pbVar1 = *pp;
    uVar2 = (uint)*pbVar1;
    if (uVar2 < 8) {
LAB_0018732a:
      pbVar1 = pbVar1 + 1;
      __n = length - 1;
      a_00->flags = uVar2 | 8 | a_00->flags & 0xfffffff0U;
      if (length == 1) {
        __dest = (uchar *)0x0;
LAB_00187378:
        a_00->length = __n;
        CRYPTO_free(a_00->data);
        a_00->data = __dest;
        a_00->type = 3;
        if (a != (ASN1_BIT_STRING **)0x0) {
          *a = a_00;
        }
        *pp = pbVar1;
        return a_00;
      }
      __dest = (uchar *)CRYPTO_malloc(__n,"crypto/asn1/a_bitstr.c",0x75);
      if (__dest != (uchar *)0x0) {
        memcpy(__dest,pbVar1,__n);
        pbVar1 = pbVar1 + __n;
        __dest[length + -2] = (byte)(0xff << uVar2) & __dest[length + -2];
        goto LAB_00187378;
      }
      reason = 0x41;
      goto LAB_001873dc;
    }
    ERR_put_error(0xd,0xbd,0xdc,"crypto/asn1/a_bitstr.c",0x89);
  }
  if (*a == a_00) {
    return (ASN1_BIT_STRING *)0x0;
  }
LAB_001873b8:
  ASN1_BIT_STRING_free(a_00);
  return (ASN1_BIT_STRING *)0x0;
}

