
void SSL_CTX_set_client_CA_list(SSL_CTX *ctx,stack_st_X509_NAME *name_list)

{
  OPENSSL_sk_pop_free(ctx->mode,0x16da91);
  ctx->mode = (ulong)name_list;
  return;
}

