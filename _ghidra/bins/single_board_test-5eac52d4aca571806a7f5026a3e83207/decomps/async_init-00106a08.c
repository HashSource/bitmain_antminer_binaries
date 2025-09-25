
undefined4 async_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = CRYPTO_THREAD_init_local(&ctxkey,0,param_3,param_4,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = CRYPTO_THREAD_init_local(&poolkey,0);
  if (iVar1 != 0) {
    return 1;
  }
  CRYPTO_THREAD_cleanup_local(&ctxkey);
  return 0;
}

