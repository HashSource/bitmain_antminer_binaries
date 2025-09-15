
SSL_SESSION * SSL_CTX_sess_get_get_cb(ssl_st *ssl,uchar *Data,int len,int *copy)

{
  return (SSL_SESSION *)ssl->shutdown;
}

