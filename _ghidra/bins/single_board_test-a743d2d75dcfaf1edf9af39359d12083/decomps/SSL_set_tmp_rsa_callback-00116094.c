
void SSL_set_tmp_rsa_callback(SSL *ssl,cb *cb)

{
  (*ssl->method->ssl_callback_ctrl)(ssl,5,(fp *)cb);
  return;
}

