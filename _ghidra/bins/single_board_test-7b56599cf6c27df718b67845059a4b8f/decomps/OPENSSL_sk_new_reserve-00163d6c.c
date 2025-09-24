
int * OPENSSL_sk_new_reserve(int param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  piVar1 = (int *)CRYPTO_zalloc(0x14,"crypto/stack/stack.c",0xd1);
  if ((piVar1 != (int *)0x0) && (piVar1[4] = param_1, 0 < param_2)) {
    if (0x3fffffff - *piVar1 < param_2) {
LAB_00163de4:
      OPENSSL_sk_free(piVar1);
      return (int *)0x0;
    }
    param_2 = *piVar1 + param_2;
    if (param_2 < 4) {
      param_2 = 4;
    }
    if ((void *)piVar1[1] == (void *)0x0) {
      iVar3 = CRYPTO_zalloc(param_2 << 2,"crypto/stack/stack.c",0xb4);
      piVar1[1] = iVar3;
      if (iVar3 == 0) {
        ERR_put_error(0xf,0x81,0x41,"crypto/stack/stack.c",0xb5);
        goto LAB_00163de4;
      }
    }
    else {
      if (param_2 == piVar1[3]) {
        return piVar1;
      }
      pvVar2 = CRYPTO_realloc((void *)piVar1[1],param_2 << 2,"crypto/stack/stack.c",0xc6);
      if (pvVar2 == (void *)0x0) goto LAB_00163de4;
      piVar1[1] = (int)pvVar2;
    }
    piVar1[3] = param_2;
  }
  return piVar1;
}

