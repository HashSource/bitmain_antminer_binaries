
void SSL_set_tmp_dh_callback(SSL *ssl,dh *dh)

{
  (*ssl->method->ssl_callback_ctrl)(ssl,6,(fp *)dh);
  return;
}

