
void X509_STORE_CTX_set_verify_cb(X509_STORE_CTX *ctx,verify_cb *verify_cb)

{
  ctx->verify = (_func_1997 *)verify_cb;
  return;
}

