
long SSL_get_default_timeout(SSL *s)

{
  long lVar1;
  
  lVar1 = (*s->method->get_timeout)();
  return lVar1;
}

