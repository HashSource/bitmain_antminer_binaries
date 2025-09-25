
void SSL_CTX_set_msg_callback(SSL_CTX *ctx,cb *cb)

{
  SSL_CTX_callback_ctrl(ctx,0xf,(_func_3520 *)cb);
  return;
}

