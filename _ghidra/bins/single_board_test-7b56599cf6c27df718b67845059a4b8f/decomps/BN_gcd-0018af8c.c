
int BN_gcd(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *r_00;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulong *puVar9;
  ulong *puVar10;
  
  iVar1 = BN_is_zero(b);
  if (iVar1 != 0) {
    pBVar2 = BN_copy(r,a);
    r->neg = 0;
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x1;
    }
    return (int)pBVar2;
  }
  iVar1 = BN_is_zero(a);
  if (iVar1 != 0) {
    pBVar2 = BN_copy(r,b);
    r->neg = 0;
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x1;
    }
    return (int)pBVar2;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  if (((r_00 != (BIGNUM *)0x0) && (iVar1 = BN_lshift1(r_00,b), iVar1 != 0)) &&
     (iVar1 = BN_lshift1(r,a), iVar1 != 0)) {
    iVar1 = 0;
    if ((0 < r->dmax) && (0 < r_00->dmax)) {
      uVar6 = 1;
      puVar10 = r->d + -1;
      puVar9 = r_00->d + -1;
      iVar3 = 0;
      iVar1 = 0;
      do {
        puVar10 = puVar10 + 1;
        iVar7 = 0x40;
        puVar9 = puVar9 + 1;
        uVar8 = ~(*puVar9 | *puVar10);
        do {
          iVar7 = iVar7 + -1;
          uVar6 = uVar6 & uVar8;
          iVar1 = iVar1 + uVar6;
          uVar8 = uVar8 >> 1;
        } while (iVar7 != 0);
        iVar3 = iVar3 + 1;
      } while ((r->dmax != iVar3) && (r_00->dmax != iVar3));
    }
    iVar3 = BN_rshift(r,r,iVar1);
    if ((iVar3 != 0) && (iVar3 = BN_rshift(r_00,r_00,iVar1), iVar3 != 0)) {
      iVar3 = r_00->top;
      if (r_00->top < r->top) {
        iVar3 = r->top;
      }
      iVar3 = iVar3 + 1;
      iVar7 = bn_wexpand(r,iVar3);
      if (((iVar7 != 0) && (iVar7 = bn_wexpand(r_00,iVar3), iVar7 != 0)) &&
         (iVar7 = bn_wexpand(pBVar2,iVar3), iVar7 != 0)) {
        BN_consttime_swap(*r->d & 1 ^ 1,r,r_00,iVar3);
        iVar4 = BN_num_bits(r);
        iVar7 = BN_num_bits(r_00);
        if (iVar7 < iVar4) {
          iVar7 = iVar4;
        }
        iVar7 = iVar7 * 3;
        if (iVar7 + 3 < 0 == SCARRY4(iVar7,3)) {
          uVar6 = 1;
          iVar4 = 0;
          do {
            iVar4 = iVar4 + 1;
            uVar8 = *r_00->d;
            if (r_00->top < 1) {
              uVar8 = 0;
            }
            uVar8 = uVar8 & -uVar6 >> 0x1f;
            r->neg = r->neg ^ uVar8;
            BN_consttime_swap(uVar8,r,r_00,iVar3);
            uVar6 = (-uVar8 & -uVar6 | uVar8 - 1 & uVar6) + 1;
            iVar5 = BN_add(pBVar2,r_00,r);
            if (iVar5 == 0) goto LAB_0018afce;
            BN_consttime_swap(*r_00->d & 1 & ~(r_00->top + -1 >> 0x1f),r_00,pBVar2,iVar3);
            iVar5 = BN_rshift1(r_00,r_00);
            if (iVar5 == 0) goto LAB_0018afce;
          } while (iVar4 != iVar7 + 4);
        }
        r->neg = 0;
        iVar1 = BN_lshift(r,r,iVar1);
        if (iVar1 != 0) {
          iVar1 = BN_rshift1(r,r);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
          goto LAB_0018afd0;
        }
      }
    }
  }
LAB_0018afce:
  iVar1 = 0;
LAB_0018afd0:
  BN_CTX_end(ctx);
  return iVar1;
}

