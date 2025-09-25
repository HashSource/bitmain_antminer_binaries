
void CRYPTO_secure_free(void *param_1)

{
  int iVar1;
  size_t len;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  iVar1 = CRYPTO_secure_allocated();
  if (iVar1 != 0) {
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    len = sh_actual_size(param_1);
    OPENSSL_cleanse(param_1,len);
    secure_mem_used = secure_mem_used - len;
    if ((DAT_00b25640 <= param_1) && (param_1 < (void *)(DAT_00b25644 + (int)DAT_00b25640))) {
      sh_free_part_4(param_1);
      CRYPTO_THREAD_unlock(sec_malloc_lock);
      return;
    }
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: WITHIN_ARENA(ptr)","crypto/mem_sec.c",0x25f);
  }
  CRYPTO_free(param_1);
  return;
}

