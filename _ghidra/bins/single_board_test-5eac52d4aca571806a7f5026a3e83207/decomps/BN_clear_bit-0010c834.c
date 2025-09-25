
int BN_clear_bit(BIGNUM *a,int n)

{
  int iVar1;
  
  if (n < 0) {
    return 0;
  }
  iVar1 = n >> 6;
  if (a->top <= iVar1) {
    return 0;
  }
  a->d[iVar1] = a->d[iVar1] & ~(1 << (n & 0x3fU));
  bn_correct_top();
  return 1;
}

