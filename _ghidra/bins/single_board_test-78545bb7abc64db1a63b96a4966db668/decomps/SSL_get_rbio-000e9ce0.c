
BIO * SSL_get_rbio(SSL *s)

{
  return (BIO *)s->method;
}

