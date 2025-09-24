
int DSO_free(DSO *dso)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  DSO_METHOD *pDVar4;
  
  piVar2 = &dso->references;
  if (dso == (DSO *)0x0) {
LAB_001195d0:
    iVar3 = 1;
  }
  else {
    do {
      ExclusiveAccess(piVar2);
      iVar3 = *piVar2;
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = iVar3 + -1;
    if (iVar3 == 1) {
      DataMemoryBarrier(0x1b);
    }
    else if (0 < iVar3 + -1) goto LAB_001195d0;
    pDVar4 = dso->meth;
    if (((dso->flags & 4U) == 0) && (pDVar4->dso_unload != (_func_3875 *)0x0)) {
      iVar3 = (*pDVar4->dso_unload)(dso);
      if (iVar3 == 0) {
        ERR_put_error(0x25,0x6f,0x6b,"crypto/dso/dso_lib.c",0x4f);
        return 0;
      }
      pDVar4 = dso->meth;
    }
    if ((pDVar4->init == (_func_3879 *)0x0) || (iVar3 = (*pDVar4->init)(dso), iVar3 != 0)) {
      OPENSSL_sk_free(dso->meth_data);
      CRYPTO_free(dso->merger);
      CRYPTO_free(dso->filename);
      CRYPTO_THREAD_lock_free(dso->loaded_filename);
      CRYPTO_free(dso);
      return 1;
    }
    ERR_put_error(0x25,0x6f,0x66,"crypto/dso/dso_lib.c",0x55);
    iVar3 = 0;
  }
  return iVar3;
}

