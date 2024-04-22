
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  bool bVar1;
  uint *puVar2;
  BN_MONT_CTX *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BN_MONT_CTX *pBVar6;
  ulong **ppuVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint extraout_r1;
  int iVar11;
  ulong *puVar12;
  BIGNUM *pBVar13;
  BIGNUM *pBVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  BIGNUM *pBVar19;
  undefined *puVar20;
  undefined *puVar21;
  uint words;
  BIGNUM *pBVar22;
  undefined *puVar23;
  ulong *puVar24;
  BN_CTX **ppBVar25;
  undefined auStack_88 [4];
  int local_84;
  BIGNUM *local_80;
  BIGNUM *local_7c;
  int local_78;
  BIGNUM *local_74;
  BIGNUM *local_70;
  int local_6c;
  BN_MONT_CTX *local_68;
  void *local_64;
  uint local_60;
  BIGNUM *local_5c;
  BIGNUM *local_58;
  size_t local_54;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  ppBVar25 = (BN_CTX **)&stack0xffffff70;
  words = m->top;
  local_5c = rr;
  local_58 = p;
  if ((*m->d & 1) == 0) {
    ERR_put_error(3,0x7c,0x66,DAT_000efcb4,0x2a2);
    return 0;
  }
  pBVar4 = (BIGNUM *)BN_num_bits(p);
  if (pBVar4 == (BIGNUM *)0x0) {
    iVar17 = BN_set_word(local_5c,1);
    return iVar17;
  }
  BN_CTX_start(ctx);
  if (in_mont == (BN_MONT_CTX *)0x0) {
    pBVar6 = BN_MONT_CTX_new();
    local_68 = pBVar6;
    if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb36;
    iVar17 = BN_MONT_CTX_set(pBVar6,m,ctx);
    if (iVar17 != 0) goto LAB_000efa32;
    pBVar6 = (BN_MONT_CTX *)0x0;
    pBVar22 = (BIGNUM *)0x0;
    local_64 = (void *)0x0;
    local_54 = 0;
LAB_000efbb2:
    BN_MONT_CTX_free(local_68);
  }
  else {
    local_68 = in_mont;
LAB_000efa32:
    if ((int)pBVar4 < 0x3aa) {
      if ((int)pBVar4 < 0x133) {
        if ((int)pBVar4 < 0x5a) {
          if ((int)pBVar4 < 0x17) {
            pBVar19 = (BIGNUM *)0x2;
            local_74 = (BIGNUM *)0x1;
            local_60 = 2;
          }
          else {
            pBVar19 = (BIGNUM *)0x8;
            local_74 = (BIGNUM *)0x3;
            local_60 = 8;
          }
        }
        else {
          pBVar19 = (BIGNUM *)0x10;
          local_74 = (BIGNUM *)0x4;
          local_60 = 0x10;
        }
      }
      else {
        pBVar19 = (BIGNUM *)0x20;
        local_74 = (BIGNUM *)0x5;
        local_60 = 0x20;
      }
    }
    else {
      pBVar19 = (BIGNUM *)0x40;
      local_74 = (BIGNUM *)0x6;
      local_60 = 0x40;
    }
    pBVar22 = (BIGNUM *)(words * 2);
    if ((int)((int)pBVar19 + words * -2) < 0 == SBORROW4((int)pBVar19,(int)(BIGNUM *)(words * 2))) {
      pBVar22 = pBVar19;
    }
    local_54 = (int)((int)&pBVar22->d + (int)pBVar19 * words) * 4;
    if ((int)local_54 < 0xc00) {
      ppBVar25 = (BN_CTX **)(&stack0xffffff70 + -(local_54 + 0x48));
      local_64 = (void *)0x0;
      pBVar22 = (BIGNUM *)(((uint)(auStack_88 + -(local_54 + 0x48)) & 0xffffffc0) + 0x40);
      memset(pBVar22,0,local_54);
LAB_000efa7e:
      puVar24 = m->d;
      local_3c.dmax = words;
      local_6c = words * 4;
      iVar11 = words * 4 * (int)pBVar19;
      iVar17 = 2;
      local_3c.top = 0;
      local_50.top = 0;
      local_3c.neg = 0;
      local_50.d = (ulong *)((int)&pBVar22->d + iVar11);
      local_50.neg = 0;
      local_50.dmax = words;
      local_3c.flags = 2;
      local_50.flags = 2;
      local_78 = (words - 1) * 4;
      local_3c.d = (ulong *)((ulong **)local_50.d + words);
      if ((int)puVar24[words - 1] < 0) {
        *(ulong **)((int)&pBVar22->d + iVar11) = (ulong *)-*puVar24;
        if (1 < (int)words) {
          if ((int)words < 10) {
            iVar11 = 1;
          }
          else {
            puVar12 = puVar24 + 0x18;
            ppuVar7 = (ulong **)local_50.d;
            iVar10 = 1;
            do {
              iVar11 = iVar10 + 8;
              iVar17 = iVar10 + 9;
              HintPreloadData(puVar12);
              ppuVar7[1] = (ulong *)~puVar12[-0x17];
              ppuVar7[2] = (ulong *)~puVar12[-0x16];
              ppuVar7[3] = (ulong *)~puVar12[-0x15];
              ppuVar7[4] = (ulong *)~puVar12[-0x14];
              ppuVar7[5] = (ulong *)~puVar12[-0x13];
              ppuVar7[6] = (ulong *)~puVar12[-0x12];
              ppuVar7[7] = (ulong *)~puVar12[-0x11];
              puVar2 = puVar12 + -0x10;
              puVar12 = puVar12 + 8;
              ppuVar7 = ppuVar7 + 8;
              *ppuVar7 = (ulong *)~*puVar2;
              iVar10 = iVar11;
              local_70 = pBVar22;
            } while (iVar17 < (int)(words - 7));
          }
          iVar10 = 0;
          do {
            *(uint *)((int)local_50.d + iVar10 + iVar11 * 4) =
                 ~*(uint *)((int)puVar24 + iVar10 + iVar11 * 4);
            iVar10 = iVar10 + 4;
            bVar1 = iVar17 < (int)words;
            iVar17 = iVar17 + 1;
          } while (bVar1);
        }
        local_50.top = words;
      }
      else {
        pBVar5 = BN_value_one();
        pBVar6 = local_68;
        *ppBVar25 = ctx;
        pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(&local_50,pBVar5,&pBVar6->RR,pBVar6,*ppBVar25)
        ;
        if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb16;
      }
      if ((a->neg == 0) && (iVar17 = BN_ucmp(a,m), pBVar6 = local_68, iVar17 < 0)) {
        local_70 = &local_3c;
        *ppBVar25 = ctx;
        pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(&local_3c,a,&pBVar6->RR,pBVar6,*ppBVar25);
        pBVar5 = local_70;
      }
      else {
        local_70 = &local_3c;
        *ppBVar25 = ctx;
        pBVar6 = (BN_MONT_CTX *)BN_div((BIGNUM *)0x0,&local_3c,a,m,*ppBVar25);
        pBVar3 = local_68;
        pBVar5 = local_70;
        if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb16;
        *ppBVar25 = ctx;
        pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(pBVar5,pBVar5,&pBVar3->RR,pBVar3,*ppBVar25);
        pBVar5 = local_70;
      }
      local_70 = pBVar5;
      if (pBVar6 != (BN_MONT_CTX *)0x0) {
        uVar8 = local_50.top;
        if ((int)words <= local_50.top) {
          uVar8 = words;
        }
        if (uVar8 * 4 != 0) {
          iVar11 = 0;
          iVar17 = iVar11;
          do {
            puVar23 = (undefined *)((int)local_50.d + iVar17);
            iVar17 = iVar17 + 1;
            *(undefined *)((int)&pBVar22->d + iVar11) = *puVar23;
            iVar11 = (int)&pBVar19->d + iVar11;
          } while (iVar17 != uVar8 * 4);
        }
        uVar8 = local_3c.top;
        if ((int)words <= local_3c.top) {
          uVar8 = words;
        }
        if (uVar8 * 4 != 0) {
          iVar17 = 0;
          pBVar13 = pBVar22;
          do {
            puVar23 = (undefined *)((int)local_3c.d + iVar17);
            iVar17 = iVar17 + 1;
            *(undefined *)((int)&pBVar13->d + 1) = *puVar23;
            pBVar13 = (BIGNUM *)((int)&pBVar19->d + (int)&pBVar13->d);
          } while (iVar17 != uVar8 * 4);
        }
        if (local_74 == (BIGNUM *)0x1) {
          local_7c = &local_50;
          puVar23 = (undefined *)((int)&pBVar4[-1].flags + 3);
          local_60 = 0;
LAB_000efdc8:
          pBVar4 = local_58;
          iVar17 = 0;
          iVar11 = local_60 - (int)puVar23;
          puVar20 = puVar23;
          local_80 = pBVar19;
          do {
            puVar21 = puVar20 + -1;
            iVar10 = BN_is_bit_set(pBVar4,(int)puVar20);
            iVar17 = iVar10 + iVar17 * 2;
            puVar20 = puVar21;
          } while (-1 < (int)(puVar21 + iVar11));
          puVar23 = puVar23 + (-1 - (local_60 & ~((int)local_60 >> 0x1f)));
          pBVar19 = local_80;
        }
        else {
          local_7c = &local_50;
          *ppBVar25 = ctx;
          pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(&local_50,pBVar5,pBVar5,local_68,*ppBVar25);
          uVar8 = local_60;
          pBVar13 = local_70;
          pBVar5 = local_7c;
          if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb16;
          uVar18 = local_50.top;
          if ((int)words <= local_50.top) {
            uVar18 = words;
          }
          if (uVar18 * 4 != 0) {
            iVar17 = 0;
            pBVar14 = pBVar22;
            do {
              puVar23 = (undefined *)((int)local_50.d + iVar17);
              iVar17 = iVar17 + 1;
              *(undefined *)((int)&pBVar14->d + 2) = *puVar23;
              pBVar14 = (BIGNUM *)((int)&pBVar19->d + (int)&pBVar14->d);
            } while (iVar17 != uVar18 * 4);
          }
          if (3 < (int)local_60) {
            local_80 = pBVar4;
            uVar18 = 3;
            do {
              pBVar6 = local_68;
              *ppBVar25 = ctx;
              pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(pBVar5,pBVar13,pBVar5,pBVar6,*ppBVar25);
              if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb16;
              uVar9 = local_50.top;
              if ((int)words <= local_50.top) {
                uVar9 = words;
              }
              if (uVar9 * 4 != 0) {
                iVar17 = 0;
                uVar15 = uVar18;
                do {
                  puVar23 = (undefined *)((int)local_50.d + iVar17);
                  iVar17 = iVar17 + 1;
                  *(undefined *)((int)&pBVar22->d + uVar15) = *puVar23;
                  uVar15 = (int)&pBVar19->d + uVar15;
                } while (iVar17 != uVar9 * 4);
              }
              uVar18 = uVar18 + 1;
              pBVar4 = local_80;
            } while (uVar18 != uVar8);
          }
          puVar23 = (undefined *)((int)&pBVar4[-1].flags + 3);
          __aeabi_idivmod(puVar23,local_74);
          local_60 = extraout_r1;
          if (-1 < (int)extraout_r1) goto LAB_000efdc8;
          iVar17 = 0;
        }
        if (((int)words <= local_50.dmax) ||
           (local_84 = iVar17, pBVar6 = (BN_MONT_CTX *)bn_expand2(local_7c,words), iVar17 = local_84
           , pBVar6 != (BN_MONT_CTX *)0x0)) {
          pBVar13 = local_58;
          pBVar3 = local_68;
          pBVar5 = local_74;
          pBVar4 = local_7c;
          if (local_6c != 0) {
            iVar11 = 0;
            do {
              puVar20 = (undefined *)((int)&pBVar22->d + iVar17);
              iVar17 = (int)&pBVar19->d + iVar17;
              *(undefined *)((int)local_50.d + iVar11) = *puVar20;
              iVar11 = iVar11 + 1;
            } while (iVar11 != local_6c);
          }
          local_50.top = words;
          if (0 < (int)words) {
            piVar16 = (int *)((int)local_50.d + local_78);
            do {
              if (*piVar16 != 0) break;
              local_50.top = local_50.top - 1;
              piVar16 = piVar16 + -1;
            } while (local_50.top != 0);
          }
          if (-1 < (int)puVar23) {
            local_60 = words;
            local_80 = pBVar22;
            local_74 = pBVar19;
            do {
              iVar11 = 0;
              iVar17 = 0;
              do {
                iVar17 = iVar17 + 1;
                *ppBVar25 = ctx;
                iVar10 = BN_mod_mul_montgomery(pBVar4,pBVar4,pBVar4,pBVar3,*ppBVar25);
                if (iVar10 == 0) {
                  pBVar6 = (BN_MONT_CTX *)0x0;
                  pBVar22 = local_80;
                  goto LAB_000efb16;
                }
                iVar10 = BN_is_bit_set(pBVar13,(int)puVar23);
                puVar23 = puVar23 + -1;
                iVar11 = iVar11 * 2 + iVar10;
              } while (iVar17 < (int)pBVar5);
              if ((local_3c.dmax < (int)local_60) &&
                 (pBVar6 = (BN_MONT_CTX *)bn_expand2(local_70,local_60), pBVar22 = local_80,
                 pBVar6 == (BN_MONT_CTX *)0x0)) goto LAB_000efb16;
              pBVar22 = local_70;
              if (local_6c != 0) {
                iVar17 = 0;
                do {
                  puVar20 = (undefined *)((int)&local_80->d + iVar11);
                  iVar11 = (int)&local_74->d + iVar11;
                  *(undefined *)((int)local_3c.d + iVar17) = *puVar20;
                  iVar17 = iVar17 + 1;
                } while (iVar17 != local_6c);
              }
              local_3c.top = local_60;
              if (0 < (int)local_60) {
                piVar16 = (int *)((int)local_3c.d + local_78);
                do {
                  if (*piVar16 != 0) break;
                  local_3c.top = local_3c.top - 1;
                  piVar16 = piVar16 + -1;
                } while (local_3c.top != 0);
              }
              *ppBVar25 = ctx;
              pBVar6 = (BN_MONT_CTX *)BN_mod_mul_montgomery(pBVar4,pBVar4,pBVar22,pBVar3,*ppBVar25);
              pBVar22 = local_80;
              if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_000efb16;
            } while (-1 < (int)puVar23);
          }
          pBVar6 = (BN_MONT_CTX *)BN_from_montgomery(local_5c,local_7c,local_68,ctx);
          if (pBVar6 != (BN_MONT_CTX *)0x0) {
            pBVar6 = (BN_MONT_CTX *)0x1;
          }
        }
      }
    }
    else {
      local_64 = CRYPTO_malloc(local_54 + 0x40,DAT_000efcb4,0x2fa);
      if (local_64 != (void *)0x0) {
        pBVar22 = (BIGNUM *)(((uint)local_64 & 0xffffffc0) + 0x40);
        memset(pBVar22,0,local_54);
        goto LAB_000efa7e;
      }
      pBVar6 = (BN_MONT_CTX *)0x0;
      pBVar22 = (BIGNUM *)0x0;
    }
LAB_000efb16:
    if (in_mont == (BN_MONT_CTX *)0x0) goto LAB_000efbb2;
  }
  if ((pBVar22 != (BIGNUM *)0x0) && (OPENSSL_cleanse(pBVar22,local_54), local_64 != (void *)0x0)) {
    CRYPTO_free(local_64);
  }
LAB_000efb36:
  BN_CTX_end(ctx);
  return (int)pBVar6;
}

