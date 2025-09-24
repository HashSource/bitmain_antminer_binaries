
undefined4 sm2_plaintext_size(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_14 [2];
  
  local_14[0] = param_1;
  iVar1 = d2i_SM2_Ciphertext(0,local_14,param_2);
  if (iVar1 != 0) {
    *param_3 = **(undefined4 **)(iVar1 + 0xc);
    SM2_Ciphertext_free();
    return 1;
  }
  ERR_put_error(0x35,0x68,0x68,"crypto/sm2/sm2_crypt.c",0x47);
  return 0;
}

