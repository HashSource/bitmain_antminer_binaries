
void policy_cache_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    policy_data_free(*param_1);
    OPENSSL_sk_pop_free(param_1[1],(undefined *)0x1788cd);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

