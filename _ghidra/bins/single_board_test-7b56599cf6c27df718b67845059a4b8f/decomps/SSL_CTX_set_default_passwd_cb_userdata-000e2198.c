
void SSL_CTX_set_default_passwd_cb_userdata(SSL_CTX *ctx,void *u)

{
  ctx->client_cert_cb = (_func_3233 *)u;
  return;
}

