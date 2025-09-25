
void SSL_CTX_set_tmp_dh_callback(SSL_CTX *ctx,dh *dh)

{
  SSL_CTX_callback_ctrl(ctx,6,(_func_3520 *)dh);
  return;
}

