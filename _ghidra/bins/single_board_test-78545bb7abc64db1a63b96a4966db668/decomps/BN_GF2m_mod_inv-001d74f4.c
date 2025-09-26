
int BN_GF2m_mod_inv(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  int iVar8;
  ulong *puVar9;
  ulong *puVar10;
  int iVar11;
  int iVar12;
  ulong *puVar13;
  ulong *puVar14;
  int iVar15;
  ulong uVar16;
  ulong *puVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  bool bVar26;
  ulong *local_70;
  ulong *local_68;
  ulong *local_64;
  BIGNUM *local_60;
  BIGNUM *local_5c;
  BIGNUM *local_58;
  BIGNUM *local_54;
  
  BN_CTX_start(param_4);
  pBVar2 = BN_CTX_get(param_4);
  if (pBVar2 != (BIGNUM *)0x0) {
    do {
      iVar3 = BN_num_bits(param_3);
      iVar3 = BN_priv_rand(pBVar2,iVar3 + -1,0xffffffff,0);
      if (iVar3 == 0) goto LAB_001d7534;
      iVar3 = BN_is_zero(pBVar2);
    } while (iVar3 != 0);
    iVar3 = BN_GF2m_mod_mul(param_1,param_2,pBVar2,param_3,param_4);
    if (iVar3 != 0) {
      BN_CTX_start(param_4);
      local_5c = BN_CTX_get(param_4);
      local_58 = BN_CTX_get(param_4);
      local_60 = BN_CTX_get(param_4);
      local_54 = BN_CTX_get(param_4);
      if ((((local_54 != (BIGNUM *)0x0) &&
           (iVar3 = BN_GF2m_mod(local_60,param_1,param_3), iVar3 != 0)) &&
          (iVar3 = BN_is_zero(local_60), iVar3 == 0)) &&
         (pBVar4 = BN_copy(local_54,param_3), pBVar4 != (BIGNUM *)0x0)) {
        iVar3 = BN_num_bits(local_60);
        iVar5 = BN_num_bits(local_54);
        iVar15 = param_3->top;
        iVar6 = bn_wexpand(local_60,iVar15);
        if (iVar6 != 0) {
          iVar6 = local_60->top;
          puVar10 = local_60->d;
          if (iVar6 < iVar15) {
            memset(puVar10 + iVar6,0,(iVar15 - iVar6) * 4);
          }
          local_60->top = iVar15;
          iVar6 = bn_wexpand(local_5c,iVar15);
          if (iVar6 != 0) {
            local_70 = local_5c->d;
            *local_70 = 1;
            if (1 < iVar15) {
              memset(local_70 + 1,0,(iVar15 + 0x3fffffff) * 4);
            }
            local_5c->top = iVar15;
            iVar6 = bn_wexpand(local_58,iVar15);
            if (iVar6 != 0) {
              local_68 = local_58->d;
              if (0 < iVar15) {
                memset(local_68,0,iVar15 * 4);
              }
              local_58->top = iVar15;
              iVar11 = iVar15 + -1;
              iVar12 = iVar15 + -8;
              bVar26 = SBORROW4(iVar11,-0x7ffffff9);
              iVar6 = iVar15 + 0x7ffffff8;
              bVar25 = iVar11 == -0x7ffffff9;
              if (-0x7ffffffa < iVar11) {
                bVar26 = SBORROW4(iVar12,1);
                iVar6 = iVar15 + -9;
                bVar25 = iVar12 == 1;
              }
              local_64 = local_54->d;
LAB_001d76b0:
              iVar20 = iVar5;
              if (iVar3 != 0) goto LAB_001d775c;
LAB_001d76b4:
              uVar16 = *puVar10;
              if (uVar16 != 0) {
LAB_001d76be:
                iVar5 = iVar20;
                if (uVar16 != 1) {
LAB_001d76c4:
                  pBVar1 = local_5c;
                  pBVar4 = local_60;
                  iVar20 = iVar3;
                  if (iVar3 < iVar5) {
                    local_70 = local_68;
                    local_60 = local_54;
                    local_68 = local_5c->d;
                    local_54 = pBVar4;
                    local_5c = local_58;
                    local_58 = pBVar1;
                    iVar20 = iVar5;
                    iVar5 = iVar3;
                    puVar10 = local_64;
                    local_64 = pBVar4->d;
                  }
                  if (0 < iVar15) {
                    puVar17 = local_64 + -1;
                    puVar7 = local_68 + -1;
                    puVar9 = local_70;
                    puVar13 = puVar10;
                    do {
                      puVar17 = puVar17 + 1;
                      puVar14 = puVar13 + 1;
                      *puVar13 = *puVar13 ^ *puVar17;
                      puVar7 = puVar7 + 1;
                      *puVar9 = *puVar7 ^ *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar13 = puVar14;
                    } while (puVar10 + iVar15 != puVar14);
                  }
                  iVar3 = iVar20;
                  if (iVar20 != iVar5) goto LAB_001d76b0;
                  iVar5 = iVar20 + 0x3e;
                  if (-1 < iVar20 + -1) {
                    iVar5 = iVar20 + -1;
                  }
                  iVar5 = iVar5 >> 6;
                  puVar17 = puVar10 + iVar5;
                  uVar16 = puVar10[iVar5];
                  while (uVar16 == 0) {
                    if (iVar5 == 0) {
                      iVar5 = 0;
                      goto LAB_001d7750;
                    }
                    puVar17 = puVar17 + -1;
                    iVar5 = iVar5 + -1;
                    uVar16 = *puVar17;
                  }
                  iVar5 = iVar5 << 6;
LAB_001d7750:
                  iVar3 = BN_num_bits_word(uVar16);
                  iVar3 = iVar3 + iVar5;
                  if (iVar3 == 0) goto LAB_001d76b4;
LAB_001d775c:
                  uVar16 = *puVar10;
                  iVar5 = iVar20;
                  if ((uVar16 & 1) != 0) {
                    if (iVar3 < 0x41) goto LAB_001d76be;
                    goto LAB_001d76c4;
                  }
                  puVar17 = param_3->d;
                  uVar18 = (int)(*local_70 << 0x1f) >> 0x1f;
                  uVar19 = *local_70 ^ *puVar17 & uVar18;
                  if (iVar11 < 1) {
                    iVar20 = 0;
                  }
                  else {
                    if (bVar25 || iVar6 < 0 != bVar26) {
                      iVar8 = 0;
                    }
                    else {
                      iVar8 = 0;
                      puVar7 = puVar17 + 0xb;
                      puVar9 = puVar10 + 0xb;
                      puVar13 = local_70 + 0xb;
                      do {
                        uVar21 = puVar9[-10];
                        HintPreloadData(puVar7);
                        puVar9[-0xb] = uVar16 >> 1;
                        HintPreloadData(puVar9);
                        iVar20 = iVar8 + 9;
                        uVar22 = puVar7[-10];
                        puVar13[-0xb] = uVar19 >> 1;
                        iVar8 = iVar8 + 8;
                        uVar19 = puVar13[-10];
                        uVar23 = puVar9[-9];
                        HintPreloadData(puVar13);
                        puVar9[-10] = uVar21 >> 1;
                        uVar21 = puVar7[-9];
                        puVar13[-10] = (uVar18 & uVar22 ^ uVar19) >> 1;
                        uVar22 = puVar13[-9];
                        puVar9[-9] = uVar23 >> 1;
                        uVar19 = puVar9[-8];
                        uVar23 = puVar7[-8];
                        puVar13[-9] = (uVar18 & uVar21 ^ uVar22) >> 1;
                        uVar21 = puVar13[-8];
                        puVar9[-8] = uVar19 >> 1;
                        uVar19 = puVar7[-7];
                        uVar22 = puVar9[-7];
                        uVar24 = puVar13[-7];
                        puVar13[-8] = (uVar18 & uVar23 ^ uVar21) >> 1;
                        uVar21 = puVar9[-6];
                        puVar9[-7] = uVar22 >> 1;
                        uVar22 = puVar7[-6];
                        puVar13[-7] = (uVar19 & uVar18 ^ uVar24) >> 1;
                        uVar19 = puVar13[-6];
                        puVar9[-6] = uVar21 >> 1;
                        uVar24 = puVar7[-5];
                        uVar23 = puVar9[-5];
                        puVar13[-6] = (uVar18 & uVar22 ^ uVar19) >> 1;
                        uVar21 = puVar13[-5];
                        puVar9[-5] = uVar23 >> 1;
                        uVar19 = puVar9[-4];
                        uVar22 = puVar7[-4];
                        uVar23 = puVar13[-4];
                        puVar13[-5] = (uVar18 & uVar24 ^ uVar21) >> 1;
                        uVar16 = puVar9[-3];
                        puVar9[-4] = uVar19 >> 1;
                        uVar19 = puVar7[-3];
                        puVar13[-4] = (uVar18 & uVar22 ^ uVar23) >> 1;
                        uVar19 = uVar19 & uVar18 ^ puVar13[-3];
                        puVar7 = puVar7 + 8;
                        puVar9 = puVar9 + 8;
                        puVar13 = puVar13 + 8;
                      } while (iVar20 < iVar12);
                    }
                    puVar17 = puVar17 + iVar8;
                    puVar7 = local_70 + iVar8;
                    puVar9 = puVar10 + iVar8;
                    do {
                      uVar21 = uVar16 >> 1;
                      uVar16 = puVar9[1];
                      iVar8 = iVar8 + 1;
                      *puVar9 = uVar21;
                      puVar17 = puVar17 + 1;
                      uVar21 = *puVar17;
                      *puVar7 = uVar19 >> 1;
                      uVar19 = puVar7[1] ^ uVar18 & uVar21;
                      iVar20 = iVar11 * 4;
                      puVar7 = puVar7 + 1;
                      puVar9 = puVar9 + 1;
                    } while (iVar8 < iVar11);
                  }
                  *(ulong *)((int)puVar10 + iVar20) = uVar16 >> 1;
                  iVar3 = iVar3 + -1;
                  *(uint *)((int)local_70 + iVar20) = uVar19 >> 1;
                  goto LAB_001d76b0;
                }
                bn_correct_top(local_5c);
                pBVar4 = BN_copy(param_1,local_5c);
                if (pBVar4 == (BIGNUM *)0x0) goto LAB_001d758e;
                BN_CTX_end(param_4);
                iVar3 = BN_GF2m_mod_mul(param_1,param_1,pBVar2,param_3,param_4);
                if (iVar3 != 0) {
                  iVar3 = 1;
                }
                goto LAB_001d7536;
              }
            }
          }
        }
      }
LAB_001d758e:
      BN_CTX_end(param_4);
      BN_CTX_end(param_4);
      return 0;
    }
  }
LAB_001d7534:
  iVar3 = 0;
LAB_001d7536:
  BN_CTX_end(param_4);
  return iVar3;
}

