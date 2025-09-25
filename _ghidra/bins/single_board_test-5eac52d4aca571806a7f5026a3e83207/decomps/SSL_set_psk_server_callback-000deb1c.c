
void SSL_set_psk_server_callback(SSL *ssl,psk_server_callback *psk_server_callback)

{
  ssl[2].renegotiate = (int)psk_server_callback;
  return;
}

