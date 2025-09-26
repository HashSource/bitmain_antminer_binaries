
void HMAC_CTX_set_flags(HMAC_CTX *ctx,ulong flags)

{
  EVP_MD_CTX_set_flags(&ctx->i_ctx,flags);
  EVP_MD_CTX_set_flags(&ctx->o_ctx,flags);
  EVP_MD_CTX_set_flags(&ctx->md_ctx,flags);
  return;
}

