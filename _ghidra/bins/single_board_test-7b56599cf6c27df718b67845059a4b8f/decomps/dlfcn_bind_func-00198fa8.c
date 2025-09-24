
int dlfcn_bind_func(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != 0 && param_1 != 0) {
    iVar2 = 0;
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 4));
    if (iVar1 < 1) {
      ERR_put_error(0x25,100,0x69,"crypto/dso/dso_dlfcn.c",0xb2);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 4);
      iVar2 = OPENSSL_sk_num(uVar3);
      iVar2 = OPENSSL_sk_value(uVar3,iVar2 + -1);
      if (iVar2 == 0) {
        ERR_put_error(0x25,100,0x68,"crypto/dso/dso_dlfcn.c",0xb7);
        iVar2 = 0;
      }
      else {
        iVar2 = dlsym(iVar2,param_2);
        if (iVar2 == 0) {
          ERR_put_error(0x25,100,0x6a,"crypto/dso/dso_dlfcn.c",0xbc);
          uVar3 = dlerror();
          ERR_add_error_data(4,"symname(",param_2,&DAT_002285e8,uVar3);
        }
      }
    }
    return iVar2;
  }
  ERR_put_error(0x25,100,0x43,"crypto/dso/dso_dlfcn.c",0xae);
  return 0;
}

