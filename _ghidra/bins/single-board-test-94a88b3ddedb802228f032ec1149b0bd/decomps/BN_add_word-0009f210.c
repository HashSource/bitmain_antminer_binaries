
int BN_add_word(BIGNUM *a,ulong w)

{
  BIGNUM *pBVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (w != 0) {
    iVar3 = a->top;
    if (iVar3 == 0) {
      iVar3 = BN_set_word(a,w);
      return iVar3;
    }
    iVar4 = a->neg;
    if (iVar4 != 0) {
      a->neg = 0;
      iVar3 = BN_sub_word(a,w);
      if (a->top == 0) {
        return iVar3;
      }
      iVar4 = 1 - a->neg;
      if (1 < (uint)a->neg) {
        iVar4 = 0;
      }
      a->neg = iVar4;
      return iVar3;
    }
    while (iVar4 < iVar3) {
      uVar2 = w + a->d[iVar4];
      a->d[iVar4] = uVar2;
      w = (ulong)(uVar2 < w);
      iVar4 = iVar4 + 1;
      if (w == 0) {
        return 1;
      }
      iVar3 = a->top;
    }
    if (iVar4 == iVar3) {
      iVar3 = iVar4;
      if (a->dmax <= iVar4) {
        pBVar1 = bn_expand2(a,iVar4 + 1);
        if (pBVar1 == (BIGNUM *)0x0) {
          return 0;
        }
        iVar3 = a->top;
      }
      a->top = iVar3 + 1;
      a->d[iVar4] = w;
      return 1;
    }
  }
  return 1;
}

