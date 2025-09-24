
void CTLOG_STORE_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    OPENSSL_sk_pop_free(*param_1,0x114199);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

