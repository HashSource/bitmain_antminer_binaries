
void SSL_set_psk_client_callback(SSL *ssl,psk_client_callback *psk_client_callback)

{
  ssl[2].tlsext_hb_seq = (uint)psk_client_callback;
  return;
}

