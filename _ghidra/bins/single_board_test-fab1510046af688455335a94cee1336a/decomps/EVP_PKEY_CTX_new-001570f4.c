
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  EVP_PKEY_CTX *ptr;
  ENGINE *e_00;
  undefined4 *puVar3;
  code *pcVar4;
  int iVar5;
  int *local_88;
  int local_84 [27];
  
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return (EVP_PKEY_CTX *)0x0;
  }
  iVar5 = *(int *)pkey->ameth;
  e_00 = pkey->engine;
  if ((pkey->engine == (ENGINE *)0x0) && (e_00 = e, e == (ENGINE *)0x0)) {
    e_00 = ENGINE_get_pkey_meth_engine(iVar5);
    if (e_00 != (ENGINE *)0x0) goto LAB_0015711a;
    local_88 = local_84;
    local_84[0] = iVar5;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar5 = sk_find(app_pkey_methods,local_88), iVar5 < 0)) {
      puVar3 = (undefined4 *)OBJ_bsearch_(&local_88,&standard_methods,7,4,(cmp *)0x156fb9);
      if (puVar3 == (undefined4 *)0x0) goto LAB_001571d6;
      pEVar2 = (EVP_PKEY_METHOD *)*puVar3;
    }
    else {
      pEVar2 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar5);
    }
  }
  else {
    iVar1 = ENGINE_init(e_00);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"pmeth_lib.c",0x92);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_0015711a:
    pEVar2 = ENGINE_get_pkey_meth(e_00,iVar5);
  }
  if (pEVar2 != (EVP_PKEY_METHOD *)0x0) {
    ptr = (EVP_PKEY_CTX *)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa8);
    if (ptr == (EVP_PKEY_CTX *)0x0) {
      if (e_00 != (ENGINE *)0x0) {
        ENGINE_finish(e_00);
      }
      ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xae);
      return (EVP_PKEY_CTX *)0x0;
    }
    *(ENGINE **)(ptr + 4) = e_00;
    *(EVP_PKEY_METHOD **)ptr = pEVar2;
    *(EVP_PKEY **)(ptr + 8) = pkey;
    *(undefined4 *)(ptr + 0x10) = 0;
    *(undefined4 *)(ptr + 0xc) = 0;
    *(undefined4 *)(ptr + 0x1c) = 0;
    CRYPTO_add_lock(&pkey->references,1,10,"pmeth_lib.c",0xb8);
    pcVar4 = *(code **)(pEVar2 + 8);
    *(undefined4 *)(ptr + 0x14) = 0;
    if (pcVar4 == (code *)0x0) {
      return ptr;
    }
    iVar5 = (*pcVar4)(ptr);
    if (0 < iVar5) {
      return ptr;
    }
    if ((*(int *)ptr != 0) && (pcVar4 = *(code **)(*(int *)ptr + 0x10), pcVar4 != (code *)0x0)) {
      (*pcVar4)(ptr);
    }
    if (*(EVP_PKEY **)(ptr + 8) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(ptr + 8));
    }
    if (*(EVP_PKEY **)(ptr + 0xc) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(ptr + 0xc));
    }
    if (*(ENGINE **)(ptr + 4) != (ENGINE *)0x0) {
      ENGINE_finish(*(ENGINE **)(ptr + 4));
    }
    CRYPTO_free(ptr);
    return (EVP_PKEY_CTX *)0x0;
  }
LAB_001571d6:
  ERR_put_error(6,0x9d,0x9c,"pmeth_lib.c",0xa4);
  return (EVP_PKEY_CTX *)0x0;
}

