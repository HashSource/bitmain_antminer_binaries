
ASN1_STRING * ASN1_OCTET_STRING_dup(ASN1_STRING *a)

{
  ASN1_STRING *str;
  int iVar1;
  
  if (a == (ASN1_STRING *)0x0) {
    str = (ASN1_STRING *)0x0;
  }
  else {
    str = (ASN1_STRING *)CRYPTO_malloc(0x10,DAT_000bcf6c,0x19c);
    if (str == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0x82,0x41,DAT_000bcf6c,0x19e);
    }
    else {
      str->type = 4;
      iVar1 = a->type;
      str->length = 0;
      str->data = (uchar *)0x0;
      str->type = iVar1;
      str->flags = 0;
      iVar1 = ASN1_STRING_set(str,a->data,a->length);
      if (iVar1 == 0) {
        if ((str->data != (uchar *)0x0) && (-1 < str->flags << 0x1b)) {
          CRYPTO_free(str->data);
        }
        CRYPTO_free(str);
        str = (ASN1_STRING *)0x0;
      }
      else {
        str->flags = a->flags;
      }
    }
  }
  return str;
}

