
int SSL_CTX_set_trust(SSL_CTX *s,int trust)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_trust((X509_VERIFY_PARAM *)s->tlsext_servername_callback,trust);
  return iVar1;
}

