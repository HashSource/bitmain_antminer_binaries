
void X509_STORE_set_verify_cb(X509_STORE *ctx,verify_cb *verify_cb)

{
  ctx->verify_cb = (_func_1986 *)verify_cb;
  return;
}

