
void X509_STORE_lock(int param_1)

{
  CRYPTO_THREAD_write_lock(*(undefined4 *)(param_1 + 0x48));
  return;
}

