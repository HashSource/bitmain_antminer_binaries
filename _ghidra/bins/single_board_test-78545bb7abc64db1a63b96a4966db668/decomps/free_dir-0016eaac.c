
void free_dir(int param_1)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(param_1 + 0xc);
  OPENSSL_sk_pop_free(ptr[1],0x16ea79);
  BUF_MEM_free((BUF_MEM *)*ptr);
  CRYPTO_THREAD_lock_free(ptr[2]);
  CRYPTO_free(ptr);
  return;
}

