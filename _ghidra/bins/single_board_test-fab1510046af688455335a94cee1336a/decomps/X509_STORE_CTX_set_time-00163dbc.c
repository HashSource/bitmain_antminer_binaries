
void X509_STORE_CTX_set_time(X509_STORE_CTX *ctx,ulong flags,time_t t)

{
  X509_VERIFY_PARAM_set_time(ctx->param,t);
  return;
}

