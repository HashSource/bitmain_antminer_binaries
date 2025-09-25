
EC_KEY * EC_KEY_new_by_curve_name(int nid)

{
  EC_KEY *key;
  EC_GROUP *pEVar1;
  int iVar2;
  
  key = EC_KEY_new();
  if (key != (EC_KEY *)0x0) {
    pEVar1 = EC_GROUP_new_by_curve_name(nid);
    *(EC_GROUP **)(key + 0xc) = pEVar1;
    if (pEVar1 == (EC_GROUP *)0x0) {
      EC_KEY_free(key);
      key = (EC_KEY *)0x0;
    }
    else if ((*(code **)(*(int *)key + 0x14) != (code *)0x0) &&
            (iVar2 = (**(code **)(*(int *)key + 0x14))(key,pEVar1), iVar2 == 0)) {
      EC_KEY_free(key);
      key = (EC_KEY *)0x0;
    }
  }
  return key;
}

