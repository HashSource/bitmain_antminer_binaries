
undefined4
DH_KDF_X9_42(uchar *param_1,uint param_2,void *param_3,size_t param_4,undefined4 param_5,
            uint *param_6,uint param_7,EVP_MD *param_8)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint len;
  size_t cnt;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uchar *local_b4;
  uchar *local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 *local_9c;
  undefined4 local_98;
  undefined4 *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  void *local_88;
  undefined4 local_84;
  EVP_MD_CTX EStack_80;
  uint local_68;
  undefined4 local_64;
  uint *local_60;
  undefined4 local_5c;
  
  local_b4 = (uchar *)0x0;
  if (0x40000000 < param_4) {
    return 0;
  }
  len = EVP_MD_size(param_8);
  EVP_MD_CTX_init(&EStack_80);
  uVar5 = param_2;
  if (param_2 < 0x40000001) {
    uVar5 = param_7;
  }
  if (uVar5 < 0x40000001) {
    local_94 = &local_90;
    local_9c = &local_98;
    local_84 = 0;
    local_88 = DAT_00100d44;
    local_a0 = param_5;
    local_90 = 4;
    local_8c = 4;
    local_98 = 4;
    if (param_6 != (uint *)0x0) {
      local_64 = 4;
      local_5c = 0;
      local_60 = param_6;
      param_6 = &local_68;
      local_68 = param_7;
    }
    cnt = CMS_SharedInfo_encode(&local_b4,&local_a0,param_6,param_2);
    puVar1 = local_b4;
    if (0 < (int)cnt) {
      local_b0 = local_b4;
      iVar4 = ASN1_get_object(&local_b0,&local_a4,&local_ac,&local_a8,cnt);
      puVar2 = local_b0;
      if (((-1 < iVar4 << 0x18) && (local_ac == 0x10)) && (local_a8 == 0)) {
        iVar4 = cnt - (int)local_b0;
        uVar5 = ASN1_get_object(&local_b0,&local_a4,&local_ac,&local_a8,(long)(puVar1 + iVar4));
        puVar3 = local_b0;
        if ((((uVar5 & 0x80) == 0) && (local_ac == 0x10)) && (local_a8 == 0)) {
          iVar4 = (int)(puVar1 + iVar4) - (int)local_b0;
          uVar5 = ASN1_get_object(&local_b0,&local_a4,&local_ac,&local_a8,(long)(puVar2 + iVar4));
          if ((((uVar5 & 0x80) == 0) && (local_ac == 6)) && (local_a8 == 0)) {
            local_b0 = local_b0 + local_a4;
            iVar4 = ASN1_get_object(&local_b0,&local_a4,&local_ac,&local_a8,
                                    (long)(puVar3 + ((int)(puVar2 + iVar4) - (int)local_b0)));
            puVar1 = local_b0;
            if ((((-1 < iVar4 << 0x18) && (local_ac == 4)) && (local_a8 == 0)) &&
               (iVar4 = CRYPTO_memcmp(local_b0,DAT_00100d44,4), iVar4 == 0)) {
              iVar4 = 1;
              do {
                EVP_DigestInit_ex(&EStack_80,param_8,(ENGINE *)0x0);
                iVar6 = EVP_DigestUpdate(&EStack_80,param_3,param_4);
                if (iVar6 == 0) goto LAB_00100bf2;
                puVar1[3] = (uchar)iVar4;
                puVar1[2] = (uchar)((uint)iVar4 >> 8);
                puVar1[1] = (uchar)((uint)iVar4 >> 0x10);
                *puVar1 = (uchar)((uint)iVar4 >> 0x18);
                iVar6 = EVP_DigestUpdate(&EStack_80,local_b4,cnt);
                if (iVar6 == 0) goto LAB_00100bf2;
                if (param_2 < len) {
                  iVar4 = EVP_DigestFinal(&EStack_80,(uchar *)&local_68,(uint *)0x0);
                  if (iVar4 == 0) goto LAB_00100bf2;
                  memcpy(param_1,&local_68,param_2);
                  OPENSSL_cleanse(&local_68,len);
                  break;
                }
                iVar6 = EVP_DigestFinal(&EStack_80,param_1,(uint *)0x0);
                if (iVar6 == 0) goto LAB_00100bf2;
                param_2 = param_2 - len;
                param_1 = param_1 + len;
                iVar4 = iVar4 + 1;
              } while (param_2 != 0);
              uVar7 = 1;
              goto LAB_00100bf4;
            }
          }
        }
      }
    }
  }
LAB_00100bf2:
  uVar7 = 0;
LAB_00100bf4:
  if (local_b4 != (uchar *)0x0) {
    CRYPTO_free(local_b4);
  }
  EVP_MD_CTX_cleanup(&EStack_80);
  return uVar7;
}

