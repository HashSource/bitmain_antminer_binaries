
int SSL_CTX_get_verify_depth(SSL_CTX *ctx)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_get_depth((X509_VERIFY_PARAM *)ctx->tlsext_servername_callback);
  return iVar1;
}

