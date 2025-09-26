
SSL_METHOD * SSL_get_ssl_method(SSL *s)

{
  return s->method;
}

