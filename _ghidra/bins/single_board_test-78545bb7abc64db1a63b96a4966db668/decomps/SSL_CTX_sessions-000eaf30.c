
lhash_st_SSL_SESSION * SSL_CTX_sessions(SSL_CTX *ctx)

{
  return (lhash_st_SSL_SESSION *)ctx->session_cache_size;
}

