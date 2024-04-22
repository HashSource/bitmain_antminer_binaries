
int X509_STORE_set_flags(X509_STORE *ctx,ulong flags)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_flags(ctx->param,flags);
  return iVar1;
}

