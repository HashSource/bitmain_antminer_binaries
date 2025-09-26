
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RAND_METHOD * RAND_get_rand_method(void)

{
  int iVar1;
  ENGINE *e;
  RAND_METHOD *pRVar2;
  
  iVar1 = CRYPTO_THREAD_run_once(&rand_init,0x155869);
  if (iVar1 == 0) {
    return (RAND_METHOD *)0x0;
  }
  pRVar2 = do_rand_init_ossl_ret_;
  if (do_rand_init_ossl_ret_ != (RAND_METHOD *)0x0) {
    CRYPTO_THREAD_write_lock(rand_meth_lock);
    e = funct_ref;
    pRVar2 = default_RAND_meth;
    if ((default_RAND_meth == (RAND_METHOD *)0x0) &&
       ((e = ENGINE_get_default_RAND(), e == (ENGINE *)0x0 ||
        (pRVar2 = ENGINE_get_RAND(e), pRVar2 == (RAND_METHOD *)0x0)))) {
      ENGINE_finish(e);
      default_RAND_meth = (RAND_METHOD *)&rand_meth;
      e = funct_ref;
      pRVar2 = default_RAND_meth;
    }
    default_RAND_meth = pRVar2;
    funct_ref = e;
    pRVar2 = default_RAND_meth;
    CRYPTO_THREAD_unlock(rand_meth_lock);
  }
  return pRVar2;
}

