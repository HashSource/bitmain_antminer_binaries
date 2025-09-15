
void X509_STORE_CTX_set_depth(X509_STORE_CTX *ctx,int depth)

{
  X509_VERIFY_PARAM_set_depth(ctx->param,depth);
  return;
}

