
void CONF_modules_unload(int all)

{
  void *ptr;
  int iVar1;
  undefined4 *ptr_00;
  int *piVar2;
  bool bVar3;
  
  while (iVar1 = sk_num(initialized_modules), 0 < iVar1) {
    piVar2 = (int *)sk_pop(initialized_modules);
    iVar1 = *piVar2;
    if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
      (**(code **)(iVar1 + 0xc))();
      iVar1 = *piVar2;
    }
    ptr = (void *)piVar2[1];
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    CRYPTO_free(ptr);
    CRYPTO_free((void *)piVar2[2]);
    CRYPTO_free(piVar2);
  }
  sk_free(initialized_modules);
  initialized_modules = (_STACK *)0x0;
  iVar1 = sk_num(supported_modules);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    if (all == 0) {
      do {
        piVar2 = (int *)sk_value(supported_modules,iVar1);
        if ((piVar2[4] < 1) && (*piVar2 != 0)) {
          sk_delete(supported_modules,iVar1);
          if ((DSO *)*piVar2 != (DSO *)0x0) {
            DSO_free((DSO *)*piVar2);
          }
          CRYPTO_free((void *)piVar2[1]);
          CRYPTO_free(piVar2);
        }
        bVar3 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar3);
    }
    else {
      do {
        ptr_00 = (undefined4 *)sk_value(supported_modules,iVar1);
        sk_delete(supported_modules,iVar1);
        if ((DSO *)*ptr_00 != (DSO *)0x0) {
          DSO_free((DSO *)*ptr_00);
        }
        iVar1 = iVar1 + -1;
        CRYPTO_free((void *)ptr_00[1]);
        CRYPTO_free(ptr_00);
      } while (iVar1 != -1);
    }
  }
  iVar1 = sk_num(supported_modules);
  if (iVar1 == 0) {
    sk_free(supported_modules);
    supported_modules = (_STACK *)0x0;
  }
  return;
}

