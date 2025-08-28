
int CRYPTO_THREADID_set_callback(threadid_func *threadid_func)

{
  if (threadid_callback != (threadid_func *)0x0) {
    return 0;
  }
  threadid_callback = threadid_func;
  return 1;
}

