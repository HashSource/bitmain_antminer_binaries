
int SSL_CTX_get_quiet_shutdown(SSL_CTX *ctx)

{
  return (int)ctx->tlsext_servername_arg;
}

