
void ERR_unload_strings(int lib,ERR_STRING_DATA *str)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CRYPTO_THREAD_run_once(&err_string_init,0x122fc1);
  if ((iVar1 != 0) && (do_err_strings_init_ossl_ret_ != 0)) {
    CRYPTO_THREAD_write_lock(err_string_lock);
    uVar2 = str->error;
    while (uVar2 != 0) {
      OPENSSL_LH_delete(int_error_hash,str);
      str = str + 1;
      uVar2 = str->error;
    }
    CRYPTO_THREAD_unlock(err_string_lock);
    return;
  }
  return;
}

