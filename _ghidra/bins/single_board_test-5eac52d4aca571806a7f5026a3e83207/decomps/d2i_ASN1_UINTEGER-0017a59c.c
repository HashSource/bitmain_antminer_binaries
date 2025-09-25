
ASN1_INTEGER * d2i_ASN1_UINTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  int iVar1;
  uchar *__dest;
  ASN1_INTEGER *a_00;
  uchar *local_28;
  size_t local_24;
  int local_20;
  int aiStack_1c [2];
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_INTEGER_new();
    if (a_00 == (ASN1_INTEGER *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    local_28 = *pp;
    a_00->type = 2;
    iVar1 = ASN1_get_object(&local_28,(long *)&local_24,&local_20,aiStack_1c,length);
    if (iVar1 << 0x18 < 0) {
      iVar1 = 0x66;
    }
    else {
      if (local_20 == 2) goto LAB_0017a64a;
      iVar1 = 0x73;
    }
LAB_0017a632:
    ERR_put_error(0xd,0x96,iVar1,"crypto/asn1/a_int.c",0x1bb);
    if (a == (ASN1_INTEGER **)0x0) goto LAB_0017a5e2;
  }
  else {
    local_28 = *pp;
    iVar1 = ASN1_get_object(&local_28,(long *)&local_24,&local_20,aiStack_1c,length);
    if (iVar1 << 0x18 < 0) {
      ERR_put_error(0xd,0x96,0x66,"crypto/asn1/a_int.c",0x1bb);
    }
    else {
      if (local_20 == 2) {
LAB_0017a64a:
        __dest = (uchar *)CRYPTO_malloc(local_24 + 1,"crypto/asn1/a_int.c",0x1a4);
        if (__dest != (uchar *)0x0) {
          a_00->type = 2;
          if (local_24 != 0) {
            if (local_24 != 1 && *local_28 == '\0') {
              local_28 = local_28 + 1;
              local_24 = local_24 - 1;
            }
            memcpy(__dest,local_28,local_24);
            local_28 = local_28 + local_24;
          }
          CRYPTO_free(a_00->data);
          a_00->data = __dest;
          a_00->length = local_24;
          if (a != (ASN1_INTEGER **)0x0) {
            *a = a_00;
          }
          *pp = local_28;
          return a_00;
        }
        iVar1 = 0x41;
        goto LAB_0017a632;
      }
      ERR_put_error(0xd,0x96,0x73,"crypto/asn1/a_int.c",0x1bb);
    }
  }
  if (*a == a_00) {
    return (ASN1_INTEGER *)0x0;
  }
LAB_0017a5e2:
  ASN1_INTEGER_free(a_00);
  return (ASN1_INTEGER *)0x0;
}

