
undefined4 X509_CRL_check_suiteb(int param_1,EVP_PKEY *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  EC_KEY *key;
  EC_GROUP *group;
  
  if ((param_3 & 0x30000) == 0) {
    return 0;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)(param_1 + 4));
  if ((param_2 != (EVP_PKEY *)0x0) && (iVar2 = EVP_PKEY_id(param_2), iVar2 == 0x198)) {
    key = (EC_KEY *)EVP_PKEY_get0_EC_KEY(param_2);
    group = EC_KEY_get0_group(key);
    if (group != (EC_GROUP *)0x0) {
      iVar2 = EC_GROUP_get_curve_name(group);
      if (iVar2 == 0x2cb) {
        if (iVar1 != -1 && iVar1 != 0x31b) {
          return 0x3b;
        }
        iVar1 = param_3 << 0xe;
      }
      else {
        if (iVar2 != 0x19f) {
          return 0x3a;
        }
        if (iVar1 != -1 && iVar1 != 0x31a) {
          return 0x3b;
        }
        iVar1 = param_3 << 0xf;
      }
      if (iVar1 < 0) {
        return 0;
      }
      return 0x3c;
    }
  }
  return 0x39;
}

