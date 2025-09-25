
DH * DH_new_method(ENGINE *engine)

{
  DH *dh;
  ENGINE *pEVar1;
  DH_METHOD *pDVar2;
  int line;
  int iVar3;
  code *pcVar4;
  
  dh = (DH *)CRYPTO_zalloc(0x4c,"crypto/dh/dh_lib.c",0x2c);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"crypto/dh/dh_lib.c",0x2f);
    return (DH *)0x0;
  }
  DataMemoryBarrier(0x1b);
  dh->references = 1;
  DataMemoryBarrier(0x1b);
  pEVar1 = (ENGINE *)CRYPTO_THREAD_lock_new();
  dh->engine = pEVar1;
  if (pEVar1 == (ENGINE *)0x0) {
    ERR_put_error(5,0x69,0x41,"crypto/dh/dh_lib.c",0x36);
    CRYPTO_free(dh);
    return (DH *)0x0;
  }
  pDVar2 = DH_get_default_method();
  iVar3 = pDVar2->flags;
  (dh->ex_data).dummy = (int)pDVar2;
  dh->flags = iVar3;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DH();
    dh->meth = (DH_METHOD *)engine;
    if ((DH_METHOD *)engine != (DH_METHOD *)0x0) goto LAB_0011384c;
    pDVar2 = (DH_METHOD *)(dh->ex_data).dummy;
LAB_00113854:
    dh->flags = pDVar2->flags;
    iVar3 = CRYPTO_new_ex_data(6,dh,&dh->ex_data);
    if (iVar3 != 0) {
      pcVar4 = *(code **)((dh->ex_data).dummy + 0x10);
      if ((pcVar4 == (code *)0x0) || (iVar3 = (*pcVar4)(), iVar3 != 0)) {
        return dh;
      }
      ERR_put_error(5,0x69,0x46,"crypto/dh/dh_lib.c",0x55);
    }
  }
  else {
    iVar3 = ENGINE_init(engine);
    line = 0x40;
    if (iVar3 != 0) {
      dh->meth = (DH_METHOD *)engine;
LAB_0011384c:
      pDVar2 = ENGINE_get_DH(engine);
      (dh->ex_data).dummy = (int)pDVar2;
      if (pDVar2 != (DH_METHOD *)0x0) goto LAB_00113854;
      line = 0x49;
    }
    ERR_put_error(5,0x69,0x26,"crypto/dh/dh_lib.c",line);
  }
  DH_free(dh);
  return (DH *)0x0;
}

