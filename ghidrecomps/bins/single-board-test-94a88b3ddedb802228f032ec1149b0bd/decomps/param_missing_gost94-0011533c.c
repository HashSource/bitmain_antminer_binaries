
int param_missing_gost94(EVP_PKEY *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  if (pvVar1 != (void *)0x0) {
    iVar2 = 1 - *(uint *)((int)pvVar1 + 0x10);
    if (1 < *(uint *)((int)pvVar1 + 0x10)) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 1;
}

