
int SSL_CTX_set_purpose(SSL_CTX *s,int purpose)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_purpose((X509_VERIFY_PARAM *)s->tlsext_servername_callback,purpose);
  return iVar1;
}

