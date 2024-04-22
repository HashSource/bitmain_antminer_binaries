
int cca_rsa_sign(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                RSA *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined auStack_70 [4];
  undefined4 local_6c;
  int local_68;
  uchar *local_64;
  undefined auStack_60 [8];
  undefined4 local_58;
  undefined4 uStack_54;
  X509_SIG local_50;
  ASN1_TYPE local_48;
  X509_ALGOR local_40;
  ASN1_OCTET_STRING local_38;
  
  local_58 = *DAT_000d9000;
  uStack_54 = DAT_000d9000[1];
  local_74 = 0x100;
  local_7c = 0;
  local_78 = 1;
  puVar1 = (undefined4 *)RSA_get_ex_data(param_6,*DAT_000d900c);
  local_68 = 0x24;
  local_6c = *puVar1;
  if (param_1 == 4 || param_1 == 0x40) {
    local_50.algor = &local_40;
    local_40.algorithm = OBJ_nid2obj(param_1);
    iVar3 = DAT_000d9008;
    if (local_40.algorithm == (ASN1_OBJECT *)0x0) {
      iVar2 = *(int *)(DAT_000d9008 + 0xc);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0xc) = iVar2;
      }
      ERR_put_error(iVar2,0x69,0x6d,DAT_000d9004,0x2f1);
      return 0;
    }
    if ((local_40.algorithm)->length == 0) {
      iVar2 = *(int *)(DAT_000d9008 + 0xc);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0xc) = iVar2;
      }
      ERR_put_error(iVar2,0x69,0x65,DAT_000d9004,0x2f7);
      return 0;
    }
    local_40.parameter = &local_48;
    local_50.digest = &local_38;
    local_48.value.ptr = (char *)0x0;
    local_48.type = 5;
    local_38.length = param_3;
    local_38.data = param_2;
    local_68 = i2d_X509_SIG(&local_50,(uchar **)0x0);
  }
  iVar2 = RSA_size(param_6);
  iVar3 = DAT_000d9008;
  if (iVar2 < local_68 + -1) {
    iVar2 = *(int *)(DAT_000d9008 + 0xc);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar3 + 0xc) = iVar2;
    }
    iVar3 = 0x30a;
LAB_000d8f58:
    ERR_put_error(iVar2,0x69,0x6b,DAT_000d9004,iVar3);
    return 0;
  }
  if (param_1 == 0x40) {
    param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,DAT_000d9004,0x326);
    iVar3 = DAT_000d9008;
    if (param_2 == (uchar *)0x0) {
      iVar2 = *(int *)(DAT_000d9008 + 0xc);
      local_64 = param_2;
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0xc) = iVar2;
      }
      iVar3 = 0x328;
LAB_000d8f8c:
      ERR_put_error(iVar2,0x69,0x41,DAT_000d9004,iVar3);
      return 0;
    }
  }
  else {
    if (param_1 == 0x72) {
      if (param_3 != 0x24) {
        iVar2 = *(int *)(DAT_000d9008 + 0xc);
        if (iVar2 == 0) {
          iVar2 = ERR_get_next_error_library();
          *(int *)(iVar3 + 0xc) = iVar2;
        }
        iVar3 = 0x312;
        goto LAB_000d8f58;
      }
      local_68 = 0x24;
      goto LAB_000d8ecc;
    }
    if (param_1 != 4) {
      return 0;
    }
    param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,DAT_000d9004,0x31b);
    iVar3 = DAT_000d9008;
    if (param_2 == (uchar *)0x0) {
      iVar2 = *(int *)(DAT_000d9008 + 0xc);
      local_64 = param_2;
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0xc) = iVar2;
      }
      iVar3 = 0x31d;
      goto LAB_000d8f8c;
    }
  }
  local_64 = param_2;
  i2d_X509_SIG(&local_50,&local_64);
LAB_000d8ecc:
  (**(code **)(DAT_000d9008 + 0x1c))
            (&local_84,&local_80,&local_7c,auStack_60,&local_78,&local_58,&local_6c,puVar1 + 1,
             &local_68,param_2,&local_74,auStack_70,param_4);
  if (param_1 == 4 || param_1 == 0x40) {
    OPENSSL_cleanse(param_2,iVar2 + 1);
    CRYPTO_free(param_2);
  }
  *param_5 = local_74;
  if (local_84 != 0) {
    return 0;
  }
  if (1 < local_80) {
    return 0;
  }
  return 1 - local_80;
}

