
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  
  pEVar2 = pkey->ameth;
  if ((pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pEVar2 = *(EVP_PKEY_ASN1_METHOD **)(pEVar2 + 0x40), pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
    iVar1 = (*(code *)pEVar2)();
    return iVar1;
  }
  return (int)pEVar2;
}

