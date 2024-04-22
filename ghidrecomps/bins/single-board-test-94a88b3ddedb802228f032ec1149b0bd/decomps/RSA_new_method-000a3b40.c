
RSA * RSA_new_method(ENGINE *engine)

{
  RSA_METHOD **ppRVar1;
  RSA *rsa;
  RSA_METHOD *pRVar2;
  int iVar3;
  _func_1766 *p_Var4;
  uint uVar5;
  
  rsa = (RSA *)CRYPTO_malloc(0x58,DAT_000a3c5c,0x8d);
  ppRVar1 = DAT_000a3c60;
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,DAT_000a3c5c,0x8f);
    return (RSA *)0x0;
  }
  pRVar2 = *DAT_000a3c60;
  if (pRVar2 == (RSA_METHOD *)0x0) {
    pRVar2 = RSA_PKCS1_SSLeay();
    *ppRVar1 = pRVar2;
  }
  rsa->meth = pRVar2;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_RSA();
    rsa->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_000a3b80;
  }
  else {
    iVar3 = ENGINE_init(engine);
    if (iVar3 == 0) {
      ERR_put_error(4,0x6a,0x26,DAT_000a3c5c,0x97);
      CRYPTO_free(rsa);
      return (RSA *)0x0;
    }
    rsa->engine = engine;
  }
  pRVar2 = ENGINE_get_RSA(engine);
  rsa->meth = pRVar2;
  if (pRVar2 == (RSA_METHOD *)0x0) {
    ERR_put_error(4,0x6a,0x26,DAT_000a3c5c,0xa1);
    ENGINE_finish(rsa->engine);
    CRYPTO_free(rsa);
    return (RSA *)0x0;
  }
LAB_000a3b80:
  rsa->pad = 0;
  uVar5 = rsa->meth->flags;
  rsa->version = 0;
  rsa->n = (BIGNUM *)0x0;
  rsa->e = (BIGNUM *)0x0;
  rsa->flags = uVar5 & 0xfffffbff;
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
  iVar3 = CRYPTO_new_ex_data(6,rsa,&rsa->ex_data);
  if (iVar3 == 0) {
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
  }
  else {
    p_Var4 = rsa->meth->init;
    if (p_Var4 == (_func_1766 *)0x0) {
      return rsa;
    }
    iVar3 = (*p_Var4)(rsa);
    if (iVar3 != 0) {
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

