
EVP_CIPHER * EVP_get_cipherbyname(char *name)

{
  EVP_CIPHER *pEVar1;
  
  pEVar1 = (EVP_CIPHER *)OBJ_NAME_get(name,2);
  return pEVar1;
}

