
void SSL_CTX_set_psk_server_callback(SSL_CTX *ctx,psk_server_callback *psk_server_callback)

{
  ctx[1].stats.sess_connect_good = (int)psk_server_callback;
  return;
}

