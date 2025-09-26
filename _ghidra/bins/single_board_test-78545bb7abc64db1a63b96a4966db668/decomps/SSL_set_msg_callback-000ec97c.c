
void SSL_set_msg_callback(SSL *ssl,cb *cb)

{
  SSL_callback_ctrl(ssl,0xf,(_func_3517 *)cb);
  return;
}

