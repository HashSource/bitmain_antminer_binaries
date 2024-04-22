
BIGNUM * BN_GF2m_mod_inv(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  bool bVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  ulong *puVar10;
  ulong *puVar11;
  ulong *puVar12;
  ulong *puVar13;
  int iVar14;
  BIGNUM *pBVar15;
  uint uVar16;
  ulong uVar17;
  ulong uVar18;
  uint uVar19;
  ulong *puVar20;
  ulong *puVar21;
  ulong *puVar22;
  uint uVar23;
  int local_70;
  int local_64;
  BIGNUM *local_60;
  BIGNUM *local_5c;
  BIGNUM *local_54;
  BIGNUM *local_4c;
  
  BN_CTX_start(param_4);
  local_60 = BN_CTX_get(param_4);
  if ((((local_60 != (BIGNUM *)0x0) && (local_54 = BN_CTX_get(param_4), local_54 != (BIGNUM *)0x0))
      && (local_5c = BN_CTX_get(param_4), local_5c != (BIGNUM *)0x0)) &&
     (((local_4c = BN_CTX_get(param_4), local_4c != (BIGNUM *)0x0 &&
       (iVar3 = BN_GF2m_mod(local_5c,param_2,param_3), iVar3 != 0)) &&
      ((local_5c->top != 0 && (pBVar15 = BN_copy(local_4c,param_3), pBVar15 != (BIGNUM *)0x0)))))) {
    local_70 = BN_num_bits(local_5c);
    local_64 = BN_num_bits(local_4c);
    iVar3 = param_3->top;
    if (local_5c->dmax < iVar3) {
      bn_expand2(local_5c,iVar3);
    }
    iVar4 = local_5c->top;
    puVar22 = local_5c->d;
    if (iVar4 < iVar3) {
      iVar7 = iVar4 + 1;
      if (-0x7ffffffa < iVar3 && iVar7 < iVar3 + -7) {
        puVar21 = puVar22 + iVar4;
        iVar8 = iVar4;
        do {
          iVar4 = iVar8 + 8;
          HintPreloadData(puVar21 + 0x22);
          iVar7 = iVar8 + 9;
          *puVar21 = 0;
          puVar21[1] = 0;
          puVar21[2] = 0;
          puVar21[3] = 0;
          puVar21[4] = 0;
          puVar21[5] = 0;
          puVar21[6] = 0;
          puVar21[7] = 0;
          puVar21 = puVar21 + 8;
          iVar8 = iVar4;
        } while (iVar7 < iVar3 + -7);
      }
      puVar21 = puVar22 + iVar4 + -1;
      do {
        puVar21 = puVar21 + 1;
        *puVar21 = 0;
        bVar1 = iVar7 < iVar3;
        iVar7 = iVar7 + 1;
      } while (bVar1);
    }
    iVar4 = local_60->dmax;
    local_5c->top = iVar3;
    if (iVar4 < iVar3) {
      bn_expand2(local_60,iVar3);
    }
    iVar4 = 1;
    puVar21 = local_60->d;
    *puVar21 = 1;
    if (1 < iVar3) {
      iVar7 = iVar4;
      puVar20 = puVar21;
      if (iVar3 < 10) {
        iVar8 = 2;
      }
      else {
        do {
          iVar4 = iVar7 + 8;
          HintPreloadData(puVar20 + 0x23);
          iVar8 = iVar7 + 9;
          puVar20[1] = 0;
          puVar20[2] = 0;
          puVar20[3] = 0;
          puVar20[4] = 0;
          puVar20[5] = 0;
          puVar20[6] = 0;
          puVar20[7] = 0;
          puVar20[8] = 0;
          iVar7 = iVar4;
          puVar20 = puVar20 + 8;
        } while (iVar8 < iVar3 + -7);
      }
      puVar20 = puVar21 + iVar4 + -1;
      do {
        puVar20 = puVar20 + 1;
        *puVar20 = 0;
        bVar1 = iVar8 < iVar3;
        iVar8 = iVar8 + 1;
      } while (bVar1);
    }
    iVar4 = local_54->dmax;
    local_60->top = iVar3;
    if (iVar4 < iVar3) {
      bn_expand2(local_54,iVar3);
    }
    puVar20 = local_54->d;
    if (0 < iVar3) {
      if (iVar3 < 9) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        puVar11 = puVar20;
        do {
          iVar4 = iVar4 + 8;
          HintPreloadData(puVar11 + 0x22);
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
          puVar11[3] = 0;
          puVar11[4] = 0;
          puVar11[5] = 0;
          puVar11[6] = 0;
          puVar11[7] = 0;
          puVar11 = puVar11 + 8;
        } while (iVar4 != (iVar3 - 9U & 0xfffffff8) + 8);
      }
      puVar11 = puVar20 + iVar4 + -1;
      do {
        iVar4 = iVar4 + 1;
        puVar11 = puVar11 + 1;
        *puVar11 = 0;
      } while (iVar4 < iVar3);
    }
    iVar4 = iVar3 + -1;
    local_54->top = iVar3;
    puVar11 = local_4c->d;
LAB_00123786:
    uVar18 = *puVar22;
    if (local_70 != 0) goto LAB_0012383a;
LAB_00123790:
    if (uVar18 != 0) {
LAB_00123796:
      puVar12 = puVar20;
      puVar5 = puVar11;
      if (uVar18 != 1) {
LAB_0012379c:
        pBVar2 = local_5c;
        pBVar15 = local_60;
        iVar7 = local_70;
        puVar20 = puVar12;
        puVar11 = puVar5;
        if (local_70 < local_64) {
          puVar11 = local_5c->d;
          local_5c = local_4c;
          puVar20 = local_60->d;
          local_70 = local_64;
          local_64 = iVar7;
          local_4c = pBVar2;
          local_60 = local_54;
          local_54 = pBVar15;
          puVar21 = puVar12;
          puVar22 = puVar5;
        }
        if (0 < iVar3) {
          iVar7 = 0;
          do {
            *(uint *)((int)puVar22 + iVar7) =
                 *(uint *)((int)puVar11 + iVar7) ^ *(uint *)((int)puVar22 + iVar7);
            *(uint *)((int)puVar21 + iVar7) =
                 *(uint *)((int)puVar20 + iVar7) ^ *(uint *)((int)puVar21 + iVar7);
            iVar7 = iVar7 + 4;
          } while (iVar7 != iVar3 << 2);
        }
        if (local_70 != local_64) goto LAB_00123786;
        iVar7 = local_70 + 0x1e;
        if (-1 < local_70 + -1) {
          iVar7 = local_70 + -1;
        }
        iVar7 = iVar7 >> 5;
        puVar12 = puVar22 + iVar7;
        uVar18 = puVar22[iVar7];
        while (uVar18 == 0) {
          if (iVar7 == 0) {
            iVar7 = 0;
            goto LAB_00123824;
          }
          puVar12 = puVar12 + -1;
          iVar7 = iVar7 + -1;
          uVar18 = *puVar12;
        }
        iVar7 = iVar7 << 5;
LAB_00123824:
        local_64 = local_70;
        local_70 = BN_num_bits_word(uVar18);
        local_70 = local_70 + iVar7;
        uVar18 = *puVar22;
        if (local_70 == 0) goto LAB_00123790;
LAB_0012383a:
        if ((uVar18 & 1) != 0) {
          puVar12 = puVar20;
          puVar5 = puVar11;
          if (local_70 < 0x21) goto LAB_00123796;
          goto LAB_0012379c;
        }
        puVar12 = param_3->d;
        uVar6 = (int)(*puVar21 << 0x1f) >> 0x1f;
        uVar23 = uVar6 & *puVar12 ^ *puVar21;
        iVar7 = 0;
        if (0 < iVar4) {
          if (iVar3 < 10) {
            iVar8 = 0;
          }
          else {
            iVar8 = 0;
            puVar5 = puVar12;
            puVar9 = puVar22;
            puVar13 = puVar21;
            do {
              uVar19 = puVar9[1];
              HintPreloadData(puVar5 + 10);
              iVar8 = iVar8 + 8;
              HintPreloadData(puVar9 + 10);
              HintPreloadData(puVar13 + 10);
              *puVar9 = uVar18 >> 1 | uVar19 << 0x1f;
              uVar16 = puVar13[1] ^ puVar5[1] & uVar6;
              *puVar13 = uVar23 >> 1 | uVar16 << 0x1f;
              uVar23 = puVar9[2];
              puVar9[1] = uVar19 >> 1 | uVar23 << 0x1f;
              uVar19 = puVar13[2] ^ puVar5[2] & uVar6;
              puVar13[1] = uVar16 >> 1 | uVar19 << 0x1f;
              uVar16 = puVar9[3];
              puVar9[2] = uVar23 >> 1 | uVar16 << 0x1f;
              uVar23 = puVar13[3] ^ puVar5[3] & uVar6;
              puVar13[2] = uVar19 >> 1 | uVar23 << 0x1f;
              uVar19 = puVar9[4];
              puVar9[3] = uVar16 >> 1 | uVar19 << 0x1f;
              uVar16 = puVar13[4] ^ puVar5[4] & uVar6;
              puVar13[3] = uVar23 >> 1 | uVar16 << 0x1f;
              uVar23 = puVar9[5];
              puVar9[4] = uVar19 >> 1 | uVar23 << 0x1f;
              uVar19 = puVar13[5] ^ puVar5[5] & uVar6;
              puVar13[4] = uVar16 >> 1 | uVar19 << 0x1f;
              uVar16 = puVar9[6];
              puVar9[5] = uVar23 >> 1 | uVar16 << 0x1f;
              uVar23 = puVar13[6] ^ puVar5[6] & uVar6;
              puVar13[5] = uVar19 >> 1 | uVar23 << 0x1f;
              uVar19 = puVar9[7];
              puVar9[6] = uVar16 >> 1 | uVar19 << 0x1f;
              uVar16 = puVar13[7] ^ puVar5[7] & uVar6;
              puVar13[6] = uVar23 >> 1 | uVar16 << 0x1f;
              uVar18 = puVar9[8];
              puVar9[7] = uVar19 >> 1 | uVar18 << 0x1f;
              puVar9 = puVar9 + 8;
              puVar5 = puVar5 + 8;
              uVar23 = uVar6 & *puVar5 ^ puVar13[8];
              puVar13[7] = uVar16 >> 1 | uVar23 << 0x1f;
              puVar13 = puVar13 + 8;
            } while (iVar8 != (iVar3 - 10U & 0xfffffff8) + 8);
          }
          puVar13 = puVar22 + iVar8;
          puVar10 = puVar21 + iVar8;
          puVar12 = puVar12 + iVar8;
          iVar14 = 0;
          uVar17 = uVar18;
          puVar9 = puVar10;
          puVar5 = puVar13;
          do {
            puVar5 = puVar5 + 1;
            uVar18 = *puVar5;
            uVar16 = uVar23 >> 1;
            iVar8 = iVar8 + 1;
            *(ulong *)((int)puVar13 + iVar14) = uVar17 >> 1 | uVar18 << 0x1f;
            puVar12 = puVar12 + 1;
            puVar9 = puVar9 + 1;
            uVar23 = *puVar12 & uVar6 ^ *puVar9;
            *(uint *)((int)puVar10 + iVar14) = uVar16 | uVar23 << 0x1f;
            iVar14 = iVar14 + 4;
            iVar7 = iVar4 * 4;
            uVar17 = uVar18;
          } while (iVar8 < iVar4);
        }
        *(ulong *)((int)puVar22 + iVar7) = uVar18 >> 1;
        local_70 = local_70 + -1;
        *(uint *)((int)puVar21 + iVar7) = uVar23 >> 1;
        goto LAB_00123786;
      }
      iVar3 = local_60->top;
      if (iVar3 < 1) goto LAB_00123a44;
      puVar22 = local_60->d + iVar3 + -1;
      goto LAB_00123a36;
    }
  }
  pBVar15 = (BIGNUM *)0x0;
  goto LAB_00123600;
  while (iVar3 = iVar3 + -1, puVar22 = puVar22 + -1, iVar3 != 0) {
LAB_00123a36:
    if (*puVar22 != 0) break;
  }
  local_60->top = iVar3;
LAB_00123a44:
  pBVar15 = BN_copy(param_1,local_60);
  if (pBVar15 != (BIGNUM *)0x0) {
    pBVar15 = (BIGNUM *)0x1;
  }
LAB_00123600:
  BN_CTX_end(param_4);
  return pBVar15;
}

