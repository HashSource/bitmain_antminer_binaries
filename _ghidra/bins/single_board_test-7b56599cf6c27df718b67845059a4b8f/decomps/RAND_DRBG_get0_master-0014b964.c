
int RAND_DRBG_get0_master(void)

{
  int iVar1;
  
  iVar1 = CRYPTO_THREAD_run_once(&rand_drbg_init,0x14b815);
  if ((iVar1 != 0) && (iVar1 = do_rand_drbg_init_ossl_ret_, do_rand_drbg_init_ossl_ret_ != 0)) {
    iVar1 = master_drbg;
  }
  return iVar1;
}

