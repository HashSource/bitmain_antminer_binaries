
int ENGINE_init(ENGINE *e)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x77,0x43,"crypto/engine/eng_init.c",0x51);
    return 0;
  }
  iVar1 = CRYPTO_THREAD_run_once(&engine_lock_init,0x121a29);
  if ((iVar1 != 0) && (do_engine_lock_init_ossl_ret_ != 0)) {
    CRYPTO_THREAD_write_lock(global_engine_lock);
    iVar1 = engine_unlocked_init(e);
    CRYPTO_THREAD_unlock(global_engine_lock);
    return iVar1;
  }
  ERR_put_error(0x26,0x77,0x41,"crypto/engine/eng_init.c",0x55);
  return 0;
}

