
void dh_bn_mod_exp(int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,
                  BN_CTX *param_6,BN_MONT_CTX *param_7)

{
  if ((param_3->top == 1) && (*(int *)(param_1 + 0x1c) << 0x1e < 0)) {
    BN_mod_exp_mont_word(param_2,*param_3->d,param_4,param_5,param_6,param_7);
    return;
  }
  BN_mod_exp_mont(param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

