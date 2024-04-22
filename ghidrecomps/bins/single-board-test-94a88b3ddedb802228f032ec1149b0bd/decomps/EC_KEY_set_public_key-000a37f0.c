
int EC_KEY_set_public_key(EC_KEY *key,EC_POINT *pub)

{
  EC_POINT *pEVar1;
  
  if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
    EC_POINT_free(*(EC_POINT **)(key + 8));
  }
  pEVar1 = EC_POINT_dup(pub,*(EC_GROUP **)(key + 4));
  *(EC_POINT **)(key + 8) = pEVar1;
  if (pEVar1 != (EC_POINT *)0x0) {
    pEVar1 = (EC_POINT *)0x1;
  }
  return (int)pEVar1;
}

