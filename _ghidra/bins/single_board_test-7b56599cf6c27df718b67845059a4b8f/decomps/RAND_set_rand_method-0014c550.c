
int RAND_set_rand_method(RAND_METHOD *meth)

{
  int iVar1;
  
  iVar1 = CRYPTO_THREAD_run_once(&rand_init,0x14bc91);
  if ((iVar1 != 0) && (iVar1 = do_rand_init_ossl_ret_, do_rand_init_ossl_ret_ != 0)) {
    CRYPTO_THREAD_write_lock(rand_meth_lock);
    ENGINE_finish(funct_ref);
    funct_ref = (ENGINE *)0x0;
    default_RAND_meth = meth;
    CRYPTO_THREAD_unlock(rand_meth_lock);
    return 1;
  }
  return iVar1;
}

