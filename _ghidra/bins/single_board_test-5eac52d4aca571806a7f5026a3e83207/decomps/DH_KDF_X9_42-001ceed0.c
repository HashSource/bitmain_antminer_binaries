
undefined4
DH_KDF_X9_42(uchar *param_1,uint param_2,void *param_3,uint param_4,undefined4 param_5,uint *param_6
            ,uint param_7,EVP_MD *param_8)

{
  uchar *puVar1;
  uchar *puVar2;
  EVP_MD_CTX *ctx;
  uint len;
  size_t cnt;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uchar *local_9c;
  uchar *local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  undefined4 *local_84;
  undefined4 local_80;
  undefined4 *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 *local_70;
  undefined4 local_6c;
  uint local_68 [2];
  uint *local_60;
  undefined4 local_5c;
  
  local_9c = (uchar *)0x0;
  if ((0x40000000 < param_4) || (ctx = (EVP_MD_CTX *)EVP_MD_CTX_new(), ctx == (EVP_MD_CTX *)0x0)) {
    return 0;
  }
  len = EVP_MD_size(param_8);
  bVar7 = 0x3fffffff < param_2;
  bVar6 = param_2 == 0x40000000;
  if (param_2 < 0x40000001) {
    bVar7 = 0x3fffffff < param_7;
    bVar6 = param_7 == 0x40000000;
  }
  if (!bVar7 || bVar6) {
    local_6c = 0;
    local_78 = 4;
    local_70 = &ctr_23595;
    local_7c = &local_78;
    local_84 = &local_80;
    local_88 = param_5;
    local_74 = 4;
    local_80 = 4;
    if (param_6 != (uint *)0x0) {
      local_68[1] = 4;
      local_5c = 0;
      local_60 = param_6;
      param_6 = local_68;
      local_68[0] = param_7;
    }
    cnt = CMS_SharedInfo_encode(&local_9c,&local_88,param_6,param_2);
    puVar1 = local_9c;
    if (0 < (int)cnt) {
      local_98 = local_9c;
      iVar3 = ASN1_get_object(&local_98,&local_8c,&local_94,&local_90,cnt);
      puVar2 = local_98;
      if (((-1 < iVar3 << 0x18) && (local_94 == 0x10)) && (local_90 == 0)) {
        iVar5 = cnt - ((int)local_98 - (int)puVar1);
        iVar3 = ASN1_get_object(&local_98,&local_8c,&local_94,&local_90,iVar5);
        puVar1 = local_98;
        if (((-1 < iVar3 << 0x18) && (local_94 == 0x10)) && (local_90 == 0)) {
          iVar5 = iVar5 - ((int)local_98 - (int)puVar2);
          iVar3 = ASN1_get_object(&local_98,&local_8c,&local_94,&local_90,iVar5);
          if (((-1 < iVar3 << 0x18) && (local_94 == 6)) && (local_90 == 0)) {
            local_98 = local_98 + local_8c;
            iVar3 = ASN1_get_object(&local_98,&local_8c,&local_94,&local_90,
                                    iVar5 - ((int)local_98 - (int)puVar1));
            puVar1 = local_98;
            if ((((-1 < iVar3 << 0x18) && (local_94 == 4)) && (local_90 == 0)) &&
               (iVar3 = CRYPTO_memcmp(local_98,&ctr_23595,4), iVar3 == 0)) {
              iVar3 = 1;
              do {
                iVar5 = EVP_DigestInit_ex(ctx,param_8,(ENGINE *)0x0);
                if ((iVar5 == 0) || (iVar5 = EVP_DigestUpdate(ctx,param_3,param_4), iVar5 == 0))
                goto LAB_001cef7e;
                puVar1[3] = (uchar)iVar3;
                puVar1[2] = (uchar)((uint)iVar3 >> 8);
                puVar1[1] = (uchar)((uint)iVar3 >> 0x10);
                *puVar1 = (uchar)((uint)iVar3 >> 0x18);
                iVar5 = EVP_DigestUpdate(ctx,local_9c,cnt);
                if (iVar5 == 0) goto LAB_001cef7e;
                if (param_2 < len) {
                  iVar3 = EVP_DigestFinal(ctx,(uchar *)local_68,(uint *)0x0);
                  if (iVar3 == 0) goto LAB_001cef7e;
                  memcpy(param_1,local_68,param_2);
                  OPENSSL_cleanse(local_68,len);
                  break;
                }
                iVar5 = EVP_DigestFinal(ctx,param_1,(uint *)0x0);
                if (iVar5 == 0) goto LAB_001cef7e;
                param_2 = param_2 - len;
                param_1 = param_1 + len;
                iVar3 = iVar3 + 1;
              } while (param_2 != 0);
              uVar4 = 1;
              goto LAB_001cef80;
            }
          }
        }
      }
    }
  }
LAB_001cef7e:
  uVar4 = 0;
LAB_001cef80:
  CRYPTO_free(local_9c);
  EVP_MD_CTX_free(ctx);
  return uVar4;
}

