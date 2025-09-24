
void OPENSSL_LH_free(int *param_1)

{
  void *ptr;
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = param_1[3];
    pvVar2 = (void *)*param_1;
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        ptr = *(void **)((int)pvVar2 + uVar3 * 4);
        if (ptr != (void *)0x0) {
          do {
            pvVar2 = *(void **)((int)ptr + 4);
            CRYPTO_free(ptr);
            ptr = pvVar2;
          } while (pvVar2 != (void *)0x0);
          uVar1 = param_1[3];
          pvVar2 = (void *)*param_1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    CRYPTO_free(pvVar2);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

