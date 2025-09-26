
void RSA_free(RSA *r)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  _func_1767 *p_Var4;
  
  if (r == (RSA *)0x0) {
    return;
  }
  piVar2 = &r->flags;
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
  if ((r->meth != (RSA_METHOD *)0x0) && (p_Var4 = r->meth->finish, p_Var4 != (_func_1767 *)0x0)) {
    (*p_Var4)(r);
  }
  ENGINE_finish(r->engine);
  CRYPTO_free_ex_data(9,r,(CRYPTO_EX_DATA *)&r->references);
  CRYPTO_THREAD_lock_free(r[1].version);
  BN_free(r->n);
  BN_free(r->e);
  BN_clear_free(r->d);
  BN_clear_free(r->p);
  BN_clear_free(r->q);
  BN_clear_free(r->dmp1);
  BN_clear_free(r->dmq1);
  BN_clear_free(r->iqmp);
  RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)(r->ex_data).dummy);
  OPENSSL_sk_pop_free((r->ex_data).sk,0x15a41d);
  BN_BLINDING_free(r->mt_blinding);
  BN_BLINDING_free((BN_BLINDING *)r[1].pad);
  CRYPTO_free(r->blinding);
  CRYPTO_free(r);
  return;
}

