
undefined4 ecx_ctrl(EVP_PKEY *param_1,int param_2,size_t param_3,int *param_4)

{
  void *__dest;
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  
  if (param_2 == 9) {
    iVar1 = *(int *)param_1->ameth;
    if (param_4 != (int *)0x0) {
      if (iVar1 == 0x40a || iVar1 == 0x43f) {
        sVar3 = 0x20;
      }
      else if (iVar1 == 0x40b) {
        sVar3 = 0x38;
      }
      else {
        sVar3 = 0x39;
      }
      if (param_3 == sVar3) {
        __dest = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
        if (__dest == (void *)0x0) {
          ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
          return 0;
        }
        memcpy(__dest,param_4,param_3);
        EVP_PKEY_assign(param_1,iVar1,__dest);
        return 1;
      }
    }
    ERR_put_error(0x10,0x10a,0x66,"crypto/ec/ecx_meth.c",0x41);
    return 0;
  }
  if (param_2 == 10) {
    if (param_1->save_parameters != 0) {
      iVar1 = *(int *)param_1->ameth;
      if (iVar1 == 0x40a || iVar1 == 0x43f) {
        uVar2 = 0x20;
      }
      else if (iVar1 == 0x40b) {
        uVar2 = 0x38;
      }
      else {
        uVar2 = 0x39;
      }
      iVar1 = CRYPTO_memdup(param_1->save_parameters,uVar2,"crypto/ec/ecx_meth.c",0x149);
      *param_4 = iVar1;
      if (iVar1 != 0) {
        iVar1 = *(int *)param_1->ameth;
        if (iVar1 == 0x40a || iVar1 == 0x43f) {
          return 0x20;
        }
        if (iVar1 != 0x40b) {
          return 0x39;
        }
        return 0x38;
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

