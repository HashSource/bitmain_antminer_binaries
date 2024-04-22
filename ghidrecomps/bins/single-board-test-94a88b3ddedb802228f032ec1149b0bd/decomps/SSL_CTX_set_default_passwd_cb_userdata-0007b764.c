
void SSL_CTX_set_default_passwd_cb_userdata(SSL_CTX *ctx,void *u)

{
  ctx->default_passwd_callback_userdata = u;
  return;
}

