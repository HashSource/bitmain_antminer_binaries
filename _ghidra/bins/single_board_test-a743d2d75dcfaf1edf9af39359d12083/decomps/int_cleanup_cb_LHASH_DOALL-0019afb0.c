
void int_cleanup_cb_LHASH_DOALL(void *param_1)

{
  sk_free(*(_STACK **)((int)param_1 + 4));
  if (*(int *)((int)param_1 + 8) != 0) {
    engine_unlocked_finish(*(int *)((int)param_1 + 8),0);
  }
  CRYPTO_free(param_1);
  return;
}

