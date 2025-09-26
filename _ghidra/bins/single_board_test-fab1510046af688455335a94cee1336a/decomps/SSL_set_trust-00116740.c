
int SSL_set_trust(SSL *s,int trust)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_trust(s->param,trust);
  return iVar1;
}

