
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CONF_modules_finish(void)

{
  int iVar1;
  int *ptr;
  void *ptr_00;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000ceccc;
  while( true ) {
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    iVar3 = DAT_000ceccc;
    if (iVar2 < 1) break;
    ptr = (int *)sk_pop(*(_STACK **)(iVar1 + 4));
    iVar3 = *ptr;
    if (*(code **)(iVar3 + 0xc) != (code *)0x0) {
      (**(code **)(iVar3 + 0xc))();
      iVar3 = *ptr;
    }
    ptr_00 = (void *)ptr[1];
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;
    CRYPTO_free(ptr_00);
    CRYPTO_free((void *)ptr[2]);
    CRYPTO_free(ptr);
  }
  sk_free(*(_STACK **)(DAT_000ceccc + 4));
  *(undefined4 *)(iVar3 + 4) = 0;
  return;
}

