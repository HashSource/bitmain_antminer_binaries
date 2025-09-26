
long SSL_CTX_set_timeout(SSL_CTX *ctx,long t)

{
  SSL_CTX *pSVar1;
  
  pSVar1 = ctx;
  if (ctx != (SSL_CTX *)0x0) {
    pSVar1 = (SSL_CTX *)ctx->new_session_cb;
    ctx->new_session_cb = (_func_3229 *)t;
  }
  return (long)pSVar1;
}

