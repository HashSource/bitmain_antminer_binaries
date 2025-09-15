
void SSL_CTX_set_psk_server_callback(SSL_CTX *ctx,psk_server_callback *psk_server_callback)

{
  ctx->psk_server_callback = (_func_3244 *)psk_server_callback;
  return;
}

