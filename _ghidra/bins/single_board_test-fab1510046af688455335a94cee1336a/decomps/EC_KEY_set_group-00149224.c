
int EC_KEY_set_group(EC_KEY *key,EC_GROUP *group)

{
  EC_GROUP *pEVar1;
  
  if (*(EC_GROUP **)(key + 4) != (EC_GROUP *)0x0) {
    EC_GROUP_free(*(EC_GROUP **)(key + 4));
  }
  pEVar1 = EC_GROUP_dup(group);
  *(EC_GROUP **)(key + 4) = pEVar1;
  if (pEVar1 != (EC_GROUP *)0x0) {
    pEVar1 = (EC_GROUP *)0x1;
  }
  return (int)pEVar1;
}

