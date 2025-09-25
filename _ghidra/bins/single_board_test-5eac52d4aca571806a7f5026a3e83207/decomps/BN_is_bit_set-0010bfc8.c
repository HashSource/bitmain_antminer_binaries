
int BN_is_bit_set(BIGNUM *a,int n)

{
  if ((-1 < n) && (n >> 6 < a->top)) {
    return a->d[n >> 6] >> (n & 0x3fU) & 1;
  }
  return 0;
}

