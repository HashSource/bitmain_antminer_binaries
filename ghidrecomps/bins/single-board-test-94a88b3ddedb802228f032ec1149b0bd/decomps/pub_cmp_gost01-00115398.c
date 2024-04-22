
int pub_cmp_gost01(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  EC_KEY *key_00;
  EC_POINT *a;
  EC_POINT *b;
  EC_GROUP *group;
  uint uVar1;
  int iVar2;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  key_00 = (EC_KEY *)EVP_PKEY_get0(param_2);
  if (key != (EC_KEY *)0x0 && key_00 != (EC_KEY *)0x0) {
    a = EC_KEY_get0_public_key(key);
    b = EC_KEY_get0_public_key(key_00);
    if (a != (EC_POINT *)0x0 && b != (EC_POINT *)0x0) {
      group = EC_KEY_get0_group(key);
      uVar1 = EC_POINT_cmp(group,a,b,(BN_CTX *)0x0);
      iVar2 = 1 - uVar1;
      if (1 < uVar1) {
        iVar2 = 0;
      }
      return iVar2;
    }
  }
  return 0;
}

