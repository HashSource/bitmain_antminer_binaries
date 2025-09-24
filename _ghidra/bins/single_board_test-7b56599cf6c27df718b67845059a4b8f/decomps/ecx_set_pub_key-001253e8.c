
undefined4 ecx_set_pub_key(EVP_PKEY *param_1,void *param_2,size_t param_3)

{
  void *__dest;
  size_t sVar1;
  int type;
  
  type = *(int *)param_1->ameth;
  if (param_2 != (void *)0x0) {
    if (type == 0x40a || type == 0x43f) {
      if (param_3 == 0x20) goto LAB_0012543e;
    }
    else {
      if (type == 0x40b) {
        sVar1 = 0x38;
      }
      else {
        sVar1 = 0x39;
      }
      if (param_3 == sVar1) {
LAB_0012543e:
        __dest = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
        if (__dest == (void *)0x0) {
          ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
          return 0;
        }
        memcpy(__dest,param_2,param_3);
        EVP_PKEY_assign(param_1,type,__dest);
        return 1;
      }
    }
  }
  ERR_put_error(0x10,0x10a,0x66,"crypto/ec/ecx_meth.c",0x41);
  return 0;
}

