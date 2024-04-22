
int EVP_PKEY_bits(EVP_PKEY *pkey)

{
  int iVar1;
  
  if (((pkey != (EVP_PKEY *)0x0) && (pkey = (EVP_PKEY *)pkey->ameth, pkey != (EVP_PKEY *)0x0)) &&
     (pkey = *(EVP_PKEY **)&((EVP_PKEY *)((int)pkey + 0x20))->pkey, pkey != (EVP_PKEY *)0x0)) {
    iVar1 = (*(code *)pkey)();
    return iVar1;
  }
  return (int)((rsa_st *)pkey).ptr;
}

