
int SSL_CTX_get_verify_depth(SSL_CTX *ctx)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_get_depth(ctx->param);
  return iVar1;
}

