
void ec_GFp_simple_field_sqr(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BN_mod_sqr(param_2,param_3,(BIGNUM *)(param_1 + 0x48),param_4);
  return;
}

