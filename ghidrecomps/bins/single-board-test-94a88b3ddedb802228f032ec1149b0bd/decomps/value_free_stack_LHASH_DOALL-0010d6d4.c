
void value_free_stack_LHASH_DOALL(void **param_1)

{
  int iVar1;
  void *ptr;
  _STACK *p_Var2;
  
  if (param_1[1] != (void *)0x0) {
    return;
  }
  p_Var2 = (_STACK *)param_1[2];
  iVar1 = sk_num(p_Var2);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    do {
      ptr = sk_value(p_Var2,iVar1);
      CRYPTO_free(*(void **)((int)ptr + 8));
      iVar1 = iVar1 + -1;
      CRYPTO_free(*(void **)((int)ptr + 4));
      CRYPTO_free(ptr);
    } while (iVar1 != -1);
  }
  if (p_Var2 != (_STACK *)0x0) {
    sk_free(p_Var2);
  }
  CRYPTO_free(*param_1);
  CRYPTO_free(param_1);
  return;
}

