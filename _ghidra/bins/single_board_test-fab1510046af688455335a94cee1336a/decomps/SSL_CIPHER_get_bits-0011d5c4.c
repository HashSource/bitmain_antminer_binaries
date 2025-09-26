
int SSL_CIPHER_get_bits(SSL_CIPHER *c,int *alg_bits)

{
  if (c != (SSL_CIPHER *)0x0) {
    if (alg_bits != (int *)0x0) {
      *alg_bits = c->alg_bits;
    }
    c = (SSL_CIPHER *)c->strength_bits;
  }
  return (int)c;
}

