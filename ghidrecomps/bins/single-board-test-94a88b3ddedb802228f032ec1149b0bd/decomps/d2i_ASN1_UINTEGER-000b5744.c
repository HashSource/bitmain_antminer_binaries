
ASN1_INTEGER * d2i_ASN1_UINTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  int iVar1;
  uchar *__dest;
  ASN1_STRING *a_00;
  uchar *local_28;
  size_t local_24;
  int local_20;
  int iStack_1c;
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    a_00->type = 2;
  }
  local_28 = *pp;
  iVar1 = ASN1_get_object(&local_28,(long *)&local_24,&local_20,&iStack_1c,length);
  if (iVar1 << 0x18 < 0) {
    iVar1 = 0x66;
  }
  else if (local_20 == 2) {
    __dest = (uchar *)CRYPTO_malloc(local_24 + 1,DAT_000b581c,0x13a);
    if (__dest != (uchar *)0x0) {
      a_00->type = 2;
      if (local_24 != 0) {
        if ((*local_28 == '\0') && (local_24 != 1)) {
          local_28 = local_28 + 1;
          local_24 = local_24 - 1;
        }
        memcpy(__dest,local_28,local_24);
        local_28 = local_28 + local_24;
      }
      if (a_00->data != (uchar *)0x0) {
        CRYPTO_free(a_00->data);
      }
      a_00->data = __dest;
      a_00->length = local_24;
      if (a != (ASN1_INTEGER **)0x0) {
        *a = a_00;
      }
      *pp = local_28;
      return a_00;
    }
    iVar1 = 0x41;
  }
  else {
    iVar1 = 0x73;
  }
  ERR_put_error(0xd,0x96,iVar1,DAT_000b581c,0x152);
  if ((a != (ASN1_INTEGER **)0x0) && (*a == a_00)) {
    return (ASN1_INTEGER *)0x0;
  }
  ASN1_STRING_free(a_00);
  return (ASN1_INTEGER *)0x0;
}

