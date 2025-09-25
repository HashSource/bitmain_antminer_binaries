
void dh_bn_mod_exp(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                  BIGNUM *param_5,BN_CTX *param_6,BN_MONT_CTX *param_7)

{
  BN_mod_exp_mont(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

