
char * ERR_lib_error_string(ulong e)

{
  int iVar1;
  uint local_18 [2];
  
  iVar1 = CRYPTO_THREAD_run_once(&err_string_init,0x127211);
  if ((iVar1 != 0) && (do_err_strings_init_ossl_ret_ != 0)) {
    local_18[0] = e & 0xff000000;
    CRYPTO_THREAD_read_lock(err_string_lock);
    iVar1 = OPENSSL_LH_retrieve(int_error_hash,local_18);
    CRYPTO_THREAD_unlock(err_string_lock);
    if (iVar1 != 0) {
      return *(char **)(iVar1 + 4);
    }
  }
  return (char *)0x0;
}

