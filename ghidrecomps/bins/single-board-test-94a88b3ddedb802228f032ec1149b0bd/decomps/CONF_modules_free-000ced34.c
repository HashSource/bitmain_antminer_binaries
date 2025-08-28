
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CONF_modules_free(void)

{
  int *ptr;
  void *ptr_00;
  int iVar1;
  
  while (iVar1 = sk_num(initialized_modules), 0 < iVar1) {
    ptr = (int *)sk_pop(initialized_modules);
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
  sk_free(initialized_modules);
  initialized_modules = (_STACK *)0x0;
  CONF_modules_unload(1);
  return;
}

