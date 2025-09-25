
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  EVP_PKEY_CTX *ctx;
  code *pcVar3;
  
  if (id == -1) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if (e == (ENGINE *)0x0) {
    e = ENGINE_get_pkey_meth_engine(id);
    if (e == (ENGINE *)0x0) {
      pEVar2 = EVP_PKEY_meth_find(id);
      goto LAB_0012f2a4;
    }
  }
  else {
    iVar1 = ENGINE_init(e);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"crypto/evp/pmeth_lib.c",0x77);
      return (EVP_PKEY_CTX *)0x0;
    }
  }
  pEVar2 = ENGINE_get_pkey_meth(e,id);
LAB_0012f2a4:
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
      pcVar3 = *(code **)(pEVar2 + 8);
      *(ENGINE **)(ctx + 4) = e;
      *(EVP_PKEY_METHOD **)ctx = pEVar2;
      *(undefined4 *)(ctx + 0x10) = 0;
      *(undefined4 *)(ctx + 8) = 0;
      if ((pcVar3 != (code *)0x0) && (iVar1 = (*pcVar3)(), iVar1 < 1)) {
        *(undefined4 *)ctx = 0;
        EVP_PKEY_CTX_free(ctx);
        ctx = (EVP_PKEY_CTX *)0x0;
      }
    }
  }
  return ctx;
}

