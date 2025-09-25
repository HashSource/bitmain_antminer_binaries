
undefined4 bn_div_fixed_top(BIGNUM *param_1,int param_2,int param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong *puVar10;
  ulong *puVar11;
  uint *puVar12;
  ulong *puVar13;
  ulong *puVar14;
  ulong *puVar15;
  int iVar16;
  ulong w;
  uint uVar17;
  ulong uVar18;
  ulong *puVar19;
  uint uVar20;
  uint uVar21;
  int num;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  bool bVar26;
  ulong *local_54;
  int local_50;
  BIGNUM *local_4c;
  
  BN_CTX_start(param_5);
  local_4c = param_1;
  if (param_1 == (BIGNUM *)0x0) {
    local_4c = BN_CTX_get(param_5);
  }
  pBVar1 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  if ((a != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a,param_4), pBVar3 != (BIGNUM *)0x0)) {
    puVar13 = a->d;
    uVar21 = a->top;
    uVar4 = BN_num_bits_word(puVar13[uVar21 + 0x3fffffff]);
    uVar24 = uVar4 & 0x3f;
    uVar23 = 0x40 - uVar4;
    if ((int)uVar4 < 1) {
      uVar24 = -(-uVar4 & 0x3f);
    }
    uVar4 = -uVar24 | -uVar24 >> 8;
    if (0 < (int)uVar21) {
      if ((int)uVar21 < 9) {
        uVar9 = 0;
        uVar22 = uVar9;
      }
      else {
        uVar9 = 0;
        uVar22 = 0;
        puVar14 = puVar13 + 0x13;
        do {
          uVar8 = puVar14[-0x13];
          uVar22 = uVar22 + 8;
          uVar25 = puVar14[-0x12];
          uVar20 = puVar14[-0x11];
          uVar17 = puVar14[-0xf];
          puVar14[-0x13] = uVar9 | uVar8 << (uVar23 & 0xff);
          uVar9 = puVar14[-0xc];
          puVar14[-0x12] = uVar8 >> (uVar24 & 0xff) & uVar4 | uVar25 << (uVar23 & 0xff);
          puVar14[-0x11] = uVar25 >> (uVar24 & 0xff) & uVar4 | uVar20 << (uVar23 & 0xff);
          uVar8 = puVar14[-0xe];
          puVar14[-0xf] = uVar17 << (uVar23 & 0xff) | puVar14[-0x10] >> (uVar24 & 0xff) & uVar4;
          HintPreloadData(puVar14);
          puVar14[-0xc] = uVar9 << (uVar23 & 0xff) | puVar14[-0xd] >> (uVar24 & 0xff) & uVar4;
          uVar9 = uVar9 >> (uVar24 & 0xff) & uVar4;
          puVar14[-0x10] = uVar20 >> (uVar24 & 0xff) & uVar4 | puVar14[-0x10] << (uVar23 & 0xff);
          puVar14[-0xe] = uVar17 >> (uVar24 & 0xff) & uVar4 | uVar8 << (uVar23 & 0xff);
          puVar14[-0xd] = puVar14[-0xd] << (uVar23 & 0xff) | uVar8 >> (uVar24 & 0xff) & uVar4;
          puVar14 = puVar14 + 8;
        } while (uVar22 != (uVar21 - 9 & 0xfffffff8) + 8);
      }
      puVar13 = puVar13 + uVar22;
      do {
        uVar22 = uVar22 + 1;
        uVar8 = *puVar13 << (uVar23 & 0xff) | uVar9;
        uVar9 = *puVar13 >> (uVar24 & 0xff) & uVar4;
        *puVar13 = uVar8;
        puVar13 = puVar13 + 1;
      } while ((int)uVar22 < (int)uVar21);
    }
    a->neg = 0;
    iVar5 = bn_lshift_fixed_top(pBVar2,param_3,uVar23);
    if (iVar5 != 0) {
      num = a->top;
      iVar16 = pBVar2->top;
      iVar5 = iVar16;
      if (iVar16 <= num) {
        iVar5 = num + 1;
        iVar6 = bn_wexpand(pBVar2,iVar5);
        if (iVar6 == 0) goto LAB_00184b56;
        memset(pBVar2->d + iVar16,0,((num - iVar16) + 1) * 4);
        pBVar2->top = iVar5;
      }
      iVar16 = iVar5 - num;
      if (num == 1) {
        uVar21 = 0;
      }
      puVar13 = pBVar2->d;
      uVar24 = a->d[num + 0x3fffffff];
      if (num != 1) {
        uVar21 = a->d[num + 0x3ffffffe];
      }
      iVar6 = bn_wexpand(local_4c,iVar16);
      if (iVar6 != 0) {
        uVar4 = *(uint *)(param_3 + 0xc);
        uVar22 = param_4->neg;
        local_54 = local_4c->d + iVar16;
        local_4c->top = iVar16;
        local_4c->neg = uVar22 ^ uVar4;
        iVar6 = bn_wexpand(pBVar1,num + 1);
        if (iVar6 != 0) {
          if (0 < iVar16) {
            puVar14 = puVar13 + iVar16;
            local_50 = 0;
            puVar13 = puVar13 + iVar5 + 0x3fffffff;
            do {
              if (uVar24 == *puVar13) {
                w = 0xffffffff;
              }
              else {
                uVar18 = puVar13[-1];
                if (puVar14 == puVar13) {
                  uVar22 = 0;
                }
                else {
                  uVar22 = puVar13[-2];
                }
                w = bn_div_words(*puVar13,uVar18,uVar24);
                uVar9 = w * uVar21;
                if ((uVar18 == w * uVar24) && (uVar22 < uVar9)) {
                  w = w - 1;
                  uVar17 = 0;
                  uVar8 = uVar24;
                  do {
                    if (uVar9 < uVar21) {
                      uVar17 = uVar17 - 1;
                    }
                    if ((uVar17 < uVar8) || (uVar9 - uVar21 <= uVar22 && uVar17 == uVar8)) break;
                    bVar26 = CARRY4(uVar8,uVar24);
                    uVar8 = uVar8 + uVar24;
                    w = w - 1;
                    uVar9 = uVar9 - uVar21;
                  } while (!bVar26);
                }
              }
              puVar14 = puVar14 + -1;
              uVar18 = bn_mul_words(pBVar1->d,a->d,num,w);
              puVar10 = pBVar1->d;
              puVar10[num + 0x40000000] = uVar18;
              uVar18 = bn_sub_words(puVar14,puVar14,puVar10,num + 1);
              uVar22 = -uVar18;
              puVar10 = pBVar1->d;
              if (0 < num) {
                puVar19 = a->d;
                if (num < 9) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = 0;
                  puVar11 = puVar10;
                  puVar15 = puVar19 + 0x17;
                  do {
                    iVar5 = iVar5 + 8;
                    HintPreloadData(puVar15);
                    *puVar11 = puVar15[-0x17] & uVar22;
                    puVar11[1] = puVar15[-0x16] & uVar22;
                    puVar11[2] = puVar15[-0x15] & uVar22;
                    puVar11[3] = puVar15[-0x14] & uVar22;
                    puVar11[4] = puVar15[-0x13] & uVar22;
                    puVar11[5] = puVar15[-0x12] & uVar22;
                    puVar11[6] = puVar15[-0x11] & uVar22;
                    puVar11[7] = puVar15[-0x10] & uVar22;
                    puVar11 = puVar11 + 8;
                    puVar15 = puVar15 + 8;
                  } while (iVar5 != (num - 9U & 0xfffffff8) + 8);
                }
                puVar12 = puVar10 + iVar5;
                puVar19 = puVar19 + iVar5;
                do {
                  iVar5 = iVar5 + 1;
                  *puVar12 = *puVar19 & uVar22;
                  puVar12 = puVar12 + 1;
                  puVar19 = puVar19 + 1;
                } while (iVar5 < num);
              }
              uVar7 = bn_add_words(puVar14,puVar14,puVar10,num);
              *puVar13 = uVar7 + *puVar13;
              local_50 = local_50 + 1;
              local_54 = local_54 + -1;
              *local_54 = w - uVar18;
              puVar13 = puVar13 + -1;
            } while (iVar16 != local_50);
          }
          pBVar2->top = num;
          pBVar2->neg = uVar4;
          if ((param_2 == 0) || (iVar5 = bn_rshift_fixed_top(param_2,pBVar2,uVar23), iVar5 != 0)) {
            BN_CTX_end(param_5);
            return 1;
          }
        }
      }
    }
  }
LAB_00184b56:
  BN_CTX_end(param_5);
  return 0;
}

