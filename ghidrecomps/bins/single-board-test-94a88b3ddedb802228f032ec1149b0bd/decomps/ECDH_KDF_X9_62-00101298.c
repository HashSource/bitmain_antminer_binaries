
undefined4
ECDH_KDF_X9_62(uchar *param_1,uint param_2,void *param_3,uint param_4,void *param_5,uint param_6,
              EVP_MD *param_7)

{
  uint len;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  undefined local_84;
  undefined local_83;
  undefined local_82;
  undefined local_81;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  bVar5 = 0x3fffffff < param_2;
  bVar4 = param_2 == 0x40000000;
  if (param_2 < 0x40000001) {
    bVar5 = 0x3fffffff < param_6;
    bVar4 = param_6 == 0x40000000;
  }
  if (!bVar5 || bVar4) {
    uVar2 = 0;
    if (param_4 < 0x40000001) {
      iVar3 = 1;
      len = EVP_MD_size(param_7);
      EVP_MD_CTX_init(&EStack_80);
      do {
        EVP_DigestInit_ex(&EStack_80,param_7,(ENGINE *)0x0);
        local_81 = (undefined)iVar3;
        local_82 = (undefined)((uint)iVar3 >> 8);
        local_83 = (undefined)((uint)iVar3 >> 0x10);
        local_84 = (undefined)((uint)iVar3 >> 0x18);
        iVar1 = EVP_DigestUpdate(&EStack_80,param_3,param_4);
        if (iVar1 == 0) {
LAB_00101342:
          uVar2 = 0;
          goto LAB_00101344;
        }
        iVar3 = iVar3 + 1;
        iVar1 = EVP_DigestUpdate(&EStack_80,&local_84,4);
        if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(&EStack_80,param_5,param_6), iVar1 == 0))
        goto LAB_00101342;
        if (param_2 < len) {
          iVar3 = EVP_DigestFinal(&EStack_80,auStack_68,(uint *)0x0);
          if (iVar3 == 0) goto LAB_00101342;
          memcpy(param_1,auStack_68,param_2);
          OPENSSL_cleanse(auStack_68,len);
          break;
        }
        iVar1 = EVP_DigestFinal(&EStack_80,param_1,(uint *)0x0);
        if (iVar1 == 0) goto LAB_00101342;
        param_2 = param_2 - len;
        param_1 = param_1 + len;
      } while (param_2 != 0);
      uVar2 = 1;
LAB_00101344:
      EVP_MD_CTX_cleanup(&EStack_80);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

