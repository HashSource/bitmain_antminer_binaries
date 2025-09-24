
void rsa_multip_info_free_ex(void *param_1)

{
  BN_clear_free(*(BIGNUM **)((int)param_1 + 0xc));
  CRYPTO_free(param_1);
  return;
}

