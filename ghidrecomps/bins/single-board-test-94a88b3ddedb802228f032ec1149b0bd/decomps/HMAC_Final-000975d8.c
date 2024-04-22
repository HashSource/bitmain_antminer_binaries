
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  int iVar1;
  EVP_MD_CTX *ctx_00;
  size_t local_5c;
  uchar auStack_58 [68];
  
  if (ctx->md != (EVP_MD *)0x0) {
    ctx_00 = &ctx->md_ctx;
    iVar1 = EVP_DigestFinal_ex(ctx_00,auStack_58,&local_5c);
    if (((iVar1 != 0) && (iVar1 = EVP_MD_CTX_copy_ex(ctx_00,&ctx->o_ctx), iVar1 != 0)) &&
       (iVar1 = EVP_DigestUpdate(ctx_00,auStack_58,local_5c), iVar1 != 0)) {
      iVar1 = EVP_DigestFinal_ex(ctx_00,md,len);
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

