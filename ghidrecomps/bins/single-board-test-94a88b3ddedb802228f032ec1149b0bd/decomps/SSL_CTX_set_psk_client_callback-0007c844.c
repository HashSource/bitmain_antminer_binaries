
void SSL_CTX_set_psk_client_callback(SSL_CTX *ctx,psk_client_callback *psk_client_callback)

{
  ctx->psk_client_callback = (_func_3243 *)psk_client_callback;
  return;
}

