
int EVP_PKEY_size(EVP_PKEY *pkey)

{
  int iVar1;
  
  if (((pkey != (EVP_PKEY *)0x0) && (pkey = (EVP_PKEY *)pkey->ameth, pkey != (EVP_PKEY *)0x0)) &&
     (pkey = (EVP_PKEY *)pkey[1].engine, pkey != (EVP_PKEY *)0x0)) {
    iVar1 = (*(code *)pkey)();
    return iVar1;
  }
  return (int)pkey;
}

