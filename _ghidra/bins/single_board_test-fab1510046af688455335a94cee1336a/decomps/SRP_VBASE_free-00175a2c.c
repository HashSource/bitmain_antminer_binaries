
undefined4 SRP_VBASE_free(undefined4 *param_1)

{
  sk_pop_free((_STACK *)*param_1,(func *)0x1756d9);
  sk_free((_STACK *)param_1[1]);
  CRYPTO_free((void *)param_1[2]);
  CRYPTO_free(param_1);
  return 0;
}

