
DH * DH_new_method(ENGINE *engine)

{
  DH *dh;
  int iVar1;
  DH_METHOD *pDVar2;
  _func_1846 *p_Var3;
  DH *pDVar4;
  uint uVar5;
  
  dh = (DH *)CRYPTO_malloc(0x4c,"dh_lib.c",0x7e);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x80);
    return (DH *)0x0;
  }
  if (default_DH_method == (DH_METHOD *)0x0) {
    default_DH_method = DH_OpenSSL();
  }
  dh->meth = default_DH_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DH();
    dh->engine = engine;
    if (engine == (ENGINE *)0x0) goto LAB_00147e64;
  }
  else {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      ERR_put_error(5,0x69,0x26,"dh_lib.c",0x88);
      CRYPTO_free(dh);
      return (DH *)0x0;
    }
    dh->engine = engine;
  }
  pDVar2 = ENGINE_get_DH(engine);
  dh->meth = pDVar2;
  if (pDVar2 == (DH_METHOD *)0x0) {
    ERR_put_error(5,0x69,0x26,"dh_lib.c",0x92);
    ENGINE_finish(dh->engine);
    CRYPTO_free(dh);
    return (DH *)0x0;
  }
LAB_00147e64:
  dh->pad = 0;
  uVar5 = dh->meth->flags;
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
  dh->flags = uVar5 & 0xfffffbff;
  dh->references = 1;
  CRYPTO_new_ex_data(8,dh,&dh->ex_data);
  p_Var3 = dh->meth->init;
  pDVar4 = dh;
  if ((p_Var3 != (_func_1846 *)0x0) && (iVar1 = (*p_Var3)(dh), iVar1 == 0)) {
    if (dh->engine != (ENGINE *)0x0) {
      ENGINE_finish(dh->engine);
    }
    CRYPTO_free_ex_data(8,dh,&dh->ex_data);
    pDVar4 = (DH *)0x0;
    CRYPTO_free(dh);
  }
  return pDVar4;
}

