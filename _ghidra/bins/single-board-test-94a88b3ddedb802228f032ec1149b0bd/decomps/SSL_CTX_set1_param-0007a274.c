
int SSL_CTX_set1_param(SSL_CTX *ctx,X509_VERIFY_PARAM *vpm)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set1(ctx->param,vpm);
  return iVar1;
}

