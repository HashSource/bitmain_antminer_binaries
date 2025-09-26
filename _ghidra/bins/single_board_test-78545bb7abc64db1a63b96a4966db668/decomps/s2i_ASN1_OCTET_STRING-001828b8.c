
ASN1_OCTET_STRING * s2i_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,char *str)

{
  ASN1_OCTET_STRING *a;
  uchar *puVar1;
  int local_14 [2];
  
  a = ASN1_OCTET_STRING_new();
  if (a == (ASN1_OCTET_STRING *)0x0) {
    ERR_put_error(0x22,0x70,0x41,"crypto/x509v3/v3_skey.c",0x28);
  }
  else {
    puVar1 = (uchar *)OPENSSL_hexstr2buf(str,local_14);
    a->data = puVar1;
    if (puVar1 == (uchar *)0x0) {
      ASN1_OCTET_STRING_free(a);
      a = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      a->length = local_14[0];
    }
  }
  return a;
}

