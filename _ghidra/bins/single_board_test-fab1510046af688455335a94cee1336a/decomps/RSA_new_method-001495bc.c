
RSA * RSA_new_method(ENGINE *engine)

{
  RSA *rsa;
  int iVar1;
  RSA_METHOD *pRVar2;
  _func_1766 *p_Var3;
  uint uVar4;
  
  rsa = (RSA *)CRYPTO_malloc(0x58,"rsa_lib.c",0x8d);
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,"rsa_lib.c",0x8f);
    return (RSA *)0x0;
  }
  if (default_RSA_meth == (RSA_METHOD *)0x0) {
    default_RSA_meth = RSA_PKCS1_SSLeay();
  }
  rsa->meth = default_RSA_meth;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_RSA();
    rsa->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_001495fc;
  }
  else {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0x97);
      CRYPTO_free(rsa);
      return (RSA *)0x0;
    }
    rsa->engine = engine;
  }
  pRVar2 = ENGINE_get_RSA(engine);
  rsa->meth = pRVar2;
  if (pRVar2 == (RSA_METHOD *)0x0) {
    ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0xa1);
    ENGINE_finish(rsa->engine);
    CRYPTO_free(rsa);
    return (RSA *)0x0;
  }
LAB_001495fc:
  rsa->pad = 0;
  uVar4 = rsa->meth->flags;
  rsa->version = 0;
  rsa->n = (BIGNUM *)0x0;
  rsa->e = (BIGNUM *)0x0;
  rsa->flags = uVar4 & 0xfffffbff;
  rsa->d = (BIGNUM *)0x0;
  rsa->p = (BIGNUM *)0x0;
  rsa->q = (BIGNUM *)0x0;
  rsa->dmp1 = (BIGNUM *)0x0;
  rsa->dmq1 = (BIGNUM *)0x0;
  rsa->iqmp = (BIGNUM *)0x0;
  rsa->_method_mod_n = (BN_MONT_CTX *)0x0;
  rsa->_method_mod_p = (BN_MONT_CTX *)0x0;
  rsa->_method_mod_q = (BN_MONT_CTX *)0x0;
  rsa->blinding = (BN_BLINDING *)0x0;
  rsa->mt_blinding = (BN_BLINDING *)0x0;
  rsa->bignum_data = (char *)0x0;
  rsa->references = 1;
  iVar1 = CRYPTO_new_ex_data(6,rsa,&rsa->ex_data);
  if (iVar1 == 0) {
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
  }
  else {
    p_Var3 = rsa->meth->init;
    if (p_Var3 == (_func_1766 *)0x0) {
      return rsa;
    }
    iVar1 = (*p_Var3)(rsa);
    if (iVar1 != 0) {
      return rsa;
    }
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
    CRYPTO_free_ex_data(6,rsa,&rsa->ex_data);
  }
  CRYPTO_free(rsa);
  return (RSA *)0x0;
}

