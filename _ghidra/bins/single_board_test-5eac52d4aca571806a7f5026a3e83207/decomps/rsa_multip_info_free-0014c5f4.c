
void rsa_multip_info_free(undefined4 *param_1)

{
  BN_clear_free((BIGNUM *)*param_1);
  BN_clear_free((BIGNUM *)param_1[1]);
  BN_clear_free((BIGNUM *)param_1[2]);
  rsa_multip_info_free_ex(param_1);
  return;
}

