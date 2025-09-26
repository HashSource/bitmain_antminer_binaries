
undefined4 err_shelve_state(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = __errno_location();
  iVar4 = *piVar1;
  iVar2 = OPENSSL_init_crypto(0x40000,0,0);
  if (((iVar2 != 0) && (iVar2 = CRYPTO_THREAD_run_once(&err_init,0x130e41), iVar2 != 0)) &&
     (err_do_init_ossl_ret_ != 0)) {
    uVar3 = CRYPTO_THREAD_get_local(&err_thread_local);
    *param_1 = uVar3;
    iVar2 = CRYPTO_THREAD_set_local(&err_thread_local,0xffffffff);
    if (iVar2 != 0) {
      *piVar1 = iVar4;
      return 1;
    }
  }
  return 0;
}

