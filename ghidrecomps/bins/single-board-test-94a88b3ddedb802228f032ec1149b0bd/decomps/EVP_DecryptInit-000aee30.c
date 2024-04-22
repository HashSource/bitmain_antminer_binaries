
int EVP_DecryptInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv)

{
  int iVar1;
  
  if (cipher != (EVP_CIPHER *)0x0) {
    memset(ctx,0,0x8c);
  }
  iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,key,iv,0);
  return iVar1;
}

