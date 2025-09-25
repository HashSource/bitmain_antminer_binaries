
undefined4 SCT_set1_log_id(int *param_1,int param_2,int param_3)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 != 0x20 && *param_1 == 0) {
    ERR_put_error(0x32,0x73,100,"crypto/ct/ct_sct.c",0x61);
    return 0;
  }
  CRYPTO_free((void *)param_1[3]);
  param_1[3] = 0;
  param_1[4] = 0;
  uVar1 = extraout_r0;
  if (param_2 == 0 || param_3 == 0) {
    uVar1 = 1;
  }
  param_1[0xf] = 0;
  if (param_2 != 0 && param_3 != 0) {
    iVar2 = CRYPTO_memdup(param_2,param_3,"crypto/ct/ct_sct.c",0x6b);
    param_1[3] = iVar2;
    if (iVar2 != 0) {
      param_1[4] = param_3;
      return 1;
    }
    ERR_put_error(0x32,0x73,0x41,"crypto/ct/ct_sct.c",0x6d);
    uVar1 = 0;
  }
  return uVar1;
}

