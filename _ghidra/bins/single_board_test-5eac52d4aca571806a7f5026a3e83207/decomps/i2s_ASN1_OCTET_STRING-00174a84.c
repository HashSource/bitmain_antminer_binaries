
char * i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,ASN1_OCTET_STRING *ia5)

{
  char *pcVar1;
  
  pcVar1 = (char *)OPENSSL_buf2hexstr(ia5->data,ia5->length);
  return pcVar1;
}

