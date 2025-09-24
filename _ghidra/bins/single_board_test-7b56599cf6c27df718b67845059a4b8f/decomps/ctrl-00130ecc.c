
int ctrl(EVP_PKEY_CTX *ctx,int type,int p1,void *p2)

{
  MD5_CTX *c;
  MD5_CTX *pMVar1;
  int iVar2;
  SHA_CTX *c_00;
  uchar auStack_7c [16];
  uchar auStack_6c [20];
  undefined1 auStack_58 [52];
  
  if (type != 0x1d) {
    return -2;
  }
  if ((ctx != (EVP_PKEY_CTX *)0x0) && (c = (MD5_CTX *)EVP_MD_CTX_md_data(), p1 == 0x30)) {
    pMVar1 = (MD5_CTX *)EVP_MD_CTX_md_data(ctx);
    iVar2 = MD5_Update(pMVar1,p2,0x30);
    if ((iVar2 != 0) && (iVar2 = SHA1_Update((SHA_CTX *)(pMVar1 + 1),p2,0x30), 0 < iVar2)) {
      memset(auStack_58,0x36,0x30);
      iVar2 = MD5_Update(c,auStack_58,0x30);
      if (iVar2 != 0) {
        iVar2 = MD5_Final(auStack_7c,c);
        if (iVar2 != 0) {
          c_00 = (SHA_CTX *)(c + 1);
          iVar2 = SHA1_Update(c_00,auStack_58,0x28);
          if (iVar2 != 0) {
            iVar2 = SHA1_Final(auStack_6c,c_00);
            if (iVar2 != 0) {
              pMVar1 = (MD5_CTX *)EVP_MD_CTX_md_data(ctx);
              iVar2 = MD5_Init(pMVar1);
              if (((iVar2 != 0) && (iVar2 = SHA1_Init((SHA_CTX *)(pMVar1 + 1)), iVar2 != 0)) &&
                 (iVar2 = update(ctx,p2,0x30), 0 < iVar2)) {
                memset(auStack_58,0x5c,0x30);
                iVar2 = MD5_Update(c,auStack_58,0x30);
                if (((iVar2 != 0) && (iVar2 = MD5_Update(c,auStack_7c,0x10), iVar2 != 0)) &&
                   ((iVar2 = SHA1_Update(c_00,auStack_58,0x28), iVar2 != 0 &&
                    (iVar2 = SHA1_Update(c_00,auStack_6c,0x14), iVar2 != 0)))) {
                  OPENSSL_cleanse(auStack_7c,0x10);
                  OPENSSL_cleanse(auStack_6c,0x14);
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

