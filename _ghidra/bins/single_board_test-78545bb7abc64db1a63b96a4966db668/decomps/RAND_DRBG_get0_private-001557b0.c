
int RAND_DRBG_get0_private
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CRYPTO_THREAD_run_once(&rand_drbg_init,0x1553ed,param_3,param_4,param_4);
  if ((iVar1 != 0) && (do_rand_drbg_init_ossl_ret_ != 0)) {
    iVar1 = CRYPTO_THREAD_get_local(&private_drbg);
    if (iVar1 == 0) {
      iVar1 = ossl_init_thread_start(4,0);
      iVar2 = master_drbg;
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = RAND_DRBG_secure_new(rand_drbg_type,rand_drbg_flags,master_drbg);
      if (iVar1 != 0) {
        if ((iVar2 == 0) && (iVar2 = rand_drbg_enable_locking(), iVar2 == 0)) {
          RAND_DRBG_free(iVar1);
          iVar1 = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 0x50) = 1;
          DataMemoryBarrier(0x1b);
          *(undefined4 *)(iVar1 + 0x54) = 1;
          DataMemoryBarrier(0x1b);
          RAND_DRBG_instantiate(iVar1,"OpenSSL NIST SP 800-90A DRBG",0x1c);
        }
      }
      CRYPTO_THREAD_set_local(&private_drbg,iVar1);
    }
    return iVar1;
  }
  return 0;
}

