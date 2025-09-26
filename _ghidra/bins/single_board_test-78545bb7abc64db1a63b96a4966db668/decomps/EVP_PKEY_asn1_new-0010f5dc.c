
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_new(int id,int flags,char *pem_str,char *info)

{
  EVP_PKEY_ASN1_METHOD *ameth;
  char *pcVar1;
  
  ameth = (EVP_PKEY_ASN1_METHOD *)CRYPTO_zalloc(0x90,"crypto/asn1/ameth_lib.c",0xdc,info,info);
  if (ameth != (EVP_PKEY_ASN1_METHOD *)0x0) {
    *(int *)ameth = id;
    *(uint *)(ameth + 8) = flags | 2;
    *(int *)(ameth + 4) = id;
    if (info != (char *)0x0) {
      pcVar1 = CRYPTO_strdup(info,"crypto/asn1/ameth_lib.c",0xe6);
      *(char **)(ameth + 0x10) = pcVar1;
      if (pcVar1 == (char *)0x0) goto LAB_0010f632;
    }
    if (pem_str != (char *)0x0) {
      pcVar1 = CRYPTO_strdup(pem_str,"crypto/asn1/ameth_lib.c",0xec);
      *(char **)(ameth + 0xc) = pcVar1;
      if (pcVar1 == (char *)0x0) {
LAB_0010f632:
        EVP_PKEY_asn1_free(ameth);
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
  }
  return ameth;
}

