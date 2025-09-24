
void RAND_keep_random_devices_open
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined8 uVar1;
  
  uVar1 = CRYPTO_THREAD_run_once(&rand_init,0x14bc91);
  if (((int)uVar1 != 0) && (do_rand_init_ossl_ret_ != 0)) {
    rand_pool_keep_random_devices_open(param_1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,param_4);
    return;
  }
  return;
}

