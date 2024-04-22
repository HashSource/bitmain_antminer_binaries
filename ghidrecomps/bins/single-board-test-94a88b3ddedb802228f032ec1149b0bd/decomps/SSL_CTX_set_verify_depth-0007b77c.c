
void SSL_CTX_set_verify_depth(SSL_CTX *ctx,int depth)

{
  X509_VERIFY_PARAM_set_depth(ctx->param,depth);
  return;
}

