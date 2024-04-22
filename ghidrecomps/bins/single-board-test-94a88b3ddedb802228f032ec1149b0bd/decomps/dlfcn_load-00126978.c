
undefined4 dlfcn_load(DSO *param_1)

{
  char *ptr;
  void *data;
  int iVar1;
  undefined4 uVar2;
  
  ptr = DSO_convert_filename(param_1,(char *)0x0);
  if (ptr == (char *)0x0) {
    ERR_put_error(0x25,0x66,0x6f,DAT_00126a14,0xb2);
    uVar2 = 0;
  }
  else {
    if ((param_1->flags & 0x20U) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0x102;
    }
    data = (void *)dlopen(ptr,uVar2);
    if (data == (void *)0x0) {
      ERR_put_error(0x25,0x66,0x67,DAT_00126a14,0xbb);
      uVar2 = dlerror();
      ERR_add_error_data(4,DAT_00126a18,ptr,DAT_00126a1c,uVar2);
      CRYPTO_free(ptr);
      uVar2 = 0;
    }
    else {
      iVar1 = sk_push(&param_1->meth_data->stack,data);
      if (iVar1 == 0) {
        ERR_put_error(0x25,0x66,0x69,DAT_00126a14,0xc0);
        CRYPTO_free(ptr);
        dlclose(data);
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
        param_1->loaded_filename = ptr;
      }
    }
  }
  return uVar2;
}

