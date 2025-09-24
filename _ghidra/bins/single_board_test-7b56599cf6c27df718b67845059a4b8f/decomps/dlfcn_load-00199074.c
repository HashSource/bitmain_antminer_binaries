
undefined4 dlfcn_load(DSO *param_1)

{
  char *ptr;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  ptr = DSO_convert_filename(param_1,(char *)0x0);
  piVar1 = __errno_location();
  iVar4 = *piVar1;
  if (ptr == (char *)0x0) {
    ERR_put_error(0x25,0x66,0x6f,"crypto/dso/dso_dlfcn.c",0x69);
  }
  else {
    if ((param_1->flags & 0x20U) == 0) {
      uVar3 = 2;
    }
    else {
      uVar3 = 0x102;
    }
    iVar2 = dlopen(ptr,uVar3);
    if (iVar2 != 0) {
      *piVar1 = iVar4;
      iVar4 = OPENSSL_sk_push(param_1->meth_data,iVar2);
      if (iVar4 == 0) {
        ERR_put_error(0x25,0x66,0x69,"crypto/dso/dso_dlfcn.c",0x80);
        CRYPTO_free(ptr);
        dlclose(iVar2);
        return 0;
      }
      param_1->filename = ptr;
      return 1;
    }
    ERR_put_error(0x25,0x66,0x67,"crypto/dso/dso_dlfcn.c",0x76);
    uVar3 = dlerror();
    ERR_add_error_data(4,"filename(",ptr,&DAT_002285e8,uVar3);
  }
  CRYPTO_free(ptr);
  return 0;
}

