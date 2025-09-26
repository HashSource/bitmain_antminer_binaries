
undefined4 dlfcn_unload(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    ERR_put_error(0x25,0x67,0x43,"crypto/dso/dso_dlfcn.c",0x92);
    return 0;
  }
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 4));
  if (iVar1 < 1) {
    uVar2 = 1;
  }
  else {
    iVar1 = OPENSSL_sk_pop(*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      ERR_put_error(0x25,0x67,0x68,"crypto/dso/dso_dlfcn.c",0x99);
      OPENSSL_sk_push(*(undefined4 *)(param_1 + 4),0);
      uVar2 = 0;
    }
    else {
      dlclose();
      uVar2 = 1;
    }
  }
  return uVar2;
}

