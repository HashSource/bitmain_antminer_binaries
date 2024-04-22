
int BN_gcd(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  if (((pBVar1 != (BIGNUM *)0x0 && pBVar2 != (BIGNUM *)0x0) &&
      (pBVar3 = BN_copy(pBVar1,a), pBVar3 != (BIGNUM *)0x0)) &&
     (pBVar3 = BN_copy(pBVar2,b), pBVar3 != (BIGNUM *)0x0)) {
    pBVar1->neg = 0;
    pBVar2->neg = 0;
    iVar4 = BN_cmp(pBVar1,pBVar2);
    pBVar3 = pBVar1;
    if (iVar4 < 0) {
      pBVar3 = pBVar2;
      pBVar2 = pBVar1;
    }
    iVar4 = 0;
    while (pBVar1 = pBVar3, iVar5 = pBVar2->top, iVar5 != 0) {
      pBVar3 = pBVar1;
      if ((pBVar1->top < 1) || (-1 < (int)(*pBVar1->d << 0x1f))) {
        if ((0 < iVar5) && ((int)(*pBVar2->d << 0x1f) < 0)) goto LAB_000f29ec;
        iVar5 = BN_rshift1(pBVar1,pBVar1);
        if ((iVar5 == 0) || (iVar5 = BN_rshift1(pBVar2,pBVar2), iVar5 == 0)) goto LAB_000f2938;
        iVar4 = iVar4 + 1;
      }
      else {
        if ((iVar5 < 1) || (-1 < (int)(*pBVar2->d << 0x1f))) {
          iVar5 = BN_rshift1(pBVar2,pBVar2);
        }
        else {
          iVar5 = BN_sub(pBVar1,pBVar1,pBVar2);
          if (iVar5 == 0) goto LAB_000f2938;
LAB_000f29ec:
          iVar5 = BN_rshift1(pBVar1,pBVar1);
        }
        if (iVar5 == 0) goto LAB_000f2938;
        iVar5 = BN_cmp(pBVar1,pBVar2);
        if (iVar5 < 0) {
          pBVar3 = pBVar2;
          pBVar2 = pBVar1;
        }
      }
    }
    if ((iVar4 == 0) || (iVar4 = BN_lshift(pBVar1,pBVar1,iVar4), iVar4 != 0)) {
      pBVar2 = BN_copy(r,pBVar1);
      if (pBVar2 != (BIGNUM *)0x0) {
        pBVar2 = (BIGNUM *)0x1;
      }
      goto LAB_000f293a;
    }
  }
LAB_000f2938:
  pBVar2 = (BIGNUM *)0x0;
LAB_000f293a:
  BN_CTX_end(ctx);
  return (int)pBVar2;
}

