
void SSL_set_info_callback(SSL *ssl,cb *cb)

{
  ssl->info_callback = (_func_3294 *)cb;
  return;
}

