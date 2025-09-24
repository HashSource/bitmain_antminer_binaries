
undefined4 rc4_hmac_md5_ctrl(undefined4 param_1,int param_2,size_t param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  MD5_CTX *pMVar4;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (param_2 == 0x16) {
    if (param_3 == 0xd) {
      uVar3 = (uint)CONCAT11(*(undefined1 *)((int)param_4 + 0xb),*(undefined1 *)((int)param_4 + 0xc)
                            );
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        if (uVar3 < 0x10) {
          return 0xffffffff;
        }
        uVar3 = uVar3 - 0x10;
        *(char *)((int)param_4 + 0xc) = (char)uVar3;
        *(char *)((int)param_4 + 0xb) = (char)(uVar3 >> 8);
      }
      *(uint *)(iVar1 + 0x51c) = uVar3;
      pMVar4 = (MD5_CTX *)memcpy((void *)(iVar1 + 0x4c0),(void *)(iVar1 + 0x408),0x5c);
      MD5_Update(pMVar4,param_4,0xd);
      return 0x10;
    }
  }
  else if (param_2 == 0x17) {
    memset(&local_60,0,0x40);
    pMVar4 = (MD5_CTX *)(iVar1 + 0x408);
    if ((int)param_3 < 0x41) {
      memcpy(&local_60,param_4,param_3);
    }
    else {
      MD5_Init(pMVar4);
      MD5_Update(pMVar4,param_4,param_3);
      MD5_Final((uchar *)&local_60,pMVar4);
    }
    local_54 = local_54 ^ 0x36363636;
    local_60 = local_60 ^ 0x36363636;
    local_5c = local_5c ^ 0x36363636;
    local_4c = local_4c ^ 0x36363636;
    local_50 = local_50 ^ 0x36363636;
    local_48 = local_48 ^ 0x36363636;
    local_44 = local_44 ^ 0x36363636;
    local_58 = local_58 ^ 0x36363636;
    local_40 = local_40 ^ 0x36363636;
    local_3c = local_3c ^ 0x36363636;
    local_30 = local_30 ^ 0x36363636;
    local_34 = local_34 ^ 0x36363636;
    local_38 = local_38 ^ 0x36363636;
    local_28 = local_28 ^ 0x36363636;
    local_24 = local_24 ^ 0x36363636;
    local_2c = local_2c ^ 0x36363636;
    MD5_Init(pMVar4);
    MD5_Update(pMVar4,&local_60,0x40);
    local_60 = local_60 ^ 0x6a6a6a6a;
    local_5c = local_5c ^ 0x6a6a6a6a;
    local_50 = local_50 ^ 0x6a6a6a6a;
    local_58 = local_58 ^ 0x6a6a6a6a;
    local_4c = local_4c ^ 0x6a6a6a6a;
    local_48 = local_48 ^ 0x6a6a6a6a;
    local_40 = local_40 ^ 0x6a6a6a6a;
    local_54 = local_54 ^ 0x6a6a6a6a;
    local_44 = local_44 ^ 0x6a6a6a6a;
    local_30 = local_30 ^ 0x6a6a6a6a;
    local_3c = local_3c ^ 0x6a6a6a6a;
    local_2c = local_2c ^ 0x6a6a6a6a;
    local_34 = local_34 ^ 0x6a6a6a6a;
    local_38 = local_38 ^ 0x6a6a6a6a;
    local_24 = local_24 ^ 0x6a6a6a6a;
    local_28 = local_28 ^ 0x6a6a6a6a;
    MD5_Init((MD5_CTX *)(iVar1 + 0x464));
    MD5_Update((MD5_CTX *)(iVar1 + 0x464),&local_60,0x40);
    OPENSSL_cleanse(&local_60,0x40);
    return 1;
  }
  return 0xffffffff;
}

