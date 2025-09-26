
void by_dir_entry_free(undefined4 *param_1)

{
  CRYPTO_free((void *)*param_1);
  OPENSSL_sk_pop_free(param_1[2],0x16e679);
  CRYPTO_free(param_1);
  return;
}

