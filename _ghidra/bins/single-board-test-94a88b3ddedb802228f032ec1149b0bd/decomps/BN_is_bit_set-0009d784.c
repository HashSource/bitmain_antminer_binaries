
int BN_is_bit_set(BIGNUM *a,int n)

{
  if ((-1 < n) && (n >> 5 < a->top)) {
    return a->d[n >> 5] >> (n & 0x1fU) & 1;
  }
  return 0;
}

