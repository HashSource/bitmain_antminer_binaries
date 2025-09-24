
void do_rand_drbg_init_ossl_(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = OPENSSL_init_crypto(0,0,0);
  if ((iVar1 != 0) && (iVar1 = CRYPTO_THREAD_init_local(&private_drbg,0), iVar1 != 0)) {
    iVar1 = CRYPTO_THREAD_init_local(&public_drbg,0);
    if (iVar1 != 0) {
      iVar1 = RAND_DRBG_secure_new(rand_drbg_type,rand_drbg_flags,0);
      if (iVar1 != 0) {
        iVar2 = rand_drbg_enable_locking();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar1 + 0x50) = 1;
          DataMemoryBarrier(0x1b);
          *(undefined4 *)(iVar1 + 0x54) = 1;
          DataMemoryBarrier(0x1b);
          RAND_DRBG_instantiate(iVar1,"OpenSSL NIST SP 800-90A DRBG",0x1c);
          master_drbg = iVar1;
          do_rand_drbg_init_ossl_ret_ = 1;
          return;
        }
        RAND_DRBG_free(iVar1);
      }
      master_drbg = 0;
      CRYPTO_THREAD_cleanup_local(&public_drbg);
    }
    CRYPTO_THREAD_cleanup_local(&private_drbg);
  }
  do_rand_drbg_init_ossl_ret_ = 0;
  return;
}

