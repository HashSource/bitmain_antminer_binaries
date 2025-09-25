
int BN_mul_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  if (a->top == 0) {
    return 1;
  }
  if (w != 0) {
    uVar1 = bn_mul_words(a->d,a->d,a->top,w);
    if (uVar1 == 0) {
      return 1;
    }
    iVar2 = bn_wexpand(a,a->top + 1);
    if (iVar2 != 0) {
      iVar3 = a->top;
      iVar2 = 1;
      a->top = iVar3 + 1;
      a->d[iVar3] = uVar1;
    }
    return iVar2;
  }
  BN_set_word(a,0);
  return 1;
}

