
void SSL_set_tmp_dh_callback(SSL *ssl,dh *dh)

{
  SSL_callback_ctrl(ssl,6,(_func_3517 *)dh);
  return;
}

