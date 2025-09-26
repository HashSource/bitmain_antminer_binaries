
void do_err_strings_init_ossl_(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = OPENSSL_init_crypto(0,0,0,in_r3,in_r3);
  if ((iVar1 != 0) && (err_string_lock = CRYPTO_THREAD_lock_new(), err_string_lock != 0)) {
    int_error_hash = OPENSSL_LH_new(0x130d95,0x130dd1);
    if (int_error_hash != 0) {
      do_err_strings_init_ossl_ret_ = 1;
      return;
    }
    CRYPTO_THREAD_lock_free(err_string_lock);
    err_string_lock = 0;
    do_err_strings_init_ossl_ret_ = 0;
    return;
  }
  do_err_strings_init_ossl_ret_ = 0;
  return;
}

