
void policy_data_free(int *param_1)

{
  if (param_1 != (int *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)param_1[1]);
    if (-1 < *param_1 << 0x1d) {
      OPENSSL_sk_pop_free(param_1[2],0x17d9b1);
    }
    OPENSSL_sk_pop_free(param_1[3],(undefined *)0x18981d);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

