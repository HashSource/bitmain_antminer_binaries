
undefined4 OPENSSL_init_crypto(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (stopped == 0) {
    iVar1 = CRYPTO_THREAD_run_once(&base,0x13f835);
    if ((iVar1 != 0) && (ossl_init_base_ossl_ret_ != 0)) {
      if ((param_1 & 0x40000) != 0) {
        return 1;
      }
      if ((param_1 & 0x80000) == 0) {
        iVar1 = CRYPTO_THREAD_run_once(&register_atexit,0x13f80d);
      }
      else {
        iVar1 = CRYPTO_THREAD_run_once(&register_atexit,0x13f6e9);
      }
      if ((((((((iVar1 != 0) && (ossl_init_register_atexit_ossl_ret_ != 0)) &&
              (iVar1 = CRYPTO_THREAD_run_once(&load_crypto_nodelete,0x13f6f9), iVar1 != 0)) &&
             (ossl_init_load_crypto_nodelete_ossl_ret_ != 0)) &&
            (((param_1 & 1) == 0 ||
             ((iVar1 = CRYPTO_THREAD_run_once(&load_crypto_strings,0x13f709), iVar1 != 0 &&
              (ossl_init_load_crypto_strings_ossl_ret_ != 0)))))) &&
           (((param_1 & 2) == 0 ||
            ((iVar1 = CRYPTO_THREAD_run_once(&load_crypto_strings,0x13f7f9), iVar1 != 0 &&
             (ossl_init_load_crypto_strings_ossl_ret_ != 0)))))) &&
          (((((param_1 & 0x10) == 0 ||
             ((iVar1 = CRYPTO_THREAD_run_once(&add_all_ciphers,0x13f719), iVar1 != 0 &&
              (ossl_init_add_all_ciphers_ossl_ret_ != 0)))) &&
            (((param_1 & 4) == 0 ||
             ((iVar1 = CRYPTO_THREAD_run_once(&add_all_ciphers,0x13f7e5), iVar1 != 0 &&
              (ossl_init_add_all_ciphers_ossl_ret_ != 0)))))) &&
           (((((param_1 & 0x20) == 0 ||
              ((iVar1 = CRYPTO_THREAD_run_once(&add_all_digests,0x13f729), iVar1 != 0 &&
               (ossl_init_add_all_digests_ossl_ret_ != 0)))) &&
             (((param_1 & 8) == 0 ||
              ((iVar1 = CRYPTO_THREAD_run_once(&add_all_digests,0x13f7d1), iVar1 != 0 &&
               (ossl_init_add_all_digests_ossl_ret_ != 0)))))) &&
            (((param_1 & 0x20000) == 0 || (iVar1 = openssl_init_fork_handlers(), iVar1 != 0))))))))
         && (((param_1 & 0x80) == 0 ||
             ((iVar1 = CRYPTO_THREAD_run_once(&config,0x13f7bd), iVar1 != 0 &&
              (ossl_init_config_ossl_ret_ != 0)))))) {
        if ((param_1 & 0x40) != 0) {
          CRYPTO_THREAD_write_lock(init_lock);
          conf_settings = param_3;
          conf_settings = CRYPTO_THREAD_run_once(&config,0x13f7a9);
          iVar1 = ossl_init_config_ossl_ret_;
          if (conf_settings == 0) {
            CRYPTO_THREAD_unlock(init_lock);
            return 0;
          }
          conf_settings = 0;
          CRYPTO_THREAD_unlock(init_lock);
          if (iVar1 < 1) {
            return 0;
          }
        }
        if ((((((param_1 & 0x100) == 0) ||
              ((iVar1 = CRYPTO_THREAD_run_once(&async,0x13f785), iVar1 != 0 &&
               (ossl_init_async_ossl_ret_ != 0)))) &&
             (((param_1 & 0x800) == 0 ||
              ((iVar1 = CRYPTO_THREAD_run_once(&engine_openssl,0x13f771), iVar1 != 0 &&
               (ossl_init_engine_openssl_ossl_ret_ != 0)))))) &&
            (((param_1 & 0x200) == 0 ||
             ((iVar1 = CRYPTO_THREAD_run_once(&engine_rdrand,0x13f75d), iVar1 != 0 &&
              (ossl_init_engine_rdrand_ossl_ret_ != 0)))))) &&
           (((param_1 & 0x400) == 0 ||
            ((iVar1 = CRYPTO_THREAD_run_once(&engine_dynamic,0x13f749), iVar1 != 0 &&
             (ossl_init_engine_dynamic_ossl_ret_ != 0)))))) {
          if ((param_1 & 0xfe00) != 0) {
            ENGINE_register_all_complete();
          }
          if ((param_1 & 0x10000) == 0) {
            return 1;
          }
          iVar1 = CRYPTO_THREAD_run_once(&zlib,0x13f739);
          if (iVar1 != 0) {
            if (ossl_init_zlib_ossl_ret_ != 0) {
              return 1;
            }
            return 0;
          }
        }
      }
    }
  }
  else if ((param_1 & 0x40000) == 0) {
    ERR_put_error(0xf,0x74,0x46,"crypto/init.c",0x267);
  }
  return 0;
}

