
ASN1_BIT_STRING * c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **pp,long length)

{
  uchar *__dest;
  int reason;
  ASN1_STRING *a_00;
  uint uVar1;
  size_t __n;
  byte *__src;
  
  if (length < 1) {
    ERR_put_error(0xd,0xbd,0x98,DAT_001053e8,0xb3);
    return (ASN1_BIT_STRING *)0x0;
  }
  if (((a != (ASN1_BIT_STRING **)0x0) && (a_00 = *a, a_00 != (ASN1_BIT_STRING *)0x0)) ||
     (a_00 = ASN1_STRING_type_new(3), a_00 != (ASN1_STRING *)0x0)) {
    uVar1 = (uint)**pp;
    if (uVar1 < 8) {
      __src = *pp + 1;
      __n = length - 1;
      a_00->flags = uVar1 | 8 | a_00->flags & 0xfffffff0U;
      if (length == 1) {
        __dest = (uchar *)0x0;
LAB_001053a2:
        a_00->length = __n;
        if (a_00->data != (uchar *)0x0) {
          CRYPTO_free(a_00->data);
        }
        a_00->data = __dest;
        a_00->type = 3;
        if (a != (ASN1_BIT_STRING **)0x0) {
          *a = a_00;
        }
        *pp = __src;
        return a_00;
      }
      __dest = (uchar *)CRYPTO_malloc(__n,DAT_001053e8,0x9e);
      if (__dest != (uchar *)0x0) {
        memcpy(__dest,__src,__n);
        __src = __src + __n;
        __dest[length + -2] = (byte)(0xff << uVar1) & __dest[length + -2];
        goto LAB_001053a2;
      }
      reason = 0x41;
    }
    else {
      reason = 0xdc;
    }
    ERR_put_error(0xd,0xbd,reason,DAT_001053e8,0xb3);
    if ((a == (ASN1_BIT_STRING **)0x0) || (a_00 != *a)) {
      ASN1_STRING_free(a_00);
      return (ASN1_BIT_STRING *)0x0;
    }
  }
  return (ASN1_BIT_STRING *)0x0;
}

