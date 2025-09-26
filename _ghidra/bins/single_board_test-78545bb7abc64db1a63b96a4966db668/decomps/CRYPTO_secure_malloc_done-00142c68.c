
undefined4 CRYPTO_secure_malloc_done(void)

{
  if (secure_mem_used != 0) {
    return 0;
  }
  CRYPTO_free(DAT_021b88e8);
  CRYPTO_free(DAT_021b88f4);
  CRYPTO_free(DAT_021b88f8);
  if ((sh != (void *)0xffffffff) && (DAT_021b88dc != 0)) {
    munmap(sh,DAT_021b88dc);
  }
  memset(&sh,0,0x28);
  secure_mem_initialized = 0;
  CRYPTO_THREAD_lock_free(sec_malloc_lock);
  sec_malloc_lock = 0;
  return 1;
}

