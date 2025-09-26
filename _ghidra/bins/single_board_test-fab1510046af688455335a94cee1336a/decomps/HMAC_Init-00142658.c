
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  int iVar1;
  
  if (md != (EVP_MD *)0x0 && key != (void *)0x0) {
    EVP_MD_CTX_init(&ctx->i_ctx);
    EVP_MD_CTX_init(&ctx->o_ctx);
    EVP_MD_CTX_init(&ctx->md_ctx);
    ctx->md = (EVP_MD *)0x0;
  }
  iVar1 = HMAC_Init_ex(ctx,key,len,md,(ENGINE *)0x0);
  return iVar1;
}

