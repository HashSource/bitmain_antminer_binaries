
void value_free_stack_doall(undefined4 *param_1)

{
  int iVar1;
  void *ptr;
  undefined4 uVar2;
  
  if (param_1[1] != 0) {
    return;
  }
  uVar2 = param_1[2];
  iVar1 = OPENSSL_sk_num(uVar2);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    do {
      ptr = (void *)OPENSSL_sk_value(uVar2,iVar1);
      CRYPTO_free(*(void **)((int)ptr + 8));
      iVar1 = iVar1 + -1;
      CRYPTO_free(*(void **)((int)ptr + 4));
      CRYPTO_free(ptr);
    } while (iVar1 != -1);
  }
  OPENSSL_sk_free(uVar2);
  CRYPTO_free((void *)*param_1);
  CRYPTO_free(param_1);
  return;
}

