
void SSL_set_psk_client_callback(SSL *ssl,psk_client_callback *psk_client_callback)

{
  ssl->kssl_ctx = (KSSL_CTX *)psk_client_callback;
  return;
}

