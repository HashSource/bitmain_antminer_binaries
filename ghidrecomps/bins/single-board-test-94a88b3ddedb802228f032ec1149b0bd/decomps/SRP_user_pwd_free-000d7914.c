
void SRP_user_pwd_free(void **param_1)

{
  if (param_1 != (void **)0x0) {
    BN_free((BIGNUM *)param_1[1]);
    BN_clear_free((BIGNUM *)param_1[2]);
    CRYPTO_free(*param_1);
    CRYPTO_free(param_1[5]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

