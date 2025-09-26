
void def_cleanup_cb(void *param_1)

{
  sk_pop_free(*(_STACK **)((int)param_1 + 4),(func *)0x1368dd);
  CRYPTO_free(param_1);
  return;
}

