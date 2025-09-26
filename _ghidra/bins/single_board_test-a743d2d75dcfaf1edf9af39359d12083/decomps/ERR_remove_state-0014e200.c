
void ERR_remove_state(void)

{
  CRYPTO_THREADID aCStack_198 [50];
  
  CRYPTO_THREADID_current(aCStack_198);
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  (*(code *)err_fns[9])(aCStack_198);
  return;
}

