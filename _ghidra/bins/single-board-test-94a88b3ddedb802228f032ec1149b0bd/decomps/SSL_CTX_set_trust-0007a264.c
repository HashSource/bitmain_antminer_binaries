
int SSL_CTX_set_trust(SSL_CTX *s,int trust)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_trust(s->param,trust);
  return iVar1;
}

