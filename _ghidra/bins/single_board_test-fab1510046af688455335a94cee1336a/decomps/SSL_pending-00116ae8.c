
int SSL_pending(SSL *s)

{
  int iVar1;
  
  iVar1 = (*s->method->ssl_pending)(s);
  return iVar1;
}

