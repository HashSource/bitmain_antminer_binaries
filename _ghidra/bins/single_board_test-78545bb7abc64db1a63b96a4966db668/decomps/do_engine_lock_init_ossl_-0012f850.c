
void do_engine_lock_init_ossl_(void)

{
  int iVar1;
  
  iVar1 = OPENSSL_init_crypto(0,0,0);
  if ((iVar1 != 0) &&
     (global_engine_lock = CRYPTO_THREAD_lock_new(), iVar1 = global_engine_lock,
     global_engine_lock != 0)) {
    iVar1 = 1;
  }
  do_engine_lock_init_ossl_ret_ = iVar1;
  return;
}

