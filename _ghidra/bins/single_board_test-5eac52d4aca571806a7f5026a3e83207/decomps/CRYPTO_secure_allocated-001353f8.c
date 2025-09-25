
undefined4 CRYPTO_secure_allocated(uint param_1)

{
  undefined4 uVar1;
  
  if (secure_mem_initialized != 0) {
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    if (param_1 < DAT_00b25640) {
      uVar1 = 0;
    }
    else if (param_1 < DAT_00b25644 + DAT_00b25640) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    CRYPTO_THREAD_unlock(sec_malloc_lock);
    return uVar1;
  }
  return 0;
}

