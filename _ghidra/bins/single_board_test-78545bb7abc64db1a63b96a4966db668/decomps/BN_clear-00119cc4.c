
void BN_clear(BIGNUM *a)

{
  if (a != (BIGNUM *)0x0) {
    if (a->d != (ulong *)0x0) {
      OPENSSL_cleanse(a->d,a->dmax << 2);
    }
    a->neg = 0;
    a->top = 0;
    return;
  }
  return;
}

