
X509 * X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx)

{
  return (X509 *)ctx->error;
}

