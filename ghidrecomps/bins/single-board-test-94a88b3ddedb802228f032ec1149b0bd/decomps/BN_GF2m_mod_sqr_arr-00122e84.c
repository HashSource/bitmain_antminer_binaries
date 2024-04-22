
BIGNUM * BN_GF2m_mod_sqr_arr(BIGNUM *param_1,int *param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  uint *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ulong *puVar9;
  int iVar10;
  int iVar11;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a == (BIGNUM *)0x0) {
    return (BIGNUM *)0x0;
  }
  iVar6 = param_2[1];
  iVar8 = a->dmax;
  iVar3 = iVar6 * 2;
  if (iVar3 - iVar8 != 0 && iVar8 <= iVar3) {
    pBVar2 = bn_expand2(a,iVar3);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012317a;
    iVar6 = param_2[1];
  }
  iVar3 = DAT_001231b0;
  iVar11 = iVar6 + -1;
  if (-1 < iVar11) {
    puVar4 = a->d;
    if (iVar6 < 5) {
      iVar8 = DAT_001231b0;
    }
    iVar5 = *param_2;
    if (4 < iVar6) {
      iVar10 = iVar5 + (iVar6 + -6) * 4;
      puVar9 = puVar4 + (iVar6 + -6) * 2;
      do {
        uVar7 = *(uint *)(iVar10 + 0x14);
        iVar11 = iVar11 + -4;
        HintPreloadData(iVar10);
        HintPreloadData(puVar9 + 1);
        HintPreloadData(puVar9);
        puVar9[0xb] = *(uint *)(iVar3 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                      *(int *)(iVar3 + (uVar7 >> 0x1c) * 4) << 0x18 |
                      *(int *)(iVar3 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                      *(int *)(iVar3 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x14);
        puVar9[10] = *(int *)(iVar3 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                     *(int *)(iVar3 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                     *(uint *)(iVar3 + (uVar7 & 0xf) * 4) |
                     *(int *)(iVar3 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x10);
        puVar9[9] = *(uint *)(iVar3 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(iVar3 + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(iVar3 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x10);
        puVar9[8] = *(int *)(iVar3 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(iVar3 + (uVar7 & 0xf) * 4) |
                    *(int *)(iVar3 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0xc);
        puVar9[7] = *(uint *)(iVar3 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(iVar3 + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(iVar3 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0xc);
        puVar9[6] = *(int *)(iVar3 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(iVar3 + (uVar7 & 0xf) * 4) |
                    *(int *)(iVar3 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 8);
        puVar9[5] = *(uint *)(iVar3 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(iVar3 + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(iVar3 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 8);
        iVar10 = iVar10 + -0x10;
        puVar9[4] = *(int *)(iVar3 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(iVar3 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(iVar3 + (uVar7 & 0xf) * 4) |
                    *(int *)(iVar3 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        puVar9 = puVar9 + -8;
        iVar8 = iVar3;
      } while (iVar11 != (iVar6 - (iVar6 - 5U & 0xfffffffc)) + -5);
    }
    puVar1 = (uint *)(iVar5 + iVar11 * 4);
    puVar4 = puVar4 + iVar11 * 2;
    do {
      uVar7 = *puVar1;
      iVar11 = iVar11 + -1;
      puVar4[1] = *(uint *)(iVar8 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                  *(int *)(iVar8 + (uVar7 >> 0x1c) * 4) << 0x18 |
                  *(int *)(iVar8 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                  *(int *)(iVar8 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
      uVar7 = *puVar1;
      *puVar4 = *(int *)(iVar8 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                *(int *)(iVar8 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                *(uint *)(iVar8 + (uVar7 & 0xf) * 4) |
                *(int *)(iVar8 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
      puVar1 = puVar1 + -1;
      puVar4 = puVar4 + -2;
    } while (-1 < iVar11);
    iVar6 = param_2[1];
  }
  iVar6 = iVar6 * 2;
  a->top = iVar6;
  if (0 < iVar6) {
    puVar4 = a->d + iVar6 + -1;
    do {
      if (*puVar4 != 0) break;
      iVar6 = iVar6 + -1;
      puVar4 = puVar4 + -1;
    } while (iVar6 != 0);
    a->top = iVar6;
  }
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
  }
  else {
    if (a != param_1) {
      if (param_1->dmax < iVar6) {
        pBVar2 = bn_expand2(param_1,iVar6);
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012317a;
        iVar6 = a->top;
      }
      if (0 < iVar6) {
        puVar9 = param_1->d;
        iVar3 = 0;
        puVar4 = a->d;
        iVar8 = 0;
        do {
          iVar8 = iVar8 + 1;
          *(undefined4 *)((int)puVar9 + iVar3) = *(undefined4 *)((int)puVar4 + iVar3);
          iVar3 = iVar3 + 4;
          iVar6 = a->top;
        } while (iVar8 < iVar6);
      }
      param_1->top = iVar6;
    }
    pBVar2 = (BIGNUM *)BN_GF2m_mod_arr_part_0(param_1,param_3);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012317a;
  }
  pBVar2 = (BIGNUM *)0x1;
LAB_0012317a:
  BN_CTX_end(param_4);
  return pBVar2;
}

