
int SSL_CIPHER_get_bits(SSL_CIPHER *c,int *alg_bits)

{
  if (c != (SSL_CIPHER *)0x0) {
    if (alg_bits != (int *)0x0) {
      *alg_bits = c[1].algorithm_mkey;
    }
    c = (SSL_CIPHER *)c[1].id;
  }
  return (int)c;
}

