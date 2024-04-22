
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  _STACK **pp_Var1;
  int iVar2;
  EVP_PKEY_METHOD **ppEVar3;
  ENGINE *e_00;
  code *pcVar4;
  EVP_PKEY_METHOD *pEVar5;
  EVP_PKEY_METHOD **local_88;
  EVP_PKEY_METHOD *local_84 [27];
  
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if ((EVP_PKEY_METHOD **)pkey->ameth == (EVP_PKEY_METHOD **)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  pEVar5 = *(EVP_PKEY_METHOD **)pkey->ameth;
  e_00 = pkey->engine;
  if ((pkey->engine == (ENGINE *)0x0) && (e_00 = e, e == (ENGINE *)0x0)) {
    e_00 = ENGINE_get_pkey_meth_engine((int)pEVar5);
    pp_Var1 = DAT_000b3a9c;
    if (e_00 != (ENGINE *)0x0) goto LAB_000b397e;
    local_88 = local_84;
    local_84[0] = pEVar5;
    if ((*DAT_000b3a9c == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_000b3a9c,local_88), iVar2 < 0)) {
      ppEVar3 = (EVP_PKEY_METHOD **)OBJ_bsearch_(&local_88,DAT_000b3aa4,7,4,DAT_000b3aa0);
      if (ppEVar3 == (EVP_PKEY_METHOD **)0x0) goto LAB_000b3a3a;
      pEVar5 = *ppEVar3;
    }
    else {
      pEVar5 = (EVP_PKEY_METHOD *)sk_value(*pp_Var1,iVar2);
    }
  }
  else {
    iVar2 = ENGINE_init(e_00);
    if (iVar2 == 0) {
      ERR_put_error(6,0x9d,0x26,DAT_000b3a98,0x92);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_000b397e:
    pEVar5 = ENGINE_get_pkey_meth(e_00,(int)pEVar5);
  }
  if (pEVar5 != (EVP_PKEY_METHOD *)0x0) {
    ppEVar3 = (EVP_PKEY_METHOD **)CRYPTO_malloc(0x28,DAT_000b3a98,0xa8);
    if (ppEVar3 == (EVP_PKEY_METHOD **)0x0) {
      if (e_00 != (ENGINE *)0x0) {
        ENGINE_finish(e_00);
      }
      ERR_put_error(6,0x9d,0x41,DAT_000b3a98,0xae);
      return (EVP_PKEY_CTX *)0x0;
    }
    ppEVar3[1] = (EVP_PKEY_METHOD *)e_00;
    *ppEVar3 = pEVar5;
    ppEVar3[2] = (EVP_PKEY_METHOD *)pkey;
    ppEVar3[4] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[3] = (EVP_PKEY_METHOD *)0x0;
    ppEVar3[7] = (EVP_PKEY_METHOD *)0x0;
    CRYPTO_add_lock(&pkey->references,1,10,DAT_000b3a98,0xb8);
    pcVar4 = *(code **)(pEVar5 + 8);
    ppEVar3[5] = (EVP_PKEY_METHOD *)0x0;
    if (pcVar4 == (code *)0x0) {
      return (EVP_PKEY_CTX *)ppEVar3;
    }
    iVar2 = (*pcVar4)(ppEVar3);
    if (0 < iVar2) {
      return (EVP_PKEY_CTX *)ppEVar3;
    }
    if ((*ppEVar3 != (EVP_PKEY_METHOD *)0x0) &&
       (pcVar4 = *(code **)(*ppEVar3 + 0x10), pcVar4 != (code *)0x0)) {
      (*pcVar4)(ppEVar3);
    }
    if ((EVP_PKEY *)ppEVar3[2] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar3[2]);
    }
    if ((EVP_PKEY *)ppEVar3[3] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppEVar3[3]);
    }
    if ((ENGINE *)ppEVar3[1] != (ENGINE *)0x0) {
      ENGINE_finish((ENGINE *)ppEVar3[1]);
    }
    CRYPTO_free(ppEVar3);
    return (EVP_PKEY_CTX *)0x0;
  }
LAB_000b3a3a:
  ERR_put_error(6,0x9d,0x9c,DAT_000b3a98,0xa4);
  return (EVP_PKEY_CTX *)0x0;
}

