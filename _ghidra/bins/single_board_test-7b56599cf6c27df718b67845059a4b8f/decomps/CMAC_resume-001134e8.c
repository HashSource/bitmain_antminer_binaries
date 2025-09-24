
int CMAC_resume(CMAC_CTX *ctx)

{
  int iVar1;
  
  if (*(int *)(ctx + 0x84) != -1) {
    iVar1 = EVP_EncryptInit_ex(*(EVP_CIPHER_CTX **)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                               (uchar *)(ctx + 0x44));
    return iVar1;
  }
  return 0;
}

