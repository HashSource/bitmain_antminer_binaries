
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  if (a_01 == (BIGNUM *)0x0) {
    uVar7 = 0xfffffffe;
    goto LAB_00121e40;
  }
  pBVar1 = BN_copy(a_00,a);
  if ((pBVar1 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(a_01,b), pBVar1 == (BIGNUM *)0x0))
  goto LAB_00121e00;
  if (a_01->top == 0) {
    if (a_00->top == 1) {
      uVar7 = (uint)(*a_00->d == 1);
    }
    else {
      uVar7 = 0;
    }
    goto LAB_00121e40;
  }
  if ((a_00->top < 1) || (-1 < (int)(*a_00->d << 0x1f))) {
    if (0 < a_01->top) {
      uVar7 = *a_01->d & 1;
      if (uVar7 == 0) goto LAB_00121e40;
      goto LAB_00121e68;
    }
  }
  else {
LAB_00121e68:
    iVar6 = 0;
    while (iVar2 = BN_is_bit_set(a_01,iVar6), iVar2 == 0) {
      iVar6 = iVar6 + 1;
    }
    iVar2 = BN_rshift(a_01,a_01,iVar6);
    if (iVar2 == 0) {
LAB_00121e00:
      BN_CTX_end(ctx);
      return -2;
    }
    uVar5 = a_00->top;
    if (iVar6 << 0x1f < 0) {
      uVar7 = uVar5;
      if (uVar5 != 0) {
        uVar7 = *a_00->d & 7;
      }
      uVar7 = *(uint *)(DAT_00121f6c + uVar7 * 4);
    }
    else {
      uVar7 = 1;
    }
    iVar6 = DAT_00121f6c;
    if ((a_01->neg != 0) && (a_01->neg = 0, iVar6 = DAT_00121f6c, a_00->neg != 0)) {
      uVar7 = -uVar7;
    }
    while (pBVar1 = a_00, iVar2 = DAT_00121f6c, DAT_00121f6c = iVar6, uVar5 != 0) {
      iVar6 = 0;
      while (iVar3 = BN_is_bit_set(pBVar1,iVar6), iVar3 == 0) {
        iVar6 = iVar6 + 1;
      }
      iVar3 = BN_rshift(pBVar1,pBVar1,iVar6);
      if (iVar3 == 0) goto LAB_00121e00;
      uVar5 = a_01->top;
      if (iVar6 << 0x1f < 0) {
        uVar4 = uVar5;
        if (uVar5 != 0) {
          uVar4 = *a_01->d & 7;
        }
        uVar7 = *(int *)(iVar2 + uVar4 * 4) * uVar7;
      }
      if (pBVar1->neg == 0) {
        uVar4 = pBVar1->top;
        if (uVar4 != 0) {
          uVar4 = *pBVar1->d;
        }
      }
      else if (pBVar1->top == 0) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = ~*pBVar1->d;
      }
      if ((uVar5 != 0) && ((*a_01->d & 2 & uVar4) != 0)) {
        uVar7 = -uVar7;
      }
      iVar6 = BN_nnmod(a_01,a_01,pBVar1,ctx);
      if (iVar6 == 0) goto LAB_00121e00;
      uVar5 = a_01->top;
      pBVar1->neg = 0;
      a_00 = a_01;
      a_01 = pBVar1;
      iVar6 = DAT_00121f6c;
      DAT_00121f6c = iVar2;
    }
    if (((a_01->top == 1) && (*a_01->d == 1)) && (a_01->neg == 0)) goto LAB_00121e40;
  }
  uVar7 = 0;
LAB_00121e40:
  BN_CTX_end(ctx);
  return uVar7;
}

