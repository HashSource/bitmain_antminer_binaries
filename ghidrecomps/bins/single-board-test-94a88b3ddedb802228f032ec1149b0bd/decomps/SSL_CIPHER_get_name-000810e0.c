
char * SSL_CIPHER_get_name(SSL_CIPHER *c)

{
  if (c != (SSL_CIPHER *)0x0) {
    return c->name;
  }
  return DAT_000810ec;
}

