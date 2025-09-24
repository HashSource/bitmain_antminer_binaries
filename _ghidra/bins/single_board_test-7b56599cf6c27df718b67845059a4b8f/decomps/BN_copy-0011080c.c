
BIGNUM * BN_copy(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  
  iVar1 = BN_get_flags(b,4);
  iVar3 = b->top;
  if (iVar1 != 0) {
    iVar3 = b->dmax;
  }
  pBVar2 = b;
  if ((b != a) && (pBVar2 = (BIGNUM *)bn_wexpand(a,iVar3), pBVar2 != (BIGNUM *)0x0)) {
    iVar1 = b->top;
    if (0 < iVar1) {
      memcpy(a->d,b->d,iVar3 << 2);
      iVar1 = b->top;
    }
    iVar3 = b->neg;
    a->top = iVar1;
    a->neg = iVar3;
    return a;
  }
  return pBVar2;
}

