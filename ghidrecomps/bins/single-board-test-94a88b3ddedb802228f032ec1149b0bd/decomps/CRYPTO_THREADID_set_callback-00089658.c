
int CRYPTO_THREADID_set_callback(threadid_func *threadid_func)

{
  if (*(int *)(DAT_00089668 + 0x18) != 0) {
    return 0;
  }
  *(threadid_func **)(DAT_00089668 + 0x18) = threadid_func;
  return 1;
}

