
void CRYPTO_secure_zalloc(void)

{
  if (secure_mem_initialized == 0) {
    CRYPTO_zalloc();
    return;
  }
  CRYPTO_secure_malloc();
  return;
}

