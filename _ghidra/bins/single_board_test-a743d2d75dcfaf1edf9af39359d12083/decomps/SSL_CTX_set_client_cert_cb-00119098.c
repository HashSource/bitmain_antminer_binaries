
void SSL_CTX_set_client_cert_cb(SSL_CTX *ctx,client_cert_cb *client_cert_cb)

{
  ctx->client_cert_cb = (_func_3233 *)client_cert_cb;
  return;
}

