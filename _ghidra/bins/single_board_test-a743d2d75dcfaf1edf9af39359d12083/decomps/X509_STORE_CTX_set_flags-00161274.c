
void X509_STORE_CTX_set_flags(X509_STORE_CTX *ctx,ulong flags)

{
  X509_VERIFY_PARAM_set_flags(ctx->param,flags);
  return;
}

