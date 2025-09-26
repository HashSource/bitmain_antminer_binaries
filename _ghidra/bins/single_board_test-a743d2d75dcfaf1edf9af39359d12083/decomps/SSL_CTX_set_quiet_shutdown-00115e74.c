
void SSL_CTX_set_quiet_shutdown(SSL_CTX *ctx,int mode)

{
  ctx->quiet_shutdown = mode;
  return;
}

