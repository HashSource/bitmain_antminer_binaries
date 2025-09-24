
EVP_MD * EVP_get_digestbyname(char *name)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  iVar1 = OPENSSL_init_crypto(8,0,0);
  if (iVar1 != 0) {
    pEVar2 = (EVP_MD *)OBJ_NAME_get(name,1);
    return pEVar2;
  }
  return (EVP_MD *)0x0;
}

