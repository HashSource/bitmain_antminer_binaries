
void def_cleanup_cb(void *param_1)

{
  sk_pop_free(*(_STACK **)((int)param_1 + 4),(func *)0x8ae85);
  CRYPTO_free(param_1);
  return;
}

