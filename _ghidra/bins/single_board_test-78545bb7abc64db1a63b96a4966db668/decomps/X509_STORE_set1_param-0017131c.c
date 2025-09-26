
int X509_STORE_set1_param(X509_STORE *ctx,X509_VERIFY_PARAM *pm)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set1(ctx->param,pm);
  return iVar1;
}

