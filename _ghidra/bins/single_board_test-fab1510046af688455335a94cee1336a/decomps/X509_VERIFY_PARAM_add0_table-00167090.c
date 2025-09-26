
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)

{
  int iVar1;
  undefined4 *ptr;
  undefined4 *puVar2;
  
  if (param_table == (_STACK *)0x0) {
    param_table = sk_new((cmp *)0x16691d);
    if (param_table == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = sk_find(param_table,param);
    if (iVar1 != -1) {
      ptr = (undefined4 *)sk_value(param_table,iVar1);
      if (ptr != (undefined4 *)0x0) {
        *ptr = 0;
        ptr[4] = 0;
        ptr[5] = 0;
        ptr[2] = 0;
        ptr[3] = 0;
        ptr[6] = 0xffffffff;
        if ((_STACK *)ptr[7] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)ptr[7],(func *)0x158bd9);
          ptr[7] = 0;
        }
        puVar2 = (undefined4 *)ptr[8];
        if ((_STACK *)*puVar2 != (_STACK *)0x0) {
          sk_pop_free((_STACK *)*puVar2,(func *)0x166929);
          *puVar2 = 0;
        }
        if ((void *)puVar2[2] != (void *)0x0) {
          CRYPTO_free((void *)puVar2[2]);
        }
        if ((void *)puVar2[3] != (void *)0x0) {
          CRYPTO_free((void *)puVar2[3]);
          puVar2[3] = 0;
          puVar2[4] = 0;
        }
        if ((void *)puVar2[5] != (void *)0x0) {
          CRYPTO_free((void *)puVar2[5]);
          puVar2[5] = 0;
          puVar2[6] = 0;
        }
        CRYPTO_free((void *)ptr[8]);
        CRYPTO_free(ptr);
      }
      sk_delete(param_table,iVar1);
    }
  }
  iVar1 = sk_push(param_table,param);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

