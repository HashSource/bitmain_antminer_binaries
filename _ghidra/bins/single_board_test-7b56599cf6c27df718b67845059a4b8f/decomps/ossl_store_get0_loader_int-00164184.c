
int ossl_store_get0_loader_int(undefined4 param_1)

{
  int iVar1;
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  
  local_30 = 0;
  local_20 = 0;
  local_1c = 0;
  local_14 = 0;
  local_38[0] = param_1;
  iVar1 = ossl_store_init_once();
  if (iVar1 != 0) {
    iVar1 = CRYPTO_THREAD_run_once(&registry_init,0x163f41);
    if ((iVar1 == 0) || (do_registry_init_ossl_ret_ == 0)) {
      ERR_put_error(0x2c,100,0x41,"crypto/store/store_register.c",0xde);
      return 0;
    }
    CRYPTO_THREAD_write_lock(registry_lock);
    iVar1 = OPENSSL_LH_retrieve(loader_register,local_38);
    if (iVar1 == 0) {
      ERR_put_error(0x2c,100,0x69,"crypto/store/store_register.c",0xe7);
      ERR_add_error_data(2,"scheme=",param_1);
    }
    CRYPTO_THREAD_unlock(registry_lock);
  }
  return iVar1;
}

