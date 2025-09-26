
void siphash_key_free(EVP_PKEY *param_1)

{
  ASN1_STRING *a;
  
  a = (ASN1_STRING *)EVP_PKEY_get0(param_1);
  if (a != (ASN1_STRING *)0x0) {
    if (a->data != (uchar *)0x0) {
      OPENSSL_cleanse(a->data,a->length);
    }
    ASN1_OCTET_STRING_free(a);
    return;
  }
  return;
}

