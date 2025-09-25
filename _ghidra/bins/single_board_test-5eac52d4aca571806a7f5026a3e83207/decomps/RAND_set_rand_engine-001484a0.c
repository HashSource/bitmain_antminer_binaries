
int RAND_set_rand_engine(ENGINE *engine)

{
  int iVar1;
  RAND_METHOD *meth;
  
  iVar1 = CRYPTO_THREAD_run_once(&rand_init,0x147a41);
  if ((iVar1 == 0) || (do_rand_init_ossl_ret_ == 0)) {
    return 0;
  }
  if (engine == (ENGINE *)0x0) {
    meth = (RAND_METHOD *)0x0;
  }
  else {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      return 0;
    }
    meth = ENGINE_get_RAND(engine);
    if (meth == (RAND_METHOD *)0x0) {
      ENGINE_finish(engine);
      return 0;
    }
  }
  CRYPTO_THREAD_write_lock(rand_engine_lock);
  RAND_set_rand_method(meth);
  funct_ref = engine;
  CRYPTO_THREAD_unlock(rand_engine_lock);
  return 1;
}

