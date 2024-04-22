
int SSL_CTX_load_verify_locations(SSL_CTX *ctx,char *CAfile,char *CApath)

{
  int iVar1;
  
  iVar1 = X509_STORE_load_locations(ctx->cert_store,CAfile,CApath);
  return iVar1;
}

