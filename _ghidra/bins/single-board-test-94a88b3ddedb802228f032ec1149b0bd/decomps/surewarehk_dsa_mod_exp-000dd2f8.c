
int surewarehk_dsa_mod_exp
              (undefined4 param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  BIGNUM BStack_2c;
  
  BN_init(&BStack_2c);
  iVar1 = surewarehk_modexp_isra_2(param_2,param_3,param_4,param_7);
  if ((iVar1 == 0) ||
     (iVar1 = surewarehk_modexp_isra_2(&BStack_2c,param_5,param_6,param_7), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = BN_mod_mul(param_2,param_2,&BStack_2c,param_7,param_8);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  BN_free(&BStack_2c);
  return iVar1;
}

