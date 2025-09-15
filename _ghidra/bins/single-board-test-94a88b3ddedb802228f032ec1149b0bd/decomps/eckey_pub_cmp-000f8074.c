
undefined4 eckey_pub_cmp(int param_1,int param_2)

{
  EC_GROUP *group;
  EC_POINT *a;
  EC_POINT *b;
  int iVar1;
  undefined4 uVar2;
  
  group = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14));
  a = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 0x14));
  b = EC_KEY_get0_public_key(*(EC_KEY **)(param_2 + 0x14));
  iVar1 = EC_POINT_cmp(group,a,b,(BN_CTX *)0x0);
  if (iVar1 == 0) {
    return 1;
  }
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

