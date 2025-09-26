
int SSL_CTX_set_purpose(SSL_CTX *s,int purpose)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_purpose(s->param,purpose);
  return iVar1;
}

