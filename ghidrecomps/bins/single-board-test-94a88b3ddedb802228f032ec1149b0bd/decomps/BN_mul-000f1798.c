
int BN_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  ulong uVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  ulong *puVar5;
  ulong *puVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  
  uVar9 = a->top;
  uVar10 = b->top;
  if (uVar9 == 0 || uVar10 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  iVar11 = uVar9 + uVar10;
  BN_CTX_start(ctx);
  a_00 = r;
  if ((r != a && r != b) || (a_00 = BN_CTX_get(ctx), a_00 != (BIGNUM *)0x0)) {
    a_00->neg = a->neg ^ b->neg;
    iVar7 = uVar9 - uVar10;
    if ((iVar7 == 0) && (uVar9 == 8)) {
      if ((0xf < a_00->dmax) || (pBVar2 = bn_expand2(a_00,0x10), pBVar2 != (BIGNUM *)0x0)) {
        puVar5 = a->d;
        puVar6 = b->d;
        a_00->top = 0x10;
        bn_mul_comba8(a_00->d,puVar5,puVar6);
        iVar11 = a_00->top;
LAB_000f1804:
        if (0 < iVar11) {
          puVar5 = a_00->d + iVar11 + -1;
          do {
            if (*puVar5 != 0) break;
            iVar11 = iVar11 + -1;
            puVar5 = puVar5 + -1;
          } while (iVar11 != 0);
          a_00->top = iVar11;
        }
        if (r == a_00) {
          iVar11 = 1;
        }
        else {
          iVar11 = 1;
          BN_copy(r,a_00);
        }
        goto LAB_000f1834;
      }
    }
    else {
      uVar8 = uVar10;
      if (0xf < (int)uVar10) {
        uVar8 = uVar9;
      }
      if (((int)uVar8 < 0x10) || (2 < iVar7 + 1U)) {
        if ((a_00->dmax < iVar11) && (pBVar2 = bn_expand2(a_00,iVar11), pBVar2 == (BIGNUM *)0x0)) {
          iVar11 = 0;
          goto LAB_000f1834;
        }
        a_00->top = iVar11;
        bn_mul_normal(a_00->d,a->d,uVar9,b->d,uVar10);
        iVar11 = a_00->top;
        goto LAB_000f1804;
      }
      if (iVar7 == -1) {
        iVar7 = BN_num_bits_word(uVar10);
      }
      else {
        iVar7 = BN_num_bits_word(uVar9);
      }
      uVar8 = 1 << (iVar7 - 1U & 0xff);
      pBVar2 = BN_CTX_get(ctx);
      if (pBVar2 != (BIGNUM *)0x0) {
        iVar7 = uVar9 - uVar8;
        uVar1 = uVar9;
        if ((int)uVar9 <= (int)uVar8) {
          iVar7 = uVar10 - uVar8;
          uVar1 = uVar10;
        }
        iVar4 = pBVar2->dmax;
        if (uVar1 == uVar8 || iVar7 < 0 != SBORROW4(uVar1,uVar8)) {
          iVar7 = uVar8 * 4;
          if (((iVar7 - iVar4 == 0 || iVar7 < iVar4) ||
              (pBVar3 = bn_expand2(pBVar2,iVar7), pBVar3 != (BIGNUM *)0x0)) &&
             ((iVar7 <= a_00->dmax || (pBVar3 = bn_expand2(a_00,iVar7), pBVar3 != (BIGNUM *)0x0))))
          {
            bn_mul_recursive(a_00->d,a->d,b->d,uVar8,uVar9 - uVar8,uVar10 - uVar8,pBVar2->d);
            goto LAB_000f1916;
          }
        }
        else {
          iVar7 = uVar8 * 8;
          if (((iVar7 - iVar4 == 0 || iVar7 < iVar4) ||
              (pBVar3 = bn_expand2(pBVar2,iVar7), pBVar3 != (BIGNUM *)0x0)) &&
             ((iVar7 <= a_00->dmax || (pBVar3 = bn_expand2(a_00,iVar7), pBVar3 != (BIGNUM *)0x0))))
          {
            bn_mul_part_recursive(a_00->d,a->d,b->d,uVar8,uVar9 - uVar8,uVar10 - uVar8,pBVar2->d);
LAB_000f1916:
            a_00->top = iVar11;
            goto LAB_000f1804;
          }
        }
      }
    }
  }
  iVar11 = 0;
LAB_000f1834:
  BN_CTX_end(ctx);
  return iVar11;
}

