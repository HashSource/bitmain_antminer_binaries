
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_PKEY * EVP_PKEY_new(void)

{
  EVP_PKEY *ptr;
  int iVar1;
  
  ptr = (EVP_PKEY *)CRYPTO_zalloc(0x28,"crypto/evp/p_lib.c",0x8e);
  if (ptr == (EVP_PKEY *)0x0) {
    ERR_put_error(6,0x6a,0x41,"crypto/evp/p_lib.c",0x91);
  }
  else {
    ptr->type = 0;
    ptr->save_type = 0;
    DataMemoryBarrier(0x1b);
    ptr->references = 1;
    DataMemoryBarrier(0x1b);
    ptr->attributes = (stack_st_X509_ATTRIBUTE *)0x1;
    iVar1 = CRYPTO_THREAD_lock_new();
    ptr[1].save_type = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(6,0x6a,0x41,"crypto/evp/p_lib.c",0x9a);
      CRYPTO_free(ptr);
      ptr = (EVP_PKEY *)0x0;
    }
  }
  return ptr;
}

