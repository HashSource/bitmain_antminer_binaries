
void ossl_init_base_ossl_(void)

{
  int iVar1;
  undefined4 local_14;
  
  iVar1 = CRYPTO_THREAD_init_local(&local_14,0x131b8d);
  if (iVar1 != 0) {
    iVar1 = CRYPTO_THREAD_lock_new();
    init_lock = iVar1;
    if (iVar1 == 0) {
      CRYPTO_THREAD_lock_free();
      init_lock = iVar1;
      CRYPTO_THREAD_cleanup_local(&local_14);
      iVar1 = 0;
    }
    else {
      OPENSSL_cpuid_setup();
      iVar1 = 1;
      destructor_key = local_14;
      base_inited = 1;
    }
  }
  ossl_init_base_ossl_ret_ = iVar1;
  return;
}

