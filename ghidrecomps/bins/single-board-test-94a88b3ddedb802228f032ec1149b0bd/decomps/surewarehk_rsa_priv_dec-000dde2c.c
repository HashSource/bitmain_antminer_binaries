
size_t surewarehk_rsa_priv_dec
                 (int param_1,undefined4 param_2,uchar *param_3,RSA *param_4,int param_5)

{
  void *pvVar1;
  size_t sVar2;
  uchar *f;
  int iVar3;
  int iVar4;
  size_t local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar3 = DAT_000ddff4;
  local_68 = *DAT_000ddfec;
  uStack_64 = DAT_000ddfec[1];
  uStack_60 = DAT_000ddfec[2];
  uStack_5c = DAT_000ddfec[3];
  local_54 = 0;
  local_58 = DAT_000ddfec[4];
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (*(int *)(DAT_000ddff4 + 0x34) == 0) {
    iVar4 = *(int *)(DAT_000ddff4 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar4;
    }
    ERR_put_error(iVar4,0x6e,0x75,DAT_000ddff8,0x38f);
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,*(int *)(DAT_000ddff0 + 0xd4));
    if (pvVar1 == (void *)0x0) {
      iVar4 = *(int *)(iVar3 + 4);
      if (iVar4 == 0) {
        iVar4 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar4;
      }
      ERR_put_error(iVar4,0x6e,0x69,DAT_000ddff8,0x394);
      return 0;
    }
  }
  if (param_5 == 1) {
    sVar2 = (**(code **)(iVar3 + 0x34))(&local_68,param_1,param_2,&local_6c,param_3,pvVar1,1);
    surewarehk_error_handling(&local_68,0x6e,sVar2);
    if (sVar2 != 1) {
      return sVar2;
    }
    return local_6c;
  }
  sVar2 = (**(code **)(iVar3 + 0x34))(&local_68,param_1,param_2,&local_6c,param_3,pvVar1,0);
  surewarehk_error_handling(&local_68,0x6e,sVar2);
  iVar4 = DAT_000ddff4;
  if (sVar2 != 1) {
    return sVar2;
  }
  f = (uchar *)CRYPTO_malloc(local_6c,DAT_000ddff8,0x3ac);
  if (f == (uchar *)0x0) {
    iVar3 = *(int *)(iVar4 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar4 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x6e,0x41,DAT_000ddff8,0x3ae);
    return 1;
  }
  memcpy(f,param_3,local_6c);
  if (param_5 == 3) {
    sVar2 = RSA_padding_check_none(param_3,local_6c,f,param_1,local_6c);
  }
  else if (param_5 == 4) {
    sVar2 = RSA_padding_check_PKCS1_OAEP(param_3,local_6c,f,local_6c,local_6c,(uchar *)0x0,0);
  }
  else {
    if (param_5 != 2) {
      iVar3 = *(int *)(iVar4 + 4);
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar4 + 4) = iVar3;
      }
      ERR_put_error(iVar3,0x6e,0x6b,DAT_000ddff8,0x3c6);
      sVar2 = 1;
      goto LAB_000ddf3e;
    }
    sVar2 = RSA_padding_check_SSLv23(param_3,local_6c,f,param_1,local_6c);
  }
  iVar4 = DAT_000ddff4;
  if ((int)sVar2 < 0) {
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar4 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x6e,0x6a,DAT_000ddff8,0x3cb);
  }
LAB_000ddf3e:
  OPENSSL_cleanse(f,local_6c);
  CRYPTO_free(f);
  return sVar2;
}

