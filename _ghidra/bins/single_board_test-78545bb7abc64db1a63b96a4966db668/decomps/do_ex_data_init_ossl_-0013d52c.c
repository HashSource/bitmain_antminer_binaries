
void do_ex_data_init_ossl_(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = OPENSSL_init_crypto(0,0,0,in_r3,in_r3);
  if ((iVar1 != 0) &&
     (ex_data_lock = CRYPTO_THREAD_lock_new(), iVar1 = ex_data_lock, ex_data_lock != 0)) {
    iVar1 = 1;
  }
  do_ex_data_init_ossl_ret_ = iVar1;
  return;
}

