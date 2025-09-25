
int BN_set_word(BIGNUM *a,ulong w)

{
  BIGNUM *pBVar1;
  ulong uVar2;
  
  if ((a->dmax < 1) && (pBVar1 = bn_expand2(a,1), pBVar1 == (BIGNUM *)0x0)) {
    return 0;
  }
  a->neg = 0;
  uVar2 = w;
  if (w != 0) {
    uVar2 = 1;
  }
  *a->d = w;
  a->top = uVar2;
  return 1;
}

