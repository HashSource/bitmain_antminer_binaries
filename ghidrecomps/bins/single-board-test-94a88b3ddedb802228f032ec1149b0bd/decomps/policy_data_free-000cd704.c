
void policy_data_free(int *param_1)

{
  ASN1_OBJECT_free((ASN1_OBJECT *)param_1[1]);
  if (-1 < *param_1 << 0x1d) {
    sk_pop_free((_STACK *)param_1[2],DAT_000cd730);
  }
  sk_pop_free((_STACK *)param_1[3],DAT_000cd734);
  CRYPTO_free(param_1);
  return;
}

