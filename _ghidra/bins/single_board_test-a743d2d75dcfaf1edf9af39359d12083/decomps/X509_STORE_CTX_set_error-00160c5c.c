
void X509_STORE_CTX_set_error(X509_STORE_CTX *ctx,int s)

{
  ctx->error = s;
  return;
}

