
void SSL_CTX_set_client_CA_list(SSL_CTX *ctx,stack_st_X509_NAME *name_list)

{
  if (&ctx->client_CA->stack != (_STACK *)0x0) {
    sk_pop_free(&ctx->client_CA->stack,(func *)0x15a3c9);
  }
  ctx->client_CA = name_list;
  return;
}

