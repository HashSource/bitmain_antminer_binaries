
DSA * DSA_new_method(ENGINE *engine)

{
  DSA *dsa;
  int iVar1;
  DSA_METHOD *pDVar2;
  _func_1880 *p_Var3;
  DSA *pDVar4;
  uint uVar5;
  
  dsa = (DSA *)CRYPTO_malloc(0x44,"dsa_lib.c",0x84);
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"dsa_lib.c",0x86);
    return (DSA *)0x0;
  }
  if (default_DSA_method == (DSA_METHOD *)0x0) {
    default_DSA_method = DSA_OpenSSL();
  }
  dsa->meth = default_DSA_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DSA();
    dsa->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_0019956c;
  }
  else {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x8d);
      CRYPTO_free(dsa);
      return (DSA *)0x0;
    }
    dsa->engine = engine;
  }
  pDVar2 = ENGINE_get_DSA(engine);
  dsa->meth = pDVar2;
  if (pDVar2 == (DSA_METHOD *)0x0) {
    ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x97);
    ENGINE_finish(dsa->engine);
    CRYPTO_free(dsa);
    return (DSA *)0x0;
  }
LAB_0019956c:
  dsa->pad = 0;
  uVar5 = dsa->meth->flags;
  dsa->version = 0;
  dsa->p = (BIGNUM *)0x0;
  dsa->q = (BIGNUM *)0x0;
  dsa->g = (BIGNUM *)0x0;
  dsa->pub_key = (BIGNUM *)0x0;
  dsa->priv_key = (BIGNUM *)0x0;
  dsa->kinv = (BIGNUM *)0x0;
  dsa->r = (BIGNUM *)0x0;
  dsa->method_mont_p = (BN_MONT_CTX *)0x0;
  dsa->flags = uVar5 & 0xfffffbff;
  dsa->write_params = 1;
  dsa->references = 1;
  CRYPTO_new_ex_data(7,dsa,&dsa->ex_data);
  p_Var3 = dsa->meth->init;
  pDVar4 = dsa;
  if ((p_Var3 != (_func_1880 *)0x0) && (iVar1 = (*p_Var3)(dsa), iVar1 == 0)) {
    if (dsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(dsa->engine);
    }
    CRYPTO_free_ex_data(7,dsa,&dsa->ex_data);
    pDVar4 = (DSA *)0x0;
    CRYPTO_free(dsa);
  }
  return pDVar4;
}

