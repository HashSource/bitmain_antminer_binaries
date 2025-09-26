
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  if (a_01 == (BIGNUM *)0x0) {
    uVar6 = 0xfffffffe;
    goto LAB_001bacc0;
  }
  pBVar1 = BN_copy(a_00,a);
  if ((pBVar1 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(a_01,b), pBVar1 == (BIGNUM *)0x0))
  goto LAB_001bac80;
  if (a_01->top == 0) {
    if (a_00->top == 1) {
      uVar6 = (uint)(*a_00->d == 1);
    }
    else {
      uVar6 = 0;
    }
    goto LAB_001bacc0;
  }
  if ((a_00->top < 1) || (-1 < (int)(*a_00->d << 0x1f))) {
    if (0 < a_01->top) {
      uVar6 = *a_01->d & 1;
      if (uVar6 == 0) goto LAB_001bacc0;
      goto LAB_001bace8;
    }
  }
  else {
LAB_001bace8:
    iVar5 = 0;
    while (iVar2 = BN_is_bit_set(a_01,iVar5), iVar2 == 0) {
      iVar5 = iVar5 + 1;
    }
    iVar2 = BN_rshift(a_01,a_01,iVar5);
    if (iVar2 == 0) {
LAB_001bac80:
      BN_CTX_end(ctx);
      return -2;
    }
    uVar4 = a_00->top;
    if (iVar5 << 0x1f < 0) {
      uVar6 = uVar4;
      if (uVar4 != 0) {
        uVar6 = *a_00->d & 7;
      }
      uVar6 = *(uint *)(&tab_8189 + uVar6 * 4);
    }
    else {
      uVar6 = 1;
    }
    if ((a_01->neg != 0) && (a_01->neg = 0, a_00->neg != 0)) {
      uVar6 = -uVar6;
    }
    while (pBVar1 = a_00, uVar4 != 0) {
      iVar5 = 0;
      while (iVar2 = BN_is_bit_set(pBVar1,iVar5), iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = BN_rshift(pBVar1,pBVar1,iVar5);
      if (iVar2 == 0) goto LAB_001bac80;
      uVar4 = a_01->top;
      if (iVar5 << 0x1f < 0) {
        uVar3 = uVar4;
        if (uVar4 != 0) {
          uVar3 = *a_01->d & 7;
        }
        uVar6 = *(int *)(&tab_8189 + uVar3 * 4) * uVar6;
      }
      if (pBVar1->neg == 0) {
        uVar3 = pBVar1->top;
        if (uVar3 != 0) {
          uVar3 = *pBVar1->d;
        }
      }
      else if (pBVar1->top == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = ~*pBVar1->d;
      }
      if ((uVar4 != 0) && ((*a_01->d & 2 & uVar3) != 0)) {
        uVar6 = -uVar6;
      }
      iVar5 = BN_nnmod(a_01,a_01,pBVar1,ctx);
      if (iVar5 == 0) goto LAB_001bac80;
      uVar4 = a_01->top;
      pBVar1->neg = 0;
      a_00 = a_01;
      a_01 = pBVar1;
    }
    if (((a_01->top == 1) && (*a_01->d == 1)) && (a_01->neg == 0)) goto LAB_001bacc0;
  }
  uVar6 = 0;
LAB_001bacc0:
  BN_CTX_end(ctx);
  return uVar6;
}

