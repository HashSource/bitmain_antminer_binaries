
void X509_STORE_CTX_trusted_stack(X509_STORE_CTX *ctx,stack_st_X509 *sk)

{
  ctx->other_ctx = sk;
  ctx->get_issuer = (_func_1999 *)0x161e1d;
  return;
}

