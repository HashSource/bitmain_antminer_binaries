
int SSL_CTX_set_client_cert_engine(SSL_CTX *ctx,ENGINE *e)

{
  int iVar1;
  ENGINE_SSL_CLIENT_CERT_PTR pEVar2;
  
  iVar1 = ENGINE_init(e);
  if (iVar1 != 0) {
    pEVar2 = ENGINE_get_ssl_client_cert_function(e);
    if (pEVar2 == (ENGINE_SSL_CLIENT_CERT_PTR)0x0) {
      ERR_put_error(0x14,0x122,0x14b,"ssl/ssl_sess.c",0x4be);
      ENGINE_finish(e);
    }
    else {
      *(ENGINE **)(ctx->tlsext_tick_hmac_key + 0xc) = e;
    }
    return (uint)(pEVar2 != (ENGINE_SSL_CLIENT_CERT_PTR)0x0);
  }
  ERR_put_error(0x14,0x122,0x26,"ssl/ssl_sess.c",0x4b9);
  return 0;
}

