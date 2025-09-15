
int BN_mul_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  BIGNUM *pBVar2;
  int iVar3;
  
  if (a->top == 0) {
    return 1;
  }
  if (w != 0) {
    uVar1 = bn_mul_words(a->d,a->d,a->top,w);
    if (uVar1 == 0) {
      return 1;
    }
    iVar3 = a->top;
    if (a->dmax <= iVar3) {
      pBVar2 = bn_expand2(a,iVar3 + 1);
      if (pBVar2 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar3 = a->top;
    }
    a->d[iVar3] = uVar1;
    a->top = iVar3 + 1;
    return 1;
  }
  BN_set_word(a,0);
  return 1;
}

