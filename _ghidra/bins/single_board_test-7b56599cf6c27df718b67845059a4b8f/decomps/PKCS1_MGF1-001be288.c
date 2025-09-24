
int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_r6;
  int iVar4;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  uchar auStack_68 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if ((ctx == (EVP_MD_CTX *)0x0) || (iVar1 = EVP_MD_size(dgst), iVar1 < 0)) {
LAB_001be352:
    iVar1 = -1;
  }
  else {
    if (0 < len) {
      unaff_r6 = 0;
    }
    iVar3 = unaff_r6;
    if (0 < len) {
      do {
        local_69 = (undefined1)unaff_r6;
        local_6c = (undefined1)((uint)unaff_r6 >> 0x18);
        local_6b = (undefined1)((uint)unaff_r6 >> 0x10);
        iVar4 = iVar1 + iVar3;
        local_6a = (undefined1)((uint)unaff_r6 >> 8);
        unaff_r6 = unaff_r6 + 1;
        iVar2 = EVP_DigestInit_ex(ctx,dgst,(ENGINE *)0x0);
        if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(ctx,seed,seedlen), iVar2 == 0)) ||
           (iVar2 = EVP_DigestUpdate(ctx,&local_6c,4), iVar2 == 0)) goto LAB_001be352;
        if (len < iVar4) {
          iVar1 = EVP_DigestFinal_ex(ctx,auStack_68,(uint *)0x0);
          if (iVar1 == 0) goto LAB_001be352;
          iVar1 = 0;
          memcpy(mask + iVar3,auStack_68,len - iVar3);
          goto LAB_001be33a;
        }
        iVar3 = EVP_DigestFinal_ex(ctx,mask + iVar3,(uint *)0x0);
        if (iVar3 == 0) goto LAB_001be352;
        iVar3 = iVar4;
      } while (iVar4 < len);
    }
    iVar1 = 0;
  }
LAB_001be33a:
  OPENSSL_cleanse(auStack_68,0x40);
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

