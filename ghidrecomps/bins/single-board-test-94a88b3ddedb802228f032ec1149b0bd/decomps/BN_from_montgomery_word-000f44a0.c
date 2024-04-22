
undefined4 BN_from_montgomery_word(BIGNUM *param_1,BIGNUM *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  uint uVar6;
  ulong *puVar7;
  uint uVar8;
  ulong *puVar9;
  int iVar10;
  ulong uVar11;
  uint *puVar12;
  ulong *puVar13;
  ulong *puVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  ulong *puVar17;
  ulong uVar18;
  int iVar19;
  ulong *ap;
  int unaff_r9;
  int iVar20;
  int iVar21;
  
  iVar10 = *(int *)(param_3 + 0x1c);
  if (iVar10 == 0) {
    param_1->top = 0;
    uVar15 = 1;
  }
  else {
    iVar19 = iVar10 * 2;
    if ((iVar19 <= param_2->dmax) || (pBVar4 = bn_expand2(param_2,iVar19), pBVar4 != (BIGNUM *)0x0))
    {
      puVar17 = *(ulong **)(param_3 + 0x18);
      iVar20 = param_2->top;
      puVar14 = param_2->d;
      param_2->neg = param_2->neg ^ *(uint *)(param_3 + 0x24);
      if (iVar20 < iVar19) {
        iVar2 = iVar20 + 1;
        if (-0x7ffffffa < iVar19 && iVar2 < iVar19 + -7) {
          puVar13 = puVar14 + iVar20;
          iVar21 = iVar20;
          do {
            iVar20 = iVar21 + 8;
            HintPreloadData(puVar13 + 0x22);
            iVar2 = iVar21 + 9;
            *puVar13 = 0;
            puVar13[1] = 0;
            puVar13[2] = 0;
            puVar13[3] = 0;
            puVar13[4] = 0;
            puVar13[5] = 0;
            puVar13[6] = 0;
            puVar13[7] = 0;
            puVar13 = puVar13 + 8;
            iVar21 = iVar20;
          } while (iVar2 < iVar19 + -7);
        }
        puVar13 = puVar14 + iVar20 + -1;
        do {
          puVar13 = puVar13 + 1;
          *puVar13 = 0;
          bVar1 = iVar2 < iVar19;
          iVar2 = iVar2 + 1;
        } while (bVar1);
      }
      if (iVar10 < 1) {
        unaff_r9 = 0;
      }
      param_2->top = iVar19;
      iVar19 = *(int *)(param_3 + 0x40);
      if (0 < iVar10) {
        if (iVar10 < 9) {
          iVar20 = 0;
          unaff_r9 = 0;
        }
        else {
          iVar20 = 0;
          unaff_r9 = 0;
          puVar12 = puVar14 + iVar10 + 7;
          do {
            HintPreloadData(puVar12);
            iVar20 = iVar20 + 8;
            HintPreloadData(puVar12 + -iVar10);
            uVar3 = bn_mul_add_words(puVar14,puVar17,iVar10,*puVar14 * iVar19);
            uVar6 = puVar12[-7];
            uVar8 = unaff_r9 + uVar3 + uVar6;
            puVar12[-7] = uVar8;
            if (uVar6 != uVar8) {
              unaff_r9 = 1;
            }
            if (uVar6 < uVar8) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 1,puVar17,iVar10,puVar14[1] * iVar19);
            uVar8 = puVar12[-6];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-6] = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 2,puVar17,iVar10,puVar14[2] * iVar19);
            uVar8 = puVar12[-5];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-5] = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 3,puVar17,iVar10,puVar14[3] * iVar19);
            uVar8 = puVar12[-4];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-4] = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 4,puVar17,iVar10,puVar14[4] * iVar19);
            uVar8 = puVar12[-3];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-3] = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 5,puVar17,iVar10,puVar14[5] * iVar19);
            uVar8 = puVar12[-2];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-2] = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            uVar3 = bn_mul_add_words(puVar14 + 6,puVar17,iVar10,puVar14[6] * iVar19);
            uVar8 = puVar12[-1];
            uVar6 = uVar8 + uVar3 + unaff_r9;
            puVar12[-1] = uVar6;
            puVar13 = puVar14 + 7;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            puVar14 = puVar14 + 8;
            uVar3 = bn_mul_add_words(puVar12 + -iVar10,puVar17,iVar10,*puVar13 * iVar19);
            uVar8 = *puVar12;
            uVar6 = uVar8 + uVar3 + unaff_r9;
            *puVar12 = uVar6;
            if (uVar8 != uVar6) {
              unaff_r9 = 1;
            }
            if (uVar8 < uVar6) {
              unaff_r9 = 0;
            }
            puVar12 = puVar12 + 8;
          } while (iVar20 != (iVar10 - 9U & 0xfffffff8) + 8);
        }
        puVar12 = puVar14 + iVar10;
        puVar13 = puVar14;
        do {
          iVar20 = iVar20 + 1;
          puVar14 = puVar13 + 1;
          uVar3 = bn_mul_add_words(puVar13,puVar17,iVar10,*puVar13 * iVar19);
          uVar8 = *puVar12;
          uVar6 = uVar3 + unaff_r9 + uVar8;
          *puVar12 = uVar6;
          if (uVar8 != uVar6) {
            unaff_r9 = 1;
          }
          if (uVar8 < uVar6) {
            unaff_r9 = 0;
          }
          puVar12 = puVar12 + 1;
          puVar13 = puVar14;
        } while (iVar20 < iVar10);
      }
      if ((iVar10 <= param_1->dmax) ||
         (pBVar4 = bn_expand2(param_1,iVar10), pBVar4 != (BIGNUM *)0x0)) {
        ap = param_2->d + iVar10;
        puVar13 = param_1->d;
        param_1->neg = param_2->neg;
        param_1->top = iVar10;
        uVar3 = bn_sub_words(puVar13,ap,puVar17,iVar10);
        if (iVar10 < 5) {
          puVar14 = (ulong *)0x0;
        }
        uVar6 = (uint)puVar13 & ~(unaff_r9 - uVar3) | unaff_r9 - uVar3 & (uint)ap;
        if (4 < iVar10) {
          uVar8 = iVar10 - 5U >> 2;
          puVar14 = puVar13 + 1;
          iVar19 = uVar6 + 4;
          puVar17 = ap + 1;
          do {
            uVar18 = *(ulong *)(iVar19 + -4);
            uVar15 = *(undefined4 *)((int)puVar17 + (uVar6 - (int)ap));
            uVar3 = *(ulong *)(iVar19 + 4);
            puVar17[-1] = 0;
            uVar11 = *(ulong *)(iVar19 + 8);
            *(undefined4 *)((int)ap + iVar19 + -uVar6) = 0;
            puVar14[-1] = uVar18;
            puVar17[1] = 0;
            *(undefined4 *)((int)puVar13 + iVar19 + -uVar6) = uVar15;
            iVar19 = iVar19 + 0x10;
            puVar17[2] = 0;
            puVar14[2] = uVar11;
            puVar17 = puVar17 + 4;
            puVar14[1] = uVar3;
            puVar14 = puVar14 + 4;
          } while (iVar19 != uVar6 + uVar8 * 0x10 + 0x14);
          puVar14 = (ulong *)((uVar8 + 1) * 4);
        }
        if ((int)puVar14 < iVar10) {
          iVar19 = (int)puVar14 + 1;
          if (iVar19 < iVar10 + -7) {
            puVar9 = (ulong *)((int)puVar14 * 4 + uVar6);
            puVar5 = puVar13 + (int)puVar14;
            puVar7 = ap + (int)puVar14;
            puVar17 = puVar14;
            do {
              puVar14 = puVar17 + 2;
              iVar19 = (int)puVar17 + 9;
              HintPreloadData(puVar9 + 0x14);
              *puVar5 = *puVar9;
              *puVar7 = 0;
              puVar5[1] = puVar9[1];
              puVar7[1] = 0;
              puVar5[2] = puVar9[2];
              puVar7[2] = 0;
              puVar5[3] = puVar9[3];
              puVar7[3] = 0;
              puVar5[4] = puVar9[4];
              puVar7[4] = 0;
              puVar5[5] = puVar9[5];
              puVar7[5] = 0;
              puVar5[6] = puVar9[6];
              puVar7[6] = 0;
              puVar17 = puVar9 + 7;
              puVar9 = puVar9 + 8;
              puVar5[7] = *puVar17;
              puVar5 = puVar5 + 8;
              puVar7[7] = 0;
              puVar7 = puVar7 + 8;
              puVar17 = puVar14;
            } while (iVar19 < iVar10 + -7);
          }
          puVar16 = (undefined4 *)((uVar6 - 4) + (int)puVar14 * 4);
          do {
            puVar16 = puVar16 + 1;
            *(undefined4 *)((int)puVar13 + -uVar6 + (int)puVar16) = *puVar16;
            *(undefined4 *)((int)ap + -uVar6 + (int)puVar16) = 0;
            bVar1 = iVar19 < iVar10;
            iVar19 = iVar19 + 1;
          } while (bVar1);
        }
        iVar10 = param_2->top;
        if (0 < iVar10) {
          puVar14 = param_2->d + iVar10 + -1;
          do {
            if (*puVar14 != 0) break;
            iVar10 = iVar10 + -1;
            puVar14 = puVar14 + -1;
          } while (iVar10 != 0);
          param_2->top = iVar10;
        }
        iVar10 = param_1->top;
        if (iVar10 < 1) {
          return 1;
        }
        puVar14 = param_1->d + iVar10 + -1;
        do {
          if (*puVar14 != 0) break;
          iVar10 = iVar10 + -1;
          puVar14 = puVar14 + -1;
        } while (iVar10 != 0);
        param_1->top = iVar10;
        return 1;
      }
    }
    uVar15 = 0;
  }
  return uVar15;
}

