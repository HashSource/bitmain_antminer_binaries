
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  bool bVar1;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  if ((a_01 == (BIGNUM *)0x0) || (pBVar2 = BN_copy(a_00,a), pBVar2 == (BIGNUM *)0x0)) {
LAB_0019517a:
    BN_CTX_end(ctx);
    return -2;
  }
  pBVar2 = BN_copy(a_01,b);
  if (pBVar2 != (BIGNUM *)0x0) {
    bVar1 = false;
    iVar3 = BN_is_zero(a_01);
    if (iVar3 != 0) {
      iVar3 = BN_abs_is_word(a_00,1);
      goto LAB_0019518c;
    }
    iVar3 = BN_is_odd(a_00);
    if ((iVar3 == 0) && (iVar3 = BN_is_odd(a_01), iVar3 == 0)) {
      iVar3 = 0;
      goto LAB_0019518c;
    }
    uVar6 = 0;
    while (iVar3 = BN_is_bit_set(a_01,uVar6), iVar3 == 0) {
      uVar6 = uVar6 + 1;
    }
    iVar3 = BN_rshift(a_01,a_01,uVar6);
    if (iVar3 != 0) {
      if ((uVar6 & 1) == 0) {
        iVar3 = 1;
      }
      else {
        iVar3 = a_00->top;
        if (iVar3 != 0) {
          iVar3 = *(int *)(&tab_9357 + (*a_00->d & 7) * 4);
        }
      }
      if ((a_01->neg != 0) && (a_01->neg = 0, a_00->neg != 0)) {
        iVar3 = -iVar3;
      }
      while( true ) {
        pBVar2 = a_00;
        bVar1 = false;
        iVar4 = BN_is_zero(pBVar2);
        if (iVar4 != 0) break;
        iVar4 = 0;
        while (iVar5 = BN_is_bit_set(pBVar2,iVar4), iVar5 == 0) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = BN_rshift(pBVar2,pBVar2,iVar4);
        if (iVar5 == 0) goto LAB_0019517a;
        if (iVar4 << 0x1f < 0) {
          if (a_01->top == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(&tab_9357 + (*a_01->d & 7) * 4) * iVar3;
          }
        }
        if (pBVar2->neg == 0) {
          if (pBVar2->top != 0) {
            uVar6 = *pBVar2->d;
            goto LAB_00195146;
          }
        }
        else {
          if (pBVar2->top == 0) {
            uVar6 = 0xffffffff;
          }
          else {
            uVar6 = ~*pBVar2->d;
          }
LAB_00195146:
          if ((a_01->top != 0) && ((*a_01->d & 2 & uVar6) != 0)) {
            iVar3 = -iVar3;
          }
        }
        iVar4 = BN_nnmod(a_01,a_01,pBVar2,ctx);
        if (iVar4 == 0) {
          bVar1 = true;
          goto LAB_0019518c;
        }
        pBVar2->neg = 0;
        a_00 = a_01;
        a_01 = pBVar2;
      }
      iVar4 = BN_is_one(a_01);
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      goto LAB_0019518c;
    }
  }
  bVar1 = true;
  iVar3 = -2;
LAB_0019518c:
  BN_CTX_end(ctx);
  if (bVar1) {
    iVar3 = -2;
  }
  return iVar3;
}

