
ulong SSL_CIPHER_get_id(SSL_CIPHER *c)

{
  return c->algorithm_mkey;
}

