
void SSL_set_tmp_ecdh_callback(SSL *ssl,ecdh *ecdh)

{
  (*ssl->method->ssl_callback_ctrl)(ssl,7,(fp *)ecdh);
  return;
}

