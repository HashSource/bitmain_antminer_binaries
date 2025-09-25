
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  EVP_PKEY_CTX *ctx;
  int iVar3;
  
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  iVar3 = pkey->type;
  if (((e == (ENGINE *)0x0) && (e = (ENGINE *)(pkey->pkey).rsa, (rsa_st *)e == (rsa_st *)0x0)) &&
     (e = pkey->engine, (rsa_st *)e == (rsa_st *)0x0)) {
    e = ENGINE_get_pkey_meth_engine(iVar3);
    if ((rsa_st *)e == (rsa_st *)0x0) {
      pEVar2 = EVP_PKEY_meth_find(iVar3);
      goto LAB_0012f0f8;
    }
  }
  else {
    iVar1 = ENGINE_init(e);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"crypto/evp/pmeth_lib.c",0x77);
      return (EVP_PKEY_CTX *)0x0;
    }
  }
  pEVar2 = ENGINE_get_pkey_meth(e,iVar3);
LAB_0012f0f8:
  if (pEVar2 == (EVP_PKEY_METHOD *)0x0) {
    ENGINE_finish(e);
    ERR_put_error(6,0x9d,0x9c,"crypto/evp/pmeth_lib.c",0x8c);
    ctx = (EVP_PKEY_CTX *)0x0;
  }
  else {
    ctx = (EVP_PKEY_CTX *)CRYPTO_zalloc(0x28,"crypto/evp/pmeth_lib.c",0x90);
    if (ctx == (EVP_PKEY_CTX *)0x0) {
      ENGINE_finish(e);
      ERR_put_error(6,0x9d,0x41,"crypto/evp/pmeth_lib.c",0x95);
    }
    else {
      *(ENGINE **)(ctx + 4) = e;
      *(EVP_PKEY_METHOD **)ctx = pEVar2;
      *(EVP_PKEY **)(ctx + 8) = pkey;
      *(undefined4 *)(ctx + 0x10) = 0;
      EVP_PKEY_up_ref(pkey);
      if ((*(code **)(pEVar2 + 8) != (code *)0x0) &&
         (iVar3 = (**(code **)(pEVar2 + 8))(), iVar3 < 1)) {
        *(undefined4 *)ctx = 0;
        EVP_PKEY_CTX_free(ctx);
        ctx = (EVP_PKEY_CTX *)0x0;
      }
    }
  }
  return ctx;
}

