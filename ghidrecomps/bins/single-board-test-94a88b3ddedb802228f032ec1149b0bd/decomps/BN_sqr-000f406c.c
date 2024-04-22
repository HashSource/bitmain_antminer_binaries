
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  BIGNUM *a_00;
  int iVar1;
  BIGNUM *a_01;
  BIGNUM *pBVar2;
  ulong *puVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  undefined auStack_a0 [128];
  
  uVar5 = a->top;
  if ((int)uVar5 < 1) {
    r->top = 0;
    r->neg = 0;
    return 1;
  }
  BN_CTX_start(ctx);
  a_01 = r;
  if (a == r) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((a_01 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) ||
     ((iVar6 = uVar5 * 2, a_01->dmax < iVar6 &&
      (pBVar2 = bn_expand2(a_01,iVar6), pBVar2 == (BIGNUM *)0x0)))) goto LAB_000f409e;
  if (uVar5 == 4) {
    bn_sqr_comba4(a_01->d,a->d);
  }
  else if (uVar5 == 8) {
    bn_sqr_comba8(a_01->d,a->d);
  }
  else {
    if (0xf < (int)uVar5) {
      iVar1 = BN_num_bits_word(uVar5);
      iVar4 = a_00->dmax;
      if (uVar5 == 1 << (iVar1 - 1U & 0xff)) {
        iVar1 = uVar5 * 4;
        if ((iVar1 - iVar4 == 0 || iVar1 < iVar4) ||
           (pBVar2 = bn_expand2(a_00,iVar1), pBVar2 != (BIGNUM *)0x0)) {
          bn_sqr_recursive(a_01->d,a->d,uVar5,a_00->d);
          goto LAB_000f40d4;
        }
      }
      else if ((iVar6 <= iVar4) || (pBVar2 = bn_expand2(a_00,iVar6), pBVar2 != (BIGNUM *)0x0)) {
        bn_sqr_normal(a_01->d,a->d,uVar5,a_00->d);
        goto LAB_000f40d4;
      }
LAB_000f409e:
      iVar6 = 0;
      goto LAB_000f40a0;
    }
    bn_sqr_normal(a_01->d,a->d,uVar5,auStack_a0);
  }
LAB_000f40d4:
  puVar3 = a->d;
  a_01->neg = 0;
  if (puVar3[uVar5 - 1] == (puVar3[uVar5 - 1] & 0xffff)) {
    iVar6 = iVar6 + -1;
  }
  a_01->top = iVar6;
  if (a_01 == r) {
    iVar6 = 1;
  }
  else {
    BN_copy(r,a_01);
    iVar6 = 1;
  }
LAB_000f40a0:
  BN_CTX_end(ctx);
  return iVar6;
}

