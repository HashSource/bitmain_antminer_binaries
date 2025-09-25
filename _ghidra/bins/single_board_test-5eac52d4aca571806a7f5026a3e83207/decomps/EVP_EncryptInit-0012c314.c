
int EVP_EncryptInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv)

{
  int iVar1;
  
  iVar1 = EVP_CipherInit(ctx,cipher,key,iv,1);
  return iVar1;
}

