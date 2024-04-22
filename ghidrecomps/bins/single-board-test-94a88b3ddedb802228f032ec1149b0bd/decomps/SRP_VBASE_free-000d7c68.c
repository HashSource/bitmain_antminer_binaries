
undefined4 SRP_VBASE_free(_STACK **param_1)

{
  sk_pop_free(*param_1,SRP_user_pwd_free + 1);
  sk_free(param_1[1]);
  CRYPTO_free(param_1[2]);
  CRYPTO_free(param_1);
  return 0;
}

