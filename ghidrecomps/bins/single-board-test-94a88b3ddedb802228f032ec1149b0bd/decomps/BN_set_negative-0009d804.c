
void BN_set_negative(BIGNUM *b,int n)

{
  if ((n != 0) && (n = b->top, n != 0)) {
    n = 1;
  }
  b->neg = n;
  return;
}

