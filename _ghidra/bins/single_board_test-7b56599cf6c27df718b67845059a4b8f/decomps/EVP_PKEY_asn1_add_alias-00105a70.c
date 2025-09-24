
int EVP_PKEY_asn1_add_alias(int to,int from)

{
  EVP_PKEY_ASN1_METHOD *ameth;
  int iVar1;
  
  ameth = EVP_PKEY_asn1_new(from,1,(char *)0x0,(char *)0x0);
  if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  *(int *)(ameth + 4) = to;
  iVar1 = EVP_PKEY_asn1_add0(ameth);
  if (iVar1 != 0) {
    return 1;
  }
  EVP_PKEY_asn1_free(ameth);
  return 0;
}

