
undefined4 ec_GFp_mont_field_encode(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    uVar1 = BN_to_montgomery(param_2,param_3,*(int *)(param_1 + 0x50));
    return uVar1;
  }
  ERR_put_error(0x10,0x86,0x6f,"crypto/ec/ecp_mont.c",0x106);
  return 0;
}

