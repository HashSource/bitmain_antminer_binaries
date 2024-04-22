
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  _STACK **pp_Var1;
  int iVar2;
  EVP_PKEY_METHOD *pEVar3;
  EVP_PKEY_METHOD **ppEVar4;
  code *pcVar5;
  int *local_80;
  int local_7c [27];
  
  if (id == -1) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if (e == (ENGINE *)0x0) {
    e = ENGINE_get_pkey_meth_engine(id);
    pp_Var1 = DAT_000b3bb8;
    if (e != (ENGINE *)0x0) goto LAB_000b3ac8;
    local_80 = local_7c;
    local_7c[0] = id;
    if ((*DAT_000b3bb8 == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_000b3bb8,local_80), iVar2 < 0)) {
      ppEVar4 = (EVP_PKEY_METHOD **)OBJ_bsearch_(&local_80,DAT_000b3bc0,7,4,DAT_000b3bbc);
      if (ppEVar4 == (EVP_PKEY_METHOD **)0x0) goto LAB_000b3b84;
      pEVar3 = *ppEVar4;
    }
    else {
      pEVar3 = (EVP_PKEY_METHOD *)sk_value(*pp_Var1,iVar2);
    }
  }
  else {
    iVar2 = ENGINE_init(e);
    if (iVar2 == 0) {
      ERR_put_error(6,0x9d,0x26,DAT_000b3bb4,0x92);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_000b3ac8:
    pEVar3 = ENGINE_get_pkey_meth(e,id);
  }
  if (pEVar3 != (EVP_PKEY_METHOD *)0x0) {
    ppEVar4 = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,DAT_000b3bb4,0xa8);
    if (ppEVar4 == (EVP_PKEY_METHOD **)0x0) {
      if (e != (ENGINE *)0x0) {
        ENGINE_finish(e);
      }
      ERR_put_error(6,0x9d,0x41,DAT_000b3bb4,0xae);
      return (EVP_PKEY_CTX *)0x0;
    }
    pcVar5 = *(code **)(pEVar3 + 8);
    ppEVar4[1] = (EVP_PKEY_METHOD *)e;
    *ppEVar4 = pEVar3;
    ppEVar4[4] = (EVP_PKEY_METHOD *)0x0;
    ppEVar4[2] = (EVP_PKEY_METHOD *)0x0;
    ppEVar4[3] = (EVP_PKEY_METHOD *)0x0;
    ppEVar4[7] = (EVP_PKEY_METHOD *)0x0;
    ppEVar4[5] = (EVP_PKEY_METHOD *)0x0;
    if (pcVar5 == (code *)0x0) {
      return (EVP_PKEY_CTX *)ppEVar4;
    }
    iVar2 = (*pcVar5)();
    if (0 < iVar2) {
      return (EVP_PKEY_CTX *)ppEVar4;
    }
    if ((*ppEVar4 != (EVP_PKEY_METHOD *)0x0) &&
       (pcVar5 = *(code **)(*ppEVar4 + 0x10), pcVar5 != (code *)0x0)) {
      (*pcVar5)(ppEVar4);
    }
    if ((EVP_PKEY *)ppEVar4[2] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar4[2]);
    }
    if ((EVP_PKEY *)ppEVar4[3] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar4[3]);
    }
    if ((ENGINE *)ppEVar4[1] != (ENGINE *)0x0) {
      ENGINE_finish((ENGINE *)ppEVar4[1]);
    }
    CRYPTO_free(ppEVar4);
    return (EVP_PKEY_CTX *)0x0;
  }
LAB_000b3b84:
  ERR_put_error(6,0x9d,0x9c,DAT_000b3bb4,0xa4);
  return (EVP_PKEY_CTX *)0x0;
}

