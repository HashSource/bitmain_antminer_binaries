
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  int iVar1;
  size_t local_5c;
  uchar auStack_58 [68];
  
  if (ctx->md == (EVP_MD *)0x0) {
    return 0;
  }
  iVar1 = EVP_DigestFinal_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,auStack_58,&local_5c);
  if (((iVar1 == 0) ||
      (iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,
                                  (EVP_MD_CTX *)(ctx->md_ctx).flags), iVar1 == 0)) ||
     (iVar1 = EVP_DigestUpdate((EVP_MD_CTX *)(ctx->md_ctx).digest,auStack_58,local_5c), iVar1 == 0))
  {
    iVar1 = 0;
  }
  else {
    iVar1 = EVP_DigestFinal_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,md,len);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

