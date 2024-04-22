
int decode_gost_algor_params(EVP_PKEY *param_1,X509_ALGOR *param_2)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int iVar4;
  DSA *key;
  EC_KEY *key_00;
  ASN1_OBJECT *local_28;
  int local_24;
  undefined4 *local_20;
  undefined4 local_1c [2];
  
  local_28 = (ASN1_OBJECT *)0x0;
  local_24 = -1;
  X509_ALGOR_get0(&local_28,&local_24,&local_20,param_2);
  if (local_24 != 0x10) {
    ERR_GOST_error(99,99,DAT_001154f4,0x68);
    return 0;
  }
  local_1c[0] = local_20[2];
  iVar1 = OBJ_obj2nid(local_28);
  ppAVar2 = (ASN1_OBJECT **)d2i_GOST_KEY_PARAMS(0,local_1c,*local_20);
  if (ppAVar2 != (ASN1_OBJECT **)0x0) {
    iVar3 = OBJ_obj2nid(*ppAVar2);
    GOST_KEY_PARAMS_free(ppAVar2);
    iVar4 = EVP_PKEY_set_type(param_1,iVar1);
    if (iVar4 == 0) {
      ERR_GOST_error(99,0x44,DAT_001154f4,0x77);
      return 0;
    }
    if (iVar1 == 0x32b) {
      key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
      if (key_00 == (EC_KEY *)0x0) {
        key_00 = EC_KEY_new();
        iVar1 = EVP_PKEY_assign(param_1,0x32b,key_00);
        if (iVar1 == 0) {
          return 0;
        }
      }
      iVar1 = fill_GOST2001_params(key_00,iVar3);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    else {
      if (iVar1 != 0x32c) {
        return 1;
      }
      key = (DSA *)EVP_PKEY_get0(param_1);
      if (key == (DSA *)0x0) {
        key = DSA_new();
        iVar1 = EVP_PKEY_assign(param_1,0x32c,key);
        if (iVar1 == 0) {
          return 0;
        }
      }
      iVar1 = fill_GOST94_params(key,iVar3);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    return iVar1;
  }
  ERR_GOST_error(99,100,DAT_001154f4,0x71);
  return 0;
}

