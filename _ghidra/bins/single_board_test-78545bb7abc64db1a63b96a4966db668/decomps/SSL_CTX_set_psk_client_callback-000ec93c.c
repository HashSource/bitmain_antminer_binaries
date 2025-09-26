
void SSL_CTX_set_psk_client_callback(SSL_CTX *ctx,psk_client_callback *psk_client_callback)

{
  ctx[1].stats.sess_connect_renegotiate = (int)psk_client_callback;
  return;
}

