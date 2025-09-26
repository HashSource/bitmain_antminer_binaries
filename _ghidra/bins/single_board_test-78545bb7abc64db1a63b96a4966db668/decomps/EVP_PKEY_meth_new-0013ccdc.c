
EVP_PKEY_METHOD * EVP_PKEY_meth_new(int id,int flags)

{
  EVP_PKEY_METHOD *pEVar1;
  
  pEVar1 = (EVP_PKEY_METHOD *)CRYPTO_zalloc(0x84,"crypto/evp/pmeth_lib.c",0xae);
  if (pEVar1 == (EVP_PKEY_METHOD *)0x0) {
    ERR_put_error(6,0xc3,0x41,"crypto/evp/pmeth_lib.c",0xb0);
  }
  else {
    *(int *)pEVar1 = id;
    *(uint *)(pEVar1 + 4) = flags | 1;
  }
  return pEVar1;
}

