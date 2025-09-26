
void ASYNC_WAIT_CTX_free(undefined4 *param_1,undefined4 param_2,undefined4 param_3,
                        undefined4 param_4)

{
  undefined4 *ptr;
  undefined4 *puVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  ptr = (undefined4 *)*param_1;
  while (ptr != (undefined4 *)0x0) {
    if ((ptr[5] == 0) && ((code *)ptr[3] != (code *)0x0)) {
      (*(code *)ptr[3])(param_1,*ptr,ptr[1],ptr[2],param_4);
    }
    puVar1 = (undefined4 *)ptr[6];
    CRYPTO_free(ptr);
    ptr = puVar1;
  }
  CRYPTO_free(param_1);
  return;
}

