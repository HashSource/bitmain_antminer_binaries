
int * OPENSSL_sk_dup(int *param_1)

{
  int *piVar1;
  void *__dest;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)CRYPTO_malloc(0x14,"crypto/stack/stack.c",0x31);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0xf,0x80,0x41,"crypto/stack/stack.c",0x32);
  }
  else {
    iVar2 = param_1[1];
    iVar3 = param_1[2];
    iVar4 = param_1[3];
    *piVar1 = *param_1;
    piVar1[1] = iVar2;
    piVar1[2] = iVar3;
    piVar1[3] = iVar4;
    iVar2 = *param_1;
    piVar1[4] = param_1[4];
    if (iVar2 == 0) {
      piVar1[1] = 0;
      piVar1[3] = 0;
    }
    else {
      __dest = CRYPTO_malloc(param_1[3] << 2,"crypto/stack/stack.c",0x40);
      piVar1[1] = (int)__dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,(void *)param_1[1],*param_1 << 2);
        return piVar1;
      }
      OPENSSL_sk_free(piVar1);
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}

