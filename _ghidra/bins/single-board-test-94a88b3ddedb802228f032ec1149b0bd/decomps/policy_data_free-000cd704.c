
void policy_data_free(int *param_1)

{
  ASN1_OBJECT_free((ASN1_OBJECT *)param_1[1]);
  if (-1 < *param_1 << 0x1d) {
    sk_pop_free((_STACK *)param_1[2],(func *)0xca54d);
  }
  sk_pop_free((_STACK *)param_1[3],ASN1_OBJECT_free);
  CRYPTO_free(param_1);
  return;
}

