
int ENGINE_finish(ENGINE *e)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    return 1;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  iVar1 = engine_unlocked_finish(e,1);
  CRYPTO_THREAD_unlock(global_engine_lock);
  if (iVar1 != 0) {
    return iVar1;
  }
  ERR_put_error(0x26,0x6b,0x6a,"crypto/engine/eng_init.c",0x69);
  return 0;
}

