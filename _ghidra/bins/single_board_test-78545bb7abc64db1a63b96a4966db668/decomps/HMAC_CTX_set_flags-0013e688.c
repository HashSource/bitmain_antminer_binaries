
void HMAC_CTX_set_flags(HMAC_CTX *ctx,ulong flags)

{
  EVP_MD_CTX_set_flags((EVP_MD_CTX *)(ctx->md_ctx).engine,flags);
  EVP_MD_CTX_set_flags((EVP_MD_CTX *)(ctx->md_ctx).flags,flags);
  EVP_MD_CTX_set_flags((EVP_MD_CTX *)(ctx->md_ctx).digest,flags);
  return;
}

