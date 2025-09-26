
void ec_GFp_mont_group_clear_finish
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  BN_clear_free(*(BIGNUM **)(param_1 + 0x54));
  *(undefined4 *)(param_1 + 0x54) = 0;
  ec_GFp_simple_group_clear_finish(param_1,extraout_r1,extraout_r2,param_4);
  return;
}

