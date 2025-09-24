
void int_cleanup_cb_doall(void *param_1)

{
  if (param_1 != (void *)0x0) {
    OPENSSL_sk_free(*(undefined4 *)((int)param_1 + 4));
    if (*(int *)((int)param_1 + 8) != 0) {
      engine_unlocked_finish(*(int *)((int)param_1 + 8),0);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

