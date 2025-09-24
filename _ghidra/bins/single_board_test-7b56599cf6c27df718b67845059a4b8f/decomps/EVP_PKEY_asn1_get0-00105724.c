
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_get0(int idx)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  
  if (idx < 0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  if (idx < 0x14) {
    return *(EVP_PKEY_ASN1_METHOD **)(&standard_methods + idx * 4);
  }
  pEVar1 = (EVP_PKEY_ASN1_METHOD *)OPENSSL_sk_value(app_methods,idx + -0x14);
  return pEVar1;
}

