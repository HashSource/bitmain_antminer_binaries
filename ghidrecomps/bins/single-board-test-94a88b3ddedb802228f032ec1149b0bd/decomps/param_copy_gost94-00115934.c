
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
    ERR_GOST_error(0x75,0x69,DAT_001159f0,0x20b);
    return 0;
  }
  if (pvVar1 != (void *)0x0) {
    if (key == (DSA *)0x0) {
      key = DSA_new();
      iVar2 = EVP_PKEY_base_id(param_2);
      EVP_PKEY_assign(param_1,iVar2,key);
    }
    if (*(BIGNUM **)&key->field_0xc != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)&key->field_0xc);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0xc));
    *(BIGNUM **)&key->field_0xc = pBVar4;
    if (*(BIGNUM **)&key->field_0x10 != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)&key->field_0x10);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0x10));
    *(BIGNUM **)&key->field_0x10 = pBVar4;
    if (*(BIGNUM **)&key->field_0x14 != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)&key->field_0x14);
    }
    pBVar4 = BN_dup(*(BIGNUM **)((int)pvVar1 + 0x14));
    *(BIGNUM **)&key->field_0x14 = pBVar4;
    if (*(int *)&key->field_0x1c != 0) {
      gost94_compute_public(key);
      return 1;
    }
    return 1;
  }
  ERR_GOST_error(0x75,0x73,DAT_001159f0,0x20f);
  return 0;
}

