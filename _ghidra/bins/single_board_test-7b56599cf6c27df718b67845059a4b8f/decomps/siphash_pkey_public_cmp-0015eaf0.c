
bool siphash_pkey_public_cmp(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  ASN1_STRING *a;
  ASN1_STRING *b;
  int iVar1;
  
  a = (ASN1_STRING *)EVP_PKEY_get0(param_1);
  b = (ASN1_STRING *)EVP_PKEY_get0(param_2);
  iVar1 = ASN1_OCTET_STRING_cmp(a,b);
  return iVar1 == 0;
}

