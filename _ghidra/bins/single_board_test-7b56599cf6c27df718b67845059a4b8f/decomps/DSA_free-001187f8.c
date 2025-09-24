
void DSA_free(DSA *r)

{
  bool bVar1;
  BIGNUM **ppBVar2;
  BIGNUM *pBVar3;
  code *pcVar4;
  
  if (r == (DSA *)0x0) {
    return;
  }
  ppBVar2 = &r->r;
  do {
    ExclusiveAccess(ppBVar2);
    pBVar3 = *ppBVar2;
    bVar1 = (bool)hasExclusiveAccess(ppBVar2);
  } while (!bVar1);
  *ppBVar2 = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
  if (pBVar3 == (BIGNUM *)0x1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < (int)((int)&pBVar3[-1].flags + 3)) {
    return;
  }
  if ((r->method_mont_p != (BN_MONT_CTX *)0x0) &&
     (pcVar4 = (code *)(r->method_mont_p->N).top, pcVar4 != (code *)0x0)) {
    (*pcVar4)();
  }
  ENGINE_finish((ENGINE *)r->references);
  CRYPTO_free_ex_data(7,r,(CRYPTO_EX_DATA *)&r->flags);
  CRYPTO_THREAD_lock_free((r->ex_data).sk);
  BN_clear_free((BIGNUM *)r->write_params);
  BN_clear_free(r->p);
  BN_clear_free(r->q);
  BN_clear_free(r->g);
  BN_clear_free(r->pub_key);
  CRYPTO_free(r);
  return;
}

