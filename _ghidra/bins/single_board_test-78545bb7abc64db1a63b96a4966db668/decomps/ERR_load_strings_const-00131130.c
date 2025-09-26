
undefined4
ERR_load_strings_const(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r0;
  undefined4 extraout_r2;
  undefined4 uVar1;
  undefined4 extraout_r2_00;
  int iVar2;
  
  ERR_load_ERR_strings();
  if (extraout_r0 != 0) {
    CRYPTO_THREAD_write_lock(err_string_lock);
    iVar2 = *param_1;
    uVar1 = extraout_r2;
    while (iVar2 != 0) {
      OPENSSL_LH_insert(int_error_hash,param_1,uVar1,iVar2,param_4);
      param_1 = param_1 + 2;
      uVar1 = extraout_r2_00;
      iVar2 = *param_1;
    }
    CRYPTO_THREAD_unlock(err_string_lock);
    return 1;
  }
  return 0;
}

