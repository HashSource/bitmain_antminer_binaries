
void EVP_MD_CTX_clear_flags(EVP_MD_CTX *ctx,int flags)

{
  ctx->flags = ctx->flags & ~flags;
  return;
}

