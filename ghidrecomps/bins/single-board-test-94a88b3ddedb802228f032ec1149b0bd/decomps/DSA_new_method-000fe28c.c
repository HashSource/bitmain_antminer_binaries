
DSA * DSA_new_method(ENGINE *engine)

{
  DSA_METHOD **ppDVar1;
  DSA *dsa;
  DSA_METHOD *pDVar2;
  int iVar3;
  _func_1880 *p_Var4;
  DSA *pDVar5;
  uint uVar6;
  
  dsa = (DSA *)CRYPTO_malloc(0x44,DAT_000fe390,0x84);
  ppDVar1 = DAT_000fe394;
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,DAT_000fe390,0x86);
    return (DSA *)0x0;
  }
  pDVar2 = *DAT_000fe394;
  if (pDVar2 == (DSA_METHOD *)0x0) {
    pDVar2 = DSA_OpenSSL();
    *ppDVar1 = pDVar2;
  }
  dsa->meth = pDVar2;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DSA();
    dsa->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_000fe2cc;
  }
  else {
    iVar3 = ENGINE_init(engine);
    if (iVar3 == 0) {
      ERR_put_error(10,0x67,0x26,DAT_000fe390,0x8d);
      CRYPTO_free(dsa);
      return (DSA *)0x0;
    }
    dsa->engine = engine;
  }
  pDVar2 = ENGINE_get_DSA(engine);
  dsa->meth = pDVar2;
  if (pDVar2 == (DSA_METHOD *)0x0) {
    ERR_put_error(10,0x67,0x26,DAT_000fe390,0x97);
    ENGINE_finish(dsa->engine);
    CRYPTO_free(dsa);
    return (DSA *)0x0;
  }
LAB_000fe2cc:
  dsa->pad = 0;
  uVar6 = dsa->meth->flags;
  dsa->version = 0;
  dsa->p = (BIGNUM *)0x0;
  dsa->q = (BIGNUM *)0x0;
  dsa->g = (BIGNUM *)0x0;
  dsa->pub_key = (BIGNUM *)0x0;
  dsa->priv_key = (BIGNUM *)0x0;
  dsa->kinv = (BIGNUM *)0x0;
  dsa->r = (BIGNUM *)0x0;
  dsa->method_mont_p = (BN_MONT_CTX *)0x0;
  dsa->flags = uVar6 & 0xfffffbff;
  dsa->write_params = 1;
  dsa->references = 1;
  CRYPTO_new_ex_data(7,dsa,&dsa->ex_data);
  p_Var4 = dsa->meth->init;
  pDVar5 = dsa;
  if ((p_Var4 != (_func_1880 *)0x0) && (iVar3 = (*p_Var4)(dsa), iVar3 == 0)) {
    if (dsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(dsa->engine);
    }
    CRYPTO_free_ex_data(7,dsa,&dsa->ex_data);
    pDVar5 = (DSA *)0x0;
    CRYPTO_free(dsa);
  }
  return pDVar5;
}

