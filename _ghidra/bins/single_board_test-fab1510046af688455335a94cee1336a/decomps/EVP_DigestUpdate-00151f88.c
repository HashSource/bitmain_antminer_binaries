
int EVP_DigestUpdate(EVP_MD_CTX *ctx,void *d,size_t cnt)

{
  int iVar1;
  
  iVar1 = (*ctx->update)(ctx,d,cnt);
  return iVar1;
}

