
void async_deinit(void)

{
  CRYPTO_THREAD_cleanup_local(&ctxkey);
  CRYPTO_THREAD_cleanup_local(&poolkey);
  return;
}

