
void err_unshelve_state(int param_1)

{
  if (param_1 != -1) {
    CRYPTO_THREAD_set_local(&err_thread_local,param_1);
    return;
  }
  return;
}

