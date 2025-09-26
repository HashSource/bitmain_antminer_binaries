
undefined4 OPENSSL_sk_reserve(int *param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (-1 < param_2) {
    if (0x3fffffff - *param_1 < param_2) {
      return 0;
    }
    param_2 = *param_1 + param_2;
    if (param_2 < 4) {
      param_2 = 4;
    }
    if ((void *)param_1[1] == (void *)0x0) {
      iVar3 = CRYPTO_zalloc(param_2 << 2,"crypto/stack/stack.c",0xb4);
      param_1[1] = iVar3;
      if (iVar3 == 0) {
        ERR_put_error(0xf,0x81,0x41,"crypto/stack/stack.c",0xb5);
        uVar1 = 0;
      }
      else {
        param_1[3] = param_2;
        uVar1 = 1;
      }
    }
    else if (param_2 == param_1[3]) {
      uVar1 = 1;
    }
    else {
      pvVar2 = CRYPTO_realloc((void *)param_1[1],param_2 << 2,"crypto/stack/stack.c",0xc6);
      if (pvVar2 == (void *)0x0) {
        return 0;
      }
      param_1[1] = (int)pvVar2;
      uVar1 = 1;
      param_1[3] = param_2;
    }
    return uVar1;
  }
  return 1;
}

