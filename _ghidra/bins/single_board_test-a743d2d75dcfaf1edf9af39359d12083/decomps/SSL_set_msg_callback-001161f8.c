
void SSL_set_msg_callback(SSL *ssl,cb *cb)

{
  ssl->msg_callback = (_func_3292 *)cb;
  return;
}

