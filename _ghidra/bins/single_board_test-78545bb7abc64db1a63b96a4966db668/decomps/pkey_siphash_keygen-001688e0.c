
int pkey_siphash_keygen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  
  pAVar1 = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_1);
  iVar2 = ASN1_STRING_get0_data();
  if ((iVar2 != 0) && (pAVar1 = ASN1_OCTET_STRING_dup(pAVar1), pAVar1 != (ASN1_STRING *)0x0)) {
    iVar2 = EVP_PKEY_assign(param_2,0x426,pAVar1);
    return iVar2;
  }
  return 0;
}

