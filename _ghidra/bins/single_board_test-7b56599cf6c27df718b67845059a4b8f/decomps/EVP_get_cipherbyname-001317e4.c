
EVP_CIPHER * EVP_get_cipherbyname(char *name)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  
  iVar1 = OPENSSL_init_crypto(4,0,0);
  if (iVar1 != 0) {
    pEVar2 = (EVP_CIPHER *)OBJ_NAME_get(name,2);
    return pEVar2;
  }
  return (EVP_CIPHER *)0x0;
}

