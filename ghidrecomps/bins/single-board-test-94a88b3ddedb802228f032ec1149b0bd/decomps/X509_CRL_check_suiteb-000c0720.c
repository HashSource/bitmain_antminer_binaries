
undefined4 X509_CRL_check_suiteb(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  EC_GROUP *group;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_3 & 0x30000) == 0) {
    return 0;
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(*param_1 + 4));
  if (((param_2 == (int *)0x0) || (*param_2 != 0x198)) ||
     (group = EC_KEY_get0_group((EC_KEY *)param_2[5]), group == (EC_GROUP *)0x0)) {
    return 0x39;
  }
  iVar2 = EC_GROUP_get_curve_name(group);
  if (iVar2 == 0x2cb) {
    if (iVar1 == 0x31b || iVar1 == -1) {
      if ((param_3 & 0x20000) == 0) {
        uVar3 = 0x3c;
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
  }
  else {
    if (iVar2 != 0x19f) {
      return 0x3a;
    }
    if (iVar1 == 0x31a || iVar1 == -1) {
      if ((param_3 & 0x10000) == 0) {
        uVar3 = 0x3c;
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
  }
  return 0x3b;
}

