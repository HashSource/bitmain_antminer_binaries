
void SSL_set_psk_server_callback(SSL *ssl,psk_server_callback *psk_server_callback)

{
  ssl->psk_client_callback = (_func_3295 *)psk_server_callback;
  return;
}

