
void X509_STORE_CTX_set_verify_cb(X509_STORE_CTX *ctx,verify_cb *verify_cb)

{
  ctx->verify_cb = (_func_1998 *)verify_cb;
  return;
}

