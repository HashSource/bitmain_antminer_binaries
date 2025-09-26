
int ctrl(EVP_PKEY_CTX *ctx,int type,int p1,void *p2)

{
  SHA_CTX *c;
  int iVar1;
  uchar auStack_54 [20];
  undefined1 auStack_40 [40];
  
  if (type != 0x1d) {
    return -2;
  }
  if (((ctx != (EVP_PKEY_CTX *)0x0) && (c = (SHA_CTX *)EVP_MD_CTX_md_data(), p1 == 0x30)) &&
     (iVar1 = SHA1_Update(c,p2,0x30), 0 < iVar1)) {
    memset(auStack_40,0x36,0x28);
    iVar1 = SHA1_Update(c,auStack_40,0x28);
    if (iVar1 != 0) {
      iVar1 = SHA1_Final(auStack_54,c);
      if (((iVar1 != 0) && (iVar1 = SHA1_Init(c), iVar1 != 0)) &&
         (iVar1 = SHA1_Update(c,p2,0x30), 0 < iVar1)) {
        memset(auStack_40,0x5c,0x28);
        iVar1 = SHA1_Update(c,auStack_40,0x28);
        if ((iVar1 != 0) && (iVar1 = SHA1_Update(c,auStack_54,0x14), iVar1 != 0)) {
          OPENSSL_cleanse(auStack_54,0x14);
          return 1;
        }
      }
    }
  }
  return 0;
}

