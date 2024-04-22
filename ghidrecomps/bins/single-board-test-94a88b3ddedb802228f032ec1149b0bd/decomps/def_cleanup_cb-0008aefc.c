
void def_cleanup_cb(void *param_1)

{
  sk_pop_free(*(_STACK **)((int)param_1 + 4),def_cleanup_util_cb + 1);
  CRYPTO_free(param_1);
  return;
}

