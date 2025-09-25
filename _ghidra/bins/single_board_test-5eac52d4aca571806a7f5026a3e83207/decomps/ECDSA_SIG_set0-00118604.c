
undefined4 ECDSA_SIG_set0(int *param_1,int param_2,int param_3)

{
  if (param_3 == 0 || param_2 == 0) {
    return 0;
  }
  BN_clear_free((BIGNUM *)*param_1);
  BN_clear_free((BIGNUM *)param_1[1]);
  *param_1 = param_2;
  param_1[1] = param_3;
  return 1;
}

