
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  EVP_PKEY_CTX *ptr;
  undefined4 *puVar3;
  code *pcVar4;
  int *local_80;
  int local_7c [27];
  
  if (id == -1) {
    return (EVP_PKEY_CTX *)0x0;
  }
  if (e == (ENGINE *)0x0) {
    e = ENGINE_get_pkey_meth_engine(id);
    if (e != (ENGINE *)0x0) goto LAB_00157264;
    local_80 = local_7c;
    local_7c[0] = id;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar1 = sk_find(app_pkey_methods,local_80), iVar1 < 0)) {
      puVar3 = (undefined4 *)OBJ_bsearch_(&local_80,&standard_methods,7,4,(cmp *)0x156fb9);
      if (puVar3 == (undefined4 *)0x0) goto LAB_00157320;
      pEVar2 = (EVP_PKEY_METHOD *)*puVar3;
    }
    else {
      pEVar2 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
    }
  }
  else {
    iVar1 = ENGINE_init(e);
    if (iVar1 == 0) {
      ERR_put_error(6,0x9d,0x26,"pmeth_lib.c",0x92);
      return (EVP_PKEY_CTX *)0x0;
    }
LAB_00157264:
    pEVar2 = ENGINE_get_pkey_meth(e,id);
  }
  if (pEVar2 != (EVP_PKEY_METHOD *)0x0) {
    ptr = (EVP_PKEY_CTX *)CRYPTO_malloc(0x28,"pmeth_lib.c",0xa8);
    if (ptr == (EVP_PKEY_CTX *)0x0) {
      if (e != (ENGINE *)0x0) {
        ENGINE_finish(e);
      }
      ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xae);
      return (EVP_PKEY_CTX *)0x0;
    }
    pcVar4 = *(code **)(pEVar2 + 8);
    *(ENGINE **)(ptr + 4) = e;
    *(EVP_PKEY_METHOD **)ptr = pEVar2;
    *(undefined4 *)(ptr + 0x10) = 0;
    *(undefined4 *)(ptr + 8) = 0;
    *(undefined4 *)(ptr + 0xc) = 0;
    *(undefined4 *)(ptr + 0x1c) = 0;
    *(undefined4 *)(ptr + 0x14) = 0;
    if (pcVar4 == (code *)0x0) {
      return ptr;
    }
    iVar1 = (*pcVar4)();
    if (0 < iVar1) {
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
LAB_00157320:
  ERR_put_error(6,0x9d,0x9c,"pmeth_lib.c",0xa4);
  return (EVP_PKEY_CTX *)0x0;
}

