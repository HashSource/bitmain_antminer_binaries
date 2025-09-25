
void SSL_CTX_set_quiet_shutdown(SSL_CTX *ctx,int mode)

{
  ctx->tlsext_servername_arg = (void *)mode;
  return;
}

