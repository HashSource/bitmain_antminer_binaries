
int X509_STORE_set_purpose(X509_STORE *ctx,int purpose)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_purpose(ctx->param,purpose);
  return iVar1;
}

