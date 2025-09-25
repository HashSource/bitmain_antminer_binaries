
int EC_KEY_set_public_key(EC_KEY *key,EC_POINT *pub)

{
  int iVar1;
  EC_POINT *pEVar2;
  
  if ((*(code **)(*(int *)key + 0x1c) != (code *)0x0) &&
     (iVar1 = (**(code **)(*(int *)key + 0x1c))(), iVar1 == 0)) {
    return 0;
  }
  EC_POINT_free(*(EC_POINT **)(key + 0x10));
  pEVar2 = EC_POINT_dup(pub,*(EC_GROUP **)(key + 0xc));
  *(EC_POINT **)(key + 0x10) = pEVar2;
  if (pEVar2 != (EC_POINT *)0x0) {
    pEVar2 = (EC_POINT *)0x1;
  }
  return (int)pEVar2;
}

