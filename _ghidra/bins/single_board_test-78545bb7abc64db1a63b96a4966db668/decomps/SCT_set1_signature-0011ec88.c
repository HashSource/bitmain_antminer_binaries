
undefined4 SCT_set1_signature(int param_1,int param_2,int param_3)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  int iVar2;
  
  CRYPTO_free(*(void **)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  uVar1 = extraout_r0;
  if (param_2 == 0 || param_3 == 0) {
    uVar1 = 1;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (param_2 != 0 && param_3 != 0) {
    iVar2 = CRYPTO_memdup(param_2,param_3,"crypto/ct/ct_sct.c",0xb9);
    *(int *)(param_1 + 0x2c) = iVar2;
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x30) = param_3;
      return 1;
    }
    ERR_put_error(0x32,0x74,0x41,"crypto/ct/ct_sct.c",0xbb);
    uVar1 = 0;
  }
  return uVar1;
}

