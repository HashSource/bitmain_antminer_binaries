
int SSL_set_purpose(SSL *s,int purpose)

{
  int iVar1;
  
  iVar1 = X509_VERIFY_PARAM_set_purpose(s->param,purpose);
  return iVar1;
}

