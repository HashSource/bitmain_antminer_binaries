
undefined4 CRYPTO_secure_malloc_done(void)

{
  if (secure_mem_used != 0) {
    return 0;
  }
  CRYPTO_free(DAT_00a27fd4);
  CRYPTO_free(DAT_00a27fe0);
  CRYPTO_free(DAT_00a27fe4);
  if ((sh != (void *)0xffffffff) && (DAT_00a27fc8 != 0)) {
    munmap(sh,DAT_00a27fc8);
  }
  memset(&sh,0,0x28);
  secure_mem_initialized = 0;
  CRYPTO_THREAD_lock_free(sec_malloc_lock);
  sec_malloc_lock = 0;
  return 1;
}

