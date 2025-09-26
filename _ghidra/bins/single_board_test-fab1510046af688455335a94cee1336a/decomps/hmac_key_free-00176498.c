
void hmac_key_free(int param_1)

{
  ASN1_OCTET_STRING *a;
  
  a = *(ASN1_OCTET_STRING **)(param_1 + 0x14);
  if (a != (ASN1_OCTET_STRING *)0x0) {
    if (a->data != (uchar *)0x0) {
      OPENSSL_cleanse(a->data,a->length);
    }
    ASN1_OCTET_STRING_free(a);
    return;
  }
  return;
}

