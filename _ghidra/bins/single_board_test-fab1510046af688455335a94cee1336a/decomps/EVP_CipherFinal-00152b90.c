
int EVP_CipherFinal(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  int iVar1;
  
  if (ctx->encrypt == 0) {
    iVar1 = EVP_DecryptFinal_ex(ctx,outm,outl);
    return iVar1;
  }
  iVar1 = EVP_EncryptFinal_ex(ctx,outm,outl);
  return iVar1;
}

