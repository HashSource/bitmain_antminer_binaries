
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
  undefined1 *puVar8;
  ulong *puVar9;
  int iVar10;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a == (BIGNUM *)0x0) {
    return (BIGNUM *)0x0;
  }
  iVar6 = param_2[1];
  puVar8 = (undefined1 *)a->dmax;
  iVar3 = iVar6 * 2;
  if (iVar3 - (int)puVar8 != 0 && (int)puVar8 <= iVar3) {
    pBVar2 = bn_expand2(a,iVar3);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_001b94ba;
    iVar6 = param_2[1];
  }
  iVar3 = iVar6 + -1;
  if (-1 < iVar3) {
    puVar4 = a->d;
    if (iVar6 < 5) {
      puVar8 = &SQR_tb;
    }
    iVar5 = *param_2;
    if (4 < iVar6) {
      puVar8 = &SQR_tb;
      iVar10 = iVar5 + (iVar6 + -6) * 4;
      puVar9 = puVar4 + (iVar6 + -6) * 2;
      do {
        uVar7 = *(uint *)(iVar10 + 0x14);
        iVar3 = iVar3 + -4;
        HintPreloadData(iVar10);
        HintPreloadData(puVar9 + 1);
        HintPreloadData(puVar9);
        puVar9[0xb] = *(uint *)(&SQR_tb + ((uVar7 << 0xc) >> 0x1c) * 4) |
                      *(int *)(&SQR_tb + (uVar7 >> 0x1c) * 4) << 0x18 |
                      *(int *)(&SQR_tb + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                      *(int *)(&SQR_tb + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x14);
        puVar9[10] = *(int *)(&SQR_tb + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                     *(int *)(&SQR_tb + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                     *(uint *)(&SQR_tb + (uVar7 & 0xf) * 4) |
                     *(int *)(&SQR_tb + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x10);
        puVar9[9] = *(uint *)(&SQR_tb + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(&SQR_tb + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(&SQR_tb + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0x10);
        puVar9[8] = *(int *)(&SQR_tb + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(&SQR_tb + (uVar7 & 0xf) * 4) |
                    *(int *)(&SQR_tb + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0xc);
        puVar9[7] = *(uint *)(&SQR_tb + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(&SQR_tb + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(&SQR_tb + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 0xc);
        puVar9[6] = *(int *)(&SQR_tb + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(&SQR_tb + (uVar7 & 0xf) * 4) |
                    *(int *)(&SQR_tb + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 8);
        puVar9[5] = *(uint *)(&SQR_tb + ((uVar7 << 0xc) >> 0x1c) * 4) |
                    *(int *)(&SQR_tb + (uVar7 >> 0x1c) * 4) << 0x18 |
                    *(int *)(&SQR_tb + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 8) >> 0x1c) * 4) << 8;
        uVar7 = *(uint *)(iVar10 + 8);
        iVar10 = iVar10 + -0x10;
        puVar9[4] = *(int *)(&SQR_tb + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                    *(int *)(&SQR_tb + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                    *(uint *)(&SQR_tb + (uVar7 & 0xf) * 4) |
                    *(int *)(&SQR_tb + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
        puVar9 = puVar9 + -8;
      } while (iVar3 != (iVar6 - (iVar6 - 5U & 0xfffffffc)) + -5);
    }
    puVar1 = (uint *)(iVar5 + iVar3 * 4);
    puVar4 = puVar4 + iVar3 * 2;
    do {
      uVar7 = *puVar1;
      iVar3 = iVar3 + -1;
      puVar4[1] = *(uint *)(puVar8 + ((uVar7 << 0xc) >> 0x1c) * 4) |
                  *(int *)(puVar8 + (uVar7 >> 0x1c) * 4) << 0x18 |
                  *(int *)(puVar8 + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                  *(int *)(puVar8 + ((uVar7 << 8) >> 0x1c) * 4) << 8;
      uVar7 = *puVar1;
      *puVar4 = *(int *)(puVar8 + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                *(int *)(puVar8 + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                *(uint *)(puVar8 + (uVar7 & 0xf) * 4) |
                *(int *)(puVar8 + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
      puVar1 = puVar1 + -1;
      puVar4 = puVar4 + -2;
    } while (-1 < iVar3);
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
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_001b94ba;
        iVar6 = a->top;
      }
      if (0 < iVar6) {
        puVar9 = param_1->d;
        iVar5 = 0;
        puVar4 = a->d;
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)puVar9 + iVar5) = *(undefined4 *)((int)puVar4 + iVar5);
          iVar5 = iVar5 + 4;
          iVar6 = a->top;
        } while (iVar3 < iVar6);
      }
      param_1->top = iVar6;
    }
    pBVar2 = (BIGNUM *)BN_GF2m_mod_arr_part_0(param_1,param_3);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_001b94ba;
  }
  pBVar2 = (BIGNUM *)0x1;
LAB_001b94ba:
  BN_CTX_end(param_4);
  return pBVar2;
}

