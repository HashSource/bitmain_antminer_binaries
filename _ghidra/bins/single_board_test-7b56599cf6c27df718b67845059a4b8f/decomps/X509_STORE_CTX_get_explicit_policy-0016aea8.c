
int X509_STORE_CTX_get_explicit_policy(X509_STORE_CTX *ctx)

{
  return (int)ctx->tree;
}

