
DH * DH_new_method(ENGINE *engine)

{
  DH_METHOD **ppDVar1;
  DH *dh;
  DH_METHOD *pDVar2;
  int iVar3;
  _func_1846 *p_Var4;
  DH *pDVar5;
  uint uVar6;
  
  dh = (DH *)CRYPTO_malloc(0x4c,DAT_000a4fec,0x7e);
  ppDVar1 = DAT_000a4ff0;
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,DAT_000a4fec,0x80);
    return (DH *)0x0;
  }
  pDVar2 = *DAT_000a4ff0;
  if (pDVar2 == (DH_METHOD *)0x0) {
    pDVar2 = DH_OpenSSL();
    *ppDVar1 = pDVar2;
  }
  dh->meth = pDVar2;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DH();
    dh->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_000a4f24;
  }
  else {
    iVar3 = ENGINE_init(engine);
    if (iVar3 == 0) {
      ERR_put_error(5,0x69,0x26,DAT_000a4fec,0x88);
      CRYPTO_free(dh);
      return (DH *)0x0;
    }
    dh->engine = engine;
  }
  pDVar2 = ENGINE_get_DH(engine);
  dh->meth = pDVar2;
  if (pDVar2 == (DH_METHOD *)0x0) {
    ERR_put_error(5,0x69,0x26,DAT_000a4fec,0x92);
    ENGINE_finish(dh->engine);
    CRYPTO_free(dh);
    return (DH *)0x0;
  }
LAB_000a4f24:
  dh->pad = 0;
  uVar6 = dh->meth->flags;
  dh->version = 0;
  dh->p = (BIGNUM *)0x0;
  dh->g = (BIGNUM *)0x0;
  dh->length = 0;
  dh->pub_key = (BIGNUM *)0x0;
  dh->priv_key = (BIGNUM *)0x0;
  dh->q = (BIGNUM *)0x0;
  dh->j = (BIGNUM *)0x0;
  dh->seed = (uchar *)0x0;
  dh->seedlen = 0;
  dh->counter = (BIGNUM *)0x0;
  dh->method_mont_p = (BN_MONT_CTX *)0x0;
  dh->flags = uVar6 & 0xfffffbff;
  dh->references = 1;
  CRYPTO_new_ex_data(8,dh,&dh->ex_data);
  p_Var4 = dh->meth->init;
  pDVar5 = dh;
  if ((p_Var4 != (_func_1846 *)0x0) && (iVar3 = (*p_Var4)(dh), iVar3 == 0)) {
    if (dh->engine != (ENGINE *)0x0) {
      ENGINE_finish(dh->engine);
    }
    CRYPTO_free_ex_data(8,dh,&dh->ex_data);
    pDVar5 = (DH *)0x0;
    CRYPTO_free(dh);
  }
  return pDVar5;
}

