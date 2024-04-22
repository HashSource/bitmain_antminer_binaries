
int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined local_84;
  undefined local_83;
  undefined local_82;
  undefined local_81;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  EVP_MD_CTX_init(&EStack_80);
  iVar1 = EVP_MD_size(dgst);
  if (iVar1 < 0) {
LAB_000fbc26:
    iVar1 = -1;
  }
  else {
    if (0 < len) {
      iVar4 = 0;
      iVar3 = 0;
      do {
        local_81 = (undefined)iVar4;
        local_84 = (undefined)((uint)iVar4 >> 0x18);
        iVar5 = iVar3 + iVar1;
        local_83 = (undefined)((uint)iVar4 >> 0x10);
        local_82 = (undefined)((uint)iVar4 >> 8);
        iVar4 = iVar4 + 1;
        iVar2 = EVP_DigestInit_ex(&EStack_80,dgst,(ENGINE *)0x0);
        if (iVar2 == 0) goto LAB_000fbc26;
        iVar2 = EVP_DigestUpdate(&EStack_80,seed,seedlen);
        if (iVar2 == 0) goto LAB_000fbc26;
        iVar2 = EVP_DigestUpdate(&EStack_80,&local_84,4);
        if (iVar2 == 0) goto LAB_000fbc26;
        if (len < iVar5) {
          iVar1 = EVP_DigestFinal_ex(&EStack_80,auStack_68,(uint *)0x0);
          if (iVar1 == 0) goto LAB_000fbc26;
          iVar1 = 0;
          memcpy(mask + iVar3,auStack_68,len - iVar3);
          goto LAB_000fbc18;
        }
        iVar3 = EVP_DigestFinal_ex(&EStack_80,mask + (iVar5 - iVar1),(uint *)0x0);
        if (iVar3 == 0) goto LAB_000fbc26;
        iVar3 = iVar5;
      } while (iVar5 < len);
    }
    iVar1 = 0;
  }
LAB_000fbc18:
  EVP_MD_CTX_cleanup(&EStack_80);
  return iVar1;
}

