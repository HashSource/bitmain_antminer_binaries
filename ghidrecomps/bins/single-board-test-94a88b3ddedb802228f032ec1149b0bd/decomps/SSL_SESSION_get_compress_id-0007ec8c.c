
uint SSL_SESSION_get_compress_id(SSL_SESSION *s)

{
  return *(uint *)(s->krb5_client_princ + 0x20);
}

