
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CONF_modules_finish(void)

{
  int *ptr;
  void *ptr_00;
  int iVar1;
  
  while( true ) {
    iVar1 = OPENSSL_sk_num(initialized_modules);
    if (iVar1 < 1) break;
    ptr = (int *)OPENSSL_sk_pop(initialized_modules);
    if (ptr != (int *)0x0) {
      iVar1 = *ptr;
      if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
        (**(code **)(iVar1 + 0xc))();
        iVar1 = *ptr;
      }
      ptr_00 = (void *)ptr[1];
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
      CRYPTO_free(ptr_00);
      CRYPTO_free((void *)ptr[2]);
      CRYPTO_free(ptr);
    }
  }
  OPENSSL_sk_free();
  initialized_modules = 0;
  return;
}

