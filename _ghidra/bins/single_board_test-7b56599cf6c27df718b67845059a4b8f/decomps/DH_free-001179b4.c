
void DH_free(DH *dh)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  
  if (dh == (DH *)0x0) {
    return;
  }
  piVar2 = &dh->references;
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  iVar3 = (dh->ex_data).dummy;
  if ((iVar3 != 0) && (pcVar4 = *(code **)(iVar3 + 0x14), pcVar4 != (code *)0x0)) {
    (*pcVar4)();
  }
  ENGINE_finish((ENGINE *)dh->meth);
  CRYPTO_free_ex_data(6,dh,&dh->ex_data);
  CRYPTO_THREAD_lock_free(dh->engine);
  BN_clear_free(dh->p);
  BN_clear_free(dh->g);
  BN_clear_free(dh->q);
  BN_clear_free(dh->j);
  CRYPTO_free(dh->seed);
  BN_clear_free(dh->counter);
  BN_clear_free(dh->pub_key);
  BN_clear_free(dh->priv_key);
  CRYPTO_free(dh);
  return;
}

