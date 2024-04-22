
uint tls1_check_ec_tmp_key(int param_1,int param_2)

{
  uint uVar1;
  EC_GROUP *pEVar2;
  EC_METHOD *pEVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  EC_KEY *key;
  undefined local_20;
  char local_1f;
  
  iVar5 = *(int *)(param_1 + 0x98);
  key = *(EC_KEY **)(iVar5 + 0x2c);
  if ((*(uint *)(iVar5 + 0x38) & 0x30000) == 0) {
    if (*(int *)(iVar5 + 0x34) != 0) {
      iVar5 = tls1_shared_curve(param_1,0);
      if (iVar5 != 0) {
        return 1;
      }
      return 0;
    }
    if (key == (EC_KEY *)0x0) {
      if (*(int *)(iVar5 + 0x30) != 0) {
        return 1;
      }
      return 0;
    }
    pEVar2 = EC_KEY_get0_group(key);
    if ((pEVar2 != (EC_GROUP *)0x0) &&
       (pEVar3 = EC_GROUP_method_of(pEVar2), pEVar3 != (EC_METHOD *)0x0)) {
      iVar5 = EC_METHOD_get_field_type(pEVar3);
      EC_GROUP_get_curve_name(pEVar2);
      iVar4 = tls1_ec_nid2curve_id();
      if (iVar4 == 0) {
        local_20 = 0xff;
        if (iVar5 == 0x196) {
          local_1f = 1;
        }
        else {
          local_1f = 2;
        }
      }
      else {
        local_20 = 0;
        local_1f = (char)iVar4;
      }
      uVar1 = tls1_check_ec_key_constprop_4(param_1,&local_20);
      return uVar1;
    }
  }
  else {
    if (param_2 == 0x300c02b) {
      local_1f = '\x17';
    }
    else {
      if (param_2 != 0x300c02c) {
        return 0;
      }
      local_1f = '\x18';
    }
    local_20 = 0;
    iVar5 = tls1_check_ec_key_constprop_4(param_1,&local_20);
    if (iVar5 != 0) {
      if ((*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) &&
         (*(int *)(*(int *)(param_1 + 0x98) + 0x30) == 0)) {
        if (key == (EC_KEY *)0x0) {
          return 0;
        }
        pEVar2 = EC_KEY_get0_group(key);
        if (pEVar2 == (EC_GROUP *)0x0) {
          return 0;
        }
        pEVar3 = EC_GROUP_method_of(pEVar2);
        if (pEVar3 == (EC_METHOD *)0x0) {
          return 0;
        }
        iVar5 = EC_METHOD_get_field_type(pEVar3);
        EC_GROUP_get_curve_name(pEVar2);
        iVar4 = tls1_ec_nid2curve_id();
        if (iVar4 == 0) {
          if (iVar5 == 0x196) {
            cVar6 = '\x01';
          }
          else {
            cVar6 = '\x02';
          }
          return (uint)(local_1f == cVar6);
        }
      }
      return 1;
    }
  }
  return 0;
}

