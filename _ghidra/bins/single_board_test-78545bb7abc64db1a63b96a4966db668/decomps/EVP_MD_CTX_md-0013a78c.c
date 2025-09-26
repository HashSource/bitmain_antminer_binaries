
EVP_MD * EVP_MD_CTX_md(EVP_MD_CTX *ctx)

{
  if (ctx != (EVP_MD_CTX *)0x0) {
    ctx = (EVP_MD_CTX *)ctx->digest;
  }
  return (EVP_MD *)ctx;
}

