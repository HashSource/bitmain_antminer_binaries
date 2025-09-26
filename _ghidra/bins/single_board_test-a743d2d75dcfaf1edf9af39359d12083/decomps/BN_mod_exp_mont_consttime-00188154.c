
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  bool bVar1;
  uint *puVar2;
  undefined1 *puVar3;
  BN_MONT_CTX *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BN_MONT_CTX *pBVar7;
  ulong **ppuVar8;
  undefined1 *extraout_r1;
  int iVar9;
  ulong *puVar10;
  int iVar11;
  BIGNUM *pBVar12;
  BIGNUM *pBVar13;
  int *piVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  int iVar17;
  BIGNUM *pBVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  BIGNUM *pBVar21;
  undefined1 *puVar22;
  ulong *puVar23;
  undefined4 *puVar24;
  undefined1 auStack_88 [4];
  undefined1 *local_84;
  BIGNUM *local_80;
  BIGNUM *local_7c;
  int local_78;
  BIGNUM *local_74;
  BIGNUM *local_70;
  int local_6c;
  BN_MONT_CTX *local_68;
  void *local_64;
  undefined1 *local_60;
  BIGNUM *local_5c;
  BIGNUM *local_58;
  size_t local_54;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  puVar24 = (undefined4 *)&stack0xffffff70;
  puVar20 = (undefined1 *)m->top;
  local_5c = rr;
  local_58 = p;
  if ((*m->d & 1) == 0) {
    ERR_put_error(3,0x7c,0x66,"bn_exp.c",0x2a2);
    return 0;
  }
  pBVar5 = (BIGNUM *)BN_num_bits(p);
  if (pBVar5 == (BIGNUM *)0x0) {
    iVar17 = BN_set_word(local_5c,1);
    return iVar17;
  }
  BN_CTX_start(ctx);
  if (in_mont == (BN_MONT_CTX *)0x0) {
    pBVar7 = BN_MONT_CTX_new();
    local_68 = pBVar7;
    if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018829a;
    iVar17 = BN_MONT_CTX_set(pBVar7,m,ctx);
    if (iVar17 != 0) goto LAB_00188196;
    pBVar7 = (BN_MONT_CTX *)0x0;
    pBVar21 = (BIGNUM *)0x0;
    local_64 = (void *)0x0;
    local_54 = 0;
LAB_00188316:
    BN_MONT_CTX_free(local_68);
  }
  else {
    local_68 = in_mont;
LAB_00188196:
    if ((int)pBVar5 < 0x3aa) {
      if ((int)pBVar5 < 0x133) {
        if ((int)pBVar5 < 0x5a) {
          if ((int)pBVar5 < 0x17) {
            pBVar18 = (BIGNUM *)0x2;
            local_74 = (BIGNUM *)0x1;
            local_60 = (undefined1 *)0x2;
          }
          else {
            pBVar18 = (BIGNUM *)0x8;
            local_74 = (BIGNUM *)0x3;
            local_60 = (undefined1 *)0x8;
          }
        }
        else {
          pBVar18 = (BIGNUM *)0x10;
          local_74 = (BIGNUM *)0x4;
          local_60 = (undefined1 *)0x10;
        }
      }
      else {
        pBVar18 = (BIGNUM *)0x20;
        local_74 = (BIGNUM *)&DAT_00000005;
        local_60 = (undefined1 *)0x20;
      }
    }
    else {
      pBVar18 = (BIGNUM *)0x40;
      local_74 = (BIGNUM *)&DAT_00000006;
      local_60 = (undefined1 *)0x40;
    }
    pBVar21 = (BIGNUM *)((int)puVar20 * 2);
    if ((int)((int)pBVar18 + (int)puVar20 * -2) < 0 == SBORROW4((int)pBVar18,(int)puVar20 * 2)) {
      pBVar21 = pBVar18;
    }
    local_54 = (int)((int)&pBVar21->d + (int)pBVar18 * (int)puVar20) * 4;
    if ((int)local_54 < 0xc00) {
      puVar24 = (undefined4 *)(&stack0xffffff70 + -(local_54 + 0x48));
      local_64 = (void *)0x0;
      pBVar21 = (BIGNUM *)(((uint)(auStack_88 + -(local_54 + 0x48)) & 0xffffffc0) + 0x40);
      memset(pBVar21,0,local_54);
LAB_001881e2:
      puVar23 = m->d;
      local_3c.dmax = (int)puVar20;
      local_6c = (int)puVar20 * 4;
      iVar9 = (int)puVar20 * 4 * (int)pBVar18;
      iVar17 = 2;
      local_3c.top = 0;
      local_50.top = 0;
      local_3c.neg = 0;
      local_50.d = (ulong *)((int)&pBVar21->d + iVar9);
      local_50.neg = 0;
      local_50.dmax = (int)puVar20;
      local_3c.flags = 2;
      local_50.flags = 2;
      local_78 = (int)(puVar20 + -1) * 4;
      local_3c.d = (ulong *)((ulong **)local_50.d + (int)puVar20);
      if ((int)puVar23[(int)(puVar20 + -1)] < 0) {
        *(ulong **)((int)&pBVar21->d + iVar9) = (ulong *)-*puVar23;
        if (1 < (int)puVar20) {
          if ((int)puVar20 < 10) {
            iVar9 = 1;
          }
          else {
            puVar10 = puVar23 + 0x18;
            ppuVar8 = (ulong **)local_50.d;
            iVar11 = 1;
            do {
              iVar9 = iVar11 + 8;
              iVar17 = iVar11 + 9;
              HintPreloadData(puVar10);
              ppuVar8[1] = (ulong *)~puVar10[-0x17];
              ppuVar8[2] = (ulong *)~puVar10[-0x16];
              ppuVar8[3] = (ulong *)~puVar10[-0x15];
              ppuVar8[4] = (ulong *)~puVar10[-0x14];
              ppuVar8[5] = (ulong *)~puVar10[-0x13];
              ppuVar8[6] = (ulong *)~puVar10[-0x12];
              ppuVar8[7] = (ulong *)~puVar10[-0x11];
              puVar2 = puVar10 + -0x10;
              puVar10 = puVar10 + 8;
              ppuVar8 = ppuVar8 + 8;
              *ppuVar8 = (ulong *)~*puVar2;
              iVar11 = iVar9;
              local_70 = pBVar21;
            } while (iVar17 < (int)(puVar20 + -7));
          }
          iVar11 = 0;
          do {
            *(uint *)((int)local_50.d + iVar11 + iVar9 * 4) =
                 ~*(uint *)((int)puVar23 + iVar11 + iVar9 * 4);
            iVar11 = iVar11 + 4;
            bVar1 = iVar17 < (int)puVar20;
            iVar17 = iVar17 + 1;
          } while (bVar1);
        }
        local_50.top = (int)puVar20;
      }
      else {
        pBVar6 = BN_value_one();
        pBVar7 = local_68;
        *puVar24 = ctx;
        pBVar7 = (BN_MONT_CTX *)
                 BN_mod_mul_montgomery(&local_50,pBVar6,&pBVar7->RR,pBVar7,(BN_CTX *)*puVar24);
        if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018827a;
      }
      if ((a->neg == 0) && (iVar17 = BN_ucmp(a,m), pBVar7 = local_68, iVar17 < 0)) {
        local_70 = &local_3c;
        *puVar24 = ctx;
        pBVar7 = (BN_MONT_CTX *)
                 BN_mod_mul_montgomery(&local_3c,a,&pBVar7->RR,pBVar7,(BN_CTX *)*puVar24);
        pBVar6 = local_70;
      }
      else {
        local_70 = &local_3c;
        *puVar24 = ctx;
        pBVar7 = (BN_MONT_CTX *)BN_div((BIGNUM *)0x0,&local_3c,a,m,(BN_CTX *)*puVar24);
        pBVar4 = local_68;
        pBVar6 = local_70;
        if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018827a;
        *puVar24 = ctx;
        pBVar7 = (BN_MONT_CTX *)
                 BN_mod_mul_montgomery(pBVar6,pBVar6,&pBVar4->RR,pBVar4,(BN_CTX *)*puVar24);
        pBVar6 = local_70;
      }
      local_70 = pBVar6;
      if (pBVar7 != (BN_MONT_CTX *)0x0) {
        puVar22 = (undefined1 *)local_50.top;
        if ((int)puVar20 <= local_50.top) {
          puVar22 = puVar20;
        }
        if ((undefined1 *)((int)puVar22 * 4) != (undefined1 *)0x0) {
          puVar15 = (undefined1 *)0x0;
          puVar16 = puVar15;
          do {
            puVar19 = (undefined1 *)((int)local_50.d + (int)puVar16);
            puVar16 = puVar16 + 1;
            *(undefined1 *)((int)&pBVar21->d + (int)puVar15) = *puVar19;
            puVar15 = (undefined1 *)((int)&pBVar18->d + (int)puVar15);
          } while (puVar16 != (undefined1 *)((int)puVar22 * 4));
        }
        puVar22 = (undefined1 *)local_3c.top;
        if ((int)puVar20 <= local_3c.top) {
          puVar22 = puVar20;
        }
        if ((int)puVar22 * 4 != 0) {
          iVar17 = 0;
          pBVar12 = pBVar21;
          do {
            puVar16 = (undefined1 *)((int)local_3c.d + iVar17);
            iVar17 = iVar17 + 1;
            *(undefined1 *)((int)&pBVar12->d + 1) = *puVar16;
            pBVar12 = (BIGNUM *)((int)&pBVar18->d + (int)&pBVar12->d);
          } while (iVar17 != (int)puVar22 * 4);
        }
        if (local_74 == (BIGNUM *)0x1) {
          local_7c = &local_50;
          puVar22 = (undefined1 *)((int)&pBVar5[-1].flags + 3);
          local_60 = (undefined1 *)0x0;
LAB_0018852c:
          pBVar5 = local_58;
          puVar16 = (undefined1 *)0x0;
          iVar17 = (int)local_60 - (int)puVar22;
          puVar15 = puVar22;
          local_80 = pBVar18;
          do {
            puVar19 = puVar15 + -1;
            iVar9 = BN_is_bit_set(pBVar5,(int)puVar15);
            puVar16 = (undefined1 *)(iVar9 + (int)puVar16 * 2);
            puVar15 = puVar19;
          } while (-1 < (int)(puVar19 + iVar17));
          puVar22 = puVar22 + (-1 - ((uint)local_60 & ~((int)local_60 >> 0x1f)));
          pBVar18 = local_80;
        }
        else {
          local_7c = &local_50;
          *puVar24 = ctx;
          pBVar7 = (BN_MONT_CTX *)
                   BN_mod_mul_montgomery(&local_50,pBVar6,pBVar6,local_68,(BN_CTX *)*puVar24);
          puVar22 = local_60;
          pBVar12 = local_70;
          pBVar6 = local_7c;
          if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018827a;
          puVar16 = (undefined1 *)local_50.top;
          if ((int)puVar20 <= local_50.top) {
            puVar16 = puVar20;
          }
          if ((int)puVar16 * 4 != 0) {
            iVar17 = 0;
            pBVar13 = pBVar21;
            do {
              puVar15 = (undefined1 *)((int)local_50.d + iVar17);
              iVar17 = iVar17 + 1;
              *(undefined1 *)((int)&pBVar13->d + 2) = *puVar15;
              pBVar13 = (BIGNUM *)((int)&pBVar18->d + (int)&pBVar13->d);
            } while (iVar17 != (int)puVar16 * 4);
          }
          if (3 < (int)local_60) {
            local_80 = pBVar5;
            puVar16 = (undefined1 *)0x3;
            do {
              pBVar7 = local_68;
              *puVar24 = ctx;
              pBVar7 = (BN_MONT_CTX *)
                       BN_mod_mul_montgomery(pBVar6,pBVar12,pBVar6,pBVar7,(BN_CTX *)*puVar24);
              if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018827a;
              puVar15 = (undefined1 *)local_50.top;
              if ((int)puVar20 <= local_50.top) {
                puVar15 = puVar20;
              }
              if ((int)puVar15 * 4 != 0) {
                iVar17 = 0;
                puVar19 = puVar16;
                do {
                  puVar3 = (undefined1 *)((int)local_50.d + iVar17);
                  iVar17 = iVar17 + 1;
                  *(undefined1 *)((int)&pBVar21->d + (int)puVar19) = *puVar3;
                  puVar19 = (undefined1 *)((int)&pBVar18->d + (int)puVar19);
                } while (iVar17 != (int)puVar15 * 4);
              }
              puVar16 = puVar16 + 1;
              pBVar5 = local_80;
            } while (puVar16 != puVar22);
          }
          puVar22 = (undefined1 *)((int)&pBVar5[-1].flags + 3);
          __aeabi_idivmod(puVar22,local_74);
          local_60 = extraout_r1;
          if (-1 < (int)extraout_r1) goto LAB_0018852c;
          puVar16 = (undefined1 *)0x0;
        }
        if (((int)puVar20 <= local_50.dmax) ||
           (local_84 = puVar16, pBVar7 = (BN_MONT_CTX *)bn_expand2(local_7c,(int)puVar20),
           puVar16 = local_84, pBVar7 != (BN_MONT_CTX *)0x0)) {
          pBVar12 = local_58;
          pBVar4 = local_68;
          pBVar6 = local_74;
          pBVar5 = local_7c;
          if (local_6c != 0) {
            iVar17 = 0;
            do {
              puVar15 = (undefined1 *)((int)&pBVar21->d + (int)puVar16);
              puVar16 = (undefined1 *)((int)&pBVar18->d + (int)puVar16);
              *(undefined1 *)((int)local_50.d + iVar17) = *puVar15;
              iVar17 = iVar17 + 1;
            } while (iVar17 != local_6c);
          }
          local_50.top = (int)puVar20;
          if (0 < (int)puVar20) {
            piVar14 = (int *)((int)local_50.d + local_78);
            do {
              if (*piVar14 != 0) break;
              local_50.top = local_50.top + -1;
              piVar14 = piVar14 + -1;
            } while ((undefined1 *)local_50.top != (undefined1 *)0x0);
          }
          if (-1 < (int)puVar22) {
            local_60 = puVar20;
            local_80 = pBVar21;
            local_74 = pBVar18;
            do {
              puVar20 = (undefined1 *)0x0;
              iVar17 = 0;
              do {
                iVar17 = iVar17 + 1;
                *puVar24 = ctx;
                iVar9 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,pBVar4,(BN_CTX *)*puVar24);
                if (iVar9 == 0) {
                  pBVar7 = (BN_MONT_CTX *)0x0;
                  pBVar21 = local_80;
                  goto LAB_0018827a;
                }
                iVar9 = BN_is_bit_set(pBVar12,(int)puVar22);
                puVar22 = puVar22 + -1;
                puVar20 = (undefined1 *)((int)puVar20 * 2 + iVar9);
              } while (iVar17 < (int)pBVar6);
              if ((local_3c.dmax < (int)local_60) &&
                 (pBVar7 = (BN_MONT_CTX *)bn_expand2(local_70,(int)local_60), pBVar21 = local_80,
                 pBVar7 == (BN_MONT_CTX *)0x0)) goto LAB_0018827a;
              pBVar21 = local_70;
              if (local_6c != 0) {
                iVar17 = 0;
                do {
                  puVar16 = (undefined1 *)((int)&local_80->d + (int)puVar20);
                  puVar20 = (undefined1 *)((int)&local_74->d + (int)puVar20);
                  *(undefined1 *)((int)local_3c.d + iVar17) = *puVar16;
                  iVar17 = iVar17 + 1;
                } while (iVar17 != local_6c);
              }
              local_3c.top = (int)local_60;
              if (0 < (int)local_60) {
                piVar14 = (int *)((int)local_3c.d + local_78);
                do {
                  if (*piVar14 != 0) break;
                  local_3c.top = local_3c.top + -1;
                  piVar14 = piVar14 + -1;
                } while ((undefined1 *)local_3c.top != (undefined1 *)0x0);
              }
              *puVar24 = ctx;
              pBVar7 = (BN_MONT_CTX *)
                       BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar21,pBVar4,(BN_CTX *)*puVar24);
              pBVar21 = local_80;
              if (pBVar7 == (BN_MONT_CTX *)0x0) goto LAB_0018827a;
            } while (-1 < (int)puVar22);
          }
          pBVar7 = (BN_MONT_CTX *)BN_from_montgomery(local_5c,local_7c,local_68,ctx);
          if (pBVar7 != (BN_MONT_CTX *)0x0) {
            pBVar7 = (BN_MONT_CTX *)0x1;
          }
        }
      }
    }
    else {
      local_64 = CRYPTO_malloc(local_54 + 0x40,"bn_exp.c",0x2fa);
      if (local_64 != (void *)0x0) {
        pBVar21 = (BIGNUM *)(((uint)local_64 & 0xffffffc0) + 0x40);
        memset(pBVar21,0,local_54);
        goto LAB_001881e2;
      }
      pBVar7 = (BN_MONT_CTX *)0x0;
      pBVar21 = (BIGNUM *)0x0;
    }
LAB_0018827a:
    if (in_mont == (BN_MONT_CTX *)0x0) goto LAB_00188316;
  }
  if ((pBVar21 != (BIGNUM *)0x0) && (OPENSSL_cleanse(pBVar21,local_54), local_64 != (void *)0x0)) {
    CRYPTO_free(local_64);
  }
LAB_0018829a:
  BN_CTX_end(ctx);
  return (int)pBVar7;
}

