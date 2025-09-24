
EVP_MD_CTX *
ecdh_KDF_X9_63(uchar *param_1,uint param_2,void *param_3,uint param_4,void *param_5,uint param_6,
              EVP_MD *param_7)

{
  EVP_MD_CTX *ctx;
  uint len;
  int iVar1;
  int iVar2;
  EVP_MD_CTX *pEVar3;
  bool bVar4;
  bool bVar5;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  uchar auStack_68 [68];
  
  bVar5 = 0x3fffffff < param_4;
  bVar4 = param_4 == 0x40000000;
  if (param_4 < 0x40000001) {
    bVar5 = 0x3fffffff < param_2;
    bVar4 = param_2 == 0x40000000;
  }
  if (param_6 < 0x40000001 && (!bVar5 || bVar4)) {
    ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (ctx != (EVP_MD_CTX *)0x0) {
      iVar2 = 1;
      len = EVP_MD_size(param_7);
      do {
        iVar1 = EVP_DigestInit_ex(ctx,param_7,(ENGINE *)0x0);
        if (iVar1 == 0) {
LAB_001b1cdc:
          pEVar3 = (EVP_MD_CTX *)0x0;
          goto LAB_001b1cde;
        }
        local_69 = (undefined1)iVar2;
        local_6a = (undefined1)((uint)iVar2 >> 8);
        local_6b = (undefined1)((uint)iVar2 >> 0x10);
        local_6c = (undefined1)((uint)iVar2 >> 0x18);
        iVar1 = EVP_DigestUpdate(ctx,param_3,param_4);
        if (iVar1 == 0) goto LAB_001b1cdc;
        iVar2 = iVar2 + 1;
        iVar1 = EVP_DigestUpdate(ctx,&local_6c,4);
        if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,param_5,param_6), iVar1 == 0))
        goto LAB_001b1cdc;
        if (param_2 < len) {
          iVar2 = EVP_DigestFinal(ctx,auStack_68,(uint *)0x0);
          if (iVar2 == 0) goto LAB_001b1cdc;
          memcpy(param_1,auStack_68,param_2);
          OPENSSL_cleanse(auStack_68,len);
          goto LAB_001b1d0e;
        }
        iVar1 = EVP_DigestFinal(ctx,param_1,(uint *)0x0);
        if (iVar1 == 0) goto LAB_001b1cdc;
        param_2 = param_2 - len;
        param_1 = param_1 + len;
        if (param_2 == 0) {
LAB_001b1d0e:
          pEVar3 = (EVP_MD_CTX *)0x1;
LAB_001b1cde:
          EVP_MD_CTX_free(ctx);
          return pEVar3;
        }
      } while( true );
    }
  }
  else {
    ctx = (EVP_MD_CTX *)0x0;
  }
  return ctx;
}

