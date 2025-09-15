
int BN_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a_00;
  BIGNUM *b_00;
  
  if (a->neg == 0) {
    a_00 = a;
    b_00 = b;
    if (b->neg != 0) {
      iVar1 = 0;
      goto LAB_000ef14e;
    }
  }
  else {
    a_00 = b;
    b_00 = a;
    if (b->neg == 0) {
      iVar1 = 1;
LAB_000ef14e:
      iVar2 = BN_uadd(r,a,b);
      if (iVar2 == 0) {
        return 0;
      }
      r->neg = iVar1;
      return 1;
    }
  }
  iVar1 = a_00->top;
  if (a_00->top < b_00->top) {
    iVar1 = b_00->top;
  }
  if ((iVar1 <= r->dmax) || (pBVar3 = bn_expand2(r,iVar1), pBVar3 != (BIGNUM *)0x0)) {
    iVar1 = BN_ucmp(a_00,b_00);
    if (iVar1 < 0) {
      iVar1 = BN_usub(r,b_00,a_00);
      if (iVar1 != 0) {
        r->neg = 1;
        return 1;
      }
    }
    else {
      iVar1 = BN_usub(r,a_00,b_00);
      if (iVar1 != 0) {
        r->neg = 0;
        return 1;
      }
    }
  }
  return 0;
}

