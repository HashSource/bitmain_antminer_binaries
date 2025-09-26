
int BN_lshift1(BIGNUM *r,BIGNUM *a)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar8;
  
  if (r == a) {
    if ((r->dmax <= r->top) && (pBVar1 = bn_expand2(r,r->top + 1), pBVar1 == (BIGNUM *)0x0)) {
      return 0;
    }
  }
  else {
    iVar2 = a->top;
    r->neg = a->neg;
    if (r->dmax <= iVar2) {
      pBVar1 = bn_expand2(r,iVar2 + 1);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar2 = a->top;
    }
    r->top = iVar2;
  }
  if (0 < a->top) {
    uVar3 = 0;
    uVar4 = uVar3;
    puVar5 = r->d;
    puVar7 = a->d;
    do {
      uVar3 = uVar3 + 1;
      uVar8 = uVar4 | *puVar7 << 1;
      uVar4 = -((int)*puVar7 >> 0x1f);
      puVar6 = puVar5 + 1;
      *puVar5 = uVar8;
      puVar5 = puVar6;
      puVar7 = puVar7 + 1;
    } while ((int)uVar3 < a->top);
    if (uVar4 != 0) {
      *puVar6 = 1;
      r->top = r->top + 1;
      return 1;
    }
  }
  return 1;
}

