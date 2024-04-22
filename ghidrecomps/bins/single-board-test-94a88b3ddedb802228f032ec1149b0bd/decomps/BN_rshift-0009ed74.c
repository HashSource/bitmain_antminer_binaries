
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  uint uVar10;
  int iVar11;
  ulong *puVar12;
  uint uVar13;
  
  if (n < 0) {
    ERR_put_error(3,0x92,0x77,DAT_0009efa0,0xb7);
    return 0;
  }
  iVar11 = n >> 5;
  if ((iVar11 < a->top) && (a->top != 0)) {
    iVar3 = BN_num_bits(a);
    iVar4 = (iVar3 - n) + 0x1f;
    iVar3 = (iVar3 - n) + 0x3e;
    if (-1 < iVar4) {
      iVar3 = iVar4;
    }
    iVar3 = iVar3 >> 5;
    if (r == a) {
      if (n == 0) {
        return 1;
      }
    }
    else {
      r->neg = a->neg;
      if ((r->dmax < iVar3) && (pBVar5 = bn_expand2(r,iVar3), pBVar5 == (BIGNUM *)0x0)) {
        return 0;
      }
    }
    puVar9 = a->d;
    uVar7 = n & 0x1f;
    iVar4 = a->top;
    puVar12 = r->d;
    r->top = iVar3;
    iVar4 = iVar4 - iVar11;
    puVar8 = puVar9 + iVar11;
    if (uVar7 == 0) {
      if (iVar4 != 0) {
        if (8 < iVar4) {
          iVar11 = iVar4 - (iVar4 - 9U & 0xfffffff8);
          puVar9 = puVar12;
          puVar1 = puVar8;
          do {
            puVar8 = puVar1 + 8;
            puVar12 = puVar9 + 8;
            iVar4 = iVar4 + -8;
            HintPreloadData(puVar1 + 0x1d);
            *puVar9 = *puVar1;
            puVar9[1] = puVar1[1];
            puVar9[2] = puVar1[2];
            puVar9[3] = puVar1[3];
            puVar9[4] = puVar1[4];
            puVar9[5] = puVar1[5];
            puVar9[6] = puVar1[6];
            puVar9[7] = puVar1[7];
            puVar9 = puVar12;
            puVar1 = puVar8;
          } while (iVar4 != iVar11 + -8);
        }
        puVar8 = puVar8 + -1;
        do {
          puVar8 = puVar8 + 1;
          iVar4 = iVar4 + -1;
          *puVar12 = *puVar8;
          puVar12 = puVar12 + 1;
        } while (iVar4 != 0);
      }
    }
    else {
      iVar3 = iVar4 + -1;
      uVar10 = puVar9[iVar11];
      puVar9 = puVar8 + 1;
      if (iVar3 != 0) {
        iVar11 = iVar3;
        if (iVar4 < 10) {
          uVar6 = 0x20 - uVar7;
          puVar8 = puVar12;
        }
        else {
          uVar6 = 0x20 - uVar7;
          puVar2 = puVar8 + 9;
          puVar1 = puVar12;
          do {
            puVar9 = puVar2;
            uVar13 = puVar9[-8];
            iVar11 = iVar11 + -8;
            HintPreloadData(puVar9 + 0xb);
            HintPreloadData(puVar1 + 0x13);
            *puVar1 = uVar13 << (uVar6 & 0xff) | uVar10 >> uVar7;
            uVar10 = puVar9[-7];
            puVar1[1] = uVar10 << (uVar6 & 0xff) | uVar13 >> uVar7;
            uVar13 = puVar9[-6];
            puVar1[2] = uVar13 << (uVar6 & 0xff) | uVar10 >> uVar7;
            uVar10 = puVar9[-5];
            puVar1[3] = uVar10 << (uVar6 & 0xff) | uVar13 >> uVar7;
            uVar13 = puVar9[-4];
            puVar1[4] = uVar13 << (uVar6 & 0xff) | uVar10 >> uVar7;
            uVar10 = puVar9[-3];
            puVar1[5] = uVar10 << (uVar6 & 0xff) | uVar13 >> uVar7;
            uVar13 = puVar9[-2];
            puVar1[6] = uVar13 << (uVar6 & 0xff) | uVar10 >> uVar7;
            uVar10 = puVar9[-1];
            puVar1[7] = uVar10 << (uVar6 & 0xff) | uVar13 >> uVar7;
            puVar2 = puVar9 + 8;
            puVar8 = puVar1 + 8;
            puVar1 = puVar1 + 8;
          } while (iVar11 != (iVar4 - (iVar4 - 10U & 0xfffffff8)) + -9);
        }
        do {
          uVar13 = uVar10 >> uVar7;
          uVar10 = *puVar9;
          iVar11 = iVar11 + -1;
          *puVar8 = uVar10 << (uVar6 & 0xff) | uVar13;
          puVar9 = puVar9 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar11 != 0);
        puVar12 = puVar12 + iVar3;
      }
      if (uVar10 >> uVar7 != 0) {
        *puVar12 = uVar10 >> uVar7;
      }
    }
    return 1;
  }
  BN_set_word(r,0);
  return 1;
}

