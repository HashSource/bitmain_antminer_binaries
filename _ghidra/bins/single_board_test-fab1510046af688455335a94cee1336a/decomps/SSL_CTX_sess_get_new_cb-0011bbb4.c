
int SSL_CTX_sess_get_new_cb(ssl_st *ssl,SSL_SESSION *sess)

{
  return ssl->new_session;
}

