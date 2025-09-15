
int X509_STORE_set_trust(X509_STORE *ctx,int trust)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_trust(ctx->param,trust);
  return iVar1;
}

