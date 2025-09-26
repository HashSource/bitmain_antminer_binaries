
int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv)

{
  int iVar1;
  
  iVar1 = EVP_CipherInit_ex(ctx,cipher,impl,key,iv,1);
  return iVar1;
}

