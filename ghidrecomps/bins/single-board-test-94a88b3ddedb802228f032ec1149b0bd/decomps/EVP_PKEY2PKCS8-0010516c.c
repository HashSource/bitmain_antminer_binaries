
PKCS8_PRIV_KEY_INFO * EVP_PKEY2PKCS8(EVP_PKEY *pkey)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = EVP_PKEY2PKCS8_broken(pkey,0);
  return pPVar1;
}

