
SSL_CTX * SSL_get_SSL_CTX(SSL *ssl)

{
  return (SSL_CTX *)ssl->psk_server_callback;
}

