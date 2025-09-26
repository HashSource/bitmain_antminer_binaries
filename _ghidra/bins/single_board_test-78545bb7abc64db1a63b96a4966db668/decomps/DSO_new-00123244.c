
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO * DSO_new(void)

{
  DSO *dso;
  stack_st_void *psVar1;
  char *pcVar2;
  char *extraout_r2;
  DSO_MERGER_FUNC pDVar3;
  undefined8 uVar4;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)CRYPTO_zalloc(0x28,"crypto/dso/dso_lib.c",0x1b);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x1d);
  }
  else {
    psVar1 = (stack_st_void *)OPENSSL_sk_new_null();
    dso->meth_data = psVar1;
    if (psVar1 == (stack_st_void *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x23);
      CRYPTO_free(dso);
      dso = (DSO *)0x0;
    }
    else {
      dso->meth = default_DSO_meth;
      DataMemoryBarrier(0x1b);
      dso->references = 1;
      DataMemoryBarrier(0x1b);
      uVar4 = CRYPTO_THREAD_lock_new();
      dso->loaded_filename = (char *)uVar4;
      if ((char *)uVar4 == (char *)0x0) {
        ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x2b);
        OPENSSL_sk_free(dso->meth_data);
        CRYPTO_free(dso);
        dso = (DSO *)0x0;
      }
      else {
        pDVar3 = dso->meth->dso_merger;
        if ((pDVar3 != (DSO_MERGER_FUNC)0x0) &&
           (pcVar2 = (*pDVar3)(dso,(char *)((ulonglong)uVar4 >> 0x20),extraout_r2),
           pcVar2 == (char *)0x0)) {
          DSO_free(dso);
          dso = (DSO *)0x0;
        }
      }
    }
  }
  return dso;
}

