
DSA * DSA_new_method(ENGINE *engine)

{
  DSA *r;
  stack_st_void *psVar1;
  BN_MONT_CTX *pBVar2;
  int iVar3;
  int line;
  uint uVar4;
  code *pcVar5;
  
  r = (DSA *)CRYPTO_zalloc(0x38,"crypto/dsa/dsa_lib.c",0x33);
  if (r == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"crypto/dsa/dsa_lib.c",0x36);
    return (DSA *)0x0;
  }
  DataMemoryBarrier(0x1b);
  r->r = (BIGNUM *)0x1;
  DataMemoryBarrier(0x1b);
  psVar1 = (stack_st_void *)CRYPTO_THREAD_lock_new();
  (r->ex_data).sk = psVar1;
  if (psVar1 == (stack_st_void *)0x0) {
    ERR_put_error(10,0x67,0x41,"crypto/dsa/dsa_lib.c",0x3d);
    CRYPTO_free(r);
    return (DSA *)0x0;
  }
  pBVar2 = (BN_MONT_CTX *)DSA_get_default_method();
  uVar4 = (pBVar2->N).dmax;
  r->method_mont_p = pBVar2;
  r->priv_key = (BIGNUM *)(uVar4 & 0xfffffbff);
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DSA();
    r->references = (int)engine;
    if (engine != (ENGINE *)0x0) goto LAB_0011467c;
    pBVar2 = r->method_mont_p;
LAB_00114684:
    r->priv_key = (BIGNUM *)((pBVar2->N).dmax & 0xfffffbff);
    iVar3 = CRYPTO_new_ex_data(7,r,(CRYPTO_EX_DATA *)&r->flags);
    if (iVar3 != 0) {
      pcVar5 = (code *)(r->method_mont_p->N).d;
      if ((pcVar5 == (code *)0x0) || (iVar3 = (*pcVar5)(), iVar3 != 0)) {
        return r;
      }
      ERR_put_error(10,0x67,0x46,"crypto/dsa/dsa_lib.c",0x5c);
    }
  }
  else {
    iVar3 = ENGINE_init(engine);
    line = 0x47;
    if (iVar3 != 0) {
      r->references = (int)engine;
LAB_0011467c:
      pBVar2 = (BN_MONT_CTX *)ENGINE_get_DSA(engine);
      r->method_mont_p = pBVar2;
      if (pBVar2 != (BN_MONT_CTX *)0x0) goto LAB_00114684;
      line = 0x50;
    }
    ERR_put_error(10,0x67,0x26,"crypto/dsa/dsa_lib.c",line);
  }
  DSA_free(r);
  return (DSA *)0x0;
}

