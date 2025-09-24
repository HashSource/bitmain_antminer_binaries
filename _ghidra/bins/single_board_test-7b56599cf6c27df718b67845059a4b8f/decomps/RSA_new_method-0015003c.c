
RSA * RSA_new_method(ENGINE *engine)

{
  RSA *rsa;
  int iVar1;
  RSA_METHOD *pRVar2;
  int line;
  uint uVar3;
  _func_1766 *p_Var4;
  
  rsa = (RSA *)CRYPTO_zalloc(0x60,"crypto/rsa/rsa_lib.c",0x34);
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,"crypto/rsa/rsa_lib.c",0x37);
    return (RSA *)0x0;
  }
  DataMemoryBarrier(0x1b);
  rsa->flags = 1;
  DataMemoryBarrier(0x1b);
  iVar1 = CRYPTO_THREAD_lock_new();
  rsa[1].version = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(4,0x6a,0x41,"crypto/rsa/rsa_lib.c",0x3e);
    CRYPTO_free(rsa);
    return (RSA *)0x0;
  }
  pRVar2 = RSA_get_default_method();
  uVar3 = pRVar2->flags;
  rsa->meth = pRVar2;
  rsa->_method_mod_n = (BN_MONT_CTX *)(uVar3 & 0xfffffbff);
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_RSA();
    rsa->engine = engine;
    if (engine != (ENGINE *)0x0) goto LAB_00150090;
    pRVar2 = rsa->meth;
LAB_00150098:
    rsa->_method_mod_n = (BN_MONT_CTX *)(pRVar2->flags & 0xfffffbff);
    iVar1 = CRYPTO_new_ex_data(9,rsa,(CRYPTO_EX_DATA *)&rsa->references);
    if (iVar1 != 0) {
      p_Var4 = rsa->meth->init;
      if ((p_Var4 == (_func_1766 *)0x0) || (iVar1 = (*p_Var4)(rsa), iVar1 != 0)) {
        return rsa;
      }
      ERR_put_error(4,0x6a,0x46,"crypto/rsa/rsa_lib.c",0x5e);
    }
  }
  else {
    iVar1 = ENGINE_init(engine);
    line = 0x48;
    if (iVar1 != 0) {
      rsa->engine = engine;
LAB_00150090:
      pRVar2 = ENGINE_get_RSA(engine);
      rsa->meth = pRVar2;
      if (pRVar2 != (RSA_METHOD *)0x0) goto LAB_00150098;
      line = 0x52;
    }
    ERR_put_error(4,0x6a,0x26,"crypto/rsa/rsa_lib.c",line);
  }
  RSA_free(rsa);
  return (RSA *)0x0;
}

