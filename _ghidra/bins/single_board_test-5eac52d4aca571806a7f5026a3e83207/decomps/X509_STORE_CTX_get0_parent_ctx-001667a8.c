
X509_STORE_CTX * X509_STORE_CTX_get0_parent_ctx(X509_STORE_CTX *ctx)

{
  return (X509_STORE_CTX *)ctx->current_reasons;
}

