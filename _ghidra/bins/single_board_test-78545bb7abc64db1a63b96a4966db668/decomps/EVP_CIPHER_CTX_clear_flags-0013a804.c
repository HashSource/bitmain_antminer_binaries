
void EVP_CIPHER_CTX_clear_flags(EVP_CIPHER_CTX *ctx,int flags)

{
  ctx->flags = ctx->flags & ~flags;
  return;
}

