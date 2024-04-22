
undefined4 param_copy_gost01(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  EC_KEY *key_00;
  int iVar1;
  int iVar2;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  key_00 = (EC_KEY *)EVP_PKEY_get0(param_2);
  iVar1 = EVP_PKEY_base_id(param_2);
  iVar2 = EVP_PKEY_base_id(param_1);
  if (iVar1 != iVar2) {
    ERR_GOST_error(0x74,0x69,DAT_00115720,0x225);
    return 0;
  }
  if (key_00 == (EC_KEY *)0x0) {
    ERR_GOST_error(0x74,0x73,DAT_00115720,0x229);
    return 0;
  }
  if (key == (EC_KEY *)0x0) {
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      ERR_GOST_error(0x74,0x41,DAT_00115720,0x22f);
      return 0;
    }
    iVar1 = EVP_PKEY_base_id(param_2);
    iVar1 = EVP_PKEY_assign(param_1,iVar1,key);
    if (iVar1 == 0) {
      ERR_GOST_error(0x74,0x44,DAT_00115720,0x233);
      return 0;
    }
  }
  group = EC_KEY_get0_group(key_00);
  iVar1 = EC_KEY_set_group(key,group);
  if (iVar1 == 0) {
    ERR_GOST_error(0x74,0x44,DAT_00115720,0x238);
    return 0;
  }
  pBVar3 = EC_KEY_get0_private_key(key);
  if (pBVar3 != (BIGNUM *)0x0) {
    gost2001_compute_public(key);
    return 1;
  }
  return 1;
}

