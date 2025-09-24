
int EC_KEY_set_group(EC_KEY *key,EC_GROUP *group)

{
  int iVar1;
  EC_GROUP *pEVar2;
  
  if ((*(code **)(*(int *)key + 0x14) != (code *)0x0) &&
     (iVar1 = (**(code **)(*(int *)key + 0x14))(), iVar1 == 0)) {
    return 0;
  }
  EC_GROUP_free(*(EC_GROUP **)(key + 0xc));
  pEVar2 = EC_GROUP_dup(group);
  *(EC_GROUP **)(key + 0xc) = pEVar2;
  if (pEVar2 != (EC_GROUP *)0x0) {
    pEVar2 = (EC_GROUP *)0x1;
  }
  return (int)pEVar2;
}

