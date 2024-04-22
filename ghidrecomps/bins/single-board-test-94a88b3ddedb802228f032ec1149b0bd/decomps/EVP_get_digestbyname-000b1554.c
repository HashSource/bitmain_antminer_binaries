
EVP_MD * EVP_get_digestbyname(char *name)

{
  EVP_MD *pEVar1;
  
  pEVar1 = (EVP_MD *)OBJ_NAME_get(name,1);
  return pEVar1;
}

