
int EVP_DigestFinal(EVP_MD_CTX *ctx,uchar *md,uint *s)

{
  int iVar1;
  
  iVar1 = EVP_DigestFinal_ex(ctx,md,s);
  EVP_MD_CTX_reset(ctx);
  return iVar1;
}

