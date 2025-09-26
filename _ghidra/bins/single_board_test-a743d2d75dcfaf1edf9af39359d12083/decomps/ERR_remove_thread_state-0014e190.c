
void ERR_remove_thread_state(CRYPTO_THREADID *tid)

{
  CRYPTO_THREADID aCStack_1a0 [50];
  
  if (tid == (CRYPTO_THREADID *)0x0) {
    CRYPTO_THREADID_current(aCStack_1a0);
  }
  else {
    CRYPTO_THREADID_cpy(aCStack_1a0,tid);
  }
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  (*(code *)err_fns[9])(aCStack_1a0);
  return;
}

