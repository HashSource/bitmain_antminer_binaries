
undefined4 OPENSSL_init_ssl(uint param_1)

{
  int iVar1;
  
  if (stopped == 0) {
    if ((param_1 & 0x80) == 0) {
      param_1 = param_1 | 0x4c;
    }
    else {
      param_1 = param_1 | 0xc;
    }
    iVar1 = OPENSSL_init_crypto(param_1);
    if ((((iVar1 != 0) && (iVar1 = CRYPTO_THREAD_run_once(&ssl_base,0xdf431), iVar1 != 0)) &&
        (ossl_init_ssl_base_ossl_ret_ != 0)) &&
       (((param_1 & 0x100000) == 0 ||
        ((iVar1 = CRYPTO_THREAD_run_once(&ssl_strings,0xdf40d), iVar1 != 0 &&
         (ossl_init_load_ssl_strings_ossl_ret_ != 0)))))) {
      if ((param_1 & 0x200000) == 0) {
        return 1;
      }
      iVar1 = CRYPTO_THREAD_run_once(&ssl_strings,0xdf41d);
      if (iVar1 != 0) {
        if (ossl_init_load_ssl_strings_ossl_ret_ == 0) {
          return 0;
        }
        return 1;
      }
    }
  }
  else if (stoperrset_25253 == 0) {
    stoperrset_25253 = 1;
    ERR_put_error(0x14,0x156,0x46,"ssl/ssl_init.c",0xb2);
    return 0;
  }
  return 0;
}

