
undefined4 param_copy_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  DSA *key;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  
  pvVar1 = EVP_PKEY_get0(param_2);
  key = (DSA *)EVP_PKEY_get0(param_1);
  iVar2 = EVP_PKEY_base_id(param_2);
  iVar3 = EVP_PKEY_base_id(param_1);
  if (iVar2 != iVar3) {
    ERR_GOST_error(0x75,0x69,"gost_ameth.c",0x20b);
    return 0;
  }
  if (pvVar1 != (void *)0x0) {
    if (key == (DSA *)0x0) {
      key = DSA_new();
      iVar2 = EVP_PKEY_base_id(param_2);
      EVP_PKEY_assign(param_1,iVar2,key);
    }
    if (key->p != (BIGNUM *)0x0) {
      BN_free(key->p);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0xc));
    key->p = pBVar4;
    if (key->q != (BIGNUM *)0x0) {
      BN_free(key->q);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0x10));
    key->q = pBVar4;
    if (key->g != (BIGNUM *)0x0) {
      BN_free(key->g);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0x14));
    key->g = pBVar4;
    if (key->priv_key != (BIGNUM *)0x0) {
      gost94_compute_public(key);
      return 1;
    }
    return 1;
  }
  ERR_GOST_error(0x75,0x73,"gost_ameth.c",0x20f);
  return 0;
}

