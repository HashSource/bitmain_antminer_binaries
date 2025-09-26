
void async_get_ctx(void)

{
  CRYPTO_THREAD_get_local(&ctxkey);
  return;
}

